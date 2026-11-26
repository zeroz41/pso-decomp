#include "pso/system/SoundEffect.h"
#include "pso/object/trap/TOMine.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
struct game_command_header;

#include "types.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/system/vector.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/ChunkMaterialColor.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/trap/TOMineTrapDisp.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMineDisp.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/trap/TOMine.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/trap/TOMineIcon02.h"
#include "pso/object/trap/TOMineIcon03.h"
#include "pso/object/trap/TOMineIcon04.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803DA798.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/TGameProtocol.h"
#include "pso/system/byteswap.h"
#include "pso/object/trap/TOMineIcon01.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/BmlResourceDescriptor.h"


#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/network/client_id.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/map/area/AreaScene.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/base/TObjCharaHelpers.h"



// ---- the unit's data, in the original's order (.data, .sdata, .rodata, .sbss)
// The mine models in bm_o_mine.bml: the four light models, then the four bodies.
const char *bm_o_mine_model_names[9] = {
    "de_obj_o_zirai02_light.gj", "de_obj_o_zirai01_light.gj", "de_obj_o_zirai03_light.gj", "de_obj_o_zirai04_light.gj",
    "fe_obj_o_zirai01.gj",       "fe_obj_o_zirai02.gj",       "fe_obj_o_zirai03.gj",       "fe_obj_o_zirai04.gj",
    NULL,
};
const char *bm_o_mine_motion_names[1] = { NULL };
BmlResourceDescriptor mine_resource_desc = { "bm_o_mine.bml", bm_o_mine_model_names, bm_o_mine_motion_names, 8, 0 };
// TOMineTrap and the four TOMineIcon constructors install this one sphere.
CollisionBody mine_collision_body_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 3.0f, 0.0f, 0, 0x18005},
};
const char *mine_name = "TOMine";
int mine_trap_instance_id = 1;
f32 mine_trap_attack_power = 700.0f; // the attack power a TOMineTrap is built with
// Per floor area: the sound effects TOMine::play_trigger_sound and play_effect_sound play (-1 = none),
// and the area scale the TOMineTrap constructor reads.
const s32 mine_trap_keymachine_table[36] = {
    -1,         0x4bc12,    0x4bc12,    0x43c11,    0x43c11,    0x43c11,    0x4004bc0b, 0x4004bc0b, 0x4004bc12,
    0x4004bc12, 0x4004bc12, -1,         -1,         -1,         -1,         -1,         0x4004bc07, 0x4004bc07,
    -1,         0x4bc07,    0x4bc07,    0x4004bc07, 0x4004bc07, 0x4bc19,    0x4bc19,    0x4bc19,    0x4bc19,
    0x4bc19,    0x4004bc19, 0x4004bc19, -1,         -1,         -1,         -1,         0x4004bc19, 0x4004bc19,
};
const s32 mine_trap_effect_table[36] = {
    -1,         0x4b913,    0x4b913,    0x43912,    0x43912,    0x43912,    0x4004b90c, 0x4004b90c, 0x4004b913,
    0x4004b913, 0x4004b913, -1,         -1,         -1,         -1,         -1,         0x4004b908, 0x4004b908,
    -1,         0x4b908,    0x4b908,    0x4004b908, 0x4004b908, 0x4b91a,    0x4b91a,    0x4b91a,    0x4b91a,
    0x4b91a,    0x4004b91a, 0x4004b91a, -1,         -1,         -1,         -1,         0x4004b91a, 0x4004b91a,
};
const f32 mine_trap_area_scale_table[36] = {
    0.0f,  1.0f,  1.0f,  1.15f, 1.15f, 1.15f, 1.3f,  1.3f,  1.45f, 1.45f, 1.45f, 0.0f,
    0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  1.15f, 1.15f, 1.3f,
    1.3f,  1.3f,  1.3f,  1.3f,  1.45f, 1.45f, 0.0f,  0.0f,  0.0f,  0.0f,  1.45f, 1.45f,
};
const char *TOMineTrap::class_name = "TOMineTrap";
const char *mine_disp_name = "TOMineDisp";
const char *mine_trap_disp_name = "TOMineTrapDisp";
BmlResource *mine_model_archive; // bm_o_mine.bml, loaded by TOMine::load_static_resource
int mine_trap_count;

// ---- functions, last address first (deferred codegen emits them in reverse)
void G_TriggerTrap_6x80::init() {
    header.subcommand = 0x80;
    header.size = 2;
}

