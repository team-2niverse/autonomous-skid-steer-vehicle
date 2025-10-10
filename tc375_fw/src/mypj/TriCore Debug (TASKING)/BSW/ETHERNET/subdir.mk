################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/ETHERNET/DoIP.c" \
"../BSW/ETHERNET/can-ethernet.c" \
"../BSW/ETHERNET/evadc.c" \
"../BSW/ETHERNET/geth_lwip.c" \
"../BSW/ETHERNET/tcp_echo.c" \
"../BSW/ETHERNET/udp_echo.c" 

COMPILED_SRCS += \
"BSW/ETHERNET/DoIP.src" \
"BSW/ETHERNET/can-ethernet.src" \
"BSW/ETHERNET/evadc.src" \
"BSW/ETHERNET/geth_lwip.src" \
"BSW/ETHERNET/tcp_echo.src" \
"BSW/ETHERNET/udp_echo.src" 

C_DEPS += \
"./BSW/ETHERNET/DoIP.d" \
"./BSW/ETHERNET/can-ethernet.d" \
"./BSW/ETHERNET/evadc.d" \
"./BSW/ETHERNET/geth_lwip.d" \
"./BSW/ETHERNET/tcp_echo.d" \
"./BSW/ETHERNET/udp_echo.d" 

OBJS += \
"BSW/ETHERNET/DoIP.o" \
"BSW/ETHERNET/can-ethernet.o" \
"BSW/ETHERNET/evadc.o" \
"BSW/ETHERNET/geth_lwip.o" \
"BSW/ETHERNET/tcp_echo.o" \
"BSW/ETHERNET/udp_echo.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/ETHERNET/DoIP.src":"../BSW/ETHERNET/DoIP.c" "BSW/ETHERNET/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/workspace_all/project2/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ETHERNET/DoIP.o":"BSW/ETHERNET/DoIP.src" "BSW/ETHERNET/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/ETHERNET/can-ethernet.src":"../BSW/ETHERNET/can-ethernet.c" "BSW/ETHERNET/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/workspace_all/project2/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ETHERNET/can-ethernet.o":"BSW/ETHERNET/can-ethernet.src" "BSW/ETHERNET/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/ETHERNET/evadc.src":"../BSW/ETHERNET/evadc.c" "BSW/ETHERNET/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/workspace_all/project2/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ETHERNET/evadc.o":"BSW/ETHERNET/evadc.src" "BSW/ETHERNET/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/ETHERNET/geth_lwip.src":"../BSW/ETHERNET/geth_lwip.c" "BSW/ETHERNET/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/workspace_all/project2/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ETHERNET/geth_lwip.o":"BSW/ETHERNET/geth_lwip.src" "BSW/ETHERNET/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/ETHERNET/tcp_echo.src":"../BSW/ETHERNET/tcp_echo.c" "BSW/ETHERNET/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/workspace_all/project2/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ETHERNET/tcp_echo.o":"BSW/ETHERNET/tcp_echo.src" "BSW/ETHERNET/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/ETHERNET/udp_echo.src":"../BSW/ETHERNET/udp_echo.c" "BSW/ETHERNET/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/workspace_all/project2/autonomous-skid-steer-vehicle/tc375_fw/src/mypj/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ETHERNET/udp_echo.o":"BSW/ETHERNET/udp_echo.src" "BSW/ETHERNET/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-ETHERNET

clean-BSW-2f-ETHERNET:
	-$(RM) ./BSW/ETHERNET/DoIP.d ./BSW/ETHERNET/DoIP.o ./BSW/ETHERNET/DoIP.src ./BSW/ETHERNET/can-ethernet.d ./BSW/ETHERNET/can-ethernet.o ./BSW/ETHERNET/can-ethernet.src ./BSW/ETHERNET/evadc.d ./BSW/ETHERNET/evadc.o ./BSW/ETHERNET/evadc.src ./BSW/ETHERNET/geth_lwip.d ./BSW/ETHERNET/geth_lwip.o ./BSW/ETHERNET/geth_lwip.src ./BSW/ETHERNET/tcp_echo.d ./BSW/ETHERNET/tcp_echo.o ./BSW/ETHERNET/tcp_echo.src ./BSW/ETHERNET/udp_echo.d ./BSW/ETHERNET/udp_echo.o ./BSW/ETHERNET/udp_echo.src

.PHONY: clean-BSW-2f-ETHERNET

