import ikpy
import numpy as np
import ikpy.utils.plot as plot_utils
import matplotlib.pyplot
from mpl_toolkits.mplot3d import Axes3D

##configuration##
my_chain = ikpy.chain.Chain.from_urdf_file("./robot_urdf/urdf/arduino_robot_arm.urdf",
                                           base_elements=["base"],
                                           last_link_vector=[0.13, 0, 0])
my_chain.active_links_mask = [False, True, True, True, True, False]
#print(my_chain)

##kinematics##
angles = [0, -0.8, -0.8, -0.8, -0.8, 0] #use radian, ranges -1.57 to 1.57
position_fk = my_chain.forward_kinematics(angles)[:3, 3]
orientation_fk = my_chain.forward_kinematics(angles)[:3, 0]
print("FK solver:")
print("position in meters", position_fk)
angles_ik = my_chain.inverse_kinematics(position_fk)
print("\nIK solver:")
print("angles in radian", angles_ik)

##plotting##
ax = matplotlib.pyplot.figure().add_subplot(111, projection='3d')
my_chain.plot(angles, ax)
my_chain.plot(angles_ik, ax)
matplotlib.pyplot.show()
