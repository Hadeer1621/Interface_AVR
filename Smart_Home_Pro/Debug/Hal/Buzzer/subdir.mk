################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hal/Buzzer/Buzzer.c 

OBJS += \
./Hal/Buzzer/Buzzer.o 

C_DEPS += \
./Hal/Buzzer/Buzzer.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/Buzzer/%.o: ../Hal/Buzzer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\App" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Mcal\ADC" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Mcal\DIO" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Mcal\ExtInt" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Mcal\GIE" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Mcal\Timer" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\App\Lib" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal\Buzzer" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal\DC_motor" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal\KeyPad" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal\Lcd" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal\Led" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal\PushButton" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal\TempSensor" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Hal" -I"C:\Users\Eng hadeer\Desktop\Smart_Home_Pro\Mcal" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


