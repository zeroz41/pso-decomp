#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/StripBufferPair.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/TObjNpcEnemy.h"
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
#include "pso/object/base/TObjBase.h"




#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_801542CC.h"

#include "pso/unk/SampledMotionPoints.h"


#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/vector.h"


#include "pso/enemy/TUnk_8048FE7C.h"

#include "pso/boss/darkfalz/TBoss4Type3.h"

#include "pso/enemy/bringer/TObjEneDf2Bringer_Eff_TpAbsorb1.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"

#include "pso/player/TUnk_804928CC.h"
#include "pso/render/TUnk_80490470.h"

void bringer_render_node_callback(NJS_OBJECT *);
void *bringer_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
// The body (init_model) and the two blade bodies of the attack collider, which the slash moves
// onto the sampled blade points (update_attack_child).
CollisionBody bringer_collision_bodies[3] = {
    { { 0.0f, 20.0f, 8.0f }, 7.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
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
TObjMotionAction bringer_motion_actions[11] = {
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
#include "pso/render/model_render_state.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"

#pragma defer_codegen on



player_stats *bringer_boss_stats_handle;
AttackParams *bringer_boss_stats_ptr_b;
ActorParamBlock *bringer_object_handle;
BringerParameters *TObjEneDf2Bringer__params;
BmlResource *TObjEneDf2Bringer::resource_bundle;
s32 TObjEneDf2Bringer__render_node_index;
s32 TObjEneDf2Bringer__render_rotation_x;
Vec *TObjEneDf2Bringer__render_point_cursor;
SampledMotionPoints *TObjEneDf2Bringer__trail_buffer;
StripBufferPair *TObjEneDf2Bringer__uv_scroll_buffer;

Vec bringer_camera_ctrl_target_vec;





// The slash's contact block, call_vt16_with_default's first argument: the recoil and the bodies
// it tests (bit 0 players, bit 1 enemies; see DragonAttackParams).
struct BringerSlashContact {
    f32 recoil;
    u32 contact_flags;
};



const char *TObjEneDf2Bringer__name = "TObjEneDf2Bringer";








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
    TObjEneDf2Bringer::resource_bundle = load_enemy_bml_resource_named(&bm_ene_df2_bringer_resource_descriptor, "bm_ene_df2_bringer_a.bml");
  }
  else
  {
    TObjEneDf2Bringer::resource_bundle = load_enemy_bml_resource(&bm_ene_df2_bringer_resource_descriptor);
  }
  bringer_boss_stats_handle = TLobby::register_boss(0xD);
  bringer_boss_stats_ptr_b = TLobby::dispatch_shared_handler_b(0xD);
  bringer_object_handle = TLobby::register_object(0xD);
  TObjEneDf2Bringer__params = (BringerParameters *)TLobby::dispatch_shared_handler_a(0xD);
  TObjEneDf2Bringer__render_node_index = 0;
  TObjEneDf2Bringer__render_rotation_x = 0;
  TObjEneDf2Bringer__render_point_cursor = 0;
  TObjEneDf2Bringer::set_entry_value_clamped(4, TObjEneDf2Bringer__params->action4_speed);
  TObjEneDf2Bringer::set_entry_value_clamped(5, TObjEneDf2Bringer__params->action5_speed);
  SampledMotionPoints *sampled = new SampledMotionPoints(4, 7.0f, 14.0f, bringer_motion_actions[4].speed);
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

    sampled->sample(TObjEneDf2Bringer::resource_bundle->models[0].model, (NJS_MOTION *)TObjEneDf2Bringer::resource_bundle->motions[bringer_motion_actions[4].motion].motion, ids, offs);
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
  TObjEneDf2Bringer__uv_scroll_buffer = new StripBufferPair(TObjEneDf2Bringer::resource_bundle->models[0].model, 1);
  init_bringer_effect_tables();
  {
    NpcAnimationBinding sp = { TObjEneDf2Bringer::resource_bundle->motions, bringer_motion_actions, 0, 1, 11 };
    TObjNpcEnemy::register_animated_chunk((s16)0x16, TObjEneDf2Bringer::resource_bundle->models[0].model, TObjEneDf2Bringer::resource_bundle->models[0].texlist, &sp, 7.0f, 0.0f);
  }
}

#pragma pop
void *TObjEneDf2Bringer::create(void *set_data) {
    void *o = new TObjEneDf2Bringer(tl_04, set_data);
    return o;
}

void TObjEneDf2Bringer::free_resources() {
    bringer_effect_cleanup_noop();
    if (TObjEneDf2Bringer__uv_scroll_buffer != NULL) {
        delete TObjEneDf2Bringer__uv_scroll_buffer;
        TObjEneDf2Bringer__uv_scroll_buffer = NULL;
    }
    if (TObjEneDf2Bringer__trail_buffer != NULL) {
        delete TObjEneDf2Bringer__trail_buffer;
        TObjEneDf2Bringer__trail_buffer = NULL;
    }
    if (TObjEneDf2Bringer::resource_bundle != NULL) {
        delete TObjEneDf2Bringer::resource_bundle;
        TObjEneDf2Bringer::resource_bundle = NULL;
    }
}

void TObjEneDf2Bringer::set_entry_value_clamped(s32 index, f32 speed) {
  if (speed < 0.1f)
  {
    speed = 0.1f;
  }
  bringer_motion_actions[index].speed = speed;
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
    this->model = TObjEneDf2Bringer::resource_bundle->models[0].model;
    this->texlist = TObjEneDf2Bringer::resource_bundle->models[0].texlist;
    init_model(bringer_collision_bodies, 1);
    set_action_table(bringer_motion_actions);
    set_motion_list(TObjEneDf2Bringer::resource_bundle->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_requested_action(this->requested_action);
    reset_hp(bringer_boss_stats_handle, bringer_boss_stats_ptr_b, bringer_object_handle);
    set_state_8();
    this->movementParameters = bringer_init_params;
    initialize_enemy_state(0x24);
    this->wall_reach = 20.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    this->status_flags = 0;
    this->status_flags |= 1;
    this->body_fade.reset_obstruction_fade();
    for (i = 0; i < 4; i++) {
        this->renderFadeStates[i].activate_and_dispatch();
    }
    for (i = 0; i < 4; i++) {
        VecCopy(&this->node_points[i], &this->position);
    }
    this->twist_angle = 0;
    this->stagger_timer = 0;
    this->face_texture = 1;
    this->hit_count = 0;
    this->combo_count = 0;
    this->rush_count = 0;
    this->collider = new TUnk_804928CC(this, this, &bringer_collision_bodies[1], 2);
    this->attack_history = new AreaAttackHistory(8);
    this->shot_launcher = new TObjEneDf2Bringer_Eff_TpAbsorb1(this, this, this->attack_history);
    this->attack_trail = TAttackTraceStrip::create(0xFF5050FF, 0x80000080);
    this->texture_scroll = 0;
    this->step = 0;
    this->counter = 0;
    this->drained_tp = 0;
    this->target_angle = 0;
    this->speed = 0.0f;
    this->pad_4C0 = 0.0f;
    this->emitter = NULL;
    this->mode = 1;
    this->dispatch_action(this->mode, 4);
}

TObjEneDf2Bringer::~TObjEneDf2Bringer() {
    if (this->emitter != NULL) {
        this->emitter->queue_destruction();
        this->emitter = NULL;
    }
    this->attack_trail->queue_destruction();
    this->attack_trail = NULL;
    delete this->shot_launcher;
    this->shot_launcher = NULL;
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
        texture_scroll = texture_scroll + 0xC;
        texture_scroll = (u8)texture_scroll;
        hits = hit_count;
        if (hits <= 2) {
            face_texture = 1;
        } else if (hits <= 4) {
            face_texture = 5;
        } else if (hits <= 5) {
            face_texture = 6;
        }
    }
    set_effect_pos_above_self();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneDf2Bringer::refresh_target() {  }

void TObjEneDf2Bringer::run_death_reaction() { if (mode != 10) { TObjEneDD::transition_enemy_state(10); } }

void TObjEneDf2Bringer::run_hit_reaction() {
    if ((mode != 9) && (mode != 8)) {
        retarget_attacker();
    }
    if (status_flags & 4) {
        clear_attack_receipts();
        return;
    }
    if (mode != 9) {
        transition_enemy_state(9);
    }
}

void TObjEneDf2Bringer::run_miss_reaction() {  }

void TObjEneDf2Bringer::set_effect_pos_above_self() {
    VecCopy(&body_center, &position);
    body_center.y += 20.0f;
    VecCopy(&center, &body_center);
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
        BringerSlashContact contact = { 3.0f, 1 };
        if (is_confused() != 0) {
            contact.contact_flags |= 2;
        }
        collider->call_vt16_with_default(&contact, attack_history);
    }
}

// The charge's contact: every player the body touches takes rush_power once per charge.
s32 TObjEneDf2Bringer::check_rush_hits() {
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
            if (obj_is_hit_receivable(player) != 0 && attack_target_history_add(attack_history, player) != 0) {
                DirectAttackPayload h;
                h.kind = 0;
                h.power = TObjEneDf2Bringer__params->rush_power;
                player->receive_direct_attack(this, h, 0, -1, -1);
                if (is_player_entity_id(player->get_entity_id()) != 0) {
                    if (TObjEneDD::check_v2_mode() != 0) {
                        if (TObjPlayer::is_locally_controlled(player) != 0) {
                            TItem *item = (TItem *)TObjPlayer::get_equipped_weapon(player);
                            if (item != NULL) {
                                TObjPlayer::send_6x26_unequip_item((TObjPlayer *)player, item->get_item_id());
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
    rotate_xz_pair_by_angle(&stack.x, &stack.z, rotation_y);
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
    if (!(status_flags & 8)) {
        return update_linked_position(300.0f);
    }
    valid = enemy_validate_retained_target(this);
    if (valid == 0) {
        status_flags &= ~8;
    }
    return valid;
}

// Targets the farthest living player within 300 units that it can see (inferred: the shot's target).
s32 TObjEneDf2Bringer::target_farthest_visible_player() {
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
                id = player->get_entity_id();
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
                player->check_can_act((s16)dmg);
                total += dmg;
                new TUnk_8048FE64(this, &player->body_center, &node_points[3]);
            }
        }
    }
    return total;
}

void TObjEneDf2Bringer::play_move_sound() {
    play_persistent_sound(remap_sound_for_area(0x4003B708), this, &position, 0, 0);
}

s32 TObjEneDf2Bringer::acquire_target(f32 range) {
    if (this->is_confused() != 0) {
        return ((TObjEneDD_ST *)this)->select_and_apply_target(range);
    }
    return select_nearest_target(range);
}

void TObjEneDf2Bringer::retarget_attacker() {
    TObjPlayer *player;
    u16 id;
    id = attacker_id;
    if (id < 0x1000U) {
        player = get_player_by_client_id(id);
        if (player != NULL) {
            set_target_player(player);
        }
        status_flags |= 8;
    }
    hit_count++;
}

s32 TObjEneDf2Bringer::check_stage_advance() {
    if (hit_count >= 5) {
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
        this->update_hidden_state(reason);
        return;
    case 2:
        update_emerge_state(reason);
        return;
    case 3:
        this->update_fade_out_state(reason);
        return;
    case 4:
        update_walk_state(reason);
        return;
    case 5:
        update_rush_state(reason);
        return;
    case 6:
        update_slash_state(reason);
        return;
    case 7:
        update_stagger_state(reason);
        return;
    case 8:
        update_shot_state(reason);
        return;
    case 9:
        this->update_damage_state(reason);
        return;
    case 10:
        this->update_death_state(reason);
    default:
        return;
    }
}

void TObjEneDf2Bringer::handle_state(s32 reason) {
    switch (reason) {
    case 4:
        this->set_field_378(0);
        this->step = 0;
        return;
    case 3:
        this->transition_enemy_state(1);
        return;
    case 0:
        this->step++;
    case 5:
        return;
    }
}

void TObjEneDf2Bringer::update_hidden_state(s32 reason) {
    switch (reason) {
    case 4:
        this->set_field_378(1);
        this->status_flags |= 1;
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

void TObjEneDf2Bringer::update_emerge_state(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(4);
        this->status_flags &= ~1;
        this->status_flags |= 2;
        this->set_intangible();
        this->body_fade.reset_obstruction_fade();
        this->step = 0;
        this->counter = 0;
        play_sound_effect(this->remap_sound_for_area(0x3640D), &this->position, 0, 0);
        VecCopy(&this->position, &this->home_position);
        VecCopy(&this->prev_position, &this->position);
        VecCopy(&this->body_center, &this->position);
        this->hit_count = 0;
        this->combo_count = 0;
        return;
    case 3:
        if (this->counter == 2) {
            this->transition_enemy_state(4);
        }
        return;
    case 0:
        advance_animation();
        this->update_linked_position(300.0f);
        this->step++;
        switch (this->counter) {
        case 0:
            if (this->step > 0x14) {
                this->counter = 1;
                this->requested_action = 3;
                play_sound_effect(this->remap_sound_for_area(0x4003B40E), &this->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
            this->spawn_particle_if_in_band();
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, 1.2f);
            play_move_sound();
            break;
        case 1:
            this->update_if_in_band();
            if (this->get_flag_b4() != 0) {
                this->counter = 2;
            }
            break;
        }
        if (this->body_fade.advance_toward_max() != 0) {
            this->status_flags &= ~2;
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

void TObjEneDf2Bringer::update_fade_out_state(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(3);
        this->status_flags &= ~7;
        this->set_intangible();
        this->step = 0;
        this->counter = 0;
        return;
    case 3:
        if (this->step == 2) {
            this->transition_enemy_state(4);
        } else if (this->step == 3) {
            this->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->step) {
        case 0:
            if (this->update_linked_position(300.0f) != 0) {
                this->step = 2;
            } else {
                this->counter++;
                if (this->counter >= 0x3C) {
                    this->step = 1;
                    this->body_fade.reset_color();
                    this->status_flags |= 2;
                }
            }
            break;
        case 1:
            if (this->body_fade.decay_value_toward_floor() != 0) {
                this->step = 3;
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
void TObjEneDf2Bringer::update_walk_state(s32 reason) {
    f32 t;
    s32 ang;
    BringerParameters *prm;
    switch (reason) {
    case 4:
        requested_action = 1;
        set_field_378(4);
        clear_intangible();
        status_flags &= ~7;
        step = 0;
        break;
    case 3:
        if (current_target == NULL) {
            transition_enemy_state(3);
        } else if (destination_distance >= (f32)TObjEneDf2Bringer__params->rush_distance && rush_count < 2) {
            transition_enemy_state(5);
        } else if (step == 1) {
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
        twist_angle = TObjBoss2Tunnel::turn_toward_angle_limited(rotation_y, twist_angle, ang, 0x200, 0x2000);
        prm = TObjEneDf2Bringer__params;
        if (destination_distance <= (f32)prm->attack_distance) {
            t = destination_direction.z * cos_table_lookup(rotation_y);
            t = (destination_direction.x * sin_table_lookup(rotation_y)) + t;
            if (t >= cos_table_lookup(0x1800)) {
                step = 1;
            }
        } else {
            t = cos_table_lookup(rotation_y);
            move_clamped_on_ground(sin_table_lookup(rotation_y), t, prm->walk_speed);
        }
        check_collisions();
        play_move_sound();
        break;
    }
}

// The charge: runs at rush_speed until it hits a wall, a player or passes its target, then
// staggers for stagger_frames while the speed decays.
void TObjEneDf2Bringer::update_rush_state(s32 reason) {
    Vec d;
    s32 hit;
    switch (reason) {
    case 4:
        requested_action = 7;
        set_field_378(4);
        status_flags &= ~7;
        step = 0;
        counter = 0;
        speed = TObjEneDf2Bringer__params->rush_speed;
        fill_value_array(attack_history);
        set_active();
        break;
    case 3:
        if (step == 3) {
            combo_count = 0;
            rush_count++;
            status_flags &= ~8;
            if (check_stage_advance() == 0) {
                transition_enemy_state(7);
            }
        }
        break;
    case 0:
        advance_animation();
        switch (step) {
        case 0:
            if (is_passing_frame(11.0f) != 0 || is_passing_frame(21.0f) != 0) {
                spawn_offset_particle();
            }
            if (get_flag_b4() != 0) {
                requested_action = 2;
                step = 1;
                status_flags |= 4;
                bodies->flags |= 0x700;
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            rotation_y = approach_angle_limited(rotation_y, (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)), 0x280);
            twist_angle = TObjBoss2Tunnel::turn_toward_angle_limited(rotation_y, twist_angle, rotation_y, 0x200, 0x2000);
            check_collisions();
            break;
        case 1:
            spawn_particle_if_in_band();
            hit = 0;
            if (enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 30.0f * TObjEneDf2Bringer__params->rush_speed) != 0) {
                hit = 1;
            }
            move_clamped_on_ground(destination_direction.x, destination_direction.z, TObjEneDf2Bringer__params->rush_speed);
            if (has_move_failures(1) != 0) {
                hit = 1;
            }
            update_enemy_collision_flags();
            if (bodies->flags & 0x200000) {
                hit = 1;
            }
            if (check_rush_hits() != 0) {
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
                step = 2;
                counter = 0;
                stagger_timer = TObjEneDf2Bringer__params->stagger_frames;
                status_flags &= ~4;
                set_field_378(7);
                play_sound_effect(remap_sound_for_area(0x4003B40E), &position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
            play_persistent_sound(remap_sound_for_area(0x4003AD09), this, &position, 0, 0);
            break;
        case 2:
            counter++;
            if (counter >= 10) {
                requested_action = 3;
                update_if_in_band();
                if (get_flag_b4() != 0) {
                    step = 3;
                }
                speed *= 0.95f;
            }
            if (speed >= 3.0f) {
                check_rush_hits();
            } else {
                check_collisions();
            }
            move_clamped_on_ground(destination_direction.x, destination_direction.z, speed);
            break;
        }
        break;
    case 5:
        status_flags &= ~4;
        bodies->flags &= ~0x700;
        clear_field_388();
        break;
    }
}

#pragma pop
// The slash: sweeps the trail between the sampled blade points and hits through
// update_attack_child, then waits slash_recover_frames.
void TObjEneDf2Bringer::update_slash_state(s32 reason) {
    Vec edge[2];
    s32 angle;
    Vec *points;
    switch (reason) {
    case 4:
        requested_action = 4;
        set_field_378(4);
        status_flags &= ~3;
        status_flags |= 4;
        fill_value_array(attack_history);
        attack_trail->clear_segments();
        step = 0;
        counter = 0;
        rush_count = 0;
        break;
    case 3:
        if (counter == 2) {
            combo_count++;
            if (combo_count >= 2) {
                combo_count = 0;
                status_flags &= ~8;
            }
            if (check_stage_advance() == 0) {
                transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        angle = rotation_y;
        twist_angle = TObjBoss2Tunnel::turn_toward_angle_limited(angle, twist_angle, angle, 0x200, 0x2000);
        switch (counter) {
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
                attack_trail->add_segment(&edge[0], &edge[1]);
            }
            update_attack_child();
            if (is_passing_frame(10.8f) != 0) {
                play_sound_effect(remap_sound_for_area(0x4003A30C), &position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
            if (get_flag_b4() != 0) {
                requested_action = 0;
                counter = 1;
                step = 0;
            }
            break;
        case 1:
            step++;
            if ((f32)step >= TObjEneDf2Bringer__params->slash_recover_frames) {
                counter = 2;
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
void TObjEneDf2Bringer::update_stagger_state(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 8;
        set_field_378(7);
        emitter = NULL;
        return;
    case 3:
        if (stagger_timer <= 0) {
            transition_enemy_state(4);
        }
        return;
    case 0:
        advance_animation();
        stagger_timer--;
        if (emitter == NULL) {
            emitter = create_particle_emitter(&node_points[0], 0x100);
            if (emitter != NULL) {
                emitter->enable();
            }
        } else if (stagger_timer & 1) {
            emitter->set_position(&node_points[0]);
        } else {
            emitter->set_position(&node_points[1]);
        }
        update_ground_contact();
        check_collisions();
        play_persistent_sound(remap_sound_for_area(0x4003AD0F), this, &position, 0, 0);
        return;
    case 5:
        if (emitter != NULL) {
            emitter->queue_destruction();
            emitter = NULL;
        }
        break;
    }
}

// The shot: drains the TP of the players it sees (attack_visible_players), turns to the
// farthest one and fires a shot whose speed grows with the TP drained (shot_speed, x1.5
// above 70, x2 above 150); in v2 it fires up to three times.
void TObjEneDf2Bringer::update_shot_state(s32 reason) {
    TParticleCtrl *e;
    switch (reason) {
    case 4:
        requested_action = 9;
        set_field_378(4);
        status_flags &= ~3;
        status_flags |= 4;
        step = 0;
        counter = 0;
        drained_tp = 0;
        target_angle = 0;
        emitter = NULL;
        break;
    case 3:
        if (step == 4) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        switch (step) {
        case 0:
            if (get_flag_b4() != 0) {
                if (target_farthest_visible_player() != 0) {
                    enemy_copy_target_destination();
                    update_velocity();
                    target_angle = (u16)(s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
                    step = 1;
                    requested_action = 1;
                } else {
                    step = 4;
                }
            } else {
                if (is_passing_frame(8.0f) != 0) {
                    Vec v = position;
                    v.y += 8.0f;
                    new TUnk_8048FE7C(this, &v, 100.0f);
                }
                if (is_passing_frame(12.0f) != 0) {
                    drained_tp = attack_visible_players();
                    play_sound_effect(remap_sound_for_area(0x4003B20B), &position, 0, 0);
                }
                if ((e = emitter) == NULL) {
                    emitter = create_particle_emitter(&node_points[3], 0xEB);
                    if (emitter != NULL) {
                        emitter->enable();
                    }
                } else if (frame < 11.0f || frame > 28.0f) {
                    e->enable();
                } else {
                    e->set_position(&node_points[3]);
                }
            }
            break;
        case 1:
            rotation_y = approach_angle_limited(rotation_y, target_angle, 0x300);
            if ((u16)rotation_y == target_angle) {
                step = 2;
                requested_action = 5;
                play_sound_effect(remap_sound_for_area(0x4003A80A), &position, 0, 0);
            }
            if (emitter != NULL) {
                emitter->queue_destruction();
                emitter = NULL;
            }
            play_move_sound();
            break;
        case 2:
            if (get_flag_b4() != 0) {
                if (TObjEneDD::check_v2_mode() != 0) {
                    counter++;
                    if (counter < 3) {
                        if (target_farthest_visible_player() != 0) {
                            enemy_copy_target_destination();
                            update_velocity();
                            target_angle = (u16)(s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
                            step = 1;
                            requested_action = 1;
                        } else {
                            step = 4;
                        }
                    } else {
                        counter = 0;
                        step = 3;
                        hit_count = 0;
                        face_texture = 1;
                        status_flags &= ~8;
                    }
                } else {
                    step = 3;
                    hit_count = 0;
                    face_texture = 1;
                    status_flags &= ~8;
                }
            }
            if (is_passing_frame(14.0f) != 0) {
                f32 spd = (f32)TObjEneDf2Bringer__params->shot_speed;
                if (drained_tp > 150) {
                    spd *= 2.0f;
                } else if (drained_tp > 70) {
                    spd *= 1.5f;
                }
                shot_launcher->setup_dir_shot(&node_points[2], target_angle, spd);
            }
            if ((e = emitter) == NULL) {
                emitter = create_particle_emitter(&position, 0xED);
                if (emitter != NULL) {
                    s32 ang[3];
                    ang[0] = 0;
                    ang[1] = target_angle - 0x4000;
                    ang[2] = -0x4000;
                    emitter->set_flags(2);
                    emitter->set_direction(ang);
                    emitter->enable();
                }
            } else if (frame < 7.0f || frame > 14.0f) {
                e->enable();
            } else {
                e->set_position(&node_points[2]);
            }
            break;
        case 3:
            counter++;
            if (counter >= 60) {
                step = 4;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        status_flags &= ~8;
        hit_count = 0;
        if (emitter != NULL) {
            emitter->queue_destruction();
            emitter = NULL;
        }
        break;
    }
}
void TObjEneDf2Bringer::update_damage_state(s32 reason) {
    Vec v;
    f32 speed;
    switch (reason) {
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
        this->stagger_timer--;
        // velocity.x, velocity.y and velocity.z are the velocity vector
        VecCopy(&v, (const Vec *)&this->velocity.x);
        speed = normalize_vector_xz(&v);
        this->move_clamped_on_ground(v.x, v.z, speed);
        this->velocity.x *= 0.8f;
        this->velocity.z *= 0.8f;
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneDf2Bringer::update_death_state(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 0xA;
        this->status_flags &= ~3;
        this->status_flags |= 2;
        this->disable_body_collision();
        this->refresh_and_send_entity_flags();
        fn_800D911C(&this->body_center);
        body_fade.start_fade_out();
        play_sound_effect(this->remap_sound_for_area(0x4003A511), &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        return;
    case 0:
        this->advance_animation();
        if (this->body_fade.decay_value_toward_floor() != 0) {
            TObjPlayer::apply_effect_variant_b(&this->position, 0);
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
    GinjaTextureState *saved_texture;
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
    if (status_flags & 1) {
        detail = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        detail = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
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
        TObjEneDf2Bringer__render_rotation_x = twist_angle;
        TObjEneDf2Bringer__render_point_cursor = node_points;
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        fade = &renderFadeStates[view];
        show = 1;
        fade->update();
        fading = fade->updateFromCamera(&body_center.x);
        if (status_flags & 2) {
            body_fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                show = 0;
            }
        } else if (fading != 0) {
            fade->set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                show = 0;
            }
        }
        TObjEneDf2Bringer__uv_scroll_buffer->scroll_uvs(texture_scroll, 0);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        {
            NJS_TEXNAME *textures = reinterpret_cast<NJS_TEXLIST *>(texlist)->textures;
            saved_texture = textures[1].texture;
            textures[1].texture = textures[face_texture].texture;
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
        if (status_flags & 2) {
            body_fade.clear_flag_and_notify();
        } else if (fading != 0) {
            fade->clear_flag_and_notify();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        reinterpret_cast<NJS_TEXLIST *>(texlist)->textures[1].texture = saved_texture;
        return;
    }
    for (i = 0; i < 4; i++) {
        VecCopy(&node_points[i], &body_center);
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
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
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
