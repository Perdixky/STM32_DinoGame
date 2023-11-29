################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Peripherals/Key/Key.c 

C_DEPS += \
./Core/Peripherals/Key/Key.d 

OBJS += \
./Core/Peripherals/Key/Key.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Peripherals/Key/%.o Core/Peripherals/Key/%.su Core/Peripherals/Key/%.cyclo: ../Core/Peripherals/Key/%.c Core/Peripherals/Key/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/HMC5883L" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/MPU6050" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/i-Bus" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Agorithm/KalmanFliter" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/BMP085" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Peripherals-2f-Key

clean-Core-2f-Peripherals-2f-Key:
	-$(RM) ./Core/Peripherals/Key/Key.cyclo ./Core/Peripherals/Key/Key.d ./Core/Peripherals/Key/Key.o ./Core/Peripherals/Key/Key.su

.PHONY: clean-Core-2f-Peripherals-2f-Key

