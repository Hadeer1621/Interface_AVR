################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Mcal/Timer/subdir.mk
-include Mcal/GIE/subdir.mk
-include Mcal/ExtInt/subdir.mk
-include Mcal/DIO/subdir.mk
-include Mcal/ADC/subdir.mk
-include Hal/TempSensor/subdir.mk
-include Hal/PushButton/subdir.mk
-include Hal/Led/subdir.mk
-include Hal/Lcd/subdir.mk
-include Hal/KeyPad/subdir.mk
-include Hal/DC_motor/subdir.mk
-include Hal/Buzzer/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
Smart_Home_Pro.lss \

FLASH_IMAGE += \
Smart_Home_Pro.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Smart_Home_Pro.elf secondary-outputs

# Tool invocations
Smart_Home_Pro.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Smart_Home_Pro.map -mmcu=atmega32 -o "Smart_Home_Pro.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Smart_Home_Pro.lss: Smart_Home_Pro.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Smart_Home_Pro.elf  >"Smart_Home_Pro.lss"
	@echo 'Finished building: $@'
	@echo ' '

Smart_Home_Pro.hex: Smart_Home_Pro.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Smart_Home_Pro.elf  "Smart_Home_Pro.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Smart_Home_Pro.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Smart_Home_Pro.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Smart_Home_Pro.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
