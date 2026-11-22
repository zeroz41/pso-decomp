#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/system/task/TMainTask.h"
#include "pso/system/EnemyBmlResource.h"
#include <stddef.h>
#include <stdlib.h>
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/gee/TUnk_8049387C.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/gee/TObjEneMe1Gee_NEEDLE.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/AngleUnits.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/model_render_state.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/system/MatrixStack.h"

#pragma defer_codegen on
extern "C" {


BmlResource * TObjEneMe1Gee__resource_bundle;
u8 * lbl_805D51B4;
s32 TObjEneMe1Gee__render_node_index;
Vec *gee_camera_ctrl_step_ptr;
TUnk_8048FA00 * TObjEneMe1Gee__data_805D51C0;
TUnk_8048FA00 * TObjEneMe1Gee__data_805D51C4;
s32 gee_resource_bundle_ptr;
GeeMovementParameters me1_gee_init_params = {225.0f, 0.0f, 0x600};

CollisionBody lbl_8049379C = {
    {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f,
};

const char *bm_ene_me1_gee_model_names[3] = {"me1_y_mb.nj", "needle_body.gj", NULL};

const char *bm_ene_me1_gee_motion_names[5] = {
    "attack_me1_y_mb.njm", "damage_me1_y_mb.njm", "tuki_me1_y_mb.njm", "wait_me1_y_mb.njm", NULL,
};

BmlResourceDescriptor bm_ene_me1_gee_resource_descriptor = {
    "bm_ene_me1_gee.bml", bm_ene_me1_gee_model_names, bm_ene_me1_gee_motion_names, 2, 4,
};

const char *bm_ene_me1_gee_low_model_names[3] = {"lo_me1_y_mb.nj", "needle_body.gj", NULL};

const char *bm_ene_me1_gee_low_motion_names[5] = {
    "attack_me1_y_mb.njm", "damage_me1_y_mb.njm", "tuki_me1_y_mb.njm", "wait_me1_y_mb.njm", NULL,
};

BmlResourceDescriptor bm_ene_me1_gee_low_resource_descriptor = {
    "bm_ene_me1_gee_low.bml", bm_ene_me1_gee_low_model_names, bm_ene_me1_gee_low_motion_names, 2, 4,
};

TObjMotionAction TObjEneMe1Gee__motion_parameters[4] = {
    {1, 0, 3, 0.9f, 0},
    {2, 0, 2, 1.0f, 0},
    {2, 0, 0, 1.0f, 0},
    {2, 0, 1, 0.8f, 0},
};

const NJS_ARGB TObjEneMe1Gee__data_8043BDB0 = {1.0f, 0.0f, 0.2f, 1.0f};

const NJS_ARGB TObjEneMe1Gee__data_8043BDC0 = {1.0f, 1.0f, 0.0f, 0.2f};

const NJS_ARGB lbl_8043BDD0 = {1.0f, 0.2f, 1.0f, 0.0f};

const char *TObjEneMe1Gee__fade_command_streams[5] = {
    "ababaababaabbababbabbbbc", "abbabbababc", "ababaaabbaaabbbabbabababbbbc", "abaaabababbac",
    "ababababaabbaabbababaabaabaaabbbbc",
};

const char *TObjEneMe1Gee__class_name = "TObjEneMe1Gee";

static saddr gee_boss_stat_handle_table[3];
static saddr gee_shared_handler_b_table[3];
static saddr gee_object_handle_table[3];
static TObjEneMe1GeeParams *gee_shared_handler_a_table[3];
static f32 gee_camera_ctrl_vec[4];




extern s32 lbl_8043BCD8[];
extern s32 lbl_8043BCE4[];
extern s32 lbl_8043BCF0[];
extern s32 lbl_8043BCFC[];

void TObjEneMe1Gee::load_resources() {
    s32 i;
    TUnk_8048FA00 *p;
    s32 t;
    Vec *v;
    v = (Vec *)gee_camera_ctrl_vec;
    gee_camera_ctrl_vec[0] = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
    if (is_split_screen() != 0) {
        TObjEneMe1Gee__resource_bundle = load_enemy_bml_resource(&bm_ene_me1_gee_low_resource_descriptor);
    } else {
        TObjEneMe1Gee__resource_bundle = load_enemy_bml_resource(&bm_ene_me1_gee_resource_descriptor);
    }
    TObjEneMe1Gee::cache_result_805D6660();
    lbl_805D51B4 = (u8 *)find_model_node((saddr)TObjEneMe1Gee__resource_bundle->models->model, 7);
    for (i = 0; i < 3; i++) {
        gee_boss_stat_handle_table[i] = (saddr)TLobby::register_boss(lbl_8043BCD8[i]);
        gee_shared_handler_b_table[i] = (saddr)TLobby::dispatch_shared_handler_b(lbl_8043BCE4[i]);
        gee_object_handle_table[i] = (saddr)TLobby::register_object(lbl_8043BCF0[i]);
        gee_shared_handler_a_table[i] = (TObjEneMe1GeeParams *)TLobby::dispatch_shared_handler_a(lbl_8043BCFC[i]);
    }
    TObjEneMe1Gee__render_node_index = 0;
    p = new TUnk_8048FA00((saddr)TObjEneMe1Gee__resource_bundle->models->model);
    TObjEneMe1Gee__data_805D51C0 = p;
    p = new TUnk_8048FA00((saddr)TObjEneMe1Gee__resource_bundle->models->model);
    TObjEneMe1Gee__data_805D51C4 = p;
    t = ((s32 *)((NJS_OBJECT *)find_model_node((saddr)TObjEneMe1Gee__resource_bundle->models->model, 4))->model)[1];
    gee_resource_bundle_ptr = t + 4;
    TObjPlayer__sub_800F0928();
    {
        NpcAnimationBinding sp8 = { NULL, reinterpret_cast<TObjMotionAction *>(TObjEneMe1Gee__motion_parameters), 0, 0, 4 };
        sp8.motions = reinterpret_cast<BmlMotionEntry *>(TObjEneMe1Gee__resource_bundle->motions);
        NpcModelRegistry::register_animated_chunk((s16)0x10, reinterpret_cast<void *>(TObjEneMe1Gee__resource_bundle->models->model), reinterpret_cast<void *>(TObjEneMe1Gee__resource_bundle->models->m_c), &sp8, 8.0f, 15.0f);
    }
}

void *TObjEneMe1Gee::create(void *set_data) {
    return new TObjEneMe1Gee(tl_04, set_data, 0);
}

TObjEneMe1Gee *TObjEneMe1Gee::create(TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index) {
    return new TObjEneMe1Gee(tl_04, leader, pos, id, index);
}

void TObjEneMe1Gee::free_globals() {
    if (TObjEneMe1Gee__data_805D51C4 != NULL) {
        delete TObjEneMe1Gee__data_805D51C4;
        TObjEneMe1Gee__data_805D51C4 = NULL;
    }
    if (TObjEneMe1Gee__data_805D51C0 != NULL) {
        delete TObjEneMe1Gee__data_805D51C0;
        TObjEneMe1Gee__data_805D51C0 = NULL;
    }
    if (TObjEneMe1Gee__resource_bundle != NULL) {
        delete TObjEneMe1Gee__resource_bundle;
        TObjEneMe1Gee__resource_bundle = NULL;
    }
    TObjEneMe1Gee__sub_802A4D4C();
}

TObjEneMe1Gee::TObjEneMe1Gee(TObject *parent, void *set_data, s32 kind) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Gee__class_name;
    invoke_initialization_hook(set_data);
    status_flags = 0;
    sub_800CC0C4();
    this->leader = this;
    this->kind = kind;
    init_state();
}

TObjEneMe1Gee::TObjEneMe1Gee(TObject *parent, TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index)
    : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Gee__class_name;
    this->leader = leader;
    init_common_from((u8 *)this->leader);
    entity_id = id;
    set_index = index;
    this->leader->calc_position(&position);
    VecCopy(&position, pos);
    rotation_y = this->leader->rotation_y;
    status_flags = 0;
    this->kind = 1;
    init_state();
}
#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void TObjEneMe1Gee::init_state() {
    s32 temp_r0;
    s32 i;
    s32 var_r30;
    u8 *temp_r4;
    this->init_position_vectors();
    this->select_model();
    this->init_model(&lbl_8049379C, 1);
    this->set_field_d8((saddr)TObjEneMe1Gee__motion_parameters);
    this->set_field_dc((saddr)TObjEneMe1Gee__resource_bundle->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    this->set_field_b8(this->requested_action);
    this->reset_hp((u8 *)gee_boss_stat_handle_table[this->kind], (u8 *)gee_shared_handler_b_table[this->kind], (u8 *)gee_object_handle_table[this->kind]);
    this->set_state_flag_1();
    this->movementParameters = &me1_gee_init_params;
    this->initialize_enemy_state(0x36);
    this->wall_reach = 10.0f;
    this->enemy_init_acquire_period(0x2D);
    this->enemy_init_validate_period(0x2D);
    this->set_active();
    this->actorFlags |= 0x01000000;
    this->kind_params = gee_shared_handler_a_table[this->kind];
    this->fade.reset_color();
    this->upper_hover_height = 45.0f;
    this->hover_height = 15.0f;
    this->random_hover_height = ((5.0f * (3.0517578e-05f * (f32) rand())) + 15.0f);
    this->hover_offset = this->hover_height;
    this->hover_y = this->position.y + this->hover_offset;
    this->attack_delay = 0;
    this->attack_count = 0;
    this->m_40c = 0;
    this->alt_model_color = 0;
    for (i = 0; i < 2; i++) {
        VecCopy(&this->node_points[i], &this->position);
    }
    this->attack_pattern = 0;
    this->stage = 0;
    this->stage_timer = 0;
    this->stage_counter = 0;
    this->m_440 = 0;
    this->orbit_angle_step = 0;
    this->m_448 = 0.0f;
    this->m_44c = 0.0f;
    this->m_450 = 0.0f;
    this->m_454.x = 0.0f;
    this->m_454.y = 0.0f;
    this->m_454.z = 0.0f;
    this->eff_line = 0;
    this->particle_emitter = 0;
    copy_argb(&this->core_color, (NJS_ARGB *)&TObjEneMe1Gee__data_8043BDC0);
    this->core_color.a = 0.0f;
    this->fade_mode = 0;
    this->core_color_packed = 0;
    this->fade_sequence = 0;
    this->fade_step_timer = 0;
    this->fade_cursor = 0;
    this->copy_pos();
    TObjEneDD::set_part_position(this, this->bodies, 0);
    this->mode = 0;
    this->dispatch_action(this->mode, 4);
    if (this->leader != NULL) {
        this->leader_id = get_entity_id(this->leader);
        return;
    }
    this->leader_id = 0xFFFF;
}
#pragma pop
TObjEneMe1Gee::~TObjEneMe1Gee() {
    if (particle_emitter != NULL) {
        particle_emitter->queue_destruction();
        particle_emitter = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneMe1Gee::run_task() {
    u8 *object;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (kind == 1 && ((leader = (TObjEneMe1Gee *)find_entity_by_id(leader_id), object = (u8 *)leader, object == NULL) || ((TObject *)object)->all_parents_unqueued_for_destruction() == 0)) {
        this->queue_destruction();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
        this->update_fade_sequence();
    }
    this->copy_pos();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
}

BmlResource *TObjEneMe1Gee::sub_800CC2BC() { return TObjEneMe1Gee__resource_bundle; }

void TObjEneMe1Gee::refresh_target() {  }

void TObjEneMe1Gee::run_death_reaction() {
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 != 0xE) && (temp_r0 != 0xC)) {
        this->transition_enemy_state(0xE);
    }
}

