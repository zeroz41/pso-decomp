#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/derolle/TBoss2Mine.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResource.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/boss/derolle/TUnk_80482EC0.h"
#include "pso/boss/derolle/TUnk_80482D04.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/boss/DragonAttackParams.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TObjPlayer_801542CC.h"

struct TBoss2MineMovement {
    f32 target_range;
    f32 base_speed;
    s32 turn_speed;
    s32 params[4];
};

// The mine's attack template: state_explode copies it, sets the power from the boss and
// hands it to TObjEneDD__sub_800BA5A4, whose setup_instance installs the collision radius.
struct TBoss2MineCollisionWords {
    s32 w[5];
};

static const DragonAttackParams boss2_mine_collision_desc = { 1, 2.0f, 50.0f, {5.0f, 1} };

const char *TBoss2Mine__name = "TBoss2Mine";

const Vec boss2_mine_shadow_scale = { 2.0f, 1.0f, 2.0f };

const NJS_ARGB boss2_mine_render_color = { 0.0f, 0.0f, 0.0f, 0.0f };


extern "C" {

f32 atan2_float(f32 y, f32 x);

f32 newton_sqrtf(s32, f32, f32, f32);

__declspec(section ".data") s32 boss2_mine_params[2] = { 0x11, 0x11 };

__declspec(section ".data") s32 boss2_mine_attack_params[2] = { 0xF, 0xF };

__declspec(section ".data") s32 boss2_mine_resist_params[2] = { 0x11, 0x11 };

TBoss2MineMovement boss2_mine_movement[2] = {
    { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } },
    { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } },
};

CollisionBody boss2_mine_collision_body = {
    { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

}

#pragma inline_depth(1)

void TBoss2Mine::apply_defense_stat_status(void *) {  }

void TBoss2Mine::apply_attack_stat_status(void *) {  }

void TBoss2Mine::clear_harmful_statuses() {  }

void TBoss2Mine::apply_shock_status() {  }

void TBoss2Mine::apply_movement_ailment(s32) {  }

void TBoss2Mine::apply_confusion_status() {  }

void TBoss2Mine::apply_slow_status() {  }

void TBoss2Mine::apply_paralysis() {  }

void TBoss2Mine::apply_poison_status() {  }

void TBoss2Mine::load_resources() { TObjPlayer::init_alt_model(); }

void TBoss2Mine::free_resources() {  }

TBoss2Mine::TBoss2Mine(TObject *parent, u16 entity_id, s32 set_index, s32 variant) : TObjEneDD(parent) {
    TBoss2DeRolLe *boss;
    m_name = TBoss2Mine__name;
    boss = TBoss2DeRolLe::get_instance();
    if (boss != 0) {
        init_common_from(boss);
    }
    this->entity_id = entity_id;
    this->set_index = set_index;
    init(variant);
}

void TBoss2Mine::init(s32 variant) {
    this->init_position_vectors();
    this->model = boss2_derolle_resource->models[3].model;
    this->texlist = boss2_derolle_resource->models[2].texlist;
    this->init_model(&boss2_mine_collision_body, 1);
    this->reset_hp(TLobby::register_boss(boss2_mine_params[variant]),
                   TLobby::dispatch_shared_handler_b(boss2_mine_attack_params[variant]),
                   TLobby::register_object(boss2_mine_resist_params[variant]));
    this->set_state_flag_2();
    this->movementParameters = &boss2_mine_movement[variant];
    this->wall_reach = 3.0f;
    this->set_intangible();
    this->mine_flags = 0;
    this->target_pos.x = 0.0f;
    this->target_pos.y = 0.0f;
    this->target_pos.z = 0.0f;
    this->throw_dir.x = 0.0f;
    this->throw_dir.y = 0.0f;
    this->throw_dir.z = 0.0f;
    this->spike_angle = 0;
    this->blast_scale = 0.0f;
    this->flash_level = 0;
    this->pulse = 0.0f;
    this->pulse_step = 0.0f;
    this->pulse_wait = 0;
    this->pulse_interval = 0;
    this->pulse_phase = 2;
    this->step = 0;
    this->timer = 0;
    this->m_3d0 = 0;
    this->tilt = 0;
    this->throw_distance = 0.0f;
    this->throw_distance_left = 0.0f;
    this->drop_distance = 0.0f;
    this->fall_speed = 0.0f;
    this->throw_speed = 0.0f;
    this->mode = 0;
    this->dispatch_action(this->mode, 4);
}

TBoss2Mine::~TBoss2Mine() {
    free_collision_body_parts(this);
}

void TBoss2Mine::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    update_status_effects();
    if (has_action_state_changed() == 0) {
        dispatch_action(mode, 3);
    }
    dispatch_action(mode, 0);
    sub_800BBA0C();
    if (!(mine_flags & 1)) {
        save_position();
        update_body_colliders();
        submit_default_cursor_candidate();
        render_minimap_dot();
    }
    refresh_collision_body_centers();
}

