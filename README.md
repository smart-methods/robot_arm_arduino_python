# robot_arm_arduino_python
Python code uses ikpy library to apply forward and inverse kinematics. The results will be executed to the robot arm by using Arduino code.

The python code was tested in python 3.6


## Dependencies
### python libraries
```
$ pip install ikpy
$ pip install matplotlib
```


## Robot Arm
The robot arm has 5 joints only 4 joints are configured in the python code, the last joint (gripper) has a default motion executed from the Arduino code directly.
### Circuit diagram 
![circuit](circuit.png)
### Robot initial positions
![positions](positions.png)

## Usage
- Run test_ikpy.py script and get the angles
- Upload kinematics.ino Arduino code and open the serial monitor to enter the angles, use this format:
```0.0, 0.0, 0.0, 0.0```

(Note: all the codes use radians in the range -1.57 to 1.57)

## The end
