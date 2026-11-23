#ifndef PSO_PLAYER_PLAYERDEATHSINK_H
#define PSO_PLAYER_PLAYERDEATHSINK_H

#include "types.h"

struct TObjPlayer;

// (name inferred) How far a dead player's body sinks, at TObjPlayer+0x5FC; update_death_pose
// advances progress and draw_body adds offset to the drawn height.
struct PlayerDeathSink {
    PlayerDeathSink();
    void reset();
    void set_progress(f32 v);
    void add_progress(f32 step);
    void update_offset();
    void calc_height(TObjPlayer *player);

    f32 offset;    // height * progress
    f32 height;    // (name inferred) clamped to -4..3 by calc_height
    f32 progress;  // (name inferred) 0..1
};
LAYOUT_ASSERT(PlayerDeathSink_size, sizeof(PlayerDeathSink) == 0xC);

#endif
