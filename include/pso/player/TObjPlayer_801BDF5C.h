#ifndef PSO_PLAYER_TOBJPLAYER_801BDF5C_H
#define PSO_PLAYER_TOBJPLAYER_801BDF5C_H

#include "types.h"

struct TObjPlayer;

// --- C functions defined in TObjPlayer_801BDF5C.cpp ---
extern "C" {
// The player of this machine's client, or NULL.
TObjPlayer *get_local_player();
void TObjPlayer__sub_801BE2C0(void *p, s32 v);
s32 TObjPlayer__sub_801BE2C8(void *p);
void set_byte_2e7__10TObjPlayerFPvUc(void *p, u8 v);
void set_byte_2cb__10TObjPlayerFPvUc(void *p, u8 v);
void set_byte_2af__10TObjPlayerFPvUc(void *p, u8 v);
void set_byte_293__10TObjPlayerFPvUc(void *p, u8 v);
int TObjPlayer__sub_801BE7BC(void *p);
void set_byte_277__10TObjPlayerFPvUc(void *p, u8 v);
void set_byte_25b__10TObjPlayerFPvUc(void *p, u8 v);
void set_byte_23f__10TObjPlayerFPvUc(void *p, u8 v);
void set_byte_223__10TObjPlayerFPvUc(void *p, u8 v);
void *TObjPlayer__sub_801BE918(void *a0, int a1, void *a2, void *a3);
int TObjPlayer__sub_801BEABC(void *p);
s32 get_field_334__10TObjPlayerFPv(void *p);
u8 get_byte_at_2e7__10TObjPlayerFPv(void *p);
u8 get_byte_at_2cb__10TObjPlayerFPv(void *p);
u8 get_byte_at_2af__10TObjPlayerFPv(void *p);
int TObjPlayer__sub_801BEB68(void *p);
u8 get_byte_at_293__10TObjPlayerFPv(void *p);
u8 get_byte_at_277__10TObjPlayerFPv(void *p);
u8 get_byte_at_25b__10TObjPlayerFPv(void *p);
u8 get_byte_at_23f__10TObjPlayerFPv(void *p);
u8 TObjPlayer__sub_801BEC3C(void *p);
void __sinit_TObjPlayer_801BDF5C_cpp(void);
u8 *create_player_object(s16 slot, s32 role, u8 *arg2);
s32 destroy_char_data__10TObjPlayerFis(saddr arg0, s16 arg1);
}
// --- end of C functions

#endif
