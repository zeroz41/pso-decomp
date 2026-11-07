#ifndef PSO_UNK_TEXT_801DF280_H
#define PSO_UNK_TEXT_801DF280_H

#include "types.h"

struct packet_header;
void bswap_c0_lobby_entries(void *p);
void bswap_choice_search_config(void *p);
void bswap_cmd_88_body(void *p);
void bswap_cmd_88_marker_record(void *p);
int bswap_cmd_8a_header(void *p);
int bswap_packet_header_cmd_b1(void *p);
void bswap_save_packet(s32 arg0);
extern "C" {
s32 *copy_entry_table(s32 *arg0, s32 *arg1);
void bswap_cmd_db_regist_connect_reply(packet_header *arg0);
s32 construct_cmd_db_regist_connect_reply(s32 arg0);
void *fn_801DF3F0(void *p, void *a1);
void fn_801DF42C(void *p);
void fn_801DF47C(void *arg0);
void fn_801DF4B8(s32 arg0);
s32 *fn_801DF4FC(s32 *arg0, s32 *arg1);
int fn_801DF558(int arg0, int arg1);
void bswap_choice_search_packet(void *p);
void bswap_u16_pair_field(void *p);
void bswap_c0_lobby_entry(void *p);
void bswap_change_ship_block_packet(void *p);
s32 construct_change_ship_block_packet(s32 arg0);
}

// --- C functions defined in text_801DF280.cpp ---
extern "C" {
s32 *copy_entry_table(s32 *arg0, s32 *arg1);
void bswap_cmd_db_regist_connect_reply(packet_header *arg0);
s32 construct_cmd_db_regist_connect_reply(s32 arg0);
void *fn_801DF3F0(void *p, void *a1);
void fn_801DF42C(void *p);
void fn_801DF47C(void *arg0);
void fn_801DF4B8(s32 arg0);
s32 *fn_801DF4FC(s32 *arg0, s32 *arg1);
int fn_801DF558(int arg0, int arg1);
void bswap_choice_search_packet(void *p);
void bswap_u16_pair_field(void *p);
void bswap_c0_lobby_entry(void *p);
void bswap_change_ship_block_packet(void *p);
s32 construct_change_ship_block_packet(s32 arg0);
}
// --- end of C functions

#endif
