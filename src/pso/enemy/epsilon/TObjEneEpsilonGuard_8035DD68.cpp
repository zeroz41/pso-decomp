#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

struct NJS_OBJECT;
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/epsilon/TObjEneEpsilonBody.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"

#include "pso/object/ambient/TObjFish.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"

#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"

u8 *epsilon_guard_boss_stat_handle;
u8 *epsilon_guard_shared_handler_b;
u8 *epsilon_guard_registered_object_handle;
TObjEneEpsilonGuardParams *TObjEneEpsilonGuard__movement_params;
extern "C" {
struct RecoveredGlobal_lbl_805439E0 { s32 value; u8 remaining[0xC]; };
RecoveredGlobal_lbl_805439E0 lbl_805439E0;
s32 epsilon_guard_camera_step;
Vec *epsilon_guard_camera_ctrl_ptr;
void render__19TObjEneEpsilonGuardFv(u8 *);
extern const TBoss3VoloptBreakupParams epsilon_guard_breakup_params = { 0x14, { 0.05f, 1.2f, 0.9f, 0.12f, 0.55f, 0.5f } };
const char *TObjEneEpsilonGuard__class_name = "TObjEneEpsilonGuard";
extern s32 lbl_805D6FA8;

extern CollisionBody TObjEneEpsilonGuard__model_desc[];

int TObjEneEpsilonGuard__sub_8035F95C(TObjEneEpsilonBody *body);
int TObjEneEpsilonGuard__sub_8035F968(void);

f32 TObjEneEpsilonGuard::receive_weapon_special_attack(void *, void *) {
    try_apply_damage(&body_center, 0);
    return 0.0f;
}
f32 TObjEneEpsilonGuard::receive_physical_attack(void *, f32) {
    try_apply_damage(&body_center, 0);
    return 0.0f;
}
f32 TObjEneEpsilonGuard__vt21(TObjEneEpsilonGuard *guard, void *attacker, DirectAttackPayload *msg, void *body, s32 tech, s32 flags) {
    if (msg->kind == 0x14) {
        return guard->TObjChara::receive_direct_attack(attacker, *msg, body, tech, flags);
    }
    guard->try_apply_damage(&guard->body_center, 0);
    return 0.0f;
}

int TObjEneEpsilonGuard__sub_8035DD68(TObjEneEpsilonGuard *guard) { return ((u32)guard->flags >> 7) & 0x1; }

s32 TObjEneEpsilonGuard__sub_8035DD74(TObjEneEpsilonGuard *guard) {
    if (guard->actorFlags & 0xA00) {
        return 0;
    }
    return ((u32)guard->flags >> 4) & 1;
}

s32 TObjEneEpsilonGuard::is_guard_active() {
    if (actorFlags & 0xA00) {
        return 0;
    }
    if (mode != 1) {
        return 0;
    }
    return ((u32)flags >> 9) & 1;
}

s32 TObjEneEpsilonGuard::is_state_flag_set() {
    if (actorFlags & 0xa00) {
        return 0;
    }
    if (flags & 0x10) {
        return 0;
    }
    if (flags & 0x20) {
        return 0;
    }
    return (flags & 4) ? 1 : 0;
}

s32 TObjEneEpsilonGuard::is_guard_ready() {
    if (actorFlags & 0xa00) {
        return 0;
    }
    if (flags & 0x10) {
        return 0;
    }
    if (flags & 0x20) {
        return 0;
    }
    return (flags & 4) ? 1 : 0;
}

void TObjEneEpsilonGuard::clear_and_flag_state() {
    effect_step = 0;
    flags |= 0x20;
    clear_all_status_effects();
}

void TObjEneEpsilonGuard::set_flag_8_and_notify() {
    flags |= 8;
    clear_all_status_effects();
}

void TObjEneEpsilonGuard__sub_8035DEC0(TObjEneEpsilonGuard *guard) {
    guard->flags |= 2;
    guard->clear_all_status_effects();
}

void TObjEneEpsilonGuard::set_target(saddr pos, s32 angle, s32 arg3) {
    VecCopy(&position, (const Vec *)pos);
    rotation_y = angle;
    if (arg3 != 0) {
        flags |= 0x100;
    } else {
        flags &= ~0x100;
    }
    flags |= 1;
    clear_all_status_effects();
}

void TObjEneEpsilonGuard::render_guard_effect() {
    f32 scale;

    if ((flags & 0x20) && ((s32)main_task.get_task_flags() & 0x200)) {
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, 24.0f, 0.0f);
        scale = effect_scale;
        scale_matrix(0, scale, scale, scale);
        set_motion_packed_rotation();
        draw_model_motion(effect_model, effect_motion, effect_frame);
        clear_motion_packed_rotation();
        pop_matrix();
    }
}

