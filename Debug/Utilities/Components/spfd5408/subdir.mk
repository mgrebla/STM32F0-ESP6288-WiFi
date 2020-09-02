################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Components/spfd5408/spfd5408.c 

OBJS += \
./Utilities/Components/spfd5408/spfd5408.o 

C_DEPS += \
./Utilities/Components/spfd5408/spfd5408.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Components/spfd5408/%.o: ../Utilities/Components/spfd5408/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F0 -DSTM32F072RBTx -DSTM32F072B_DISCO -DDEBUG -DSTM32F072xB -DUSE_HAL_DRIVER -I"C:/Users/Maciek/workspace/ESP_01_Comm/HAL_Driver/Inc/Legacy" -I"C:/Users/Maciek/workspace/ESP_01_Comm/Utilities/Components/stlm75" -I"C:/Users/Maciek/workspace/ESP_01_Comm/Utilities/Components/hx8347d" -I"C:/Users/Maciek/workspace/ESP_01_Comm/Utilities/Components/spfd5408" -I"C:/Users/Maciek/workspace/ESP_01_Comm/Utilities/Components/Common" -I"C:/Users/Maciek/workspace/ESP_01_Comm/Utilities/Components/l3gd20" -I"C:/Users/Maciek/workspace/ESP_01_Comm/Utilities/STM32F072B-Discovery" -I"C:/Users/Maciek/workspace/ESP_01_Comm/inc" -I"C:/Users/Maciek/workspace/ESP_01_Comm/CMSIS/device" -I"C:/Users/Maciek/workspace/ESP_01_Comm/CMSIS/core" -I"C:/Users/Maciek/workspace/ESP_01_Comm/HAL_Driver/Inc" -I"C:/Users/Maciek/workspace/ESP_01_Comm/Utilities/Components/st7735" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


