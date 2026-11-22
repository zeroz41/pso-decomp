#ifndef PSO_PLAYER_TOBJPLAYER_801D3554_H
#define PSO_PLAYER_TOBJPLAYER_801D3554_H

#include "types.h"

u8 *copy_drop_node(u8 *arg0, u8 *arg1);
extern "C" {
void fn_801D371C(void *p, void *q);
void insert_item_node__10TObjPlayerFiiiii(saddr list, s32 pos, s32 source, s32 arg3, s32 id);
}
void start_placement_search(saddr arg0, saddr arg1, saddr arg2);

// --- C functions defined in TObjPlayer_801D3554.cpp ---
extern "C" {
void fn_801D371C(void *p, void *q);
void insert_item_node__10TObjPlayerFiiiii(saddr list, s32 pos, s32 source, s32 arg3, s32 id);
}
// --- end of C functions

#endif
