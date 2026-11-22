#ifndef PSO_CAMERA_TCAMERACTRL_8006CC30_H
#define PSO_CAMERA_TCAMERACTRL_8006CC30_H

#include "types.h"

struct Vec;

extern "C" {
void end_conversation_camera(void);
void begin_conversation_camera(void);
// Eases the follow camera to these offsets from the player, turned by the player's
// facing (the local player's, or client_id's in split screen).
void request_follow_camera_offsets(Vec *position, Vec *target, u16 client_id);
}

// Hands the offsets to the follow camera of each view (client_id 0xFFFF: every view, each
// turned by its player's facing plus angle).
void apply_follow_camera_offsets(Vec *position, Vec *target, s32 angle, u16 client_id);

#endif
