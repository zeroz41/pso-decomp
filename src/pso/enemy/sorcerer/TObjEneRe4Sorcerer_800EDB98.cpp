#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"

#include "pso/object/base/TObjChara.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"

#include "pso/render/RenderFadeState.h"

#include "pso/system/task/TObject.h"

#include "pso/unk/TLobby.h"

#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer.h"

#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

#include "pso/player/TObjPlayer_800D8FDC.h"

#include "pso/system/vector.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/math/AngleLookup.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/player/TObjPlayer_80011014.h"

#include "types.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/AreaSound.h"

#include "pso/map/FloorArea.h"

#include "pso/system/BmlResource.h"

#include "pso/system/BmlResourceDescriptor.h"

#include "pso/math/AngleUnits.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/enemy/sorcerer/TObjEneRe4Bit.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/render/TUnk_80490470.h"
#include "pso/object/base/TObjBase.h"
extern "C" {









}

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"

#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/enemy/berura/TObjEneRe7Berura.h"


#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecGiZonde.h"

#include "pso/technique/TTecGrants.h"

#include "pso/technique/TTecMegid.h"

#include "pso/technique/TTecRaFoie.h"

#include "pso/technique/TTecResta.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/render_util.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_801E3F14.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/StripBufferPair.h"
extern "C" {












































}



