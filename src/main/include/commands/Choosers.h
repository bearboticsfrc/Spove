#include <frc/smartdashboard/SendableChooser.h>
#include "units_include.h"

enum class AutonomousChoice {
    ARed,
    BRed,
    ABlue,
    BBlue,
};

enum class BallTrackChoice {
  On,
  Off
};

class Choosers {
public:
    Choosers();
    AutonomousChoice autonomousChoice();
    BallTrackChoice ballTrackChoice();

private:
  frc::SendableChooser<AutonomousChoice> m_autonomousChooser;
  frc::SendableChooser<BallTrackChoice> m_ballTrackChooser;
};
