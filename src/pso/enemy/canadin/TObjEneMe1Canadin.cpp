#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/math/FloatRounding.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/bringer/TObjEneDf2Bringer_Eff_Rush.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/NinjaUtil.h"
#include "pso/player/TObjPlayer_800F0810.h"

#include "pso/render/TUnk_80494938.h"
#include <stddef.h>

#include "pso/enemy/canadin/TObjEneMe1CanadinLeader.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffDischarge.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLine.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"


extern "C" {
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
s32 post_translate_matrix(void *);
// inferred: the BML resource load_resources reads through bm_ene_me1_mb_resource_descriptor
BmlResource *bm_ene_me1_mb_resource;
// inferred: node counter of the render callback (TObjEneDf2Bringer__render_node_index twin)
u32 TObjEneMe1Canadin__render_node_index;
Vec *TObjEneMe1Canadin__render_point_cursor;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
f32 atan2_float(f32 y, f32 x);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 angle);
f32 subtract_vector(void *, void *);
u32 __cvt_fp2unsigned(f32);


struct CanadinBehaviorParams {
    s32 m_0;
    f32 m_4;
    f32 m_8;
    f32 m_C;
    s32 m_10;
};

// The leader's can_member_attack_target slot, called here with a player; TObjEneMe1CanadinLeader declares it without one.
struct CanadinLeaderCallBase { char pad[0x18]; };

struct CanadinLeaderCall : CanadinLeaderCallBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual s32 m114(TObjChara *player);
};

u16 get_entity_id(void *);
f32 newton_sqrtf(f32);
int select_and_apply_target__12TObjEneDD_STFf(void*);
void set_part_position__9TObjEneDDFPvPvi(void *, s32, s32);
void TBoss3Volopt__sub_800D8D88(saddr position);
s32 trigger_dell_biter_events__10TObjPlayerFv(void *, f32);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
s32 matrix_mult_vec(int, Vec *, Vec *);
s32 rotate_vector_by_matrix(int, Vec *, Vec *);

TUnk_8048FA00 *lbl_805D4FDC;
TUnk_8048FA00 *lbl_805D4FE0;
s32 *lbl_805D4FE4;
s32 *lbl_805D4FE8;
s32 *lbl_805D4FEC;
s32 *lbl_805D4FF0;

TObjEneMe1CanadinMovement canadin_setup_param_block = { 225.0f, 0.0f, 0x600, 0, 0, 0, 0 };
CollisionBody lbl_8048FECC = { { 0.0f, 0.0f, 0.0f }, 8.0f, 0.0f, 0, 0x8003 };
// The Canadin's two models and six motions, and the archive that holds them.
const char *bm_ene_me1_mb_model_names[3] = {
    "me1n_y_mb.nj",
    "me1_y_mb.nj",
    NULL
};
const char *bm_ene_me1_mb_motion_names[7] = {
    "change02_me1_y_mb.njm",
    "change01_me1_y_mb.njm",
    "damage01_me1_y_mb.njm",
    "damage02_me1_y_mb.njm",
    "wait01_me1_y_mb.njm",
    "wait02_me1_y_mb.njm",
    NULL
};
BmlResourceDescriptor bm_ene_me1_mb_resource_descriptor = {
    "bm_ene_me1_mb.bml", bm_ene_me1_mb_model_names, bm_ene_me1_mb_motion_names, 2, 6
};
const Vec lbl_8043A268 = { 0.0f, 0.0f, 1.0f };
const Vec lbl_8043A274 = { 0.0f, -1.0f, 0.0f };
const NJS_ARGB canadin_formation_reset_vec4 = { 1.0f, 0.0f, 0.2f, 1.0f };
const NJS_ARGB TObjEneMe1Canadin__map_core_default_vec4 = { 1.0f, 1.0f, 0.0f, 0.2f };
const NJS_ARGB canadin_formation_fade_start_color = { 1.0f, 0.2f, 1.0f, 0.0f };
TObjMotionAction lbl_8048FF30[7] = {
    { 1, 0, 4, 0.2f, 0 },
    { 1, 0, 5, 0.2f, 0 },
    { 2, 1, 1, 0.5f, 0 },
    { 2, 0, 0, 0.5f, 0 },
    { 2, 0, 2, 0.7f, 0 },
    { 2, 1, 3, 0.6f, 0 },
    { 3, 0, 1, 0.5f, 0 },
};
const char *canadin_leader_fade_sequence_table[5] = {
    "ababaababaabbababbabbbbc",
    "abbabbababc",
    "ababaaabbaaabbbabbabababbbbc",
    "abaaabababbac",
    "ababababaabbaabbababaabaabaaabbbbc",
};
const CanadinBehaviorParams canadin_behavior_params = { 3, 5.0f, 3.0f, 3.0f, 1 };
const CanadinBehaviorParams canadin_projectile_param_block = { 3, 10.0f, 20.0f, 3.0f, 1 };
const char *TObjEneMe1Canadin__class_name = "TObjEneMe1Canadin";
const char *TObjEneMe1CanadinLeader__class_name = "TObjEneMe1CanadinLeader";
saddr lbl_80500930[3];
saddr lbl_8050093C[3];
saddr lbl_80500948[3];
TObjEneMe1CanadinParams *lbl_80500954[3];
Vec lbl_80500960;

}

extern const s32 lbl_8043A180[3];
extern const s32 lbl_8043A18C[3];
extern const s32 lbl_8043A198[3];
extern const s32 lbl_8043A1A4[3];

// Motion setup passed to TLobby::spawn_npc_enemy: (motions, animation table, 0, 0x70000).

// Floor load: loads the Canadin archive, the per-difficulty stats and the breakup models, and spawns the
// two NPC copies.
void TObjEneMe1Canadin::load_resources() {
    s32 i;
    s32 model;
    s32 model2;
    void *p;

    lbl_80500960.x = 0.0f;
    lbl_80500960.y = 0.0f;
    lbl_80500960.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        bm_ene_me1_mb_resource = load_enemy_bml_resource_named(&bm_ene_me1_mb_resource_descriptor, "bm_ene_me1_mb_a.bml");
    } else {
        bm_ene_me1_mb_resource = load_enemy_bml_resource(&bm_ene_me1_mb_resource_descriptor);
    }
    for (i = 0; i < 3; i++) {
        lbl_80500930[i] = (saddr)TLobby::register_boss(lbl_8043A180[i]);
        lbl_8050093C[i] = (saddr)TLobby::dispatch_shared_handler_b(lbl_8043A18C[i]);
        lbl_80500948[i] = (saddr)TLobby::register_object(lbl_8043A198[i]);
        lbl_80500954[i] = (TObjEneMe1CanadinParams *)TLobby::dispatch_shared_handler_a(lbl_8043A1A4[i]);
    }
    TObjEneMe1Canadin__render_node_index = 0;
    p = new TUnk_8048FA00((saddr)bm_ene_me1_mb_resource->models[1].model);
    lbl_805D4FDC = (TUnk_8048FA00 *)p;
    p = new TUnk_8048FA00((saddr)bm_ene_me1_mb_resource->models[0].model);
    lbl_805D4FE0 = (TUnk_8048FA00 *)p;
    model = (saddr)bm_ene_me1_mb_resource->models[1].model;
    lbl_805D4FE4 = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, 3))->model)->polygon_list + 2);
    lbl_805D4FE8 = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, 2))->model)->polygon_list + 2);
    model2 = (saddr)bm_ene_me1_mb_resource->models[0].model;
    lbl_805D4FEC = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model2, 3))->model)->polygon_list + 2);
    lbl_805D4FF0 = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model2, 2))->model)->polygon_list + 2);
    TObjPlayer__sub_800F0928();
    s16 ids[2] = { 0x17, 0x18 };
    NpcAnimationBinding params = { reinterpret_cast<BmlMotionEntry *>(bm_ene_me1_mb_resource->motions), reinterpret_cast<TObjMotionAction *>(lbl_8048FF30), 0, 0, 7 };
    for (i = 0; i < 2; i++) {
        NpcModelRegistry::register_animated_chunk(ids[i], reinterpret_cast<void *>(bm_ene_me1_mb_resource->models[i].model), reinterpret_cast<void *>(bm_ene_me1_mb_resource->models[1].m_c), &params, 8.0f, 15.0f);
    }
}

void *TObjEneMe1Canadin::create(void *set_data) {
    return new TObjEneMe1Canadin(tl_04, set_data, 0);
}

