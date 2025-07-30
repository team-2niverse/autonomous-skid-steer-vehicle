################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MATLAB/rtGetInf.c \
../MATLAB/rtGetNaN.c \
../MATLAB/rt_nonfinite.c \
../MATLAB/skid_steer_controller.c 

COMPILED_SRCS += \
MATLAB/rtGetInf.src \
MATLAB/rtGetNaN.src \
MATLAB/rt_nonfinite.src \
MATLAB/skid_steer_controller.src 

C_DEPS += \
MATLAB/rtGetInf.d \
MATLAB/rtGetNaN.d \
MATLAB/rt_nonfinite.d \
MATLAB/skid_steer_controller.d 

OBJS += \
MATLAB/rtGetInf.o \
MATLAB/rtGetNaN.o \
MATLAB/rt_nonfinite.o \
MATLAB/skid_steer_controller.o 


# Each subdirectory must supply rules for building sources it contributes
MATLAB/rtGetInf.src: ../MATLAB/rtGetInf.c MATLAB/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/Coding/C/proj1/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
MATLAB/rtGetInf.o: MATLAB/rtGetInf.src MATLAB/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
MATLAB/rtGetNaN.src: ../MATLAB/rtGetNaN.c MATLAB/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/Coding/C/proj1/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
MATLAB/rtGetNaN.o: MATLAB/rtGetNaN.src MATLAB/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
MATLAB/rt_nonfinite.src: ../MATLAB/rt_nonfinite.c MATLAB/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/Coding/C/proj1/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
MATLAB/rt_nonfinite.o: MATLAB/rt_nonfinite.src MATLAB/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
MATLAB/skid_steer_controller.src: ../MATLAB/skid_steer_controller.c MATLAB/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/Coding/C/proj1/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
MATLAB/skid_steer_controller.o: MATLAB/skid_steer_controller.src MATLAB/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-MATLAB

clean-MATLAB:
	-$(RM) MATLAB/rtGetInf.d MATLAB/rtGetInf.o MATLAB/rtGetInf.src MATLAB/rtGetNaN.d MATLAB/rtGetNaN.o MATLAB/rtGetNaN.src MATLAB/rt_nonfinite.d MATLAB/rt_nonfinite.o MATLAB/rt_nonfinite.src MATLAB/skid_steer_controller.d MATLAB/skid_steer_controller.o MATLAB/skid_steer_controller.src

.PHONY: clean-MATLAB