void TObjEneMe1Gee::run_hit_reaction() { if (this->mode != 13) { this->transition_enemy_state(13); } }

void TObjEneMe1Gee::run_miss_reaction() {  }

void TObjEneMe1Gee::copy_pos() {
    this->body_center.x = this->position.x;
    this->body_center.y = this->hover_y;
    this->body_center.z = this->position.z;
    VecCopy(&this->center, &this->body_center);
}

void TObjEneMe1Gee::update_body_colliders() {
    this->hover_offset = (this->hover_y - this->position.y);
    if (this->hover_offset < 30.0f) {
        this->set_colliders_contact_low();
    } else {
        this->set_colliders_contact_high();
    }
    this->bodies->offset.y = this->hover_offset;
}
#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::sub_800CC0C4() {
    if ((s32) floor_to_float(this->parameters[0]) == 0) {
        this->sub_800CB5D4();
    } else {
        this->sub_800CB5B8();
    }
    if ((s32) floor_to_float(this->parameters[1]) == 0) {
        this->sub_800CB60C();
    } else {
        this->sub_800CB5F0();
    }
    this->needle_speed = (6.0f + this->parameters[3]);
    if (this->needle_speed < 0.01f) {
        this->needle_speed = 0.01f;
    }
    this->climb_speed = (1.0f + this->parameters[2]);
    if (this->climb_speed < 1.0f) {
        this->climb_speed = 1.0f;
    }
}
#pragma pop
void TObjEneMe1Gee::select_model() {
    this->model = (void *)TObjEneMe1Gee__resource_bundle->models->model;
    this->texlist = (saddr)TObjEneMe1Gee__resource_bundle->models->m_c;
}
#pragma push
#pragma fp_contract on
void TObjEneMe1Gee::calc_position(Vec *out) {
    s32 angle = get_random_scaled();
    f32 radius = 30.0f * this->random_ratio() + 10.0f;
    out->x = radius * sin_table_lookup(angle);
    out->y = 0.0f;
    out->z = radius * cos_table_lookup(angle);
    vec3_add_to(out, &this->position);
}
#pragma pop
u8 *TObjEneMe1Gee::move_xz_on_ground(u8 *dest) {
    u8 *ground = TObjEneDD::move_xz_on_ground(dest);
    if (ground == NULL) {
        this->status_flags &= 0xFEFFFFFF;
    } else {
        this->status_flags |= 0x01000000;
    }
    return ground;
}

void TObjEneMe1Gee::sub_800CBF58(f32 farg0) {
    f32 temp_f3;
    temp_f3 = farg0 - this->hover_y;
    this->status_flags &= 0xFFF7FFFF;
    if (temp_f3 >= 0.5f) {
        this->hover_y += 0.5f;
        return;
    }
    if (temp_f3 <= (-0.5f)) {
        this->hover_y -= 0.5f;
        return;
    }
    this->hover_y = farg0;
    this->status_flags |= 0x80000;
}

void TObjEneMe1Gee::approach_target_value(f32 target) {
    f32 d = target - this->hover_y;
    this->status_flags &= ~0x80000;
    if (d >= this->climb_speed) {
        this->hover_y += this->climb_speed;
    } else if (d <= -this->climb_speed) {
        this->hover_y -= this->climb_speed;
    } else {
        this->hover_y = target;
        this->status_flags |= 0x80000;
    }
}

void TObjEneMe1Gee::set_move_speed_x() {
    this->sub_800CBF58(this->position.y + this->upper_hover_height);
}

