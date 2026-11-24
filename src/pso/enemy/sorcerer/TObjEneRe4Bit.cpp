#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/enemy/sorcerer/TObjEneRe4Bit.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/render/model_render_state.h"
#include "pso/enemy/sorcerer/Re4BitData.h"
#include "pso/object/base/TObjBase.h"
#pragma defer_codegen on

NJS_OBJECT *TObjEneRe4Bit__model;
NJS_TEXLIST *re4_bit_texture_list;
const char *TObjEneRe4Bit__name = TObjEneRe4Bit__class_name_string;

TObjEneRe4InitParams re4_bit_init_params = {225.0f, 0.0f, 0x600};
CollisionBody re4_bit_model_node_desc = {{0.0f, 0.0f, 0.0f}, 2.0f, 0.0f, 0, 0x8003};

__declspec(section ".data") player_stats *TObjEneRe4Bit_boss_handles[2];
__declspec(section ".data") AttackParams *TObjEneRe4Bit_attack_handles[2];
__declspec(section ".data") ActorParamBlock *TObjEneRe4Bit_resistance_handles[2];
__declspec(section ".data") void *TObjEneRe4Bit_behavior_params[2];

void TObjEneRe4Bit::apply_defense_stat_status(void *) {  }

void TObjEneRe4Bit::apply_attack_stat_status(void *) {  }

void TObjEneRe4Bit::clear_harmful_statuses() {  }

void TObjEneRe4Bit::apply_shock_status() {  }

void TObjEneRe4Bit::apply_movement_ailment(s32) {  }

void TObjEneRe4Bit::apply_confusion_status() {  }

void TObjEneRe4Bit::apply_slow_status() {  }

void TObjEneRe4Bit::apply_paralysis() {  }

void TObjEneRe4Bit::apply_poison_status() {  }

void TObjEneRe4Bit::load_resources() {
    s32 i;
    TObjEneRe4Bit__model = sorcerer_bml_resource->models[1].model;
    re4_bit_texture_list = sorcerer_bml_resource->models[0].texlist;
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit_boss_handles[i] = TLobby::register_boss(re4_bit_base_param_ids[i]);
        TObjEneRe4Bit_attack_handles[i] = TLobby::dispatch_shared_handler_b(re4_bit_attack_param_ids[i]);
        TObjEneRe4Bit_resistance_handles[i] = TLobby::register_object(re4_bit_resistance_param_ids[i]);
        TObjEneRe4Bit_behavior_params[i] = TLobby::dispatch_shared_handler_a(re4_bit_behavior_param_ids[i]);
    }
}

void TObjEneRe4Bit::free_resources() {  }

TObjEneRe4Bit *TObjEneRe4Bit::create(TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index) {
    return new TObjEneRe4Bit(tl_04, owner, anchor, enabled, id, set_index);
}

void TObjEneRe4Sorcerer::create_disabled(Vec *anchor, u16 id, s32 set_index) {
    TObjEneRe4Bit::create(this, anchor, 0, id, set_index);
}

void TObjEneRe4Sorcerer::create_enabled(Vec *anchor, u16 id, s32 set_index) {
    TObjEneRe4Bit::create(this, anchor, 1, id, set_index);
}

TObjEneRe4Bit::TObjEneRe4Bit(TObject *parent, TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index)
    : TObjEneDD_ST(parent) {
    m_name = TObjEneRe4Bit__name;
    init_common_from(owner);
    owner_id = ((TObjBase *)owner)->get_entity_id();
    entity_id = id;
    this->set_index = set_index;
    this->anchor = anchor;
    this->enabled = enabled;
    VecCopy(&position, anchor);
    init();
}

void TObjEneRe4Bit::init() {
    s32 i;

    init_position_vectors();
    model = TObjEneRe4Bit__model;
    texlist = re4_bit_texture_list;
    init_model(&re4_bit_model_node_desc, 1);
    i = enabled == 1 ? 0 : 1;
    reset_hp(TObjEneRe4Bit_boss_handles[i], TObjEneRe4Bit_attack_handles[i], TObjEneRe4Bit_resistance_handles[i]);
    set_state_8();
    movementParameters = &re4_bit_init_params;
    if (enabled == 1) {
        initialize_enemy_state(0x20);
    } else {
        initialize_enemy_state(0x21);
    }
    wall_reach = 3.0f;
    behavior_flags = 0;
    texture_index = 3;
    technique_texture = 3;
    lift_height = 0.0f;
    fade.reset_obstruction_fade();
    homing_velocity.x = 0.0f;
    homing_velocity.y = 0.0f;
    homing_velocity.z = 0.0f;
    cast_state = 0;
    state_step = 0;
    pad_40c = 0;
    hide();
    call_vt_90_91();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneRe4Bit::~TObjEneRe4Bit() {
    free_collision_body_parts(this);
}

void TObjEneRe4Bit::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    if (update_status_effects() == 1 || (behavior_flags & 0x2000) == 0) {
        update_action_state();
        clear_state_flags_when_done();
    } else {
        behavior_flags &= ~0x2000;
    }
    copy_pos();
    update_body_colliders();
    submit_default_cursor_candidate();
}

