// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include "commands/ExampleCommand.h"
#include "commands/Xboxdrive.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Drivetrain.h"
#include "Arduino.h"
#include "commands/BallTrack.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  Arduino m_arduino;
  
 public:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand; 

  void ConfigureButtonBindings();
  Drivetrain m_drivetrain;
  frc::XboxController m_xboxcontroller0 = frc::XboxController(0);
  frc::XboxController m_xboxcontroller1 = frc::XboxController(1);
  Xboxdrive m_xboxdrive = Xboxdrive(&m_xboxcontroller0, &m_xboxcontroller1, &m_drivetrain);
  BallTrack m_balltrack = BallTrack(&m_arduino, &m_drivetrain);
};