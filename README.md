# Path-planning
The objective of this project is to navigate a mobile robot through an obstacle course to a goal location. The start position of the robot as well as the locations of all obstacles and of the goal are given before the robot is started.

DESIGN

The robot uses a simple architecture. It consists of 6 components. They are 1 controller, 2 front wheels, 1 rear wheel, 2 motors (Motor_A , Motor_B). The 2 motors were attached to 2 wheels (Motor A one wheel and Motor B another wheel) using bridges. Then the motors were attached to the sides of
controller using bridges. In order to balance the structure of robot a third wheel was used. This wheel was attached at the midpoint of the rear end of the controller using a bridge. Motor_A and Motor_B were linked to ports A and B of the controller respectively. The main advantage of the structure is that the display screen side, battery port, motor and sensor ports were not packed. This avoided frequent dismantling of the structure. Also 75% of the weight is on the driving wheels which increases the friction and prevents it from slipping.

PROGRAM STRUCTURE

The program is implemented using C++. There are 3 main functions in the program.

· MoveForward(No_of_steps)- when this function is invoked the robot will move forward given number of steps. This is implemented by rotating both the motors in the same direction to certain number of rotations to reach the specified location.

· TurnLeft()- when this function is invoked the robot turns left by 90 degrees (approx.). This is implemented by rotating the motors in different directions (Motor_A moves forward and Motor_B moves backward) by a certain number of rotations.

· TurnRight()- when this function is invoked the robot turns right by 90 degrees (approx.). This is implemented by rotating the motors in different directions (Motor_A moves backward and Motor_B moves forward) by a certain number of rotations. 

PATH PLANNING

This algorithm uses Manhattan distance between the start and the goal location. The algorithm consists of the following steps:

Step1: Create an array of 16x10 size and initialize all elements with zero.

Step2: Mark all the location containing the obstacles with value -1.

Step3: Mark the goal location with value of 1.

Step4: MarkAroundGoal(). Mark the neighbors of goal and their neighbors till a neighbor is a boundary or an obstacle, with value 1+the value of that location.

Step5: MarkArroundMarked(). Mark the neighbors of the marked vertices.

Step6: MarkAroundObstacles(). Mark around obstacles, so that no tile remains unmarked.

Step7: Beginning from the start location, move the robot to a location with a value one less than the value of current location till goal location is reached (i.e. value of current location is one).

Step8: Exit once goal is reached.

PID CONTROLLER

In order to implement these functions precisely we experimented with various values for parameters such as speed and the number of rotations required for Motor_A and Motor_B. When the motor was moving forward, since both the motors had different rotational speed (even though the percentage of rotational speed is same), the robot was deviating from its path. So in order to compensate for the deviation a function called Reallign() is invoked within MoveForward() whenever difference in counts of motor goes beyond certain threshold. This compensates for the deviation by realigning the robot to its path by turning the robot on to one side slightly (left or right) depending on its original path. Also in order to make the movement as straight as possible the percentage of rotational speed of the motors were also different. Motor_A was given more percentage of rotational speed value than Motor_B.



