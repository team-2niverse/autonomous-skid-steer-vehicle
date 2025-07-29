################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Driver/ERU.c \
../BSW/Driver/EV_ADC.c \
../BSW/Driver/asclin.c \
../BSW/Driver/can.c \
../BSW/Driver/gtm_atom_pwm.c \
../BSW/Driver/ssv_motor.c \
../BSW/Driver/stm.c 

COMPILED_SRCS += \
BSW/Driver/ERU.src \
BSW/Driver/EV_ADC.src \
BSW/Driver/asclin.src \
BSW/Driver/can.src \
BSW/Driver/gtm_atom_pwm.src \
BSW/Driver/ssv_motor.src \
BSW/Driver/stm.src 

C_DEPS += \
BSW/Driver/ERU.d \
BSW/Driver/EV_ADC.d \
BSW/Driver/asclin.d \
BSW/Driver/can.d \
BSW/Driver/gtm_atom_pwm.d \
BSW/Driver/ssv_motor.d \
BSW/Driver/stm.d 

OBJS += \
BSW/Driver/ERU.o \
BSW/Driver/EV_ADC.o \
BSW/Driver/asclin.o \
BSW/Driver/can.o \
BSW/Driver/gtm_atom_pwm.o \
BSW/Driver/ssv_motor.o \
BSW/Driver/stm.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Driver/ERU.src: ../BSW/Driver/ERU.c BSW/Driver/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/Driver/ERU.o: BSW/Driver/ERU.src BSW/Driver/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/Driver/EV_ADC.src: ../BSW/Driver/EV_ADC.c BSW/Driver/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/Driver/EV_ADC.o: BSW/Driver/EV_ADC.src BSW/Driver/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/Driver/asclin.src: ../BSW/Driver/asclin.c BSW/Driver/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/Driver/asclin.o: BSW/Driver/asclin.src BSW/Driver/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/Driver/can.src: ../BSW/Driver/can.c BSW/Driver/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/Driver/can.o: BSW/Driver/can.src BSW/Driver/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/Driver/gtm_atom_pwm.src: ../BSW/Driver/gtm_atom_pwm.c BSW/Driver/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/Driver/gtm_atom_pwm.o: BSW/Driver/gtm_atom_pwm.src BSW/Driver/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/Driver/ssv_motor.src: ../BSW/Driver/ssv_motor.c BSW/Driver/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/Driver/ssv_motor.o: BSW/Driver/ssv_motor.src BSW/Driver/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/Driver/stm.src: ../BSW/Driver/stm.c BSW/Driver/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/Driver/stm.o: BSW/Driver/stm.src BSW/Driver/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Driver

clean-BSW-2f-Driver:
	-$(RM) BSW/Driver/ERU.d BSW/Driver/ERU.o BSW/Driver/ERU.src BSW/Driver/EV_ADC.d BSW/Driver/EV_ADC.o BSW/Driver/EV_ADC.src BSW/Driver/asclin.d BSW/Driver/asclin.o BSW/Driver/asclin.src BSW/Driver/can.d BSW/Driver/can.o BSW/Driver/can.src BSW/Driver/gtm_atom_pwm.d BSW/Driver/gtm_atom_pwm.o BSW/Driver/gtm_atom_pwm.src BSW/Driver/ssv_motor.d BSW/Driver/ssv_motor.o BSW/Driver/ssv_motor.src BSW/Driver/stm.d BSW/Driver/stm.o BSW/Driver/stm.src

.PHONY: clean-BSW-2f-Driver

