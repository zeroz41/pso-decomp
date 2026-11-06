#ifndef PSO_UI_CHARCREATE_PALETTECURSORACTION_H
#define PSO_UI_CHARCREATE_PALETTECURSORACTION_H
#include "types.h"

struct PaletteCursorAction {
    u8 kind;
    u8 parameter;
    u16 flags;
};
struct PaletteCursorOverride {
    PaletteCursorAction action;
    u32 enabled;
};
struct TObjPlayer;
extern "C" s32 canSetMenuCursorAction(PaletteCursorOverride*, TObjPlayer*, u8 kind, u8 parameter);
#endif
