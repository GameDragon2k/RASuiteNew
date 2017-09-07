#pragma once

#include <wtypes.h>

INT_PTR CALLBACK GameIdSelProc(HWND, UINT, WPARAM, LPARAM);

class Dlg_GameIdSel
{
public:
	static unsigned int DoModalDialog( HINSTANCE hInst, HWND hParent, const char* sMD5 );

public:
	unsigned int m_nReturnedGameID;
	const char* m_sMD5;
};

extern Dlg_GameIdSel g_GameIdDialog;




