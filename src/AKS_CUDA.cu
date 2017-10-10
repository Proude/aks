#include "AKS.h"
#include <fstream>

/*
 * Comparison in GPU between bignumbers
 */
__device__ int gpu_compare(int *a, int *b, int aidx, int bidx)
{
	int i = N - 1;

	while (a[aidx + i] == b[bidx + i] && i > 0)
		i--;
	if (i == N) return 0;
	if (a[aidx + i] > b[bidx + i]) return 1;
	else if (a[aidx + i] == b[bidx + i]) return 0;
	else return -1;
}

/*
 * Multiplication in GPU between bignumbers
 */
__device__ void gpu_multiplication(int *c, int *a, int *b, int aidx, int bidx, int cidx)
{
	int n, s, k;

	// count the digits on each number
	for (k = N - 1; a[aidx + k] == 0; k--);
	n =  k + 1;
	for (k = N - 1; b[bidx + k] == 0; k--);
	s =  k + 1;

	// initialize the result
	int z[2 * N + 1];

	for (int i = 0; i < 2 * N + 1; i++)
		z[i] = 0;

	// calculate the product
	for (int i = 0; i < s; i++)
	{
		int carry = 0;
		for (int j = 0; j < n; j++)
		{
			int temp = z[i + j] + (a[aidx + j] * b[bidx + i]) + carry;
			z[i + j] = temp % 10;
			carry = temp / 10;
		}
		z[n + i] = carry;
	}

	// move the result to the destination
	for (int i = 0; i < N; i++)
		c[cidx + i] = z[i];
}

/*
 * Subtraction in GPU between bignumbers
 */
__device__ void gpu_substraction(int *c, int *a, int *b, int aidx, int bidx, int cidx)
{
	int carry = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = carry + a[aidx + i] - b[bidx + i];
		if (temp < 0)
		{
			// modulo 10
			c[cidx + i] = ((temp % 10) + 10) % 10;
			carry = -1;
		}
		else
		{
			c[cidx + i] = temp % 10;
			carry = 0;
		}
	}
}
/*
 * Addition in GPU between bignumbers
 */
__device__ void gpu_addition(int *c, int *a, int *b, int aidx, int bidx, int cidx)
{
	int carry = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = carry + a[aidx + i] + b[bidx + i];
		c[cidx + i] = temp % 10;
		carry = temp / 10;
	}
}

/*
 * Division in GPU between bignumbers
 */
__device__ void gpu_division(int *c, int *a, int *b, int aidx, int bidx, int cidx)
{
		int temp[N];
		int result[N];
		int x[N];
		for (int i = 0; i < N; i++)
		{
			temp[i] = 0;
			result[i] = 0;
			x[i] = a[aidx + i];
		}
		temp[0] = 1;

		while (gpu_compare(x, b, 0, bidx) != -1)
		{
			gpu_substraction(x, x, b, 0, bidx, 0);
			gpu_addition(result, result, temp, 0, 0, 0);
		}

		for (int i = 0; i < N; i++)
			c[cidx + i] = result[i];
}

/*
 * Modulo in GPU between bignumbers
 */
__device__ void gpu_modulo(int *c, int *a, int *b, int aidx, int bidx, int cidx)
{
	int temp[N];
	int result[N];
	int x[N];
	for (int i = 0; i < N; i++)
	{
		temp[i] = 0;
		result[i] = 0;
		x[i] = a[aidx + i];
	}
	temp[0] = 1;

	while (gpu_compare(x, b, 0, bidx) != -1)
	{
		gpu_substraction(x, x, b, 0, bidx, 0);
		gpu_addition(result, result, temp, 0, 0, 0);
	}
	for (int i = 0; i < N; i++)
		c[cidx + i] = x[i];
}

/*
 * CUDA kernel that calculates the coefficients and
 * checks if they are divible by n
 */
__global__ void calculateCoefficients(int *coeff, int *coeff_max, int *coeff_min)
{
	int ix = threadIdx.x + blockDim.x * blockIdx.x;
	int iy = threadIdx.y + blockDim.y * blockIdx.y;
	// index to third dimension
	int index = ix * 1024 * blockDim.y + iy * 1024;

	int temp[N];
	int res[N];
	int sarray[N];
	int num[N];

	for (int i = 0; i < N; i++)
	{
		temp[i] = 0;
		res[i] = 0;
		sarray[i] = 0;
		num[i] = coeff[index + i];
	}
	temp[0] = 1;
	res[0] = 1;

	//calculate combination
	for (int i = 0; i < ix; i++)
	{
		gpu_substraction(coeff_max, coeff_max, temp, index, 0, index);
		gpu_multiplication(coeff, coeff, coeff_max, index, index, index);
	}

	for (int i = 0; i < ix; i++)
	{
		gpu_addition(coeff_min, coeff_min, temp, index, 0, index);
		gpu_division(coeff, coeff, coeff_min, index, index, index);
	}

	//calculate power
	int exp = ix + 1;
	int s = iy + 1;
	int j = 0;
	while(s > 0)
	{
		sarray[j++] = s % 10;
		s = s / 10;
	}

	for (int i = 0; i < exp; i++)
	{
		gpu_multiplication(res, res, sarray, 0, 0, 0);
		gpu_modulo(res, res, num, 0, 0, 0);
	}
	gpu_modulo(res, res, num, 0, 0, 0);
	//calculate modulo

	gpu_multiplication(coeff, coeff, res, index, 0, index);
	gpu_modulo(coeff, coeff, num, index, 0, index);

	//if everything is zero return true;
}

