################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../ASW/SOMEIP/someip.c" 

COMPILED_SRCS += \
"ASW/SOMEIP/someip.src" 

C_DEPS += \
"./ASW/SOMEIP/someip.d" 

OBJS += \
"ASW/SOMEIP/someip.o" 


# Each subdirectory must supply rules for building sources it contributes
"ASW/SOMEIP/someip.src":"../ASW/SOMEIP/someip.c" "ASW/SOMEIP/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/workspace_all/project2_debug/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"ASW/SOMEIP/someip.o":"ASW/SOMEIP/someip.src" "ASW/SOMEIP/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-ASW-2f-SOMEIP

clean-ASW-2f-SOMEIP:
	-$(RM) ./ASW/SOMEIP/someip.d ./ASW/SOMEIP/someip.o ./ASW/SOMEIP/someip.src

.PHONY: clean-ASW-2f-SOMEIP