void TObjEneEpsilonGuard::render_with_fade(s32 detail) {
    s32 i;
    RenderFadeState *fade;
    i = 0;
    if (is_split_screen() != 0) {
        i = TCameraCtrl::get_camera_mode();
    }
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    fade = &this->fades[i];
    fade->update();
    if (fade->updateFromCamera(&this->body_center.x) != 0) {
        fade->set_flags_and_apply_damage_color();
        if (!((s32)main_task.get_task_flags() & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if (this->mode == 3) {
        this->fade.set_flags_and_apply_damage_color();
        if (!((s32)main_task.get_task_flags() & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if ((s32)main_task.get_task_flags() & 0x200) {
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        return;
    }
    this->update_secondary_light();
    TObjFish::set_global_param(this->texlist);
    push_matrix();
    post_translate_matrix(&this->position.x);
    translate_matrix(0, 0.0f, 24.0f, 0.0f);
    rotate_matrix_y(0, this->rotation_y);
    TObjEneDD::clear_global_flag_400();
    epsilon_guard_camera_step = 0;
    epsilon_guard_camera_ctrl_ptr = &this->effect_anchor;
    this->effect_anchor.x = 0.0f;
    this->effect_anchor.y = 0.0f;
    this->effect_anchor.z = 0.0f;
    set_chunk_model_node_callback(TObjEneEpsilonGuard::advance_camera_ctrl_step);
    TObjPlayer::toggle_particle_effect();
    if (detail == 1) {
        this->TObjMotion::draw();
    } else {
        this->draw_motion_model();
    }
    TParticleCtrl::end_effect_render();
    set_chunk_model_node_callback(NULL);
    pop_matrix();
    this->update_primary_light();
    if (fade->updateFromCamera(&this->body_center.x) != 0) {
        fade->clear_flag_and_notify();
    } else if (this->mode == 3) {
        this->fade.clear_flag_and_notify();
    }
    model_render_flags = saved_model_render_flags;
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
}

void TObjEneEpsilonGuard::render() {
    s32 detail;
    if ((TObjPlayer::check_demo_mode() == 0) && !(actorFlags & 0x02000000)) {
        detail = 0;
        if (!(flags & 0x10)) {
            if (TObjEneDD::is_main_phase_15() != 0) {
                detail = classify_actor_view_detail(6e+02f, 6e+02f, 15.0f);
            } else if (update_object_view_visibility(6e+02f, 15.0f) != 0) {
                detail = 1;
            } else {
                detail = 0;
            }
        }
        if (detail != 0) {
            draw_ground_shadow(0, 0);
            defer_render();
            render_with_fade(detail);
            render_guard_effect();
            return;
        }
        effect_anchor.x = 0.0f;
        effect_anchor.y = 0.0f;
        effect_anchor.z = 0.0f;
        sub_803626A8((saddr)&effect_anchor, 0);
    }
}

void TObjEneEpsilonGuard::advance_camera_ctrl_step(NJS_OBJECT *) {
    if ((s32) epsilon_guard_camera_step == 0) {
        forward_transform_to_view((const Vec *)&lbl_805439E0.value, (Vec *)epsilon_guard_camera_ctrl_ptr);
    }
    epsilon_guard_camera_step += 1;
}

void TObjEneEpsilonGuard::handle_message(s32 arg1) {
    switch (arg1) {
    case 4:
        set_intangible();
        flags |= 0x14;
        send_entity_set_flags();
        return;
    case 3:
        queue_destruction();
    case 5:
    case 0:
        return;
    }
}


void TObjEneEpsilonGuard::handle_break_state(s32 msg) {
    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(4);
        flags |= 0x40;
        flags &= ~0x14;
        clear_intangible();
        TObjPlayer::spawn_effect_f8((saddr)&effect_anchor, 0x14);
        state_step = 0;
        break_timer = 0;
        break;
    case 3:
        if (state_step == 1) {
            transition_enemy_state(5);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        break_timer++;
        if (break_timer >= 0x14) {
            clear_intangible();
            TBoss3Volopt::create_breakup_mdl((s32)lbl_805D6FA8, (saddr)&epsilon_guard_breakup_params, texlist, (saddr)&position, rotation_y);
            play_sound_effect(0x4003AD4C, &body_center, 0, 0);
            ((TObjPlayer *)&body_center)->trigger_dell_biter_events();
            state_step = 1;
        }
        check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard__sub_8035E578(TObjEneEpsilonGuard *guard, s32 msg) {
    switch (msg) {
    case 4:
        guard->requested_action = 0;
        guard->set_field_378(3);
        guard->fade.set_rate_from_divisor(0x14);
        guard->fade.reset_color();
        guard->flags &= ~0x14;
        guard->clear_intangible();
        break;
    case 3:
        if (guard->fade.decay_value_toward_floor() != 0) {
            guard->transition_enemy_state(0);
            guard->flags |= 0x10;
            guard->set_intangible();
            break;
        }
    case 5:
        break;
    case 0:
        guard->advance_animation();
        guard->check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard::state_orbit(s32 msg) {
    TObjEneEpsilonBody *body;

    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(2);
        flags |= 4;
        flags &= ~0x18;
        clear_intangible();
        state_step = 0;
        orbit_angle = rotation_y;
        orbit_angle_step = 0;
        return;
    case 3:
        if (flags & 8) {
            transition_enemy_state(3);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            if (flags & 0x100) {
                orbit_angle_step = (s32) ((-65536.0f * TObjEneEpsilonGuard__movement_params->m_8) / (6.283184f * TObjEneEpsilonGuard__movement_params->orbit_radius));
            } else {
                orbit_angle_step = (s32) ((65536.0f * TObjEneEpsilonGuard__movement_params->m_8) / (6.283184f * TObjEneEpsilonGuard__movement_params->orbit_radius));
            }
            state_step = 1;
            break;
        case 1:
            body = (TObjEneEpsilonBody *)find_entity_by_id(body_id);
            if (body != NULL) {
                if (TObjEneEpsilonGuard__sub_8035F968() == 1) {
                    flags &= ~4;
                    state_step = 2;
                } else if (TObjEneEpsilonGuard__sub_8035F95C(body) != 1) {
                    goto orbit;
                }
            } else {
orbit:
                orbit_angle += orbit_angle_step;
                set_orbit_destination(orbit_angle);
                update_velocity();
                this->move_with_wall_slide_commit(destination_direction.x, destination_direction.z, TObjEneEpsilonGuard__movement_params->m_8);
            }
            break;
        case 2:
            if ((find_entity_by_id(body_id) != 0U) && (TObjEneEpsilonGuard__sub_8035F968() == 0)) {
                flags |= 4;
                state_step = 1;
            }
            break;
        }
        rotation_y = calc_angle_to_target();
        check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard__sub_8035E8C0(TObjEneEpsilonGuard *guard, s32 msg) {
    switch (msg) {
    case 4:
        guard->requested_action = 0;
        guard->set_field_378(1);
        guard->flags &= ~0x216;
        guard->clear_intangible();
        return;
    case 3:
        if (guard->flags & 2) {
            guard->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        guard->advance_animation();
        guard->enemy_copy_target_destination();
        guard->update_velocity();
        if (!(guard->flags & 0x200)) {
            TObjEneEpsilonGuardParams *d = TObjEneEpsilonGuard__movement_params;
            if (guard->destination_distance > d->orbit_radius + d->m_4) {
                guard->flags |= 0x200;
            } else {
                ((TObjEneDD *)guard)->move_with_wall_slide_commit(-guard->destination_direction.x, -guard->destination_direction.z, d->m_4);
            }
        }
        guard->rotation_y = guard->calc_angle_to_target();
        guard->check_collisions();
        break;
    }
}

void TObjEneEpsilonGuard::handle_event(s32 msg) {
    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(0);
        set_intangible();
        flags |= 0x10;
        flags &= ~5;
        return;
    case 3:
        if (flags & 1) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        flags |= 0x10;
        break;
    }
}
void TObjEneEpsilonGuard::sub_8035EA90() {
    f32 lim;
    s32 i;
    TObjChara *p;
    uaddr body;
    if (flags & 0x20) {
        switch (effect_step) {
        case 0:
            effect_scale = 0.0f;
            effect_timer = 0;
            effect_frame = 0.0f;
            effect_step = 1;
            emitter = create_particle_emitter(&body_center, 0x221);
            break;
        case 1:
            effect_scale += 0.1f;
            if (emitter != NULL) {
                emitter->set_position(&body_center);
            }
            if (effect_scale >= 1.0f) {
                effect_scale = 1.0f;
                effect_step = 2;
            }
            break;
        case 2:
            effect_timer++;
            if (emitter != NULL) {
                emitter->set_position(&body_center);
            }
            if (effect_timer >= TObjEneEpsilonGuard__movement_params->m_18) {
                effect_scale = 1.0f;
                effect_step = 3;
            }
            break;
        case 3:
            effect_scale -= 0.1f;
            if (emitter != NULL) {
                emitter->set_position(&body_center);
            }
            if (effect_scale <= 0.0f) {
                effect_scale = 0.0f;
                flags &= ~0x20;
                if (emitter != NULL) {
                    emitter->queue_destruction();
                    emitter = NULL;
                }
            }
            break;
        default:
            flags &= ~0x20;
            if (emitter != NULL) {
                emitter->queue_destruction();
                emitter = NULL;
            }
            break;
        }
        lim = (f32)effect_motion->nbFrame - 1.0f;
        effect_frame += 0.5f;
        if (lim < effect_frame) {
            effect_frame -= lim;
        }
        TObjEneEpsilonGuard__model_desc[1].radius = 36.0f * effect_scale;
        VecCopy(&collider->position, &position);
        TObjPlayer::init_all_slots();
        collider->check_object_collisions();
        if (collider->bodies->flags & 0x80000) {
            for (i = 0; i < 16; i++) {
                p = (TObjChara *)TObjPlayer::get_battle_param(i);
                if (p == NULL) {
                    break;
                }
                if (obj_is_hit_receivable((u8 *)p) != 0) {
                    body = (uaddr)find_entity_by_id(body_id);
                    if (body != 0 && p->has_flag_0x800() == 0) {
                        DirectAttackPayload attack;
                        f32 damage;
                        attack.kind = ((TObjEneEpsilonBody *)body)->get_table_value_by_index();
                        attack.power = TObjEneEpsilonGuard__movement_params->m_c;
                        damage = p->receive_direct_attack(this, attack, 0, -1, -1);
                        p->apply_knockback_from_attacker((u8 *)this, damage);
                    }
                }
            }
        }
    } else if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

void update_body_colliders__19TObjEneEpsilonGuardFv(void *);
void check_collisions__19TObjEneEpsilonGuardFv(void *);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
int TObjEneEpsilonGuard__sub_8035F950(TObjEneEpsilonBody *body);

void TObjEneEpsilonGuard::update_guard_state() {
    s16 state;
    TObjCollidable *body;

    if (!(flags & 0x40)) {
        body = find_entity_by_id(body_id);
        if ((body == NULL) || (TObjEneEpsilonGuard__sub_8035F950((TObjEneEpsilonBody *)body) == 1)) {
            if (flags & 0x10) {
                transition_enemy_state(5);
            } else {
                transition_enemy_state(4);
            }
        } else {
            current_target = (TObjChara *)body;
            target_id = get_entity_id(current_target);
            enemy_copy_target_destination();
            sub_8035EA90();
        }
        if (flags & 0x20) {
            play_persistent_sound(0x4003A846, (saddr)this, (uaddr)&position, 0, 0);
            return;
        }
        state = mode;
        if ((state != 4) && (state != 5)) {
            play_persistent_sound(0x4003AD43, (saddr)this, (uaddr)&position, 0, 0);
        }
    }
}

void TObjEneEpsilonGuard::check_collisions() {
    TObjEneDD::check_collisions();
    if (bodies->flags & 0x400000) {
        flags |= 0x80;
    } else {
        flags &= ~0x80;
    }
    update_center_position();
}

void TObjEneEpsilonGuard::update_center_position() {
    body_center.x = position.x;
    body_center.y = 24.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}
void TObjEneEpsilonGuard::update_body_colliders() { set_part_local_pos(&body_center, 0); }

void TObjEneEpsilonGuard__vt85(TObjEneEpsilonGuard *arg0, s32 arg1, s32 arg2);
void run_task__19TObjEneEpsilonGuardFv(u8 *arg0);
extern BmlResource *lbl_805D6FA0;
s32 __ct__14TObjEneEpsilonFP7TObject();
void *TObjEneEpsilonGuard__ct(TObjEneEpsilonGuard *guard, TObject *parent, TObjEneEpsilonBody *body, s32 entity_id, s32 set_index, const Vec *pos, s32 angle);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
u8 *__dt__14TObjEneEpsilonFv(u8 *arg0, s16 arg1);
TObjEneEpsilonGuard *__dt__19TObjEneEpsilonGuardFv(TObjEneEpsilonGuard *guard, s16 del);
void refresh_target__19TObjEneEpsilonGuardFv(void);
void run_miss_reaction__19TObjEneEpsilonGuardFv(void);
void run_hit_reaction__19TObjEneEpsilonGuardFv(void);
void run_death_reaction__19TObjEneEpsilonGuardFv(void);

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void snap_to_ground_at__9TObjEneDDFPUc();
extern "C" void apply_enemy_state__9TObjEneDDFPl();
extern "C" void update_immobilizing_statuses__9TObjEneDDFv();
extern "C" void update_action_state__9TObjEneDDFv();
extern "C" void has_action_state_changed__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void set_invulnerable__9TObjEneDDFv();
extern "C" void clear_invulnerable__9TObjEneDDFv();
extern "C" void enable_body_collision__9TObjEneDDFv();
extern "C" void disable_body_collision__9TObjEneDDFv();
extern "C" void set_intangible__9TObjEneDDFv();
extern "C" void clear_intangible__9TObjEneDDFv();
extern "C" void set_colliders_contact_high__9TObjEneDDFv();
extern "C" void set_colliders_contact_low__9TObjEneDDFv();
extern "C" void is_confused__9TObjEneDDFv();
extern "C" void render_minimap_dot__9TObjEneDDFv();
extern "C" void move_xz_on_ground__9TObjEneDDFPUc();
extern "C" void update_ground_contact__9TObjEneDDFv();
extern "C" void receive_physical_attack__19TObjEneEpsilonGuardFPvf();
extern "C" void receive_weapon_special_attack__19TObjEneEpsilonGuardFPvPv();
extern "C" int acquire_target__12TObjEneDD_STFf(void *p);
extern "C" void is_target_in_attack_range__14TObjEneEpsilonFv();
extern "C" void update_movement_status__14TObjEneEpsilonFv();
extern "C" void update_status_effects__12TObjEneDD_STFv();
extern "C" void has_no_target__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void deliver_attack_hits__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void run_attack_action__9TObjCharaFv();
extern "C" void run_move_action__9TObjCharaFv();
extern "C" void run_idle_action__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void update_actor_ground_y_at__9TObjCharaFP3Vec();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void gain_photon_blast_chain_charge__9TObjCharaFv();
extern "C" void spend_photon_blast_charge__9TObjCharaFf();
extern "C" void gain_photon_blast_charge__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
TObjEneEpsilonMovement epsilon_guard_params = {
    150.0f, 0.5555555f, 0x400, { 0x1E0000, 0, 1, 0 },
};
TObjMotionAction lbl_804F2024[1] = {
    { 1, 0, 2, 1.0f, 0 },
};
CollisionBody TObjEneEpsilonGuard__model_desc[2] = {
    {{0.0f, 12.0f, 0.0f}, 2.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.0f, 0.0f}, 36.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
void *__vt__19TObjEneEpsilonGuard[105] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__19TObjEneEpsilonGuardFv, (void *)&run_task__19TObjEneEpsilonGuardFv,
    (void *)&render__19TObjEneEpsilonGuardFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&update_actor_ground_y_at__9TObjCharaFP3Vec, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__19TObjEneEpsilonGuardFPvf, (void *)&TObjEneEpsilonGuard__vt21,
    (void *)&receive_weapon_special_attack__19TObjEneEpsilonGuardFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&refresh_target__19TObjEneEpsilonGuardFv, (void *)&has_no_target__9TObjCharaFv, (void *)&is_target_in_attack_range__14TObjEneEpsilonFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&update_slow_status__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__14TObjEneEpsilonFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&run_idle_action__9TObjCharaFv, (void *)&run_move_action__9TObjCharaFv,
    (void *)&run_attack_action__9TObjCharaFv, (void *)&run_miss_reaction__19TObjEneEpsilonGuardFv, (void *)&run_hit_reaction__19TObjEneEpsilonGuardFv, (void *)&run_death_reaction__19TObjEneEpsilonGuardFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&deliver_attack_hits__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&gain_photon_blast_charge__9TObjCharaFf,
    (void *)&spend_photon_blast_charge__9TObjCharaFf, (void *)&gain_photon_blast_chain_charge__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&apply_enemy_state__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&update_status_effects__12TObjEneDD_STFv,
    (void *)&update_immobilizing_statuses__9TObjEneDDFv, (void *)&update_action_state__9TObjEneDDFv, (void *)&has_action_state_changed__9TObjEneDDFv, (void *)&TObjEneEpsilonGuard__vt85,
    (void *)&update_body_colliders__19TObjEneEpsilonGuardFv, (void *)&check_collisions__19TObjEneEpsilonGuardFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&set_invulnerable__9TObjEneDDFv,
    (void *)&clear_invulnerable__9TObjEneDDFv, (void *)&enable_body_collision__9TObjEneDDFv, (void *)&disable_body_collision__9TObjEneDDFv, (void *)&set_intangible__9TObjEneDDFv,
    (void *)&clear_intangible__9TObjEneDDFv, (void *)&set_colliders_contact_high__9TObjEneDDFv, (void *)&set_colliders_contact_low__9TObjEneDDFv, (void *)&is_confused__9TObjEneDDFv,
    (void *)&render_minimap_dot__9TObjEneDDFv, (void *)&move_xz_on_ground__9TObjEneDDFPUc, (void *)&update_ground_contact__9TObjEneDDFv, (void *)&snap_to_ground_at__9TObjEneDDFPUc,
    (void *)&acquire_target__12TObjEneDD_STFf,
};

s32 TObjEneEpsilonGuard::calc_angle_to_target() {
    f32 x;

    enemy_copy_target_destination();
    x = position.x;
    return (s32) (10430.38043493439 * atan2_float(x - destination.x, position.z - destination.z));
}

#pragma push
#pragma fp_contract on
void TObjEneEpsilonGuard::set_orbit_destination(s32 angle) {
    enemy_copy_target_destination();
    destination.x = (TObjEneEpsilonGuard__movement_params->orbit_radius * sin_table_lookup(angle)) + destination.x;
    destination.z = (TObjEneEpsilonGuard__movement_params->orbit_radius * cos_table_lookup(angle)) + destination.z;
}
#pragma pop

void TObjEneEpsilonGuard::run_miss_reaction() {  }
void TObjEneEpsilonGuard::run_hit_reaction() {  }
void TObjEneEpsilonGuard::run_death_reaction() {  }
void TObjEneEpsilonGuard::refresh_target() {  }


void TObjEneEpsilonGuard__vt85(TObjEneEpsilonGuard *guard, s32 state, s32 msg) {
    switch (state) {
    case 0:
        guard->handle_event(msg);
        return;
    case 1:
        TObjEneEpsilonGuard__sub_8035E8C0(guard, msg);
        return;
    case 2:
        guard->state_orbit(msg);
        return;
    case 3:
        TObjEneEpsilonGuard__sub_8035E578(guard, msg);
        return;
    case 4:
        guard->handle_break_state(msg);
        return;
    case 5:
        guard->handle_message(msg);
        return;
    }
}

void TObjEneEpsilonGuard::run_task() {
    TObjCollidable *body;
    if (update_status_effects() != 4) {
        update_guard_state();
        update_action_state();
        if (!(flags & 0x10)) {
            update_body_colliders();
            update_center_position();
            submit_default_cursor_candidate();
            render_minimap_dot();
            return;
        }
        body = find_entity_by_id(body_id);
        if (body != NULL) {
            VecCopy(&position, &body->position);
            update_center_position();
        }
    } else if (mode == 0) {
        transition_enemy_state(0);
    }
}

TObjEneEpsilonGuard *TObjEneEpsilonGuard::create(s32 entity_id, s32 set_index, const Vec *pos, s32 angle) {
    TObjEneEpsilonGuard *o;
    o = (TObjEneEpsilonGuard *)TObject::operator new(sizeof(TObjEneEpsilonGuard));
    if (o != NULL) {
        o = (TObjEneEpsilonGuard *)TObjEneEpsilonGuard__ct(o, tl_04, (TObjEneEpsilonBody *)this, entity_id, set_index, pos, angle);
    }
    return o;
}

TObjEneEpsilonGuard *__dt__19TObjEneEpsilonGuardFv(TObjEneEpsilonGuard *guard, s16 del) {
    if (guard != NULL) {
        *(void ***)((u8 *)guard + 0x18) = __vt__19TObjEneEpsilonGuard;
        if (guard->emitter != NULL) {
            guard->emitter->queue_destruction();
            guard->emitter = NULL;
        }
        if (guard->collider != NULL) {
            free_collision_body_parts(guard->collider);
            delete guard->collider;
            guard->collider = NULL;
        }
        free_collision_body_parts(guard);
        __dt__13TUnk_80494938Fv(&guard->fade, -1);
        __dt__14TObjEneEpsilonFv((u8 *)guard, 0);
        if (del > 0) {
            TObject::operator delete(guard);
        }
    }
    return guard;
}

void TObjEneEpsilonGuard::init_model_and_state() {
    init_position_vectors();
    model = (void *)get_bml_model((BmlResource *)lbl_805D6FA0, 2);
    texlist = (saddr)get_bml_texlist((BmlResource *)lbl_805D6FA0, 0);
    init_model(TObjEneEpsilonGuard__model_desc, 1);
    set_field_d8((saddr)lbl_804F2024);
    set_field_dc((saddr)lbl_805D6FA0->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp(epsilon_guard_boss_stat_handle, epsilon_guard_shared_handler_b, epsilon_guard_registered_object_handle);
    set_indexed_flags(0, 0x80020);
    set_state_flag_4();
    movementParameters = &epsilon_guard_params;
    initialize_enemy_state(0x57);
    VecCopy(&effect_anchor, &position);
    flags = 0;
    flags |= 0x10;
    set_intangible();
    effect_model = (void *)get_bml_model((BmlResource *)lbl_805D6FA0, 3);
    effect_motion = (NJS_MOTION *)get_bml_motion(lbl_805D6FA0, 3);
    effect_frame = 0.0f;
    effect_timer = 0;
    state_step = 0;
    break_timer = 0;
    orbit_angle = 0;
    orbit_angle_step = 0;
    mode = 0;
    dispatch_action(mode, 4);
    collider = new TObjCollidable(NULL);
    init_collision_body_parts(collider, &TObjEneEpsilonGuard__model_desc[1], 1);
    emitter = NULL;
    sub_800F5874(0x3F);
}

void *TObjEneEpsilonGuard__ct(TObjEneEpsilonGuard *guard, TObject *parent, TObjEneEpsilonBody *body, s32 entity_id, s32 set_index, const Vec *pos, s32 angle) {
    s32 i;
    __ct__14TObjEneEpsilonFP7TObject();
    *(void ***)((u8 *)guard + 0x18) = __vt__19TObjEneEpsilonGuard;
    __ct__13TUnk_80494938Fv(&guard->fade);
    guard->m_name = TObjEneEpsilonGuard__class_name;
    guard->body_id = get_entity_id(body);
    guard->init_common_from((u8 *)body);
    guard->entity_id = entity_id;
    guard->set_index = set_index;
    guard->room = body->room;
    guard->set_group = body->set_group;
    VecCopy(&guard->position, pos);
    VecCopy(&guard->home_position, &body->home_position);
    guard->rotation_z = 0;
    guard->rotation_x = 0;
    guard->rotation_y = angle;
    guard->init_model_and_state();
    guard->set_intangible();
    guard->flags |= 0x10;
    for (i = 0; i < 4; i++) {
        guard->fades[i].activate_and_dispatch();
    }
    return guard;
}

}
