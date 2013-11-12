################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/application.cpp \
../src/bisection.cpp \
../src/fd_newton.cpp \
../src/main.cpp \
../src/newton.cpp 

OBJS += \
./src/application.o \
./src/bisection.o \
./src/fd_newton.o \
./src/main.o \
./src/newton.o 

CPP_DEPS += \
./src/application.d \
./src/bisection.d \
./src/fd_newton.d \
./src/main.d \
./src/newton.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


