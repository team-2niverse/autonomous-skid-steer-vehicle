################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/IO/Bluetooth.c \
../BSW/IO/Buzzer.c \
../BSW/IO/GPIO.c \
../BSW/IO/UltraSonic.c \
../BSW/IO/gpt12.c 

COMPILED_SRCS += \
BSW/IO/Bluetooth.src \
BSW/IO/Buzzer.src \
BSW/IO/GPIO.src \
BSW/IO/UltraSonic.src \
BSW/IO/gpt12.src 

C_DEPS += \
BSW/IO/Bluetooth.d \
BSW/IO/Buzzer.d \
BSW/IO/GPIO.d \
BSW/IO/UltraSonic.d \
BSW/IO/gpt12.d 

OBJS += \
BSW/IO/Bluetooth.o \
BSW/IO/Buzzer.o \
BSW/IO/GPIO.o \
BSW/IO/UltraSonic.o \
BSW/IO/gpt12.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/IO/Bluetooth.src: ../BSW/IO/Bluetooth.c BSW/IO/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/IO/Bluetooth.o: BSW/IO/Bluetooth.src BSW/IO/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/IO/Buzzer.src: ../BSW/IO/Buzzer.c BSW/IO/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/IO/Buzzer.o: BSW/IO/Buzzer.src BSW/IO/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/IO/GPIO.src: ../BSW/IO/GPIO.c BSW/IO/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/IO/GPIO.o: BSW/IO/GPIO.src BSW/IO/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/IO/UltraSonic.src: ../BSW/IO/UltraSonic.c BSW/IO/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/IO/UltraSonic.o: BSW/IO/UltraSonic.src BSW/IO/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
BSW/IO/gpt12.src: ../BSW/IO/gpt12.c BSW/IO/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/IO/gpt12.o: BSW/IO/gpt12.src BSW/IO/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-IO

clean-BSW-2f-IO:
	-$(RM) BSW/IO/Bluetooth.d BSW/IO/Bluetooth.o BSW/IO/Bluetooth.src BSW/IO/Buzzer.d BSW/IO/Buzzer.o BSW/IO/Buzzer.src BSW/IO/GPIO.d BSW/IO/GPIO.o BSW/IO/GPIO.src BSW/IO/UltraSonic.d BSW/IO/UltraSonic.o BSW/IO/UltraSonic.src BSW/IO/gpt12.d BSW/IO/gpt12.o BSW/IO/gpt12.src

.PHONY: clean-BSW-2f-IO

