#ifndef PSO_QUEST_QUESTSTORYFLAGS_H
#define PSO_QUEST_QUESTSTORYFLAGS_H

#include "types.h"

// The quest story flags: 1024 bits per difficulty. A bank is a difficulty; the functions without
// a bank use game_difficulty_selection. Flags out of range read as -1 and are not written.

// The quest story flags of each difficulty (command 6x6F carries a copy).
extern u8 quest_story_flags_by_difficulty[4][128];

// Copies the story flags into the character save record of client 0.
void save_quest_story_flags(void);
s32 get_story_flag_in_bank(s32 bank, s32 flag);
s32 get_story_flag(s32 flag);
void clear_story_flag_in_bank(s32 bank, s32 flag);
void clear_story_flag(s32 flag);
void set_story_flag_in_bank(s32 bank, s32 flag);
// Online, sends the flag to the other players (6x75) instead of setting it.
void set_story_flag_in_bank_or_send_quest_flag(s32 bank, s32 flag);
void set_story_flag(s32 flag);
// Online, sends the flag to the other players (6x75) instead of setting it.
void set_story_flag_or_send_quest_flag(s32 flag);
// Without split screen, loads the story flags of the client the first view follows.
void load_view_player_story_flags(void);
// The boss-thanks flags (151-154), -1 ends the list.
extern const s32 lobby_story_flag_clear_list[6];
// Clears the flags of lobby_story_flag_clear_list.
void clear_story_flag_list(void);
void clear_story_flag_list_and_reload(void);
// Copies the story flags from the character save record of client.
void load_quest_story_flags(u16 client);
void clear_all_story_flags(void);

#endif
