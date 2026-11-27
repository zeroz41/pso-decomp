#include "pso/math/ClampedStep.h"
#include "pso/system/TrailStrip.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/network/TGameProtocol.h"
#include "pso/render/render_util.h"

#include "pso/item/TItemAttackColBase.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/render/model_render_state.h"

#pragma readonly_strings on


struct Send6xADOlgaFlowSubordinateBossActionsB { u8 hdr[4]; u8 d[0x40]; u8 tail[8+1]; };

const char *TItemEffOrgaFlowShot::class_name = "TItemEffOrgaFlowShot";

extern "C" {
int olga_flow_subordinate_actions_enabled;
}

void send_6xAD_olga_flow_subordinate_boss_actions(u8 *actions) {
    Send6xADOlgaFlowSubordinateBossActionsB b;
    s32 i;
    if (is_local_client_floor_leader() != 0) {
        build_6xAD_olga_flow_subordinate_boss_actions(&b);
        for (i = 0; i < 0x40; i++) {
            b.d[i] = actions[i];
        }
        ((TItemEffOrgaFlowShot *)(&b))->bswap_6xAD_subordinate_action();
    }
}

void clear_6xAD_action_buffer(s8 *buf) {
    s32 var_ctr;

    for (var_ctr = 0x40; var_ctr != 0; var_ctr -= 1) {
        *buf = -1;
        buf += 1;
    }
}

struct Send6xADOlgaFlowSubordinateBossActionsB;
void handle_6xAD_olga_flow_subordinate_boss_actions(G_OlgaFlowSubordinateBossActions_6xAD *command) {
    Vec v[3];
    s8 boss;
    s32 n;
    s8 *p;
    s32 i;
    s32 j;
    if (olga_flow_subordinate_actions_enabled == 0) {
        return;
    }
    read_be16_field2_forward(command);
    boss = command->actions[0];
    if (boss >= 0) {
        p = &command->actions[1];
        n = 0;
        for (i = 0; i < 3; i++, p += 2) {
            if (p[0] < 0 || p[1] < 0) {
                break;
            }
            TBoss6Type2::grid_to_world_pos(p[0], p[1], &v[i]);
            n++;
        }
        TBoss6Mag::set_path_points_by_index(boss, v, n);
    }
    for (j = 0; j < 0x40; j++) {
        if (command->actions[j] >= 0 && j >= 7 && j <= 0x26) {
            s8 c = command->actions[j];
            s32 idx = j - 7;
            s32 a = 0;
            s32 type = c & 0xF;
            s32 f;
            if (c & 0x40) {
                a = 1;
            }
            f = 0;
            if (c & 0x20) {
                f = 1;
            }
            switch (type) {
            case 0:
                TBoss6Rock::set_rock_target(idx, a, f);
                break;
            case 1:
                TBoss6Rock::clear_rock_state(idx);
                break;
            }
        }
    }
}

void disable_olga_flow_subordinate_actions(void) { olga_flow_subordinate_actions_enabled = 0; }

void enable_olga_flow_subordinate_actions(void) { olga_flow_subordinate_actions_enabled = 1; }

void TItemEffOrgaFlowShot::bswap_6xAD_subordinate_action() { read_be16_field2_forward(this); send_subcommand((u8 *)this); }

void read_be16_field2_forward(void* p) { ((G_ClientIDHeader *)p)->bswap(); }
void build_6xAD_olga_flow_subordinate_boss_actions(void* p) { *(u8*)((char*)p + 0x0) = 173; *(u8*)((char*)p + 0x1) = 17; }


#pragma push
#pragma fp_contract on
#pragma fp_contract on

