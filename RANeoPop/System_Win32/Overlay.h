#pragma once

#include <ddraw.h>
#include "../../RA_Integration/RA_Interface.h"


#ifndef RA_EXPORTS

#ifdef __cplusplus
extern "C" {
#endif

extern void EndOverlay();
extern void RenderAchievementsOverlay(HWND hwnd, ControllerInput input, BOOL paused);
extern bool disable_RA_overlay;

#ifdef __cplusplus
}
#endif
#endif //RA_EXPORTS
