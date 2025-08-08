#!/bin/bash

CMD="docker run --device /dev/input --net host -it --rm ros:ssv ros2 launch skid_steer_vehicle bringup.launch.xml"

echo $CMD
$CMD
