#pragma once

#include "Lynxwin.h"
#include <ddraw.h>

#include "../RA_Integration/RA_Interface.h"


#ifndef RA_EXPORTS

#ifdef __cplusplus
extern "C" {
#endif

extern void RenderAchievementsOverlay(HDC hdc, RECT rect);

#ifdef __cplusplus
}
#endif
#endif //RA_EXPORTS
