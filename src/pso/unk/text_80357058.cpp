#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/item/TItemAttackCol_802E4798.h"
#include "pso/object/TObjLight_803DF220.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/unk/text_80141A30.h"
#include "pso/unk/text_802E4A4C.h"
#include "pso/unk/text_80357058.h"
#include "pso/render/depth_buffer.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/boss/TBoss6Type2.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/item/TItemAttackCol.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80357548___vt__20TItemEffOrgaFlowShot { s32 value; u8 remaining[0x1C]; };
typedef char RecoveredGlobal_80357548___vt__20TItemEffOrgaFlowShot_size[sizeof(RecoveredGlobal_80357548___vt__20TItemEffOrgaFlowShot) == 0x20 ? 1 : -1];

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

struct Vec_803570E4 { f32 x, y, z; };

struct V4_8035740C { f32 x, y, z; s32 w; };

struct O_8035740C { u8 pad0[0xC4]; V4_8035740C v[10]; };

extern "C" {
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 normalize_vector(void *);
extern s32 __vt__20TItemEffOrgaFlowShot[];
extern s32 TItemEffOrgaFlowShot__name;
extern const f32 lbl_805E0038;
extern const f32 lbl_805E003C;
extern const f32 lbl_805E0040;
extern const f32 lbl_805E0044;
extern const f32 lbl_805E0028;
extern const f32 lbl_805E002C;
s32 is_local_client_floor_leader();
void grid_to_world_pos__11TBoss6Type2FccPv(u8, u8, Vec_803570E4 *);
void clear_rock_state__10TBoss6RockFl(s32 i, s32 a, s32 b);
extern int olga_flow_subordinate_actions_enabled;
void handle_6xAD_olga_flow_subordinate_boss_actions(Pkt_803570E4 *pkt);
s32 has_game_join_id__13TUnk_804E355CFv();
extern const f32 lbl_805E0030;
extern const f32 lbl_805E0034;
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
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

void TBoss6Type2__sub_803570C8(s8 *arg0) {
    s32 var_ctr;

    for (var_ctr = 0x40; var_ctr != 0; var_ctr -= 1) {
        *arg0 = -1;
        arg0 += 1;
    }
}

struct B_80357058;
void handle_6xAD_olga_flow_subordinate_boss_actions(Pkt_803570E4 *pkt) {
    Vec_803570E4 v[3];
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
            grid_to_world_pos__11TBoss6Type2FccPv(p[0], p[1], &v[i]);
            n++;
        }
        TBoss6Type2::set_path_points_by_index(boss, v, n);
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
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    temp_f2 = lbl_805E0028 * *(f32 *)&this->m_190;
    this->m_40 = temp_f2;
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) (lbl_805E002C + *(f32 *)&this->m_194);
    this->m_24 = (f32) ((this->m_17c * temp_f2) + this->m_114);
    *(f32 *)&this->m_28 = (f32) *(f32 *)&this->unk_118;
    *(f32 *)&this->unk_2C = (f32) ((this->m_184 * temp_f2) + this->m_11c);
}
#pragma pop

void TItemEffOrgaFlowShot::render() {
    s32 arg0 = (s32)this;
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    set_depth_buffer_settings_1();
    TObjPlayer::init_xyz_limits();
    TObjPlayer__sub_803DF768(1);
    draw_untextured_trail_strip((void *)(arg0 + 0xC4), (void *)(0xA));
    reset_player_transform();
    TObjPlayer::reset_transform_state();
    restore_saved_depth_alpha_state();
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
}

void run_task__20TItemEffOrgaFlowShotFv(u8 *item_eff_orga_flow_shot) {
    s32 temp_r3;
    s32 i;
    if (has_game_join_id__13TUnk_804E355CFv() != 0) {
        ((TUnk_804E355C *)item_eff_orga_flow_shot)->check_hits();
    } else {
        queue_destruction__7TObjectFv((item_eff_orga_flow_shot));
        disallow_rendering__7TObjectFv((TObject *)(item_eff_orga_flow_shot));
    }
    TItemEffOrgaFlowShot::approach_value((f32 *)(item_eff_orga_flow_shot + 0x190), (f32)lbl_805E0030, (f32)((f32) (*(f32 *)((s8 *)item_eff_orga_flow_shot + 0x18C))));
    if (*(f32 *)((s8 *)item_eff_orga_flow_shot + 0x190) == *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x18C)) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(item_eff_orga_flow_shot + 0x194), (f32)lbl_805E0034, (f32)((f32) (*(f32 *)((s8 *)item_eff_orga_flow_shot + 0x198))));
    }
    for (i = 0; i != 10; i++) {
        TObjBoss2Tunnel::decrement_packed_timer((u32 *)(&((O_8035740C *)item_eff_orga_flow_shot)->v[i].w), 2);
    }
    if (*(f32 *)((s8 *)item_eff_orga_flow_shot + 0x194) == *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x198)) {
        temp_r3 = ((TItemEffOrgaFlowShot *)item_eff_orga_flow_shot)->m_19c;
        ((TItemEffOrgaFlowShot *)item_eff_orga_flow_shot)->m_19c = (temp_r3 - 1);
        if (temp_r3 == 0) {
            queue_destruction__7TObjectFv((item_eff_orga_flow_shot));
        }
    }
    ((TItemEffOrgaFlowShot *)item_eff_orga_flow_shot)->update_segments();
    ((TItemEffOrgaFlowShot *)item_eff_orga_flow_shot)->update_position_from_velocity();
}

