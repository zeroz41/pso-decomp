#ifndef PSO_UI_WINDOW_TWINDOWSNAPSHOT_802A7D68_H
#define PSO_UI_WINDOW_TWINDOWSNAPSHOT_802A7D68_H

#include "types.h"

extern "C" {
void TWindowSnapShot__sub_802A7DA0(void);
}

// --- C functions defined in TWindowSnapShot_802A7D68.cpp ---
extern "C" {
void TWindowSnapShot__sub_802A7DA0(void);
}
// --- end of C functions

s32 copy_if_space(void);
extern "C" {
void set_motion_variant(void *p, s32 _w1);
int matches_loaded_motion(void *p);
u8 *TLobby__sub_802A7B50(u8 *arg0);
int TLobby__sub_802A7B8C(void);
void zero_pair_fields(void *p);
void free_snapshot_image_buffer(void);
void set_slot_position__6TLobbyFii(s32 arg0, saddr arg1);
}

#endif
