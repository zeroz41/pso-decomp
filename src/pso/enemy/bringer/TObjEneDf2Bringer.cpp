#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/bringer/TObjEneDf2Bringer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/BmlResourceDescriptor.h"




#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_801542CC.h"

#include "pso/unk/SampledMotionPoints.h"


#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/system/vector.h"


#include "pso/enemy/TUnk_8048FE7C.h"

#include "pso/boss/darkfalz/TBoss4Type3.h"

#include "pso/enemy/TUnk_8048FE08.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"

#include "pso/player/TUnk_804928CC.h"
#include "pso/render/TUnk_80490470.h"

void bringer_render_node_callback(NJS_OBJECT *);
extern "C" {
void *bringer_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8048FA2C[33] = {
    (void *)0x0, (void *)0x41a00000, (void *)0x41000000, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x40400000, (void *)0x0,
    (void *)0x0, (void *)0x9d03, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x40400000, (void *)0x0, (void *)0x0,
    (void *)0x9d03, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
// The Bringer's model and motions, and the archive that holds them.
__declspec(section ".data") const char *bm_ene_df2_bringer_model_names[2] = {
    "bm8_s_kb_body.nj",
    NULL
};
const char *bm_ene_df2_bringer_motion_names[12] = {
    "beam_bm8_s_kb_body.njm",
    "cold_bm8_s_kb_body.njm",
    "damage_bm8_s_kb_body.njm",
    "dead_bm8_s_kb_body.njm",
    "hoe_bm8_s_kb_body.njm",
    "kamae_bm8_s_kb_body.njm",
    "kiri_bm8_s_kb_body.njm",
    "run_bm8_s_kb_body.njm",
    "tpkyu_bm8_s_kb_body.njm",
    "wait_bm8_s_kb_body.njm",
    "walk_bm8_s_kb_body.njm",
    NULL
};
BmlResourceDescriptor bm_ene_df2_bringer_resource_descriptor = {
    "bm_ene_df2_bringer.bml", bm_ene_df2_bringer_model_names, bm_ene_df2_bringer_motion_names, 1, 11
};
TObjMotionAction lbl_8048FAF8[11] = {
    { 1, 0, 9, 0.8f, 0 },
    { 1, 0, 10, 1.0f, 0 },
    { 1, 0, 7, 1.0f, 0 },
    { 3, 0, 4, 0.6f, 0 },
    { 3, 0, 6, 0.6f, 0 },
    { 3, 0, 0, 0.6f, 0 },
    { 3, 0, 2, 0.7f, 0 },
    { 3, 0, 5, 0.6f, 0 },
    { 1, 0, 1, 0.6f, 0 },
    { 3, 0, 8, 0.4f, 0 },
    { 3, 0, 3, 0.6f, 0 },
};

}




#include <stddef.h>
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/enemy/dellbiter/TObjEneDellBiter.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/unk/TLobby.h"
#include "pso/item/TItem.h"

#include "pso/enemy/bringer/BringerEffects.h"
#include "pso/enemy/TUnk_8048FE64.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/SoundEffect.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D853C.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"

#pragma defer_codegen on


extern "C" {
s32 TObjPlayer__sub_800A04F0(void *);
s32 scroll_strip_uvs(int, int, int);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
TParticleCtrl *create_particle_emitter(const void *pos, s32 id);


}

saddr bringer_boss_stats_handle;
saddr bringer_boss_stats_ptr_b;
saddr bringer_object_handle;
BringerParameters *TObjEneDf2Bringer__data_805D4FB4;
BmlResource *TObjEneDf2Bringer__resource_bundle;
s32 TObjEneDf2Bringer__render_node_index;
s32 TObjEneDf2Bringer__render_rotation_x;
Vec *TObjEneDf2Bringer__render_point_cursor;
SampledMotionPoints *TObjEneDf2Bringer__trail_buffer;
saddr TObjEneDf2Bringer__uv_scroll_buffer;

Vec bringer_camera_ctrl_target_vec;





struct Pair_800993E8 { f32 a; u32 flags; };



extern "C" {
s32 rotate_xz_pair_by_angle(f32 *, f32 *, s32, f32, f32);
}


void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {


const char *TObjEneDf2Bringer__name = "TObjEneDf2Bringer";






extern void *tl_04;


#pragma push
#pragma fp_contract on
void TObjEneDf2Bringer::load_resources() {
  Vec offs[4];
  s32 ids[4];
  Vec a;
  Vec d;
  void *o;
  Vec *p3;
  s32 n;
  Vec *seg;
  Vec *p1;
  s32 i;
  f32 len;
  f32 s2;
  f32 s1;
  s32 j;
  bringer_camera_ctrl_target_vec.x = 0.0f;
  bringer_camera_ctrl_target_vec.y = 0.0f;
  bringer_camera_ctrl_target_vec.z = 0.0f;
  if (TObjEneDD::check_v2_mode() != 0)
  {
    TObjEneDf2Bringer__resource_bundle = load_enemy_bml_resource_named(&bm_ene_df2_bringer_resource_descriptor, "bm_ene_df2_bringer_a.bml");
  }
  else
  {
    TObjEneDf2Bringer__resource_bundle = load_enemy_bml_resource(&bm_ene_df2_bringer_resource_descriptor);
  }
  bringer_boss_stats_handle = (saddr)TLobby::register_boss(0xD);
  bringer_boss_stats_ptr_b = (saddr)TLobby::dispatch_shared_handler_b(0xD);
  bringer_object_handle = (saddr)TLobby::register_object(0xD);
  TObjEneDf2Bringer__data_805D4FB4 = (BringerParameters *)TLobby::dispatch_shared_handler_a(0xD);
  TObjEneDf2Bringer__render_node_index = 0;
  TObjEneDf2Bringer__render_rotation_x = 0;
  TObjEneDf2Bringer__render_point_cursor = 0;
  TObjEneDf2Bringer::set_entry_value_clamped(4, TObjEneDf2Bringer__data_805D4FB4->action4_speed);
  TObjEneDf2Bringer::set_entry_value_clamped(5, TObjEneDf2Bringer__data_805D4FB4->action5_speed);
  SampledMotionPoints *sampled = new SampledMotionPoints(4, 7.0f, 14.0f, lbl_8048FAF8[4].speed);
  TObjEneDf2Bringer__trail_buffer = sampled;
  {
    ids[0] = 0x1A;
    ids[1] = 0x1A;
    ids[2] = 0x1E;
    ids[3] = 0x1E;
    for (i = 0; i < 4; i++)
    {
      offs[i].x = 0.0f;
      offs[i].y = 0.0f;
      offs[i].z = 0.0f;
    }

    sampled->sample(TObjEneDf2Bringer__resource_bundle->models[0].model, (NJS_MOTION *)TObjEneDf2Bringer__resource_bundle->motions[lbl_8048FAF8[4].motion].motion, ids, offs);
  }
  n = TObjEneDf2Bringer__trail_buffer->sample_count;
  seg = TObjEneDf2Bringer__trail_buffer->points;
  for (j = 0; j < n; seg += 4, j++)
  {
    VecCopy(&a, &seg[0]);
    VecCopy(&d, &seg[2]);
    subtract_vector(&d, &a);
    len = normalize_vector_safe(&d);
    p1 = &seg[1];
    s1 = 0.4f * len;
    VecCopy(p1, &a);
    p1->x = (d.x * s1) + p1->x;
    p1->y = (d.y * s1) + p1->y;
    p1->z = (d.z * s1) + p1->z;
    p3 = &seg[3];
    s2 = 0.7f * len;
    VecCopy(p3, &a);
    p3->x = (d.x * s2) + p3->x;
    p3->y = (d.y * s2) + p3->y;
    p3->z = (d.z * s2) + p3->z;
  }
  o = ::operator new(0x14);
  if (o != 0)
  {
    o = ((TLobby *)o)->alloc_tables((saddr)TObjEneDf2Bringer__resource_bundle->models[0].model, 1);
  }
  TObjEneDf2Bringer__uv_scroll_buffer = (uaddr) o;
  init_bringer_effect_tables();
  {
    NpcAnimationBinding sp = { TObjEneDf2Bringer__resource_bundle->motions, lbl_8048FAF8, 0, 1, 11 };
    NpcModelRegistry::register_animated_chunk((s16)0x16, TObjEneDf2Bringer__resource_bundle->models[0].model, TObjEneDf2Bringer__resource_bundle->models[0].m_c, &sp, 7.0f, 0.0f);
  }
}

#pragma pop
void *TObjEneDf2Bringer::create() {
    void *o = (void *)new TObjEneDf2Bringer((TObject *)tl_04, (void *)this);
    return o;
}

void TObjEneDf2Bringer::free_resources() {
    bringer_effect_cleanup_noop();
    if ((u32) TObjEneDf2Bringer__uv_scroll_buffer != 0U) {
        destroy_buffer_pair((void *)TObjEneDf2Bringer__uv_scroll_buffer, 1);
        TObjEneDf2Bringer__uv_scroll_buffer = 0U;
    }
    if (TObjEneDf2Bringer__trail_buffer != NULL) {
        delete TObjEneDf2Bringer__trail_buffer;
        TObjEneDf2Bringer__trail_buffer = NULL;
    }
    if (TObjEneDf2Bringer__resource_bundle != NULL) {
        delete TObjEneDf2Bringer__resource_bundle;
        TObjEneDf2Bringer__resource_bundle = NULL;
    }
}

void TObjEneDf2Bringer::set_entry_value_clamped(s32 index, f32 speed) {
  if (speed < 0.1f)
  {
    speed = 0.1f;
  }
  lbl_8048FAF8[index].speed = speed;
}

}
TObjEneDf2Bringer::TObjEneDf2Bringer(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    m_name = TObjEneDf2Bringer__name;
    invoke_initialization_hook(set_data);
    sub_800994F8();
    this->init_enemy();
}


void TObjEneDf2Bringer::init_enemy() {
    s32 i;

    init_position_vectors();
    this->model = TObjEneDf2Bringer__resource_bundle->models[0].model;
    this->texlist = (saddr)TObjEneDf2Bringer__resource_bundle->models[0].m_c;
    init_model((CollisionBody *)lbl_8048FA2C, (s32)1);
    set_field_d8((saddr)lbl_8048FAF8);
    set_field_dc((saddr)TObjEneDf2Bringer__resource_bundle->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    reset_hp((u8 *)bringer_boss_stats_handle, (u8 *)bringer_boss_stats_ptr_b, (u8 *)bringer_object_handle);
    set_state_8();
    this->movementParameters = bringer_init_params;
    initialize_enemy_state(0x24);
    this->wall_reach = 20.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    this->pad_3C0 = 0;
    this->pad_3C0 |= 1;
    this->pad_3C4.reset_obstruction_fade();
    for (i = 0; i < 4; i++) {
        this->renderFadeStates[i].activate_and_dispatch();
    }
    for (i = 0; i < 4; i++) {
        VecCopy(&this->pad_450[i], &this->position);
    }
    this->pad_480 = 0;
    this->pad_484 = 0;
    this->pad_488 = 1;
    this->pad_494 = 0;
    this->pad_48C = 0;
    this->pad_490 = 0;
    this->collider = new TUnk_804928CC(this, this, (const CollisionBody *)((u8 *)lbl_8048FA2C + 0x2C), 2);
    this->attack_history = new AreaAttackHistory(8);
    this->pad_4A0 = new TUnk_8048FE08(this, this, this->attack_history);
    this->pad_4A4 = TUnk_80494968::create(0xFF5050FF, 0x80000080);
    this->pad_4A8 = 0;
    this->pad_4AC = 0;
    this->pad_4B0 = 0;
    this->pad_4B4 = 0;
    this->pad_4B8 = 0;
    this->pad_4BC = 0.0f;
    this->pad_4C0 = 0.0f;
    this->pad_4C4 = NULL;
    this->mode = 1;
    this->dispatch_action(this->mode, 4);
}

TObjEneDf2Bringer::~TObjEneDf2Bringer() {
    if (this->pad_4C4 != NULL) {
        this->pad_4C4->queue_destruction();
        this->pad_4C4 = NULL;
    }
    this->pad_4A4->queue_destruction();
    this->pad_4A4 = NULL;
    delete this->pad_4A0;
    this->pad_4A0 = NULL;
    delete this->attack_history;
    this->attack_history = NULL;
    delete this->collider;
    this->collider = NULL;
    free_collision_body_parts(this);
}


void TObjEneDf2Bringer::run_task() {
    s32 hits;
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    if (update_status_effects() != 4) {
        update_action_state();
        pad_4A8 = pad_4A8 + 0xC;
        pad_4A8 = (u8)pad_4A8;
        hits = pad_494;
        if (hits <= 2) {
            pad_488 = 1;
        } else if (hits <= 4) {
            pad_488 = 5;
        } else if (hits <= 5) {
            pad_488 = 6;
        }
    }
    set_effect_pos_above_self();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneDf2Bringer::refresh_target() {  }

void TObjEneDf2Bringer::run_death_reaction() { if (*(short*)((char*)this + 0x326) != 10) { TObjEneDD::transition_enemy_state(10); } }

void TObjEneDf2Bringer::run_hit_reaction() {
    u8 *self = (u8 *)this;
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 != 9) && (temp_r0 != 8)) {
        this->sub_80098DEC();
    }
    if (*(s32 *)((s8 *)self + 0x3C0) & 4) {
        ((TObjEneDD *)self)->clear_attack_receipts();
        return;
    }
    if ((s16) this->mode != 9) {
        ((TObjEneDD *)self)->transition_enemy_state(9);
    }
}

void TObjEneDf2Bringer::run_miss_reaction() {  }

void TObjEneDf2Bringer::set_effect_pos_above_self() {
    u8 *self = (u8 *)this;
    VecCopy((Vec *)(self + 0x2FC), (const Vec *)(self + 0x38));
    *(f32 *)((s8 *)self + 0x300) += 20.0f;
    VecCopy((Vec *)(self + 0x74), (const Vec *)(self + 0x2FC));
}

void TObjEneDf2Bringer::update_body_colliders() {  }

void TObjEneDf2Bringer::sub_800994F8() {  }

// The slash: from the swing's start frame to frame 13 the attack collider follows the blade
// points sampled from the motion and hits through attack_history.
void TObjEneDf2Bringer::update_attack_child() {
    Vec *points;
    f32 start;
    if (TObjEneDD::check_v2_mode() != 0) {
        start = 7.8f;
    } else {
        start = 10.8f;
    }
    if (frame >= start && frame <= 13.0f) {
        points = TObjEneDf2Bringer__trail_buffer->lookup(frame);
        VecCopy(&collider->position, &position);
        collider->rotation_y = rotation_y;
        VecCopy(&collider->bodies[0].offset, &points[1]);
        VecCopy(&collider->bodies[1].offset, &points[3]);
        collider->refresh_collision_body_centers();
        Pair_800993E8 pair = { 3.0f, 1 };
        if (is_confused() != 0) {
            pair.flags |= 2;
        }
        collider->call_vt16_with_default(&pair, attack_history);
    }
}

// The charge's contact: every player the body touches takes rush_power once per charge.
s32 TObjEneDf2Bringer::sub_80099248() {
    s32 hit;
    TObjPlayer *player;
    s32 i;
    u8 *eff;
    hit = 0;
    TObjPlayer::init_all_slots();
    check_object_collisions();
    check_enemy_body_collisions(this);
    if (bodies->flags & 0x180000) {
        hit = 1;
        for (i = 0; i < 0x10; i++) {
            player = (TObjPlayer *)TObjPlayer::get_battle_param(i);
            if (player == NULL) {
                break;
            }
            if (obj_is_hit_receivable((u8 *)player) != 0 && attack_target_history_add(attack_history, player) != 0) {
                DirectAttackPayload h;
                h.kind = 0;
                h.power = TObjEneDf2Bringer__data_805D4FB4->rush_power;
                player->receive_direct_attack(this, h, 0, -1, -1);
                if (is_player_entity_id(get_entity_id(player)) != 0) {
                    if (TObjEneDD::check_v2_mode() != 0) {
                        if (TObjPlayer::is_locally_controlled(player) != 0) {
                            TItem *item = (TItem *)TObjPlayer::get_item_field_6(player);
                            if (item != NULL) {
                                TObjPlayer::send_6x26_unequip_item((void *)player, item->get_item_id());
                            }
                        }
                    } else if (random_ratio() <= 0.3333f) {
                        TObjEneDD__sub_800BA438(this, player);
                    }
                }
                eff = (u8 *)TObject::operator new(0x34);
                if (eff != NULL) {
                    construct_bringer_rush_effect(eff, (saddr)this, (u8 *)this, (saddr)player, 12.0f);
                }
            }
        }
    }
    return hit;
}

void TObjEneDf2Bringer::spawn_offset_particle() {
    Vec stack;
    stack.x = -5.0f;
    stack.y = 0.0f;
    stack.z = 7.0f;
    rotate_xz_pair_by_angle(&stack.x, &stack.z, rotation_y, 0.0f, -5.0f);
    vec3_add_to(&stack, &position);
    spawn_particle_effect(&stack, 0xF3);
}

void TObjEneDf2Bringer::spawn_particle_if_in_band() {
    if (is_passing_frame(0.0f) != 0 || is_passing_frame(8.0f) != 0) {
        spawn_particle_effect(&position, 0xF0);
    }
}

void TObjEneDf2Bringer::update_if_in_band() {
    if (is_passing_frame(21.0f) != 0) {
        spawn_offset_particle();
    }
}

// Without a held target (flag 8) it follows the linked position; a held target that is no
// longer valid clears the flag.
s32 TObjEneDf2Bringer::update_flag_0x3C0() {
    s32 valid;
    if (!(pad_3C0 & 8)) {
        return update_linked_position(300.0f);
    }
    valid = enemy_validate_retained_target(this);
    if (valid == 0) {
        pad_3C0 &= ~8;
    }
    return valid;
}

// Targets the farthest living player within 300 units that it can see (inferred: the shot's target).
s32 TObjEneDf2Bringer::sub_80098FF4() {
    s32 count;
    TObjPlayer *player;
    u16 id;
    s32 i;
    f32 dist;
    f32 best;
    best = 0.0f;
    id = 0xFFFF;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player->is_alive() != 0) {
            dist = horizontal_distance_squared(&body_center, &player->position);
            if (dist < 90000.0f && dist > best &&
                csnLookAt(&body_center, &player->body_center) == NULL) {
                id = get_entity_id(player);
                best = dist;
            }
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(this, id);
        return 1;
    }
    enemy_clear_target();
    return 0;
}

