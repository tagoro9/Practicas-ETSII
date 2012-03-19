################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lib/keys/keys.cc 

OBJS += \
./lib/keys/keys.o 

CC_DEPS += \
./lib/keys/keys.d 


# Each subdirectory must supply rules for building sources it contributes
lib/keys/%.o: ../lib/keys/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


