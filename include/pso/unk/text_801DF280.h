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
void *copy_cmd_88_marker_record(void *p, void *a1);
void bswap_cmd_c4_body(void *p);
void bswap_cmd_c4_entry(void *arg0);
void bswap_cmd_c4_entry_record(s32 arg0);
s32 *copy_cmd_c4_entry_table(s32 *arg0, s32 *arg1);
int copy_cmd_c4_entry(int arg0, int arg1);
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
void *copy_cmd_88_marker_record(void *p, void *a1);
void bswap_cmd_c4_body(void *p);
void bswap_cmd_c4_entry(void *arg0);
void bswap_cmd_c4_entry_record(s32 arg0);
s32 *copy_cmd_c4_entry_table(s32 *arg0, s32 *arg1);
int copy_cmd_c4_entry(int arg0, int arg1);
void bswap_choice_search_packet(void *p);
void bswap_u16_pair_field(void *p);
void bswap_c0_lobby_entry(void *p);
void bswap_change_ship_block_packet(void *p);
s32 construct_change_ship_block_packet(s32 arg0);
}
// --- end of C functions

#endif
