#ifndef SRC_TESTJOYSTICK_H_
#define SRC_TESTJOYSTICK_H_

#include <Joystick.h>
#include <JoystickValueButton.h>
#include "JoystickButton.h"
#include "JoystickUpDownButton.h"
#include "JoystickRepeatButton.h"

using namespace _3624;

class TestJoystick : public frc::Joystick
{
public :
	TestJoystick(int port);

	void Initialize();
	void GetButtonState();

	JoystickValueButton *Throttle() { return &m_throttle; }
	_3624::JoystickButton *Trigger() { return &m_trigger; }
	_3624::JoystickButton *Reset() { return &m_reset; }
	JoystickUpDownButton *Speed() { return &m_speed; }
	JoystickUpDownButton *Lifter() { return &m_lifter; }

private :
	_3624::JoystickButton m_trigger, m_reset;
	JoystickValueButton   m_throttle, m_speedUp, m_speedDown;
	JoystickRepeatButton m_liftUp, m_liftDown;
	JoystickUpDownButton m_speed, m_lifter;

	std::vector<_3624::JoystickButton *> m_buttons;
};

#endif
