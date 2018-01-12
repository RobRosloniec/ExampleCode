#include "TestJoystick.h"
#include "JoystickButton.h"

using namespace _3624;

TestJoystick::TestJoystick(int port)
	: Joystick(port), m_trigger(0), m_reset(10), m_throttle(1, 10, 0),
	  m_speedUp(4, 10, 0), m_speedDown(2, 10, 0, false, -1),
	  m_liftUp(5, 100, 0, false, 1, 1.0, 0.2), m_liftDown(3, 100, 0, false, -1, 1.0, 0.2),
	  m_speed(&m_speedUp, &m_speedDown), m_lifter(&m_liftUp, &m_liftDown)
{
	m_buttons.push_back(&m_trigger);
	m_buttons.push_back(&m_throttle);
	m_buttons.push_back(&m_reset);
	m_buttons.push_back(&m_speedUp);
	m_buttons.push_back(&m_speedDown);
	m_buttons.push_back(&m_liftUp);
	m_buttons.push_back(&m_liftDown);
}

void TestJoystick::GetButtonState()
{
	for (unsigned int buttonIndex=0; buttonIndex<m_buttons.size(); buttonIndex++)
	{
		JoystickButton *pButton = m_buttons[buttonIndex];

		pButton->Changed(false);

		bool buttonState = GetRawButton(pButton->Index() + 1);

		pButton->Update(buttonState);
	}

	m_speed.Update();
	m_lifter.Update();
}

void TestJoystick::Initialize()
{
	for (unsigned int buttonIndex=0; buttonIndex<m_buttons.size(); buttonIndex++)
	{
		JoystickButton *pButton = m_buttons[buttonIndex];

		pButton->Initialize();
	}

	m_speed.Update();
	m_lifter.Update();
}
