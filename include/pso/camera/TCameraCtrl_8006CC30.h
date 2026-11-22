#ifndef PSO_CAMERA_TCAMERACTRL_8006CC30_H
#define PSO_CAMERA_TCAMERACTRL_8006CC30_H

#include "types.h"

struct Vec;

extern "C" {
void end_conversation_camera(void);
void begin_conversation_camera(void);
// Eases the follow camera to these offsets from the player, turned by the player's
// facing (the local player's, or client_id's in split screen).
void request_follow_camera_offsets(Vec *position, const Vec *target, u16 client_id);
}

#endif
