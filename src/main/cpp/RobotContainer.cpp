// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "frc2/command/Command.h"
#include <frc/smartdashboard/SmartDashboard.h>

RobotContainer::RobotContainer() : 
m_autonomousCommand(&m_subsystem),
m_arduino() {
  // Initialize all of your commands and subsystems here
  
  // Configure the button bindings
  ConfigureButtonBindings();
  m_drivetrain.SetDefaultCommand(m_joystickdrive);
  //m_drivetrain.Register();
  frc::SmartDashboard::PutData("Ball Track", &m_balltrack);
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
