################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c \
../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c 

C_DEPS += \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.d \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.d 

OBJS += \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.o \
./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32H7xx_HAL_Driver/Src/%.o Drivers/STM32H7xx_HAL_Driver/Src/%.su Drivers/STM32H7xx_HAL_Driver/Src/%.cyclo: ../Drivers/STM32H7xx_HAL_Driver/Src/%.c Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/HMC5883L" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/MPU6050" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/i-Bus" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Agorithm/KalmanFliter" -I"C:/Users/32937/STM32CubeIDE/workspace_1.13.2/h750vb/Core/Peripherals/BMP085" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.su ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.d ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.o ./Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.su

.PHONY: clean-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src

