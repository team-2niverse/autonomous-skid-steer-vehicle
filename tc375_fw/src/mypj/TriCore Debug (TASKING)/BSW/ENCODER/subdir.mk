################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/ENCODER/Encoder.c 

COMPILED_SRCS += \
BSW/ENCODER/Encoder.src 

C_DEPS += \
BSW/ENCODER/Encoder.d 

OBJS += \
BSW/ENCODER/Encoder.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/ENCODER/Encoder.src: ../BSW/ENCODER/Encoder.c BSW/ENCODER/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/ENCODER/Encoder.o: BSW/ENCODER/Encoder.src BSW/ENCODER/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-ENCODER

clean-BSW-2f-ENCODER:
	-$(RM) BSW/ENCODER/Encoder.d BSW/ENCODER/Encoder.o BSW/ENCODER/Encoder.src

.PHONY: clean-BSW-2f-ENCODER

