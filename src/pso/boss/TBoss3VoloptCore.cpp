#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/boss/TBoss3VoloptCore.h"
#include "pso/boss/TBoss3VoloptMonitor.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TUnk_80484888.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/TMainTask.h"

// The actors check_target_collision hits, with slot 25 as it is called here:
// the base declares apply_knockback_from_attacker(u8 *) without the strength.
struct TBoss3VoloptCoreTarget : public TUnk_804AF8A0 {
    virtual s32 add_actor_exp(s32 exp);
    virtual s32 consume_timer_field(s32 frames);
    virtual s32 get_actor_level_index();
    virtual u8 *update_actor_ground_y();
    virtual u8 *vfunc_18(u8 *);
    virtual s32 is_actor_cadence_frame(s32 frame);
    virtual s32 select_melee_contact_body(TObject *attacker, f32 range);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, f32);
    virtual f32 receive_physical_attack(TObject *attacker, f32 scale);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void apply_knockback_from_attacker(TObject *attacker, f32 strength);
};

struct TBoss3VoloptOrbitSpeeds {
    u8 pad_0[0x18];
    s32 speeds[1];
};

extern "C" {
extern s32 local_client_id;
extern u32 model_render_flags;
void *find_entity_by_id(u16 id);
TObjPlayer *get_player_by_client_id(s32 client_id);
void advance_animation_playback(TObjMotion *motion);
void minimap_render_dot(f32 *pos, s32 color, s32, s32);
void play_persistent_sound(u32 id, TObject *source, f32 *pos, s32, s32);
void play_sound_effect(u32 id, f32 *pos, s32, s32);
s32 angle_difference_abs(s32 a, s32 b);
s32 approach_angle_limited(s32 angle, s32 target, s32 step);
TObject *create_particle_emitter(Vec *pos, s32 id);
f32 cos_table_lookup(s32 angle);
void push_matrix(void);
void pop_matrix(void);
void set_matrix_identity(s32 matrix, f32 scale);
void rotate_matrix_x(s32 matrix, s32 angle);
void rotate_matrix_y(s32 matrix, s32 angle);
void scale_matrix(s32 matrix, f32 x, f32 y, f32 z);
void post_translate_matrix(f32 *pos);
void rotate_vector_by_matrix(s32 matrix, Vec *src, Vec *dst);
void vec3_add_to(Vec *dst, Vec *add);
void subtract_vector(Vec *dst, Vec *sub);
void draw_chunk_object(void *object);
void free_collision_body_parts(TObjEnemyCustom *object);
void init_collision_body_parts(TObjEnemyCustom *object, TBoss3VoloptCoreBodyPart *parts, s32 count);
void obj_setFlags30(TObjEnemyCustom *object, u32 flags);
s32 obj_is_hit_receivable(TBoss3VoloptCoreTarget *object);
void TCameraCtrl__sub_8006A044(s32 id, f32 strength);
}
void reset_status_effect_row(u8 *row);

#pragma readonly_strings on
static const char *TBoss3VoloptCore_name = "TBoss3VoloptCore";
static void *core_combat_stats_a;
static void *core_combat_stats_b;
static void *core_combat_stats_c;
static TBoss3VoloptOrbitSpeeds *core_orbit_speeds;
static BmlResource *core_resources;
s32 boss3_volopt_core_active_flag;
static s32 core_turn_angle_limit;

static TObjMotionAction core_motions[5] = {
    { 1, 0, 0xE, 0.7f, 0x0 },
    { 1, 0, 0xE, 0.7f, 0x1 },
    { 2, 0, 0xE, 0.7f, 0x4 },
    { 2, 0, 0x2, 0.8f, 0x8 },
    { 1, 0, 0x2, 0.8f, 0x10 },
};
static TBoss3VoloptCoreMovement core_movement = {
    150.0f, 0.55555552f, 0x400, { 0x1E0000, 0, 1, 0 },
};
static TBoss3VoloptCoreBodyPart core_body_parts[1] = {
    { { 0 }, 0.001f, { 0 }, 0x8003, { 0 } },
};

