FROM ros:humble
WORKDIR /root
COPY skid_steer_vehicle /root/ros_ws/src/skid_steer_vehicle

RUN cd ros_ws && apt-get update && rosdep update \
    && rosdep install --from-paths src -y --ignore-src \
    && . /opt/ros/humble/setup.sh && colcon build --symlink-install

RUN sed -i '5a source /root/ros_ws/install/setup.bash' /ros_entrypoint.sh \
    && rm -rf /var/lib/apt/lists/*
