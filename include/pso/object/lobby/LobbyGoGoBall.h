#ifndef PSO_OBJECT_LOBBY_LOBBYGOGOBALL_H
#define PSO_OBJECT_LOBBY_LOBBYGOGOBALL_H

#include "types.h"
#include "dolphin/mtx/GeoTypes.h"
#include "pso/network/protocol/protocol_types.h"

// 6x79: where the lobby Go-Go ball was thrown from.
struct G_GoGoBall_6x79 {
    G_ClientIDHeader header;
    s32 sequence;
    s32 angle;
    f32 x;
    f32 z;
    u8 mode;
    void init();
    void send();
    void bswap();
};
LAYOUT_ASSERT(G_GoGoBall_6x79_size, sizeof(G_GoGoBall_6x79) == 0x18);

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
    f32 restitution;            // the ball keeps this much of its speed on each bounce
    f32 pad_8;
    f32 throw_forward_speed;
    f32 throw_up_speed;
    s16 lifetime;               // frames before the ball says "Good Bye"; also the goal effects' lifetime
    u8 pad_16;
    u8 pad_17;
    u8 pad_18;
    u8 pad_19;
    f32 radius;
    Vec start_position;
    Vec team1_goal;             // a ball resting here scores one point for team 1
    Vec team0_goal;             // a ball resting here scores one point for team 0
    f32 goal_radius;
    u16 ball_type;              // selects the ball's model and textures
    f32 throw_forward_speed_alt;  // used instead when the sync state's mode is 1
    f32 throw_up_speed_alt;
    void copy_state(GoGoBallConfig *src);
};
LAYOUT_ASSERT(GoGoBallConfig_size, sizeof(GoGoBallConfig) == 0x54);

extern GoGoBallConfig gogo_ball_configuration;
extern GoGoBallSyncState gogo_ball_sync_state;

// The two teams' scores, shown in the lobby timer window.
extern s32 gogo_ball_team_scores[];
s16 get_gogo_ball_score(s32 team);
void set_gogo_ball_score(s32 team, s32 score);
void add_gogo_ball_one_point_score(s32 team);
void add_gogo_ball_three_point_score(s32 team);
void close_gogo_ball_timer();

// Sends the 6x79 throw of the ball at position; handle_6x79_gogo_ball receives it.
void throw_gogo_ball(Vec *position, s32 angle, s32 sequence);
void handle_6x79_gogo_ball(u8 *packet);

// The Go-Go ball's model and the lobby textures (biri_ball.bml, robby_*.gvm, ...).
void load_lobby_textures();
void free_lobby_textures();

#endif