TObjEneMe1Canadin *TObjEneMe1CanadinLeader::create_canadin(TObjEneMe1Canadin *leader, Vec *position, s32 id, s32 index) {
    return new TObjEneMe1Canadin(tl_04, leader, position, id, index);
}

// Floor teardown: frees the two breakup models and the Canadin archive.
void TObjEneMe1Canadin::free_resources() {
    if (lbl_805D4FE0 != NULL) {
        delete lbl_805D4FE0;
        lbl_805D4FE0 = NULL;
    }
    if (lbl_805D4FDC != NULL) {
        delete lbl_805D4FDC;
        lbl_805D4FDC = NULL;
    }
    if (bm_ene_me1_mb_resource != NULL) {
        delete bm_ene_me1_mb_resource;
        bm_ene_me1_mb_resource = NULL;
    }
}

TObjEneMe1Canadin::TObjEneMe1Canadin(TObject *parent, void *set_data, s32 kind) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Canadin__class_name;
    invoke_initialization_hook(set_data);
    m_3C8 = 0;
    update_by_field_0x354();
    m_3C0 = this;
    m_3C4 = kind;
    setup_enemy();
}

TObjEneMe1Canadin::TObjEneMe1Canadin(TObject *parent, TObjEneMe1Canadin *leader, Vec *pos, s32 id, s32 sub_id) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Canadin__class_name;
    m_3C0 = leader;
    init_common_from((u8 *)m_3C0);
    entity_id = id;
    set_index = sub_id;
    m_3C0->calc_move_vector(&position);
    VecCopy(&position, pos);
    rotation_y = m_3C0->rotation_y;
    m_3C8 = 0;
    m_3C4 = 1;
    setup_enemy();
}

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::setup_enemy() {
    s32 i;

    init_position_vectors();
    this->select_model();
    init_model(&lbl_8048FECC, 1);
    set_field_d8((saddr)lbl_8048FF30);
    set_field_dc((saddr)bm_ene_me1_mb_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp((u8 *)lbl_80500930[m_3C4], (u8 *)lbl_8050093C[m_3C4], (u8 *)lbl_80500948[m_3C4]);
    set_state_flag_4();
    movementParameters = &canadin_setup_param_block;
    initialize_enemy_state(0x1C);
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x2D);
    enemy_init_validate_period(0x2D);
    set_active();
    actorFlags |= 0x01000000;
    m_468 = lbl_80500954[m_3C4];
    fade.reset_color();
    m_3E8 = 45.0f;
    m_3EC = 15.0f;
    m_3F0 = 5.0f * (3.0517578e-05f * (f32)rand()) + 15.0f;
    m_3F4 = m_3EC;
    m_3F8 = position.y + m_3F4;
    m_3FC = 4;
    m_400 = 0;
    m_404 = 0;
    eff_light = new TObjEneMe1Canadin_EffLight(this, 5);
    m_40C = 0;
    m_410 = 0;
    for (i = 0; i < 7; i++) {
        VecCopy(&m_414[i], &position);
    }
    m_46C = 0;
    m_470 = 0;
    m_474 = 0;
    m_478 = 0;
    m_47C = 0;
    m_480 = 0;
    m_484 = 0.0f;
    m_488 = 0.0f;
    m_48C = 0.0f;
    m_490.x = 0.0f;
    m_490.y = 0.0f;
    m_490.z = 0.0f;
    m_49C = 0;
    unk_4A0 = 0;
    copy_argb(&m_4A4, (NJS_ARGB *)&TObjEneMe1Canadin__map_core_default_vec4);
    m_4A4.a = 0.0f;
    m_4B8 = 0;
    m_4B4 = 0;
    m_4BC = 0;
    m_4C0 = 0;
    m_4C4 = 0;
    copy_pos();
    set_part_position__9TObjEneDDFPvPvi(this, (saddr)bodies, 0);
    mode = 0;
    dispatch_action(mode, 4);
    if (m_3C0 != NULL) {
        m_4C8 = ((u16 (*)(void *))get_entity_id)(m_3C0);
    } else {
        m_4C8 = 0xFFFF;
    }
}
#pragma pop

TObjEneMe1Canadin::~TObjEneMe1Canadin() {
    if (unk_4A0 != NULL) {
        unk_4A0->queue_destruction();
        unk_4A0 = NULL;
    }
    eff_light->queue_destruction();
    eff_light = NULL;
    free_collision_body_parts(this);
}

void TObjEneMe1Canadin::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        update_if_ready();
        return;
    }
    if (m_3C4 == 1) {
        m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(m_4C8);
        if (m_3C0 == NULL || m_3C0->all_parents_unqueued_for_destruction() == 0) {
            queue_destruction();
            return;
        }
    }
    if (update_status_effects() != 4) {
        update_action_state();
        update_fade_sequence();
    }
    copy_pos();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneMe1Canadin::refresh_target() {  }

void TObjEneMe1Canadin::run_death_reaction() {
    s16 temp_r0;

    temp_r0 = mode;
    if ((temp_r0 != 0xD) && (temp_r0 != 0xB)) {
        transition_enemy_state(0xD);
    }
}

void TObjEneMe1Canadin::run_hit_reaction() { if (mode != 12) { transition_enemy_state(12); } }

void TObjEneMe1Canadin::run_miss_reaction() {  }

void TObjEneMe1Canadin::copy_pos() {
    body_center.x = (f32) position.x;
    body_center.y = (f32) m_3F8;
    body_center.z = (f32) position.z;
    VecCopy(&center, &body_center);
}

void TObjEneMe1Canadin::update_body_colliders() {
    m_3F4 = (f32) (m_3F8 - position.y);
    if (m_3F4 < 30.0f) {
        set_colliders_contact_low();
    } else {
        set_colliders_contact_high();
    }
    bodies->offset.y = m_3F4;
}

void TObjEneMe1Canadin::update_by_field_0x354() {
    if ((s32) floor_to_float(parameters[0]) == 0) {
        fn_8009E350();
        return;
    }
    fn_8009E334();
}

void TObjEneMe1Canadin::select_model() {
    model = (void *)bm_ene_me1_mb_resource->models[0].model;
    texlist = (saddr)bm_ene_me1_mb_resource->models[1].m_c;
}

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::calc_move_vector(Vec *out) {
    s32 angle;
    f32 x;
    f32 dist;

    angle = TObjEneDD::get_random_scaled();
    f32 ratio = random_ratio();
    dist = (30.0f * ratio) + 10.0f;
    x = dist * sin_table_lookup(angle);
    out->x = x;
    out->y = 0.0f;
    out->z = (f32) (dist * cos_table_lookup(angle));
    vec3_add_to(out, &position);
}
#pragma pop

u8 *TObjEneMe1Canadin::move_xz_on_ground(u8 *arg) {
    u8 *result = TObjEneDD::move_xz_on_ground(arg);
    if (result == NULL) {
        m_3C8 &= ~0x1000000;
    } else {
        m_3C8 |= 0x01000000;
    }
    return result;
}


extern "C" void TObjEneMe1Canadin__sub_8009EB98(TObjEneMe1Canadin *self, f32 height) {
    f32 temp_f3;
    temp_f3 = height - self->m_3F8;
    self->m_3C8 &= ~0x80000;
    if (temp_f3 >= 0.5f) {
        self->m_3F8 += 0.5f;
    } else if (temp_f3 <= -0.5f) {
        self->m_3F8 -= 0.5f;
    } else {
        self->m_3F8 = height;
        self->m_3C8 |= 0x80000;
    }
}

void TObjEneMe1Canadin::update_position_with_offset() {
    TObjEneMe1Canadin__sub_8009EB98(this, position.y + m_3E8);
}


extern "C" void TObjEneMe1Canadin__sub_8009EB14(TObjEneMe1Canadin *self, f32 height) {
    Vec pos;
    TObjEneMe1Canadin__sub_8009EB98(self, height);
    VecCopy(&pos, &self->position);
    pos.y = self->m_3F8;
    self->move_xz_on_ground((u8 *)&pos);
}

void TObjEneMe1Canadin::set_target_speed_z() {
    TObjEneMe1Canadin__sub_8009EB14(this, m_3EC + position.y);
}

void TObjEneMe1Canadin::update_hover_height() {
    TObjEneMe1Canadin__sub_8009EB14(this, m_3E8 + position.y);
}

