#include "types.h"
#include <string.h>
#include "pso/quest/QuestStoryFlags.h"

void clear_all_story_flags(void) {
    memset(quest_story_flags_by_difficulty, 0, 0x200);
}
