#ifndef PSO_UI_WINDOW_TWINDOWACTIONPALETTE_801C1890_H
#define PSO_UI_WINDOW_TWINDOWACTIONPALETTE_801C1890_H

#include "types.h"

struct TObjPlayer;
struct TItem;
extern "C" {
void TObjPlayer__sub_801C19C8(void *p, f32 v);
void TObjPlayer__sub_801C1AC8(void *self);
void TObjPlayer__sub_801C1B0C(void);
s32 TWindowDuelResult__sub_801C19AC(f32 *arg0);
f32 fn_801C19A4(void *p);
void fn_801C19E0(void *p, s32 v);
s32 fn_801C1BA0(void *p);
}
extern "C" {
s32 is_item_equipped(TItem *item);
}

#endif
