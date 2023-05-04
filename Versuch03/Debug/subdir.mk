################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../reversi.cpp \
../reversiKI.cpp \
../test.cpp 

CPP_DEPS += \
./reversi.d \
./reversiKI.d \
./test.d 

OBJS += \
./reversi.o \
./reversiKI.o \
./test.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./reversi.d ./reversi.o ./reversiKI.d ./reversiKI.o ./test.d ./test.o

.PHONY: clean--2e-