extern "C" {





Vec lbl_80501070;







TObjEneRe4InitParams re4_sorcerer_init_params = {225.0f, 0.0f, 0x600};

CollisionBody re4_sorcerer_collision_body_part_table[1] = {
    {{0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *bm_ene_re4_sorcerer_model_names[3] = {
    "re4_b_sorcer_body.nj",
    "re4_b_bit.nj",
    NULL
};

const char *bm_ene_re4_sorcerer_motion_names[9] = {
    "attack2_re4_b_body.njm",
    "attack3_re4_b_body.njm",
    "attack1_re4_b_body.njm",
    "cure_re4_b_body.njm",
    "damage_re4_b_body.njm",
    "die_re4_b_body.njm",
    "enter_re4_b_body.njm",
    "wait_re4_b_body.njm",
    NULL
};

BmlResourceDescriptor bm_ene_re4_sorcerer_resource_descriptor = {
    "bm_ene_re4_sorcerer.bml", bm_ene_re4_sorcerer_model_names, bm_ene_re4_sorcerer_motion_names, 2, 8
};

TObjMotionAction re4_sorcerer_action_params[8] = {
    {1, 0, 7, 0.6f, 0},
    {2, 2, 2, 0.6f, 0},
    {1, 0, 0, 0.6f, ACTION_NO_BLEND_IN},
    {3, 0, 1, 0.7f, 0},
    {3, 0, 3, 0.5f, 0},
    {3, 0, 4, 0.6f, 0},
    {3, 0, 5, 0.5f, 0},
    {2, 0, 6, 0.6f, ACTION_NO_BLEND_IN},
};

// inferred: TObjEneRe4Sorcerer__name, from the string it holds (the ctor stores it as the object's m_name).
const char *TObjEneRe4Sorcerer__name = "TObjEneRe4Sorcerer";

const NpcAnimationBinding re4_sorcerer_spawn_descriptor = { NULL, re4_sorcerer_action_params, 0, 0, 8 };
}

player_stats *TObjEneRe4Sorcerer__base_params;

AttackParams *TObjEneRe4Sorcerer__attack_params;

ActorParamBlock *TObjEneRe4Sorcerer__resistance_params;

s32 *sorcerer_behavior_params;

BmlResource *sorcerer_bml_resource;

s32 TObjEneRe4Sorcerer__render_node_index;

s32 TObjEneRe4Sorcerer__saved_render_flags;

f32 TObjEneRe4Sorcerer__effect_render_scale;

Vec *re4_sorcerer_render_node_ptr;

StripBufferPair *TObjEneRe4Sorcerer__uv_scroll_buffer;

NJS_ARGB *MaterialColorFade::get_color() {
    return &color;
}

void TObjEneRe4Sorcerer::load_resources() {
    uaddr r;
    lbl_80501070.x = 0.0f;
    lbl_80501070.y = 0.0f;
    lbl_80501070.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        sorcerer_bml_resource = (BmlResource *)load_enemy_bml_resource_named(&bm_ene_re4_sorcerer_resource_descriptor, "bm_ene_re4_sorcerer_a.bml");
    } else {
        sorcerer_bml_resource = (BmlResource *)load_enemy_bml_resource(&bm_ene_re4_sorcerer_resource_descriptor);
    }
    TObjEneRe4Sorcerer__base_params = TLobby::register_boss(0xA);
    TObjEneRe4Sorcerer__attack_params = TLobby::dispatch_shared_handler_b(0xA);
    TObjEneRe4Sorcerer__resistance_params = TLobby::register_object(0xA);
    sorcerer_behavior_params = (s32 *)TLobby::dispatch_shared_handler_a(0xA);
    TObjEneRe4Sorcerer__render_node_index = 0;
    TObjEneRe4Sorcerer__saved_render_flags = 0;
    TObjEneRe4Sorcerer__effect_render_scale = 0.0f;
    re4_sorcerer_render_node_ptr = NULL;
    TObjEneRe4Bit::load_resources();
    TObjEneRe4Sorcerer__uv_scroll_buffer = new StripBufferPair(sorcerer_bml_resource->models->model, 2);
    NpcAnimationBinding p = re4_sorcerer_spawn_descriptor;
    p.motions = sorcerer_bml_resource->motions;
    TObjNpcEnemy::register_animated_chunk((s16)0x2A, sorcerer_bml_resource->models->model, sorcerer_bml_resource->models->texlist, &p, re4_sorcerer_collision_body_part_table[0].radius, 15.0f);
}

TObjEneRe4Sorcerer *TObjEneRe4Sorcerer::create() {
    return new TObjEneRe4Sorcerer((TObject *)tl_04, this);
}

void TObjEneRe4Sorcerer::free_bits() {
    if (TObjEneRe4Sorcerer__uv_scroll_buffer != NULL) {
        delete TObjEneRe4Sorcerer__uv_scroll_buffer;
        TObjEneRe4Sorcerer__uv_scroll_buffer = NULL;
    }
    TObjEneRe4Bit::free_resources();
    if ((uaddr) sorcerer_bml_resource != 0U) {
        delete (BmlResource *)sorcerer_bml_resource;
        sorcerer_bml_resource = 0U;
    }
}

TObjEneRe4Sorcerer::TObjEneRe4Sorcerer(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    m_name = TObjEneRe4Sorcerer__name;
    invoke_initialization_hook(set_data);
    sub_800EFE30();
    init_enemy();
}

#pragma push
#pragma opt_loop_invariants off
extern "C" {
void TObjEneRe4Sorcerer::init_enemy() {
    s32 i;
    u16 id;
    s32 t;
    s32 n;
    BmlModelEntry *models;

    init_position_vectors();
    model = (void *)sorcerer_bml_resource->models->model;
    models = sorcerer_bml_resource->models;
    texlist = models->texlist;
    this->init_model(re4_sorcerer_collision_body_part_table, 1);
    set_action_table(re4_sorcerer_action_params);
    set_motion_list(sorcerer_bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    reset_hp(TObjEneRe4Sorcerer__base_params, TObjEneRe4Sorcerer__attack_params, TObjEneRe4Sorcerer__resistance_params);
    set_state_8();
    movementParameters = &re4_sorcerer_init_params;
    initialize_enemy_state(0x1F);
    wall_reach = 15.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    set_active();
    mode = 0;
    dispatch_action(mode, 4);
    strip_scroll = 0;
    texture_scroll = 0.0f;
    behavior_flags = 0;
    behavior_flags &= ~2;
    for (i = 0; i < 2; i++) {
        VecCopy(&bit_anchors[i], &position);
    }
    id = entity_id + 1;
    n = set_index + 1;
    bit_ids[0] = id;
    create_disabled(&bit_anchors[0], id++, n++);
    bit_ids[1] = id;
    create_enabled(&bit_anchors[1], id, n);
    attack_cycle = 0;
    warp_count = 0;
    warp_angle = 0;
    pad_3f4 = evp;
    effect_scale = 1.0f;
    fade.reset_obstruction_fade();
    clear_target_cursor_list(&targets);
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    disable_hits();
}
}

#pragma pop
extern "C" {
TObjEneRe4Sorcerer::~TObjEneRe4Sorcerer() {
    s32 i;
    void *p;
    for (i = 0; i < 2; i++) {
        if ((p = find_entity_by_id(bit_ids[i])) != NULL) {
            ((TObject *)p)->queue_destruction();
        }
        bit_ids[i] = 0xFFFF;
    }
    free_collision_body_parts(this);
}

void TObjEneRe4Sorcerer::run_task() {
    s32 i;
    void *p;
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    if (update_status_effects() != 4) {
        if (is_enemy_entity_id(target_id) != 0 && find_entity_by_id(target_id) == NULL) {
            ((TObjEneDD_ST *)(this))->enemy_clear_target();
        }
        update_action_state();
        calc_orb_positions();
        strip_scroll += 5;
        strip_scroll = (u8)strip_scroll;
        texture_scroll += 0.01f;
        if (texture_scroll >= 1.0f) {
            texture_scroll -= 1.0f;
        }
    } else {
        for (i = 0; i < 2; i++) {
            if ((p = find_entity_by_id(bit_ids[i])) != NULL) {
                ((TObjEneRe4Bit *)p)->set_flag3cc_bit2000();
            }
        }
    }
    update_collision_center();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneRe4Sorcerer::refresh_target() {  }

void TObjEneRe4Sorcerer::run_death_reaction() {
    if (mode != 9) {
        transition_enemy_state(9);
    }
}

void TObjEneRe4Sorcerer::run_hit_reaction() {
    if (mode != 8) {
        if (!(behavior_flags & 8)) {
            transition_enemy_state(8);
            return;
        }
        clear_attack_receipts();
    }
}

void TObjEneRe4Sorcerer::run_miss_reaction() {  }

void TObjEneRe4Sorcerer::update_collision_center() {
    body_center.x = position.x;
    body_center.y = 22.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}

void TObjEneRe4Sorcerer::update_body_colliders() {
    bodies->offset.y = 22.0f;
}

void TObjEneRe4Sorcerer::sub_800EFE30() {  }

CsnHit *TObjEneRe4Sorcerer::move_xz_on_ground(const Vec *dest) {
    CsnHit *ground = TObjEneDD::move_xz_on_ground(dest);
    if (ground == NULL) {
        this->behavior_flags &= ~0x10;
    } else {
        this->behavior_flags |= 0x10;
    }
    return ground;
}

CsnHit *TObjEneRe4Sorcerer::update_ground_contact() {
    CsnHit *ground = TObjEneDD::update_ground_contact();
    if (ground == NULL) {
        this->behavior_flags &= ~0x10;
    } else {
        this->behavior_flags |= 0x10;
    }
    return ground;
}
}

#pragma push
#pragma opt_loop_invariants off
extern "C" {
s32 TObjEneRe4Sorcerer::select_attack_target(f32 ranger_range_sq, f32 range_sq) {
    f32 d;
    f32 best;
    s32 first;
    u16 id;
    TObjChara *p;
    s32 n;
    int i;
    void *o1;
    void *o2;
    if (this->is_confused() != 0) {
        best = range_sq;
        id = 0xFFFF;
        o1 = find_entity_by_id(this->bit_ids[0]);
        o2 = find_entity_by_id(this->bit_ids[1]);
        first = TLobby::get_game_mode();
        n = first + TObjEneDD::get_enemy_count();
        for (i = first; i < n; i++) {
            p = (TObjChara *)TObjPlayer::get_player_data(i);
            if (p != this && p != o1 && p != o2 && ((TObjBase *)p)->is_alive() != 0) {
                d = horizontal_distance_squared(&this->body_center, &p->position);
                if (d < best && csnLookAt(&this->body_center, &p->body_center) == 0) {
                    id = p->get_entity_id();
                    best = d;
                }
            }
        }
        if (enemy_bind_or_clear_target(this, id) != 0) {
            return 1;
        }
    }
    {
    TObjChara *q; u16 tA; u16 tB; s32 j; s32 m; f32 e;
    tA = 0xFFFF;
    tB = tA;
    m = TLobby::get_game_mode();
    for (j = 0; j < m; j++) {
        q = (TObjChara *)TObjPlayer::get_player_data(j);
        if (((TObjBase *)q)->is_alive() != 0) {
            e = horizontal_distance_squared(&this->body_center, &q->body_center);
            if (is_target_ranger(q) != 0) {
                if (e < ranger_range_sq && is_target_unobstructed_from((TObjEneDD *)this, (TObjChara *)q) != 0) {
                    ranger_range_sq = e;
                    tA = q->get_entity_id();
                }
            } else if (e < range_sq && is_target_unobstructed_from((TObjEneDD *)this, (TObjChara *)q) != 0) {
                range_sq = e;
                tB = q->get_entity_id();
            }
        }
    }
    if (tA != 0xFFFF) {
        enemy_set_target_id(this, tA);
        return 1;
    }
    if (tB != 0xFFFF) {
        enemy_set_target_id(this, tB);
        return 1;
    }
    }
    ((TObjEneDD_ST *)(this))->enemy_clear_target();
    return 0;
}
}

#pragma pop
extern "C" {
s32 TObjEneRe4Sorcerer::try_attack(f32 ranger_range_sq, f32 range_sq) {
    if (tick_period_counter((saddr)this, &acquire_counter, 0x1E) != 0) {
        return select_attack_target(ranger_range_sq, range_sq);
    }
    if (enemy_has_live_target() != 0) {
        return 1;
    }
    ((TObjEneDD_ST *)(this))->enemy_clear_target();
    return 0;
}

void TObjEneRe4Sorcerer::warp_around_target(f32 speed) {
    s32 i;
    Vec out;
    Vec v;
    Vec t;
    TObjEneRe4Bit *bit;
    this->enemy_copy_target_destination();
    this->update_velocity();
    v.x = speed * sin_table_lookup(this->warp_angle);
    v.y = 0.0f;
    v.z = speed * cos_table_lookup(this->warp_angle);
    vec3_add_to(&v, &this->destination);
    subtract_vector(&v, &this->position);
    speed = normalize_vector_xz(&v);
    calc_wall_clamped_destination(this, &out, v.x, v.z, speed);
    t.x = out.x;
    t.y = 10.0f + out.y;
    t.z = out.z;
    if (csnVectorUnder(&t, this->ground_candidates.groups, 0xE0) == 0) {
        VecCopy(&this->position, &out);
    }
    this->update_ground_contact();
    VecCopy(&this->prev_position, &this->position);
    this->update_collision_center();
    this->rotation_y = this->warp_angle + 0x8000;
    this->calc_orb_positions();
    this->warp_angle += 0x2AAA;
    this->transform_part_positions();
    for (i = 0; i < 2; i++) {
        bit = (TObjEneRe4Bit *)find_entity_by_id(this->bit_ids[i]);
        if (bit != NULL) {
            bit->reset_transform();
        }
    }
}

void TObjEneRe4Sorcerer::set_motion_by_state() {
    if (this->attack_cycle != 2) {
        this->transition_enemy_state(5);
        return;
    }
    this->transition_enemy_state(7);
}

void TObjEneRe4Sorcerer::request_death_effect() {
    if (attack_cycle != 2) {
        transition_enemy_state(4);
        return;
    }
    transition_enemy_state(6);
}

void TObjEneRe4Sorcerer::advance_anim_frame() {
    attack_cycle = attack_cycle + 1;
    if (attack_cycle >= 3) {
        attack_cycle = 0;
    }
}

void TObjEneRe4Sorcerer::disable_hits() {
    s32 i;
    this->set_invulnerable();
    this->disable_body_collision();
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(this->bit_ids[i]);
        if (bit != NULL) {
            bit->invoke_state_callbacks();
        }
    }
}

void TObjEneRe4Sorcerer::enable_hits() {
    s32 i;
    this->clear_invulnerable();
    this->enable_body_collision();
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(this->bit_ids[i]);
        if (bit != NULL) {
            bit->call_vt_90_91();
        }
    }
}

s32 TObjEneRe4Sorcerer::check_shield(TObjChara *target) {
    if (TObjEneDD::check_v2_mode() != 0) {
        return target->hp < target->get_hpmax();
    }
    return target->hp < (target->get_hpmax() / 4);
}

s32 TObjEneRe4Sorcerer::update_farthest_target(TObjChara *player, f32 *farthest) {
    f32 distance;
    if (player->is_alive() != 0 && check_shield(player) != 0) {
        distance = horizontal_distance_squared(&position, &player->position);
        if ((distance <= 40000.0f) && (distance > *farthest)) {
            *farthest = distance;
            target_id = player->get_entity_id();
            current_target = player;
            return 1;
        }
    }
    return 0;
}

void TObjEneRe4Sorcerer::set_photon_state() {
    TObjEneRe4Bit *bit;
    if (attack_cycle == 0) {
        bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            bit->set_state_flag_and_mode(0);
        }
    } else {
        bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            bit->set_state_flag_and_mode(1);
        }
    }
}

void TObjEneRe4Sorcerer::apply_mylla_effect() {
    TObjEneRe4Bit *bit;
    bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[1]);
    if (bit != NULL) {
        bit->set_state_flag_and_mode(2);
    }
}

