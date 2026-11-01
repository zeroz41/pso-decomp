#ifndef PSO_UI_TADSINGLEPLYCHRSELECTGC_8033A8EC_H
#define PSO_UI_TADSINGLEPLYCHRSELECTGC_8033A8EC_H

#include "types.h"

struct TAdSinglePlyChrSelectGC;
extern "C" {
void TAdSinglePlyChrSelectGC__sub_8033A9F0(TAdSinglePlyChrSelectGC *arg0);
int TAdSinglePlyChrSelectGC__sub_8033B244(void *p);
void TAdSinglePlyChrSelectGC__sub_8033B264(void);
void TAdSinglePlyChrSelectGC__sub_8033B5F0(void *arg0);
void TAdSinglePlyChrSelectGC__sub_8033B9E0(void *p);
void TAdSinglePlyChrSelectGC__sub_8033B9EC(void *p);
u8 TAdSinglePlyChrSelectGC__sub_8033B9F8(u8 *arg0);
bool TAdSinglePlyChrSelectGC__sub_8033BA84(s32 chan);
void close_window__23TAdSinglePlyChrSelectGCFPv(void *arg0);
}
void init_single_player_char_select_scene(void);
void seed_character_select_serial_rng(s32 arg0);

#endif
