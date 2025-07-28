################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Can/Can.c 

COMPILED_SRCS += \
Bsw/Can/Can.src 

C_DEPS += \
Bsw/Can/Can.d 

OBJS += \
Bsw/Can/Can.o 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Can/Can.src: ../Bsw/Can/Can.c Bsw/Can/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Team-2niverse/Pori/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Bsw/Can/Can.o: Bsw/Can/Can.src Bsw/Can/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsw-2f-Can

clean-Bsw-2f-Can:
	-$(RM) Bsw/Can/Can.d Bsw/Can/Can.o Bsw/Can/Can.src

.PHONY: clean-Bsw-2f-Can

