#include "pso/enemy/EnemyMovement.h"
#include "pso/system/BmlAccessors.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"

#include "pso/effect/enemy/TEneEffHamon.h"

#include "pso/render/ChunkMaterialState.h"

#include "types.h"

#include "pso/enemy/TUnk_804909C4.h"

#include "pso/render/NinjaUtil.h"

#include "pso/object/base/TObjChara.h"

#include "pso/enemy/darkgunner/TObjEneDarkGunCenter.h"

#include "pso/player/TObjPlayer.h"

#include "pso/enemy/TObjEnemyCustom.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/darkgunner/TObjEneDarkGunner.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/system/SoundEffect.h"

#include "pso/math/MatrixTransforms.h"

#include "pso/math/AngleLookup.h"

#include <stdlib.h>


#include "pso/render/render_util.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/effect/particle/TParticleCtrl_800874F4.h"

#include "pso/map/CsnQuery.h"

#include "pso/system/task/TObject.h"


#include "pso/system/vector.h"

#include "pso/render/TUnk_80490470.h"

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/enemy/lappy/TObjEneLappy.h"

#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/unk/TLobby.h"

#include "pso/ui/hud/TNowLoading.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"

#include "pso/system/TLanguage_801E4874.h"

#include "pso/enemy/saver/SaverLifecycle.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/render/MaterialColorFade.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/enemy/TeneFakeTecThunderEff.h"
#include "pso/object/TObjControl.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/system/MatrixOps.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

extern "C" {

}

extern "C" {

typedef struct XZ_800A1814 {
    f32 x, z;
} XZ_800A1814;

typedef struct Ofs_800A1814 {
    XZ_800A1814 v[4];
} Ofs_800A1814;

struct Raw_800A10A0 { u8 b[12]; };
















}


