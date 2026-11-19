#ifndef PSO_UNK_TLOBBY_800F8AA8_H
#define PSO_UNK_TLOBBY_800F8AA8_H

#include "types.h"

extern "C" {
// The name copy_name last copied (16 characters, not terminated when full).
extern char player_name_copy_buffer[16];
// What __sinit stores into disc_read_filename: an empty file name.
extern const char *lbl_805D2B10;

void TLobby__sub_800F8AD0(void);
void TLobby__sub_800F8BD8(void);
void TLobby__sub_800F8DD8(void);
void TLobby__sub_800F8F34(void);
void apply_phase_keyboard_mode(void);
bool is_area_transfer_pending(void);
}

#endif
