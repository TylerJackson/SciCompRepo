################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src2/Mat.cpp \
../src2/Problem1.cpp \
../src2/Problem2.cpp 

OBJS += \
./src2/Mat.o \
./src2/Problem1.o \
./src2/Problem2.o 

CPP_DEPS += \
./src2/Mat.d \
./src2/Problem1.d \
./src2/Problem2.d 


# Each subdirectory must supply rules for building sources it contributes
src2/%.o: ../src2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