void TObjEneRe4Bit::refresh_target() {  }

void TObjEneRe4Bit::run_death_reaction() {
    s16 m = mode;
    if (m != 6) {
        if (m == 2) {
            transition_enemy_state(6);
            cast_state = 3;
            return;
        }
        transition_enemy_state(6);
    }
}

void TObjEneRe4Bit::run_hit_reaction() {
    if (mode != 5) {
        if (behavior_flags & 0x1000) {
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(5);
    }
}

void TObjEneRe4Bit::run_miss_reaction() {  }

void TObjEneRe4Bit::copy_pos() { VecCopy(&center, &body_center); }

void TObjEneRe4Bit::update_body_colliders() {
    bodies->offset.y = body_center.y - position.y;
}

void TObjEneRe4Bit::update_position_flag() {
    Vec pos;

    VecCopy(&pos, &body_center);
    if (move_xz_on_ground(&pos) == 0) {
        behavior_flags &= ~0x800;
        return;
    }
    behavior_flags |= 0x800;
}

#pragma push
#pragma fp_contract on
void TObjEneRe4Bit::update_homing_velocity() {
    Vec dir;
    f32 s;
    VecCopy(&dir, anchor);
    dir.y = dir.y + lift_height;
    subtract_vector(&dir, &body_center);
    s = 0.01f * normalize_vector_safe(&dir);
    homing_velocity.x = 0.9f * (dir.x * s + homing_velocity.x);
    homing_velocity.y = 0.9f * (dir.y * s + homing_velocity.y);
    homing_velocity.z = 0.9f * (dir.z * s + homing_velocity.z);
    vec3_add_to(&body_center, &homing_velocity);
    position.x = body_center.x;
    position.z = body_center.z;
}
#pragma pop

s32 TObjEneRe4Bit::can_cast() {
    s16 m;
    u8 result;
    m = mode;
    result = 0;
    if ((m != 5) && (m != 6)) {
        result = 1;
    }
    return result;
}

s32 TObjEneRe4Bit::get_state() { return cast_state; }

Vec *TObjEneRe4Bit::get_spell_data() { return &body_center; }

void TObjEneRe4Bit::reset_texture() { texture_index = 3; }

void TObjEneRe4Bit::set_state_flag_and_mode(s32 kind) {
    behavior_flags |= 0x1;
    switch (kind) {
    case 0:
        technique_texture = 4;
        return;
    case 1:
        technique_texture = 5;
        return;
    case 2:
        technique_texture = 6;
        return;
    }
}

void TObjEneRe4Bit::set_attack_flag() { behavior_flags |= 0x2; }

void TObjEneRe4Bit::hide() { behavior_flags &= ~0x100; }

void TObjEneRe4Bit::set_flag_and_notify() {
    behavior_flags |= 0x10;
    if (!(behavior_flags & 0x4)) {
        set_hold_flags();
    }
}

void TObjEneRe4Bit::set_hold_flags() {
    behavior_flags |= 0x204;
    behavior_flags &= ~0x8;
    fade.reset_color();
}

void TObjEneRe4Bit::clear_state_flag_0x10() {
    behavior_flags &= ~0x10;
    if (!(behavior_flags & 0x408)) {
        set_state_flags();
    }
}

void TObjEneRe4Bit::set_state_flags() {
    behavior_flags &= ~0x4;
    behavior_flags |= 0x308;
    fade.reset_obstruction_fade();
}

void TObjEneRe4Bit::invoke_state_callbacks() {
    set_invulnerable();
    disable_body_collision();
}

void TObjEneRe4Bit::call_vt_90_91() {
    clear_invulnerable();
    enable_body_collision();
}

void TObjEneRe4Bit::set_flag3cc_bit2000() { behavior_flags |= 0x2000; }

void TObjEneRe4Bit::reset_transform() {
    VecCopy(&body_center, anchor);
    homing_velocity.x = 0.0f;
    homing_velocity.y = 0.0f;
    homing_velocity.z = 0.0f;
    update_position_flag();
    transform_part_positions();
}

void TObjEneRe4Bit::clear_state_flags_when_done() {
    u32 flags = behavior_flags;
    if (flags & 0x4) {
        if (fade.decay_value_toward_floor() != 0) {
            behavior_flags &= ~0x4;
            behavior_flags &= ~0x200;
            behavior_flags &= ~0x100;
        }
    } else if ((flags & 0x8) && fade.advance_toward_max() != 0) {
        behavior_flags &= ~0x8;
        behavior_flags &= ~0x200;
    }
}

void TObjEneRe4Bit::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_state_message(reason);
        return;
    case 1:
        handle_event(reason);
        return;
    case 2:
        update_raise_state(reason);
        return;
    case 3:
        update_lower_state(reason);
        return;
    case 5:
        update_damage_state(reason);
        return;
    case 6:
        update_death_state(reason);
    default:
        return;
    }
}

void TObjEneRe4Bit::handle_state_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        transition_enemy_state(1);
        return;
    }
}

