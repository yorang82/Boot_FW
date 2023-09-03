################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app/src/gpio.c \
../Core/Src/app/src/utilst.c 

OBJS += \
./Core/Src/app/src/gpio.o \
./Core/Src/app/src/utilst.o 

C_DEPS += \
./Core/Src/app/src/gpio.d \
./Core/Src/app/src/utilst.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app/src/%.o Core/Src/app/src/%.su Core/Src/app/src/%.cyclo: ../Core/Src/app/src/%.c Core/Src/app/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/01.Yorang/STM32CubeIDE/STM32F405/Boot_FW/Core/Src/app" -I"D:/01.Yorang/STM32CubeIDE/STM32F405/Boot_FW/Core/Src/app/include" -I"D:/01.Yorang/STM32CubeIDE/STM32F405/Boot_FW/Core/Src/app/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app-2f-src

clean-Core-2f-Src-2f-app-2f-src:
	-$(RM) ./Core/Src/app/src/gpio.cyclo ./Core/Src/app/src/gpio.d ./Core/Src/app/src/gpio.o ./Core/Src/app/src/gpio.su ./Core/Src/app/src/utilst.cyclo ./Core/Src/app/src/utilst.d ./Core/Src/app/src/utilst.o ./Core/Src/app/src/utilst.su

.PHONY: clean-Core-2f-Src-2f-app-2f-src