void TObjEneMe1Canadin::update_angle() {
    rotation_y = approach_angle_limited(rotation_y, (s32) (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)), 0x400);
    rotation_y = (s32) (s16) rotation_y;
}

void TObjEneMe1Canadin::update_move() {
    if (enemy_has_live_target() != 0) {
        enemy_copy_target_destination();
        update_velocity();
        update_angle();
    }
}

void TObjEneMe1Canadin::select_next_attack_state() {
    if (m_3C8 & 0x100) {
        transition_enemy_state(7);
        return;
    }
    if (m_3C4 == 0) {
        if (m_46C < 2) {
            transition_enemy_state(6);
            m_46C += 1;
            return;
        }
        transition_enemy_state(7);
        m_46C = 0;
        return;
    }
    transition_enemy_state(6);
}

void TObjEneMe1Canadin::check_collisions() { TObjEneDD::check_collisions(); }


void TObjEneMe1Canadin::fn_8009E948() {
    bodies->flags |= 0x28;
}
void TObjEneMe1Canadin::fn_8009E930() {
    bodies->flags &= ~0x28;
}
s32 TObjEneMe1Canadin::fn_8009E860(f32 *out, f32 squared_range) {
    TObjEneMe1Canadin *self = this;
    TargetCandidate list[5];
    s32 found;
    s32 count;
    TObjChara *player;
    s32 i;
    found = 0;
    *out = -1.0f;
    count = collect_enemy_target_candidates(self, list, squared_range);
    for (i = 0; i < count; i++) {
        player = get_player_by_client_id(list[i].id);
        if (player != self->current_target) {
            self->m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(self->m_4C8);
            if (self->m_3C0->can_member_attack_target(player) != 0) {
                *out = newton_sqrtf(list[i].dist);
                found = 1;
                self->set_target_player(player);
                break;
            }
        }
    }
    return found;
}

s32 TObjEneMe1Canadin::check_target() {
    f32 sp8;
    s32 var_r31;

    var_r31 = 0;
    if (destination_distance < 70.0f) {
        var_r31 = 1;
        m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(m_4C8);
        if ((m_3C0->can_member_attack_target(current_target) == 0) && (fn_8009E860(&sp8, 22500.0f) != 0) && (sp8 > 70.0f)) {
            var_r31 = 0;
        }
    }
    return var_r31;
}

void TObjEneMe1Canadin::advance_state_4_to_5() {
    if (m_3FC == 4) {
        requested_action = 2;
        m_3FC = 5;
    }
}

void TObjEneMe1Canadin::advance_state_5_to_4() {
    TObjEneMe1Canadin *self = this;
    if (self->m_3FC == 5) {
        self->requested_action = 3;
        self->m_3FC = 4;
    }
}


s32 TObjEneMe1Canadin::fn_8009E76C() {
    return m_3F4 < 20.0f;
}

void TObjEneMe1Canadin::spawn_members() {  }

s32 TObjEneMe1Canadin::check_retreat_trigger() {
    s32 temp_r4;
    temp_r4 = m_3C8;
    if (temp_r4 & 0x20) {
        m_3C8 = (s32) (temp_r4 & 0xFFFFFFDF);
        transition_enemy_state(0xA);
        m_40C = 0;
        return 1;
    }
    if (temp_r4 & 0x40) {
        m_3C8 = (s32) (temp_r4 & 0xFFFFFFBF);
        transition_enemy_state(0xB);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Canadin::try_trigger_action() {
    if (current_target == NULL) {
        transition_enemy_state(0xE);
        return 1;
    }
    return 0;
}

void TObjEneMe1Canadin::noop() {}

s32 TObjEneMe1Canadin::acquire_target(f32) { return select_and_apply_target__12TObjEneDD_STFf(this); }

void TObjEneMe1Canadin::update_fade_sequence() {
    TObjEneMe1Canadin *p = this;
    switch (p->m_4B8) {
    case 0:
        break;
    case 1:
        if (p->m_4A4.a > 0.0f) {
            p->m_4A4.a = p->m_4A4.a - 0.06f;
        } else {
            p->m_4A4.a = 0.0f;
            p->m_4B8 = 0;
        }
        p->pack_color_rgba();
        break;
    case 2:
        if (p->m_4A4.a < 1.0f) {
            p->m_4A4.a += 0.06f;
        } else {
            p->m_4A4.a = 1.0f;
            p->m_4B8 = 0;
        }
        p->pack_color_rgba();
        break;
    case 3:
        p->m_4C0++;
        if ((f32)p->m_4C0 >= 2.0f) {
            p->m_4C0 = 0;
            switch (((s8 **)canadin_leader_fade_sequence_table)[p->m_4BC][p->m_4C4++]) {
            case 0x62:
                p->m_4A4.a = 0.0f;
                break;
            case 0x63:
                p->m_4B8 = 0;
                copy_argb(&p->m_4A4, (NJS_ARGB *)&canadin_formation_reset_vec4);
                break;
            case 0x61:
                p->m_4A4.a = 1.0f;
                break;
            }
            p->pack_color_rgba();
        }
        break;
    }
}


void TObjEneMe1Canadin::fn_8009E4AC(s32 sequence) {
    reset_map_core((NJS_ARGB *)&canadin_formation_fade_start_color);
    m_4B8 = 3;
    m_4BC = sequence;
    m_4C0 = 2;
    m_4C4 = 0;
}

void TObjEneMe1Canadin::reset_map_core(void *color) {
    copy_argb(&m_4A4, (NJS_ARGB *)color);
    pack_color_rgba();
}

void TObjEneMe1Canadin::pack_color_rgba() {
    m_4B4 = ((u8) __cvt_fp2unsigned(255.0f * m_4A4.g) << 24)
        | ((u8) __cvt_fp2unsigned(255.0f * m_4A4.b) << 16)
        | ((u8) __cvt_fp2unsigned(0.8f * (255.0f * m_4A4.a)) << 8)
        | (u8) __cvt_fp2unsigned(255.0f * m_4A4.r);
}

void TObjEneMe1Canadin::apply_model_color() {
    *lbl_805D4FEC = m_4B4;
    *lbl_805D4FF0 = m_4B4;
}

int TObjEneMe1Canadin::has_no_members() { return 1; }


void TObjEneMe1Canadin::fn_8009E378() {
    if (mode == 2) {
        m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(m_4C8);
        m_3C0->fn_8009E2DC();
    }
}
int TObjEneMe1Canadin::fn_8009E36C() { return (m_3C8 >> 15) & 0x1; }
void TObjEneMe1Canadin::fn_8009E350() {
    m_3C8 |= 0x100;
    m_3C8 &= ~0x200;
}
void TObjEneMe1Canadin::fn_8009E334() {
    m_3C8 |= 0x200;
    m_3C8 &= ~0x100;
}
s32 TObjEneMe1Canadin::fn_8009E31C(s32 mask) {
    return (m_3C8 & mask) != 0;
}
TObjChara *TObjEneMe1Canadin::fn_8009E300() {
    if (m_3C8 & 0x40000) {
        return current_target;
    }
    return NULL;
}

void TObjEneMe1Canadin::remove_member(uaddr) {  }

int TObjEneMe1Canadin::can_member_attack_target(TObjChara *) { return 1; }


void TObjEneMe1Canadin::fn_8009E2DC() {
    m_400 = 0;
    m_3C8 |= 1;
}

void TObjEneMe1Canadin::set_leader_index(TObjChara *target, s32 index) {
    set_target_player(target);
    m_400 = index;
    m_3C8 |= 1;
}

void TObjEneMe1Canadin::set_attack_flag() { m_3C8 |= 0x2; }


void TObjEneMe1Canadin::fn_8009E27C() { m_3C8 |= 0x4; }

void TObjEneMe1Canadin::set_flag3c8_bit8() { m_3C8 |= 0x8; }


void TObjEneMe1Canadin::fn_8009E258() {
    m_3C8 |= 0x100000 | 4;
}

void TObjEneMe1Canadin::set_flag3c8_bit20() { m_3C8 |= 0x20; }

void TObjEneMe1Canadin::set_flag3c8_bit40() { m_3C8 |= 0x40; }


void TObjEneMe1Canadin::fn_8009E1D4(Vec *pos) {
    CanadinBehaviorParams params = canadin_behavior_params;
    params.m_4 = m_468->m_4;
    TObjEneDD::setup(this, (saddr)pos, (saddr)&params);
}

void TObjEneMe1Canadin::dispatch_action(u32 which, s32 arg) {
    switch (which) {
    case 0:
        handle_state(arg);
        break;
    case 1:
        fn_8009DE90(arg);
        break;
    case 2:
        action(arg);
        break;
    case 3:
        vfunc_110(arg);
        break;
    case 4:
        vfunc_111(arg);
        break;
    case 5:
        move(arg);
        break;
    case 6:
        fn_8009D320(arg);
        break;
    case 7:
        fn_8009CC74(arg);
        break;
    case 8:
        fn_8009C91C(arg);
        break;
    case 9:
        run_task(arg);
        break;
    case 10:
        fn_8009C2EC(arg);
        break;
    case 11:
        fn_8009C178(arg);
        break;
    case 12:
        fn_8009C510(arg);
        break;
    case 13:
        state_dead(arg);
        break;
    case 14:
        fn_8009BFF8(arg);
        break;
    case 16:
        update_walk_animation(arg);
        break;
    case 17:
        update_by_state(arg);
        break;
    }
}

void TObjEneMe1Canadin::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0;
        set_field_378(2);
        this->set_intangible();
        m_3C8 |= 0x400000;
        m_3FC = 4;
        m_4B8 = 1;
        m_470 = 0;
        return;
    case 3:
        if (m_470 >= 4) {
            if (m_3C4 == 0) {
                m_3C8 |= 0x100000;
            }
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        m_470 += 1;
        if (m_470 == 2) {
            this->spawn_members();
        }
        m_3C8 &= ~0x1000000;
        break;
    }
}


void TObjEneMe1Canadin::fn_8009DE90(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        self->set_field_378(2);
        self->m_3C8 &= ~0x400000;
        self->set_intangible();
        self->actorFlags |= 0x01000000;
        self->m_3FC = 4;
        self->m_4B8 = 1;
        self->fade.start_fade_in();
        TBoss3Volopt__sub_800D8D88((saddr)&self->position);
        return;
    case 3:
        if (self->fade.advance_toward_max() != 0) {
            self->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        self->advance_animation();
        if (self->m_3C4 == 2) {
            TObjEneMe1Canadin__sub_8009EB14(self, 25.0f + self->position.y);
        } else {
            self->set_target_speed_z();
        }
        self->update_body_colliders();
        break;
    }
}

void TObjEneMe1Canadin::action(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        requested_action = 0;
        set_field_378(2);
        m_3C8 &= ~0x400000;
        this->set_intangible();
        actorFlags &= ~0x1000000;
        m_3FC = 4;
        m_4B8 = 1;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            temp_r3 = m_3C8;
            if (temp_r3 & 1) {
                m_3C8 = (s32) (temp_r3 & 0xFFFFFFFE);
                transition_enemy_state(3);
            } else if (enemy_has_live_target() != 0) {
                transition_enemy_state(3);
            }
        }
        break;
    case 0:
        advance_animation();
        if (m_3C4 != 1) {
            update_linked_position(200.0f);
        }
        if (m_3C4 == 2) {
            TObjEneMe1Canadin__sub_8009EB14(this, 25.0f + position.y);
        } else {
            set_target_speed_z();
        }
        this->check_collisions();
        break;
    case 5:
    case 1:
        break;
    }
}

