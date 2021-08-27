################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Hola\ Mundo.c 

OBJS += \
./src/Hola\ Mundo.o 

C_DEPS += \
./src/Hola\ Mundo.d 


# Each subdirectory must supply rules for building sources it contributes
src/Hola\ Mundo.o: ../src/Hola\ Mundo.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Hola Mundo.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


