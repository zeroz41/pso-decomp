#include "pso/math/ClampedStep.h"
#include "pso/system/TrailStrip.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/object/ambient/TObjLight_803DF220.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_80357058.h"

#include "pso/item/TUnk_804E355C.h"
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
#include "pso/unk/text_803D96A8.h"

#pragma readonly_strings on


struct B_80357058 { u8 hdr[4]; u8 d[0x40]; u8 tail[8+1]; };

struct Vec4_80357284 { f32 x, y, z; s32 w; };

struct Seg_80357284 { Vec4_80357284 a; Vec4_80357284 b; };

struct Shot_80357284 {
    u8 pad0[0xC4];
    Seg_80357284 seg[5];
    f32 v164[3];
    f32 v170[3];
    f32 dir[3];
    u8 pad188[8];
    f32 len;
    f32 speed;
};

struct Pkt_803570E4 { u8 hdr[4]; s8 d[0x40]; };

struct V4_8035740C { f32 x, y, z; s32 w; };

struct O_8035740C { u8 pad0[0xC4]; V4_8035740C v[10]; };

const char *TItemEffOrgaFlowShot::class_name = "TItemEffOrgaFlowShot";

extern "C" {
s32 is_local_client_floor_leader();
void clear_rock_state__10TBoss6RockFl(s32 i, s32 a, s32 b);
int olga_flow_subordinate_actions_enabled;
void handle_6xAD_olga_flow_subordinate_boss_actions(Pkt_803570E4 *pkt);
}

void send_6xAD_olga_flow_subordinate_boss_actions(u8 *arg0) {
    B_80357058 b;
    s32 i;
    if (is_local_client_floor_leader() != 0) {
        build_6xAD_olga_flow_subordinate_boss_actions(&b);
        for (i = 0; i < 0x40; i++) {
            b.d[i] = arg0[i];
        }
        ((TItemEffOrgaFlowShot *)(&b))->bswap_6xAD_subordinate_action();
    }
}

void TBoss6Type2__sub_803570C8(s8 *buf) {
    s32 var_ctr;

    for (var_ctr = 0x40; var_ctr != 0; var_ctr -= 1) {
        *buf = -1;
        buf += 1;
    }
}

struct B_80357058;
void handle_6xAD_olga_flow_subordinate_boss_actions(Pkt_803570E4 *pkt) {
    Vec v[3];
    s8 boss;
    s32 n;
    s8 *p;
    s32 i;
    s32 j;
    if (olga_flow_subordinate_actions_enabled == 0) {
        return;
    }
    read_be16_field2_forward(pkt);
    boss = pkt->d[0];
    if (boss >= 0) {
        p = &pkt->d[1];
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
        if (pkt->d[j] >= 0 && j >= 7 && j <= 0x26) {
            s8 c = pkt->d[j];
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
                clear_rock_state__10TBoss6RockFl(idx, a, f);
                break;
            }
        }
    }
}

void TItemEffOrgaFlowShot__sub_80357204(void) { olga_flow_subordinate_actions_enabled = 0; }

void TItemEffOrgaFlowShot__sub_80357210(void) { olga_flow_subordinate_actions_enabled = 1; }

void TItemEffOrgaFlowShot::bswap_6xAD_subordinate_action() { read_be16_field2_forward(this); send_subcommand((u8 *)this); }

void read_be16_field2_forward(void* p) { ((G_ClientIDHeader *)p)->bswap(); }
void build_6xAD_olga_flow_subordinate_boss_actions(void* p) { *(u8*)((char*)p + 0x0) = 173; *(u8*)((char*)p + 0x1) = 17; }

extern s32 saved_model_render_flags;
extern s32 model_render_flags;

#pragma push
#pragma fp_contract on
#pragma fp_contract on

void TItemEffOrgaFlowShot::update_segments() {
    Shot_80357284 *o = (Shot_80357284 *)this;
    Vec4_80357284 *dst;
    Vec4_80357284 *src;
    f32 dx;
    f32 dz;
    s32 i;
    dst = &o->seg[0].a;
    src = &o->seg[0].b;
    o->seg[0].b.x = o->v164[0] * o->speed + o->seg[1].b.x;
    o->seg[0].b.y = o->v164[1] * o->speed + o->seg[1].b.y;
    o->seg[0].b.z = o->v164[2] * o->speed + o->seg[1].b.z;
    o->seg[4].b.x = o->v170[0] * o->speed + o->seg[3].b.x;
    o->seg[4].b.y = o->v170[1] * o->speed + o->seg[3].b.y;
    o->seg[4].b.z = o->v170[2] * o->speed + o->seg[3].b.z;
    dx = o->dir[0] * o->len;
    dz = o->dir[2] * o->len;
    for (i = 0; i < 5; i++) {
        dst->x = src->x + dx;
        dst->y = src->y;
        dst->z = src->z + dz;
        dst->w = src->w;
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
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    set_depth_buffer_settings_1();
    set_additive_blend();
    setup_world_color_draw(1);
    draw_untextured_trail_strip(trail, 10);
    reset_player_transform();
    set_default_alpha_blend();
    restore_saved_depth_alpha_state();
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
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
        TObjBoss2Tunnel::decrement_packed_timer((u32 *)(&((O_8035740C *)this)->v[i].w), 2);
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

TItemEffOrgaFlowShot::TItemEffOrgaFlowShot(TObject *parent, OrgaFlowShotParams *params) : TUnk_804E355C(parent, params) {
    m_name = class_name;
    pad_C0 = 0;
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

void TItemEffOrgaFlowShot::create(void *parent, void *params) {
    new TItemEffOrgaFlowShot((TObject *)parent, (OrgaFlowShotParams *)params);
}
