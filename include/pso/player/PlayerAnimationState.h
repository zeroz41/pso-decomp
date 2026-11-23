#ifndef PSO_PLAYER_PLAYERANIMATIONSTATE_H
#define PSO_PLAYER_PLAYERANIMATIONSTATE_H

#include "types.h"

// (name inferred) The action/animation a player is playing, at TObjPlayer+0x5F0;
// handle_6x52_set_animation_state and send_6x52_animation_state copy it to and from
// the 6x52 packet.
struct PlayerAnimationState {
    PlayerAnimationState();
    void reset();
    void set_state(s16 v);
    void set_action_id(s16 v);
    s16 get_action_id();
    void set_angle(s32 v);
    s32 get_angle();
    void set_animation(s16 v);
    s16 get_animation();
    s16 get_state();

    s16 state;
    s16 action_id;
    s32 angle;      // (name inferred) set from rotation_y
    s16 animation;  // (name inferred) idle animation or requested_action
};
LAYOUT_ASSERT(PlayerAnimationState_size, sizeof(PlayerAnimationState) == 0xC);

#endif