void TObjEneRe4Bit::handle_event(s32 mode) {
    u32 flags;

    switch (mode) {
    case 4:
        set_field_378(1);
        behavior_flags &= ~0x1000;
        break;
    case 3:
        flags = behavior_flags;
        if (flags & 0x1) {
            behavior_flags = flags & ~0x1;
            transition_enemy_state(2);
            break;
        }
        if (flags & 0x2) {
            behavior_flags = flags & ~0x2;
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        update_homing_velocity();
        update_position_flag();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneRe4Bit::update_raise_state(s32 reason) {
    u32 flags;
    switch (reason) {
    case 4:
        this->set_field_378(3);
        this->behavior_flags |= 0x1000;
        this->state_step = 0;
        this->cast_state = 1;
        this->texture_index = this->technique_texture;
        return;
    case 3:
        flags = this->behavior_flags;
        if (flags & 0x2) {
            this->behavior_flags = flags & ~0x2;
            this->transition_enemy_state(3);
        }
        return;
    case 0:
        switch (this->state_step) {
        case 1:
            break;
        case 0:
            this->lift_height += 0.8f;
            if (this->lift_height > 20.0f) {
                this->lift_height = 20.0f;
                this->state_step = 1;
                this->cast_state = 2;
            }
            this->rotation_y = this->rotation_y + 0x1800;
            break;
        }
        this->update_homing_velocity();
        this->update_position_flag();
        return;
    case 5:
        this->cast_state = 0;
        break;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TObjEneRe4Bit::update_lower_state(s32 reason) {
    switch (reason) {
    case 4:
        this->set_field_378(3);
        this->behavior_flags &= ~0x1000;
        this->texture_index = 3;
        break;
    case 3:
        if (this->lift_height <= 0.0f) {
            this->transition_enemy_state(1);
            break;
        }
    case 5:
        break;
    case 0:
        this->lift_height -= 0.8f;
        if (this->lift_height < 0.0f) {
            this->lift_height = 0.0f;
        }
        this->rotation_y = this->rotation_y - 0x1800;
        this->update_homing_velocity();
        this->update_position_flag();
        break;
    }
}
#pragma pop

void TObjEneRe4Bit::update_damage_state(s32 reason) {
    switch (reason) {
    case 4:
        this->state_step = 0;
        return;
    case 3:
        if (this->state_step > 0xF) {
            this->transition_enemy_state(1);
        }
        return;
    case 0:
        this->state_step = this->state_step + 1;
        VecCopy(&this->body_center, this->anchor);
        this->body_center.y = this->body_center.y + this->lift_height;
        this->body_center.x = this->body_center.x + ((TObjEneDD *)this)->calc_elapsed_scaled();
        this->body_center.z = this->body_center.z + ((TObjEneDD *)this)->calc_elapsed_scaled();
        this->update_ground_contact();
        return;
    case 5:
        this->clear_attack_receipts();
        return;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneRe4Bit::update_death_state(s32 reason) {
    u32 flags;
    switch (reason) {
    case 4:
        this->state_step = 0;
        this->set_hold_flags();
        this->behavior_flags |= 0x400;
        play_sound_effect(this->remap_sound_for_area(0x4003A815), &this->position, 0, 0);
        break;
    case 3:
        if (this->behavior_flags & 0x8) {
            play_sound_effect(this->remap_sound_for_area(0x4003AD16), &this->position, 0, 0);
            this->transition_enemy_state(1);
        }
        break;
    case 0:
        this->state_step = this->state_step + 1;
        if (this->state_step >= 900) {
            flags = this->behavior_flags;
            if (!(flags & 0x10)) {
                this->behavior_flags = flags & ~0x400;
                this->set_state_flags();
                return;
            }
        }
        break;
    case 5:
        this->actorFlags &= ~0x800;
        this->hp = this->hpmax;
        this->reset_texture();
        this->lift_height = 0.0f;
        break;
    }
}
#pragma pop

void TObjEneRe4Bit::render() {
    f32 range;
    s32 saved;
    s32 draw;
    NJS_TEXNAME *textures;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        range = view_detail_far_depth;
    } else {
        range = 400.0f;
    }
    if (!(behavior_flags & 0x100)) {
        return;
    }
    if (update_object_view_visibility(range, 20.0f) == 0) {
        return;
    }
    if (behavior_flags & 0x800) {
        Vec v = re4_bit_render_vec.scale;
        TObjEnemy::draw_ground_shadow(&v, 0);
    }
    update_secondary_light();
    textures = ((NJS_TEXLIST *)texlist)->textures;
    saved = textures[3].texaddr;
    textures[3].texaddr = textures[texture_index].texaddr;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    TObjPlayer::toggle_particle_effect();
    draw = 1;
    if (behavior_flags & 0x200) {
        fade.set_flags_and_apply_damage_color();
        if (defer_render() != 0) {
            draw = 0;
        }
    }
    if (draw != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, body_center.y - position.y, 0.0f);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, 2.0f, 2.0f, 2.0f);
        draw_chunk_object(model);
        pop_matrix();
    }
    fade.clear_flag_and_notify();
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    update_primary_light();
    ((NJS_TEXLIST *)texlist)->textures[3].texaddr = saved;
}
