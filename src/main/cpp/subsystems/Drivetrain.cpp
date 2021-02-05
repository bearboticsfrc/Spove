// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {
    frontLeft.SetInverted(false);
    frontRight.SetInverted(false);

    backLeft.SetInverted(false);
    backRight.SetInverted(false);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

void Drivetrain::drive(double leftSpeed, double rightSpeed) {
    frontLeft.Set(ControlMode::PercentOutput, leftSpeed);
    backLeft.Set(ControlMode::PercentOutput, leftSpeed);
    frontRight.Set(ControlMode::PercentOutput, rightSpeed);
    backRight.Set(ControlMode::PercentOutput, rightSpeed);
}


