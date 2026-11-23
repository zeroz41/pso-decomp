#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H

#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"

class TPlyCharData;

extern "C" {
u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int client);
void TAdSinglePlyChrSelectGC__sub_801FCCB4(u8 *arg0, s32 arg1);
s32 TAdSinglePlyChrSelectGC__sub_801FCCC0(u8 *arg0);
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C(void);
int TAdSinglePlyChrSelectGC__sub_801FD990(s32 chan);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void);
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void);
void TAdSinglePlyChrSelectGC__sub_801FDC14(void);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i);
s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FEBBC(void);
u8 *TAdSinglePlyChrSelectGC__sub_801FFC74(u8 *arg0, u8 *arg1);
s32 TAdSinglePlyChrSelectGC__sub_801FFCFC(saddr arg0, saddr arg1);
void TAdSinglePlyChrSelectGC__sub_801FFF14(void);
void TAdSinglePlyChrSelectGC__sub_801FFF98(void *arg0);
s32 TAdSinglePlyChrSelectGC__sub_802000C8(void *arg0_, void *arg1);
void TAdSinglePlyChrSelectGC__sub_80200418(void);
u32 calc_crc32_bitwise(u8 *arg0, u32 arg1);
s32 alloc_global_buffer(void);
s32 buffer_init(void);
void game_state_load(void);
s32 get_field_118__22TAdEnterSerialAccessGCFv(void);
s32 get_serial_result__22TAdEnterSerialAccessGCFv(void);
int get_split_screen_character_save_record(int a0);
s32 init_buffer(void);
void init_fresh_character_card(void);
void init_fresh_character_slot(s32 arg0);
void init_timestamped_data(void);
s32 load_and_verify_data(s32 arg0);
s32 load_guild_card_save(void);
s32 load_pso_system(void);
s32 load_system_file(s32 arg0);
void load_tables(int a0);
s32 pso_system_load_gc(void);
}

#endif
