#ifndef PSO_PLAYER_MOVEMENTHOLD_H
#define PSO_PLAYER_MOVEMENTHOLD_H

#include "types.h"

// TObjPlayer + 0x730, and its copy at + 0x98 of the player join record: a hold that keeps the player
// inside a circle. handle_6x2C_impose_hold fills it from the 6x2C packet and is_outside_movement_hold
// tests the player position against the circle. The player update counts the frames down and sends
// command 0x45 when they run out.
struct MovementHold {
    s16 frames;       // frames left; negative when no hold is running
    s16 effect_type;  // the TObjEneHoldEffect type shown on the held player
    u8 pad_4[0x4];
    f32 radius_sq;    // compared with the squared distance to the centre
    f32 center_x;
    f32 center_z;

    MovementHold *init();
    void reset();
    s32 count_down();
    s16 get_frames();
    f32 get_radius_sq();
    f32 *get_center();
    void set_radius_sq(f32 v);
    void set_center(f32 x, f32 z);
    void set_frames(s16 v);
    void set_effect_type(s16 v);
};

#endif