extern int player_battle_param_table[];

void TObjEneMe1GiGue::set_state(s32 action) {
    s16 current = mode;
    if (current != action) {
        m_380 = current;
        next_action = action;
    }
}

void TObjEneMe1GiGue::update_if_active(s32 action) {
    if (!(m_388 & 1)) {
        set_state(action);
    }
}

int TObjPlayer::get_battle_param(int index) {
    return player_battle_param_table[index];
}

void TBoss3VoloptCore::load_entry_params_volopt(s32 index) {
    model = (void *)core_resources->models[index].model;
    texture_id = core_resources->models[index].m_c;
}

s32 TBoss3VoloptCore::get_orbit_speed(s32 index) {
    return core_orbit_speeds->speeds[index];
}

s32 TBoss3VoloptCore::is_target_in_attack_range() {
    return 0;
}

TBoss3VoloptCore::TBoss3VoloptCore(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    apply_set_data(set_data);
    init_params();
}

TBoss3VoloptCore::TBoss3VoloptCore(TObject *parent, u16 id, s32 param) : TObjEnemyCustom(parent) {
    entity_id = id;
    *(s16 *)((u8 *)this + 0x2C) = param;
    m_80 = 0;
    *(s16 *)((u8 *)this + 0x28) = *(s16 *)((u8 *)parent + 0x28);
    *(s16 *)((u8 *)this + 0x2A) = *(s16 *)((u8 *)parent + 0x2A);
    init_params();
}

void TBoss3VoloptCore::init_params() {
    m_name = TBoss3VoloptCore_name;
    motion_list = core_resources->motions;
    action_table = core_motions;
    set_field_d8((s32)action_table);
    init_collision_body_parts(this, core_body_parts, 1);
    variant = 0;
    movementParameters = &core_movement;
    recalc_combat_stats(core_combat_stats_a, core_combat_stats_b, core_combat_stats_c, 1.0f, 1.0f);
    m_b8 = 0;
    set_animation(m_b8);
    set_field_b8(m_b8);
    hp = hpmax;
    m_32e = m_2ba;
    referenceHp = hp;
    set_param(0x2E);
    update_prev_position();
    ((TBoss3Volopt *)this)->reset_photon_effect();
    load_entry_params_volopt(0x18);
    m_388 |= 0x10000;
    orbit_angle = 0;
    m_a4->flags |= 0xC00;
    vfunc_58();
    add_flags_2e4(4);
    hit_cooldown = 0;
    obj_setFlags30(this, 0x8000);
    if (TBoss3Volopt::is_v2_mode() != 0) {
        core_turn_angle_limit = 0xA00;
    } else {
        core_turn_angle_limit = 0x200;
    }
    clear_lobby_object_state();
}

TBoss3VoloptCore::~TBoss3VoloptCore() {
    free_collision_body_parts(this);
    TBoss3Volopt::set_camera_focus(NULL);
}

void *TBoss3VoloptCore::create(void *set_data) {
    return new TBoss3VoloptCore(tl_04, set_data);
}

void TBoss3VoloptCore::load_resources() {
    core_resources = boss3_volopt_resources;
    core_combat_stats_a = TLobby::register_boss(0x21);
    core_combat_stats_b = TLobby::dispatch_shared_handler_b(0x21);
    core_combat_stats_c = TLobby::register_object(0x21);
    core_orbit_speeds = (TBoss3VoloptOrbitSpeeds *)TLobby::dispatch_shared_handler_a(0x21);
}

void TBoss3VoloptCore::release() {}

