#ifndef PSO_OBJECT_LOBBY_LOBBYGOGOBALL_H
#define PSO_OBJECT_LOBBY_LOBBYGOGOBALL_H

#include "types.h"
#include "dolphin/mtx/GeoTypes.h"

// The lobby Go-Go ball as last received from the 6x79 subcommand, plus the goals it scored.
struct GoGoBallSyncState {
    Vec position;    // ball position from the packet (y is always 0)
    s32 angle;       // passed to the ball's throw setup
    s16 goal_flags;  // 1/2: team 0/1 one-point goal, 0x10/0x20: three-point goal
    s16 applied;     // 0 while a received packet waits to be applied to the ball
    s32 sequence;    // the ball takes a packet only when this is not older than its own
    u8 mode;         // 1 selects the alternative throw speeds of the configuration
};
LAYOUT_ASSERT(GoGoBallSyncState_size, sizeof(GoGoBallSyncState) == 0x1C);

// One of the ten lobby Go-Go ball setups, copied from the table by the internet beat.
struct GoGoBallConfig {
    f32 gravity;
    u8 pad_4[0xC - 0x4];
    f32 throw_forward_speed;
    f32 throw_up_speed;
    s16 lifetime;               // frames before the ball says "Good Bye"; also the goal effects' lifetime
    u8 pad_16[0x1C - 0x16];
    f32 radius;
    Vec start_position;
    Vec team1_goal;             // a ball resting here scores one point for team 1
    Vec team0_goal;             // a ball resting here scores one point for team 0
    f32 goal_radius;
    u16 ball_type;              // selects the ball's model and textures
    u8 pad_4a[0x4C - 0x4A];
    f32 throw_forward_speed_alt;  // used instead when the sync state's mode is 1
    f32 throw_up_speed_alt;
};
LAYOUT_ASSERT(GoGoBallConfig_size, sizeof(GoGoBallConfig) == 0x54);

extern GoGoBallConfig gogo_ball_configuration;
extern GoGoBallSyncState gogo_ball_sync_state;

#endif