void TObjEneRe4Sorcerer::calc_orb_positions() {
    f32 offset_z;
    f32 offset_x;

    offset_x = 15.0f * cos_table_lookup(rotation_y);
    offset_z = 15.0f * -sin_table_lookup(rotation_y);
    bit_anchors[1].x = position.x + offset_x;
    bit_anchors[1].y = 18.0f + position.y;
    bit_anchors[1].z = position.z + offset_z;
    bit_anchors[0].x = position.x - offset_x;
    bit_anchors[0].y = 18.0f + position.y;
    bit_anchors[0].z = position.z - offset_z;
}

void TObjEneRe4Sorcerer::turn_to_target() {
    enemy_copy_target_destination();
    update_velocity();
    rotation_y = approach_angle_limited(rotation_y, (saddr)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z)), 0xA00);
}

s32 TObjEneRe4Sorcerer::cast_technique() {
    Vec v;
    s32 frame;
    Vec *src;
    if (is_target_unobstructed_from((TObjEneDD *)this, current_target) != 0) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            src = bit->get_spell_data();
        } else {
            src = &position;
        }
        if (attack_cycle == 0) {
            clear_target_cursor_list(&targets);
            targets.count = 1;
            targets.records[0].id = current_target->get_entity_id();
            targets.records[0].flag = 0;
            if (TObjEneDD::check_v2_mode() != 0) {
                TTecGrants::create(this, src, &targets, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            } else if (TLobby::get_instance() == 1) {
                TTecGiZonde::create(this, src, &targets, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            } else {
                TTecRaFoie::create_ex(this, src, &targets, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            }
        } else if (TObjEneDD::check_v2_mode() != 0) {
            TTecMegid::create((saddr)this, (saddr)src, (saddr)&current_target->position, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[7]));
        } else {
            VecCopy(&v, &current_target->position);
            subtract_vector(&v, src);
            frame = TObjEneDD::clamp_frame_index(sorcerer_behavior_params[7]);
            TTecGiBarta::create_ex(this, src, (s32)(RADIANS_TO_ANGLE * atan2_float(v.x, v.z)), frame);
        }
        return 1;
    }
    return 0;
}

