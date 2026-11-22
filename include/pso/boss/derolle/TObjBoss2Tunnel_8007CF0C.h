#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007CF0C_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007CF0C_H

#include "types.h"

extern "C" {
void TObjBoss2Tunnel__sub_8007DD24(void);
}
// Takes a snapshot of the screen inside the C stick frame and saves it to the memory card.
s32 take_snapshot(void);
// Moves the capture frame with the C stick and keeps it on screen.
void move_snapshot_frame(void);
void draw_snapshot_capture_overlay(void);
void load_data_buffers(void);
extern "C" {
s32 memcard_check_snapshot(s32 for_save, s32 *error);
}

#endif
