################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clase\ 0.c 

OBJS += \
./src/Clase\ 0.o 

C_DEPS += \
./src/Clase\ 0.d 


# Each subdirectory must supply rules for building sources it contributes
src/Clase\ 0.o: ../src/Clase\ 0.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Clase 0.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


