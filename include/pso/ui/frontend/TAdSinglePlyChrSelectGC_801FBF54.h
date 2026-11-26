#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H

#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"

class TPlyCharData;
struct CharacterFile;
struct CharacterFileSlot;
struct CharacterSaveRecord;

CharacterFileSlot *get_selected_character_slot(CharacterFile *file);
CharacterSaveRecord *get_selected_save_record(CharacterFile *file);
struct GuildCardSaveData;

// What the card slot summary lookups report about a character slot of a card file.
struct CardSlotSummary {
    const char *name;
    s32 level;
    u32 copied;     // the slot's CharacterFileSlot::copied
    s32 play_time;  // seconds played (CharacterSaveRecord::play_time)
};

// The summary of slot i of the slot A card file, NULL when i is out of range or the slot is empty.
CardSlotSummary *get_card_slot_summary(u32 i);
// The same for the slot B card file (secondary_card_character_save_buffer).
CardSlotSummary *get_secondary_card_slot_summary(u32 i);
s32 is_secondary_slot_active(u32 i);
s32 load_slot_b_character_file(s32);
s32 poll_slot_b_character_load(void);
void build_guild_card_save_file(void);
void decrypt_slot_b_character_file(void);

extern "C" {
u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int client);
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C(void);
int start_system_file_write(s32 chan);
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void);
}
void set_character_file_seed(u8 *file, s32 value);
s32 get_character_file_seed(u8 *file);
s32 start_character_file_write(void);
void decrypt_guild_card_payload(GuildCardSaveData *data);
void encrypt_guild_card_payload(GuildCardSaveData *data, void *arg1);
u32 calc_crc32_bitwise(u8 *data, u32 size);
s32 alloc_global_buffer(void);
s32 buffer_init(void);
void game_state_load(void);
CharacterSaveRecord *get_split_screen_character_save_record(int client);
s32 init_buffer(void);
void init_fresh_character_card(void);
void init_fresh_character_slot(s32 slot);
void init_timestamped_data(void);
s32 load_and_verify_data(s32 verify_only);
s32 load_guild_card_save(void);
extern "C" {
s32 load_pso_system(void);
}
s32 load_system_file(s32 mode);
void load_tables(int a0);
s32 pso_system_load_gc(void);

#endif
