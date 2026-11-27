#include "types.h"
#include "pso/quest/StoryQuestProgress.h"
#include "pso/quest/QuestStoryFlags.h"

#include <stddef.h>
#include "pso/network/TLobby.h"


extern const StoryQuestFlagPair episode1_story_quest_flag_pairs[];
extern const StoryQuestFlagPair episode2_story_quest_flag_pairs[];
s32 should_record_episode1_quest_completion(void) {
    s32 all_complete;
    s32 i;
    if (get_story_flag(0x3FE) == 1) {
        return 0;
    }
    all_complete = 1;
    i = 0;
        do {
        if (get_story_flag(episode1_story_quest_flag_pairs[i].cleared_flag) == 0) {
            all_complete = 0;
        }
        i += 1;
    } while (i < 0x1A);
    return all_complete;
}
s32 are_all_story_quests_complete(void) {
    s32 n;
    s32 i;
    s32 r = TLobby::get_instance();
    n = 3;
    if (r == 0) {
        n = 0x1A;
    }
    for (i = 0; i < n; i++) {
        if (TLobby::get_instance() == 0) {
            if (get_story_flag(episode1_story_quest_flag_pairs[i].cleared_flag) == 0) {
                return 0;
            }
        } else {
            if (get_story_flag(episode2_story_quest_flag_pairs[i].cleared_flag) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
void clear_episode1_quest_availability(void* unusedDifficulty) {
    s32 i;
    i = 0;
    do {
        clear_story_flag(episode1_story_quest_flag_pairs[i].available_flag);
        i += 1;
    } while (i < 0x1A);
}
void apply_story_quest_unlock_rules(void* unusedDifficulty) {
    set_story_flag_or_send_quest_flag(0x64);
    set_story_flag_or_send_quest_flag(0x66);
    set_story_flag_or_send_quest_flag(0x6A);
    if ((get_story_flag(0x65) != 0) && (get_story_flag(0x67) != 0) && (get_story_flag(0x6B) != 0)) {
        set_story_flag_or_send_quest_flag(0x6C);
        set_story_flag_or_send_quest_flag(0x6E);
        set_story_flag_or_send_quest_flag(0x70);
        set_story_flag_or_send_quest_flag(0x74);
    }
    if ((get_story_flag(0x65) != 0) && (get_story_flag(0x67) != 0) && (get_story_flag(0x6B) != 0) && (get_story_flag(0x18) != 0)) {
        set_story_flag_or_send_quest_flag(0x68);
        set_story_flag_or_send_quest_flag(0x76);
        set_story_flag_or_send_quest_flag(0x78);
        set_story_flag_or_send_quest_flag(0x7E);
        set_story_flag_or_send_quest_flag(0x84);
    }
    if ((get_story_flag(0x77) != 0) && (get_story_flag(0x79) != 0) && (get_story_flag(0x7F) != 0) && (get_story_flag(0x85) != 0)) {
        set_story_flag_or_send_quest_flag(0x7A);
        set_story_flag_or_send_quest_flag(0x80);
    }
    if ((get_story_flag(0x65) != 0) && (get_story_flag(0x67) != 0) && (get_story_flag(0x6B) != 0) && (get_story_flag(0x21) != 0)) {
        set_story_flag_or_send_quest_flag(0x82);
        set_story_flag_or_send_quest_flag(0x86);
        set_story_flag_or_send_quest_flag(0x8A);
    }
    if ((get_story_flag(0x65) != 0) && (get_story_flag(0x67) != 0) && (get_story_flag(0x6B) != 0) && (get_story_flag(0x30) != 0)) {
        set_story_flag_or_send_quest_flag(0x92);
        set_story_flag_or_send_quest_flag(0x88);
    }
    if (get_story_flag(0x71) != 0) {
        set_story_flag_or_send_quest_flag(0x72);
    }
    if (get_story_flag(0x7B) != 0) {
        set_story_flag_or_send_quest_flag(0x7C);
    }
    if ((get_story_flag(0x8B) != 0) && (get_story_flag(0x7F) != 0) && (get_story_flag(0x21) != 0)) {
        set_story_flag_or_send_quest_flag(0x8C);
    }
    if ((get_story_flag(0x7F) != 0) && (get_story_flag(0x30) != 0)) {
        set_story_flag_or_send_quest_flag(0x90);
    }
    if ((get_story_flag(0x8D) != 0) && (get_story_flag(0x30) != 0) && (get_story_flag(0x91) != 0)) {
        set_story_flag_or_send_quest_flag(0x8E);
        set_story_flag_or_send_quest_flag(0x94);
    }
    set_story_flag_or_send_quest_flag(-1);
    if (get_story_flag(0x95) != 0) {
        set_story_flag_or_send_quest_flag(0x9F);
    }
    if (get_story_flag(0xA1) != 0) {
        set_story_flag_or_send_quest_flag(0xA2);
    }
    if (get_story_flag(0xA3) != 0) {
        set_story_flag_or_send_quest_flag(0xA4);
    }
}
void refresh_story_quest_availability(void* p) { clear_episode1_quest_availability(p); apply_story_quest_unlock_rules(p); }
__declspec(section ".rodata") extern const StoryQuestFlagPair episode1_story_quest_flag_pairs[26] = {
    {100, 101}, {102, 103}, {104, 105}, {106, 107}, {108, 109}, {110, 111}, {112, 113}, {114, 115}, {116, 117},
    {118, 119}, {120, 121}, {122, 123}, {124, 125}, {126, 127}, {128, 129}, {130, 131}, {132, 133}, {134, 135},
    {136, 137}, {138, 139}, {140, 141}, {142, 143}, {144, 145}, {146, 147}, {148, 149}, {159, 160},
};
__declspec(section ".rodata") extern const StoryQuestFlagPair episode2_story_quest_flag_pairs[3] = {{-1, 161}, {162, 163}, {164, 165}};
