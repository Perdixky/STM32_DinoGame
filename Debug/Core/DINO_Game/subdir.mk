################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DINO_Game/Dino_Game.c \
../Core/DINO_Game/Dino_Image&Font.c 

C_DEPS += \
./Core/DINO_Game/Dino_Game.d \
./Core/DINO_Game/Dino_Image&Font.d 

OBJS += \
./Core/DINO_Game/Dino_Game.o \
./Core/DINO_Game/Dino_Image&Font.o 


# Each subdirectory must supply rules for building sources it contributes
Core/DINO_Game/Dino_Game.o: ../Core/DINO_Game/Dino_Game.c Core/DINO_Game/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/HMC5883L" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/MPU6050" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/i-Bus" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Agorithm/KalmanFliter" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/BMP085" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/OLED" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/Key" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/DINO_Game/%.o Core/DINO_Game/%.su Core/DINO_Game/%.cyclo: ../Core/DINO_Game/%.c Core/DINO_Game/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/HMC5883L" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/MPU6050" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/i-Bus" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Agorithm/KalmanFliter" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/BMP085" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/OLED" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-DINO_Game

clean-Core-2f-DINO_Game:
	-$(RM) ./Core/DINO_Game/Dino_Game.cyclo ./Core/DINO_Game/Dino_Game.d ./Core/DINO_Game/Dino_Game.o ./Core/DINO_Game/Dino_Game.su ./Core/DINO_Game/Dino_Image&Font.cyclo ./Core/DINO_Game/Dino_Image&Font.d ./Core/DINO_Game/Dino_Image&Font.o ./Core/DINO_Game/Dino_Image&Font.su

.PHONY: clean-Core-2f-DINO_Game