s32 TObjEneRe4Sorcerer::cast_resta() {
    Vec *spell_data;

    if (current_target->is_alive() != 0) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            spell_data = bit->get_spell_data();
        } else {
            spell_data = &position;
        }
        TTecResta::create(this, spell_data, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[8]));
        return 1;
    }
    return 0;
}

void TObjEneRe4Sorcerer::create_effect() {
    if (attack_cycle == 0) {
        play_persistent_sound(remap_sound_for_area(0x4003A812), this, &position, 0, 0);
        return;
    }
    play_persistent_sound(remap_sound_for_area(0x4003AB13), this, &position, 0, 0);
}

void TObjEneRe4Sorcerer::sub_800EF214() {
    play_persistent_sound(this->remap_sound_for_area(0x4003A81D), this, &this->position, 0, 0);
}

void TObjEneRe4Sorcerer::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_state(reason);
        return;
    case 1:
        update_hidden_state(reason);
        return;
    case 2:
        update_enter_state(reason);
        return;
    case 3:
        update_fade_out_state(reason);
        return;
    case 4:
        state_wait(reason);
        return;
    case 5:
        update_attack_state(reason);
        return;
    case 6:
        update_state_machine(reason);
        return;
    case 7:
        update_cure_state(reason);
        return;
    case 8:
        update_damage_state(reason);
        return;
    case 9:
        handle_death_state(reason);
    default:
        return;
    }
}

