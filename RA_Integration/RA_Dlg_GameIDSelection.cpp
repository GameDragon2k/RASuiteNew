#include "RA_Dlg_GameIDSelection.h"

#include <windowsx.h>
#include <stdio.h>

#include "RA_Defs.h"
#include "RA_Core.h"
#include "RA_Resource.h"
#include "RA_User.h"
#include "RA_Achievement.h"
#include "RA_httpthread.h"


Dlg_GameIdSel g_GameIdDialog;

INT_PTR CALLBACK GameIdSelProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam )
{


 	switch(uMsg)
 	{
 	case WM_INITDIALOG:
	{

		SetDlgItemText(hDlg, IDC_RA_GAMEIDS, "");
		return TRUE;
	}
	break;
 
 	case WM_COMMAND:
 		switch( LOWORD(wParam) )
 		{
 		case IDOK:
 			{
				char sSelectedID[16];
				GetDlgItemText(hDlg, IDC_RA_GAMEIDS, sSelectedID, 16);
				g_GameIdDialog.m_nReturnedGameID = atoi(sSelectedID);


 			}
 		case IDCANCEL:
			{
 				EndDialog( hDlg, TRUE );
 				return TRUE;
 				break;
			}
		}
 		break;
 	case WM_KEYDOWN:
		wParam;
		break;
 	case WM_CLOSE:
 
 		EndDialog( hDlg, FALSE );
 		return TRUE;
 		break;
 	}

	return FALSE;
}

unsigned int Dlg_GameIdSel::DoModalDialog(HINSTANCE hInst, HWND hParent, const char* sMD5)
{
	if (sMD5 == NULL)
		return 0;

	g_GameIdDialog.m_sMD5 = sMD5;


	DialogBox(hInst, MAKEINTRESOURCE(IDD_RA_GAMEIDSEL), hParent, GameIdSelProc);

	return g_GameIdDialog.m_nReturnedGameID;
}
