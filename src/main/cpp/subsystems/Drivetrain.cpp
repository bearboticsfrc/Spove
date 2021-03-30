// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include <frc/geometry/Pose2d.h>

Drivetrain::Drivetrain() {
    frontLeft.SetInverted(false);
    frontRight.SetInverted(true);

    backLeft.SetInverted(false);
    backRight.SetInverted(true);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

void Drivetrain::drive(double leftSpeed, double rightSpeed) {
    frontLeft.Set(ControlMode::PercentOutput, leftSpeed);
    backLeft.Set(ControlMode::PercentOutput, leftSpeed);
    frontRight.Set(ControlMode::PercentOutput, rightSpeed);
    backRight.Set(ControlMode::PercentOutput, rightSpeed);
}

void Drivetrain::SetPose(frc::Pose2d newPose) {
    previousPose = pose = newPose;
}

/*void Drivetrain::SetSpeed(double speed) {
    SetSpeeds(speed, speed);
}*/

/*void Drivetrain::SetSpeeds(units::meters_per_second_t lSpeed, units::meters_per_second_t rSpeed) {
    auto l = lSpeed.to<double>() / METERS_PER_REV * 60.0;
    auto r = rSpeed.to<double>() / METERS_PER_REV * 60.0;
}*/

frc::Pose2d Drivetrain::GetPose() {
    return pose;
}   

frc::Pose2d Drivetrain::GetLastPose() {
    return previousPose;
}

