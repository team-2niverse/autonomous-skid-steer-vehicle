################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Tof/Tof.c 

COMPILED_SRCS += \
Bsw/Tof/Tof.src 

C_DEPS += \
Bsw/Tof/Tof.d 

OBJS += \
Bsw/Tof/Tof.o 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Tof/Tof.src: ../Bsw/Tof/Tof.c Bsw/Tof/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Team-2niverse/Pori/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Bsw/Tof/Tof.o: Bsw/Tof/Tof.src Bsw/Tof/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsw-2f-Tof

clean-Bsw-2f-Tof:
	-$(RM) Bsw/Tof/Tof.d Bsw/Tof/Tof.o Bsw/Tof/Tof.src

.PHONY: clean-Bsw-2f-Tof