void *__dt__20TItemEffOrgaFlowShotFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TItemEffOrgaFlowShot;
        ((TUnk_804E355C *)arg0)->destroy_attack_collision(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TItemEffOrgaFlowShot__ct(TItemEffOrgaFlowShot *item_eff_orga_flow_shot, s32 arg1, u8 *arg2) {
    construct_attack_collision((u8 *)item_eff_orga_flow_shot, arg1, arg2);
    *(s32 **)((s8 *)item_eff_orga_flow_shot + 0x18) = &(*(RecoveredGlobal_80357548___vt__20TItemEffOrgaFlowShot *)&__vt__20TItemEffOrgaFlowShot).value;
    *(s32 *)((s8 *)item_eff_orga_flow_shot + 0) = (s32) TItemEffOrgaFlowShot__name;
    *(s32 *)((s8 *)item_eff_orga_flow_shot + 0xC0) = 0;
    item_eff_orga_flow_shot->m_48 = 1;
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x44) = (f32) lbl_805E0038;
    *(s32 *)((s8 *)item_eff_orga_flow_shot + 0x30) = (s32) *(s32 *)((s8 *)arg2 + 0x28);
    item_eff_orga_flow_shot->m_188 = (s32) *(s32 *)((s8 *)arg2 + 0x28);
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x190) = (f32) lbl_805E003C;
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x18C) = (f32) lbl_805E0040;
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x194) = (f32) lbl_805E003C;
    item_eff_orga_flow_shot->m_19c = 0x14;
    item_eff_orga_flow_shot->m_17c = sin_table_lookup(item_eff_orga_flow_shot->m_188);
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x180) = (f32) lbl_805E003C;
    item_eff_orga_flow_shot->m_184 = cos_table_lookup(item_eff_orga_flow_shot->m_188);
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x164) = (f32) (*(f32 *)((s8 *)arg2 + 0x2C) - *(f32 *)((s8 *)arg2 + 0x38));
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x168) = (f32) (*(f32 *)((s8 *)arg2 + 0x30) - *(f32 *)((s8 *)arg2 + 0x3C));
    item_eff_orga_flow_shot->m_16c = (f32) (*(f32 *)((s8 *)arg2 + 0x34) - *(f32 *)((s8 *)arg2 + 0x40));
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x198) = (f32) (lbl_805E0044 * normalize_vector((u8 *)item_eff_orga_flow_shot + 0x164));
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x170) = (f32) (*(f32 *)((s8 *)arg2 + 0x5C) - *(f32 *)((s8 *)arg2 + 0x50));
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x174) = (f32) (*(f32 *)((s8 *)arg2 + 0x60) - *(f32 *)((s8 *)arg2 + 0x54));
    item_eff_orga_flow_shot->m_178 = (f32) (*(f32 *)((s8 *)arg2 + 0x64) - *(f32 *)((s8 *)arg2 + 0x58));
    normalize_vector((u8 *)item_eff_orga_flow_shot + 0x170);
    item_eff_orga_flow_shot->m_f4 = (f32) *(f32 *)((s8 *)arg2 + 0x38);
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0xF8) = (f32) *(f32 *)((s8 *)arg2 + 0x3C);
    item_eff_orga_flow_shot->m_fc = (f32) *(f32 *)((s8 *)arg2 + 0x40);
    item_eff_orga_flow_shot->m_100 = 0x6040FF40;
    item_eff_orga_flow_shot->m_114 = (f32) *(f32 *)((s8 *)arg2 + 0x44);
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x118) = (f32) *(f32 *)((s8 *)arg2 + 0x48);
    item_eff_orga_flow_shot->m_11c = (f32) *(f32 *)((s8 *)arg2 + 0x4C);
    item_eff_orga_flow_shot->m_120 = 0x408840;
    item_eff_orga_flow_shot->m_134 = (f32) *(f32 *)((s8 *)arg2 + 0x50);
    *(f32 *)((s8 *)item_eff_orga_flow_shot + 0x138) = (f32) *(f32 *)((s8 *)arg2 + 0x54);
    item_eff_orga_flow_shot->m_13c = (f32) *(f32 *)((s8 *)arg2 + 0x58);
    item_eff_orga_flow_shot->m_140 = 0x6040FF40;
    item_eff_orga_flow_shot->m_e0 = 0x408840;
    item_eff_orga_flow_shot->m_160 = 0x408840;
    item_eff_orga_flow_shot->update_segments();
    item_eff_orga_flow_shot->update_position_from_velocity();
    return (u8 *)item_eff_orga_flow_shot;
}

void TItemEffOrgaFlowShot::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x1A0);
    if (o != NULL) {
        TItemEffOrgaFlowShot__ct((TItemEffOrgaFlowShot *)((u8 *)o), (s32)((s32)arg0), (u8 *)((u8 *)arg1));
    }
}