void TObjEneRe4Sorcerer::handle_state(s32 mode) {
    switch (mode) {
    case 4:
        state_timer = 0;
        break;
    case 3:
        if (state_timer >= 2) {
            transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        state_timer = state_timer + 1;
        break;
    }
}

void TObjEneRe4Sorcerer::update_hidden_state(s32 reason) {
    switch (reason) {
    case 4:
        ((TObjEneDD *)this)->set_field_378(1);
        VecCopy(&this->position, &this->home_position);
        VecCopy(&this->prev_position, &this->home_position);
        VecCopy(&this->body_center, &this->home_position);
        this->set_intangible();
        return;
    case 3:
        if (this->try_attack(160000.0f, 62500.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->warp_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(-this->destination_direction.x, -this->destination_direction.z));
            warp_around_target(50.0f);
            this->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        this->update_body_colliders();
        break;
    }
}
}

#pragma push
#pragma opt_common_subs off
extern "C" {
void TObjEneRe4Sorcerer::update_enter_state(s32 reason) {
    s32 i;
    TObjEneRe4Bit *bit;

    switch (reason) {
    case 4:
        this->requested_action = 7;
        ((TObjEneDD *)this)->set_field_378(3);
        this->behavior_flags |= 0xE;
        this->clear_intangible();
        disable_hits();
        this->fade.reset_obstruction_fade();
        for (i = 0; i < 2; i++) {
            if ((bit = (TObjEneRe4Bit *)find_entity_by_id(this->bit_ids[i])) != NULL) {
                bit->reset_transform();
                bit->clear_state_flag_0x10();
            }
        }
        this->effect_scale = 0.0f;
        this->state_timer = 0;
        this->state_step = 0;
        play_area_variant_sound(&this->position);
        break;
    case 3:
        if (this->state_timer >= 0x3C) {
            this->set_motion_by_state();
        }
        break;
    case 0:
        if (this->fade.get_color()->a >= -0.75f) {
            this->advance_animation();
            this->turn_to_target();
        }
        switch (this->state_step) {
        case 0:
            if (this->fade.advance_toward_max() != 0) {
                this->state_timer = 0;
                this->state_step = 1;
                this->behavior_flags &= ~4;
                enable_hits();
            }
            break;
        case 1:
            this->state_timer += 1;
            if (this->effect_scale < 1.0f) {
                this->effect_scale += 0.2f;
            }
            this->check_collisions();
            break;
        }
        this->update_ground_contact();
        sub_800EF214();
        break;
    case 5:
        this->effect_scale = 1.0f;
        this->behavior_flags &= ~4;
        break;
    }
}
}

#pragma pop
extern "C" {
void TObjEneRe4Sorcerer::update_fade_out_state(s32 reason) {
    f32 scale;
    s32 i;
    switch (reason) {
    case 4:
        ((TObjEneDD *)this)->set_field_378(3);
        this->clear_intangible();
        disable_hits();
        this->behavior_flags |= 2;
        this->behavior_flags &= 0xFFFFFFF7;
        for (i = 0; i < 2; i++) {
            TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(this->bit_ids[i]);
            if (bit != NULL) {
                bit->set_flag_and_notify();
            }
        }
        this->state_timer = 0;
        this->state_step = 0;
        this->fade.reset_color();
        play_area_variant_sound(&this->position);
        break;
    case 3:
        if (this->state_timer >= 0x1E) {
            this->request_death_effect();
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            scale = this->effect_scale;
            if (scale > 0.0f) {
                this->effect_scale = scale - 0.2f;
                if (this->effect_scale < 0.0f) {
                    this->effect_scale = 0.0f;
                    this->behavior_flags |= 4;
                    this->fade.reset_color();
                }
            } else if (this->fade.decay_value_toward_floor() != 0) {
                this->state_timer = 0;
                this->state_step = 1;
                this->behavior_flags &= 0xFFFFFFF9;
            }
            sub_800EF214();
            break;
        case 1:
            this->state_timer = this->state_timer + 1;
            break;
        }
        this->update_ground_contact();
        break;
    case 5:
        this->behavior_flags &= 0xFFFFFFFB;
        this->effect_scale = 1.0f;
        break;
    }
}

void TObjEneRe4Sorcerer::state_wait(s32 mode) {
    switch (mode) {
    case 4:
        state_timer = 0;
        set_field_378(4);
        behavior_flags &= 0xFFFFFFFD;
        set_intangible();
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        return;
    case 3:
        if (try_attack(160000.0f, 160000.0f) != 0) {
            if (warp_count & 1) {
                warp_around_target(80.0f);
            } else {
                warp_around_target(30.0f);
            }
            transition_enemy_state(2);
            return;
        }
        if (state_timer > 0x5A) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        state_timer = state_timer + 1;
        break;
    }
}

void TObjEneRe4Sorcerer::update_attack_state(s32 reason) {
    s32 step;
    s32 state;
    TObjEneRe4Bit *bit;
    bit = (TObjEneRe4Bit *)find_entity_by_id(this->bit_ids[0]);
    switch (reason) {
    case 4:
        this->requested_action = 0;
        ((TObjEneDD *)this)->set_field_378(3);
        this->behavior_flags |= 0xA;
        this->state_timer = 0;
        this->state_step = 0;
        return;
    case 3:
        if (this->state_step == 5) {
            this->advance_anim_frame();
            this->warp_count = this->warp_count + 1;
            this->transition_enemy_state(3);
        }
        return;
    case 0:
        this->advance_animation();
        this->state_timer = this->state_timer + 1;
        step = this->state_step;
        switch (step) {
        case 0:
            if ((bit != NULL) && (bit->can_cast() != 0)) {
                this->state_timer = 0;
                if (this->try_attack(10000.0f, 10000.0f) == 0) {
                    this->state_step = 4;
                } else {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    if (this->destination_distance >= 100.0f) {
                        this->state_step = 4;
                    } else {
                        this->state_step = 1;
                        this->requested_action = 1;
                        this->behavior_flags |= 8;
                        this->set_photon_state();
                    }
                    this->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
                }
            } else if (this->state_timer >= 0xF0) {
                this->state_step = 5;
            }
            this->turn_to_target();
            this->create_effect();
            break;
        case 1:
            if ((bit != NULL) && (bit->can_cast() == 0)) {
                this->state_step = 5;
            } else if (this->state_timer >= 0x5A) {
                this->requested_action = 3;
                this->state_step = 3;
            }
            this->turn_to_target();
            this->create_effect();
            break;
        case 2:
        case 3:
            if ((this->frame >= 11.0f) && (step == 3)) {
                if (bit != NULL) {
                    state = bit->get_state();
                } else {
                    state = 3;
                }
                switch (state) {
                case 2:
                    this->state_step = 2;
                    this->cast_technique();
                    break;
                case 3:
                    this->state_step = 2;
                    break;
                }
            }
            if (this->get_flag_b4() != 0) {
                this->state_step = 5;
                if (bit != NULL) {
                    bit->set_attack_flag();
                }
            }
            break;
        case 4:
            if (this->state_timer >= 0x3C) {
                this->state_step = 5;
            }
            break;
        case 5:
            break;
        }
        this->check_collisions();
        this->update_body_colliders();
        sub_800EF214();
        return;
    case 5:
        if (bit != NULL) {
            bit->set_attack_flag();
        }
        this->behavior_flags &= 0xFFFFFFF7;
        break;
    }
}

void TObjEneRe4Sorcerer::update_state_machine(s32 reason) {
    f32 *t = &farthest_distance;
    s32 mask;
    s32 n;
    s32 i;
    TObjChara *p;
    s32 j;
    switch (reason) {
    case 4:
        set_field_378(6);
        set_intangible();
        behavior_flags &= ~2;
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        init_float_params();
        if (is_confused() != 0) {
            state_timer = 3;
        } else {
            state_timer = 0;
        }
        state_step = 0;
        *t = 0.0f;
        break;
    case 3:
        if (state_timer == 4) {
            transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        switch (state_timer) {
        case 3:
            mask = 0;
            n = TLobby::get_game_mode();
            *t = 0.0f;
            for (i = 0; i < n; i++) {
                p = (TObjChara *)TObjPlayer::get_player_data(i);
                mask |= update_farthest_target(p, t);
            }
            if (mask != 0) {
                state_timer = 2;
            } else {
                state_timer = 0;
            }
            break;
        case 0:
            if (check_shield(this) != 0) {
                current_target = this;
                state_timer = 2;
            } else {
                state_timer = 1;
            }
            break;
        case 1:
            j = TLobby::get_game_mode();
            n = j + TObjEneDD::get_enemy_count();
            *t = 0.0f;
            for (; j < n; j++) {
                p = (TObjChara *)TObjPlayer::get_player_data(j);
                if (p == this) {
                    continue;
                }
                if (p != 0) {
                    s16 a = p->room;
                    if (a != room) {
                        continue;
                    }
                }
                update_farthest_target(p, t);
            }
            state_timer = 2;
            break;
        case 2:
            if (current_target != 0) {
                warp_around_target(20.0f);
            } else {
                VecCopy(&destination, &position);
                warp_around_target(160.0f);
            }
            state_timer = 4;
            break;
        }
        break;
    }
}

void TObjEneRe4Sorcerer::update_cure_state(s32 reason) {
    s32 step;
    s32 state;
    TObjEneRe4Bit *bit;

    bit = (TObjEneRe4Bit *)find_entity_by_id(this->bit_ids[1]);
    switch (reason) {
    case 4:
        this->requested_action = 0;
        ((TObjEneDD *)this)->set_field_378(3);
        this->behavior_flags |= 0xA;
        this->state_timer = 0;
        this->state_step = 0;
        return;
    case 3:
        if (this->state_step == 5) {
            this->advance_anim_frame();
            this->transition_enemy_state(3);
        }
        return;
    case 0:
        this->advance_animation();
        this->state_timer = this->state_timer + 1;
        step = this->state_step;
        switch (step) {
        case 0:
            if ((bit != NULL) && (bit->can_cast() != 0)) {
                this->state_timer = 0;
                if (this->current_target->is_alive() != 0) {
                    if (this->current_target != this) {
                        this->enemy_copy_target_destination();
                        this->update_velocity();
                        if (this->destination_distance >= 100.0f) {
                            this->state_step = 4;
                        } else {
                            this->state_step = 1;
                            this->requested_action = 1;
                            this->behavior_flags |= 8;
                            this->apply_mylla_effect();
                        }
                        this->rotation_y = (saddr)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
                    } else {
                        this->state_step = 1;
                        this->requested_action = 1;
                        this->behavior_flags |= 8;
                        this->apply_mylla_effect();
                    }
                } else {
                    this->state_step = 4;
                }
            } else if ((f32)this->state_timer >= 240.0f) {
                this->state_step = 5;
            }
            break;
        case 1:
            if ((bit != NULL) && (bit->can_cast() == 0)) {
                this->state_step = 5;
            } else if ((f32)this->state_timer >= 90.0f) {
                this->requested_action = 4;
                this->state_step = 3;
            }
            play_persistent_sound(this->remap_sound_for_area(0x4003A814), this, &this->position, 0, 0);
            break;
        case 2:
        case 3:
            if ((this->frame >= 11.0f) && (step == 3)) {
                if (bit != NULL) {
                    state = bit->get_state();
                } else {
                    state = 3;
                }
                switch (state) {
                case 2:
                    this->state_step = 2;
                    this->cast_resta();
                    break;
                case 3:
                    this->state_step = 2;
                    break;
                }
            }
            if (this->get_flag_b4() != 0) {
                this->state_step = 5;
                if (bit != NULL) {
                    bit->set_attack_flag();
                }
            }
            break;
        case 4:
            if ((f32)this->state_timer >= 60.0f) {
                this->state_step = 5;
            }
            break;
        case 5:
            break;
        }
        this->check_collisions();
        this->update_body_colliders();
        sub_800EF214();
        return;
    case 5:
        if (bit != NULL) {
            bit->set_attack_flag();
        }
        this->behavior_flags &= 0xFFFFFFF7;
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        break;
    }
}

void TObjEneRe4Sorcerer::update_damage_state(s32 reason) {
    Vec v;
    f32 c;
    switch (reason) {
    case 4:
        this->requested_action = 5;
        this->advance_animation();
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(this->next_mode);
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&v, &this->velocity);
        c = normalize_vector_xz(&v);
        this->move_to_wall_clamped_destination(v.x, v.z, c);
        this->velocity.x *= 0.8f;
        this->velocity.z *= 0.8f;
        sub_800EF214();
        break;
    case 5:
        this->clear_attack_receipts();
        break;
    }
}

void TObjEneRe4Sorcerer::handle_death_state(s32 mode) {
    switch (mode) {
    case 4:
        requested_action = 6;
        behavior_flags |= 6;
        refresh_and_send_entity_flags();
        state_timer = 0;
        fn_800D911C(&body_center);
        fade.start_fade_out();
        effect_scale = 0.0f;
        play_sound_effect(remap_sound_for_area(0x4003AD19), &position, 0, 0);
        return;
    case 0:
        advance_animation();
        if (fade.decay_value_toward_floor() != 0) {
            TObjPlayer::apply_effect_variant_b(&position, 0);
            queue_destruction();
        }
    case 3:
    case 5:
        return;
    }
}
}

#pragma push
#pragma opt_propagation off
extern "C" {
void TObjEneRe4Sorcerer::step_effect_sequence(NJS_OBJECT *) {
    s32 t;
    switch (TObjEneRe4Sorcerer__render_node_index) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 0x34: {
        f32 k = TObjEneRe4Sorcerer__effect_render_scale;
        t = model_render_flags;
        TObjEneRe4Sorcerer__saved_render_flags = t;
        model_render_flags = t & 0xFFFF7FFF;
        scale_matrix(0, k, k, k);
        TParticleCtrl::begin_effect_render();
        break;
    }
    case 0x37:
        model_render_flags = TObjEneRe4Sorcerer__saved_render_flags;
        TObjPlayer::toggle_particle_effect();
        break;
    }
    TObjEneRe4Sorcerer__render_node_index += 1;
}
}

