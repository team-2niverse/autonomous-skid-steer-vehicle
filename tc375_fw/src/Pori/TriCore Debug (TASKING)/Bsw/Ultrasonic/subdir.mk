################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Ultrasonic/Ultrasonic.c 

COMPILED_SRCS += \
Bsw/Ultrasonic/Ultrasonic.src 

C_DEPS += \
Bsw/Ultrasonic/Ultrasonic.d 

OBJS += \
Bsw/Ultrasonic/Ultrasonic.o 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Ultrasonic/Ultrasonic.src: ../Bsw/Ultrasonic/Ultrasonic.c Bsw/Ultrasonic/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Team-2niverse/Pori/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Bsw/Ultrasonic/Ultrasonic.o: Bsw/Ultrasonic/Ultrasonic.src Bsw/Ultrasonic/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsw-2f-Ultrasonic

clean-Bsw-2f-Ultrasonic:
	-$(RM) Bsw/Ultrasonic/Ultrasonic.d Bsw/Ultrasonic/Ultrasonic.o Bsw/Ultrasonic/Ultrasonic.src

.PHONY: clean-Bsw-2f-Ultrasonic