extern "C" {
saddr TObjEneDarkGunner__base_params_by_variant[1];

saddr TObjEneDarkGunner__attack_params_by_variant[1];

saddr TObjEneDarkGunner__resistance_params_by_variant[1];




void *bm_ene_darkgunner_model_names[5] = {
    (void *)"re5_b_cly_cy_line.nj", (void *)"re5_b_gunner_body.nj", (void *)"re5_b_rcly_cy_line.nj", (void *)"shockwave.nj",
    (void *)0x0,
};

void *bm_ene_darkgunner_motion_names[15] = {
    (void *)"attack_re5_b_body.njm", (void *)"await_re5_b_body.njm", (void *)"damage2_re5_b_body.njm", (void *)"damage_re5_b_body.njm",
    (void *)"die_re5_b_body.njm", (void *)"drop_re5_b_body.njm", (void *)"duckdame_re5_b_body.njm", (void *)"duckdie_re5_b_body.njm",
    (void *)"duckroop_re5_b_body.njm", (void *)"duckwake_re5_b_body.njm", (void *)"duck_re5_b_body.njm", (void *)"move_re5_b_body.njm",
    (void *)"pullback_re5_b_body.njm", (void *)"wait_re5_b_body.njm", (void *)0x0,
};

void *bm_ene_darkgunner_resource_descriptor[4] = {
    (void *)"bm_ene_darkgunner.bml", (void *)&bm_ene_darkgunner_model_names, (void *)&bm_ene_darkgunner_motion_names, (void *)0x4000e,
};

void *dark_gunner_action_table[56] = {
    (void *)0x10000, (void *)0xd, (void *)0x3f800000, (void *)0x0,
    (void *)0x20000, (void *)0xb, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x20000, (void *)0x5, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20004, (void *)0x0, (void *)0x3f4ccccd, (void *)0x4,
    (void *)0x10004, (void *)0x1, (void *)0x3f800000, (void *)0x4,
    (void *)0x20000, (void *)0x3, (void *)0x3f333333, (void *)0x8,
    (void *)0x20000, (void *)0x2, (void *)0x3f333333, (void *)0x8,
    (void *)0x30007, (void *)0x4, (void *)0x3f333333, (void *)0x10,
    (void *)0x2000b, (void *)0xa, (void *)0x3f333333, (void *)0x0,
    (void *)0x2000c, (void *)0x6, (void *)0x3f19999a, (void *)0x8,
    (void *)0x3000a, (void *)0x7, (void *)0x3f000000, (void *)0x10,
    (void *)0x1000b, (void *)0x8, (void *)0x3f333333, (void *)0x0,
    (void *)0x20000, (void *)0x9, (void *)0x3f19999a, (void *)0x0,
    (void *)0x20000, (void *)0xc, (void *)0x3f333333, (void *)0x4,
};

const char *TObjEneDarkGunner__class_name = "TObjEneDarkGunner";

struct MaterialColor {
    u32 argb;
    f32 r;
    f32 g;
    f32 b;
};

const NpcAnimationBinding dark_gunner_attack_binding_desc = { NULL, reinterpret_cast<TObjMotionAction *>(dark_gunner_action_table), 0, 1, 14 };

const MaterialColor lbl_8043A668 = {0, 0.0f, 0.0f, 0.0f};

const Vec dark_gunner_shadow_scale = {1.5f, 1.5f, 1.5f};

const Ofs_800A1814 hamon_effect_offset_table = {{{-7.0f, -7.0f}, {-7.0f, 7.0f}, {7.0f, -7.0f}, {7.0f, 7.0f}}};

const Vec lbl_8043A6A4 = {0.0f, 0.0f, 0.0f};

void *dark_gunner_movement_params[14] = {
    (void *)0x42a00000, (void *)0x3e8e38e3, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0, (void *)0x42a00000,
    (void *)0x3e8e38e3, (void *)0x400, (void *)0x1e0000, (void *)0x0,
    (void *)0x1, (void *)0x0,
};

CollisionBody dark_gunner_collision_bodies[1] = {
    {{0.0f, 3.5f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

void *dark_gunner_constant_material[4] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};

Vec dark_gunner_child_local_offsets[4] = {
    {0.0f, 10.0f, 2.0f}, {0.0f, 10.0f, -2.0f}, {2.0f, 10.0f, 0.0f}, {-2.0f, 10.0f, 0.0f},
};

TObjEneDarkGunnerBehaviorParams *TObjEneDarkGunner__behavior_params;

extern f32 player_scale_factor;

extern BmlResource *TObjEneDarkGunner__bml_resource;

extern uaddr TObjEneDarkGunner__effect_resource;

extern s32 TObjEneDarkGunner__cly_line_texlist;

extern s32 TObjEneDarkGunner__rcly_line_texlist;

extern NJS_OBJECT *TObjEneDarkGunner__shadow_chunk_object;

}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {
extern int fold_flush_0;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants off
extern "C" {
extern int fold_flush_1;
}

#pragma pop
extern "C" {



extern s32 TObjEneDarkGunner__polygon_update_tick;

extern s16 *TObjEneDarkGunner__body_child_polygons;

extern s16 *TObjEneDarkGunner__cly_line_polygons;

}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
inline f32 fmax_800A2390(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}

inline f32 fmin_800A28A4(f32 a, f32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

inline f32 fmax_800A28A4(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}
}

#pragma pop
extern "C" {


void load_darkgunner_effect_resources();

f32 player_scale_factor;

BmlResource *TObjEneDarkGunner__bml_resource; // bm_ene_darkgunner.bml

uaddr TObjEneDarkGunner__effect_resource;

s32 TObjEneDarkGunner__cly_line_texlist;

s32 TObjEneDarkGunner__rcly_line_texlist;

NJS_OBJECT *TObjEneDarkGunner__shadow_chunk_object;

s32 TObjEneDarkGunner__polygon_update_tick;

s16 *TObjEneDarkGunner__body_child_polygons;

s16 *TObjEneDarkGunner__cly_line_polygons;

void TeneFakeTecThunderEff::set_cancel_flag() { m_340 = 1; }

void TeneFakeTecThunderEff::clear_counter() { m_340 = 0; }

void TObjEneDarkGunner::set_fields_24_34_from_global(void *a1) {
    this->model = get_bml_model(TObjEneDarkGunner__bml_resource, (s32)(saddr)a1);
    this->texlist = (saddr)get_bml_texlist(TObjEneDarkGunner__bml_resource, (s32)(saddr)a1);
}

int TObjEneDarkGunner::is_flag_set_388_bit26() { return (m_388 >> 26) & 0x1; }

s32 TObjEneDarkGunner::sub_800A3210(s32 index) {
    return TObjEneDarkGunner__behavior_params->int_params[index];
}

f32 TObjEneDarkGunner::sub_800A3200(s32 index) {
    return TObjEneDarkGunner__behavior_params->float_params[index];
}

void TObjEneDarkGunner::run_move_action() {  }

void TObjEneDarkGunner::run_idle_action() {  }

void TObjEneDarkGunner::refresh_target() {  }
}

extern "C" {
TObjEneDarkGunner::TObjEneDarkGunner(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    s32 i;

    m_name = TObjEneDarkGunner__class_name;
    apply_set_data(set_data);
    initialize_enemy_photon_effect(this);
    variant = 0;
    set_param(0x22);
    add_flags_2e4(8);
    state36C = *(s16 *)((u8 *)set_data + 0x3E);
    resetTimer = 0xF;
    timer = resetTimer;
    VecCopy(&prev_position, &position);
    VecCopy(&home_position, &position);
    VecCopy(&move_origin, &position);
    VecCopy(&move_destination, &position);
    set_fields_24_34_from_global((void *)1);
    motion_list = TObjEneDarkGunner__bml_resource->motions;
    action_table = (TObjMotionAction *)dark_gunner_action_table;
    set_field_d8((saddr)action_table);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    init_collision_body_parts(this, dark_gunner_collision_bodies, 1);
    movementParameters = dark_gunner_movement_params;
    bind_enemy_combat_stats((u8 *)TObjEneDarkGunner__base_params_by_variant[variant], (u8 *)TObjEneDarkGunner__attack_params_by_variant[variant], (u8 *)TObjEneDarkGunner__resistance_params_by_variant[variant]);
    init_scale_global();
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    m_388 = 0x550000;
    obj_setFlags30(this, 0x04040000);
    rotation_z = 0x8000;
    render_y_offset = 0.0f;
    hover_speed = 0.0f;
    hover_height = 0.0f;
    trail_emitter = NULL;
    glow_emitter = NULL;
    bodies->flags |= 4;
    bodies->flags &= ~2;
    pad_39e = 0;
    for (i = 0; i < 4; i++) {
        children[i] = NULL;
    }
    {
        NpcAnimationBinding atk = dark_gunner_attack_binding_desc;
        atk.motions = TObjEneDarkGunner__bml_resource->motions;
        NpcModelRegistry::register_animated_chunk(0x19, reinterpret_cast<void *>(TObjEneDarkGunner__bml_resource->models[1].model), reinterpret_cast<void *>(TObjEneDarkGunner__bml_resource->models[1].m_c), &atk, 10.0f, 0.0f);
    }
}
}

extern "C" {
TObjEneDarkGunner::~TObjEneDarkGunner() {
    s32 i;
    free_collision_body_parts(this);
    for (i = 0; i < 4; i++) {
        if (children[i] != NULL) {
            children[i]->queue_destruction();
        }
    }
    if (trail_emitter != NULL) {
        ((TObject *)trail_emitter)->queue_destruction();
    }
    if (glow_emitter != NULL) {
        ((TObject *)glow_emitter)->queue_destruction();
    }
}

void load_darkgunner_effect_resources() {
    s32 i;
    BmlResource *res = new BmlResource(1, (BmlResourceDescriptor *)bm_ene_darkgunner_resource_descriptor, 0, 0, NULL);
    TObjEneDarkGunner__bml_resource = res;
    TObjEneDarkGunner__shadow_chunk_object = get_bml_model(TObjEneDarkGunner__bml_resource, 0);
    TObjEneDarkGunner__cly_line_texlist = (saddr)get_bml_texlist(TObjEneDarkGunner__bml_resource, 0);
    TObjEneDarkGunner__rcly_line_texlist = (saddr)get_bml_texlist(TObjEneDarkGunner__bml_resource, 2);
    TObjEneDarkGunner__body_child_polygons = ((NJS_CNK_MODEL *)get_bml_model(TObjEneDarkGunner__bml_resource, 1)->child->model)->polygon_list;
    TObjEneDarkGunner__cly_line_polygons = ((NJS_CNK_MODEL *)get_bml_model(TObjEneDarkGunner__bml_resource, 0)->model)->polygon_list;
    TObjPlayer__sub_800A4294();
    TEneEffHamon::init_fish_effects();
    TObjEneDarkGunner__effect_resource = (uaddr)load_gvm_texture_file((saddr)"re5_b_gunner_body_pika.gvm");
    for (i = 0; i < 1; i++) {
        TObjEneDarkGunner__base_params_by_variant[i] = (saddr)TLobby::register_boss(30 + i);
        TObjEneDarkGunner__attack_params_by_variant[i] = (saddr)TLobby::dispatch_shared_handler_b(30 + i);
        TObjEneDarkGunner__resistance_params_by_variant[i] = (saddr)TLobby::register_object(30 + i);
    }
    TObjEneDarkGunner__behavior_params = (TObjEneDarkGunnerBehaviorParams *)TLobby::dispatch_shared_handler_a(30);
}

void TObjEneDarkGunner::cleanup_effects() {
    if (TObjEneDarkGunner__bml_resource != NULL) {
        delete TObjEneDarkGunner__bml_resource;
        TObjEneDarkGunner__bml_resource = NULL;
    }
    if ((u32) TObjEneDarkGunner__effect_resource != 0U) {
        TObjPlayer::free_if_valid((s32)TObjEneDarkGunner__effect_resource);
        TObjEneDarkGunner__effect_resource = 0U;
    }
    TObjPlayer::reset_effect_count();
    TEneEffHamon__sub_800A380C();
}

void *TObjEneDarkGunner::create(void *set_data) {
    return new TObjEneDarkGunner(tl_04, set_data);
}
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
void TObjEneDarkGunner::run_task() {
    if (TObjEneDarkGunner__polygon_update_tick != actor_frame_tick) {
        TObjEneDarkGunner__polygon_update_tick = actor_frame_tick;
        TObjPlayer__sub_8023DEE0(TObjEneDarkGunner__body_child_polygons, 8, 0, 1);
        TObjPlayer__sub_8023DEE0(TObjEneDarkGunner__cly_line_polygons, 8, 0, 0);
    }
    if (TObjPlayer::check_demo_mode() == 1) {
        init_scale_global();
        sub_800A1974();
        return;
    }
    update_flag30_timer();
    if (has_flag_0x800() != 0) {
        run_death_reaction();
    } else if (test_flag30_512() != 0) {
        run_hit_reaction();
    } else if (obj_testFlags30(0x100) != 0) {
        run_miss_reaction();
    }
    update_attack_stat_status();
    update_defense_stat_status();
    if ((m_388 & 0x400000) && obj_testFlags30(0x22) == 0) {
        s32 phase = material_phase;
        material_phase = phase + 0x800;
        bodies->unk_28 = sub_800A3210(2);
    } else {
        bodies->unk_28 = 0.0f;
    }
    if ((m_388 & 0x800000) && obj_testFlags30(0x22) == 0) {
        if (glow_emitter == NULL) {
            glow_emitter = create_particle_emitter(&body_center, 0xDB);
        } else {
            glow_emitter->set_position(&body_center);
        }
    } else if (glow_emitter != NULL) {
        ((TObject *)glow_emitter)->queue_destruction();
        glow_emitter = NULL;
    }
    if ((m_388 & 0x200000) && obj_testFlags30(0x22) == 0) {
        if (trail_emitter == NULL) {
            if (is_flag_set_388_bit26() != 0) {
                trail_emitter = create_particle_emitter(&shadow_pos, 0xD9);
            } else {
                trail_emitter = create_particle_emitter(&shadow_pos, 0xD4);
            }
        } else {
            trail_emitter->set_position(&shadow_pos);
        }
    } else if (trail_emitter != NULL) {
        ((TObject *)trail_emitter)->queue_destruction();
        trail_emitter = NULL;
    }
    if (update_action_hold_status() != 0 || update_shock_clock() != 0 || update_movement_status() != 0) {
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
        return;
    }
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            sub_800A1520();
        }
        mode = next_action;
        state = 0;
    }
    sub_800A1520();
    update_prev_position();
    body_center.y += render_y_offset;
    VecCopy(&center, &shadow_pos);
    if (m_388 & 0x80000) {
        render_y_offset = fmin_800A28A4(0.5f + render_y_offset, 10.0f);
    } else {
        render_y_offset = fmax_800A28A4(render_y_offset - 0.5f, 0.0f);
    }
    sub_800A159C();
    bodies->offset.y = 4.0f + render_y_offset;
    if ((actor_frame_tick & 3) == 0 && (m_388 & 0x400000) && obj_testFlags30(0x22) == 0 &&
        classify_actor_view_detail(150.0f, 400.0f, 15.0f) != 0) {
        Vec p = position;
        p.y += render_y_offset;
        spawn_particle_effect(&p, 0xD6);
    }
}

void TObjEneDarkGunner::apply_fall_damage_flag() {
    s32 var_r4;
    if (xz_distance_squared(&position, &home_position) > 100.0f) {
        var_r4 = 8;
    } else {
        var_r4 = 0;
    }
    update_if_active(var_r4);
}
}

#pragma pop
extern "C" {
void TObjEneDarkGunner::sub_800A27CC() {
    switch (((TObjPlayer *)this)->m_37c) {
    case 0:
        if (((TObjEneDarkGunner *)((TObjPlayer *)this))->m_388 & 0x10000) {
            ((TObjPlayer *)this)->actorFlags |= 0x04040000;
            ((TObjPlayer *)this)->rotation_z = 0x8000;
            ((TObjPlayer *)this)->m_37c = 1;
        } else {
            ((TObjPlayer *)this)->requested_action = 0;
            ((TObjPlayer *)this)->m_37c = 2;
        }
        ((TObjEneDarkGunner *)((TObjPlayer *)this))->m_388 |= 0x400000;
        ((TObjPlayer *)this)->advance_animation();
        break;
    case 1:
        break;
    case -1:
        break;
    }
}

void TObjEneDarkGunner::set_hidden_flag() {
    if (!(actorFlags & 0x800)) {
        update_if_active(1);
        m_388 |= 0x20000;
    }
}
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern "C" {
void TObjEneDarkGunner::update_move() {
    obj_clearFlags30(0x40000);
    switch ((s32)state) {
    case 0:
        m_388 &= ~0x00200000;
        m_388 |= 0x400000;
        if (m_388 & 0x10000) {
            m_388 &= ~0x30000;
            velocity.z = 0.0f;
            velocity.y = 0.0f;
            velocity.x = 0.0f;
            state = 1;
        } else {
            actorFlags &= 0xFBFBFFFF;
            state = 3;
        }
        break;
    case 1:
        apply_actor_gravity(this, NULL, 0.0f);
        rotation_z -= 0x1000;
        if (rotation_z < 0) {
            rotation_z = 0;
        }
        if (actorFlags & 0x800000) {
            rotation_z = 0;
            requested_action = 2;
            state = 2;
            actorFlags &= 0xFBFBFFFF;
            bodies->flags &= ~4;
            bodies->flags |= 2;
            spawn_hamon_effects(0xF, 0, 2.2f);
            spawn_hamon_effects(0xF, 3, 2.0f);
            spawn_hamon_effects(0xF, 6, 1.8f);
        }
        break;
    case 2:
        apply_actor_gravity(this, NULL, 0.0f);
        if (requested_action == 0) {
            state = 3;
        }
        break;
    case 3:
        rotation_z = 0;
        bodies->flags &= ~4;
        bodies->flags |= 2;
        advance_animation();
        if (m_388 & 0x20000) {
            m_388 &= ~0x20000;
            m_388 |= 0x80000;
            if (m_388 & 0x40000) {
                m_388 &= ~0x40000;
                state = 4;
            } else {
                spin_count = 0;
                state = 6;
            }
        } else {
            m_388 &= ~0x80000;
        }
        break;
    case 6:
        rotation_y += 0x555;
        spin_count++;
        if (spin_count >= 4) {
            state = 4;
        }
        break;
    case 4:
        move_heading = rotation_y;
        move_speed = sub_800A3200(0);
        move_distance = 0.0f;
        turn_delay = 0;
        pad_39e = 0;
        requested_action = 1;
        state = 5;
        rotation_z = 0;
        bodies->flags &= ~4;
        bodies->flags |= 2;
    case 5:
        advance_animation();
        enemy_set_heading_velocity(move_speed, this, move_heading);
        step_along_ground();
        move_distance += move_speed;
        move_speed = fmax_800A2390(-0.2f + move_speed, 0.5f);
        if (move_distance >= sub_800A3200(1)) {
            m_388 &= ~0x80000;
            state = 3;
        }
        play_persistent_sound(0x4003AD28, (saddr)this, (uaddr)&position, 0, 0);
        if (turn_delay > 0) {
            turn_delay--;
            if (bodies->flags & 0x300000) {
                move_heading += 0x4000;
                turn_delay = 5;
            }
        }
        if (!(actor_frame_tick & 2)) {
            spawn_hamon_effects(0xF, 0, 1.5f);
        }
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case -1:
        break;
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}
}

#pragma pop
#pragma push
#pragma opt_loop_invariants off
extern "C" {
void TObjEneDarkGunner::update_attack() {
    switch ((s32)state) {
    case 0:
        actorFlags |= 0x200000;
        m_388 &= 0xFFB7FFFF;
        attack_count = 0;
        requested_action = 3;
        play_sound_effect(0x4003B52F, &position, 0, 0);
        play_sound_effect(0x4003AD29, &position, 0, 0);
        state = 1;
        break;
    case 1:
        if (frame >= 5.0f) {
            hover_speed = 1.6088889f;
        }
        if (requested_action != 4) break;
        m_388 |= 0x200000;
        attack_timer = sub_800A3210(0);
        state = 2;
        play_sound_effect(0x4003B52A, &position, 0, 0);
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                void *p = TObject::operator new(0x348);
                if (p != NULL) {
                    p = TObjPlayer__sub_800A4204((u8 *)p, (u8 *)this, (saddr)&shadow_pos, (saddr)&child_offsets[i], 2);
                }
                children[i] = (TeneFakeTecThunderEff *)p;
            }
        }
        break;
    case 2:
        hover_speed = 1.6088889f;
        if (--attack_timer > 0) break;
        attack_timer = 4;
        m_388 &= ~0x200000;
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                TeneFakeTecThunderEff *q = children[i];
                if (q != NULL) {
                    q->queue_destruction();
                    children[i] = NULL;
                }
            }
        }
        state = 3;
        if (is_flag_set_388_bit26() != 0) {
            spawn_particle_effect(&shadow_pos, 0xD8);
        } else {
            spawn_particle_effect(&shadow_pos, 0xD2);
        }
        break;
    case 3:
        hover_speed = 1.6088889f;
        if (--attack_timer > 0) break;
        attack_count++;
        attack_timer = 15;
        state = 4;
        find_target_in_range(200.0f);
        if (targetId == 0xFFFF) break;
        new TUnk_804909C4((u8 *)this, (saddr)&shadow_pos, (saddr)&((TObjChara *)target)->body_center);
        play_sound_effect(0x40039E2B, &position, 0, 0);
        break;
    case 4:
        hover_speed = 1.6088889f;
        if (--attack_timer > 0) break;
        state = 5;
        requested_action = 13;
        hover_speed = 0.0f;
        break;
    case 5:
        if (requested_action != 0) break;
        if (attack_count < 2) {
            state = 1;
            requested_action = 3;
            break;
        }
        update_if_active(1);
        break;
    case -1:
        m_388 &= ~0x200000;
        actorFlags &= ~0x200000;
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                TeneFakeTecThunderEff *q = children[i];
                if (q != NULL) {
                    q->queue_destruction();
                    children[i] = NULL;
                }
            }
        }
        break;
    }
    obj_clearFlags30(0x40000);
    advance_animation();
    apply_actor_gravity(this, NULL, 0.0f);
    update_collisions();
    minimap_render_dot(&position, -23988, 1, 0);
    submit_cursor_candidate(this, -1);
}
}

