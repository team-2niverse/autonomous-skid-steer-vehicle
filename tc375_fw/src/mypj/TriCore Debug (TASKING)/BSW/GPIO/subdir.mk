################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/GPIO/Buzzer.c \
../BSW/GPIO/Led.c 

COMPILED_SRCS += \
BSW/GPIO/Buzzer.src \
BSW/GPIO/Led.src 

C_DEPS += \
BSW/GPIO/Buzzer.d \
BSW/GPIO/Led.d 

OBJS += \
BSW/GPIO/Buzzer.o \
BSW/GPIO/Led.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/GPIO/Buzzer.src: ../BSW/GPIO/Buzzer.c BSW/GPIO/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/GPIO/Buzzer.o: BSW/GPIO/Buzzer.src BSW/GPIO/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/GPIO/Led.src: ../BSW/GPIO/Led.c BSW/GPIO/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/GPIO/Led.o: BSW/GPIO/Led.src BSW/GPIO/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-GPIO

clean-BSW-2f-GPIO:
	-$(RM) BSW/GPIO/Buzzer.d BSW/GPIO/Buzzer.o BSW/GPIO/Buzzer.src BSW/GPIO/Led.d BSW/GPIO/Led.o BSW/GPIO/Led.src

.PHONY: clean-BSW-2f-GPIO

