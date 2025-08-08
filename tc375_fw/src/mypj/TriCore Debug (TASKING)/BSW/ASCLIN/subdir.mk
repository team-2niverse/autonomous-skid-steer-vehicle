################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/ASCLIN/Asclin.c 

COMPILED_SRCS += \
BSW/ASCLIN/Asclin.src 

C_DEPS += \
BSW/ASCLIN/Asclin.d 

OBJS += \
BSW/ASCLIN/Asclin.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/ASCLIN/Asclin.src: ../BSW/ASCLIN/Asclin.c BSW/ASCLIN/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/ASCLIN/Asclin.o: BSW/ASCLIN/Asclin.src BSW/ASCLIN/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-ASCLIN

clean-BSW-2f-ASCLIN:
	-$(RM) BSW/ASCLIN/Asclin.d BSW/ASCLIN/Asclin.o BSW/ASCLIN/Asclin.src

.PHONY: clean-BSW-2f-ASCLIN

