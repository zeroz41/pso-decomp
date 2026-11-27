#ifndef PSO_BOSS_OLGAFLOW_OLGAFLOWACTIONS_H
#define PSO_BOSS_OLGAFLOW_OLGAFLOWACTIONS_H

#include "types.h"

#include "pso/network/protocol/protocol_types.h"
#include <stddef.h>

struct Vec;
struct Boss6Type2MoveTarget;

// High byte of the angle, then the radius and height in units of ten.
struct Boss6PolarBytes {
    s8 angle;
    s8 radius;
    s8 height;

    void decode_polar_position(Vec *position);
};

struct Boss6FlowAction {
    s8 action;
    Boss6PolarBytes position;

    void decode_target(Vec *target);
};

// The grid cell (TBoss6Type2::grid_to_world_pos) and the high byte of the heading.
struct Boss6GridBytes {
    s8 grid_x;
    s8 grid_z;
    s8 heading;

    void decode_grid_position(Boss6Type2MoveTarget *target);
};

struct Boss6Type2FlowAction {
    s8 action;
    Boss6GridBytes position;

    void decode_target(Boss6Type2MoveTarget *target);
};

// 6xA4: Olga Flow's first form action. Sent by TBoss6Type1::send_6xA4_action and
// send_flow_action_if_idle; received by handle_6xA4_olga_flow_boss_actions. The header holds the
// boss's entity id; initialize sets the header size to 5 words.
struct OlgaFlowActionMsg {
    G_ClientIDHeader header;
    Boss6FlowAction flow;
    s8 attack_mode;
    s8 target_mode;
    u8 random_factor;
    u8 reserved_0b[9];

    void initialize();
    void swap_entity_id();
    void send();
};

// 6xA5: Olga Flow's second form action. Sent by TBoss6Type2::send_action_packet and
// send_action_packet_if_idle; received by handle_6xA5_olga_flow_boss_actions. initialize sets the
// header size to 5 words.
struct OlgaFlowType2ActionMsg {
    G_ClientIDHeader header;
    Boss6Type2FlowAction flow;
    u8 random_factor;
    s8 next_motion;
    s8 target_mode;
    s8 target_state;
    s8 first_client;
    s8 second_client;
    s8 first_action_client;
    s8 second_action_client;
    u8 reserved_10[4];

    void initialize();
    void swap_entity_id();
    void send();
};

LAYOUT_ASSERT(OlgaFlowActionMsg_size, sizeof(OlgaFlowActionMsg) == 0x14);
LAYOUT_ASSERT(OlgaFlowActionMsg_flow_offset, offsetof(OlgaFlowActionMsg, flow) == 4);
LAYOUT_ASSERT(OlgaFlowActionMsg_sync_offset, offsetof(OlgaFlowActionMsg, attack_mode) == 8);
LAYOUT_ASSERT(OlgaFlowType2ActionMsg_size, sizeof(OlgaFlowType2ActionMsg) == 0x14);
LAYOUT_ASSERT(OlgaFlowType2ActionMsg_action_offset, offsetof(OlgaFlowType2ActionMsg, flow) == 4);
LAYOUT_ASSERT(OlgaFlowType2ActionMsg_sync_offset, offsetof(OlgaFlowType2ActionMsg, random_factor) == 8);

// 6xA3: Olga Flow's plot phase and spawn variant. Sent by TBoss6PlotFalz::send_6xA3_action;
// received by handle_6xA3_olga_flow_boss_actions. initialize sets the header size to 5 words.
struct OlgaFlowPlotActionMsg {
    G_ClientIDHeader header;
    s8 phase;
    s8 mode;
    u8 reserved_06[14];

    void initialize();
    void swap_entity_id();
    void send();
};

LAYOUT_ASSERT(OlgaFlowPlotActionMsg_size, sizeof(OlgaFlowPlotActionMsg) == 0x14);
LAYOUT_ASSERT(OlgaFlowPlotActionMsg_phase_offset, offsetof(OlgaFlowPlotActionMsg, phase) == 4);

struct game_command_header;
void handle_6xA3_olga_flow_boss_actions(game_command_header *command);
void handle_6xA4_olga_flow_boss_actions(game_command_header *command);
void handle_6xA5_olga_flow_boss_actions(game_command_header *command);

#endif
