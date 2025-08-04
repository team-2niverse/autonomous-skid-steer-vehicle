################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/PID/Pid.c 

COMPILED_SRCS += \
BSW/PID/Pid.src 

C_DEPS += \
BSW/PID/Pid.d 

OBJS += \
BSW/PID/Pid.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/PID/Pid.src: ../BSW/PID/Pid.c BSW/PID/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/Coding/C/proj1/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/PID/Pid.o: BSW/PID/Pid.src BSW/PID/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-PID

clean-BSW-2f-PID:
	-$(RM) BSW/PID/Pid.d BSW/PID/Pid.o BSW/PID/Pid.src

.PHONY: clean-BSW-2f-PID