void TBoss2Mine::refresh_target() {  }

void TBoss2Mine::run_death_reaction() {
    if (mode != 4) {
        transition_enemy_state(4);
    }
}

void TBoss2Mine::run_hit_reaction() { clear_attack_receipts(); }

void TBoss2Mine::run_miss_reaction() {  }

void TBoss2Mine::save_position() { VecCopy(&center, &body_center); }

void TBoss2Mine::update_move_flag() {
    position.x = body_center.x;
    position.z = body_center.z;
    if (update_ground_contact() == 0) {
        mine_flags &= ~2;
        return;
    }
    mine_flags |= 2;
}

void TBoss2Mine::set_node_offsets() {
    NJS_OBJECT *node = ((NJS_OBJECT *)model)->child;
    s32 i;
    s32 angle = -spike_angle;
    for (i = 0; i < 4; i++) {
        node->ang[0] = angle;
        node = node->sibling;
    }
    angle = spike_angle;
    for (i = 0; i < 4; i++) {
        node->ang[0] = angle;
        node = node->sibling;
    }
}

void TBoss2Mine::init_params(s32 interval, f32 rate) {
    pulse_step = rate;
    pulse_interval = interval;
    pulse_phase = 0;
    pulse = 0.0f;
    pulse_wait = 0;
}

void TBoss2Mine::set_state_by_distance(s32 time_left) {
    if (time_left < 90) {
        f32 speed = 0.5f;
        pulse_interval = 3;
        pulse_step = speed;
        return;
    }
    if (time_left < 150) {
        pulse_interval = 5;
        return;
    }
    if (time_left < 300) {
        pulse_interval = 10;
        return;
    }
    pulse_interval = 30;
}

void TBoss2Mine::update_pulse_state() {
    pulse_wait++;
    switch (pulse_phase) {
    case 2:
        if (pulse_wait >= pulse_interval) {
            pulse_wait = 0;
            pulse = 0.0f;
            pulse_phase = 0;
        } else {
            mine_flags &= ~4;
            break;
        }
    case 0:
        pulse += pulse_step;
        if (pulse >= 1.0f) {
            pulse = 1.0f;
            pulse_phase = 1;
        }
        flash_level = (s32)(255.0f * pulse) << 16;
        mine_flags |= 4;
        break;
    case 1:
        pulse -= pulse_step;
        if (pulse <= 0.0f) {
            pulse = 0.0f;
            pulse_wait = 0;
            pulse_phase = 2;
        }
        flash_level = (s32)(255.0f * pulse) << 16;
        mine_flags |= 4;
        break;
    case 3:
        break;
    }
}

void TBoss2Mine::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        state_hidden(reason);
        return;
    case 1:
        state_launch(reason);
        return;
    case 2:
        state_armed(reason);
        return;
    case 3:
        state_explode(reason);
        return;
    case 4:
        state_destroyed(reason);
        return;
    }
}

void TBoss2Mine::state_hidden(s32 reason) {
    u32 flags;

    switch (reason) {
    case 4:
        set_intangible();
        mine_flags |= 1;
        mine_flags &= ~6;
        return;
    case 3:
        flags = mine_flags;
        if (flags & 0x100) {
            mine_flags = flags & ~0x100;
            transition_enemy_state(1);
        }
    case 5:
    case 0:
        return;
    }
}

