################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lib/gui/desGui.cc 

OBJS += \
./lib/gui/desGui.o 

CC_DEPS += \
./lib/gui/desGui.d 


# Each subdirectory must supply rules for building sources it contributes
lib/gui/%.o: ../lib/gui/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


