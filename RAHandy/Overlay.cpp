
#include "Lynxwin.h"
#include <stdio.h>
#include <math.h>

#include "Overlay.h"

#include "../RA_Integration/RA_Interface.h"

void RenderAchievementsOverlay(HDC hdc, RECT rect) 
{
	ControllerInput input;
	input.m_bLeftPressed		= (gInputData & BUTTON_LEFT);
	input.m_bRightPressed		= (gInputData & BUTTON_RIGHT);
	input.m_bDownPressed		= (gInputData & BUTTON_DOWN);
	input.m_bUpPressed			= (gInputData & BUTTON_UP);
	input.m_bConfirmPressed		= (gInputData & BUTTON_A);
	input.m_bCancelPressed		= (gInputData & BUTTON_B);
	input.m_bQuitPressed		= (gInputData & BUTTON_PAUSE);

	static int nOldTime = GetTickCount(); //Time in ms I presume

	int nDelta;
	nDelta = GetTickCount() - nOldTime;
	nOldTime = GetTickCount();

	RECT newRect;
	SetRect(&newRect, 0, 0, rect.right - rect.left, rect.bottom - rect.top);

	RA_UpdateRenderOverlay(hdc, &input, ((float)nDelta / 1000.0f), &newRect, FALSE, gSystemHalt);
}