void TObjEneMe1Canadin::vfunc_110(s32 arg1) {
    s32 temp_r3;
    f32 temp_f1;

    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(3);
        m_3C8 &= ~0x400000;
        this->clear_intangible();
        actorFlags &= ~0x1000000;
        {
            const f32 *p = (const f32 *)&canadin_formation_reset_vec4;
            m_4A4.r = p[1];
            m_4A4.g = p[2];
            m_4A4.b = p[3];
            pack_color_rgba();
        }
        m_470 = 0;
        return;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            temp_r3 = m_3C8;
            if (temp_r3 & 2) {
                m_3C8 = temp_r3 & ~2;
                if (m_3C4 == 1) {
                    transition_enemy_state(5);
                } else {
                    transition_enemy_state(4);
                }
            }
        }
    case 1:
        return;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        switch (m_470) {
        case 2:
            break;
        case 0:
            m_400 -= 1;
            if (m_400 <= 0) {
                m_4B8 = 2;
                m_470 = 1;
                play_sound_effect(0x4003B21A, &body_center, 0, 0);
            }
            break;
        case 1:
            if (m_4B8 == 0) {
                m_3C8 |= 0x8000;
                switch (m_3C4) {
                case 0:
                    this->set_attack_flag();
                case 1:
                    m_470 = 3;
                    break;
                }
            }
            update_move();
            break;
        case 3:
            update_move();
            break;
        }
        set_target_speed_z();
        this->check_collisions();
        return;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TObjEneMe1Canadin::vfunc_111(s32 arg1) {
    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(4);
        m_3C8 &= ~0x400000;
        this->clear_intangible();
        actorFlags |= 0x01000000;
        return;
    case 3:
        if (m_3C8 & 0x80000) {
            m_404 = 0;
            this->select_next_attack_state();
        }
        return;
    case 5:
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        update_move();
        this->update_hover_height();
        this->check_collisions();
        noop();
        break;
    }
}

void TObjEneMe1Canadin::move(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(5);
        m_3C8 &= ~0x400000;
        this->clear_intangible();
        actorFlags |= 0x01000000;
        m_470 = 0;
        return;
    case 3:
        if ((this->check_retreat_trigger() == 0) && (m_470 == 3)) {
            m_404 = 0;
            this->select_next_attack_state();
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        switch (m_470) {
        case 0:
            temp_r3 = m_3C8;
            if (temp_r3 & 4) {
                m_3C8 = (s32) (temp_r3 & 0xFFFFFFFB);
                if (fn_8009E31C(0x200) != 0) {
                    m_470 = 1;
                    fn_8009E4AC(1);
                } else {
                    m_470 = 2;
                    advance_state_4_to_5();
                    fn_8009E4AC(3);
                }
            }
            update_move();
            update_hover_height();
            break;
        case 1:
            if (m_4B8 == 0) {
                m_470 = 3;
            }
            update_move();
            update_hover_height();
            break;
        case 2:
            update_move();
            if (m_4B8 != 0) {
                update_hover_height();
            } else {
                TObjEneMe1Canadin__sub_8009EB14(this, position.y + m_3F0);
                if (m_3C8 & 0x80000) {
                    m_470 = 3;
                }
            }
            break;
        }
        this->check_collisions();
        noop();
        break;
    }
}


