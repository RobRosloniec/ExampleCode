#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <IterativeRobot.h>
#include <CANTalon.h>
#include "WPILib.h"
#include "TestJoystick.h"
#include "Autonomous.h"
#include "Teleop.h"

class Robot: public frc::IterativeRobot {
public:
	Robot();

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();

	void RobotPeriodic() {}
	void TestInit() {}
	void TestPeriodic() {}
	void DisabledInit() {}
	void DisabledPeriodic() {}

private:
	TestJoystick m_testJoystick;
	CANTalon 	m_lf, m_rf, m_lb, m_rb;
	RobotDrive 	m_drive;
	Autonomous m_autonomous;
	Teleop m_teleop;
};

#endif
