#include "Robot.h"
#include "Autonomous.h"
#include "Teleop.h"

TestJoystick *g_pTestJoystick;
RobotDrive *g_pRobotDrive;

Robot::Robot()
     : m_testJoystick(0), m_lf(11), m_rf(12), m_lb(13), m_rb(14),
	   m_drive(m_lf, m_lb, m_rf, m_rb)
{
	g_pTestJoystick = &m_testJoystick;
	g_pRobotDrive = &m_drive;
}

void Robot::RobotInit()
{
	printf("RobotInit\n");

	m_lf.SetSafetyEnabled(false);
	m_rf.SetSafetyEnabled(false);
	m_lb.SetSafetyEnabled(false);
	m_rb.SetSafetyEnabled(false);
	m_drive.SetSafetyEnabled(false);

	m_lf.SetInverted(false);
	m_rf.SetInverted(false);
	m_lb.SetInverted(false);
	m_rb.SetInverted(false);
}

void Robot::AutonomousInit()
{
	m_autonomous.Init();
}

void Robot::AutonomousPeriodic()
{
	m_autonomous.Periodic();
}

void Robot::TeleopInit()
{
	m_teleop.Init();
}

void Robot::TeleopPeriodic()
{
	m_teleop.Periodic();
}

START_ROBOT_CLASS(Robot)