#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::fn_8009D320(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    Vec *pos;
    pos = &self->m_490;
    switch (arg1) {
    case 4:
        self->set_field_378(6);
        self->m_3C8 |= 0x10000;
        self->m_3C8 &= ~0x400000;
        self->clear_intangible();
        self->actorFlags |= 0x01000000;
        self->reset_map_core((void *)&canadin_formation_reset_vec4);
        self->m_470 = 1;
        self->m_474 = 0;
        self->m_49C = 0;
        self->unk_4A0 = 0;
        break;
    case 3:
        if (self->check_retreat_trigger() == 0 && self->try_trigger_action() == 0 && self->m_470 == 6) {
            if (self->m_3C8 & 0x100000) {
                self->transition_enemy_state(8);
            } else {
                self->transition_enemy_state(9);
            }
        }
        break;
    case 0:
        self->advance_animation();
        if (self->m_470 == 1) {
            if (self->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)self)->update_death_check() == 0) {
            break;
        }
        self->enemy_copy_target_destination();
        switch (self->m_470) {
        case 1:
            self->update_velocity();
            if (self->check_target() != 0) {
                self->m_470 = 2;
                self->m_3C8 |= 0x40000;
                self->advance_state_4_to_5();
            } else {
                self->advance_state_5_to_4();
            }
            TObjEneEpsilon__sub_800B92F8(self, 0x200, 0.5f);
            break;
        case 2:
            self->update_velocity();
            self->update_angle();
            if (self->requested_action == 1) {
                self->m_470 = 3;
                self->reset_map_core((void *)&TObjEneMe1Canadin__map_core_default_vec4);
                VecCopy(pos, &self->destination);
                self->m_49C = new TObjEneMe1Canadin_EffLine(self, self->m_414, pos);
                play_sound_effect(0x4002B71B, &self->body_center, 0, 0);
                play_sound_effect(0x4002B51E, &self->body_center, 0, 0);
            }
            break;
        case 3: {
            Vec v;
            self->update_velocity();
            self->update_angle();
            VecCopy(&v, &self->destination);
            subtract_vector(&v, pos);
            if (normalize_vector_xz(&v) < 0.6f) {
                VecCopy(pos, &self->destination);
            } else {
                pos->x = 0.6f * v.x + pos->x;
                pos->y = 0.6f * v.y + pos->y;
                pos->z = 0.6f * v.z + pos->z;
            }
            if (self->unk_4A0 == 0) {
                self->unk_4A0 = create_particle_emitter(self->m_414, 0xF7);
                if (self->unk_4A0 != 0) {
                    ((TParticleCtrl *)self->unk_4A0)->enable();
                }
            } else {
                ((TParticleCtrl *)self->unk_4A0)->set_position(self->m_414);
            }
            self->m_474++;
            if (self->m_474 > self->m_468->m_18) {
                self->m_470 = 4;
                self->m_474 = 0;
                self->m_49C->queue_destruction();
                self->m_49C = 0;
                if (self->unk_4A0 != 0) {
                    self->unk_4A0->queue_destruction();
                    self->unk_4A0 = 0;
                }
            }
            break;
        }
        case 4:
            self->m_474++;
            if (self->m_474 >= self->m_468->m_1C) {
                self->m_470 = 5;
                self->m_474 = 0;
                self->m_3C8 &= ~0x40000;
                self->reset_map_core((void *)&canadin_formation_reset_vec4);
                self->m_404++;
                new TObjEneMe1Canadin_EffDischarge(self, self->m_414, pos);
                play_sound_effect(0x4002A408, &self->body_center, 0, 0);
            }
            break;
        case 5:
            self->m_474++;
            if (self->m_474 > self->m_468->m_20) {
                self->m_474 = 0;
                if (self->m_404 >= self->m_468->m_24) {
                    self->m_470 = 6;
                } else {
                    self->m_470 = 1;
                }
            }
            break;
        }
        self->update_position_with_offset();
        self->check_collisions();
        self->noop();
        break;
    case 5:
        self->m_3C8 &= ~0x40000;
        self->reset_map_core((void *)&canadin_formation_reset_vec4);
        if (self->m_49C != 0) {
            self->m_49C->queue_destruction();
            self->m_49C = 0;
        }
        if (self->unk_4A0 != 0) {
            self->unk_4A0->queue_destruction();
            self->unk_4A0 = 0;
        }
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
#pragma optimization_level 3
void TObjEneMe1Canadin::fn_8009CC74(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->advance_state_4_to_5();
        self->set_field_378(7);
        self->m_3C8 &= ~0x400000;
        self->clear_intangible();
        self->actorFlags &= ~0x1000000;
        self->m_3C8 &= ~0x80000;
        self->m_470 = 0;
        self->m_474 = 40;
        self->m_478 = 0;
        self->m_484 = 0.0f;
        self->m_488 = 0.0f;
        break;
    case 3:
        if (self->check_retreat_trigger() == 0 && self->try_trigger_action() == 0 && self->m_470 == 4) {
            self->transition_enemy_state(8);
        }
        break;
    case 0:
        self->advance_animation();
        if (self->m_470 == 0) {
            if (self->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)self)->update_death_check() == 0) {
            break;
        }
        switch (self->m_470) {
        case 4:
            break;
        case 0: {
            f32 d;
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->update_angle();
            self->m_474++;
            if (self->m_474 > 40) {
                self->m_474 = 0;
                self->m_470 = 1;
                if (self->m_3C8 & 0x40000) {
                    if (self->destination_distance < 40.0f) {
                        self->m_470 = 2;
                        self->reset_map_core((void *)&TObjEneMe1Canadin__map_core_default_vec4);
                    }
                } else if (self->destination_distance < 100.0f) {
                    self->m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(self->m_4C8);
                    if (self->m_3C0->can_member_attack_target(self->current_target) != 0) {
                        self->m_3C8 |= 0x40000;
                    } else if (self->fn_8009E860(&d, 10000.0f) != 0) {
                        if (d < 100.0f) {
                            self->m_3C8 |= 0x40000;
                        }
                    } else {
                        self->m_470 = 4;
                    }
                }
            }
            TObjEneMe1Canadin__sub_8009EB14(self, self->position.y + self->m_3F4);
            break;
        }
        case 1:
            if (self->m_474 == 0) {
                f32 s, c, inv, len;
                self->enemy_copy_target_destination();
                self->update_velocity();
                len = 1800.0f;
                inv = 1.0f / newton_sqrtf(len);
                c = 30.0f * inv;
                s = 30.0f * inv;
                len *= inv;
                if (self->m_478 == 1) {
                    self->m_478 = 0;
                    s *= -1.0f;
                } else {
                    self->m_478 = 1;
                }
                {
                    f32 nx, nz;
                    nx = self->destination_direction.x * c + self->destination_direction.z * s;
                    nz = self->destination_direction.z * c - self->destination_direction.x * s;
                    self->destination_direction.x = nx;
                    self->destination_direction.z = nz;
                }
                self->m_484 = 0.25f * len;
                self->m_488 = 0.25f * (self->m_3EC - self->m_3F4);
                play_sound_effect(0x4003AD18, &self->body_center, 0, 0);
            }
            self->fn_8009E948();
            self->m_474++;
            if (self->m_474 >= 4) {
                self->m_474 = 0;
                self->m_470 = 0;
                self->fn_8009E930();
            }
            self->m_3F8 += self->m_488;
            self->move_to_wall_clamped_destination(self->destination_direction.x, self->destination_direction.z, self->m_484);
            TObjEneMe1Canadin::push_history_entry(self->eff_light, 1.2f, self->m_414, self->m_4B4);
            break;
        case 2:
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->update_angle();
            TObjEneMe1Canadin__sub_8009EB98(self, self->position.y + self->m_3EC);
            if (self->destination_distance < 18.0f) {
                if (self->fn_8009E76C() != 0) {
                    self->m_474 = 0;
                    self->m_470 = 3;
                }
            } else {
                if (self->destination_distance > 40.0f) {
                    self->m_470 = 1;
                }
                TObjEneEpsilon__sub_800B92AC(self, 0x200, self->m_468->m_0);
            }
            self->noop();
            break;
        case 3:
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->update_angle();
            self->m_474++;
            if (self->m_474 == 20) {
                Vec v;
                VecCopy(&v, &self->m_414[5]);
                vec3_add_to(&v, &self->m_414[6]);
                v.x *= 0.5f;
                v.y *= 0.5f;
                v.z *= 0.5f;
                create_timed_particle_emitter(&v, 0x113, 0, 0x14);
            } else if (self->m_474 == 25) {
                self->m_404++;
                if (self->fn_8009E76C() != 0 && self->current_target->select_melee_contact_body(self, 1.0f) != 0) {
                    self->current_target->receive_physical_attack(self, 1.0f);
                    self->current_target->apply_knockback_from_attacker((u8 *)self, 3.0f);
                    if ((s32)is_player_entity_id(get_entity_id(self->current_target)) != 0 && is_target_android(self->current_target) != 0 && self->random_ratio() < 0.05f) {
                        self->current_target->apply_shock_status();
                        self->current_target->vfunc_74(0);
                    }
                }
                play_sound_effect(0x4003B219, &self->body_center, 0, 0);
            } else if (self->m_474 > 50) {
                if (self->m_404 >= 3) {
                    self->m_470 = 4;
                } else {
                    self->m_474 = 0;
                    if (self->destination_distance < 13.0f) {
                        self->m_470 = 3;
                    } else if (self->destination_distance < 40.0f) {
                        self->m_470 = 2;
                    } else {
                        self->m_470 = 1;
                        self->reset_map_core((void *)&canadin_formation_reset_vec4);
                        if (self->destination_distance > 100.0f) {
                            self->m_3C8 &= ~0x40000;
                        }
                    }
                }
            }
            self->set_target_speed_z();
            break;
        }
        self->check_collisions();
        break;
    case 5:
        self->m_3C8 &= ~0x40000;
        self->reset_map_core((NJS_ARGB *)&canadin_formation_reset_vec4);
        self->fn_8009E930();
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::fn_8009C91C(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    Vec *dir = &self->m_490;
    switch (arg1) {
    case 4:
        self->advance_state_4_to_5();
        self->set_field_378(8);
        self->m_3C8 &= ~0x400000;
        self->clear_intangible();
        self->m_404 = 0;
        self->m_470 = 1;
        self->fn_8009E948();
        self->m_474 = 0;
        self->m_478 = 0;
        self->m_480 = 0;
        self->m_484 = 0.0f;
        self->m_488 = 0.0f;
        self->m_48C = 0.0f;
        dir->x = 0.0f;
        dir->y = 0.0f;
        dir->z = 0.0f;
        break;
    case 3:
        if (self->check_retreat_trigger() == 0 && self->try_trigger_action() == 0 && self->m_478 >= 4) {
            self->select_next_attack_state();
        }
        break;
    case 0:
        self->advance_animation();
        if (self->update_linked_position(200.0f) != 0) {
            switch (self->m_470) {
            case 1: {
                if (self->m_474 == 0) {
                    f32 t;
                    self->enemy_copy_target_destination();
                    self->update_velocity();
                    t = 8192.0f * ((TObjEneDD *)self)->calc_elapsed_scaled();
                    if (t >= 0.0f) {
                        t += 12288.0f;
                    } else {
                        t -= 12288.0f;
                    }
                    t *= 0.125f;
                    self->m_480 = t;
                    dir->x = -self->destination_direction.x;
                    dir->z = -self->destination_direction.z;
                    self->m_484 = 0.125f * (self->m_3E8 - self->m_3F4);
                    self->m_48C = 0.125f * (70.0f - self->destination_distance);
                    self->m_488 = self->destination_distance;
                }
                self->m_474++;
                if (self->m_474 >= 8) {
                    self->m_478++;
                    self->m_470 = 0;
                    self->fn_8009E930();
                }
                self->m_3F8 += self->m_484;
                rotate_xz_pair_by_angle(&dir->x, &dir->z, self->m_480);
                {
                    Vec v;
                    f32 c;
                    self->m_488 += self->m_48C;
                    v.x = dir->x * self->m_488 + self->destination.x;
                    v.z = dir->z * self->m_488 + self->destination.z;
                    subtract_vector(&v, &self->position);
                    c = normalize_vector_xz(&v);
                    self->move_to_wall_clamped_destination(v.x, v.z, c);
                }
                self->rotation_y = (s32)(10430.38043493439 * atan2_float(dir->x, dir->z)) + 0x8000;
                TObjEneMe1Canadin::push_history_entry(self->eff_light, 0.8f, self->m_414, self->m_4B4);
                break;
            }
            case 0:
                self->enemy_copy_target_destination();
                self->update_velocity();
                self->update_angle();
                self->update_hover_height();
                self->m_474++;
                if (self->m_474 > 30) {
                    self->m_474 = 0;
                    self->m_470 = 1;
                }
                break;
            }
            self->check_collisions();
        }
        break;
    case 5:
        self->fn_8009E930();
        break;
    }
}
#pragma pop

