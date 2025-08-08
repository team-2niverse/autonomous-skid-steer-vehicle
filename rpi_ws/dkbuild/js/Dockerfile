FROM ros:humble
WORKDIR /root
COPY joy2can /root/ros_ws/src/joy2can

RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-humble-joy

RUN cd ros_ws && rosdep install --from-paths src -y --ignore-src \
    && . /opt/ros/humble/setup.sh && colcon build --symlink-install

RUN sed -i '5a source /root/ros_ws/install/setup.bash' /ros_entrypoint.sh \
    && rm -rf /var/lib/apt/lists/*
