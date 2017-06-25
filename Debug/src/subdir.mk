################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AKS.cpp \
../src/LPF.cpp \
../src/PerfectPower.cpp \
../src/PerfectPowerTests.cpp \
../src/main.cpp 

OBJS += \
./src/AKS.o \
./src/LPF.o \
./src/PerfectPower.o \
./src/PerfectPowerTests.o \
./src/main.o 

CPP_DEPS += \
./src/AKS.d \
./src/LPF.d \
./src/PerfectPower.d \
./src/PerfectPowerTests.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/NTL -I/usr/include/cppunit -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


