################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Main/Cpu0_Main.c \
../App/Main/Cpu1_Main.c \
../App/Main/Cpu2_Main.c \
../App/Main/Sys_Init.c 

COMPILED_SRCS += \
App/Main/Cpu0_Main.src \
App/Main/Cpu1_Main.src \
App/Main/Cpu2_Main.src \
App/Main/Sys_Init.src 

C_DEPS += \
App/Main/Cpu0_Main.d \
App/Main/Cpu1_Main.d \
App/Main/Cpu2_Main.d \
App/Main/Sys_Init.d 

OBJS += \
App/Main/Cpu0_Main.o \
App/Main/Cpu1_Main.o \
App/Main/Cpu2_Main.o \
App/Main/Sys_Init.o 


# Each subdirectory must supply rules for building sources it contributes
App/Main/Cpu0_Main.src: ../App/Main/Cpu0_Main.c App/Main/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Main/Cpu0_Main.o: App/Main/Cpu0_Main.src App/Main/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
App/Main/Cpu1_Main.src: ../App/Main/Cpu1_Main.c App/Main/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Main/Cpu1_Main.o: App/Main/Cpu1_Main.src App/Main/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
App/Main/Cpu2_Main.src: ../App/Main/Cpu2_Main.c App/Main/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Main/Cpu2_Main.o: App/Main/Cpu2_Main.src App/Main/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
App/Main/Sys_Init.src: ../App/Main/Sys_Init.c App/Main/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Main/Sys_Init.o: App/Main/Sys_Init.src App/Main/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-App-2f-Main

clean-App-2f-Main:
	-$(RM) App/Main/Cpu0_Main.d App/Main/Cpu0_Main.o App/Main/Cpu0_Main.src App/Main/Cpu1_Main.d App/Main/Cpu1_Main.o App/Main/Cpu1_Main.src App/Main/Cpu2_Main.d App/Main/Cpu2_Main.o App/Main/Cpu2_Main.src App/Main/Sys_Init.d App/Main/Sys_Init.o App/Main/Sys_Init.src

.PHONY: clean-App-2f-Main

