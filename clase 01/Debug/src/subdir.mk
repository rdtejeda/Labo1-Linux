################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clase\ 01.c 

OBJS += \
./src/clase\ 01.o 

C_DEPS += \
./src/clase\ 01.d 


# Each subdirectory must supply rules for building sources it contributes
src/clase\ 01.o: ../src/clase\ 01.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/clase 01.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