void TBoss3VoloptCore::run_task() {
    vol_opt_active_hit_zone = calc_hit_zone_index();
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_80040558();
        return;
    }
    VecCopy((Vec *)&m_44, (Vec *)position);
    if (hit_cooldown > 0) {
        hit_cooldown--;
    }
    if (has_flag_0x800() != 0) {
        vfunc_63();
    } else if (test_flag30_512() != 0) {
        if (hit_cooldown > 0) {
            obj_clearFlags30(0x200);
        } else {
            vfunc_62();
        }
    }
    if (obj_testFlags30(0x4000) != 0) {
        if (((TObjPlayer *)this)->add_status_effect_timer(4, -1) <= 0) {
            reset_status_effect_row(unk_284);
            obj_clearFlags30(0x4000);
        }
    } else {
        if (mode != (s32)next_action) {
            if ((s32)state != -1) {
                state = -1;
                dispatch_reaction_state();
            }
            mode = next_action;
            state = 0;
        }
        dispatch_reaction_state();
        position[1] = (position[1] > 7.0f) ? position[1] : 7.0f;
        update_prev_position();
        TBoss3Volopt::set_camera_focus((Vec *)&m_2fc);
        clear_all_status_effects();
    }
}

void TBoss3VoloptCore::dispatch_reaction_state() {
    switch (mode) {
    case 0:
        run_freeze_state();
        return;
    case 1:
        update_orbit_state();
        return;
    case 2:
        update_charge_state();
        return;
    case 4:
        update_grabbed_state();
        return;
    case 5:
        update_reaction_animation();
        return;
    case 7:
        update_state_spin();
        return;
    case 9:
        sub_8003F81C();
        return;
    case 10:
        update_topple_state();
        break;
    }
}

void TBoss3VoloptCore::sub_80040558() {}

void TBoss3VoloptCore::render() {
    if (!(actorFlags & 0x02000000) && update_object_view_visibility(400.0f, 40.0f) != 0) {
        TObjFish::set_global_param(texture_id);
        push_matrix();
        model_render_flags &= ~0x400;
        post_translate_matrix(position);
        rotate_matrix_x(0, m_5c);
        if (m_388 & 0x10000) {
            rotate_matrix_y(0, facing_angle);
            scale_matrix(0, 1.0f, 1.0f, 0.05f);
            rotate_matrix_y(0, rotation_y - facing_angle);
        } else {
            rotate_matrix_y(0, rotation_y);
        }
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else {
            draw();
        }
        pop_matrix();
    }
}

void TBoss3VoloptCore::update_charge_state() {
    s32 angles[3];
    f32 distance;
    TObjPlayer *player;
    target = (u8 *)get_player_by_client_id(targetId);
    switch (state) {
    case 0:
        m_388 &= ~0x10000;
        m_b8 = 0;
        m_5c = 0;
        if ((s32)m_380 == 4) {
            state = charge_step;
        } else {
            VecCopy(&home_pos, (Vec *)position);
            charge_step = 1;
            state = 1;
            charge_timer = 0x1E;
        }
        break;
    case 1:
        VecCopy((Vec *)unk_308, (Vec *)((TObjPlayer *)target)->position);
        subtract_vector((Vec *)unk_308, (Vec *)position);
        ((TObjPlayer *)this)->update_angle(0x800, unk_308);
        if (--charge_timer <= 0) {
            charge_timer = 0x96;
            charge_step = 2;
            state = 2;
            angles[1] = facing_angle;
            angles[0] = 0;
            angles[2] = 0x4000;
            new TUnk_80484888(&volopt_slot_positions[slot_index], 0x11B, 8, angles, 0.5f, 0.0f);
        }
        break;
    case 2:
        player = (TObjPlayer *)target;
        if (player == NULL) {
            charge_step = 4;
            state = 4;
            return;
        }
        VecCopy((Vec *)unk_308, (Vec *)&player->m_2fc);
        subtract_vector((Vec *)unk_308, (Vec *)position);
        vec_set_length((Vec *)unk_308, 5.0f);
        ((TObjPlayer *)this)->update_angle(0x800, unk_308);
        vec3_add_to((Vec *)position, (Vec *)unk_308);
        if (check_target_collision() != 0) {
            charge_step = 4;
            state = 4;
        }
        if (--charge_timer <= 0) {
            charge_step = 4;
            state = 4;
        }
        break;
    case 4:
        VecCopy((Vec *)unk_308, &home_pos);
        subtract_vector((Vec *)unk_308, (Vec *)position);
        distance = vec_set_length((Vec *)unk_308, 5.0f);
        ((TObjPlayer *)this)->update_angle(0x800, unk_308);
        vec3_add_to((Vec *)position, (Vec *)unk_308);
        check_target_collision();
        if (distance < 10.0f) {
            targetId = 0xFFFF;
            vfunc_59();
        }
        break;
    }
    advance_animation_playback(this);
    minimap_render_dot(position, -0x5DB4, 1, 0);
}

