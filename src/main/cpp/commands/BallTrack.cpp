// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/BallTrack.h"

BallTrack::BallTrack(Arduino *arduino, Drivetrain *drivetrain, ARed *aRed, BRed *bRed, ABlue *aBlue, BBlue *bBlue)
 : m_arduino{arduino},m_drivetrain{drivetrain}, choosers(choosers), m_aRed{aRed}, m_bRed{bRed}, m_aBlue{aBlue}, m_bBlue{bBlue}
 {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivetrain);
  
}

// Called when the command is initially scheduled.
void BallTrack::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void BallTrack::Execute() {
  double ballX = 0; 
  double ballY= 0;
  double ballWidth = 0;
  double ballHeight = 0;
  
  auto data = m_arduino->readData();
  if (data.second && data.first.size() != 0){
      for (SensorFrame frame : data.first) {
        ballX = frame.x;
        //ballY = frame.y;
        //ballWidth = frame.width;
        //ballHeight = frame.height;

      }
      double turn = (ballX - 150) / 250;
      double speed = 0.0;

      int path;
      int successes = 0; 

      if (successes < 5) {
      if (ballX <= 182 && ballX >= 178) {
        successes++;
        path = 0;
      }else if (ballX <= 37 && ballX >=35) {
        successes++;
        path = 1;
      }else if (ballX <= 275 && ballX >= 271) {
        successes++;
        path = 2;
      }else if (ballX <= 218 && ballX >= 222) {
        successes++;
        path = 3;
      }
    } 
    else {
      choosePath(path);
    }
/*
      if (turn > 150.0 / 500.0)
      {
        turn = 150.0 / 500.0;
      }

      if (turn < -150.0 / 500.0)
      {
        turn = -150.0 / 500.0;
      }

      if (abs(ballX - 150) < 30 && ballWidth > 20) {
        speed = 5 / ballWidth;
      }*/

      
      //m_drivetrain->drive(speed + turn, speed -turn);

  } //else {
    //m_drivetrain->drive(0,0);
  //}
}
// Called once the command ends or is interrupted.
void BallTrack::End(bool interrupted) {}

// Returns true when the command should end.
bool BallTrack::IsFinished() {
  return false;
}

void BallTrack::choosePath(int path) {
  switch (choosers->ballTrackChoice()) {
    case BallTrackChoice::On:
      std::cout << "using ball tracking\n";
      RunPath(path);
      break;
      case BallTrackChoice::Off:
        std::cout << "ball tracking off\n";
        break;
      default:
        std::cout << "not using ball tracking\n";
    } 
}

frc2::Command* BallTrack::RunPath(int path) {
  switch (path) {
    case 0:
      std::cout << "Running ARed\n";
      return m_aRed;
    case 1:
      std::cout << "Running BRed\n";
      return m_bRed;
    case 2:
      std::cout << "Running ABlue\n";
      return m_aBlue;
    case 3:
      std::cout << "Running BBlue\n";
      return m_bBlue;
    default:
      std::cout << "Hi Christian\n";
      return m_aRed;
  }
}


frc::Trajectory generateTrajectoryARed() {
  frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson("/home/lvuser/deploy/RedA.wpilib.json");
  return trajectory;
}


frc::Trajectory generateTrajectoryBRed() {
  frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson("/home/lvuser/deploy/RedB.wpilib.json");
  return trajectory;
}


frc::Trajectory generateTrajectoryABlue() {
  frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson("/home/lvuser/deploy/BlueA.wpilib.json");
  return trajectory;
}


frc::Trajectory generateTrajectoryBBlue() {
  frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson("/home/lvuser/deploy/BlueB.wpilib.json");
  return trajectory;
}

frc::DifferentialDriveKinematics getKinematics() {
  return frc::DifferentialDriveKinematics { 24_in };
}

frc2::RamseteCommand getTrajectoryCommand(Drivetrain &drivetrain, frc::Trajectory trajectory) {
  return frc2::RamseteCommand(
    trajectory,
    [&drivetrain]() { return drivetrain.GetPose(); },
    frc::RamseteController(
      2.0,
      0.6
    ),
    getKinematics(),
    [&drivetrain](units::meters_per_second_t left, units::meters_per_second_t right) { drivetrain.drive(left.to<double>(), right.to<double>()); },
    { &drivetrain }
  );
}

frc2::RamseteCommand getTrajectoryCommandARed(Drivetrain &drivetrain) {
  return getTrajectoryCommand(drivetrain, generateTrajectoryARed());
}

frc2::RamseteCommand getTrajectoryCommandBRed(Drivetrain &drivetrain) {
  return getTrajectoryCommand(drivetrain, generateTrajectoryBRed());
}

frc2::RamseteCommand getTrajectoryCommandABlue(Drivetrain &drivetrain) {
  return getTrajectoryCommand(drivetrain, generateTrajectoryABlue());
}

frc2::RamseteCommand getTrajectoryCommandBBlue(Drivetrain &drivetrain) {
  return getTrajectoryCommand(drivetrain, generateTrajectoryBBlue());
}

ARed::ARed(Drivetrain *drivetrain) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(
    frc2::InstantCommand{ [=] { drivetrain->SetPose(generateTrajectoryARed().States()[0].pose); } },
    getTrajectoryCommandARed(*drivetrain)
    // TODO: Drive back
  );
}

BRed::BRed(Drivetrain *drivetrain) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(
    frc2::InstantCommand{ [=] { drivetrain->SetPose(generateTrajectoryBRed().States()[0].pose); } },
    getTrajectoryCommandBRed(*drivetrain)
    // TODO: Drive back
  );
}

ABlue::ABlue(Drivetrain *drivetrain) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(
    frc2::InstantCommand{ [=] { drivetrain->SetPose(generateTrajectoryABlue().States()[0].pose); } },
    getTrajectoryCommandABlue(*drivetrain)
    // TODO: Drive back
  );
}

BBlue::BBlue(Drivetrain *drivetrain) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(
    frc2::InstantCommand{ [=] { drivetrain->SetPose(generateTrajectoryBBlue().States()[0].pose); } },
    getTrajectoryCommandBBlue(*drivetrain)
    // TODO: Drive back
  );
}

