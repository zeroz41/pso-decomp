#ifndef PSO_UI_HUD_TMAINCURSOR_80154090_H
#define PSO_UI_HUD_TMAINCURSOR_80154090_H

#include "types.h"

// One entry of the target-candidate array the cursor walks when gathering lock-on targets
// (array pointer at owner +0xA4, count at +0xA8): flags at 0x18 carry per-entry marks, the
// position read by TMainCursor::update_position lives at 0x1C, entry stride is 0x2C.
struct TargetCandidateEntry { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };

extern "C" {
void TMainCursor__sub_80154090(void);
void TMainCursor__sub_80154094(void);
void TMainCursor__sub_80154230(void *cursor, s32 index, u16 bit);
s32 TMainCursor__sub_80154288(u8 *cursor, s32 index, u16 bit);
}

#endif
