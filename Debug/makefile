################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Filter/complementary_filter.obj" \
"./Filter/kalman_filter.obj" \
"./Tasks/displayTask.obj" \
"./Tasks/ledTask.obj" \
"./Tasks/mpuTask.obj" \
"./i2cDrivers/i2cMasterPoll.obj" \
"./i2cDrivers/mpu9150.obj" \
"./source/dabort.obj" \
"./source/errata_SSWF021_45.obj" \
"./source/esm.obj" \
"./source/gio.obj" \
"./source/i2c.obj" \
"./source/notification.obj" \
"./source/notification_conflict-20150709-010640.obj" \
"./source/os_croutine.obj" \
"./source/os_event_groups.obj" \
"./source/os_heap.obj" \
"./source/os_list.obj" \
"./source/os_mpu_wrappers.obj" \
"./source/os_port.obj" \
"./source/os_portasm.obj" \
"./source/os_queue.obj" \
"./source/os_tasks.obj" \
"./source/os_timer.obj" \
"./source/pinmux.obj" \
"./source/sci.obj" \
"./source/sciPrintf.obj" \
"./source/sys_core.obj" \
"./source/sys_dma.obj" \
"./source/sys_intvecs.obj" \
"./source/sys_main.obj" \
"./source/sys_mpu.obj" \
"./source/sys_pcr.obj" \
"./source/sys_phantom.obj" \
"./source/sys_pmm.obj" \
"./source/sys_pmu.obj" \
"./source/sys_selftest.obj" \
"./source/sys_startup.obj" \
"./source/sys_vim.obj" \
"./source/system.obj" \
"../source/sys_link.cmd" \
$(GEN_CMDS__FLAG) \
-lrtsv7R4_T_be_v3D16_eabi.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include Filter/subdir_vars.mk
-include Tasks/subdir_vars.mk
-include i2cDrivers/subdir_vars.mk
-include source/subdir_vars.mk
-include Filter/subdir_rules.mk
-include Tasks/subdir_rules.mk
-include i2cDrivers/subdir_rules.mk
-include source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TMS570\ Test\ FreeRtos.out \

EXE_OUTPUTS__QUOTED += \
"TMS570 Test FreeRtos.out" \

BIN_OUTPUTS += \
TMS570\ Test\ FreeRtos.hex \

BIN_OUTPUTS__QUOTED += \
"TMS570 Test FreeRtos.hex" \


# All Target
all: TMS570\ Test\ FreeRtos.out

# Tool invocations
TMS570\ Test\ FreeRtos.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 --abi=eabi -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed -z -m"TMS570 Test FreeRtos.map" --stack_size=0x800 --heap_size=0x800 -i"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/lib" -i"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="TMS570 Test FreeRtos_linkInfo.xml" --rom_model --be32 -o "TMS570 Test FreeRtos.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

TMS570\ Test\ FreeRtos.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armhex"  -o "TMS570 Test FreeRtos.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Filter\complementary_filter.obj" "Filter\kalman_filter.obj" "Tasks\displayTask.obj" "Tasks\ledTask.obj" "Tasks\mpuTask.obj" "i2cDrivers\i2cMasterPoll.obj" "i2cDrivers\mpu9150.obj" "source\dabort.obj" "source\errata_SSWF021_45.obj" "source\esm.obj" "source\gio.obj" "source\i2c.obj" "source\notification.obj" "source\notification_conflict-20150709-010640.obj" "source\os_croutine.obj" "source\os_event_groups.obj" "source\os_heap.obj" "source\os_list.obj" "source\os_mpu_wrappers.obj" "source\os_port.obj" "source\os_portasm.obj" "source\os_queue.obj" "source\os_tasks.obj" "source\os_timer.obj" "source\pinmux.obj" "source\sci.obj" "source\sciPrintf.obj" "source\sys_core.obj" "source\sys_dma.obj" "source\sys_intvecs.obj" "source\sys_main.obj" "source\sys_mpu.obj" "source\sys_pcr.obj" "source\sys_phantom.obj" "source\sys_pmm.obj" "source\sys_pmu.obj" "source\sys_selftest.obj" "source\sys_startup.obj" "source\sys_vim.obj" "source\system.obj" 
	-$(RM) "Filter\complementary_filter.d" "Filter\kalman_filter.d" "Tasks\displayTask.d" "Tasks\ledTask.d" "Tasks\mpuTask.d" "i2cDrivers\i2cMasterPoll.d" "i2cDrivers\mpu9150.d" "source\errata_SSWF021_45.d" "source\esm.d" "source\gio.d" "source\i2c.d" "source\notification.d" "source\notification_conflict-20150709-010640.d" "source\os_croutine.d" "source\os_event_groups.d" "source\os_heap.d" "source\os_list.d" "source\os_mpu_wrappers.d" "source\os_port.d" "source\os_queue.d" "source\os_tasks.d" "source\os_timer.d" "source\pinmux.d" "source\sci.d" "source\sciPrintf.d" "source\sys_dma.d" "source\sys_main.d" "source\sys_pcr.d" "source\sys_phantom.d" "source\sys_pmm.d" "source\sys_selftest.d" "source\sys_startup.d" "source\sys_vim.d" "source\system.d" 
	-$(RM) "source\dabort.d" "source\os_portasm.d" "source\sys_core.d" "source\sys_intvecs.d" "source\sys_mpu.d" "source\sys_pmu.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