#pragma pop
extern "C" {
void TObjEneDarkGunner::run_hit_reaction() {
    s16 temp_r0;
    TObjEneDarkGunCenter *center;
    temp_r0 = this->mode;
    if (temp_r0 != 4) {
        if ((temp_r0 == 2) && (is_flag_set_388_bit26() != 0) &&
            (center = (TObjEneDarkGunCenter *)get_enemy_entity(center_id)) != NULL) {
            center->trigger_targets_action();
            return;
        }
        this->set_state(4);
    }
}

void TObjEneDarkGunner::update_damage() {
    f32 limit;
    f32 speed;
    switch ((s32)state) {
    case 0:
        actorFlags = actorFlags & 0xFFDFFFFF;
        if (m_388 & 0x800000) {
            requested_action = 9;
        } else {
            requested_action = 5;
        }
        speed = vector_length(&velocity);
        limit = sub_800A3200(2);
        if (speed > limit) {
            velocity.x = (velocity.x * limit) / speed;
            velocity.z = (velocity.z * limit) / speed;
        }
        if (m_388 & 0x400000) {
            spawn_particle_effect(&body_center, 0xD7);
        }
        pad_39e = 0;
        state = 1;
    case 1:
        velocity.x *= 0.95;
        velocity.z *= 0.95;
        advance_animation();
        {
        Vec v = body_center;
        v.x = v.x + velocity.x;
        v.z = v.z + velocity.z;
        if (check_path_obstructed(this, &v) == 0) {
            move_with_wall_slide((u8 *)this);
        } else {
            velocity.z = 0.0f;
            velocity.x = 0.0f;
        }
        }
        apply_actor_gravity(this, NULL, 0.0f);
        update_collisions();
        if (action_flags != 8U) {
            obj_clearFlags30(0x40300);
            m_388 = m_388 & 0xFF7FFFFE;
            referenceHp = hp;
            set_hidden_flag();
        }
        break;
    case -1:
        m_388 = m_388 & 0xFFFFFFFE;
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneDarkGunner::update_dying() {
    m_388 &= 0xFF07FFFF;
    switch ((s32)state) {
    case 0:
        requested_action = 7;
        refresh_lobby_state();
        send_entity_set_flags();
        render_control.start_fade_out();
        fn_800D911C(&body_center);
        m_388 |= 4;
        play_sound_effect(0x4003AD37, &position, 0, 0);
        state = 1;
        break;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if (render_control.decay_value_toward_floor() == 1) {
            TObjPlayer::apply_effect_variant_a((saddr)&position, 0);
            queue_destruction();
        }
        break;
    case -1:
        break;
    }
}

void TObjEneDarkGunner::render() {
    s32 view;
    s32 drawn;
    s32 visible;
    BOOL cancel;
    s32 i;

    if (obj_testFlags30(0x02000000) == 0) {
        view = classify_actor_view_detail(150.0f, 400.0f, 15.0f);
        if (view != 0) {
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            drawn = 1;
            push_matrix();
            saved_model_render_flags = model_render_flags;
            model_render_flags &= ~0x10;
            translate_matrix(0, position.x, position.y + render_y_offset, position.z);
            rotate_matrix_z(0, rotation_z);
            rotate_matrix_y(0, rotation_y);
            if (m_388 & 0x400000) {
                f32 s;
                model_render_flags |= 0x820;
                set_chunk_material_override_pair(0xFF00, 0x800);
                s = -0.25f * fabs_float(sin_table_lookup(material_phase));
                MaterialColor color = lbl_8043A668;
                color.r = s;
                color.g = s;
                color.b = s;
                set_constant_material((const NJS_ARGB *)&color);
                TObjFish::set_global_param(TObjEneDarkGunner__effect_resource);
            } else {
                TObjFish::set_global_param(texlist);
            }
            if (m_388 & 4) {
                if (render_control.has_visible_opacity() != 0) {
                    render_control.set_flags_and_apply_damage_color();
                    visible = 1;
                    if (defer_render() != 0) {
                        visible = 0;
                    }
                    if (visible != 0) {
                        if (view == 1) {
                            draw();
                        } else {
                            draw_motion_model();
                        }
                    }
                    render_control.clear_flag_and_notify();
                } else {
                    drawn = 0;
                }
            } else if (view == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            if (m_388 & 0x400000) {
                set_constant_material((const NJS_ARGB *)dark_gunner_constant_material);
                set_chunk_material_override_pair(0xFF00, 0);
            }
            model_render_flags = saved_model_render_flags;
            pop_matrix();
            render_shadow();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            cancel = view == 1 && (m_388 & 0x200000) && obj_testFlags30(0x22) == 0;
            for (i = 0; i < 4; i++) {
                if (children[i] != NULL) {
                    if (cancel) {
                        children[i]->set_cancel_flag();
                    } else {
                        children[i]->clear_counter();
                    }
                }
            }
            if (obj_testFlags30(0x800) == 0 && drawn != 0 && obj_testFlags30(0x800000) != 0) {
                Vec offset = dark_gunner_shadow_scale;
                draw_ground_shadow(&offset, 0);
            }
        }
    }
}

void TObjEneDarkGunner::sub_800A1974() {  }

void TObjEneDarkGunner::render_shadow() {
    if (obj_testFlags30(0x800) == 0) {
        if (is_flag_set_388_bit26() == 0) {
            TObjFish::set_global_param(TObjEneDarkGunner__cly_line_texlist);
        } else {
            TObjFish::set_global_param(TObjEneDarkGunner__rcly_line_texlist);
        }
        push_matrix();
        post_translate_matrix(&shadow_pos.x);
        draw_chunk_object(TObjEneDarkGunner__shadow_chunk_object);
        pop_matrix();
    }
}
}

#pragma push
#pragma opt_loop_invariants off
extern "C" {
void TObjEneDarkGunner::spawn_hamon_effects(s32 type, s32 variant, f32 scale) {
    Vec p;
    Ofs_800A1814 ofs = hamon_effect_offset_table;
    s32 i;
    void *e;
    p.y = 0.01f + (position.y + render_y_offset);
    for (i = 0; i < 4; i++) {
        p.x = position.x + ofs.v[i].x;
        p.z = position.z + ofs.v[i].z;
        e = TObject::operator new(0x60);
        if (e != NULL) {
            __ct__12TEneEffHamonFv((u8 *)e, (saddr)&p, type, variant, scale);
        }
    }
}
}

#pragma pop
extern "C" {
int TObjEneDarkGunner::sub_800A1808() { return (actorFlags >> 23) & 0x1; }

void TObjEneDarkGunner::run_miss_reaction() {
    u8 *self = (u8 *)this;
    ((TObjBase *)self)->obj_clearFlags30((s32)(0x100U));
    spawn_particle_effect(&body_center, 0xD7);
    play_sound_effect(0x4003B22D, (u8 *)&this->position, 0, 0);
}

void TObjEneDarkGunner::sub_800A16C4() {
    s16 left;
    switch ((s32)state) {
    case 0:
        m_388 = m_388 | 1;
        obj_clearFlags30(0x100);
        timer = resetTimer;
        requested_action = 0;
        actorFlags = actorFlags & 0xFF9FFFFF;
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        update_collisions();
        left = timer;
        timer = left - 1;
        if (left < 0) {
            referenceHp = hp;
            m_388 = m_388 & 0xFFFFFFFE;
            set_hidden_flag();
        }
        break;
    case -1:
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneDarkGunner::sub_800A159C() {
    f32 lo;
    s32 i;
    hover_speed += (-0.10888889f);
    hover_height += hover_speed;
    hover_height = (hover_height < 0.0f) ? 0.0f : ((hover_height < 9.0f) ? hover_height : 9.0f);
    push_matrix_from(identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_z(0, rotation_z);
    rotate_matrix_y(0, rotation_y);
    Vec t = lbl_8043A6A4;
    lo = 5.0f + hover_height;
    t.y = lo + render_y_offset;
    matrix_mult_vec(0, &t, &shadow_pos);
    if (mode == 2) {
        for (i = 0; i < 4; i++) {
            matrix_mult_vec(0, &dark_gunner_child_local_offsets[i], &child_offsets[i]);
        }
    }
    pop_matrix();
}

void TObjEneDarkGunner::sub_800A1520() {
    switch (mode) {
    case 0:
        sub_800A27CC();
        return;
    case 1:
        update_move();
        return;
    case 2:
        update_attack();
        return;
    case 4:
        update_damage();
        return;
    case 3:
        sub_800A16C4();
        return;
    case 5:
        update_dying();
        return;
    case 6:
        update_hide_sequence();
        return;
    case 8:
        update_move_to_destination();
        break;
    }
}

void TObjEneDarkGunner::trigger_action_if_not_flagged() {
    if (!(actorFlags & 0x800) && !(m_388 & 0x800000)) {
        update_if_active(6);
    }
}

void TObjEneDarkGunner::update_hide_sequence() {
    s32 temp_r3;

    switch ((s32)state) {
    case 0:
        obj_clearFlags30(0x240300);
        m_388 |= 0x800000;
        m_388 &= ~0x480000;
        this->requested_action = 8;
        hide_timer = sub_800A3210(1);
        state = 1;
    case 1:
        advance_animation();
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity(this, (s32 *)(0), 0.0f);
        }
        update_collisions();
        temp_r3 = hide_timer - 1;
        hide_timer = (s16) temp_r3;
        if ((s16) temp_r3 <= 0) {
            set_hidden_flag();
        }
        break;
    case -1:
        m_388 &= 0xFF7FFFFF;
        break;
    }
    minimap_render_dot(&this->position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneDarkGunner::update_move_to_destination() {
    switch ((s32)state) {
    case -1:
        break;
    case 0:
        m_388 &= ~0x200000;
        m_388 |= 0x480000;
        requested_action = 0;
        state = 1;
    case 1: {
        advance_animation();
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, (s32 *)(0), 0.0f);
        }
        calc_velocity_toward_destination(this, position, home_position, sub_800A3200(0));
        move_with_wall_slide((u8 *)this);
        if (xz_distance_squared(&position, &home_position) <= 100.0f) {
            m_388 &= ~0x80000;
            apply_fall_damage_flag();
        }
        break;
    }
    }
}

void TObjEneDarkGunner::init_scale_global() {
    player_scale_factor = sub_800A3200(3);
}
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {
void TObjEneDarkGunner::step_along_ground() {
    Vec pos;
    Raw_800A10A0 vel;
    Vec dir;
    Vec v;
    s32 ang;
    s32 sign;
    s32 b;
    s32 a;
    s32 i;
    CsnHit *hit;
    CsnContact *q;

    VecCopy(&prev_position, &position);
    VecCopy(&pos, &body_center);
    vel = *(Raw_800A10A0 *)&velocity;
    vec_set_length((Vec *)&vel, 10.0f + sub_800A3200(0));
    vec3_add_to(&pos, (Vec *)&vel);
    hit = csnVector(&body_center, &pos, -1);
    if (hit != NULL) {
        a = 10430.38043493439 * atan2_float(velocity.x, velocity.z);
        q = hit->contact;
        b = 10430.38043493439 * atan2_float(q->normal.x, q->normal.z);
        move_heading = b - (0x8000 - angle_diff_s16(a, b));
    }
    if ((1.0f / 32768.0f) * (f32)rand() < 0.5f) {
        sign = -1;
    } else {
        sign = 1;
    }
    for (i = 0, ang = 0; i < 15; i++, ang += 0x1000) {
        if (i == 0) {
            VecCopy(&dir, &velocity);
        } else {
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, sign * ang);
            rotate_vector_by_matrix(0, &velocity, &dir);
            pop_matrix();
        }
        VecCopy(&v, &position);
        vec3_add_to(&v, &dir);
        if (project_actor_to_ground(this, &v, 0) == 1) {
            VecCopy(&position, &v);
            VecCopy(&velocity, &position);
            subtract_vector(&velocity, &prev_position);
            return;
        }
    }
}
}

#pragma pop
extern "C" {
s32 TObjEneDarkGunner::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        sub_800A100C();
        return 1;
    }
    return 0;
}

s32 TObjEneDarkGunner::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        sub_800A100C();
        return 1;
    }
    return 0;
}

void TObjEneDarkGunner::sub_800A100C() {  }

void TObjEneDarkGunner::sub_800A0FDC() {
    m_388 |= 0x04000000;
    set_param(0x23);
}

void TObjEneDarkGunner::clear_lappy_flag_set_param() {
    m_388 &= ~0x04000000;
    set_param(0x22);
}
}