void G_TriggerTrap_6x80::send() {
    bswap();
    send_subcommand(this);
}

void G_TriggerTrap_6x80::bswap() {
    header.bswap();
    bswap_16(&trap_number);
    bswap_16(&what);
}

int TOMineTrap::calc_distance_accuracy_penalty(TObjChara *attacker, CollisionBody *, const Vec *, float) {
    if (attacker != target) {
        return 1;
    }
    return 0;
}

s32 TOMineTrap::select_melee_contact_body(TObjChara *attacker, f32) {
    if (attacker != target) {
        return 1;
    }
    return 0;
}


void TOMine::vfunc_84() {  }
int TOMineTrap::set_trap_count(int trap_count) { mine_trap_count = trap_count; return trap_count; }
int TOMineTrap::set_instance(int instance) { mine_trap_instance_id = instance; return instance; }
void set_mine_trap_damage(f32 power) {
    mine_trap_attack_power = power;
}
int TOMineTrap::get_trap_count() {  return mine_trap_count; }
u16 TOMineTrap::get_trap_number() { return trap_number; }
int TOMineTrap::get_instance() { return mine_trap_instance_id; }
void TOMineTrap::set_trap_type(u16 type) { this->m_2d8 = type; }
s16 TOMineTrap::get_mode() { return mode; }
u16 TOMineTrap::get_trap_type() { return this->m_2d8; }
s32 can_see_traps(TObjPlayer *player) { return player->check_flag(0x10000); }
TOMine::TOMine(TObject *parent) : TObjChara(parent) {
    m_name = mine_name;
    phase = 0;
    trigger_radius = 0.0f;
    detect_radius = 0.0f;
    attack.power = 0.0f;
    attack.kind = 0;
    target_id = 0xFFFF;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    float_flags = 0;
    facing = 0;
    set_actor_flags(0x60000000);
    actorFlags &= ~0x40000;
}

TOMine::~TOMine() {}