void TBoss3VoloptCore::update_grabbed_state() {
    switch (state) {
    case 0:
        if (obj_testFlags30(0x02000000) != 0) {
            m_388 |= 0x40000;
        }
        obj_clearFlags30(0x02200200);
        referenceHp = hp;
        m_b8 = 3;
        play_sound_effect(0x4003A81F, NULL, 0, 0);
        play_sound_effect(0x4003BC20, NULL, 0, 0);
        if (local_client_id == m_2d4) {
            TCameraCtrl__sub_8006A044(0x1E, 0.08f);
        }
        hit_cooldown = 0x14;
        state = 1;
    case 1:
        advance_animation_playback(this);
        if (m_b4 != 8) {
            m_388 &= ~1;
            if (m_388 & 0x40000) {
                set_grabbed_state(0xF);
            } else {
                ((TObjEneMe1GiGue *)this)->update_if_active(m_380);
            }
        }
        return;
    case -1:
        m_388 &= ~0x40000;
        break;
    }
}

void TBoss3VoloptCore::update_reaction_animation() {
    switch (state) {
    case 0:
        m_b8 = 4;
        state = 1;
    case 1:
        advance_animation_playback(this);
        break;
    case -1:
        return;
    }
}

void TBoss3VoloptCore::run_freeze_state() {
    switch (state) {
    case 0:
        boss3_volopt_core_active_flag = 1;
        actorFlags |= 0x02040000;
        state = 1;
        break;
    case 1:
        break;
    case -1:
        actorFlags &= ~0x02040000;
        break;
    }
}

s32 TBoss3VoloptCore::check_target_collision() {
    s32 found;
    s32 i;
    TBoss3VoloptCoreTarget *object;
    if (target == NULL) {
        return 0;
    }
    found = 0;
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)this)->check_object_collisions();
    if (m_a4->flags & 0x80000) {
        for (i = 0; i < 0x10; i++) {
            object = (TBoss3VoloptCoreTarget *)TObjPlayer::get_battle_param(i);
            if (object == NULL) {
                break;
            }
            if (obj_is_hit_receivable(object) != 0) {
                if (object->select_melee_contact_body(this, 1.0f) != 0) {
                    object->apply_knockback_from_attacker(this, 3.0f);
                    object->receive_physical_attack(this, 1.0f);
                }
                if ((u8 *)object == target) {
                    found = 1;
                }
            }
        }
    }
    return found;
}

void TBoss3VoloptCore::update_state_spin() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        m_388 |= 0x20000;
        orbit_angle = 0x4000;
        sweep_angle = -0x1555;
        targetId = 0xFFFF;
        m_388 |= 0x10000;
        m_b8 = 0;
        m_5c = 0;
        update_orbit_position();
        facing_angle = calc_spin_value();
        rotation_y = facing_angle;
        *(s16 *)&timer = 0x5A;
        state = 1;
    case 1:
        advance_animation_playback(this);
        if (--*(s16 *)&timer <= 0) {
            actorFlags &= ~0x40000;
            m_388 &= ~1;
            vfunc_58();
        }
        break;
    case -1:
        break;
    }
}

