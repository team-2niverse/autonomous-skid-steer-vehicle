################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/MOTOR/Motor.c 

COMPILED_SRCS += \
BSW/MOTOR/Motor.src 

C_DEPS += \
BSW/MOTOR/Motor.d 

OBJS += \
BSW/MOTOR/Motor.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/MOTOR/Motor.src: ../BSW/MOTOR/Motor.c BSW/MOTOR/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/MOTOR/Motor.o: BSW/MOTOR/Motor.src BSW/MOTOR/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-MOTOR

clean-BSW-2f-MOTOR:
	-$(RM) BSW/MOTOR/Motor.d BSW/MOTOR/Motor.o BSW/MOTOR/Motor.src

.PHONY: clean-BSW-2f-MOTOR

