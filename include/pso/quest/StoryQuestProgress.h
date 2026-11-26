#ifndef PSO_QUEST_STORYQUESTPROGRESS_H
#define PSO_QUEST_STORYQUESTPROGRESS_H

#include "types.h"

void apply_story_quest_unlock_rules(void *unusedDifficulty);
s32 are_all_story_quests_complete(void);
void clear_episode1_quest_availability(void *unusedDifficulty);
void refresh_story_quest_availability(void *p);
s32 should_record_episode1_quest_completion(void);

struct ShouldRecordEpisode1QuestCompletionInduction { u8 bytes[0x8]; };

struct AreAllStoryQuestsCompletePair { s32 a; s32 b; };

#endif
