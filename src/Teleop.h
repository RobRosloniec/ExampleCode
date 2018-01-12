#ifndef SRC_TELEOP_H_
#define SRC_TELEOP_H_

#include "JoystickValueButton.h"
#include "JoystickButton.h"
#include "JoystickUpDownButton.h"
#include "WPILib.h"

class Teleop
{
public :
	void Init();
	void Periodic();

private :
	void Reset();

	JoystickValueButton *m_pThrottleButton, *m_pMoveUpButton, *m_pMoveDownButton;
	_3624::JoystickButton *m_pTriggerButton, *m_pResetButton;
	JoystickUpDownButton *m_pSpeedButtons, *m_pLifterButtons;
};

#endif
