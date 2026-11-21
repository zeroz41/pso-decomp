#ifndef PSO_BOSS_OLGAFLOW_OLGAFLOWACTIONS_H
#define PSO_BOSS_OLGAFLOW_OLGAFLOWACTIONS_H

#include "pso/network/protocol/protocol_types.h"
#include <stddef.h>

struct Vec;

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

struct OlgaFlowType2ActionMsg {
    G_ClientIDHeader header;
    s8 action;
    s8 grid_x;
    s8 grid_z;
    s8 heading;
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

typedef char OlgaFlowActionMsg_size[sizeof(OlgaFlowActionMsg) == 0x14 ? 1 : -1];
typedef char OlgaFlowActionMsg_flow_offset[offsetof(OlgaFlowActionMsg, flow) == 4 ? 1 : -1];
typedef char OlgaFlowActionMsg_sync_offset[offsetof(OlgaFlowActionMsg, attack_mode) == 8 ? 1 : -1];
typedef char OlgaFlowType2ActionMsg_size[sizeof(OlgaFlowType2ActionMsg) == 0x14 ? 1 : -1];
typedef char OlgaFlowType2ActionMsg_action_offset[offsetof(OlgaFlowType2ActionMsg, action) == 4 ? 1 : -1];
typedef char OlgaFlowType2ActionMsg_sync_offset[offsetof(OlgaFlowType2ActionMsg, random_factor) == 8 ? 1 : -1];

struct OlgaFlowPlotActionMsg {
    G_ClientIDHeader header;
    s8 phase;
    s8 mode;
    u8 reserved_06[14];

    void initialize();
    void swap_entity_id();
    void send();
};

typedef char OlgaFlowPlotActionMsg_size[sizeof(OlgaFlowPlotActionMsg) == 0x14 ? 1 : -1];
typedef char OlgaFlowPlotActionMsg_phase_offset[offsetof(OlgaFlowPlotActionMsg, phase) == 4 ? 1 : -1];

struct game_command_header;
extern "C" void handle_6xA3_olga_flow_boss_actions(game_command_header *command);
void handle_6xA4_olga_flow_boss_actions(game_command_header *command);
extern "C" void handle_6xA5_olga_flow_boss_actions(game_command_header *command);

#endif
