################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/INT/INT.c 

OBJS += \
./MCAL/INT/INT.o 

C_DEPS += \
./MCAL/INT/INT.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/INT/%.o: ../MCAL/INT/%.c MCAL/INT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

