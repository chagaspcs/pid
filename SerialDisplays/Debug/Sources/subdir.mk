################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/dsf_SerialDisplays.cpp \
../Sources/main.cpp \
../Sources/mkl_GPIO.cpp \
../Sources/mkl_GPIOPort.cpp \
../Sources/mkl_PIT.cpp \
../Sources/mkl_PITPeriodicInterrupt.cpp 

OBJS += \
./Sources/dsf_SerialDisplays.o \
./Sources/main.o \
./Sources/mkl_GPIO.o \
./Sources/mkl_GPIOPort.o \
./Sources/mkl_PIT.o \
./Sources/mkl_PITPeriodicInterrupt.o 

CPP_DEPS += \
./Sources/dsf_SerialDisplays.d \
./Sources/main.d \
./Sources/mkl_GPIO.d \
./Sources/mkl_GPIOPort.d \
./Sources/mkl_PIT.d \
./Sources/mkl_PITPeriodicInterrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


