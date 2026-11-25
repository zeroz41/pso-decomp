#ifndef PSO_UNK_TEXT_801F43B4_H
#define PSO_UNK_TEXT_801F43B4_H

#include "types.h"

extern "C" {
void copy_card_window_data(void);
}
s32 get_story_flag(s32 flag);

// The quest story flags of each difficulty (command 6x6F carries a copy).
extern u8 quest_story_flags_by_difficulty[4][128];

#endif
