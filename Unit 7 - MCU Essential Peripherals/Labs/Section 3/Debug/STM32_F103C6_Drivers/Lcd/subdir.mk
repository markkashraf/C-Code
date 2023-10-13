################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/Lcd/lcd.c 

OBJS += \
./STM32_F103C6_Drivers/Lcd/lcd.o 

C_DEPS += \
./STM32_F103C6_Drivers/Lcd/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/Lcd/lcd.o: ../STM32_F103C6_Drivers/Lcd/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Mark/C Code/Unit 7 - MCU Essential Peripherals/Labs/Section 33/STM32_F103C6_Drivers" -I"C:/Users/Mark/C Code/Unit 7 - MCU Essential Peripherals/Labs/Section 33/STM32_F103C6_Drivers/GPIO" -I"C:/Users/Mark/C Code/Unit 7 - MCU Essential Peripherals/Labs/Section 33/STM32_F103C6_Drivers/Keypad" -I"C:/Users/Mark/C Code/Unit 7 - MCU Essential Peripherals/Labs/Section 33/STM32_F103C6_Drivers/Lcd" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/Lcd/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

