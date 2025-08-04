################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ASW/ABE/Aeb.c 

COMPILED_SRCS += \
ASW/ABE/Aeb.src 

C_DEPS += \
ASW/ABE/Aeb.d 

OBJS += \
ASW/ABE/Aeb.o 


# Each subdirectory must supply rules for building sources it contributes
ASW/ABE/Aeb.src: ../ASW/ABE/Aeb.c ASW/ABE/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
ASW/ABE/Aeb.o: ASW/ABE/Aeb.src ASW/ABE/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-ASW-2f-ABE

clean-ASW-2f-ABE:
	-$(RM) ASW/ABE/Aeb.d ASW/ABE/Aeb.o ASW/ABE/Aeb.src

.PHONY: clean-ASW-2f-ABE

