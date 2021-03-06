#ifndef _POPUPWINDOWS_H_
#define _POPUPWINDOWS_H_

#include "RA_PopupWindows.h"

#include "RA_ProgressPopup.h"
#include "RA_AchievementPopup.h"
#include "RA_LeaderboardPopup.h"
#include "RA_Core.h"


class PopupWindows
{
public:
	//void Init();

	void Update( ControllerInput* pInput, float fDelta, bool bFullscreen, bool bPaused )
	{
		m_ProgressPopups.Update( *pInput, fDelta, bFullscreen, bPaused );
		m_AchievementPopups.Update( *pInput, fDelta, bFullscreen, bPaused );
		m_LeaderboardPopups.Update( *pInput, fDelta, bFullscreen, bPaused );
		//AchievementPopup_Update( &m_AchievementPopups, fDelta, bFullscreen, bPaused );
	}

	void Render( HDC hDC, RECT* rcDest )
	{
		m_ProgressPopups.Render( hDC, *rcDest );
		m_AchievementPopups.Render( hDC, *rcDest );
		m_LeaderboardPopups.Render( hDC, *rcDest );
		//AchievementPopup_Render( &m_AchievementPopups, hDC, &rcDest );
	}

	void Clear()
	{
		m_ProgressPopups.Clear();
		m_AchievementPopups.Clear();
		//AchievementPopup_Clear( &m_AchievementPopups );
	}

	ProgressPopup& ProgressPopups()			{ return m_ProgressPopups; }
	AchievementPopup& AchievementPopups()	{ return m_AchievementPopups; }
	LeaderboardPopup& LeaderboardPopups()	{ return m_LeaderboardPopups; }

private:
	ProgressPopup m_ProgressPopups;
	AchievementPopup m_AchievementPopups;
	LeaderboardPopup m_LeaderboardPopups;
};

//	Exposed to DLL
extern "C"
{

API extern int _RA_UpdatePopups( ControllerInput* input, float fDTime, bool Full_Screen, bool Paused );
API extern int _RA_RenderPopups( HDC hDC, RECT* rcSize );

}

extern PopupWindows g_PopupWindows;

#endif //_POPUPWINDOWS_H_