################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Controller/rtGetInf.c \
../App/Controller/rtGetNaN.c \
../App/Controller/rt_nonfinite.c \
../App/Controller/skid_steer_controller.c 

COMPILED_SRCS += \
App/Controller/rtGetInf.src \
App/Controller/rtGetNaN.src \
App/Controller/rt_nonfinite.src \
App/Controller/skid_steer_controller.src 

C_DEPS += \
App/Controller/rtGetInf.d \
App/Controller/rtGetNaN.d \
App/Controller/rt_nonfinite.d \
App/Controller/skid_steer_controller.d 

OBJS += \
App/Controller/rtGetInf.o \
App/Controller/rtGetNaN.o \
App/Controller/rt_nonfinite.o \
App/Controller/skid_steer_controller.o 


# Each subdirectory must supply rules for building sources it contributes
App/Controller/rtGetInf.src: ../App/Controller/rtGetInf.c App/Controller/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Controller/rtGetInf.o: App/Controller/rtGetInf.src App/Controller/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
App/Controller/rtGetNaN.src: ../App/Controller/rtGetNaN.c App/Controller/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Controller/rtGetNaN.o: App/Controller/rtGetNaN.src App/Controller/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
App/Controller/rt_nonfinite.src: ../App/Controller/rt_nonfinite.c App/Controller/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Controller/rt_nonfinite.o: App/Controller/rt_nonfinite.src App/Controller/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
App/Controller/skid_steer_controller.src: ../App/Controller/skid_steer_controller.c App/Controller/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/autoever/Repos/team_2niverse/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
App/Controller/skid_steer_controller.o: App/Controller/skid_steer_controller.src App/Controller/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-App-2f-Controller

clean-App-2f-Controller:
	-$(RM) App/Controller/rtGetInf.d App/Controller/rtGetInf.o App/Controller/rtGetInf.src App/Controller/rtGetNaN.d App/Controller/rtGetNaN.o App/Controller/rtGetNaN.src App/Controller/rt_nonfinite.d App/Controller/rt_nonfinite.o App/Controller/rt_nonfinite.src App/Controller/skid_steer_controller.d App/Controller/skid_steer_controller.o App/Controller/skid_steer_controller.src

.PHONY: clean-App-2f-Controller

