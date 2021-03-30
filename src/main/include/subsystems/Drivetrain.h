// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/smartdashboard/FieldObject2d.h"

#include <ctre/Phoenix.h>
#include <frc/geometry/Pose2d.h>
#include <units/velocity.h>
#include <units/length.h>
#include "units_include.h"
const double WHEEL_DIAMETER = 0.1524 /* 6 inches */;
const double METERS_PER_WHEEL_REV = WHEEL_DIAMETER * 3.1415926535897984626433;
const double METERS_PER_REV = METERS_PER_WHEEL_REV / 5.25;

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  void drive(double leftSpeed, double rightSpeed);
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  //void SetSpeed(double speed);
  //void SetSpeeds(double leftSpeed, double rightSpeed);
  //void SetSpeeds(units::meters_per_second_t leftSpeed, units::meters_per_second_t rightSpeed);

  units::meter_t GetAverageEncoder() ;

  frc::Pose2d GetPose();

  frc::Pose2d GetLastPose();

  void SetPose(frc::Pose2d newPose);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  TalonSRX frontLeft = TalonSRX(8);
  VictorSPX backLeft = VictorSPX(7);
  TalonSRX frontRight = TalonSRX(5);
  VictorSPX backRight = VictorSPX(6);

  frc::Pose2d previousPose;
  frc::Pose2d pose;
};
