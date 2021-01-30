// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Joystickdrive.h"

Joystickdrive::Joystickdrive(frc::Joystick *joystick, Drivetrain *drivetrain) 
 : m_joystick{joystick},m_drivetrain{drivetrain}
 {
   AddRequirements(m_drivetrain);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Joystickdrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Joystickdrive::Execute() {
   double speed = m_joystick->GetY();
   m_drivetrain->drive(speed,speed);
   
   }

// Called once the command ends or is interrupted.
void Joystickdrive::End(bool interrupted) {}

// Returns true when the command should end.
bool Joystickdrive::IsFinished() {
  return false;
}
