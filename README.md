# VEX V5 Control System — Robotics Control Framework

## Overview
A demonstration of advanced control system concepts for VEX V5 robotics, featuring PID-based motion control, odometry tracking, and autonomous routine selection. This framework showcases modern robotics control algorithms and software architecture patterns.

## Features
- PID-based motion control with tunable parameters
- Real-time odometry tracking using wheel encoders and gyroscope
- Autonomous routine selector with touchscreen interface
- Modular drivetrain configuration system
- Comprehensive motion control API

## Technical Architecture
The `Drive` object configures the drivetrain and tracking sensors. The system demonstrates:

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

Key control system methods:
- `drive_distance(distance, heading)` — precise distance control with heading correction
- `turn_to_angle(angle)` — absolute angle positioning using gyroscope feedback
- `drive_to_point(x, y)` — coordinate-based navigation with odometry
- `control_arcade()` — manual control interface

## Control System Features
The framework demonstrates advanced robotics concepts including closed-loop control, sensor fusion, and autonomous behavior selection through an interactive touchscreen interface.

## License
This project is released as open source for educational use.

