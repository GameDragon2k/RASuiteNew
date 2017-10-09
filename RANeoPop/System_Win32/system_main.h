//---------------------------------------------------------------------------
// NEOPOP : Emulator as in Dreamland
//
// Copyright (c) 2001-2002 by neopop_uk
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//	This program is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version. See also the license.txt file for
//	additional informations.
//---------------------------------------------------------------------------

/*
//---------------------------------------------------------------------------
//=========================================================================

	system_main.h

//=========================================================================
//---------------------------------------------------------------------------

  History of changes:
  ===================

21 JUL 2002 - neopop_uk
=======================================
- This include file is for 'system_main.c' functions only

26 JUL 2002 - neopop_uk
=======================================
- Made the menu external for 'unload rom'

22 AUG 2002 - neopop_uk
=======================================
- Moved NEOPOP_WIN32_VERSION here for more importance.

27 AUG 2002 - neopop_uk
=======================================
- Added "BOOL windowed"
  
28 AUG 2002 - neopop_uk
=======================================
- Made the keyboard accelerator global for external message pumps.
- Added 'set paused' function so comms can pause things.

//---------------------------------------------------------------------------
*/

#ifndef __SYSTEM_MAIN__
#define __SYSTEM_MAIN__
//=============================================================================

#define NEOPOP_WIN32_VERSION	"v1.08"


HWND g_hWnd;
HMENU g_menu;
HINSTANCE g_hInstance;
RECT g_ScreenRect;
HACCEL g_accelerator;	//Keyboard shortcuts


#ifdef __cplusplus
extern "C" {
#endif

BOOL system_paused;

void system_changed_rom(void);
void system_set_paused();

void system_init(void);
void setMRUMenu(UINT menuId, char* mru);
void setZoom(int z);
void setFrameSkip(void);
void buildMRUMenu(void);
BOOL windows_load_rom(char* filename);
void switchDisplayMode(void);
void system_shutdown(void);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK PathsProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK MiscProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

#ifdef __cplusplus
}
#endif


//=============================================================================
#endif
