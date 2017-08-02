import sys
import io

def generate_xml(indices):

	# generate file containing uri and frame arguments for each Flie
	part_one = open("part_one.launch", "w")

	for i in indices:
		str_i = str(i)

		# <arg name="uri_3" default="radio://0/100/2M/0xE7E7E7E703" />
		if i < 10: # single digit
			part_one.write('<arg name="uri_' + str_i + '" default="radio://0/100/2M/0xE7E7E7E70' + str_i + '" />\n')
		else: # double digit
			part_one.write('<arg name="uri_' + str_i + '" default="radio://0/100/2M/0xE7E7E7E7' + str_i + '" />\n' )

		# <arg name="frame_3" default="/vicon/CrazyflieQW_3/CrazyflieQW_3" />
		part_one.write('<arg name="frame_' + str_i + '" default="/vicon/CrazyflieQW_' + str_i + '/CrazyflieQW_' + str_i + '" />\n')

	part_one.close()


	# generate file containing each Flie's name param for the pose node
	  # and a group for each Flie
	part_two = open("part_two.launch", "w")

	part_two.write('<node name="pose" pkg="crazyflie_swarm" type="publish_pose_2.py" output="screen">\n')
	part_two.write('\t<param name="key_topic" value="key_event" />\n')

	for i in indices:
		part_two.write('\t<param name="goal_topic_' + str(i) + '" value="crazyflie_' + str(i) + '/goal" />\n')

	part_two.write('\t<param name="rate" value="60" />\n')
	part_two.write('</node>\n\n')

	for i in indices:
		str_i = str(i)

		part_two.write('<group ns="crazyflie_' + str_i + '">\n')

		part_two.write('\t<include file="$(find crazyflie_driver)/launch/crazyflie_add.launch">\n')
		part_two.write('\t\t<arg name="uri" value="$(arg uri_' + str_i + '" />\n')
		part_two.write('\t\t<arg name="tf_prefix" value="crazyflie_' + str_i + '" />\n')
		part_two.write('\t\t<arg name="enable_logging" value="True" />\n')
		part_two.write('\t</include>\n')

		part_two.write('\t<node name="Service_Proxy" pkg="crazyflie_swarm" type="service_proxy.py" output="screen">\n')
		part_two.write('\t\t<param name="use_crazyflie_controller" value="True" />\n')
		part_two.write('\t\t<param name="use_crazyflie_controller" value="True" />\n')
		part_two.write('\t\t<param name="key_topic" value="/key_event" />\n')
		part_two.write('\t</node>\n')

		part_two.write('\t<include file="$(find crazyflie_controller)/launch/crazyflie2.launch">\n')
		part_two.write('\t\t<arg name="frame" value="$(arg frame_' + str_i + ')" />\n')
		part_two.write('\t</include>\n')

		part_two.write('\t<node pkg="tf" type="static_transform_publisher" name="baselink_broadcaster" args="0 0 0 0 0 0 1 $(arg frame_' + str_i + ') /crazyflie/base_link 100" />\n')

		part_two.write('</group>\n\n')

	part_two.close()


if __name__ == "__main__":

	# syntax: { 2 3 5 } means Crazyflies 2, 3, 5
	#		  [ 1 10 ] means Crazyflies 1, 2, 3, ... 10

	x = raw_input("Enter a range ([]) or a specific set ({}) of indices: ")
	split_x = x.split()

	if split_x[0] == '{':
		indices = [int(split_x[i]) for i in range(1, len(split_x) - 1)]
	else:
		indices = range(int(split_x[1]), int(split_x[2]) + 1)

	generate_xml(indices)