void TOMine::load_static_resource() {
    mine_model_archive = new BmlResource(1, &mine_resource_desc, NULL, NULL, NULL);
}
void TOMine::free_instance() {
    if (mine_model_archive != NULL) {
        delete mine_model_archive;
        mine_model_archive = NULL;
    }
}
void TOMine::render() {
    s32 t;
    if (mode == 3 && update_object_view_visibility(400.0f, 20.0f) != 0) {
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, facing);
        draw_body();
        TParticleCtrl::begin_effect_render();
        t = model_render_flags;
        saved_model_render_flags = t;
        model_render_flags = t | 0x20;
        set_constant_material(&color);
        draw_light();
        set_constant_material(&chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}
void TOMine::draw_body() { set_texture_list(this->texlist); draw_ginja_object(this->model); }
void TOMine::draw_light() {
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(light_textures));
    draw_ginja_object(light_model);
}
void TOMine::run_task() {
    s32 countdown;

    if (TObjPlayer::check_demo_mode() != 1) {
        this->vfunc_79();
        update_float_height();
        switch (this->mode) {
        case 2:
        case 0:
            find_target_player();
            VecCopy(&body_center, &float_position);
            VecCopy(&bodies->center, &float_position);
            return;
        case 3:
            countdown = this->set_params[2];
            this->set_params[2] = (countdown - 1);
            if (countdown < 0) {
                this->mode = 4;
            }
            switch (this->behavior) {
            default:
                apply_float_position();
                break;
            case 1:
                trigger_group();
                break;
            case 2:
                follow_target();
                break;
            }
            submit_cursor_candidate(this, -1);
            return;
        case 4:
            detonate();
            break;
        }
    }
}
int TOMine::find_target_player() {
  u16 client;
  unsigned short no_client;
  target_id = find_nearest_visible_player(this, NULL, detect_radius);
  client = target_id;
  no_client = -1;
  if (client != no_client)
  {
    target = get_player_by_client_id(client);
    update_trigger();
  }
  return target_id;
}
void TOMine::submit_cursor_target(s32 client) { submit_target_to_player_cursor(this, client); }
#pragma push
#pragma fp_contract on
void TOMine::detonate() {
    s32 i;
    TObjChara *obj;
    set_indexed_flags(0, 2);
    bodies->radius = this->trigger_radius;
    clear_battle_param_slots();
    this->check_object_collisions();
    check_enemy_body_collisions(this);
    for (i = 0; i < 0x10; i++) {
        obj = (TObjChara *)TObjPlayer::get_battle_param(i);
        if (TObjPlayer::is_valid_and_active((uaddr)obj) != 0) {
            DirectAttackPayload pair = attack;
            f32 r = obj->receive_direct_attack(this, pair, NULL, -1, -1);
            if (attack.kind < 5) {
                obj->apply_knockback_from_attacker(this, 0.1f * r);
            }
        }
    }
    this->mode = 6;
    this->clear_player_status_flag(0, 1);
    this->receive_physical_attack(0, 1.0f);
}
void TOMine::sync_position() { VecCopy(&position, &float_position); refresh_collision_body_centers(); }
void TOMine::update_float_height() {
    f32 y;
    f32 float_y;
    if (!(this->float_flags & 2)) {
        float_y = float_position.y;
        float_position.y = (f32) (float_y + ((0.5f * ((25.0f + this->home_position.y) - float_y)) + 1.0f));
        y = 25.0f + this->home_position.y;
        if (y <= float_position.y) {
            float_position.y = y;
            this->float_flags = (s32) (this->float_flags | 2);
        }
    } else {
        this->rotation_x = (this->rotation_x + 0x800);
        float_position.y = (f32) (float_position.y + sin_table_lookup(this->rotation_x));
    }
}
void TOMine::apply_float_position() { sync_position(); }
void TOMine::trigger_group() {
    TOMine *mine;
    s32 i;
    switch (this->phase) {
    case 0:
        this->phase = 1;
        for (i = registered_enemy_count; i < entity_table_count; i++) {
            mine = static_cast<TOMine *>(static_cast<TObject *>(TObjPlayer::get_player_data(i)));
            if (mine != NULL && mine != this &&
                (mine->check_value_equals(mine_icon01_name) != 0 ||
                 mine->check_value_equals(mine_icon02_name) != 0 ||
                 mine->check_value_equals(mine_icon03_name) != 0 ||
                 mine->check_value_equals(mine_icon04_name) != 0) &&
                mine->behavior == 1 && mine->group_id == group_id) {
                mine->update_trigger();
            }
        }
        break;
    }
    sync_position();
}
void TOMine::follow_target() {
  unsigned short none_id;
  Vec stack;
  f32 prev_y;
  none_id = -1U;
  if (((this->target_id) == none_id) || ((this->target) == 0))
  {
    this->mode = 2;
    return;
  }
  VecCopy(&prev_position, &position);
  VecCopy((Vec *)(&stack.x), &this->target->position);
  stack.y = position.y;
  subtract_vector(&stack, &this->position);
  if (2.0f < vec_squared_length(&stack))
  {
    normalize_vector(&stack);
    stack.x *= 2.0f;
    stack.z *= 2.0f;
  }
  vec3_add_to(&this->position, &stack);
  update_enemy_collision_flags();
  prev_y = prev_position.y;
  position.y = (f32) ((0.5f * ((25.0f + this->target->position.y) - prev_y)) + prev_y);
  calc_attach_pos();
  this->rotation_y = (s32) (10430.38043493439 * atan2_float((f64) stack.x, (f64) stack.z));
  refresh_collision_body_centers();
}
#pragma pop
void TOMine::set_armed() {
    this->mode = 2;
    set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    calc_attach_pos();
    refresh_collision_body_centers();
    play_effect_sound();
}
void TOMine::update_trigger() {
    s16 mode;
    if (((u16) this->entity_id >= 0x4000U) && ((uaddr) this->set_entry != 0U) && (access_object_saved_state(&mode, 1) != 0)) {
        this->mode = 3;
        mode = this->mode;
        send_object_state_update(&mode);
    }
}
f32 TOMine::receive_direct_attack(TObjBase *player, DirectAttackPayload payload, CollisionBody *, s32, s32) {
  s32 kind;
  s32 locally_controlled;
  if (player == 0)
  {
    return 0.0f;
  }
  if (this->is_target_in_list(player) == 1)
  {
    return 0.0f;
  }
  locally_controlled = 0;
  if ((player->get_entity_id() < 4U) && (((TObjChara *)player)->is_locally_controlled() != 0))
  {
    locally_controlled = 1;
  }
  if (locally_controlled != 0)
  {
    kind = payload.kind;
    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x13:
      this->receive_physical_attack(0, 1.0f);
      break;
    }
  }
  return 0.0f;
}
f32 TOMine::receive_weapon_special_attack(TObjChara *player, CollisionBody *) {
    if (is_target_in_list(player) == 1) {
        return 0.0f;
    }
    if ((player->is_locally_controlled() != 0) && (((TObjPlayer *)player)->obj_getS16_116() != 0)) {
        this->receive_physical_attack(0, 1.0f);
    }
    return 0.0f;
}
f32 TOMine::receive_physical_attack(TObjChara *, f32) {
    s16 mode;
    if (((u16) this->entity_id >= 0x4000U) && ((uaddr) this->set_entry != 0U) && (access_object_saved_state(&mode, 1) != 0)) {
        this->mode = 5;
        mode = this->mode;
        send_object_state_update(&mode);
    }
    return 0.0f;
}
void TOMine::apply_saved_state(s16 *state, s32 live) {
    s16 mode;
    mode = *state;
    if (mode == 5) {
        if (live == 1) {
            play_trigger_effects();
        }
        set_flag8();
        queue_destruction();
        access_object_saved_state(state, 0);
        return;
    }
    if (mode == 3) {
        this->mode = mode;
        set_indexed_flags(0, 1);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        this->calc_attach_pos();
        refresh_collision_body_centers();
        this->play_effect_sound();
        access_object_saved_state(state, 0);
        this->queue_destruction_for_each_node();
    }
}
void TOMine::play_trigger_effects() {
    spawn_particle_effect(&body_center, 0x47);
    this->spawn_blast_particle();
    this->play_trigger_sound();
}
// Slot 82: the detonation particle (inferred; was named detonate_if_triggered on TOMineTrap).
void TOMine::spawn_blast_particle() {
    {
        TParticleCtrl *particle = spawn_particle_effect(&body_center, 0x45);
        if (particle != NULL) {
            particle->set_scale(1.25f, 1.25f);
        }
    }
}
// Slot 80: plays the floor area's mine_trap_keymachine_table sound (was named attach_to_keymachine on TOMineTrap).
void TOMine::play_trigger_sound() {
    s32 area = get_current_floor_area();
    s32 elem = mine_trap_keymachine_table[area];
    if (elem != -1) {
        play_sound_effect(elem, &position, 0, 0);
    }
}
// Slot 81: plays the floor area's mine_trap_effect_table sound (was named spawn_effect on TOMineTrap).
void TOMine::play_effect_sound() {
    s32 area = get_current_floor_area();
    s32 elem = mine_trap_effect_table[area];
    if (elem != -1) {
        play_sound_effect(elem, &position, 0, 0);
    }
}
void TOMine::update_state() {
    s32 group;
    group_id = (s32) this->scale.z;
    group = group_id;
    if (group < 0) {
        this->behavior = 0;
        return;
    }
    if (group > 0) {
        this->behavior = 1;
        return;
    }
    if (get_main_phase() == 0xE) {
        this->behavior = 0;
        this->set_params[2] = 0x1E;
        return;
    }
    this->behavior = 2;
}
const char *TOMine::get_name() { return (const char *)get_localized_text_entry(16, 16); }
void TOMine::vfunc_85() {  }
void TOMine::apply_object_set_data(void *set_data) {
    TObjBase::apply_object_set_data(set_data);
    this->spawn_disp_objects();
    VecCopy(&float_position, &position);
}
void TOMine::spawn_disp_objects() {
    TOMineDisp *disp;
    u16 i;
    if (is_split_screen() == 0) {
        disp = new TOMineDisp(this, local_client_id);
        if (disp != NULL) {
            VecCopy(&disp->home_position, &home_position);
            VecCopy(&disp->position, &position);
        }
    } else {
        for (i = 0; i != 4; i++) {
            disp = new TOMineDisp(this, i);
            if (disp != NULL) {
                VecCopy(&disp->home_position, &home_position);
                VecCopy(&disp->position, &position);
            }
        }
    }
}

