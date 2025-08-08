#!/bin/bash

CMD="docker run --device /dev/input --net host -it --rm ros:js-can-v5 ros2 launch joy2can tx_launch.xml"

echo $CMD
$CMD
