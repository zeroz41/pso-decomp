#ifndef PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024674C_H
#define PSO_UI_WINDOW_TWINDOWCTRLMAIN_8024674C_H

#include "types.h"

extern "C" {
int TWindowFukidasi__sub_8024695C(void *p);
}
struct NJS_TEXLIST;

// The HUD palette and glyph texture list loaded for the window system.
extern "C" NJS_TEXLIST *hud_texlist;
__declspec(section ".data") extern NJS_TEXLIST f256_hyouji_texlist;
void load_hud_palette_textures(void);
extern "C" {
}

#endif
