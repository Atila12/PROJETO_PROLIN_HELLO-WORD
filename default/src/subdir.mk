################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ctls.c \
../src/icc.c \
../src/mag.c \
../src/main.c \
../src/ui_helpers.c \
../src/util.c 

OBJS += \
./src/ctls.o \
./src/icc.o \
./src/mag.o \
./src/main.o \
./src/ui_helpers.o \
./src/util.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Compiler'
	"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/toolchains/arm-8.3.0/bin/arm-none-linux-gnueabi-gcc" -O0 -g2 -Wall -funwind-tables -I"C:/Users/Inovare/workspace/HelloWorld/inc" -I"C:/Users/Inovare/workspace/HelloWorld/src" -I"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/platforms/prolin-dev-8.3.0/include" -I"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/toolchains/arm-8.3.0/arm-none-linux-gnueabi/sysroot/usr/include" -I"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/toolchains/arm-8.3.0/lib/gcc/arm-none-linux-gnueabi/8.3.0/include" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ctls.o ./src/icc.o ./src/mag.o ./src/main.o ./src/ui_helpers.o ./src/util.o

.PHONY: clean-src