void TObjEneMe1Gee::sub_800CBE6C(f32 y) {
    Vec pos;
    this->sub_800CBF58(y);
    VecCopy(&pos, &this->position);
    pos.y = this->hover_y;
    this->move_xz_on_ground((u8 *)&pos);
}

void TObjEneMe1Gee::update_hover_height() {
    this->sub_800CBE6C(this->hover_height + this->position.y);
}

void TObjEneMe1Gee::update_animation_frame() {
    this->sub_800CBE6C(this->upper_hover_height + this->position.y);
}

void TObjEneMe1Gee::sub_800CBDBC(f32 y) {
    Vec pos;
    this->approach_target_value(y);
    VecCopy(&pos, &this->position);
    pos.y = this->hover_y;
    this->move_xz_on_ground((u8 *)&pos);
}

void TObjEneMe1Gee::update_from_float_sum() {
    this->sub_800CBDBC(this->hover_height + this->position.y);
}

void TObjEneMe1Gee::update_angle() {
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z)), 0x400);
    this->rotation_y = (s32) (s16) this->rotation_y;
}

void TObjEneMe1Gee::update() { if (this->enemy_has_live_target() != 0) { this->enemy_copy_target_destination(); this->update_velocity(); this->update_angle(); } }

void TObjEneMe1Gee::select_next_attack_state() {
    if (this->status_flags & 0x100) {
        this->transition_enemy_state(8);
        return;
    }
    if ((s32) this->kind == 0) {
        if ((s32) this->attack_pattern < 2) {
            this->transition_enemy_state(7);
            this->attack_pattern += 1;
            return;
        }
        this->transition_enemy_state(8);
        this->attack_pattern = 0;
        return;
    }
    this->transition_enemy_state(7);
}

void TObjEneMe1Gee::check_collisions() { TObjEneDD::check_collisions(); }

void TObjEneMe1Gee::sub_800CBC1C() {
    this->bodies->flags |= 0x28;
}

void TObjEneMe1Gee::sub_800CBC04() {
    this->bodies->flags &= ~0x28;
}

s32 TObjEneMe1Gee::find_attack_target(f32 *out, f32 range) {
    TargetCandidate recs[5];
    s32 found;
    s32 n;
    TObjPlayer *p;
    s32 i;
    found = 0;
    *out = (-1.0f);
    n = collect_enemy_target_candidates(this, recs, range);
    for (i = 0; i < n; i++) {
        p = get_player_by_client_id(recs[i].id);
        if (p != this->current_target) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            if (this->leader->can_member_attack_target(p) != 0) {
                *out = newton_sqrtf(recs[i].dist);
                found = 1;
                this->set_target_player(p);
                break;
            }
        }
    }
    return found;
}

s32 TObjEneMe1Gee::check_can_attack() {
    f32 sp8;
    s32 var_r31;

    var_r31 = 0;
    if (this->destination_distance < 70.0f) {
        var_r31 = 1;
        *(void **)&this->leader = find_entity_by_id(this->leader_id);
        if ((this->leader->can_member_attack_target(this->current_target) == 0) && (this->find_attack_target(&sp8, 22500.0f) != 0) && (sp8 > 70.0f)) {
            var_r31 = 0;
        }
    }
    return var_r31;
}

s32 TObjEneMe1Gee::sub_800CBA80() {
    return this->hover_offset < 20.0f;
}

void TObjEneMe1Gee::spawn_members() {  }