void TObjEneMe1Canadin::run_task(s32 arg1) {
    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(9);
        m_3C8 &= ~0x400000;
        set_intangible();
        actorFlags |= 0x01000000;
        if (m_3C4 == 1) {
            m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(m_4C8);
            m_3C0->set_flag3c8_bit8();
        }
        m_404 = 0;
        return;
    case 3:
        if ((check_retreat_trigger() == 0) && (destination_distance < 1.0f)) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        set_target_destination(&home_position);
        update_velocity();
        update_angle();
        update_position_with_offset();
        move_with_wall_slide_commit(destination_direction.x, destination_direction.z, 0.8f);
        update_body_colliders();
        noop();
        break;
    }
}


void TObjEneMe1Canadin::fn_8009C510(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    f32 t;
    Vec v;
    f32 f;
    switch (arg1) {
    case 4:
        self->requested_action = self->m_3FC;
        self->advance_animation();
        self->fn_8009E378();
        self->m_3C8 &= ~0x400000;
        self->clear_intangible();
        self->actorFlags &= ~0x1000000;
        self->m_470 = 0;
        if (self->m_3F8 > 5.0f + (self->position.y + self->m_3EC)) {
            self->m_474 = 0;
        } else {
            self->m_474 = 2;
        }
        self->m_488 = self->m_484 = 0.0f;
        break;
    case 3:
        if (self->m_474 == 3) {
            self->transition_enemy_state(self->next_mode);
        }
        break;
    case 0:
        self->advance_animation();
        VecCopy(&v, (const Vec *)&self->x_speed);
        f = normalize_vector_xz(&v);
        self->move_with_wall_slide_on_ground(v.x, v.z, f);
        f *= 0.5f;
        self->x_speed = v.x * f;
        self->m_310 = v.z * f;
        switch (self->m_474) {
        case 0:
            self->m_484 -= 0.13f;
            if (self->m_484 < -4.0f) {
                self->m_484 = -4.0f;
            }
            self->m_3F8 += self->m_484;
            if (self->m_3F8 < 12.0f + (self->position.y + self->m_3EC)) {
                self->m_474 = 1;
                if (self->m_484 > -2.0f) {
                    self->m_484 = -2.0f;
                }
                self->m_488 = self->m_484 * self->m_484 / 30.0f;
            }
            break;
        case 1:
            self->m_484 += self->m_488;
            self->m_3F8 += self->m_484;
            if (self->m_484 >= 0.0f) {
                if (self->m_3F8 > self->position.y + self->m_3EC) {
                    self->m_3F8 = self->position.y + self->m_3EC;
                    self->m_470 = 0;
                    self->m_474 = 2;
                }
            }
            break;
        case 2:
            self->m_470++;
            if (self->m_470 >= self->m_468->m_28) {
                self->m_474 = 3;
            }
            break;
        }
        self->check_collisions();
        break;
    case 5:
        ((TObjEneDD *)self)->clear_attack_receipts();
        if (self->m_3FC == 5) {
            self->requested_action = 1;
        } else {
            self->requested_action = 0;
        }
        break;
    }
}
void TObjEneMe1Canadin::fn_8009C2EC(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->advance_state_4_to_5();
        self->set_field_378(0xA);
        self->clear_intangible();
        self->m_3C8 &= ~0x400000;
        self->m_3C8 |= 0x200000;
        self->actorFlags |= 0x01000000;
        self->m_410 = -0x7F80;
        break;
    case 3:
        if (self->m_470 >= 0x96) {
            self->transition_enemy_state(0xD);
            self->hp = 0;
            self->actorFlags |= 0x800;
            play_sound_effect(0x4003AD1F, &self->body_center, 0, 0);
        }
        break;
    case 1:
        break;
    case 0: {
        self->advance_animation();
        if (self->update_linked_position(200.0f) != 0) {
            self->enemy_copy_target_destination();
        }
        self->update_velocity();
        TObjEneMe1Canadin__sub_8009EB98(self, self->position.y + self->m_3EC);
        TObjEneEpsilon__sub_800B92AC(self, 0x200, 0.68f);
        self->rotation_z += 0x2000;
        self->m_470++;
        if (self->m_470 >= 0x96) {
            CanadinBehaviorParams c = canadin_projectile_param_block;
            TObjEneMe1CanadinParams *t = self->m_468;
            c.m_4 = t->m_8;
            TObjEneDD__sub_800BA5A4(self, &c);
            self->m_3C8 |= 0x800000;
        }
        if (self->m_470 % 10 < 5) {
            self->m_410 = 0xFFFF0000;
        } else {
            self->m_410 = 0xFF000000;
        }
        play_persistent_sound(0x4003B71D, (saddr)self, (uaddr)&self->body_center, 0, 0);
        self->check_collisions();
        break;
    }
    case 5:
        self->rotation_z = 0;
        break;
    }
}
void TObjEneMe1Canadin::fn_8009C178(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        self->set_field_378(0xB);
        self->set_intangible();
        self->m_3C8 &= ~0x400000;
        self->actorFlags |= 0x800;
        if (self->m_3C4 == 1) {
            self->m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(self->m_4C8);
            self->m_3C0->remove_member((uaddr)self);
        } else {
            self->send_entity_set_flags();
        }
        create_timed_particle_emitter(&self->body_center, 0x117, 0, 0x19);
        create_timed_particle_emitter(&self->body_center, 0x118, 0x19, 0xF);
        self->fade.set_rate_from_divisor(0x19);
        self->fade.reset_color();
        play_sound_effect(0x4003AD18, &self->body_center, 0, 0);
        return;
    case 3:
        if ((self->fade.decay_value_toward_floor() != 0) && (self->has_no_members() != 0)) {
            self->queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}
void TObjEneMe1Canadin::fn_8009BFF8(s32 arg1) {
    TObjEneMe1Canadin *self = this;

    switch (arg1) {
    case 4:
        self->set_field_378(0xE);
        self->m_3C8 &= ~0x400000;
        self->clear_intangible();
        self->m_470 = 0;
        return;
    case 3:
        if (self->m_470 == 2) {
            self->select_next_attack_state();
        }
    case 5:
        return;
    case 0:
        self->advance_animation();
        if (self->update_linked_position(200.0f) != 0) {
            self->m_470 = 2;
        }
        switch (self->m_470) {
        case 0:
            self->m_474 += 1;
            if (self->m_474 >= 0x3C) {
                self->m_470 = 1;
                self->advance_state_5_to_4();
            }
            TObjEneMe1Canadin__sub_8009EB14(self, self->position.y + self->m_3F4);
            break;
        case 1:
            self->set_target_destination(&self->home_position);
            self->update_velocity();
            self->update_angle();
            self->update_position_with_offset();
            if (self->destination_distance > 2.0f) {
                self->move_with_wall_slide_commit(self->destination_direction.x, self->destination_direction.z, 0.8f);
            }
            break;
        }
        self->check_collisions();
        self->noop();
        break;
    }
}

void TObjEneMe1Canadin::state_dead(s32 arg1) {
    Vec pos;
    f32 temp_f1;
    switch (arg1) {
    case 4:
        if (m_3C4 == 1) {
            m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(m_4C8);
            m_3C0->remove_member((uaddr)this);
        }
        TBoss3Volopt::create_breakup_mdl((saddr)lbl_805D4FE0, 0, (s32)(texlist), (saddr)&body_center, (s32)(rotation_y));
        m_3C8 |= 0x400000;
        VecCopy(&pos, &body_center);
        temp_f1 = pos.y;
        pos.y = temp_f1 - 5.0f;
        trigger_dell_biter_events__10TObjPlayerFv(&pos, temp_f1);
        refresh_and_send_entity_flags();
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003AA1E, &body_center, 0, 0);
        return;
    case 0:
        queue_destruction();
    case 3:
    case 5:
        return;
    }
}

