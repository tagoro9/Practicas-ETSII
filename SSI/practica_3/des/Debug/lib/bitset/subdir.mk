################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lib/bitset/bitset.cc 

OBJS += \
./lib/bitset/bitset.o 

CC_DEPS += \
./lib/bitset/bitset.d 


# Each subdirectory must supply rules for building sources it contributes
lib/bitset/%.o: ../lib/bitset/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


