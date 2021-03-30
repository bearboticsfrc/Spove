// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "frc2/command/Command.h"
#include <frc/smartdashboard/SmartDashboard.h>

RobotContainer::RobotContainer() : 
m_aRed(&m_drivetrain),
m_bRed(&m_drivetrain),
m_aBlue(&m_drivetrain),
m_bBlue(&m_drivetrain),
m_autonomousCommand(&m_subsystem),
m_arduino() {
  // Initialize all of your commands and subsystems here
  
  // Configure the button bindings
  ConfigureButtonBindings();
  m_drivetrain.SetDefaultCommand(m_xboxdrive);
  //m_drivetrain.Register();
  frc::SmartDashboard::PutData("Ball Track", &m_balltrack);
}


void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    switch (choosers.autonomousChoice()) {
    case AutonomousChoice::ARed:
      return &m_aRed;
    case AutonomousChoice::BRed:
      return &m_bRed;
    case AutonomousChoice::ABlue:
      return &m_aBlue;
    case AutonomousChoice::BBlue:
      return &m_bBlue;
    default:
      std::cerr << "UNHANDLED OPTION FOR AUTONOMOUS\n";
      return nullptr;
  }
}
