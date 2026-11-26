#ifndef PSO_PLAYER_PLAYERDATALOAD_H
#define PSO_PLAYER_PLAYERDATALOAD_H

#include "types.h"

void free_player_data_load_buffer(void);

// --- C functions defined in PlayerDataLoad.cpp ---
void free_player_data_load_buffer(void);
// --- end of C functions

saddr get_global_63e0();
void load_player_data();

#endif
