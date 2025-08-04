#include <memory>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "can_msgs/msg/frame.hpp"

class Joy2CanNode : public rclcpp::Node {
public:
	Joy2CanNode() : Node("joy_to_can_node"), bitmask_button(0) {
		pub_ = this->create_publisher<can_msgs::msg::Frame>("/to_can_bus", 10);
		sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
				"/joy", 10,
				std::bind(&Joy2CanNode::joy_callback, this, std::placeholders::_1)
				);
	}
private:
	uint8_t bitmask_button;
	void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg) {
		if (msg->axes.size() < 4)
			return;

		float drive = msg->axes[1] * 255.0;
		float diff = drive * msg->axes[3];
		if (drive < 0)
			diff *= -1;
		int pwmA = static_cast<int>(std::round(drive - diff));
		int pwmB = static_cast<int>(std::round(drive + diff));

		if (pwmA > 255)
			pwmA = 255;
		else if (pwmA < -255)
			pwmA = -255;
		if (pwmB > 255)
			pwmB = 255;
		else if (pwmB < -255)
			pwmB = -255;

		can_msgs::msg::Frame can_msg;
		can_msg.id = 100;
		can_msg.is_rtr = false;
		can_msg.is_extended = false;
		can_msg.is_error = false;
		can_msg.dlc = 4;

		if (pwmA < 0) {
			can_msg.data[0] = 0;
			can_msg.data[1] = static_cast<uint8_t>(-pwmA);
		} else {
			can_msg.data[0] = 1;
			can_msg.data[1] = static_cast<uint8_t>(pwmA);
		}

		if (pwmB < 0) {
			can_msg.data[2] = 0;
			can_msg.data[3] = static_cast<uint8_t>(-pwmB);
		} else {
			can_msg.data[2] = 1;
			can_msg.data[3] = static_cast<uint8_t>(pwmB);
		}

		for (int i = can_msg.dlc; i < 8; i++)
			can_msg.data[i] = 0;
		can_msg.header.frame_id = "base_link";
		can_msg.header.stamp = this->now();

		pub_->publish(can_msg);
	}

	rclcpp::Publisher<can_msgs::msg::Frame>::SharedPtr pub_;
	rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub_;
};

int main(int argc, char* argv[]) {
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<Joy2CanNode>());
	rclcpp::shutdown();
	return 0;
}