void TObjEneMe1Canadin::update_walk_animation(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0;
        m_470 = 0;
        return;
    case 0:
        advance_animation();
        m_470 += 1;
        if (m_470 > 0x5A) {
            m_470 = 0;
            requested_action = (requested_action + 1);
            if ((s16) requested_action >= 7) {
                requested_action = 0;
            }
        }
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Canadin::update_by_state(s32 arg1) {

    switch (arg1) {
    case 4:
        requested_action = 0;
        m_3F8 = (f32) (position.y + m_3EC);
        m_484 = sin_table_lookup(rotation_y);
        m_488 = cos_table_lookup(rotation_y);
        return;
    case 0:
        advance_animation();
        m_3F8 = (f32) (position.y + m_3EC);
        body_center.y = (f32) m_3F8;
        move_with_wall_slide_commit(m_484, m_488, 0.2f);
    case 3:
    case 5:
    case 1:
        return;
    }
}


void fn_8009BD00(NJS_OBJECT *) {
    Vec *temp_r4;
    Vec *pos;
    Vec *temp_r5;
    Vec *temp_r5_2;
    switch (TObjEneMe1Canadin__render_node_index) {
    case 2:
    case 3:
        push_matrix();
        forward_split_screen_view_matrix();
        temp_r5 = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = temp_r5 + 1;
        matrix_mult_vec(0, &lbl_80500960, temp_r5);
        temp_r4 = TObjEneMe1Canadin__render_point_cursor;
        temp_r5_2 = temp_r4;
        TObjEneMe1Canadin__render_point_cursor = temp_r4 + 1;
        rotate_vector_by_matrix(0, temp_r4, temp_r5_2);
        pop_matrix();
        break;
    case 6:
    case 11:
    case 14:
        pos = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = pos + 1;
        forward_transform_to_view(&lbl_80500960, pos);
        break;
    }
    TObjEneMe1Canadin__render_node_index += 1;
}

void TObjEneMe1Canadin::render() {
    s16 temp_r0;
    s16 temp_r0_2;
    s32 var_r30;
    s32 var_r29;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_canadin_model_with_debug_type();
        return;
    }
    if (m_3C8 & 0x400000) {
        var_r30 = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        var_r30 = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        var_r30 = 1;
    } else {
        var_r30 = 0;
    }
    if (var_r30 != 0) {
        if (m_3C8 & 0x01000000) {
            draw_ground_shadow(0, 0);
        }
        update_secondary_light();
        TObjFish::set_global_param(texlist);
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        apply_model_color();
        push_matrix();
        post_translate_matrix(&position);
        translate_matrix(0, 0.0f, m_3F4, 0.0f);
        rotate_matrix_y(0, rotation_y);
        temp_r0 = mode;
        var_r29 = 1;
        if ((temp_r0 == 1) || (temp_r0 == 0xB)) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                var_r29 = 0;
            }
        }
        if (var_r29 != 0) {
            if ((s16) mode != 0xA) {
                TObjEneMe1Canadin__render_node_index = 0;
                TObjEneMe1Canadin__render_point_cursor = m_414;
                VecCopy(&m_414[3], &lbl_8043A268);
                VecCopy(&m_414[1], &lbl_8043A274);
                set_chunk_model_node_callback(fn_8009BD00);
                if (var_r30 == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                set_chunk_model_node_callback(NULL);
            } else {
                rotate_matrix_z(NULL, rotation_z);
                TObjEneMe1Canadin__render_node_index = -1;
                TObjEneMe1Canadin__render_point_cursor = m_414;
                VecCopy(&m_414[3], &lbl_8043A268);
                VecCopy(&m_414[1], &lbl_8043A274);
                set_chunk_model_node_callback(fn_8009BD00);
                this->draw_with_alt_model(m_410);
                set_chunk_model_node_callback(NULL);
            }
        }
        temp_r0_2 = mode;
        if ((temp_r0_2 == 1) || (temp_r0_2 == 0xB)) {
            fade.clear_flag_and_notify();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        return;
    }
    VecCopy(&m_414[3], &lbl_8043A268);
    VecCopy(&m_414[1], &lbl_8043A274);
    VecCopy(&m_414[2], &body_center);
    VecCopy(&m_414[0], &body_center);
    VecCopy(&m_414[4], &body_center);
    VecCopy(&m_414[5], &body_center);
    VecCopy(&m_414[6], &body_center);
}

void TObjEneMe1Canadin::update_if_ready() { if (get_target_info() != 0) { this->update_by_field_0x354(); } }

#pragma pool_data off
void TObjEneMe1Canadin::render_canadin_model_with_debug_type() {
    s32 temp_r3;
    if (((s32)get_target_info() != 0) && (m_3C4 == 0)) {
        temp_r3 = m_3C8;
        if (temp_r3 & 0x100) {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:IN FIGHTER");
        } else if (temp_r3 & 0x200) {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:OUT FIGHTER");
        } else {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:UNKOWN");
        }
    }
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjEneDD::clear_global_flag_400();
        draw_chunk_object((void *)model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
#pragma pool_data reset

void *TObjEneMe1CanadinLeader::create(void *set_data) {
    return new TObjEneMe1CanadinLeader(tl_04, set_data);
}

TObjEneMe1CanadinLeader::TObjEneMe1CanadinLeader(TObject *parent, void *set_data) : TObjEneMe1Canadin(parent, set_data, 2) {
    s32 i;

    m_name = TObjEneMe1CanadinLeader__class_name;
    select_model();
    m_3E8 += 10.0f;
    m_4CC = 8;
    m_4D0 = 0;
    for (i = 0; i < 8; i++) {
        m_4D4[i] = 0;
    }
    m_4F4 = 0;
    initialize_enemy_state(0x1D);
}

TObjEneMe1CanadinLeader::~TObjEneMe1CanadinLeader() {
}

void TObjEneMe1CanadinLeader::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        update_if_ready();
        return;
    }
    if (update_status_effects() != 4) {
        update_action_state();
        update_fade_sequence();
        update_formation_state();
    }
    copy_pos();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneMe1CanadinLeader::select_model() {
    model = (void *)bm_ene_me1_mb_resource->models[1].model;
    texlist = (saddr)bm_ene_me1_mb_resource->models[1].m_c;
}

void TObjEneMe1CanadinLeader::select_next_attack_state() {
    switch (m_46C) {
    case 0:
    case 1:
        m_46C++;
        transition_enemy_state(6);
        break;
    case 2:
        m_46C = 0;
        transition_enemy_state(7);
        break;
    }
}

void TObjEneMe1CanadinLeader::spawn_members() {
    saddr id;
    saddr sub;
    s32 angle;
    s32 n;
    s32 i;
    s32 j;
    Vec v;
    n = (s32)ceil_to_float((f32)m_4CC / (f32)m_468->m_2C);
    if (n < 1) {
        n = 1;
    }
    angle = rotation_y;
    id = (entity_id + 1) & 0xFFFF;
    sub = set_index + 1;
    for (i = 0; i < n; i++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &position);
        angle += 0x10000 / m_4CC;
        m_4D4[i] = create_canadin(this, &v, id++, sub++);
        m_4D4[i]->fn_8009E334();
        m_4D0++;
    }
    for (j = n; j < m_4CC; j++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &position);
        angle += 0x10000 / m_4CC;
        m_4D4[j] = create_canadin(this, &v, id++, sub++);
        m_4D4[j]->fn_8009E350();
        m_4D0++;
    }
}

