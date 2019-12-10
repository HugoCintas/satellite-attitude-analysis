################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
i2cDrivers/%.obj: ../i2cDrivers/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 --abi=eabi --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" --include_path="C:/Users/simu04/workspace_v9/TMS570 Test FreeRtos/Filter" --include_path="C:/Users/simu04/workspace_v9/TMS570 Test FreeRtos/Tasks" --include_path="C:/Users/simu04/workspace_v9/TMS570 Test FreeRtos/i2cDrivers" --include_path="C:/Users/simu04/workspace_v9/TMS570 Test FreeRtos/include" -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --preproc_with_compile --preproc_dependency="i2cDrivers/$(basename $(<F)).d_raw" --obj_directory="i2cDrivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