void TItemEffOrgaFlowShot::update_segments() {
    TrailStripVertex *dst;
    TrailStripVertex *src;
    f32 dx;
    f32 dz;
    s32 i;
    dst = &trail[0];
    src = &trail[1];
    trail[1].x = head_dir.x * spread + trail[3].x;
    trail[1].y = head_dir.y * spread + trail[3].y;
    trail[1].z = head_dir.z * spread + trail[3].z;
    trail[9].x = tail_dir.x * spread + trail[7].x;
    trail[9].y = tail_dir.y * spread + trail[7].y;
    trail[9].z = tail_dir.z * spread + trail[7].z;
    dx = forward.x * length;
    dz = forward.z * length;
    for (i = 0; i < 5; i++) {
        dst->x = src->x + dx;
        dst->y = src->y;
        dst->z = src->z + dz;
        dst->color = src->color;
        dst += 2;
        src += 2;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TItemEffOrgaFlowShot::update_position_from_velocity() {
    f32 radius;
    radius = 0.5f * length;
    body.radius = radius;
    body.half_width = 4.0f + spread;
    position.x = (forward.x * radius) + trail[5].x;
    position.y = trail[5].y;
    position.z = (forward.z * radius) + trail[5].z;
}
#pragma pop

void TItemEffOrgaFlowShot::render() {
    begin_effect_render();
    saved_model_render_flags = model_render_flags;
    set_depth_buffer_settings_1();
    set_additive_blend();
    setup_world_color_draw(1);
    draw_untextured_trail_strip(trail, 10);
    reset_player_transform();
    set_default_alpha_blend();
    restore_saved_depth_alpha_state();
    model_render_flags = saved_model_render_flags;
    end_effect_render();
}

void TItemEffOrgaFlowShot::run_task() {
    s32 i;
    if (has_game_join_id() != 0) {
        check_hits();
    } else {
        queue_destruction();
        disallow_rendering();
    }
    ::approach_value(&length, 50.0f, max_length);
    if (length == max_length) {
        ::approach_value(&spread, 0.6f, max_spread);
    }
    for (i = 0; i != 10; i++) {
        TObjBoss2Tunnel::decrement_packed_timer(&trail[i].color, 2);
    }
    if (spread == max_spread) {
        if (linger_frames-- == 0) {
            queue_destruction();
        }
    }
    update_segments();
    update_position_from_velocity();
}

TItemEffOrgaFlowShot::~TItemEffOrgaFlowShot() {}

TItemEffOrgaFlowShot::TItemEffOrgaFlowShot(TObject *parent, OrgaFlowShotParams *params) : TItemAttackColBase(parent, params) {
    m_name = class_name;
    hits_objects = 0;
    body.shape = 1;
    body.half_width = 10.0f;
    rotation_y = params->rotation_y;
    angle = params->rotation_y;
    length = 0.0f;
    max_length = 200.0f;
    spread = 0.0f;
    linger_frames = 0x14;
    forward.x = sin_table_lookup(angle);
    forward.y = 0.0f;
    forward.z = cos_table_lookup(angle);
    head_dir.x = params->joints[0].x - params->joints[1].x;
    head_dir.y = params->joints[0].y - params->joints[1].y;
    head_dir.z = params->joints[0].z - params->joints[1].z;
    max_spread = 3.0f * normalize_vector(&head_dir);
    tail_dir.x = params->joints[4].x - params->joints[3].x;
    tail_dir.y = params->joints[4].y - params->joints[3].y;
    tail_dir.z = params->joints[4].z - params->joints[3].z;
    normalize_vector(&tail_dir);
    trail[3].x = params->joints[1].x;
    trail[3].y = params->joints[1].y;
    trail[3].z = params->joints[1].z;
    trail[3].color = 0x6040FF40;
    trail[5].x = params->joints[2].x;
    trail[5].y = params->joints[2].y;
    trail[5].z = params->joints[2].z;
    trail[5].color = 0x408840;
    trail[7].x = params->joints[3].x;
    trail[7].y = params->joints[3].y;
    trail[7].z = params->joints[3].z;
    trail[7].color = 0x6040FF40;
    trail[1].color = 0x408840;
    trail[9].color = 0x408840;
    update_segments();
    update_position_from_velocity();
}

void TItemEffOrgaFlowShot::create(TObject *parent, OrgaFlowShotParams *params) {
    new TItemEffOrgaFlowShot(parent, params);
}
