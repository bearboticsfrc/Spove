#include "commands/Choosers.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "units_include.h"

Choosers::Choosers() {

    m_autonomousChooser.AddOption("ARed", AutonomousChoice::ARed);
    m_autonomousChooser.AddOption("BRed", AutonomousChoice::BRed);
    m_autonomousChooser.AddOption("ABlue", AutonomousChoice::ABlue);
    m_autonomousChooser.AddOption("BBlue", AutonomousChoice::BBlue);

    m_ballTrackChooser.AddOption("On", BallTrackChoice::On);
    m_ballTrackChooser.AddOption("Off", BallTrackChoice::Off);

    frc::SmartDashboard::PutData("AutoChooser", &m_autonomousChooser);
    frc::SmartDashboard::PutData("BallTrackChooser", &m_ballTrackChooser);
}

AutonomousChoice Choosers::autonomousChoice(){
    return m_autonomousChooser.GetSelected();
}
BallTrackChoice Choosers::ballTrackChoice(){
    return m_ballTrackChooser.GetSelected();
}
