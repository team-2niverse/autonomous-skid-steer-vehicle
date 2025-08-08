#!/bin/bash

CMD="docker run \
	--privileged \
	--net host \
	-it \
	-e DISPLAY=$DISPLAY \
	-v /tmp/.X11-unix:/tmp/.X11-unix \
	ros:humble-desktop"

SET_XHOST="xhost +local:docker"
UNSET_XHOST="xhost -local:docker"

echo $SET_XHOST
$SET_XHOST
echo $CMD
$CMD
echo $UNSET_XHOST
$UNSET_XHOST
