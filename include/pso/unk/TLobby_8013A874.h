#ifndef PSO_UNK_TLOBBY_8013A874_H
#define PSO_UNK_TLOBBY_8013A874_H

#include "types.h"

void bswap_u32_pair(void *p);
u8 *copy_join_lobby_entry(u8 *dst, u8 *src);

extern "C" {
void bswap__15disp_data_part2Fv(saddr part2);
}

// --- C functions defined in TLobby_8013A874.cpp ---
extern "C" {
void bswap__15disp_data_part2Fv(saddr part2);
}
// --- end of C functions

#endif
