// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/BallTrack.h"

BallTrack::BallTrack(Arduino *arduino, Drivetrain *drivetrain) 
 : m_arduino{arduino},m_drivetrain{drivetrain}
 {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivetrain);
  
}

// Called when the command is initially scheduled.
void BallTrack::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void BallTrack::Execute() {
  double ballX;
  double ballWidth;
  
  auto data = m_arduino->readData();
  if (data.second && data.first.size() != 0){
      for (SensorFrame frame : data.first) {
        ballX = frame.x;
        ballWidth = frame.width;
      }
      double turn = (ballX - 150) / 250;
      double speed = 0.0;
/*
      if (turn > 150.0 / 500.0)
      {
        turn = 150.0 / 500.0;
      }

      if (turn < -150.0 / 500.0)
      {
        turn = -150.0 / 500.0;
      }*/

      if (abs(ballX - 150) < 30 && ballWidth > 20) {
        speed = 5 / ballWidth;
      }

      
     // m_drivetrain->drive(speed + turn, speed -turn);

  } else {
    m_drivetrain->drive(0,0);
  }
}

// Called once the command ends or is interrupted.
void BallTrack::End(bool interrupted) {}

// Returns true when the command should end.
bool BallTrack::IsFinished() {
  return false;
}