s32 TObjEneMe1Gee::check_retreat_trigger() {
    s32 temp_r4;
    temp_r4 = this->status_flags;
    if (temp_r4 & 0x40) {
        this->status_flags = (s32) (temp_r4 & 0xFFFFFFBF);
        this->transition_enemy_state(0xC);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Gee::check_death_trigger() {
    if (this->current_target == NULL) {
        this->transition_enemy_state(0xF);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Gee::handle_message(s32 id) {
    s32 var_r3;

    if (id == 0x3A843) {
        var_r3 = 0x3A843;
        if (get_current_floor_area() == AREA_SEASIDE_NIGHT) {
            return 0x4003B20D;
        }
        return var_r3;
    }
    var_r3 = this->remap_sound_for_area(id);
    return var_r3;
}

void TObjEneMe1Gee::sub_800CB968() {
    play_persistent_sound(this->handle_message(0x3BC16), (saddr)this, (uaddr)&this->body_center, 0, 0);
}

s32 TObjEneMe1Gee::acquire_target(f32 range) { return this->select_and_apply_target(range); }

void TObjEneMe1Gee::update_fade_sequence() {
    switch (this->fade_mode) {
    case 0:
        break;
    case 1:
        if (this->core_color.a > 0.0f) {
            this->core_color.a = this->core_color.a - 0.06f;
        } else {
            this->core_color.a = 0.0f;
            this->fade_mode = 0;
        }
        this->update_packed_color();
        break;
    case 2:
        if (this->core_color.a < 1.0f) {
            this->core_color.a += 0.06f;
        } else {
            this->core_color.a = 1.0f;
            this->fade_mode = 0;
        }
        this->update_packed_color();
        break;
    case 3:
        (this->fade_step_timer)++;
        if ((f32)this->fade_step_timer >= 2.0f) {
            this->fade_step_timer = 0;
            switch (TObjEneMe1Gee__fade_command_streams[this->fade_sequence][(this->fade_cursor)++]) {
            case 'b':
                this->core_color.a = 0.0f;
                break;
            case 'c':
                this->fade_mode = 0;
                copy_argb(&this->core_color, (NJS_ARGB *)&TObjEneMe1Gee__data_8043BDB0);
                break;
            case 'a':
                this->core_color.a = 1.0f;
                break;
            }
            this->update_packed_color();
        }
        break;
    }
}

void TUnk_8049387C::sub_800CB764(s32 arg1) {
    this->destroy_subobj(&lbl_8043BDD0);
    this->fade_mode = 3;
    this->fade_sequence = arg1;
    this->fade_step_timer = 2;
    this->fade_cursor = 0;
}

void TObjEneMe1Gee::destroy_subobj(const NJS_ARGB *color) {
    copy_argb(&this->core_color, (NJS_ARGB *)color);
    this->update_packed_color();
}
#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::update_packed_color() {
    u8 g = (u32)(255.0f * this->core_color.g);
    u8 b = (u32)(0.8f * (255.0f * this->core_color.b));
    u8 r = (u32)(255.0f * this->core_color.r);
    u8 a = (u32)(255.0f * this->core_color.a);
    this->core_color_packed = (b << 24) | (g << 16) | (r << 8) | a;
}
#pragma pop
void TObjEneMe1Gee::apply_model_color() {
    if ((s32 *) (*(s32 **)&gee_resource_bundle_ptr) != NULL) {
        *(*(s32 **)&gee_resource_bundle_ptr) = this->core_color_packed;
    }
}

int TObjEneMe1Gee::has_no_members() { return 1; }

void TObjEneMe1Gee::update_photon_target() {
    if ((s16) this->mode == 3) {
        this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
        this->leader->sub_800CB560();
    }
}

int TObjEneMe1Gee::sub_800CB628() { return (this->status_flags >> 15) & 0x1; }

void TObjEneMe1Gee::sub_800CB60C() {
    this->status_flags |= 0x02000000;
    this->status_flags &= 0xFBFFFFFF;
}

void TObjEneMe1Gee::sub_800CB5F0() {
    this->status_flags |= 0x04000000;
    this->status_flags &= 0xFDFFFFFF;
}

void TObjEneMe1Gee::sub_800CB5D4() {
    this->status_flags |= 0x100;
    this->status_flags &= 0xFFFFFDFF;
}

void TObjEneMe1Gee::sub_800CB5B8() {
    this->status_flags |= 0x200;
    this->status_flags &= 0xFFFFFEFF;
}

s32 TObjEneMe1Gee::sub_800CB5A0(s32 mask) {
    return (u8) ((this->status_flags & mask) != 0);
}

TObjChara *TObjEneMe1Gee::sub_800CB584() {
    if (this->status_flags & 0x40000) {
        return this->current_target;
    }
    return NULL;
}

void TObjEneMe1Gee::remove_member(uaddr) {  }

int TObjEneMe1Gee::can_member_attack_target(TObjChara *) { return 1; }

void TObjEneMe1Gee::sub_800CB560() {
    this->attack_delay = 0;
    this->status_flags |= 1;
}

void TObjEneMe1Gee::set_state_flag(TObjChara *target, s32 arg2) {
    this->set_target_player(target);
    this->attack_delay = arg2;
    this->status_flags |= 1;
}

void TObjEneMe1Gee::set_flag3c8_bit2() { this->status_flags |= 0x2; }

void TObjEneMe1Gee::set_flag3c8_bit4() { this->status_flags |= 0x4; }

void TObjEneMe1Gee::set_flag3c8_bit8() { this->status_flags |= 0x8; }

void TObjEneMe1Gee::sub_800CB4DC() {
    this->status_flags |= 0x100000 | 4;
}

void TObjEneMe1Gee::set_flag3c8_bit40() { this->status_flags |= 0x40; }

void TObjEneMe1Gee::dispatch_action(u32 state, s32 mode) {
    switch (state) {
    case 0:
        state_attack_loop(mode);
        break;
    case 1:
        state_move(mode);
        break;
    case 2:
        sub_800CAFD8(mode);
        break;
    case 3:
        state_hover(mode);
        break;
    case 4:
        vfunc_110(mode);
        break;
    case 5:
        vfunc_111(mode);
        break;
    case 6:
        state_attack(mode);
        break;
    case 7:
        sub_800CA454(mode);
        break;
    case 8:
        sub_800C9DF8(mode);
        break;
    case 9:
        sub_800C9A94(mode);
        break;
    case 10:
        sub_800C9964(mode);
        break;
    case 12:
        sub_800C9580(mode);
        break;
    case 13:
        hurt_state(mode);
        break;
    case 14:
        state_dead(mode);
        break;
    case 15:
        state_return_home(mode);
        break;
    case 17:
        handle_event(mode);
        break;
    case 18:
        state_orbit(mode);
        break;
    }
}

void TObjEneMe1Gee::state_attack_loop(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        this->set_intangible();
        this->status_flags |= 0x400000;
        this->fade_mode = 1;
        this->stage = 0;
        return;
    case 3:
        if ((s32) this->stage >= 4) {
            if ((s32) this->kind == 0) {
                this->status_flags |= 0x100000;
            }
            if (this->status_flags & 0x02000000) {
                this->transition_enemy_state(1);
            } else {
                this->transition_enemy_state(2);
            }
        }
    case 5:
        break;
    case 0:
        this->stage += 1;
        if ((s32) this->stage == 2) {
            this->spawn_members();
        }
        this->status_flags &= 0xFEFFFFFF;
        break;
    }
}

void TObjEneMe1Gee::state_move(s32 msg) {

    switch (msg) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        this->status_flags &= 0xFFBFFFFF;
        this->set_intangible();
        this->actorFlags = (this->actorFlags & 0xFEFFFFFF);
        this->fade_mode = 1;
        fade.start_fade_in();
        play_area_sound_effect(&this->position);
        return;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            this->transition_enemy_state(3);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if ((s32) this->kind == 2) {
            this->sub_800CBE6C(25.0f + this->position.y);
        } else {
            this->update_hover_height();
        }
        this->update_body_colliders();
        break;
    }
}

void TObjEneMe1Gee::sub_800CAFD8(s32 mode) {
    Vec pos;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(3);
        this->status_flags &= 0xFFBFFFFF;
        this->status_flags &= 0xFFF7FFFF;
        this->actorFlags |= 0x01000000;
        this->set_intangible();
        this->fade_mode = 1;
        this->fade.start_fade_in();
        VecCopy(&pos, &this->position);
        pos.y += 150.0f;
        this->hover_y = pos.y;
        TBoss3Volopt__sub_800D8D88((saddr) &pos);
        this->set_invulnerable();
        this->stage = 0;
        return;
    case 3:
        if (this->status_flags & 0x80000) {
            this->transition_enemy_state(3);
            this->clear_invulnerable();
        }
        return;
    case 0:
        this->advance_animation();
        switch (this->stage) {
        case 0:
            if (this->fade.advance_toward_max() != 0) {
                this->stage = 1;
            }
            break;
        case 1:
            this->update_from_float_sum();
            break;
        }
        this->update_body_colliders();
        this->sub_800CB968();
        return;
    case 5:
        this->clear_invulnerable();
        this->actorFlags &= 0xFEFFFFFF;
        break;
    }
}

void TObjEneMe1Gee::state_hover(s32 mode) {
    s32 temp_r3;

    switch (mode) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags &= 0xFEFFFFFF;
        this->fade_mode = 1;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            temp_r3 = this->status_flags;
            if (temp_r3 & 1) {
                this->status_flags = (s32) (temp_r3 & 0xFFFFFFFE);
                this->transition_enemy_state(4);
            } else if (this->enemy_has_live_target() != 0) {
                this->transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        if ((s32) this->kind != 1) {
            this->update_linked_position(200.0f);
        }
        if ((s32) this->kind == 2) {
            this->sub_800CBE6C(25.0f + this->position.y);
        } else {
            this->update_hover_height();
        }
        this->check_collisions();
        break;
    case 5:
        this->actorFlags &= 0xFEFFFFFF;
        break;
    case 1:
        break;
    }
}