void TBoss2Mine::state_launch(s32) {  }

void TBoss2Mine::state_armed(s32) {  }

void TBoss2Mine::state_explode(s32 reason) {
    DragonAttackParams hit;
    switch (reason) {
    case 4:
        clear_intangible();
        mine_flags &= ~7;
        flash_level = 0;
        step = 0;
        timer = 0;
        create_timed_particle_emitter(&bodies->center, 0x16A, 0, 6);
        return;
    case 3:
        if (timer == 2) {
            transition_enemy_state(0);
        }
    case 5:
        return;
    case 0:
        step++;
        if (step > 30) {
            *reinterpret_cast<TBoss2MineCollisionWords *>(&hit) =
                *reinterpret_cast<const TBoss2MineCollisionWords *>(&boss2_mine_collision_desc);
            hit.power = TBoss2DeRolLe::get_mine_power();
            TObjEneDD__sub_800BA5A4(this, &hit);
            spawn_particle_effect_with_flags(&bodies->center, 0x16B, 0x40);
            timer = 2;
            play_sound_effect(0x4003AD05, &body_center, 0, 0);
        }
        break;
    }
}

void TBoss2Mine::state_destroyed(s32 reason) {
    switch (reason) {
    case 4:
        clear_intangible();
        mine_flags &= ~7;
        return;
    case 3:
        transition_enemy_state(0);
        return;
    case 5:
        actorFlags &= ~0x800;
        hp = hpmax;
    case 0:
        return;
    }
}

