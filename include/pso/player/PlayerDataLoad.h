#ifndef PSO_PLAYER_PLAYERDATALOAD_H
#define PSO_PLAYER_PLAYERDATALOAD_H

#include "types.h"

void free_player_data_load_buffer(void);

u8 *get_player_data_load_buffer();
void load_player_data();
void alloc_buffer();

#endif
