################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/extra/widgets/span/lv_span.c 

OBJS += \
./Drivers/lvgl/src/extra/widgets/span/lv_span.o 

C_DEPS += \
./Drivers/lvgl/src/extra/widgets/span/lv_span.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/extra/widgets/span/%.o Drivers/lvgl/src/extra/widgets/span/%.su Drivers/lvgl/src/extra/widgets/span/%.cyclo: ../Drivers/lvgl/src/extra/widgets/span/%.c Drivers/lvgl/src/extra/widgets/span/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L496xx -c -I../Core/Inc -I"C:/STM32CubeIDE/workspace_1.17.0/stmwithtft3.5inch/Drivers/lvgl" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-span

clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-span:
	-$(RM) ./Drivers/lvgl/src/extra/widgets/span/lv_span.cyclo ./Drivers/lvgl/src/extra/widgets/span/lv_span.d ./Drivers/lvgl/src/extra/widgets/span/lv_span.o ./Drivers/lvgl/src/extra/widgets/span/lv_span.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-span