void TObjEneMe1Gee::vfunc_110(s32 msg) {
    s32 temp_r3;

    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(4);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags &= 0xFEFFFFFF;
        this->core_color.r = TObjEneMe1Gee__data_8043BDB0.r;
        this->core_color.g = TObjEneMe1Gee__data_8043BDB0.g;
        this->core_color.b = TObjEneMe1Gee__data_8043BDB0.b;
        this->update_packed_color();
        this->stage = 0;
        return;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            temp_r3 = this->status_flags;
            if (temp_r3 & 2) {
                this->status_flags = (s32) (temp_r3 & 0xFFFFFFFD);
                if ((s32) this->kind == 1) {
                    this->transition_enemy_state(6);
                } else {
                    this->transition_enemy_state(5);
                }
            }
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        switch (this->stage) {
        case 2:
            break;
        case 0:
            this->attack_delay -= 1;
            if ((s32) this->attack_delay <= 0) {
                this->fade_mode = 2;
                this->stage = 1;
            }
            break;
        case 1:
            if ((s32) this->fade_mode == 0) {
                this->status_flags |= 0x8000;
                switch (this->kind) {
                case 0:
                    this->set_flag3c8_bit2();
                case 1:
                    this->stage = 3;
                    break;
                }
            }
            this->update();
            break;
        case 3:
            this->update();
            break;
        }
        this->update_hover_height();
        this->check_collisions();
        return;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TObjEneMe1Gee::vfunc_111(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        set_field_378(5);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags |= 0x01000000;
        return;
    case 3:
        if (this->status_flags & 0x80000) {
            this->attack_count = 0;
            this->select_next_attack_state();
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        update();
        update_animation_frame();
        this->check_collisions();
        break;
    }
}

void TObjEneMe1Gee::state_attack(s32 msg) {
    s32 temp_r3;

    switch (msg) {
    case 4:
        this->requested_action = 0;
        set_field_378(6);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags |= 0x01000000;
        this->stage = 0;
        return;
    case 3:
        if ((this->check_retreat_trigger() == 0) && ((s32) this->stage == 3)) {
            this->attack_count = 0;
            this->select_next_attack_state();
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        switch (this->stage) {
        case 0:
            temp_r3 = this->status_flags;
            if (temp_r3 & 4) {
                this->status_flags = (s32) (temp_r3 & 0xFFFFFFFB);
                if (this->sub_800CB5A0(0x200) != 0) {
                    this->stage = 1;
                    ((TUnk_8049387C *)this)->sub_800CB764(1);
                } else {
                    this->stage = 2;
                    ((TUnk_8049387C *)this)->sub_800CB764(3);
                }
            }
            update();
            this->update_animation_frame();
            break;
        case 1:
            if ((s32) this->fade_mode == 0) {
                this->stage = 3;
            }
            update();
            this->update_animation_frame();
            break;
        case 2:
            update();
            if ((s32) this->fade_mode != 0) {
                this->update_animation_frame();
            } else {
                this->sub_800CBE6C(this->position.y + this->random_hover_height);
                if (this->status_flags & 0x80000) {
                    this->stage = 3;
                }
            }
            break;
        }
        this->check_collisions();
        break;
    }
}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#pragma pool_data off
void TObjEneMe1Gee::sub_800CA454(s32 mode) {
    Vec *dir = &this->m_454;
    switch (mode) {
    case 4:
        this->set_field_378(7);
        this->status_flags |= 0x10000;
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags |= 0x1000000;
        this->destroy_subobj(&TObjEneMe1Gee__data_8043BDB0);
        this->stage = 1;
        this->stage_timer = 0;
        this->eff_line = NULL;
        this->particle_emitter = NULL;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->check_death_trigger() == 0 && this->stage == 6) {
            if (this->status_flags & 0x100000) {
                this->transition_enemy_state(9);
            } else {
                this->transition_enemy_state(10);
            }
        }
        break;
    case 0:
        this->advance_animation();
        if (this->stage == 1) {
            if (this->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        this->enemy_copy_target_destination();
        switch (this->stage) {
        case 1:
            this->update_velocity();
            if (this->check_can_attack() != 0) {
                this->stage = 2;
                this->status_flags |= 0x40000;
            }
            TObjEneEpsilon__sub_800B92F8(this, 0x200, 0.5f);
            break;
        case 2:
            this->update_velocity();
            this->update_angle();
            this->stage = 3;
            this->destroy_subobj(&TObjEneMe1Gee__data_8043BDC0);
            VecCopy(dir, &this->destination);
            break;
        case 3: {
            Vec d;
            this->update_velocity();
            this->update_angle();
            VecCopy(&d, &this->destination);
            subtract_vector(&d, dir);
            if (normalize_vector_xz(&d) < 0.6f) {
                VecCopy(dir, &this->destination);
            } else {
                dir->x = 0.6f * d.x + dir->x;
                dir->y = 0.6f * d.y + dir->y;
                dir->z = 0.6f * d.z + dir->z;
            }
            this->stage_timer++;
            if (this->stage_timer > this->kind_params->m_18) {
                this->requested_action = 1;
                this->stage = 4;
                this->stage_timer = 0;
                if (this->eff_line != NULL) {
                    this->eff_line->queue_destruction();
                    this->eff_line = NULL;
                }
                if (this->particle_emitter != NULL) {
                    this->particle_emitter->queue_destruction();
                    this->particle_emitter = NULL;
                }
                play_sound_effect(this->handle_message(0x3AD17), &this->body_center, 0, 0);
            } else {
                play_persistent_sound((s32)(this->handle_message(0x3A914)), (saddr)this, (uaddr)&this->body_center, 0, 0);
            }
            break;
        }
        case 4:
            this->stage_timer++;
            if (this->stage_timer >= 15) {
                this->stage = 5;
                this->status_flags &= ~0x40000;
                this->destroy_subobj(&TObjEneMe1Gee__data_8043BDB0);
                this->attack_count++;
                this->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix(&this->position.x);
                rotate_matrix_y(0, this->rotation_y);
                set_motion_packed_rotation();
                this->calc_joint_matrices(this->stage_timer);
                clear_motion_packed_rotation();
                pop_matrix();
                this->stage_timer = 0;
                push_matrix_from(anim_model_matrix_array[7]);
                {
                    Vec out;
                    Vec in = {0.0f, 0.0f, 0.0f};
                    matrix_mult_vec(0, &in, &out);
                    pop_matrix();
                    out.y += this->upper_hover_height;
                    new TObjEneMe1Gee_NEEDLE(this, &out, dir, this->needle_speed, this->kind_params->m_4);
                }
            }
            break;
        case 5:
            this->stage_timer++;
            if (this->stage_timer > this->kind_params->m_20) {
                this->stage_timer = 0;
                if (this->attack_count >= this->kind_params->m_24) {
                    this->stage = 6;
                } else {
                    this->stage = 1;
                }
            }
            break;
        }
        this->set_move_speed_x();
        this->check_collisions();
        break;
    case 5:
        this->status_flags &= ~0x40000;
        this->destroy_subobj(&TObjEneMe1Gee__data_8043BDB0);
        if (this->eff_line != NULL) {
            this->eff_line->queue_destruction();
            this->eff_line = NULL;
        }
        if (this->particle_emitter != NULL) {
            this->particle_emitter->queue_destruction();
            this->particle_emitter = NULL;
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe1Gee::sub_800C9DF8(s32 mode) {
    f32 dist;

    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(8);
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags &= ~0x1000000;
        this->status_flags &= ~0x80000;
        this->stage = 0;
        this->stage_timer = 0x28;
        this->stage_counter = 0;
        this->m_448 = 0.0f;
        this->m_44c = 0.0f;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->check_death_trigger() == 0 && this->stage == 5) {
            this->transition_enemy_state(9);
        }
        break;
    case 0:
        this->advance_animation();
        if (this->stage == 0) {
            if (this->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        switch (this->stage) {
        case 0:
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->stage_timer++;
            if (this->stage_timer > 0x28) {
                this->stage_timer = 0;
                this->stage = 1;
                if (this->status_flags & 0x40000) {
                    if (this->destination_distance < 40.0f) {
                        this->stage = 2;
                        this->destroy_subobj(&TObjEneMe1Gee__data_8043BDC0);
                    }
                } else if (this->destination_distance < 100.0f) {
                    this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
                    if (this->leader->can_member_attack_target(this->current_target) != 0) {
                        this->status_flags |= 0x40000;
                    } else if (this->find_attack_target(&dist, 10000.0f) != 0) {
                        if (dist < 100.0f) {
                            this->status_flags |= 0x40000;
                        }
                    } else {
                        this->stage = 5;
                    }
                }
            }
            this->sub_800CBE6C(this->position.y + this->hover_offset);
            break;
        case 1:
            if (this->stage_timer == 0) {
                f32 z;
                f32 x;
                f32 c;
                f32 s;
                f32 inv;
                f32 k;
                this->enemy_copy_target_destination();
                this->update_velocity();
                play_sound_effect(this->handle_message(0x3AD13), &this->body_center, 0, 0);
                k = 956.25f;
                inv = 1.0f / newton_sqrtf(k);
                k *= inv;
                c = 30.0f * inv;
                s = 7.5f * inv;
                if (this->stage_counter == 1) {
                    this->stage_counter = 0;
                    s *= (-1.0f);
                } else {
                    this->stage_counter = 1;
                }
                x = this->destination_direction.x;
                z = this->destination_direction.z * c - x * s;
                this->destination_direction.x = x * c + this->destination_direction.z * s;
                this->destination_direction.z = z;
                this->m_448 = 0.25f * k;
                this->m_44c = 0.25f * (this->hover_height - this->hover_offset);
            }
            this->sub_800CBC1C();
            this->stage_timer++;
            if (this->stage_timer >= 4) {
                this->stage_timer = 0;
                this->stage = 0;
                this->sub_800CBC04();
            }
            this->hover_y += this->m_44c;
            this->move_to_wall_clamped_destination(this->destination_direction.x, this->destination_direction.z, this->m_448);
            break;
        case 2:
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->sub_800CBF58(this->position.y + this->hover_height);
            if (this->destination_distance < 18.0f) {
                if (this->sub_800CBA80() != 0) {
                    this->stage_timer = 0;
                    this->stage = 3;
                }
            } else {
                if (this->destination_distance > 40.0f) {
                    this->stage = 1;
                }
                TObjEneEpsilon__sub_800B92AC(this, 0x200, this->kind_params->m_0);
            }
            break;
        case 3:
            this->requested_action = 1;
            this->stage = 4;
            play_sound_effect(this->handle_message(0x3AD15), &this->body_center, 0, 0);
        case 4:
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->stage_timer++;
            if (this->requested_action == 0) {
                if (this->attack_count >= 3) {
                    this->stage = 5;
                } else {
                    this->stage_timer = 0;
                    if (this->destination_distance < 13.0f) {
                        this->stage = 3;
                    } else if (this->destination_distance < 40.0f) {
                        this->stage = 2;
                    } else {
                        this->stage = 1;
                        this->destroy_subobj(&TObjEneMe1Gee__data_8043BDB0);
                        if (this->destination_distance > 100.0f) {
                            this->status_flags &= ~0x40000;
                        }
                    }
                }
            } else if (this->is_passing_frame(10.0f) != 0) {
                this->attack_count++;
                if (this->sub_800CBA80() != 0) {
                    if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                        this->current_target->receive_physical_attack(this, 1.0f);
                        this->current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                        if (this->random_ratio() <= 0.25f) {
                            DirectAttackPayload p = {0x11, 0.0f};
                            this->current_target->receive_direct_attack(this, p, 0, -1, -1);
                        }
                    }
                }
            }
            this->update_hover_height();
            break;
        case 5:
            break;
        }
        this->check_collisions();
        break;
    case 5:
        this->status_flags &= ~0x40000;
        this->destroy_subobj(&TObjEneMe1Gee__data_8043BDB0);
        this->sub_800CBC04();
        break;
    }
}
#pragma pop
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe1Gee::sub_800C9A94(s32 mode) {
    Vec *dir = &this->m_454;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(9);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->attack_count = 0;
        this->stage = 1;
        this->sub_800CBC1C();
        this->stage_timer = 0;
        this->stage_counter = 0;
        this->orbit_angle_step = 0;
        this->m_448 = 0.0f;
        this->m_44c = 0.0f;
        this->m_450 = 0.0f;
        dir->x = 0.0f;
        dir->y = 0.0f;
        dir->z = 0.0f;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->check_death_trigger() == 0 && this->stage_counter >= 4) {
            this->select_next_attack_state();
        }
        break;
    case 0:
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            switch (this->stage) {
            case 1: {
                if (this->stage_timer == 0) {
                    f32 t;
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    t = 8192.0f * calc_elapsed_scaled();
                    if (t >= 0.0f) {
                        t += 12288.0f;
                    } else {
                        t -= 12288.0f;
                    }
                    t *= 0.125f;
                    this->orbit_angle_step = t;
                    dir->x = -this->destination_direction.x;
                    dir->z = -this->destination_direction.z;
                    this->m_448 = 0.125f * (this->upper_hover_height - this->hover_offset);
                    this->m_450 = 0.125f * (70.0f - this->destination_distance);
                    this->m_44c = this->destination_distance;
                    play_sound_effect(this->handle_message(0x3AD13), &this->body_center, 0, 0);
                }
                this->stage_timer++;
                if (this->stage_timer >= 8) {
                    this->stage_counter++;
                    this->stage = 0;
                    this->sub_800CBC04();
                }
                this->hover_y += this->m_448;
                rotate_xz_pair_by_angle(&dir->x, &dir->z, this->orbit_angle_step);
                {
                    Vec v;
                    f32 c;
                    this->m_44c += this->m_450;
                    v.x = dir->x * this->m_44c + this->destination.x;
                    v.z = dir->z * this->m_44c + this->destination.z;
                    subtract_vector(&v, &this->position);
                    c = normalize_vector_xz(&v);
                    this->move_to_wall_clamped_destination(v.x, v.z, c);
                }
                this->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(dir->x, dir->z)) + 0x8000;
                break;
            }
            case 0:
                this->enemy_copy_target_destination();
                this->update_velocity();
                this->update_angle();
                this->update_animation_frame();
                this->stage_timer++;
                if (this->stage_timer > 30) {
                    this->stage_timer = 0;
                    this->stage = 1;
                }
                break;
            }
            this->check_collisions();
        }
        break;
    case 5:
        this->sub_800CBC04();
        break;
    }
}
#pragma pop
void TObjEneMe1Gee::sub_800C9964(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xA);
        this->status_flags &= 0xFFBFFFFF;
        this->set_intangible();
        if ((s32) this->kind == 1) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id((this->leader_id));
            ((TObjEneMe1Gee *)(this->leader))->set_flag3c8_bit8();
        }
        this->attack_count = 0;
        return;
    case 3:
        if ((this->check_retreat_trigger() == 0) && (this->destination_distance < 1.0f)) {
            this->transition_enemy_state(6);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        this->set_target_destination(&this->home_position);
        this->update_velocity();
        this->update_angle();
        this->set_move_speed_x();
        this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, 0.8f);
        this->update_body_colliders();
        break;
    }
}