/*
 * AKS Bernstein using CUDA
 */
bool AKS::AKSAlgorithm_Bernstein_CUDA()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	if (pp.AlgorithmX(number))
	{
		gettimeofday(&end, NULL);
		std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
		return false;
	}
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (perfect power) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	gettimeofday(&start, NULL);
	int r = primitiveModulo();
	gettimeofday(&end, NULL);
	std::cout << "r = " << r << std::endl;
	std::cout << "Elapsed time (find r) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	int phiR = phi(NTL::ZZ(r));
	const double d = 0.5 * phiR;
	const double i = 0.475 * phiR;
	const double j = 0.475 * phiR;

	gettimeofday(&start, NULL);
	long s = findSB(r, d, i, j);
	std::cout << "s = " << s <<std::endl;
	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (find s) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;
	bool result = true;

	gettimeofday(&start, NULL);
	#pragma omp parallel for reduction(&:result)
	for (int i = 2; i <= s + 1; i++)
	{
		NTL::ZZ iZZ(i);
		if ((iZZ % number != 0) && (NTL::PowerMod(iZZ % number, number - 1, number) != 1))
			result &= false;
//		if ((i != number) && NTL::GCD(number, i) != 1)
//			return false;
		for (int j = 2; j <= s + 1; j++)
		{
			NTL::ZZ jZZ(j);
			if ((iZZ * jZZ > 1) && ((iZZ * jZZ) - 1 != number) && (iZZ * jZZ - 1 < number) && (NTL::GCD(number, (iZZ * jZZ) - 1) != 1))
				result &= false;
			if ((iZZ - jZZ > 0) && (iZZ-jZZ != number) && (iZZ-jZZ < number) && (NTL::GCD(number, iZZ - jZZ) != 1))
				result &= false;
		}
	}
	gettimeofday(&end, NULL);
	if (result == false)
		return false;
	std::cout << "Elapsed time (gcd) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	gettimeofday(&start, NULL);

	// initialise the memory for the host
	int int_num = NTL::conv<int>(number);
	// the calculated coefficients. Initialized as h_coeff = n
	int h_coeff[int_num - 1][s][N];
	// helps to calculate combination
	int h_coeff_max[int_num - 1][s][N];
	int h_coeff_min[int_num - 1][s][N];

	// initialise
	for (int i = 0; i < int_num - 1; i++)
		for (int j = 0; j < s; j++)
			for (int z = 0; z < N; z++)
			{
				h_coeff[i][j][z] = num_arr[N - z - 1];
				h_coeff_max[i][j][z] = num_arr[N - z - 1];
				if(z == 0)
					h_coeff_min[i][j][z] = 1;
				else
					h_coeff_min[i][j][z] = 0;
			}

	// initialize the memory for the device
	int *d_coeff;
	int *d_coeff_max;
	int *d_coeff_min;
	cudaError_t err;

	// Malloc copy on the device
	err = cudaMalloc((void**) &d_coeff, s * (int_num - 1) * N * sizeof(int));
	std::cout << cudaGetErrorString(err) << std::endl;
	err = cudaMalloc((void**) &d_coeff_max, s * (int_num - 1) * N * sizeof(int));
	std::cout << cudaGetErrorString(err) << std::endl;
	err = cudaMalloc((void**) &d_coeff_min, s * (int_num - 1) * N * sizeof(int));
	std::cout << cudaGetErrorString(err) << std::endl;

	// transfer to device memory
	err = cudaMemcpy(d_coeff, h_coeff, s * (int_num - 1) * N * sizeof(int), cudaMemcpyHostToDevice);
	std::cout << cudaGetErrorString(err) << std::endl;
	err = cudaMemcpy(d_coeff_max, h_coeff_max, s * (int_num - 1) * N * sizeof(int), cudaMemcpyHostToDevice);
	std::cout << cudaGetErrorString(err) << std::endl;
	err = cudaMemcpy(d_coeff_min, h_coeff_min, s * (int_num - 1) * N * sizeof(int), cudaMemcpyHostToDevice);
	std::cout << cudaGetErrorString(err) << std::endl;

	// build the geometry of the problem
	dim3 block;
	dim3 grid;
	if ((int_num - 1) * s > 1024)
	{
		block.x = 32;
		block.y = 32;
		grid.x = (int_num - 1) / 1024;
		grid.y = s / 1024;
	}
	else
	{
		block.x = int_num - 1;
		block.y = s;
		grid.x = 1;
	}

	// calling the kernel
	calculateCoefficients<<<grid, block>>>(d_coeff, d_coeff_max, d_coeff_min);

	// get the result from device to host
	err = cudaMemcpy(h_coeff, d_coeff, s * (int_num - 1) * N * sizeof(int), cudaMemcpyDeviceToHost);
	std::cout << cudaGetErrorString(err) << std::endl;

	// check the result
	for (int i = 0; i < int_num - 1; i++)
		for (int j = 0; j < s; j++)
		{
			for (int z = 0; z < N; z++)
			{
				if (h_coeff[i][j][z] != 0)
					return false;
			}
		}

	// free memory
	cudaFree(d_coeff);
	cudaFree(d_coeff_max);
	cudaFree(d_coeff_min);

	gettimeofday(&end, NULL);
	std::cout << "Elapsed time (congruence) = " << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << std::endl;

	return true;
}
