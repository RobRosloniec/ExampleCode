#include "JoystickButton.h"

using namespace _3624;

JoystickButton::JoystickButton(int index)
{
	m_bPressed = false;
	m_index = index;
	m_bChanged = false;
}

bool JoystickButton::Update(bool bPressed)
{
	if (bPressed != m_bPressed)
	{
		m_bPressed = bPressed;
		m_bChanged = true;

		return true;
	}
	return false;
}

void JoystickButton::Initialize()
{
	m_bPressed = false;
}