void TObjEneMe1Gee::hurt_state(s32 mode) {
    Vec v;
    f32 len;
    switch (mode) {
    case 4:
        this->requested_action = 3;
        this->advance_animation();
        this->update_photon_target();
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags &= ~0x1000000;
        this->stage = 0;
        if (this->hover_y > 5.0f + (this->position.y + this->hover_height)) {
            this->stage_timer = 0;
        } else {
            this->stage_timer = 2;
        }
        this->m_448 = 0.0f;
        this->m_44c = 0.0f;
        break;
    case 3:
        if (this->stage_timer == 3) {
            this->transition_enemy_state(this->next_mode);
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&v, &this->velocity);
        len = normalize_vector_xz(&v);
        this->move_with_wall_slide_on_ground(v.x, v.z, len);
        len *= 0.5f;
        this->velocity.x = v.x * len;
        this->velocity.z = v.z * len;
        switch (this->stage_timer) {
        case 0:
            this->m_448 = this->m_448 - 0.13f;
            if (this->m_448 < -4.0f) {
                this->m_448 = -4.0f;
            }
            this->hover_y += this->m_448;
            if (this->hover_y < 12.0f + (this->position.y + this->hover_height)) {
                this->stage_timer = 1;
                if (this->m_448 > -2.0f) {
                    this->m_448 = -2.0f;
                }
                this->m_44c = (this->m_448 * this->m_448) / 30.0f;
            }
            break;
        case 1:
            this->m_448 += this->m_44c;
            this->hover_y += this->m_448;
            if (this->m_448 >= 0.0f) {
                if (this->hover_y > this->position.y + this->hover_height) {
                    this->hover_y = this->position.y + this->hover_height;
                    this->stage = 0;
                    this->stage_timer = 2;
                }
            }
            break;
        case 2:
            this->stage++;
            if (this->stage >= this->kind_params->m_28) {
                this->stage_timer = 3;
            }
            break;
        }
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        this->requested_action = 0;
        break;
    }
}
#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::sub_800C9580(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xC);
        this->set_intangible();
        this->status_flags &= 0xFFBFFFFF;
        this->actorFlags |= 0x800;
        if ((s32) this->kind == 1) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            this->leader->remove_member((uaddr)this);
        } else {
            this->send_entity_set_flags();
        }
        this->fade.set_rate_from_divisor(0x19);
        this->fade.reset_color();
        return;
    case 3:
        if ((this->fade.decay_value_toward_floor() != 0) && (this->has_no_members() != 0)) {
            this->queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}
