################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Motor.c \
../PID.c 

COMPILED_SRCS += \
Motor.src \
PID.src 

C_DEPS += \
Motor.d \
PID.d 

OBJS += \
Motor.o \
PID.o 


# Each subdirectory must supply rules for building sources it contributes
Motor.src: ../Motor.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Motor.o: Motor.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
PID.src: ../PID.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
PID.o: PID.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean--2e-

clean--2e-:
	-$(RM) Motor.d Motor.o Motor.src PID.d PID.o PID.src

.PHONY: clean--2e-

