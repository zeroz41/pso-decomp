#include "types.h"
#include <string.h>
#include "pso/unk/text_801F498C.h"

struct RecoveredGlobal_801F498C_lbl_805127F8 {
    s32 value;
    u8 remaining[0x1FC];
};

extern RecoveredGlobal_801F498C_lbl_805127F8 quest_story_flags_by_difficulty;
LAYOUT_ASSERT(RecoveredGlobal_801F498C_lbl_805127F8_size, sizeof(RecoveredGlobal_801F498C_lbl_805127F8) == 0x200);
void clear_all_story_flags(void) {
    memset(&quest_story_flags_by_difficulty.value, 0, 0x200);
}