#pragma pop
void TObjEneMe1Gee::state_return_home(s32 mode) {

    switch (mode) {
    case 4:
        set_field_378(0xF);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->stage = 0;
        return;
    case 3:
        if ((s32) this->stage == 2) {
            this->select_next_attack_state();
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->stage = 2;
        }
        switch (this->stage) {
        case 0:
            this->stage_timer += 1;
            if ((s32) this->stage_timer >= 0x3C) {
                this->stage = 1;
            }
            this->sub_800CBE6C(this->position.y + this->hover_offset);
            break;
        case 1:
            set_target_destination(&this->home_position);
            this->update_velocity();
            update_angle();
            set_move_speed_x();
            if (this->destination_distance > 2.0f) {
                this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, 0.8f);
            }
            break;
        }
        this->check_collisions();
        break;
    }
}

void TObjEneMe1Gee::state_dead(s32 msg) {
    Vec pos;
    switch (msg) {
    case 4:
        if ((s32) this->kind == 1) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            this->leader->remove_member((uaddr)this);
        }
        TBoss3Volopt::create_breakup_mdl((saddr)TObjEneMe1Gee__data_805D51C4, 0, this->texlist, (saddr)&this->body_center, this->rotation_y);
        play_sound_effect(this->handle_message(0x3A843), &this->position, 0, 0);
        this->status_flags |= 0x400000;
        this->actorFlags |= 0x01000000;
        VecCopy(&pos, &this->body_center);
        pos.y -= 5.0f;
        this->refresh_and_send_entity_flags();
        return;
    case 0:
        this->queue_destruction();
    case 3:
    case 5:
        return;
    }
}

void TObjEneMe1Gee::handle_event(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->stage = 0;
        return;
    case 0:
        advance_animation();
        this->stage += 1;
        if ((s32) this->stage > 0x5A) {
            this->stage = 0;
            this->requested_action = (this->requested_action + 1);
            if ((s16) this->requested_action >= 4) {
                this->requested_action = 0;
            }
        }
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Gee::state_orbit(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->hover_y = this->position.y + this->hover_height;
        this->m_448 = sin_table_lookup(this->rotation_y);
        this->m_44c = cos_table_lookup(this->rotation_y);
        return;
    case 0:
        advance_animation();
        this->hover_y = this->position.y + this->hover_height;
        this->body_center.y = this->hover_y;
        this->move_with_wall_slide_commit(this->m_448, this->m_44c, 0.2f);
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Gee::advance_camera_ctrl_step(NJS_OBJECT *) {
    Vec *pos;
    Vec *temp_r4_2;
    switch ((s32) TObjEneMe1Gee__render_node_index) {
    case 4:
        pos = gee_camera_ctrl_step_ptr;
        gee_camera_ctrl_step_ptr = pos + 1;
        forward_transform_to_view((const Vec *)gee_camera_ctrl_vec, pos);
        break;
    case 7:
        temp_r4_2 = gee_camera_ctrl_step_ptr;
        gee_camera_ctrl_step_ptr = temp_r4_2 + 1;
        forward_transform_to_view((const Vec *)gee_camera_ctrl_vec, temp_r4_2);
        break;
    }
    TObjEneMe1Gee__render_node_index += 1;
}

void TObjEneMe1Gee::render() {
    s16 temp_r0;
    s16 temp_r0_2;
    s32 var_r30;
    s32 var_r29;

    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    if (this->status_flags & 0x400000) {
        var_r30 = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        var_r30 = this->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        var_r30 = 1;
    } else {
        var_r30 = 0;
    }
    if (var_r30 != 0) {
        if (this->status_flags & 0x01000000) {
            this->draw_ground_shadow(0, 0);
        }
        this->update_secondary_light();
        TObjFish::set_global_param(this->texlist);
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        this->apply_model_color();
        push_matrix();
        post_translate_matrix(&this->position.x);
        translate_matrix(0, 0.0f, this->hover_offset, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        temp_r0 = this->mode;
        var_r29 = 1;
        if ((temp_r0 == 1) || (temp_r0 == 0xC)) {
            this->fade.set_flags_and_apply_damage_color();
            if (this->defer_render() != 0) {
                var_r29 = 0;
            }
        }
        if (var_r29 != 0) {
            if ((s16) this->mode != 0xB) {
                TObjEneMe1Gee__render_node_index = 0;
                gee_camera_ctrl_step_ptr = this->node_points;
                set_chunk_model_node_callback(TObjEneMe1Gee::advance_camera_ctrl_step);
                if (var_r30 == 1) {
                    set_motion_packed_rotation();
                    this->draw();
                    clear_motion_packed_rotation();
                } else {
                    set_motion_packed_rotation();
                    this->draw_motion_model();
                    clear_motion_packed_rotation();
                }
                set_chunk_model_node_callback(NULL);
            } else {
                rotate_matrix_z(NULL, this->rotation_z);
                TObjEneMe1Gee__render_node_index = -1;
                gee_camera_ctrl_step_ptr = this->node_points;
                set_chunk_model_node_callback(TObjEneMe1Gee::advance_camera_ctrl_step);
                this->draw_with_alt_model(this->alt_model_color);
                set_chunk_model_node_callback(NULL);
            }
        }
        temp_r0_2 = this->mode;
        if ((temp_r0_2 == 1) || (temp_r0_2 == 0xC)) {
            this->fade.clear_flag_and_notify();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        this->update_primary_light();
        return;
    }
    VecCopy(&this->node_points[0], &this->body_center);
    VecCopy(&this->node_points[1], &this->body_center);
}

void TObjEneMe1Gee::run_demo_task() { if (this->get_target_info() != 0) { this->sub_800CC0C4(); } }

#pragma push
// pool_data off: render_demo reaches each debug string with its own lis/addi.
#pragma pool_data off
void TObjEneMe1Gee::render_demo() {
    s32 temp_r3;
    s32 temp_r3_2;
    if (this->get_target_info() != 0) {
        if ((s32) this->kind == 0) {
            temp_r3 = this->status_flags;
            if (temp_r3 & 0x100) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 2)), "TYPE:IN FIGHTER");
            } else if (temp_r3 & 0x200) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 2)), "TYPE:OUT FIGHTER");
            } else {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 2)), "TYPE:UNKOWN");
            }
            temp_r3_2 = this->status_flags;
            if (temp_r3_2 & 0x02000000) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 3)), "TYPE:LOW APPEAR");
            } else if (temp_r3_2 & 0x04000000) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 3)), "TYPE:HIGH APPEAR");
            } else {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 3)), "TYPE:UNKOWN");
            }
        }
        TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 4)), "APPEAR SPEED(+1.f Min:0.01f)");
        TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 5)), "NEEDLE SPEED(+6.f Min:1.f)");
    }
    if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        this->draw_ground_shadow(0, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        draw_chunk_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
#pragma pop

TUnk_8049387C::~TUnk_8049387C() {}

void TUnk_8049387C::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
        this->update_fade_sequence();
        this->sub_800C84C8();
    }
    this->copy_pos();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TUnk_8049387C::select_model() {
    this->model = (void *)TObjEneMe1Gee__resource_bundle->models->model;
    this->texlist = (saddr)TObjEneMe1Gee__resource_bundle->models->m_c;
}