void TBoss2Mine::render() {
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    if (mine_flags & 1) {
        return;
    }
    if (update_object_view_visibility(400.0f, 20.0f) == 0) {
        return;
    }
    if (mine_flags & 2) {
        Vec shadow_scale = boss2_mine_shadow_scale;
        TObjEnemy::draw_ground_shadow(&shadow_scale, 0);
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    TObjPlayer::toggle_particle_effect();
    set_node_offsets();
    push_matrix();
    post_translate_matrix(&position.x);
    translate_matrix(0, 0.0f, body_center.y - position.y, 0.0f);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    rotate_matrix_y(NULL, rotation_z);
    translate_matrix(0, 0.0f, -10.0f, 0.0f);
    if (mine_flags & 4) {
        model_render_flags |= 0x20;
        NJS_ARGB color = boss2_mine_render_color;
        f32 f = -(f32)(flash_level >> 16) / 255.0f;
        color.b = f;
        color.g = f;
        color.r = -f;
        set_constant_material(&color);
        draw_chunk_object(model);
    } else {
        draw_chunk_object(model);
    }
    pop_matrix();
    if (mode == 3) {
        push_matrix();
        f32 s = 0.5f * blast_scale;
        post_translate_matrix(&position.x);
        scale_matrix(NULL, s, 3.0f, s);
        draw_chunk_object(debug_cylinder_object);
        pop_matrix();
    }
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
}

void TBoss2Mine::run_demo_task() {  }

void TBoss2Mine::render_demo() {  }

TUnk_80482EC0::TUnk_80482EC0(TObject *parent, u16 entity_id, s32 set_index)
    : TBoss2Mine(parent, entity_id, set_index, 0) {}

TUnk_80482EC0::~TUnk_80482EC0() {}

void TUnk_80482EC0::update_body_colliders() {
    bodies->offset.y = 5.0f + (body_center.y - position.y);
}

void TBoss2Mine::set_launch_position_velocity(const Vec *start, const Vec *target) {
    mine_flags |= 0x100;
    VecCopy(&body_center, start);
    VecCopy(&target_pos, target);
    target_pos.y += 1.0f;
    VecCopy(&position, &body_center);
    spike_angle = 0;
    hp = hpmax;
    actorFlags &= ~0xA00;
}

#pragma push
#pragma fp_contract on
void TUnk_80482EC0::state_launch(s32 reason) {
    f32 fall_time;
    f32 y;
    s32 angle;
    switch (reason) {
    case 4:
        set_intangible();
        mine_flags &= ~7;
        VecCopy(&throw_dir, &target_pos);
        subtract_vector(&throw_dir, &body_center);
        throw_distance = normalize_vector_xz(&throw_dir);
        angle = (s32)(10430.38043493439 * atan2_float(throw_dir.x, throw_dir.z));
        rotation_y = angle;
        rotation_x = 0x4000;
        y = body_center.y;
        fall_time = newton_sqrtf(angle, (2.0f * (y - target_pos.y)) / 0.2f, y, 2.0f);
        drop_distance = 10.0f * fall_time;
        throw_speed = 10.0f;
        fall_speed = 0.0f;
        tilt = 0;
        throw_distance_left = throw_distance;
        break;
    case 3:
        if (body_center.y < target_pos.y) {
            body_center.y = target_pos.y;
            transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        body_center.x = throw_dir.x * throw_speed + body_center.x;
        body_center.z = throw_dir.z * throw_speed + body_center.z;
        throw_distance_left = throw_distance_left - throw_speed;
        if (throw_distance_left < drop_distance) {
            fall_speed = fall_speed - 0.2f;
            body_center.y = body_center.y + fall_speed;
            if (rotation_x >= 0x8000) {
                rotation_x = 0x8000;
            } else {
                tilt = tilt + 0x300;
                rotation_x = tilt + 0x4000;
            }
        } else {
            rotation_x = 0x4000;
        }
        update_move_flag();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_80482EC0::state_armed(s32 reason) {
    u32 flags;
    s32 extra;
    switch (reason) {
    case 4:
        clear_intangible();
        mine_flags &= ~5;
        mine_flags |= 2;
        rotation_x = 0x8000;
        flash_level = 0;
        step = 0;
        extra = (s32)(30.0f * calc_elapsed_scaled());
        timer = extra + 180;
        play_sound_effect(0x4003A804, &body_center, 0, 0);
        init_params(30, 0.25f);
        return;
    case 3:
        flags = mine_flags;
        if (flags & 0x100) {
            mine_flags = flags & ~0x100;
            transition_enemy_state(1);
        }
        if (step == 2) {
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        switch (step) {
        case 0:
            spike_angle = spike_angle + 0x280;
            if (spike_angle >= 0x38E3) {
                spike_angle = 0x38E3;
                step = 1;
                return;
            }
            break;
        case 1:
            timer = timer - 1;
            if (timer <= 0) {
                step = 2;
            }
            set_state_by_distance(timer);
            update_pulse_state();
            break;
        }
        break;
    }
}
#pragma pop

TUnk_80482D04::TUnk_80482D04(TObject *parent, u16 entity_id, s32 set_index)
    : TBoss2Mine(parent, entity_id, set_index, 1) {
    owner = NULL;
    slot = 0;
    owner_offset.x = 0.0f;
    owner_offset.y = 0.0f;
    owner_offset.z = 0.0f;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = 0.0f;
}

TUnk_80482D04::~TUnk_80482D04() {}

void TUnk_80482D04::update_body_colliders() {
    bodies->offset.y = 1.0f + (body_center.y - position.y);
}

void TUnk_80482D04::move_mine() {
    if (owner->is_alive() != 0) {
        VecCopy(&target_pos, &owner->position);
        vec3_add_to(&target_pos, &owner_offset);
        target_pos.y += 17.0f;
    }
}

void TUnk_80482D04::init_launch(Vec *pos, TObjBase *owner, s32 slot) {
    s32 angle;
    s32 heading;
    this->mine_flags |= 0x100;
    VecCopy(&this->body_center, pos);
    this->owner = owner;
    angle = slot * 0x5555;
    this->slot = slot;
    this->owner_offset.x = 20.0f * sin_table_lookup(angle);
    this->owner_offset.y = 0.0f;
    this->owner_offset.z = 20.0f * cos_table_lookup(angle);
    if (slot == 0) {
        heading = 0x8000;
    } else if (slot == 1) {
        heading = 0x6800;
    } else {
        heading = 0x9800;
    }
    this->direction.x = sin_table_lookup(heading);
    this->direction.y = 0.0f;
    this->direction.z = cos_table_lookup(heading);
    this->rotation_y = heading;
    this->target_pos.x = 0.0f;
    this->target_pos.y = 0.0f;
    this->target_pos.z = 0.0f;
    this->move_mine();
    this->rotation_x = 0x4000;
    VecCopy(&this->position, &this->body_center);
    this->spike_angle = 0;
    this->hp = this->hpmax;
    this->actorFlags &= ~0xA00;
}

#pragma push
#pragma fp_contract on
void TUnk_80482D04::state_launch(s32 reason) {
    Vec to_target;
    f32 t;
    switch (reason) {
    case 4:
        set_intangible();
        mine_flags &= ~7;
        spike_angle = 0;
        rotation_x = 0x4000;
        rotation_z = 0;
        step = 1;
        timer = 0;
        launch_speed = 8.0f;
        homing_weight = 0.0f;
        break;
    case 3:
        if (step == 3) {
            transition_enemy_state(2);
        }
        break;
    case 0:
        switch (step) {
        case 0:
            timer++;
            if (timer >= 15) {
                step = 1;
                play_sound_effect(0x4003A804, &body_center, 0, 0);
            }
            body_center.x = direction.x * launch_speed + body_center.x;
            body_center.z = direction.z * launch_speed + body_center.z;
            break;
        case 1:
            spike_angle += 0x400;
            if (spike_angle >= 0x38E3) {
                spike_angle = 0x38E3;
                step = 2;
            }
            body_center.x = direction.x * launch_speed + body_center.x;
            body_center.z = direction.z * launch_speed + body_center.z;
            break;
        case 2:
            rotation_x -= 0x600;
            if (rotation_x < 0) {
                rotation_x = 0;
            }
            rotation_z += 2560.0f;
            launch_speed -= 0.2f;
            if (launch_speed <= 3.0f) {
                launch_speed = 3.0f;
            }
            move_mine();
            VecCopy(&to_target, &target_pos);
            subtract_vector(&to_target, &body_center);
            if (normalize_vector_safe(&to_target) <= 4.5f) {
                step = 3;
            }
            homing_weight += 0.05f;
            if (homing_weight > 3.0f) {
                homing_weight = 3.0f;
            }
            t = homing_weight / launch_speed;
            direction.x = to_target.x * t + direction.x;
            direction.y = to_target.y * t + direction.y;
            direction.z = to_target.z * t + direction.z;
            normalize_vector_safe(&direction);
            body_center.x = direction.x * launch_speed + body_center.x;
            body_center.y = direction.y * launch_speed + body_center.y;
            body_center.z = direction.z * launch_speed + body_center.z;
            break;
        }
        update_move_flag();
        break;
    case 5:
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_80482D04::state_armed(s32 reason) {
    Vec to_target;
    f32 s;
    switch (reason) {
    case 4:
        clear_intangible();
        mine_flags &= ~5;
        mine_flags |= 2;
        rotation_x = 0;
        flash_level = 0;
        step = 0;
        timer = (s32)(60.0f * calc_elapsed_scaled()) + 240;
        init_params(30, 0.25f);
        break;
    case 3:
        if (mine_flags & 0x100) {
            mine_flags &= ~0x100;
            transition_enemy_state(1);
        }
        if (step == 1) {
            transition_enemy_state(3);
        }
        break;
    case 0:
        timer--;
        if (timer <= 0) {
            step = 1;
        }
        rotation_z += 2560.0f;
        move_mine();
        VecCopy(&to_target, &target_pos);
        subtract_vector(&to_target, &body_center);
        s = normalize_vector_xz(&to_target);
        s *= 0.75f;
        if (s < 0.2f) {
            VecCopy(&body_center, &target_pos);
        } else {
            if (s > 4.0f) {
                s = 4.0f;
            }
            body_center.x = to_target.x * s + body_center.x;
            body_center.y = target_pos.y;
            body_center.z = to_target.z * s + body_center.z;
        }
        set_state_by_distance(timer);
        update_pulse_state();
        position.x = body_center.x;
        position.z = body_center.z;
        check_collisions();
        body_center.x = position.x;
        body_center.z = position.z;
        update_move_flag();
        break;
    case 5:
        break;
    }
}
#pragma pop