s32 TBoss3VoloptCore::calc_spin_value() {
    return (s32)(182.04445f * (f32)((((s32)(u16)orbit_angle / 10922) * 0x3C) + 0x78));
}

void TBoss3VoloptCore::update_orbit_position() {
    f32 radius;
    s32 offset = ((u16)orbit_angle % 10922) - 0x1555;
    if (m_388 & 0x20000) {
        orbit_radius = 134.0f / cos_table_lookup(offset);
        position[1] = 50.0f;
    } else {
        orbit_radius = 128.0f / cos_table_lookup(offset);
        position[1] = 15.0f;
    }
    push_matrix();
    radius = orbit_radius;
    position[0] = radius;
    position[2] = 0.0f;
    set_matrix_identity(0, radius);
    rotate_matrix_y(0, orbit_angle);
    rotate_vector_by_matrix(0, (Vec *)position, (Vec *)position);
    pop_matrix();
}

s32 TBoss3VoloptCore::calc_hit_zone_index() {
    s32 zone;
    s32 offset;
    s32 angle;
    TObjEnemyCustom *monitor;
    if (mode == 0) {
        return -1;
    }
    angle = orbit_angle;
    zone = -1;
    offset = (u16)angle % 0x2AAA - 0x1555;
    if (position[1] >= 25.0f) {
        if (__abs(offset) <= 0x8DC) {
            zone = 0;
        }
    } else if (offset <= 0xDB2) {
        if (offset >= 0x510) {
            zone = 1;
        } else if (offset >= -0x510) {
            zone = 2;
        } else if (offset >= -0xDB2) {
            zone = 3;
        }
    }
    if (zone >= 0) {
        zone += ((u16)(angle - 0x2AAA) / 0x2AAA) * 4;
        monitor = (TObjEnemyCustom *)find_entity_by_id(boss3_volopt_monitor_base_actor_id + zone);
        if (monitor == NULL || (monitor->actorFlags & 0x800)) {
            zone = -1;
        }
    }
    return zone;
}

void TBoss3VoloptCore::set_boss_target_pos(s32 slot, s32 moves, s32 delay_frames) {
    if (obj_testFlags30(0x800) == 0) {
        m_388 |= 0x20000;
        target_slot = slot;
        moves_left = moves;
        delay = delay_frames;
        boss3_volopt_core_active_flag = 0;
        alloc_boss_target_slot();
        m_388 &= ~1;
        vfunc_59();
    }
}

void TBoss3VoloptCore::update_orbit_state() {
    switch (state) {
    case 0:
        m_388 |= 0x10000;
        m_b8 = 0;
        m_5c = 0;
        state = 1;
        break;
    case 1:
        advance_animation_playback(this);
        orbit_angle -= get_orbit_speed(0);
        sweep_angle -= get_orbit_speed(0);
        update_orbit_position();
        facing_angle = calc_spin_value();
        rotation_y = facing_angle - 0x4000;
        if (moves_left > 1) {
            if (sweep_angle <= -0x238E) {
                moves_left--;
                if (--target_slot < 0) {
                    target_slot = 5;
                }
                if (alloc_boss_target_slot() == 1) {
                    state = 0;
                }
                break;
            }
        } else if (sweep_angle < -0x1555) {
            drop_angle = orbit_angle;
            ((TObjEneMe1GiGue *)this)->update_if_active(9);
        }
        play_persistent_sound(0x4003BC05, this, position, 0, 0);
        break;
    case -1:
        break;
    }
    if (vol_opt_active_hit_zone >= 0) {
        minimap_render_dot(position, -0x5DB4, 1, 0);
    }
}