// Drains a quarter of the TP of every living player it can see, returns the total drained.
s32 TObjEneDf2Bringer::attack_visible_players() {
    s32 count;
    TObjPlayer *player;
    s32 total;
    s32 i;
    s32 dmg;
    count = TLobby::get_game_mode();
    total = 0;
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player->is_alive() != 0) {
            horizontal_distance_squared(&body_center, &player->position);
            if (csnLookAt(&body_center, &player->body_center) == NULL) {
                dmg = floor_to_float(0.25f * (f32)get_actor_tp(player));
                check_can_act__10TObjPlayerFii((saddr)player, (s16)dmg);
                total += dmg;
                new TUnk_8048FE64(this, &player->body_center, &pad_450[3]);
            }
        }
    }
    return total;
}

void TObjEneDf2Bringer::sub_80098EB4() {
    play_persistent_sound(remap_sound_for_area(0x4003B708), (saddr)this, (uaddr)&position, 0, 0);
}

s32 TObjEneDf2Bringer::acquire_target(f32 range) {
    if (this->is_confused() != 0) {
        return ((TObjEneDD_ST *)this)->select_and_apply_target(range);
    }
    return select_nearest_target(range);
}

void TObjEneDf2Bringer::sub_80098DEC() {
    u8 *self = (u8 *)this;
    saddr player;
    u16 temp_r3;
    temp_r3 = *(u16 *)((s8 *)self + 0x2D4);
    if (temp_r3 < 0x1000U) {
        player = (saddr)get_player_by_client_id(temp_r3);
        if (player != 0) {
            ((TObjEneDD_ST *)self)->set_target_player((void *)player);
        }
        *(s32 *)((s8 *)self + 0x3C0) = (s32) (*(s32 *)((s8 *)self + 0x3C0) | 8);
    }
    *(s32 *)((s8 *)self + 0x494) = (s32) (*(s32 *)((s8 *)self + 0x494) + 1);
}

