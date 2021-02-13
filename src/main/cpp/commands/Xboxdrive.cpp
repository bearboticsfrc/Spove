// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Xboxdrive.h"
#include "units_include.h"

using JoystickHand = frc::GenericHID::JoystickHand;

const double DEADZONE = 0.075;

template<class T> int signum(T value) {
    return (value > T{0}) - (value < T{0});
}

double applyDeadzone(double value) {
    double sign = signum(value);
    double magn = std::abs(value);

    if (magn < DEADZONE) {
        return 0.0;
    }

    double newMag = (magn - DEADZONE) / (1.0 - DEADZONE);
    return newMag * sign;
}

double applyFilters(double value) {
    double deadzoned = applyDeadzone(value);
    return std::pow(deadzoned, 3.0);
}

double Xboxdrive::GetX() const {
    return applyFilters((m_xboxcontroller0->GetX(JoystickHand::kLeftHand)) * 0.9);
}

double Xboxdrive::GetY() const {
    return applyFilters(-m_xboxcontroller0->GetY(JoystickHand::kLeftHand));
}


Xboxdrive::Xboxdrive(frc::XboxController *xboxcontroller0, frc::XboxController *xboxcontroller1, Drivetrain *drivetrain)
: m_xboxcontroller0{xboxcontroller0}, m_xboxcontroller1{xboxcontroller1}, m_drivetrain{drivetrain}  
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivetrain);
}

// Called when the command is initially scheduled.
void Xboxdrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Xboxdrive::Execute() {
    double speed = Xboxdrive::GetY();
    double turn = Xboxdrive::GetX();
    m_drivetrain->drive(speed + turn,speed - turn);
    }

// Called once the command ends or is interrupted.
void Xboxdrive::End(bool interrupted) {}

// Returns true when the command should end.
bool Xboxdrive::IsFinished() {
  return false;
}