s32 TOMine::select_melee_contact_body(TObjChara *attacker, f32) {
    if (is_target_in_list(attacker) == 1) {
        return 0;
    }
    if (((s32) this->behavior == 2) && (attacker == this->target)) {
        return 0;
    }
    if (attacker->is_locally_controlled() != 0) {
        return 1;
    }
    return 0;
}

int TOMine::calc_distance_accuracy_penalty(TObjChara *attacker, CollisionBody *, const Vec *, float) {
    if (is_target_in_list(attacker) == 1) {
        return 0;
    }
    if (((s32) this->behavior == 2) && (attacker == this->target)) {
        return 0;
    }
    if (attacker->is_locally_controlled() != 0) {
        return 1;
    }
    return 0;
}


void TOMine::vfunc_79() {  }
void TOMine::apply_knockback_from_attacker(TObjBase *, f32) {  }
s32 TOMine::try_start_action(TObjChara *, s32, f32) { return 1; }
s32 TOMine::roll_physical_accuracy(TObjChara *, s32, f32) { return 1; }
s32 TOMine::is_target_in_list(void *obj) {
    if (obj != 0) {
        u32 id = ((TObjBase *)(obj))->get_entity_id();
        if (id < 4) {
            TObject *n;
            for (n = m_down; n != 0; n = n->m_next) {
                if (static_cast<TOMineDisp *>(n)->matches_id(id) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
#pragma push
#pragma fp_contract on
TOMineTrap::TOMineTrap(TObjBase *owner, s16 kind, s16 slot) : TOMine(tl_05) {
    TObjPlayer *player;
    s32 floor;
    f32 area_scale;

    m_name = TOMineTrap::class_name;
    owner_message_state = 0;
    if (owner != NULL) {
        set_trap_type(owner->get_entity_id());
    } else {
        m_2d8 = 0xFFFF;
    }
    player = NULL;
    if (get_trap_type() != 0xFFFF && get_trap_type() < 0x1000) {
        player = get_player_by_client_id(get_trap_type());
    }
    get_current_floor_area();
    floor = get_current_floor();
    if (enable_v2_features == 1 && owner != NULL && player != NULL && floor == player->get_floor() &&
        is_current_area_item_enabled() == 1 && is_boss_area() == 0) {
        switch (kind) {
        default:
            kind = 0;
        case 0:
            attack.kind = 1;
            if (lobby_rule_settings.get_rules_active() == 1) {
                attack.power = mine_trap_attack_power;
            } else {
                area_scale = mine_trap_area_scale_table[get_current_floor_area()];
                attack.power = 700.0f * area_scale *
                               (2.0f * (0.01f * (f32)player->get_actor_level_index() + 0.1f));
            }
            if (attack.power < 0.0f) {
                attack.power = 0.0f;
            }
            break;
        case 1:
            attack.kind = 2;
            attack.power = 0.0f;
            break;
        case 2:
            attack.kind = 17;
            attack.power = 0.0f;
            break;
        case 3:
            attack.kind = 18;
            attack.power = 0.0f;
            break;
        }
        trap_number = slot + kind * 20 + get_trap_type() * 80u;
        VecCopy(&float_position, VecCopy(&home_position, VecCopy(&position, &owner->position)));
        init_position_vectors();
        calc_attach_pos();
        spawn_disp_objects();
        facing = owner->rotation_y;
        alt_room = owner->alt_room;
        room = owner->room;
        switch (attack.kind) {
        default:
            attack.kind = 1;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 19:
            model = get_bml_model(mine_model_archive, 4);
            texlist = get_bml_texlist(mine_model_archive, 4);
            light_model = get_bml_model(mine_model_archive, 1);
            light_textures = get_bml_texlist(mine_model_archive, 1);
            break;
        case 15:
        case 16:
        case 17:
        case 18:
            model = get_bml_model(mine_model_archive, 5);
            texlist = get_bml_texlist(mine_model_archive, 5);
            light_model = get_bml_model(mine_model_archive, 0);
            light_textures = get_bml_texlist(mine_model_archive, 0);
            break;
        }
        mode = 0;
        detect_radius = 50.0f;
        trigger_radius = 50.0f;
        set_params[0] = 150;
        set_params[1] = 30;
        if (game_difficulty_selection == 3 && lobby_rule_settings.get_rules_active() == 0) {
            set_params[0] = 60;
            trigger_radius = 80.0f;
            set_trap_count(0);
            set_instance(1);
        }
        behavior = 0;
        target_id = 0xFFFF;
        actorFlags |= 0x60000000;
        init_collision_body_parts(this, mine_collision_body_parts, 1);
        register_object_by_id();
    } else {
        queue_destruction();
    }
}

#pragma pop
TOMineTrap::~TOMineTrap() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}


void *TOMineTrap::get_mine_data_ptr() { return &float_position; }
TOMineTrap *TOMineTrap::create_placed_trap(TObjBase *owner, s16 kind, s16 slot) {
    u16 id;
    TObjPlayer *player;
    if (enable_v2_features != 1 || owner == NULL || (id = owner->get_entity_id()) == 0xFFFF || id >= 0x1000 ||
        (player = get_player_by_client_id(id)) == NULL || player->get_floor() != get_current_floor() ||
        kind < 0 || kind >= 4 || slot < 0 || slot > 0x14) {
        return NULL;
    }
    if (is_boss_area() == 1 || is_current_area_item_enabled() == 0) {
        return NULL;
    }
    return new TOMineTrap(owner, kind, slot);
}
void TOMineTrap::destroy_matching_traps() {
    TObject *obj;
    s32 i;
    for (i = registered_player_count + registered_enemy_count; i < entity_table_count; i++) {
        obj = TObjPlayer::get_player_data(i);
        if (obj != 0 && obj->check_value_equals(TOMineTrap::class_name) != 0) {
            obj->queue_destruction();
        }
    }
}
void TOMineTrap::run_task() {
    TObjChara *attacker;
    TObjPlayer *p;
    s32 i;
    u16 id;

    update_float_height();
    switch (mode) {
    case 0:
    case 2:
        if (find_target_in_range() == 1) {
            set_triggered();
        }
        VecCopy(&body_center, &float_position);
        VecCopy(&bodies->center, &float_position);
        break;
    case 3:
        if (set_params[1]-- < 0) {
            set_state();
            send_state_packet(2);
        }
        apply_float_position();
        submit_cursor_candidate(this, -1);
        break;
    case 4:
        attacker = get_player_by_client_id(get_trap_type());
        if (attacker == NULL) {
            attacker = this;
        }
        for (i = 0; i < entity_table_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL || p == (TObjChara *)this || p->test_actor_flags(0x4000800) != 0) {
                continue;
            }
            if (p->alt_room != alt_room && p->room != room && p->room != alt_room) {
                continue;
            }
            id = p->get_entity_id();
            if (id == 0xFFFF) {
                continue;
            }
            if (id == get_trap_type() && TOMineTrap::get_trap_count() != 1) {
                continue;
            }
            if (id < 0x1000) {
                TObjChara *chara = p;
                if (TObjPlayer::get_player_count() == 1 && p->get_floor() == get_current_floor() &&
                    horizontal_distance_squared(&position, &chara->position) < trigger_radius * trigger_radius) {
                    if (chara->obj_isState2_324() == 0) {
                        target = chara;
                        switch (attack.kind) {
                        case 2:
                            target->apply_movement_ailment(0);
                            break;
                        default:
                            target->receive_direct_attack(this, attack, 0, -1, -1);
                            break;
                        }
                        target->record_attack_source(get_trap_type());
                    }
                    if (owner_message_state != 1) {
                        owner_message_state = show_owner_message(chara);
                    }
                }
            } else if (id < 0x4000) {
                if (horizontal_distance_squared(&position, &p->position) < trigger_radius * trigger_radius) {
                    target = p;
                    switch (attack.kind) {
                    case 2:
                        target->apply_movement_ailment(0);
                        target->sync_enemy_state(0);
                        break;
                    default:
                        target->receive_direct_attack(attacker, attack, 0, -1, -1);
                        break;
                    }
                    target->record_attack_source(get_trap_type());
                }
            } else if (reinterpret_cast<TObject *>(p)->check_value_equals(TOMineTrap::class_name) != 0) {
                if (horizontal_distance_squared(&position, &p->position) < trigger_radius * trigger_radius) {
                    target = p;
                    target->receive_physical_attack(this, 1.0f);
                }
            }
        }
        mode = 5;
        clear_player_status_flag(0, 1);
        play_trigger_effects();
        queue_destruction();
        break;
    }
}
void TOMineTrap::set_armed() {
    this->mode = 2;
    this->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}
void TOMineTrap::set_triggered() {
    this->mode = 3;
    this->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}
s32 TOMineTrap::find_target_in_range() {
    TObjChara *actor;
    s32 i;
    u16 id;

    target_id = 0xFFFF;
    target = 0;
    if (set_params[0] > 0) {
        set_params[0]--;
        return 0;
    }
    for (i = 0; i < registered_player_count + registered_enemy_count; i++) {
        actor = TObjPlayer::get_player_data(i);
        if (actor == NULL || actor == this || actor->test_actor_flags(0x800) != 0) {
            continue;
        }
        id = actor->get_entity_id();
        if (id == 0xFFFF) {
            continue;
        }
        if (id == get_trap_type() && TOMineTrap::get_trap_count() != 1 &&
            lobby_rule_settings.get_rules_active() != 0) {
            continue;
        }
        if (id < 0x1000) {
            if (((TObjPlayer *)actor)->get_floor() != get_current_floor()) {
                continue;
            }
            if (horizontal_distance_squared(&position, &actor->position) < detect_radius * detect_radius) {
                target_id = id;
                target = actor;
                return 1;
            }
        } else if (id < 0x4000) {
            if (horizontal_distance_squared(&position, &actor->position) < detect_radius * detect_radius) {
                target_id = id;
                target = actor;
                return 1;
            }
        }
    }
    return 0;
}
void TOMineTrap::set_state() { this->mode = 4; }
void TOMineTrap::spawn_blast_particle() {
    TParticleCtrl *r;
    switch (this->attack.kind) {
    default:
        r = spawn_particle_effect(&body_center, 0x45);
        if (r != NULL) {
            r->set_scale(1.25f, 1.25f);
        }
        break;
    case 15:
    case 16:
    case 17:
    case 18:
        spawn_particle_effect(&body_center, 0x8E);
        spawn_particle_effect(&body_center, 0x8E);
        break;
    case 6:
    case 7:
        spawn_particle_effect(&body_center, 0x8D);
        spawn_particle_effect(&body_center, 0x8D);
        break;
    }
}

f32 TOMineTrap::receive_physical_attack(TObjChara *attacker, f32) {
    switch (mode) {
    case 0:
    case 1:
    case 2:
        if ((attacker != NULL) && (reinterpret_cast<TObject *>(attacker)->check_value_equals(TOMineTrap::class_name) != 0)) {
            set_triggered();
            if (set_params[1] > 0xF) {
                set_params[1] = 0xF;
            }
            break;
        }
    case 3:
        set_state();
        send_state_packet(2);
        break;
    }
    return 0.0f;
}


void TOMineTrap::send_state_packet(u16 idx) {
    if (idx < 3) {
        G_TriggerTrap_6x80 packet;
        packet.init();
        packet.header.client_id = this->entity_id;
        packet.trap_number = this->trap_number;
        packet.what = idx;
        packet.send();
    }
}
void handle_6x80_trigger_trap(game_command_header *command) {
    G_TriggerTrap_6x80 *packet = (G_TriggerTrap_6x80 *)command;
    TOMineTrap *p;
    s32 i;
    if (packet == NULL) {
        return;
    }
    packet->bswap();
    for (i = registered_player_count + registered_enemy_count; i < entity_table_count; i++) {
        p = (TOMineTrap *)TObjPlayer::get_player_data(i);
        if (p == NULL) {
            continue;
        }
        if (reinterpret_cast<TObject *>(p)->check_value_equals(TOMineTrap::class_name) == 0) {
            continue;
        }
        if (packet->trap_number != p->get_trap_number()) {
            continue;
        }
        switch (packet->what) {
        case 0:
            switch (p->get_mode()) {
            case 0:
            case 1:
                p->set_armed();
                break;
            }
            break;
        case 1:
            switch (p->get_mode()) {
            case 0:
            case 1:
            case 2:
                p->set_triggered();
                break;
            }
            break;
        case 2:
            switch (p->get_mode()) {
            case 0:
            case 1:
            case 2:
            case 3:
                p->set_state();
                break;
            }
            break;
        }
        return;
    }
}

const char *TOMineTrap::get_name() {
    const char *name;
    TObjPlayer *player;

    name = NULL;
    player = get_player_by_client_id(get_trap_type());
    if (player != NULL) {
        name = player->get_name();
    }
    return name;
}

s32 TOMineTrap::show_owner_message(TObjChara *player) {
    const char *name;
    TObjPlayer *p;
    if (player != NULL && TTecCtrl::is_technique_ready() != 0) {
        p = get_player_by_client_id(get_trap_type());
        if (p != NULL) {
            name = p->get_name();
            if (name != NULL) {
                text_builder_reset();
                text_builder_append("\x09""C4");
                text_builder_append(name);
                text_builder_append(" TRAP\n");
                TWindowCtrl::append_message_all(get_shared_text_buffer(), 0x200);
                return 1;
            }
        }
    }
    return 0;
}

void TOMineTrap::spawn_disp_objects() {
    TOMineTrapDisp *disp;
    u16 i;

    if (is_split_screen() == 0) {
        disp = new TOMineTrapDisp(this, local_client_id, get_trap_type());
        if (disp != NULL) {
            VecCopy(&disp->home_position, &home_position);
            VecCopy(&disp->position, &position);
        }
    } else {
        for (i = 0; i != 4; i++) {
            disp = new TOMineTrapDisp(this, i, get_trap_type());
            if (disp != NULL) {
                VecCopy(&disp->home_position, &home_position);
                VecCopy(&disp->position, &position);
            }
        }
    }
}

TOMineDisp::TOMineDisp(TObject *parent, u16 client) : TObjBase(parent) {
    m_name = mine_disp_name;
    client_id = client;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    state = 0;
    m_90 = 0;
}

TOMineDisp::~TOMineDisp() {

}

void TOMineDisp::run_task() {
    TOMine *mine = static_cast<TOMine *>(this->m_up);
    TObjPlayer *player;
    switch (this->state) {
    case 0:
        player = get_player_by_client_id(this->client_id);
        if (player != NULL && player->is_locally_controlled() != 0 && can_see_traps(player) != 0) {
            if (horizontal_distance_squared(&position, &player->position) <= 40000.0f ||
                player->get_room() == this->get_room()) {
                this->state = 2;
            }
        }
        break;
    case 3:
        break;
    case 2:
        mine->submit_cursor_target(this->client_id);
        VecCopy(&this->position, (const Vec *)(((TOMineTrap *)mine)->get_mine_data_ptr()));
        break;
    }
}

void TOMineDisp::render() {
    TOMine *mine;
    s32 render_flags;
    u16 id = TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_mode());
    if (id != this->client_id) {
        return;
    }
    if (this->state != 2) {
        return;
    }
    if (this->update_object_view_visibility(400.0f, 20.0f) == 0) {
        return;
    }
    push_matrix();
    mine = static_cast<TOMine *>(this->m_up);
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    mine->draw_body();
    TParticleCtrl::begin_effect_render();
    render_flags = model_render_flags;
    saved_model_render_flags = render_flags;
    model_render_flags = render_flags | 0x20;
    set_constant_material(&this->color);
    mine->draw_light();
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

TOMineTrapDisp::TOMineTrapDisp(TObject *parent, u16 client, u16 owner) : TOMineDisp(parent, client) {
    m_name = mine_trap_disp_name;
    owner_id = owner;
}

TOMineTrapDisp::~TOMineTrapDisp() {

}

void TOMineTrapDisp::run_task() {
    TOMine *d;
    s32 hit;
    s32 i;
    TObjPlayer *pl;

    d = static_cast<TOMine *>(m_up);
    switch (state) {
    case 0:
        hit = 0;
        if (TOMineTrap::get_instance() == 1) {
            for (i = 0; i < 4; i++) {
                pl = get_player_by_client_id(i);
                if (pl != 0 && pl->is_locally_controlled() != 0) {
                    if (can_see_traps(pl) != 0 ||
                        (TTecCtrl::is_technique_ready() != 0 && owner_id == (u16)pl->get_entity_id())) {
                        if (!(horizontal_distance_squared(&position, &pl->position) <= 40000.0f)) {
                            if ((s16)pl->get_room() != (s16)this->get_room()) {
                                continue;
                            }
                        }
                        if (client_id == (u16)pl->get_entity_id()) {
                            hit = 1;
                        }
                    }
                }
            }
        }
        if (hit != 0) {
            state = 2;
        }
        return;
    case 1:
        break;
    case 2:
        d->submit_cursor_target(client_id);
        VecCopy(&position, (const Vec *)(((TOMineTrap *)d)->get_mine_data_ptr()));
        break;
    case 3:
        break;
    }
}

s32 TOMineDisp::matches_id(u16 id) {
    if (id == client_id && state != 2) {
        return 1;
    }
    return 0;
}

