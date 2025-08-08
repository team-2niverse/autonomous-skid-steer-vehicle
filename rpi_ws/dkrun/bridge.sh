#!/bin/bash

CMD="docker run --device /dev/input --net host -it --rm ros:js-can-v6 ros2 launch joy2can bridge_launch.xml"

echo $CMD
$CMD
