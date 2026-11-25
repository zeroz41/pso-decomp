#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H

#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"

class TPlyCharData;
struct GuildCardSaveData;

// What the card slot summary lookups report about a card slot.
struct CardSlotSummary { s32 x; s32 y; s32 state; };

extern "C" {
u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int client);
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C(void);
int start_system_file_write(s32 chan);
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void);
s32 TAdSinglePlyChrSelectGC__sub_801FDC14(s32 slot);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i);
s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FEBBC(void);
void TAdSinglePlyChrSelectGC__sub_801FFF14(void);
void TAdSinglePlyChrSelectGC__sub_80200418(void);
}
void set_character_file_seed(u8 *file, s32 value);
s32 get_character_file_seed(u8 *file);
s32 start_character_file_write(void);
GuildCardSaveData *copy_guild_card_payload(GuildCardSaveData *dest, GuildCardSaveData *source);
s32 copy_guild_card_entries(saddr dest, saddr source);
void decrypt_guild_card_payload(GuildCardSaveData *data);
void encrypt_guild_card_payload(GuildCardSaveData *data, void *arg1);
u32 calc_crc32_bitwise(u8 *data, u32 size);
s32 alloc_global_buffer(void);
s32 buffer_init(void);
void game_state_load(void);
extern "C" {
}
int get_split_screen_character_save_record(int a0);
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