void TUnk_8049387C::select_next_attack_state() {
    switch (this->attack_pattern) {
    case 0:
    case 1:
        this->attack_pattern++;
        this->transition_enemy_state(7);
        break;
    case 2:
        this->attack_pattern = 0;
        this->transition_enemy_state(8);
        break;
    }
}

// dead-stripped: only its literals survive. 10.0f (.sdata2 0x805DA0B8) is pooled after spawn_members'
// 0.0f and before render_demo's 400.0f, ahead of its first live user sub_800C9DF8 (deferred codegen
// runs this file bottom-up). Minimal body after sub_800C9DF8's frame-10 hit check; name inferred.
static s32 is_hit_frame(TUnk_8049387C *gee) {
    return gee->is_passing_frame(10.0f);
}

void TUnk_8049387C::spawn_members() {
    s32 n;
    s32 i;
    s32 j;
    u16 a;
    s32 b;
    s32 angle;
    Vec v;
    n = (s32)ceil_to_float((f32)this->member_total / (f32)this->kind_params->m_2c);
    if (n < 1) {
        n = 1;
    }
    a = this->entity_id + 1;
    angle = this->rotation_y;
    b = this->set_index + 1;
    for (i = 0; i < n; i++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &this->position);
        angle += 0x10000 / this->member_total;
        this->members[i] = create(this, &v, a++, b++);
        this->members[i]->sub_800CB5B8();
        this->member_count++;
    }
    for (j = n; j < this->member_total; j++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &this->position);
        angle += 0x10000 / this->member_total;
        this->members[j] = create(this, &v, a++, b++);
        this->members[j]->sub_800CB5D4();
        this->member_count++;
    }
}

s32 TUnk_8049387C::check_retreat_trigger() {
    s32 i;
    if (this->status_flags & 0x40) {
        this->status_flags &= ~0x40;
        this->transition_enemy_state(12);
        for (i = 0; i < this->member_count; i++) {
            this->members[i]->set_flag3c8_bit40();
        }
        return 1;
    }
    return 0;
}

void TUnk_8049387C::remove_member(uaddr arg1) {
    s32 i;
    TObjEneMe1Gee *tmp;

    for (i = 0; i < this->member_count; i++) {
        if (this->members[i] == (TObjEneMe1Gee *)arg1) {
            this->member_count--;
            tmp = this->members[this->member_count];
            this->members[this->member_count] = (TObjEneMe1Gee *)arg1;
            this->members[i] = tmp;
            break;
        }
    }
    if ((s32)this->formation_state == 3) {
        s32 lim = (s32)ceil_to_float((f32)this->member_total / (f32)this->kind_params->m_2c);
        if (this->member_count <= this->member_total - lim) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            this->leader->set_flag3c8_bit8();
        }
    }
    if (!(this->status_flags & 0x100000) && this->member_count <= this->member_total / 2) {
        this->status_flags |= 0x10;
    }
    if (this->member_count <= 2) {
        this->status_flags |= 0x40;
    }
}

int TUnk_8049387C::can_member_attack_target(TObjChara *) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < this->member_count; i++) {
        if (this->members[i]->sub_800CB584() == this->current_target) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

void TUnk_8049387C::apply_model_color() {  }

int TUnk_8049387C::has_no_members() {
    return (u8) (this->member_count <= 0);
}

void TUnk_8049387C::sub_800C84C8() {
    s32 j;
    s32 i;

    if (this->status_flags & 0x10) {
        this->status_flags &= ~0x10;
        this->formation_state = 7;
    }
    switch (this->formation_state) {
    case 1:
        this->sub_800CB764(0);
        this->formation_state = 2;
        break;
    case 2:
        if (this->fade_mode == 0) {
            this->formation_state = 3;
            this->status_flags &= ~8;
            copy_argb(&this->core_color, (NJS_ARGB *)&TObjEneMe1Gee__data_8043BDB0);
            for (i = 0; i < this->member_count; i++) {
                if (this->members[i]->sub_800CB5A0(0x200) != 0) {
                    this->members[i]->set_flag3c8_bit4();
                }
            }
        }
        break;
    case 3:
        if (this->status_flags & 8) {
            this->formation_state = 4;
        }
        break;
    case 4:
        this->sub_800CB764(2);
        this->formation_state = 5;
        break;
    case 5:
        if (this->fade_mode == 0) {
            copy_argb(&this->core_color, (NJS_ARGB *)&TObjEneMe1Gee__data_8043BDB0);
            this->formation_state = 6;
            for (i = 0; i < this->member_count; i++) {
                if (this->members[i]->sub_800CB5A0(0x100) != 0) {
                    this->members[i]->set_flag3c8_bit4();
                }
            }
        }
        break;
    case 7:
        this->sub_800CB764(4);
        this->formation_state = 8;
        break;
    case 8:
        if (this->fade_mode == 0) {
            this->formation_state = 9;
            copy_argb(&this->core_color, (NJS_ARGB *)&TObjEneMe1Gee__data_8043BDB0);
            for (j = 0; j < this->member_count; j++) {
                this->members[j]->sub_800CB4DC();
            }
            this->sub_800CB4DC();
        }
        break;
    case 9:
        break;
    }
}

void TUnk_8049387C::vfunc_110(s32 msg) {
    s32 k;
    s32 i;
    s32 j;
    s32 m;

    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(4);
        this->clear_intangible();
        this->core_color.r = TObjEneMe1Gee__data_8043BDB0.r;
        this->core_color.g = TObjEneMe1Gee__data_8043BDB0.g;
        this->core_color.b = TObjEneMe1Gee__data_8043BDB0.b;
        this->stage = 0;
        for (k = 2, i = 0; i < this->member_count; k += 2, i++) {
            this->members[i]->set_state_flag(this->current_target, k);
        }
        break;
    case 3:
        if (this->status_flags & 2) {
            this->status_flags &= ~2;
            this->formation_state = 1;
            this->transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        switch (this->stage) {
        case 0:
            (this->attack_delay)--;
            if (this->attack_delay <= 0) {
                this->fade_mode = 2;
                this->stage = 1;
            }
            break;
        case 1:
            if (this->fade_mode == 0) {
                this->status_flags |= 0x8000;
                for (j = 0; j < this->member_count; j++) {
                    if (this->members[j]->sub_800CB628() == 0) {
                        break;
                    }
                }
                if (j == this->member_count) {
                    this->set_flag3c8_bit2();
                    for (m = 0; m < this->member_count; m++) {
                        this->members[m]->set_flag3c8_bit2();
                    }
                }
            }
            this->update();
            break;
        }
        this->sub_800CBE6C(25.0f + this->position.y);
        this->check_collisions();
        break;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TUnk_8049387C::vfunc_111(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(5);
        this->clear_intangible();
        break;
    case 3:
        if (this->status_flags & 4) {
            this->select_next_attack_state();
        }
        break;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        this->update();
        this->update_animation_frame();
        this->check_collisions();
        break;
    case 5:
        break;
    }
}

void TUnk_8049387C::state_dead(s32 msg) {
    switch (msg) {
    case 4:
        TBoss3Volopt::create_breakup_mdl((saddr)TObjEneMe1Gee__data_805D51C0, 0, this->texlist, (saddr)&this->body_center, this->rotation_y);
        this->status_flags |= 0x400000;
        refresh_lobby_state();
        return;
    case 0:
        if (this->has_no_members() != 0) {
            this->send_entity_set_flags();
            this->queue_destruction();
        }
    case 3:
    case 1:
        return;
    case 5:
        this->actorFlags &= 0xFFFFFDFF;
        break;
    }
}
}