#pragma pop
extern "C" {
void TObjEneRe4Sorcerer::render() {
    s32 camera;
    RenderFadeState *camera_fade;
    s32 fading;
    s32 detail;
    s32 draw_model;
    if (TObjPlayer::check_demo_mode() == 1) {
        render_demo();
        return;
    }
    camera = 0;
    if (is_split_screen() != 0) {
        camera = TCameraCtrl::get_camera_mode();
    }
    camera_fade = &fades[camera];
    camera_fade->update();
    fading = camera_fade->updateFromCamera(&body_center.x);
    if (!(behavior_flags & 2)) {
        detail = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        detail = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail != 0) {
        if (behavior_flags & 0x10) {
            draw_ground_shadow(0, 0);
        }
        update_secondary_light();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjEneRe4Sorcerer__uv_scroll_buffer->scroll_uvs(strip_scroll, 0);
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, texture_scroll);
        TObjPlayer::toggle_particle_effect();
        draw_model = 1;
        if (behavior_flags & 4) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw_model = 0;
            }
        } else if (fading != 0) {
            camera_fade->set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw_model = 0;
            }
        }
        if (draw_model != 0) {
            push_matrix();
            post_translate_matrix(&position.x);
            translate_matrix(0, 0.0f, 22.0f, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneRe4Sorcerer__render_node_index = 0;
            TObjEneRe4Sorcerer__saved_render_flags = 0;
            TObjEneRe4Sorcerer__effect_render_scale = effect_scale;
            re4_sorcerer_render_node_ptr = bit_anchors;
            set_chunk_model_node_callback(TObjEneRe4Sorcerer::step_effect_sequence);
            model_render_flags |= 0x01000000;
            if (detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            model_render_flags &= 0xFEFFFFFF;
            set_chunk_model_node_callback(NULL);
            pop_matrix();
        }
        if (behavior_flags & 4) {
            fade.clear_flag_and_notify();
        } else if (fading != 0) {
            camera_fade->clear_flag_and_notify();
        }
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        TParticleCtrl::end_effect_render();
    }
}
}

extern "C" {
void TObjEneRe4Sorcerer::run_demo_task() {
    if (get_target_info() != 0) {
        sub_800EFE30();
    }
}

void TObjEneRe4Sorcerer::render_demo() {
    get_target_info();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, 22.0f, 0.0f);
        rotate_matrix_y(0, rotation_y);
        strip_scroll = (strip_scroll + 5);
        TObjEneRe4Sorcerer__uv_scroll_buffer->scroll_uvs(strip_scroll, 0);
        texture_scroll += 0.01f;
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, texture_scroll);
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(model);
        TParticleCtrl::end_effect_render();
        model_render_flags &= 0xFFFDFFFF;
        pop_matrix();
    }
}
}
