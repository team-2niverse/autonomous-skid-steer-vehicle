################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/GPT12/Gpt12.c 

COMPILED_SRCS += \
BSW/GPT12/Gpt12.src 

C_DEPS += \
BSW/GPT12/Gpt12.d 

OBJS += \
BSW/GPT12/Gpt12.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/GPT12/Gpt12.src: ../BSW/GPT12/Gpt12.c BSW/GPT12/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Project_Mini/combine/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
BSW/GPT12/Gpt12.o: BSW/GPT12/Gpt12.src BSW/GPT12/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-GPT12

clean-BSW-2f-GPT12:
	-$(RM) BSW/GPT12/Gpt12.d BSW/GPT12/Gpt12.o BSW/GPT12/Gpt12.src

.PHONY: clean-BSW-2f-GPT12