void TBoss3VoloptCore::sub_8003F81C() {
    switch (state) {
    case 0:
        m_388 |= 0x10000;
        m_b8 = 0;
        *(s16 *)&timer = 5;
        effect = NULL;
        state = 1;
    case 1:
        rotation_y = approach_angle_limited(rotation_y, facing_angle - 0x8000, core_turn_angle_limit);
        if (angle_difference_abs(rotation_y, facing_angle - 0x8000) <= core_turn_angle_limit) {
            *(s16 *)&timer = (TBoss3Volopt::is_v2_mode() != 0) ? 5 : 0x1E;
            state = 2;
        }
        break;
    case 2:
        if (--*(s16 *)&timer <= 0) {
            Vec pos = *(Vec *)position;
            pos.y -= 20.0f;
            effect = create_particle_emitter(&pos, 0x31);
            play_sound_effect(0x4003AD1E, position, 0, 0);
            state = 3;
        }
        break;
    case 3:
        if (--*(s16 *)&timer < 0) {
            boss3_volopt_core_active_flag = 1;
            vfunc_58();
        }
        break;
    case -1:
        if (effect != NULL) {
            effect->queue_destruction();
            effect = NULL;
        }
        break;
    }
    advance_animation_playback(this);
    if (vol_opt_active_hit_zone >= 0) {
        minimap_render_dot(position, -0x5DB4, 1, 0);
    }
}

s32 TBoss3VoloptCore::alloc_boss_target_slot() {
    s32 i;
    s32 slot;
    for (i = 0; i < 6; i++) {
        slot = (target_slot + 6 - i) % 6;
        if (volopt_target_slot_used[slot * 4] == 0) {
            target_slot = slot;
            break;
        }
    }
    if (i == 6) {
        boss3_volopt_core_active_flag = 1;
        vfunc_58();
        return 0;
    }
    orbit_angle = (s32)(182.04445f * (f32)((target_slot + 2) * 60 - 10));
    sweep_angle = -0x71C;
    return 1;
}

void TBoss3VoloptCore::link_photon(u16 id, s32) {
    TBoss3VoloptCore *core = (TBoss3VoloptCore *)find_entity_by_id(volopt_core_id);
    if (core != NULL && core->hit_cooldown <= 0) {
        TObject *source = (TObject *)find_entity_by_id(id);
        if (source != NULL) {
            core->m_a4->flags |= 0x04000000;
            core->receive_physical_attack(source, 1.0f);
        }
    }
}

void TBoss3VoloptCore::update_topple_state() {
    switch (state) {
    case -1:
        break;
    case 0:
        m_388 |= 0x10000;
        m_b8 = 0;
        if (angle_difference_abs(rotation_y, facing_angle - 0x4000) <= core_turn_angle_limit) {
            state = 3;
        } else {
            state = 1;
        }
        break;
    case 1:
        if (--delay <= 0) {
            state = 2;
        }
        break;
    case 2:
        rotation_y = approach_angle_limited(rotation_y, facing_angle - 0x4000, core_turn_angle_limit);
        if (angle_difference_abs(rotation_y, facing_angle - 0x4000) <= core_turn_angle_limit) {
            state = 3;
        }
        break;
    case 3:
        play_persistent_sound(0x4003BC05, this, position, 0, 0);
        advance_animation_playback(this);
        orbit_angle -= get_orbit_speed(0);
        sweep_angle -= get_orbit_speed(0);
        update_orbit_position();
        facing_angle = calc_spin_value();
        if (sweep_angle <= -0x238E) {
            vfunc_58();
        }
        break;
    }
    advance_animation_playback(this);
    if (vol_opt_active_hit_zone >= 0) {
        minimap_render_dot(position, -0x5DB4, 1, 0);
    }
}

void TBoss3VoloptCore::set_grabbed_state(s32 delay) {
    TBoss3VoloptCore *core = (TBoss3VoloptCore *)find_entity_by_id(volopt_core_id);
    if (core != NULL && core->mode != 10) {
        ((TObjEneMe1GiGue *)core)->update_if_active(10);
        core->delay = delay;
    }
}
