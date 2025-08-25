# VEX Robotics Control System

## Overview
This repository provides a reusable control system for VEX V5 robots. It includes PID-based motion control, odometry tracking and a simple autonomous routine selector.

## Getting Started
1. Clone this repository and open it in VEXcode Pro V5.
2. Connect your hardware to match the port assignments in `include/robot-config.h`.
3. Update the `Drive` constructor in `src/main.cpp` to match your drivetrain's geometry and sensor ports.
4. Build and download the project to the VEX Brain.
5. Before a match, tap the VEX Brain screen to cycle through the available autonomous routines.

## Drive Constructor
The `Drive` object configures the drivetrain and tracking sensors. An example setup is shown below:

```
Drive chassis(
    TANK_ONE_ROTATION,                 // drive configuration
    motor_group(BLMotor, FLMotor, MLMotor), // left motors
    motor_group(BRMotor, FRMotor, MRMotor), // right motors
    PORT16,                            // inertial sensor port
    3.08,                              // wheel diameter (in)
    2.5,                               // external gear ratio
    360,                               // gyro scale
    PORT1, -PORT2, PORT3, -PORT4,      // individual motor ports (sign indicates direction)
    PORT5, 2.75, 1,                    // forward tracking wheel port, diameter, offset
    PORT5, 2.75, 5.2                   // sideways tracking wheel port, diameter, offset
);
```

Key drive methods include:
- `drive_distance(distance, heading)` – drive a specified distance while holding a heading.
- `turn_to_angle(angle)` – rotate the robot to an absolute angle.
- `drive_to_point(x, y)` – move to a field coordinate using odometry.
- `control_arcade()` – enable arcade style driver control.

## Autonomous Selection
During `pre_auton`, the Brain's touchscreen acts as an auton cycler. Each tap advances to the next autonomous routine and displays its name on-screen.

## License
This project is released as open source for educational use.