s32 TObjEneMe1CanadinLeader::check_retreat_trigger() {
    s32 i;
    if (m_3C8 & 0x40) {
        m_3C8 &= ~0x40;
        transition_enemy_state(0xb);
        for (i = 0; i < m_4D0; i++) {
            m_4D4[i]->set_flag3c8_bit40();
        }
        return 1;
    }
    return 0;
}

void TObjEneMe1CanadinLeader::remove_member(uaddr id) {
    TObjEneMe1Canadin *member = (TObjEneMe1Canadin *)id;
    s32 i;
    for (i = 0; i < m_4D0; i++) {
        if (m_4D4[i] == member) {
            m_4D0--;
            TObjEneMe1Canadin *t = m_4D4[m_4D0];
            m_4D4[m_4D0] = member;
            m_4D4[i] = t;
            break;
        }
    }
    if (m_4F4 == 3) {
        s32 k = ceil_to_float((f32)m_4CC / (f32)m_468->m_2C);
        if (m_4D0 <= m_4CC - k) {
            m_3C0 = (TObjEneMe1Canadin *)find_entity_by_id(m_4C8);
            m_3C0->set_flag3c8_bit8();
        }
    }
    if (!(m_3C8 & 0x100000) && m_4D0 <= m_4CC / 2) {
        m_3C8 |= 0x10;
    }
    if (m_4D0 <= 2) {
        m_3C8 |= 0x40;
    }
}

int TObjEneMe1CanadinLeader::can_member_attack_target(TObjChara *) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < m_4D0; i++) {
        if (m_4D4[i]->fn_8009E300() == current_target) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

void TObjEneMe1CanadinLeader::apply_model_color() {
    *lbl_805D4FE4 = m_4B4;
    *lbl_805D4FE8 = m_4B4;
}

int TObjEneMe1CanadinLeader::has_no_members() {
    return (u8) (m_4D0 <= 0);
}

void TObjEneMe1CanadinLeader::update_formation_state() {
    TObjEneMe1CanadinLeader *self = this;
    s32 i;
    s32 j;
    if (self->m_3C8 & 0x10) {
        self->m_3C8 &= ~0x10;
        self->m_4F4 = 7;
    }
    switch (self->m_4F4) {
    case 1:
        self->fn_8009E4AC(0);
        self->m_4F4 = 2;
        play_sound_effect(0x4003AD1B, &self->body_center, 0, 0);
        break;
    case 2:
        if (self->m_4B8 == 0) {
            self->m_4F4 = 3;
            self->m_3C8 &= ~8;
            copy_argb(&self->m_4A4, (NJS_ARGB *)&canadin_formation_reset_vec4);
            for (i = 0; i < self->m_4D0; i++) {
                if (self->m_4D4[i]->fn_8009E31C(0x200) != 0) {
                    self->m_4D4[i]->fn_8009E27C();
                }
            }
        }
        break;
    case 3:
        if (self->m_3C8 & 8) {
            self->m_4F4 = 4;
        }
        break;
    case 4:
        self->fn_8009E4AC(2);
        self->m_4F4 = 5;
        play_sound_effect(0x4003AD1C, &self->body_center, 0, 0);
        break;
    case 5:
        if (self->m_4B8 == 0) {
            copy_argb(&self->m_4A4, (NJS_ARGB *)&canadin_formation_reset_vec4);
            self->m_4F4 = 6;
            for (i = 0; i < self->m_4D0; i++) {
                if (self->m_4D4[i]->fn_8009E31C(0x100) != 0) {
                    self->m_4D4[i]->fn_8009E27C();
                }
            }
        }
        break;
    case 6:
        break;
    case 7:
        self->fn_8009E4AC(4);
        self->m_4F4 = 8;
        play_sound_effect(0x4003AD1B, &self->body_center, 0, 0);
        break;
    case 8:
        if (self->m_4B8 == 0) {
            self->m_4F4 = 9;
            copy_argb(&self->m_4A4, (NJS_ARGB *)&canadin_formation_reset_vec4);
            for (j = 0; j < self->m_4D0; j++) {
                self->m_4D4[j]->fn_8009E258();
            }
            self->fn_8009E258();
        }
        break;
    case 0:
    case 9:
        break;
    }
}

void TObjEneMe1CanadinLeader::vfunc_110(s32 arg1) {
    s32 k;
    s32 i;
    s32 j;

    switch (arg1) {
    case 4: {
        advance_state_5_to_4();
        set_field_378(3);
        clear_intangible();
        const f32 *p = (const f32 *)&canadin_formation_reset_vec4;
        m_4A4.r = p[1];
        m_4A4.g = p[2];
        m_4A4.b = p[3];
        m_470 = 0;
        for (k = 2, i = 0; i < m_4D0; k += 2, i++) {
            m_4D4[i]->set_leader_index(current_target, k);
        }
        break;
    }
    case 3:
        if (m_3C8 & 2) {
            m_3C8 &= ~2;
            m_4F4 = 1;
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        switch (m_470) {
        case 0:
            m_400--;
            if (m_400 <= 0) {
                m_4B8 = 2;
                m_470 = 1;
                play_sound_effect(0x4003B21A, &body_center, 0, 0);
            }
            break;
        case 1:
            if (m_4B8 == 0) {
                m_3C8 |= 0x8000;
                for (j = 0; j < m_4D0; j++) {
                    if (m_4D4[j]->fn_8009E36C() == 0) {
                        break;
                    }
                }
                if (j == m_4D0) {
                    set_attack_flag();
                    s32 m;
                    for (m = 0; m < m_4D0; m++) {
                        m_4D4[m]->set_attack_flag();
                    }
                }
            }
            update_move();
            break;
        }
        TObjEneMe1Canadin__sub_8009EB14(this, 25.0f + position.y);
        check_collisions();
        break;
    case 5:
        clear_invulnerable();
        break;
    }
}

void TObjEneMe1CanadinLeader::vfunc_111(s32 mode) {
    switch (mode) {
    case 4:
        advance_state_5_to_4();
        set_field_378(4);
        clear_intangible();
        break;
    case 3:
        if (m_3C8 & 4) {
            select_next_attack_state();
        }
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        update_move();
        update_hover_height();
        check_collisions();
        break;
    case 5:
        break;
    }
}

void TObjEneMe1CanadinLeader::state_dead(s32 mode) {
    s32 i;
    switch (mode) {
    case 4:
        TBoss3Volopt::create_breakup_mdl((saddr)lbl_805D4FDC, 0, (s32)texlist, (saddr)&body_center, (s32)rotation_y);
        for (i = 0; i < m_4D0; i++) {
            m_4D4[i]->set_flag3c8_bit20();
        }
        m_3C8 |= 0x400000;
        play_sound_effect(0x4003B71D, &body_center, 0, 0);
        ((TObjPlayer *)this)->refresh_lobby_state();
        break;
    case 0:
        if (has_no_members() != 0) {
            send_entity_set_flags();
            queue_destruction();
        }
        break;
    case 5:
        actorFlags &= ~0x200;
        break;
    case 1:
        return;
    case 3:
        return;
    }
}
