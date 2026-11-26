#include "types.h"
#include <string.h>
#include "pso/unk/text_801F498C.h"
#include "pso/unk/text_801F43B4.h"

void clear_all_story_flags(void) {
    memset(quest_story_flags_by_difficulty, 0, 0x200);
}
