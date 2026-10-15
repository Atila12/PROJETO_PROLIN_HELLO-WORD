################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include objects.mk

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := HelloWorld
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
NOSTRIP += \
app.nostrip \


# All Target
all: main-build

# Main-build Target
main-build: HelloWorld

# Tool invocations
HelloWorld: $(NOSTRIP) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Strip'
	"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/toolchains/arm-8.3.0/bin/arm-none-linux-gnueabi-strip" -g $(NOSTRIP) -o"HelloWorld"
	@echo 'Finished building target: $@'
	@echo ' '

app.nostrip: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GCC Linker'
	"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/toolchains/arm-8.3.0/bin/arm-none-linux-gnueabi-gcc" -o"app.nostrip" $(OBJS) $(USER_OBJS) $(LIBS) -Wl,-rpath=./lib,-rpath=/opt/lib,-rpath=/system/lib -Wl,-rpath-link,"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/platforms/nuxiums-dev-8.3.0/lib" -g -losal -lxui -lts -L"C:/Users/Inovare/workspace/HelloWorld/lib" -L"C:/Users/Inovare/Projetos_Prolin/prolin_sdk_win-3.8/sdk/platforms/prolin-dev-8.3.0/lib"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) HelloWorld app.nostrip
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
