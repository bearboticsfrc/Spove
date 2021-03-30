// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Drivetrain.h"
#include "Arduino.h"
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc2/command/RamseteCommand.h>
#include "subsystems/Drivetrain.h"
#include <frc2/command/InstantCommand.h>
#include <frc/geometry/Pose2d.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/Choosers.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
namespace frc{
  class RamseteCommand;
}

frc::RamseteCommand getTrajectoyCommandARed();
frc::RamseteCommand getTrajectoyCommandBRed();
frc::RamseteCommand getTrajectoyCommandABlue();
frc::RamseteCommand getTrajectoyCommandBBlue();

frc::Trajectory generateTrajectoryARed();
frc::Trajectory generateTrajectoryBRed();
frc::Trajectory generateTrajectoryABlue();
frc::Trajectory generateTrajectoryBBlue();

class ARed
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, 
                                 ARed>{
 public:
   ARed(Drivetrain *drivetrain);

   private:
};

class BRed
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, 
                                 BRed>{
 public:
   BRed(Drivetrain *drivetrain);

   private:
};

class ABlue
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, 
                                 ABlue>{
 public:
   ABlue(Drivetrain *drivetrain);

   private:
};

class BBlue
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, 
                                 BBlue>{
 public:
   BBlue(Drivetrain *drivetrain);

   private:
};

class BallTrack
    : public frc2::CommandHelper<frc2::CommandBase, BallTrack> {
 public:
  BallTrack(Arduino *arduino, Drivetrain *drivetrain, ARed *aRed, BRed *bRed, ABlue *aBlue, BBlue *bBlue);

  void choosePath(int path);

  frc2::Command* RunPath(int path);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  Arduino* m_arduino;
  Drivetrain* m_drivetrain;
  ARed* m_aRed;
  BRed* m_bRed;
  ABlue* m_aBlue;
  BBlue* m_bBlue;

  private:
  Choosers *choosers;
};
