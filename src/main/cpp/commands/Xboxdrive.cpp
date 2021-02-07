// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Xboxdrive.h"

using JoystickHand = frc::GenericHID::JoystickHand;

Xboxdrive::Xboxdrive(frc::XboxController *xboxcontroller, Drivetrain *drivetrain)
: m_xboxcontroller{xboxcontroller},m_drivetrain{drivetrain}  
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivetrain);
}

// Called when the command is initially scheduled.
void Xboxdrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Xboxdrive::Execute() {
    double speed = -m_xboxcontroller->GetY(JoystickHand::kLeftHand);
    double turn = m_xboxcontroller->GetX(JoystickHand::kLeftHand);
    m_drivetrain->drive(speed + turn,speed - turn);
    }

// Called once the command ends or is interrupted.
void Xboxdrive::End(bool interrupted) {}

// Returns true when the command should end.
bool Xboxdrive::IsFinished() {
  return false;
}