s32 TObjEneDf2Bringer::check_stage_advance() {
    if ((s32) *(s32 *)((s8 *)this + 0x494) >= 5) {
        this->transition_enemy_state(8);
        return 1;
    }
    return 0;
}

void TObjEneDf2Bringer::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_state(reason);
        return;
    case 1:
        this->sub_80098BAC(reason);
        return;
    case 2:
        exec(reason);
        return;
    case 3:
        this->sub_800987E8(reason);
        return;
    case 4:
        sub_8009859C(reason);
        return;
    case 5:
        sub_8009813C(reason);
        return;
    case 6:
        sub_80097E9C(reason);
        return;
    case 7:
        action(reason);
        return;
    case 8:
        sub_80097820(reason);
        return;
    case 9:
        this->sub_80097714(reason);
        return;
    case 10:
        this->sub_80097620(reason);
    default:
        return;
    }
}

void TObjEneDf2Bringer::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        this->set_field_378(0);
        this->pad_4AC = 0;
        return;
    case 3:
        this->transition_enemy_state(1);
        return;
    case 0:
        this->pad_4AC++;
    case 5:
        return;
    }
}

void TObjEneDf2Bringer::sub_80098BAC(s32 mode) {
    switch (mode) {
    case 4:
        this->set_field_378(1);
        this->pad_3C0 |= 1;
        this->set_intangible();
        return;
    case 3:
        if (((s32)this->update_linked_position(300.0f)) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->rotation_y = (s32) (10430.38043493439 * atan2_float((f64) this->destination_direction.x, (f64) this->destination_direction.z));
            this->transition_enemy_state(2);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneDf2Bringer::exec(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(4);
        this->pad_3C0 &= ~1;
        this->pad_3C0 |= 2;
        this->set_intangible();
        this->pad_3C4.reset_obstruction_fade();
        this->pad_4AC = 0;
        this->pad_4B0 = 0;
        play_sound_effect(this->remap_sound_for_area(0x3640D), &this->position, 0, 0);
        VecCopy(&this->position, &this->home_position);
        VecCopy(&this->prev_position, &this->position);
        VecCopy(&this->body_center, &this->position);
        this->pad_494 = 0;
        this->pad_48C = 0;
        return;
    case 3:
        if (this->pad_4B0 == 2) {
            this->transition_enemy_state(4);
        }
        return;
    case 0:
        advance_animation();
        this->update_linked_position(300.0f);
        this->pad_4AC++;
        switch (this->pad_4B0) {
        case 0:
            if (this->pad_4AC > 0x14) {
                this->pad_4B0 = 1;
                this->requested_action = 3;
                play_sound_effect(this->remap_sound_for_area(0x4003B40E), &this->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
            this->spawn_particle_if_in_band();
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, 1.2f);
            sub_80098EB4();
            break;
        case 1:
            this->update_if_in_band();
            if (this->get_flag_b4() != 0) {
                this->pad_4B0 = 2;
            }
            break;
        }
        if (this->pad_3C4.advance_toward_max() != 0) {
            this->pad_3C0 &= ~2;
            this->clear_intangible();
            this->check_collisions();
            return;
        }
        break;
    case 5:
        this->clear_intangible();
        break;
    }
}

void TObjEneDf2Bringer::sub_800987E8(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(3);
        this->pad_3C0 &= ~7;
        this->set_intangible();
        this->pad_4AC = 0;
        this->pad_4B0 = 0;
        return;
    case 3:
        if (this->pad_4AC == 2) {
            this->transition_enemy_state(4);
        } else if (this->pad_4AC == 3) {
            this->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->pad_4AC) {
        case 0:
            if (this->update_linked_position(300.0f) != 0) {
                this->pad_4AC = 2;
            } else {
                this->pad_4B0++;
                if (this->pad_4B0 >= 0x3C) {
                    this->pad_4AC = 1;
                    this->pad_3C4.reset_color();
                    this->pad_3C0 |= 2;
                }
            }
            break;
        case 1:
            if (this->pad_3C4.decay_value_toward_floor() != 0) {
                this->pad_4AC = 3;
            }
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

#pragma push
#pragma fp_contract on
// The approach: walks toward the target, charges when it is farther than rush_distance and
// slashes once it is within attack_distance and facing it.
void TObjEneDf2Bringer::sub_8009859C(s32 mode) {
    f32 t;
    s32 ang;
    BringerParameters *prm;
    switch (mode) {
    case 4:
        requested_action = 1;
        set_field_378(4);
        clear_intangible();
        pad_3C0 &= ~7;
        pad_4AC = 0;
        break;
    case 3:
        if (current_target == NULL) {
            transition_enemy_state(3);
        } else if (destination_distance >= (f32)TObjEneDf2Bringer__data_805D4FB4->rush_distance && pad_490 < 2) {
            transition_enemy_state(5);
        } else if (pad_4AC == 1) {
            transition_enemy_state(6);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (update_flag_0x3C0() != 0) {
            enemy_copy_target_destination();
            update_velocity();
        }
        ang = (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, ang, 0x300);
        pad_480 = TObjBoss2Tunnel::turn_toward_angle_limited(rotation_y, pad_480, ang, 0x200, 0x2000);
        prm = TObjEneDf2Bringer__data_805D4FB4;
        if (destination_distance <= (f32)prm->attack_distance) {
            t = destination_direction.z * cos_table_lookup(rotation_y);
            t = (destination_direction.x * sin_table_lookup(rotation_y)) + t;
            if (t >= cos_table_lookup(0x1800)) {
                pad_4AC = 1;
            }
        } else {
            t = cos_table_lookup(rotation_y);
            move_clamped_on_ground(sin_table_lookup(rotation_y), t, prm->walk_speed);
        }
        check_collisions();
        sub_80098EB4();
        break;
    }
}

// The charge: runs at rush_speed until it hits a wall, a player or passes its target, then
// staggers for stagger_frames while the speed decays.
void TObjEneDf2Bringer::sub_8009813C(s32 mode) {
    Vec d;
    s32 hit;
    switch (mode) {
    case 4:
        requested_action = 7;
        set_field_378(4);
        pad_3C0 &= ~7;
        pad_4AC = 0;
        pad_4B0 = 0;
        pad_4BC = TObjEneDf2Bringer__data_805D4FB4->rush_speed;
        fill_value_array(attack_history);
        set_active();
        break;
    case 3:
        if (pad_4AC == 3) {
            pad_48C = 0;
            pad_490++;
            pad_3C0 &= ~8;
            if (check_stage_advance() == 0) {
                transition_enemy_state(7);
            }
        }
        break;
    case 0:
        advance_animation();
        switch (pad_4AC) {
        case 0:
            if (is_passing_frame(11.0f) != 0 || is_passing_frame(21.0f) != 0) {
                spawn_offset_particle();
            }
            if (get_flag_b4() != 0) {
                requested_action = 2;
                pad_4AC = 1;
                pad_3C0 |= 4;
                bodies->flags |= 0x700;
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            rotation_y = approach_angle_limited(rotation_y, (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)), 0x280);
            pad_480 = TObjBoss2Tunnel::turn_toward_angle_limited(rotation_y, pad_480, rotation_y, 0x200, 0x2000);
            check_collisions();
            break;
        case 1:
            spawn_particle_if_in_band();
            hit = 0;
            if (enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 30.0f * TObjEneDf2Bringer__data_805D4FB4->rush_speed) != 0) {
                hit = 1;
            }
            move_clamped_on_ground(destination_direction.x, destination_direction.z, TObjEneDf2Bringer__data_805D4FB4->rush_speed);
            if (has_move_failures(1) != 0) {
                hit = 1;
            }
            update_enemy_collision_flags();
            if (bodies->flags & 0x200000) {
                hit = 1;
            }
            if (sub_80099248() != 0) {
                hit = 1;
            }
            if (enemy_validate_retained_target(this) != 0) {
                VecCopy(&d, &current_target->position);
                subtract_vector(&d, &position);
                if (normalize_vector_xz(&d) >= 30.0f) {
                    if (d.x * sin_table_lookup(rotation_y) + d.z * cos_table_lookup(rotation_y) < 0.0f) {
                        hit = 1;
                    }
                }
            }
            if (hit != 0) {
                pad_4AC = 2;
                pad_4B0 = 0;
                pad_484 = TObjEneDf2Bringer__data_805D4FB4->stagger_frames;
                pad_3C0 &= ~4;
                set_field_378(7);
                play_sound_effect(remap_sound_for_area(0x4003B40E), &position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
            play_persistent_sound(remap_sound_for_area(0x4003AD09), (saddr)this, (uaddr)&position, 0, 0);
            break;
        case 2:
            pad_4B0++;
            if (pad_4B0 >= 10) {
                requested_action = 3;
                update_if_in_band();
                if (get_flag_b4() != 0) {
                    pad_4AC = 3;
                }
                pad_4BC *= 0.95f;
            }
            if (pad_4BC >= 3.0f) {
                sub_80099248();
            } else {
                check_collisions();
            }
            move_clamped_on_ground(destination_direction.x, destination_direction.z, pad_4BC);
            break;
        }
        break;
    case 5:
        pad_3C0 &= ~4;
        bodies->flags &= ~0x700;
        clear_field_388();
        break;
    }
}

#pragma pop
// The slash: sweeps the trail between the sampled blade points and hits through
// update_attack_child, then waits slash_recover_frames.
void TObjEneDf2Bringer::sub_80097E9C(s32 mode) {
    Vec edge[2];
    s32 angle;
    Vec *points;
    switch (mode) {
    case 4:
        requested_action = 4;
        set_field_378(4);
        pad_3C0 &= ~3;
        pad_3C0 |= 4;
        fill_value_array(attack_history);
        pad_4A4->clear_segments();
        pad_4AC = 0;
        pad_4B0 = 0;
        pad_490 = 0;
        break;
    case 3:
        if (pad_4B0 == 2) {
            pad_48C++;
            if (pad_48C >= 2) {
                pad_48C = 0;
                pad_3C0 &= ~8;
            }
            if (check_stage_advance() == 0) {
                transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        angle = rotation_y;
        pad_480 = TObjBoss2Tunnel::turn_toward_angle_limited(angle, pad_480, angle, 0x200, 0x2000);
        switch (pad_4B0) {
        case 0:
            if (is_passing_frame(11.0f) != 0) {
                spawn_offset_particle();
            }
            points = TObjEneDf2Bringer__trail_buffer->lookup(frame);
            if (points != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position.x);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec(0, &points[2], &edge[0]);
                matrix_mult_vec(0, &points[0], &edge[1]);
                pop_matrix();
                pad_4A4->vfunc_6(&edge[0], &edge[1]);
            }
            update_attack_child();
            if (is_passing_frame(10.8f) != 0) {
                play_sound_effect(remap_sound_for_area(0x4003A30C), &position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
            if (get_flag_b4() != 0) {
                requested_action = 0;
                pad_4B0 = 1;
                pad_4AC = 0;
            }
            break;
        case 1:
            pad_4AC++;
            if ((f32)pad_4AC >= TObjEneDf2Bringer__data_805D4FB4->slash_recover_frames) {
                pad_4B0 = 2;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        break;
    }
}

// The stagger after a charge that hit something: sparks alternate between the two front
// points until stagger_frames run out.
void TObjEneDf2Bringer::action(s32 mode) {
    switch (mode) {
    case 4:
        requested_action = 8;
        set_field_378(7);
        pad_4C4 = NULL;
        return;
    case 3:
        if (pad_484 <= 0) {
            transition_enemy_state(4);
        }
        return;
    case 0:
        advance_animation();
        pad_484--;
        if (pad_4C4 == NULL) {
            pad_4C4 = create_particle_emitter(&pad_450[0], 0x100);
            if (pad_4C4 != NULL) {
                pad_4C4->enable();
            }
        } else if (pad_484 & 1) {
            pad_4C4->set_position(&pad_450[0]);
        } else {
            pad_4C4->set_position(&pad_450[1]);
        }
        update_ground_contact();
        check_collisions();
        play_persistent_sound(remap_sound_for_area(0x4003AD0F), (saddr)this, (uaddr)&position, 0, 0);
        return;
    case 5:
        if (pad_4C4 != NULL) {
            pad_4C4->queue_destruction();
            pad_4C4 = NULL;
        }
        break;
    }
}

// The shot: drains the TP of the players it sees (attack_visible_players), turns to the
// farthest one and fires a shot whose speed grows with the TP drained (shot_speed, x1.5
// above 70, x2 above 150); in v2 it fires up to three times.
void TObjEneDf2Bringer::sub_80097820(s32 mode) {
    TParticleCtrl *e;
    switch (mode) {
    case 4:
        requested_action = 9;
        set_field_378(4);
        pad_3C0 &= ~3;
        pad_3C0 |= 4;
        pad_4AC = 0;
        pad_4B0 = 0;
        pad_4B4 = 0;
        pad_4B8 = 0;
        pad_4C4 = NULL;
        break;
    case 3:
        if (pad_4AC == 4) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        switch (pad_4AC) {
        case 0:
            if (get_flag_b4() != 0) {
                if (sub_80098FF4() != 0) {
                    enemy_copy_target_destination();
                    update_velocity();
                    pad_4B8 = (u16)(s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
                    pad_4AC = 1;
                    requested_action = 1;
                } else {
                    pad_4AC = 4;
                }
            } else {
                if (is_passing_frame(8.0f) != 0) {
                    Vec v = position;
                    v.y += 8.0f;
                    new TUnk_8048FE7C(this, &v, 100.0f);
                }
                if (is_passing_frame(12.0f) != 0) {
                    pad_4B4 = attack_visible_players();
                    play_sound_effect(remap_sound_for_area(0x4003B20B), &position, 0, 0);
                }
                if ((e = pad_4C4) == NULL) {
                    pad_4C4 = create_particle_emitter(&pad_450[3], 0xEB);
                    if (pad_4C4 != NULL) {
                        pad_4C4->enable();
                    }
                } else if (frame < 11.0f || frame > 28.0f) {
                    e->enable();
                } else {
                    e->set_position(&pad_450[3]);
                }
            }
            break;
        case 1:
            rotation_y = approach_angle_limited(rotation_y, pad_4B8, 0x300);
            if ((u16)rotation_y == pad_4B8) {
                pad_4AC = 2;
                requested_action = 5;
                play_sound_effect(remap_sound_for_area(0x4003A80A), &position, 0, 0);
            }
            if (pad_4C4 != NULL) {
                pad_4C4->queue_destruction();
                pad_4C4 = NULL;
            }
            sub_80098EB4();
            break;
        case 2:
            if (get_flag_b4() != 0) {
                if (TObjEneDD::check_v2_mode() != 0) {
                    pad_4B0++;
                    if (pad_4B0 < 3) {
                        if (sub_80098FF4() != 0) {
                            enemy_copy_target_destination();
                            update_velocity();
                            pad_4B8 = (u16)(s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
                            pad_4AC = 1;
                            requested_action = 1;
                        } else {
                            pad_4AC = 4;
                        }
                    } else {
                        pad_4B0 = 0;
                        pad_4AC = 3;
                        pad_494 = 0;
                        pad_488 = 1;
                        pad_3C0 &= ~8;
                    }
                } else {
                    pad_4AC = 3;
                    pad_494 = 0;
                    pad_488 = 1;
                    pad_3C0 &= ~8;
                }
            }
            if (is_passing_frame(14.0f) != 0) {
                f32 spd = (f32)TObjEneDf2Bringer__data_805D4FB4->shot_speed;
                if (pad_4B4 > 150) {
                    spd *= 2.0f;
                } else if (pad_4B4 > 70) {
                    spd *= 1.5f;
                }
                pad_4A0->setup_dir_shot(&pad_450[2], pad_4B8, spd);
            }
            if ((e = pad_4C4) == NULL) {
                pad_4C4 = create_particle_emitter(&position, 0xED);
                if (pad_4C4 != NULL) {
                    s32 ang[3];
                    ang[0] = 0;
                    ang[1] = pad_4B8 - 0x4000;
                    ang[2] = -0x4000;
                    pad_4C4->set_flags(2);
                    pad_4C4->set_direction(ang);
                    pad_4C4->enable();
                }
            } else if (frame < 7.0f || frame > 14.0f) {
                e->enable();
            } else {
                e->set_position(&pad_450[2]);
            }
            break;
        case 3:
            pad_4B0++;
            if (pad_4B0 >= 60) {
                pad_4AC = 4;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        pad_3C0 &= ~8;
        pad_494 = 0;
        if (pad_4C4 != NULL) {
            pad_4C4->queue_destruction();
            pad_4C4 = NULL;
        }
        break;
    }
}
void TObjEneDf2Bringer::sub_80097714(s32 mode) {
    Vec v;
    f32 speed;
    switch (mode) {
    case 4:
        this->requested_action = 6;
        this->advance_animation();
        this->set_active();
        break;
    case 3:
        if (this->get_flag_b4() != 0 && this->check_stage_advance() == 0) {
            this->transition_enemy_state(this->next_mode);
        }
        break;
    case 0:
        this->advance_animation();
        this->pad_484--;
        // x_speed, y_speed and m_310 are the velocity vector
        VecCopy(&v, (const Vec *)&this->x_speed);
        speed = normalize_vector_xz(&v);
        this->move_clamped_on_ground(v.x, v.z, speed);
        this->x_speed *= 0.8f;
        this->m_310 *= 0.8f;
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneDf2Bringer::sub_80097620(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xA;
        this->pad_3C0 &= ~3;
        this->pad_3C0 |= 2;
        this->disable_body_collision();
        this->refresh_and_send_entity_flags();
        fn_800D911C(&this->body_center);
        TObjPlayer__sub_800A04F0(&this->pad_3C4);
        play_sound_effect(this->remap_sound_for_area(0x4003A511), &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        return;
    case 0:
        this->advance_animation();
        if (this->pad_3C4.decay_value_toward_floor() != 0) {
            TObjPlayer::apply_effect_variant_b((saddr)&this->position, 0);
            this->queue_destruction();
        }
    case 3:
    case 5:
        return;
    }
}

void bringer_render_node_callback(NJS_OBJECT *) {
    Vec *pos;
    switch (TObjEneDf2Bringer__render_node_index) {
    case 8:
        rotate_matrix_x(0, TObjEneDf2Bringer__render_rotation_x);
        break;
    case 11:
    case 16:
    case 26:
    case 41:
        pos = TObjEneDf2Bringer__render_point_cursor;
        TObjEneDf2Bringer__render_point_cursor = pos + 1;
        forward_transform_to_view((const Vec *)&bringer_camera_ctrl_target_vec, pos);
        break;
    }
    TObjEneDf2Bringer__render_node_index += 1;
}

#pragma push
#pragma opt_loop_invariants off

void TObjEneDf2Bringer::render() {
    s32 detail;
    s32 fading;
    RenderFadeState *fade;
    s32 show;
    uaddr saved_texture;
    s32 view;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    view = 0;
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    if (pad_3C0 & 1) {
        detail = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        detail = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail != 0) {
        {
            Vec v = { 2.0f, 1.0f, 5.0f };
            draw_ground_shadow(&v, 0);
        }
        update_secondary_light();
        TObjEneDf2Bringer__render_node_index = 0;
        TObjEneDf2Bringer__render_rotation_x = pad_480;
        TObjEneDf2Bringer__render_point_cursor = pad_450;
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        fade = &renderFadeStates[view];
        show = 1;
        fade->update();
        fading = fade->updateFromCamera(&body_center.x);
        if (pad_3C0 & 2) {
            pad_3C4.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                show = 0;
            }
        } else if (fading != 0) {
            fade->set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                show = 0;
            }
        }
        scroll_strip_uvs(TObjEneDf2Bringer__uv_scroll_buffer, (s16)pad_4A8, 0);
        TObjFish::set_global_param(texlist);
        {
            NJS_TEXNAME *textures = ((NJS_TEXLIST *)texlist)->textures;
            saved_texture = textures[1].texaddr;
            textures[1].texaddr = textures[pad_488].texaddr;
        }
        if (show != 0) {
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            set_chunk_model_node_callback(bringer_render_node_callback);
            set_motion_packed_rotation();
            if (detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            clear_motion_packed_rotation();
            set_chunk_model_node_callback(NULL);
            pop_matrix();
        }
        if (pad_3C0 & 2) {
            pad_3C4.clear_flag_and_notify();
        } else if (fading != 0) {
            fade->clear_flag_and_notify();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = saved_texture;
        return;
    }
    for (i = 0; i < 4; i++) {
        VecCopy(&pad_450[i], &body_center);
    }
}

#pragma pop

void TObjEneDf2Bringer::run_demo_task() { if (get_target_info() != 0) { sub_800994F8(); } }

void TObjEneDf2Bringer::render_demo() {
    f32 frame;
    s32 i;
    AnimationMotion *mot;
    get_target_info();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        Vec v = { 1.0f, 1.0f, 3.0f };
        draw_ground_shadow(&v, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        i = (s32)parameters[0];
        if (i < 0) {
            i = 0;
        } else if (i >= 11) {
            i = 10;
        }
        mot = motion_list[action_table[i].motion].motion;
        frame = parameters[1];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (mot->frameCount - 1)) {
            frame = (mot->frameCount - 1);
        }
        set_motion_packed_rotation();
        draw_model_motion(model, mot, frame);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
