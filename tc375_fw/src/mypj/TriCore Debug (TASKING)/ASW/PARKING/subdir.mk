################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ASW/PARKING/Parking.c 

COMPILED_SRCS += \
ASW/PARKING/Parking.src 

C_DEPS += \
ASW/PARKING/Parking.d 

OBJS += \
ASW/PARKING/Parking.o 


# Each subdirectory must supply rules for building sources it contributes
ASW/PARKING/Parking.src: ../ASW/PARKING/Parking.c ASW/PARKING/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
ASW/PARKING/Parking.o: ASW/PARKING/Parking.src ASW/PARKING/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-ASW-2f-PARKING

clean-ASW-2f-PARKING:
	-$(RM) ASW/PARKING/Parking.d ASW/PARKING/Parking.o ASW/PARKING/Parking.src

.PHONY: clean-ASW-2f-PARKING

