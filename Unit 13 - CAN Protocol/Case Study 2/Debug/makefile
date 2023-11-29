################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Case_Study_2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Case_Study_2.list \

OBJCOPY_BIN += \
Case_Study_2.bin \


# All Target
all: Case_Study_2.elf secondary-outputs

# Tool invocations
Case_Study_2.elf: $(OBJS) $(USER_OBJS) C:\Users\mark_\C\ Code\Unit\ 13\ -\ CAN\ Protocol\Case\ Study\ 2\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Case_Study_2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\mark_\C Code\Unit 13 - CAN Protocol\Case Study 2\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Case_Study_2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Case_Study_2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Case_Study_2.list"
	@echo 'Finished building: $@'
	@echo ' '

Case_Study_2.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Case_Study_2.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
