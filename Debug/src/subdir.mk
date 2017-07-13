################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AKS.cpp \
../src/AKSTests.cpp \
../src/Congruence.cpp \
../src/LPF.cpp \
../src/LPFTests.cpp \
../src/PerfectPower.cpp \
../src/PerfectPowerTests.cpp \
../src/PrimalityTests.cpp \
../src/Utilities.cpp \
../src/UtilitiesTests.cpp \
../src/main.cpp 

OBJS += \
./src/AKS.o \
./src/AKSTests.o \
./src/Congruence.o \
./src/LPF.o \
./src/LPFTests.o \
./src/PerfectPower.o \
./src/PerfectPowerTests.o \
./src/PrimalityTests.o \
./src/Utilities.o \
./src/UtilitiesTests.o \
./src/main.o 

CPP_DEPS += \
./src/AKS.d \
./src/AKSTests.d \
./src/Congruence.d \
./src/LPF.d \
./src/LPFTests.d \
./src/PerfectPower.d \
./src/PerfectPowerTests.d \
./src/PrimalityTests.d \
./src/Utilities.d \
./src/UtilitiesTests.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/include/NTL -I/usr/lib/gcc/x86_64-linux-gnu/5.4.1/include -I/usr/include/cppunit -I/usr/local/include -O3 -g3 -Wall -fopenmp -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


