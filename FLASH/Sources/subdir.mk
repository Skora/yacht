################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/AS5040.c" \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \

C_SRCS += \
../Sources/AS5040.c \
../Sources/Events.c \
../Sources/ProcessorExpert.c \

OBJS += \
./Sources/AS5040.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \

C_DEPS += \
./Sources/AS5040.d \
./Sources/Events.d \
./Sources/ProcessorExpert.d \

OBJS_QUOTED += \
"./Sources/AS5040.o" \
"./Sources/Events.o" \
"./Sources/ProcessorExpert.o" \

C_DEPS_QUOTED += \
"./Sources/AS5040.d" \
"./Sources/Events.d" \
"./Sources/ProcessorExpert.d" \

OBJS_OS_FORMAT += \
./Sources/AS5040.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \


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

Sources/ProcessorExpert.o: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ProcessorExpert.o"
	@echo 'Finished building: $<'
	@echo ' '

