################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ASW/ABE/Abe.c 

COMPILED_SRCS += \
ASW/ABE/Abe.src 

C_DEPS += \
ASW/ABE/Abe.d 

OBJS += \
ASW/ABE/Abe.o 


# Each subdirectory must supply rules for building sources it contributes
ASW/ABE/Abe.src: ../ASW/ABE/Abe.c ASW/ABE/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/Coding/C/proj1/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
ASW/ABE/Abe.o: ASW/ABE/Abe.src ASW/ABE/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-ASW-2f-ABE

clean-ASW-2f-ABE:
	-$(RM) ASW/ABE/Abe.d ASW/ABE/Abe.o ASW/ABE/Abe.src

.PHONY: clean-ASW-2f-ABE

