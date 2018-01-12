#include "Teleop.h"
#include "TestJoystick.h"

extern TestJoystick *g_pTestJoystick;
extern RobotDrive *g_pRobotDrive;

void Teleop::Init()
{
	printf("TeleopInit\n");

	m_pThrottleButton = g_pTestJoystick->Throttle();
	m_pTriggerButton = g_pTestJoystick->Trigger();
	m_pResetButton = g_pTestJoystick->Reset();
	m_pSpeedButtons = g_pTestJoystick->Speed();
	m_pLifterButtons = g_pTestJoystick->Lifter();

	Reset();
}

void Teleop::Reset()
{
	g_pTestJoystick->Initialize();
}

void Teleop::Periodic()
{
	g_pTestJoystick->GetButtonState();

	if (m_pResetButton->Changed() && !m_pResetButton->Pressed())
	{
		printf("Reset\n");
		Reset();
	}

	if (m_pThrottleButton->Changed())
		printf("Throttle Changed from %d to %d\n", m_pThrottleButton->LastValue(), m_pThrottleButton->Value());

	if (m_pTriggerButton->Changed())
		printf("Trigger Changed to %d\n", m_pTriggerButton->Pressed());

	if (m_pSpeedButtons->Changed())
		printf("Speed Changed from %d to %d\n", m_pSpeedButtons->LastValue(), m_pSpeedButtons->Value());

	if (m_pLifterButtons->Changed())
		printf("Lifter Changed from %d to %d\n", m_pLifterButtons->LastValue(), m_pLifterButtons->Value());

	g_pRobotDrive->ArcadeDrive(g_pTestJoystick->GetY(), g_pTestJoystick->GetZ());
}
