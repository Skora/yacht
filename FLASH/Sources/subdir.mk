################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/AS5040.c" \
"../Sources/Events.c" \
"../Sources/LTC2945.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/adc_data.c" \
"../Sources/mma8453.c" \

C_SRCS += \
../Sources/AS5040.c \
../Sources/Events.c \
../Sources/LTC2945.c \
../Sources/ProcessorExpert.c \
../Sources/adc_data.c \
../Sources/mma8453.c \

OBJS += \
./Sources/AS5040.o \
./Sources/Events.o \
./Sources/LTC2945.o \
./Sources/ProcessorExpert.o \
./Sources/adc_data.o \
./Sources/mma8453.o \

C_DEPS += \
./Sources/AS5040.d \
./Sources/Events.d \
./Sources/LTC2945.d \
./Sources/ProcessorExpert.d \
./Sources/adc_data.d \
./Sources/mma8453.d \

OBJS_QUOTED += \
"./Sources/AS5040.o" \
"./Sources/Events.o" \
"./Sources/LTC2945.o" \
"./Sources/ProcessorExpert.o" \
"./Sources/adc_data.o" \
"./Sources/mma8453.o" \

C_DEPS_QUOTED += \
"./Sources/AS5040.d" \
"./Sources/Events.d" \
"./Sources/LTC2945.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/adc_data.d" \
"./Sources/mma8453.d" \

OBJS_OS_FORMAT += \
./Sources/AS5040.o \
./Sources/Events.o \
./Sources/LTC2945.o \
./Sources/ProcessorExpert.o \
./Sources/adc_data.o \
./Sources/mma8453.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/AS5040.o: ../Sources/AS5040.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/AS5040.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/AS5040.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/LTC2945.o: ../Sources/LTC2945.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/LTC2945.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/LTC2945.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert.o: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ProcessorExpert.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/adc_data.o: ../Sources/adc_data.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/adc_data.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/adc_data.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mma8453.o: ../Sources/mma8453.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mma8453.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mma8453.o"
	@echo 'Finished building: $<'
	@echo ' '


