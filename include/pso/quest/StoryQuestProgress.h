#ifndef PSO_QUEST_STORYQUESTPROGRESS_H
#define PSO_QUEST_STORYQUESTPROGRESS_H

#include "types.h"

void apply_story_quest_unlock_rules(void *unusedDifficulty);
s32 are_all_story_quests_complete(void);
void clear_episode1_quest_availability(void *unusedDifficulty);
void refresh_story_quest_availability(void *p);
s32 should_record_episode1_quest_completion(void);

// A story quest's two story flags: apply_story_quest_unlock_rules sets available_flag when the
// quest opens and tests cleared_flag (available_flag + 1) for the quests it requires.
struct StoryQuestFlagPair {
    s32 available_flag;
    s32 cleared_flag;
};

#endif
