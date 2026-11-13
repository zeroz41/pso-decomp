#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/epsilon/TObjEneEpsilonBody.h"
#include "pso/render/render_util.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/map/CsnQuery.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/EnemyTargetCandidate.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/TUnk_80484840.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/model_render_state.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"

#pragma inline_depth(1)
// Joint index per guard slot and the joint-local point the guard angle is measured from (sub_803606A0).
extern EpsilonGuardSlotValues epsilon_guard_attack_offset_table;
extern Vec lbl_80479D10;
// 20 rows of per-guard attack flags (update_attack_pattern).
extern EpsilonGuardAttackPatterns epsilon_guard_attack_pattern_table;
// Guard slot visiting order {2, 0, 1, 3} (TObjEneEpsilonGuard__sub_8035FD50).
extern EpsilonGuardSlotValues lbl_80479E5C;
// Per-colour value {1, 2, 3, 5} (get_table_value_by_index).
extern EpsilonGuardSlotValues epsilon_guard_table_value_set;
// Per-colour value {9, 7, 10, 11} (sub_8035F8A8).
extern EpsilonGuardSlotValues16 lbl_80479E7C;


extern "C" {

f32 atan2_float(f32 y, f32 x);
s32 matrix_mult_vec(int, void *, void *);
extern BmlResource *lbl_805D6FA0;
s32 draw_chunk_object();
s32 get_mode__11TCameraCtrlFPv(void *);
void TObjEneEpsilonGuard__sub_80360BF8(TObjEneEpsilonBody *body, s32 arg1);
extern EpsilonBodySharedParams *lbl_805D6F8C;
void action__19TObjEneEpsilonGuardFPvi(TObjEneEpsilonBody *body, s32 arg1);
void draw_line_list(VoloptLineList *, s32, u32);
extern Vec lbl_805439FC[2];
void TObjEneEpsilonGuard__sub_80361C70(TObjEneEpsilonBody *body, s32 arg1);
void TObjEneEpsilonGuard__sub_8035F844(TObjEneEpsilonBody *body, s32 arg1);
void TObjEneEpsilonGuard__sub_8035DEC0(TObjEneEpsilonGuard *guard);
void TObjEneEpsilonGuard__sub_8035FA50(TObjEneEpsilonBody *body);
s32 TObjEneEpsilonGuard__sub_8035FBBC(TObjEneEpsilonBody *body);
s32 TObjEneEpsilonGuard__sub_8035FC20(TObjEneEpsilonBody *body);
s32 TObjEneEpsilonGuard__sub_8035FCEC(TObjEneEpsilonBody *body);
s32 TObjEneEpsilonGuard__sub_8035DD74(TObjEneEpsilonGuard *guard);
void handle_guard_action_state__19TObjEneEpsilonGuardFPvi(TObjEneEpsilonBody *body, s32 arg1);
void TObjEneEpsilonGuard__sub_803610D0(TObjEneEpsilonBody *body, s32 arg1);
extern u8 epsilon_guard_destroy_breakup_params[];
extern s32 lbl_805D6FA4;
s32 TObjEneMe3SinowZoa__sub_800D72A4(void *);
extern s32 epsilon_guard_camera_sample_phase;
extern s32 *epsilon_guard_angle_sample_write_ptr;
extern Vec *epsilon_guard_camera_sample_read_ptr;
extern Vec *epsilon_guard_camera_sample_end_ptr;
void draw_with_fade__19TObjEneEpsilonGuardFPvi(TObjEneEpsilonBody *body, s32 arg1);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
extern NJS_ARGB lbl_80479CAC[];
s32 check_path_obstructed(void *, void *);
}

s16 obj_getS16_118(u8 *p);
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
extern "C" {

void create_fire_explosion_effect(void *, f32, Vec *, s32, s32);
u32 TObjEneEpsilonGuard__sub_8035FD50(TObjEneEpsilonBody *body, s32 slot);
extern s32 tl_07;
void TObjEneEpsilonGuard__sub_803616E4(TObjEneEpsilonBody *body, s32 arg1);
extern u8 lbl_805439F0[];
s32 TObjEneEpsilonGuard__sub_8035DD68(TObjEneEpsilonGuard *guard);
void TObjEneEpsilonGuard__sub_8035FB44(TObjEneEpsilonBody *body);
s32 TObjEneEpsilonGuard__sub_8035FAA8(TObjEneEpsilonBody *body);

extern s32 lbl_805D5870;


}


extern TObject *tl_04;


extern u8 *lbl_805D6F80;
extern u8 *lbl_805D6F84;
extern u8 *lbl_805D6F88;

// The body's action table, movement parameters and collision bodies.
TObjMotionAction lbl_804F2230[2] = {
    {1, 0, 0, 0.3f, 0},
    {1, 1, 1, 0.6f, 0},
};
TObjEneEpsilonMovement lbl_804F2250 = {
    150.0f, 0.5555555f, 0x400, { 0x1E0000, 0, 1, 0 },
};
CollisionBody lbl_804F226C[2] = {
    {{0.0f, 12.0f, 0.0f}, 12.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.0f, 0.0f}, 20.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
VoloptLineColor lbl_804F22C4[2] = {{0x80, 0xFF, 0x40, 0x40}, {0x80, 0xFF, 0x40, 0x40}};
VoloptLineList TObjEneEpsilonGuard__debug_line_list = {lbl_805439FC, lbl_804F22C4, 0, 4};

extern const char *lbl_805D4460;

extern u8 *epsilon_guard_part_color_table[];

// Writes the body's colour into the material colour bytes of the nine guard parts.
void TObjEneEpsilonBody::set_guard_part_colors(NJS_ARGB *color) {
    s32 i;
    for (i = 0; i < 9; i++) {
        epsilon_guard_part_color_table[i][7] = color->r;
        epsilon_guard_part_color_table[i][4] = color->g;
        epsilon_guard_part_color_table[i][5] = color->b;
    }
}

TObjEneEpsilonBody::TObjEneEpsilonBody(TObject *parent, void *set_data) : TObjEneEpsilon(parent) {
    s32 i;
    m_name = lbl_805D4460;
    invoke_initialization_hook(set_data);
    init_params();
    set_param(0x54);
    init_position_vectors();
    init_model(lbl_804F226C, 2);
    flags = 0;
    flags |= 2;
    set_guard_state();
    texlist = TObjFish__sub_8001EDB0(lbl_805D6FA0, 0);
    set_field_d8((s32)lbl_804F2230);
    set_field_dc((s32)(lbl_805D6FA0)->motions);
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp(lbl_805D6F80, lbl_805D6F84, lbl_805D6F88);
    check_state_flag_4();
    movementParameters = &lbl_804F2250;
    m_37c = 10.0f;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    color_index = (s32)(4.0f * random_ratio()) % 4;
    copy_argb(&color, &lbl_80479CAC[color_index]);
    fire_phase_timer = fire_phase_frames;
    guard_phase_timer = guard_phase_frames;
    attack_pattern_timer = lbl_805D6F8C->m_20;
    action_step = 0;
    action_timer = 0;
    m_4ec = 0;
    target_player = 0;
    m_4f4 = 0;
    m_4f8 = 0.0f;
    fire_position.x = 0.0f;
    fire_position.y = 0.0f;
    fire_position.z = 0.0f;
    target_position.x = 0.0f;
    target_position.y = 0.0f;
    target_position.z = 0.0f;
    for (i = 0; i < 4; i++) {
        TObjEneEpsilonGuard *guard = ((TObjEneEpsilonGuard *)this)->create((void *)(u16)(entity_id + 1 + i), (void *)(set_index + 1 + i), &position, (void *)rotation_y);
        if (guard != NULL) {
            guard_ids[i] = get_entity_id(guard);
        }
        VecCopy(&guard_position[i], &position);
        guard_rotation_y[i] = rotation_y;
    }
    mode = 0;
    dispatch_action(mode, 4);
    for (s32 j = 0; j < 4; j++) {
        fades[j].activate_and_dispatch();
    }
    warp_emitter = NULL;
    emitter = NULL;
    sub_800F5874(0x3F);
}

TObjEneEpsilonBody::~TObjEneEpsilonBody() {
    s32 i;
    free_collision_body_parts(this);
    if (warp_emitter != NULL) {
        warp_emitter->queue_destruction();
        warp_emitter = NULL;
    }
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
    for (i = 0; i < 4; i++) {
        if (guard_ids[i] != 0) {
            TObjCollidable *guard = (TObjCollidable *)find_entity_by_id(guard_ids[i]);
            if (guard != NULL) {
                guard->queue_destruction();
            }
        }
    }
}

void *create_TObjEneEpsilonBody(void *set_data) {
    return new TObjEneEpsilonBody(tl_04, set_data);
}

void TObjEneEpsilonBody::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_105();
        return;
    }
    if (vfunc_83() != 4) {
        update_guard_flag();
        vfunc_85();
    } else if (mode == 1) {
        transition_enemy_state(0);
    }
    if (mode != 9) {
        play_persistent_sound(0x4003AD43, (s32)this, (u32)&position, 0, 0);
    }
    vfunc_88();
    update_position();
    submit_default_cursor_candidate();
    vfunc_100();
}
extern "C" {

void TObjEneEpsilonBody::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        sub_80361D4C(reason);
        return;
    case 1:
        TObjEneEpsilonGuard__sub_80361C70(this, reason);
        return;
    case 2:
        TObjEneEpsilonGuard__sub_803616E4(this, reason);
        return;
    case 3:
        handle_guard_action_state__19TObjEneEpsilonGuardFPvi(this, reason);
        return;
    case 4:
        action__19TObjEneEpsilonGuardFPvi(this, reason);
        return;
    case 5:
        TObjEneEpsilonGuard__sub_803610D0(this, reason);
        return;
    case 6:
        ((TObjEneEpsilonGuard *)this)->handle_warp_state(reason);
        return;
    case 7:
        TObjEneEpsilonGuard__sub_80360BF8(this, reason);
        return;
    case 8:
        update_fade(reason);
        return;
    case 9:
        action_destroy(reason);
    default:
        return;
    }
}
void TObjEneEpsilonBody::vfunc_28() {  }
void TObjEneEpsilonBody::vfunc_63() { if (this->mode != 9) { transition_enemy_state(9); } }
void TObjEneEpsilonBody::vfunc_62() {
    s32 temp_r4;

    if ((s16) this->mode != 8) {
        temp_r4 = this->flags;
        if (!(temp_r4 & 2) && !(temp_r4 & 0x40)) {
            transition_enemy_state(8);
        }
    }
}

void TObjEneEpsilonBody::vfunc_61() {  }

void TObjEneEpsilonBody::update_position() {
    m_2fc = position.x;
    m_300 = 24.0f + position.y;
    m_304 = position.z;
    VecCopy(&center, body_center());
}
void TObjEneEpsilonBody::vfunc_88() {  }

void TObjEneEpsilonBody::vfunc_89() {
    TObjEneDD::vfunc_89();
    update_position();
}
#pragma push
#pragma opt_common_subs off
void TObjEneEpsilonBody::init_params() {
    move_speed = 0.5f + parameters[0];
    if (move_speed < 0.0f) {
        move_speed = 0.0f;
    }
    turn_step = 512.0f + parameters[1];
    if (move_speed <= 0.0f) {
        move_speed = 0.0f;
    }
    fire_phase_frames = 20.0f + parameters[2];
    if (fire_phase_frames < 5) {
        fire_phase_frames = 5;
    }
    fire_phase_frames *= 30.0f;
    guard_phase_frames = 20.0f + parameters[3];
    if (guard_phase_frames < 5) {
        guard_phase_frames = 5;
    }
    guard_phase_frames *= 30.0f;
}
#pragma pop

void TObjEneEpsilonBody::update_guard_flag() {
    if (update_linked_position(400.0f) == 1) {
        this->flags = (s32) (this->flags & 0xFFFFFF7F);
        return;
    }
    this->flags = (s32) (this->flags | 0x80);
}

void TObjEneEpsilonBody::vfunc_105() {  }

void TObjEneEpsilonBody::sub_80361D4C(s32 arg1) {
    switch (arg1) {
    case 4:
        set_field_378(0);
        vfunc_95();
        flags |= 0x43;
        flags &= ~0x200;
        set_guard_state();
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy((Vec *)&m_2fc, &home_position);
        fire_phase_timer = fire_phase_frames;
        guard_phase_timer = guard_phase_frames;
        return;
    case 3:
        if (!(flags & 0x80)) {
            transition_enemy_state(1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneEpsilonGuard__sub_80361C70(TObjEneEpsilonBody *body, s32 arg1) {
    switch (arg1) {
    case 4:
        body->set_field_378(0);
        body->vfunc_96();
        body->flags |= 0x42;
        body->flags &= ~0x201;
        body->set_guard_state();
        body->fade.start_fade_in();
        break;
    case 3:
        if (body->fade.advance_toward_max() != 0) {
            body->transition_enemy_state(2);
            break;
        }
    case 5:
        break;
    case 0:
        body->advance_animation();
        body->vfunc_89();
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneEpsilonGuard__sub_803616E4(TObjEneEpsilonBody *body, s32 arg1) {
    Vec *d;
    Vec *tgt;
    d = &body->fire_position;
    tgt = &body->target_position;
    switch (arg1) {
    case 4:
        body->set_field_378(2);
        body->vfunc_96();
        body->flags |= 0x42;
        body->flags &= ~0x309;
        body->set_guard_state();
        body->action_step = 0;
        body->action_timer = 0;
        body->m_4ec = 0;
        body->target_player = 0xFFFF;
        body->m_4f4 = 0;
        break;
    case 3:
        if (body->flags & 0x80) {
            body->transition_enemy_state(7);
        } else if (body->action_step == 1) {
            body->fire_phase_timer = body->fire_phase_frames;
            body->transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        body->advance_animation();
        body->tick_timer_set_flag();
        if (!(body->flags & 0x80)) {
            body->enemy_copy_target_destination();
            body->update_velocity();
            body->m_4f8 = body->m_3a0 * sin_table_lookup(body->rotation_y) + body->m_3a8 * cos_table_lookup(body->rotation_y);
            if (body->m_4f8 < cos_table_lookup(0x1000)) {
                body->turn_toward_target_direction(body->turn_step);
                body->vfunc_102();
            } else {
                enemy_turn_and_move_on_ground((u8 *)body, body->turn_step, body->move_speed);
            }
            if (body->target_player != 0xFFFF) {
                TObjPlayer *player = TObjPlayer::get_player_data(body->target_player);
                if (TObjPlayer::is_valid_and_active((u32)player) != 0) {
                    if (check_path_obstructed(body, &player->m_2fc) == 1) {
                        body->action_timer = 0;
                        body->target_player = 0xFFFF;
                    } else {
                        VecCopy(tgt, &player->position);
                    }
                } else {
                    body->action_timer = 0;
                    body->target_player = 0xFFFF;
                }
            } else {
                body->action_timer = 0;
            }
        } else {
            body->action_timer = 0;
        }
        switch (body->action_timer) {
        case 0:
            body->flags &= ~0x100;
            if (body->flags & 8) {
                body->action_step = 1;
            } else {
                body->m_4f4++;
                body->target_player = TObjEneEpsilonGuard__sub_8035FD50(body, body->m_4f4);
                if (body->target_player != 0xFFFF) {
                    if (TObjPlayer::is_valid_and_active((u32)TObjPlayer::get_player_data(body->target_player)) != 0) {
                        VecCopy(d, &body->position);
                        d->y += 10.0f;
                        if (project_actor_to_ground(body, d, 0) != 0) {
                            body->action_timer = 1;
                            body->m_4ec = lbl_805D6F8C->m_18;
                        }
                    }
                }
            }
            break;
        case 1: {
            Vec b;
            Vec a;
            f32 s;
            body->flags |= 0x100;
            VecCopy(&a, tgt);
            VecCopy(&b, d);
            subtract_vector(&a, d);
            normalize_vector_xz(&a);
            s = lbl_805D6F8C->m_4;
            b.x += a.x * s;
            b.y += 10.0f;
            b.z += a.z * s;
            if (project_actor_to_ground(body, &b, 0) != 0 && csnVector(d, &b, 0x88E0) == 0) {
                VecCopy(d, &b);
            }
            body->m_4ec--;
            if (body->m_4ec <= 0) {
                body->action_timer = 2;
                body->m_4ec = lbl_805D6F8C->m_1c;
            }
            play_persistent_sound(0x4003BC47, (s32)body, (u32)&body->position, 0, 0);
            break;
        }
        case 2:
            body->flags |= 0x100;
            body->m_4ec--;
            if (body->m_4ec <= 0) {
                TObjPlayer *player;
                s32 i;
                void *e = TObject::operator new(0x64);
                if (e != 0) {
                    create_fire_explosion_effect(e, 40.0f, d, 0, tl_07);
                }
                play_sound_effect(0x4003A348, &body->position, 0, 0);
                for (i = 0; i < 4; i++) {
                    player = get_player_by_client_id(i);
                    if (player != 0 && horizontal_distance_squared(&player->position, d) <= 1600.0f) {
                        DirectAttackPayload t;
                        t.kind = 1;
                        t.power = lbl_805D6F8C->m_8;
                        if (player->receive_direct_attack(body, t, 0, -1, -1) > 0.0f) {
                            obj_setFlags30(player, 0x600);
                        }
                        play_sound_effect(0x4002A828, &player->position, 0, 0);
                    }
                }
                body->m_4ec = 30;
                body->action_timer = 3;
            }
            break;
        case 3:
            body->flags &= ~0x100;
            body->m_4ec--;
            if (body->m_4ec <= 0) {
                body->action_timer = 0;
                body->target_player = 0xFFFF;
            }
            break;
        default:
            body->flags &= ~0x100;
            body->action_timer = 0;
            body->target_player = 0xFFFF;
            break;
        }
        body->vfunc_89();
        break;
    }
}
#pragma pop

void handle_guard_action_state__19TObjEneEpsilonGuardFPvi(TObjEneEpsilonBody *body, s32 arg1) {
    switch (arg1) {
    case 4:
        body->set_field_378(3);
        body->vfunc_96();
        body->flags |= 0x42;
        body->flags &= ~0x201;
        body->set_guard_state();
        body->action_step = 0;
        body->action_timer = 0xF;
        play_sound_effect(0x4003A64B, &body->position, 0, 0);
        break;
    case 3:
        if (body->action_step == 3) {
            TObjEneEpsilonGuard__sub_8035FA50(body);
            body->flags &= ~0x10;
            body->transition_enemy_state(4);
        } else if (body->action_step == 2) {
            body->transition_enemy_state(2);
        }
        break;
    case 0:
        body->advance_animation();
        switch (body->action_step) {
        case 0:
            body->action_timer--;
            if (((TObjEneEpsilonGuard *)body)->assign_guard_targets() == 1) {
                body->flags &= ~2;
                body->set_guard_state();
                body->action_step = 1;
                body->action_timer = 0x3C;
            } else if (body->action_timer <= 0) {
                body->action_step = 2;
            }
            break;
        case 1:
            body->action_timer--;
            if (body->action_timer == 0xF) {
                play_sound_effect(0x4003A345, &body->position, 0, 0);
            }
            if (TObjEneEpsilonGuard__sub_8035FBBC(body) != 0 || body->action_timer <= 0) {
                body->action_step = 3;
            }
            break;
        }
        body->vfunc_89();
        break;
    case 5:
        return;
    }
}

void action__19TObjEneEpsilonGuardFPvi(TObjEneEpsilonBody *body, s32 arg1) {
    s32 temp_r3;
    switch (arg1) {
    case 4:
        body->set_field_378(4);
        body->vfunc_96();
        body->flags |= 0x400;
        body->flags &= ~0x247;
        body->set_guard_state();
        body->action_step = 0;
        return;
    case 3:
        if (body->action_step == 2) {
            body->transition_enemy_state(5);
        }
        break;
    case 5:
        break;
    case 0:
        body->advance_animation();
        body->tick_stun_timer();
        switch (body->action_step) {
        case 0:
            temp_r3 = body->flags;
            if (((temp_r3 & 4) || (temp_r3 & 0x80)) && (TObjEneEpsilonGuard__sub_8035FCEC(body) != 0)) {
                body->action_step = 2;
                body->guard_phase_timer = body->guard_phase_frames;
            } else {
                TObjEneEpsilonGuard__sub_8035FB44(body);
                TObjEneEpsilonGuard::update_attack_pattern(body);
                if (body->flags & 0x10) {
                    body->action_step = 1;
                    body->action_timer = lbl_805D6F8C->m_24;
                }
            }
            break;
        case 1:
            body->action_timer--;
            if (body->action_timer <= 0) {
                body->flags &= ~0x10;
                body->action_step = 0;
            }
            break;
        }
        body->vfunc_89();
        break;
    }
}

void TObjEneEpsilonGuard__sub_803610D0(TObjEneEpsilonBody *body, s32 arg1) {
    switch (arg1) {
    case 4:
        body->set_field_378(4);
        body->vfunc_96();
        body->flags &= ~0x253;
        body->set_guard_state();
        body->action_step = 0;
        body->action_timer = 0xF;
        body->emitter = create_particle_emitter(&body->position, 0x225);
        if (body->emitter != 0) {
            body->emitter->enable();
        }
        play_sound_effect(0x4003A64B, &body->position, 0, 0);
        break;
    case 3:
        if (body->action_step == 5) {
            body->transition_enemy_state(6);
        } else if (body->action_step == 4) {
            body->transition_enemy_state(4);
        }
        break;
    case 0:
        body->advance_animation();
        switch (body->action_step) {
        case 0:
            body->action_timer--;
            if (TObjEneEpsilonGuard__sub_8035FAA8(body) == 1) {
                body->set_field_378(5);
                body->flags |= 0x40;
                body->action_step = 1;
                body->action_timer = 0x3C;
            } else if (body->action_timer <= 0) {
                body->action_step = 4;
            }
            if (body->emitter != 0) {
                body->emitter->enable();
            }
            break;
        case 1:
            body->action_timer--;
            if (TObjEneEpsilonGuard__sub_8035FCEC(body) != 0 || body->action_timer <= 0) {
                body->action_step = 2;
                body->action_timer = 8;
            }
            if (body->emitter != 0) {
                body->emitter->enable();
            }
            break;
        case 2:
            body->action_timer--;
            if (body->action_timer <= 0) {
                body->flags |= 2;
                body->set_guard_state();
                body->action_step = 3;
                body->action_timer = 8;
                play_sound_effect(0x4003A344, &body->position, 0, 0);
            }
            if (body->emitter != 0) {
                body->emitter->set_position(&body->position);
            }
            break;
        case 3:
            body->action_timer--;
            if (body->action_timer <= 0) {
                body->action_step = 5;
            }
            if (body->emitter != 0) {
                body->emitter->set_position(&body->position);
            }
            break;
        }
        body->vfunc_89();
        break;
    case 5:
        if (body->emitter != 0) {
            body->emitter->queue_destruction();
            body->emitter = 0;
        }
        break;
    }
}

void TObjEneEpsilonGuard::handle_warp_state(s32 arg1) {
    TObjEneEpsilonBody *body = (TObjEneEpsilonBody *)this;
    switch (arg1) {
    case 4:
        set_field_378(4);
        vfunc_96();
        body->flags |= 0x242;
        body->flags &= ~1;
        body->set_guard_state();
        body->action_step = 0;
        body->action_timer = 0;
        body->m_4f8 = 0.0f;
        body->warp_emitter = create_particle_emitter(&m_2fc, 0x220);
        break;
    case 3:
        if (body->action_step == 3) {
            transition_enemy_state(2);
        }
        break;
    case 0:
        advance_animation();
        if (body->warp_emitter != 0) {
            body->warp_emitter->set_position(&m_2fc);
        }
        switch (body->action_step) {
        case 0:
            body->m_4f8 += 0.033333335f;
            if (body->m_4f8 >= 1.0f) {
                body->m_4f8 = 1.0f;
                body->action_step = 1;
                body->action_timer = 0x1E;
                copy_argb(&body->color, &lbl_80479CAC[body->color_index]);
                body->color_index = (body->color_index + 1) % 4;
                body->color_step.r = (lbl_80479CAC[body->color_index].r - body->color.r) / 30.0f;
                body->color_step.g = (lbl_80479CAC[body->color_index].g - body->color.g) / 30.0f;
                body->color_step.b = (lbl_80479CAC[body->color_index].b - body->color.b) / 30.0f;
            }
            play_persistent_sound(0x4003A349, (s32)this, (u32)&position, 0, 0);
            break;
        case 1:
            body->action_timer--;
            body->color.r += body->color_step.r;
            body->color.g += body->color_step.g;
            body->color.b += body->color_step.b;
            if (body->action_timer <= 0) {
                copy_argb(&body->color, &lbl_80479CAC[body->color_index]);
                body->m_4f8 = 1.0f;
                body->action_step = 2;
            }
            play_persistent_sound(0x4003A349, (s32)this, (u32)&position, 0, 0);
            break;
        case 2:
            body->m_4f8 = body->m_4f8 - 0.033333335f;
            if (body->m_4f8 <= 0.0f) {
                body->m_4f8 = 0.0f;
                body->action_step = 3;
                play_sound_effect(0x40039F4A, &position, 0, 0);
            } else {
                play_persistent_sound(0x4003A349, (s32)this, (u32)&position, 0, 0);
            }
            break;
        }
        vfunc_89();
        break;
    case 5:
        if (body->warp_emitter != 0) {
            body->warp_emitter->queue_destruction();
            body->warp_emitter = 0;
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneEpsilonGuard__sub_80360BF8(TObjEneEpsilonBody *body, s32 arg1) {
    switch (arg1) {
    case 4:
        body->set_field_378(4);
        body->vfunc_96();
        body->flags |= 0x42;
        body->flags &= ~0x201;
        body->set_guard_state();
        body->action_step = 0;
        body->action_timer = 0x3C;
        return;
    case 5:
        break;
    case 3:
        if (body->action_step == 3) {
            body->transition_enemy_state(0);
            body->vfunc_95();
        }
        break;
    case 0:
        body->advance_animation();
        switch (body->action_step) {
        case 0:
            if (!(body->flags & 0x80)) {
                body->action_step = 2;
            } else {
                body->action_timer--;
                if (body->action_step <= 0) {
                    body->flags |= 0x40;
                    body->set_field_378(4);
                    body->action_step = 1;
                    body->fade.reset_color();
                }
            }
            break;
        case 1:
            if (body->fade.decay_value_toward_floor() != 0) {
                VecCopy(&body->position, &body->home_position);
                body->flags |= 1;
                body->action_step = 3;
            }
            break;
        }
        body->vfunc_89();
        break;
    }
}
#pragma pop

void TObjEneEpsilonBody::update_fade(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(2);
        vfunc_96();
        flags |= 0x10;
        flags &= ~0x243;
        set_guard_state();
        action_step = 0;
        flash_level = -0x22U;
        return;
    case 3:
        if (action_step == 2) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        switch (action_step) {
        case 0:
            flash_level += 0x22;
            if (flash_level > 0xFFU) {
                flash_level = 0xFFU;
                action_step = 1;
            }
            break;
        case 1:
            flash_level -= 0x22;
            if (flash_level <= 0x22U) {
                flash_level = 0U;
                action_step = 2;
            }
            break;
        default:
            flash_level = 0U;
            action_step = 2;
            break;
        }
        vfunc_89();
        return;
    case 5:
        clear_attack_receipts();
        break;
    }
}

void TObjEneEpsilonBody::action_destroy(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(9);
        vfunc_96();
        flags |= 0x800;
        flags &= ~0x243;
        set_guard_state();
        refresh_and_send_entity_flags();
        action_step = 0;
        action_timer = 0;
        break;
    case 3:
        if (action_step == 1 && ((TObjEneEpsilonGuard *)this)->all_children_gone() != 0) {
            queue_destruction();
        }
        break;
    case 5:
        break;
    case 0:
        if (action_step == 0) {
            advance_animation();
            action_timer++;
            if (action_timer >= 0x14) {
                vfunc_95();
                TBoss3Volopt::create_breakup_mdl((s32)lbl_805D6FA4, (s32)epsilon_guard_destroy_breakup_params, (s32)texlist, (s32)body_center(), (s32)rotation_y);
                play_sound_effect(0x4003AD4C, &m_2fc, 0, 0);
                ((TObjPlayer *)body_center())->trigger_dell_biter_events();
                flags |= 1;
                action_step = 1;
            }
        }
        break;
    }
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneEpsilonBody::render() {
    s32 var_r31;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_106();
        return;
    }
    if (!(this->actorFlags & 0x02000000)) {
        if (is_split_screen() != 0) {
            TCameraCtrl::get_camera_mode();
        }
        if (this->flags & 1) {
            var_r31 = 0;
        } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
            var_r31 = classify_actor_view_detail(650.0f, 650.0f, 30.0f);
        } else if (update_object_view_visibility(600.0f, 30.0f) != 0) {
            var_r31 = 1;
        } else {
            var_r31 = 0;
        }
        if (var_r31 != 0) {
            TObjEneDD::draw_ground_shadow(0, 0);
            this->defer_render();
            draw_with_fade__19TObjEneEpsilonGuardFPvi(this, var_r31);
            if ((s16) this->mode == 6) {
                if (this->flags & 0x200) {
                    this->render_body_effect();
                }
            }
        } else {
            i = 0;
            do {
                sub_803606A0(i);
                i += 1;
            } while (i < 4);
        }
        if ((s16) this->mode == 2) {
            if (this->flags & 0x100) {
                ((TObjEneEpsilonGuard *)this)->draw_debug_line();
            }
        }
    }
}
#pragma pop

void TObjEneEpsilonBody::sub_803606A0(s32 i) {
    EpsilonGuardSlotValues t = epsilon_guard_attack_offset_table;

    if (i < 0) {
        i = 0;
    } else if (i > 3) {
        i = 3;
    }
    push_matrix_from(identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[t.v[i]]);
    {
        Vec v = lbl_80479D10;
        matrix_mult_vec(0, &v, &guard_position[i]);
    }
    pop_matrix();
    guard_rotation_y[i] = (s32)(10430.38043493439 * atan2_float(guard_position[i].x - position.x, guard_position[i].z - position.z));
}

void TObjEneEpsilonGuard::draw_debug_line() {
    TObjEneEpsilonBody *body = (TObjEneEpsilonBody *)this;
    VecCopy(&lbl_805439FC[0], body->body_center());
    VecCopy(&lbl_805439FC[1], &body->fire_position);
    set_additive_blend();
    draw_line_list(&TObjEneEpsilonGuard__debug_line_list, 1, 5);
    set_default_alpha_blend();
}

void draw_with_fade__19TObjEneEpsilonGuardFPvi(TObjEneEpsilonBody *body, s32 arg1) {
    s32 i;
    RenderFadeState *r;
    i = 0;
    if (is_split_screen() != 0) {
        i = TCameraCtrl::get_camera_mode();
    }
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    body->set_guard_part_colors(&body->color);
    r = &body->fades[i];
    r->update();
    if (r->updateFromCamera(&body->m_2fc) != 0) {
        r->set_flags_and_apply_damage_color();
        if (!(get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if (body->fade.has_visible_opacity() != 0) {
        if (TObjEneMe3SinowZoa__sub_800D72A4(&body->fade) != 0) {
            body->fade.set_flags_and_apply_damage_color();
            if (!(get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200)) {
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                return;
            }
        } else if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else {
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        return;
    }
    body->update_secondary_light();
    TObjFish::set_global_param(body->texlist);
    push_matrix();
    post_translate_matrix(&body->position.x);
    translate_matrix(0, 0.0f, 24.0f, 0.0f);
    rotate_matrix_y(0, body->rotation_y);
    TObjEneDD::clear_global_flag_400();
    if (body->flags & 2) {
        set_chunk_model_node_callback((s32)((void *) TObjEneEpsilonGuard::record_camera_angle_samples));
    }
    TObjPlayer::toggle_particle_effect();
    epsilon_guard_camera_sample_read_ptr = body->guard_position;
    epsilon_guard_angle_sample_write_ptr = body->guard_rotation_y;
    epsilon_guard_camera_sample_end_ptr = &body->position;
    if (body->mode == 8) {
        s32 c = (body->flash_level & 0xFF) << 0x10;
        epsilon_guard_camera_sample_phase = -1;
        body->draw_with_alt_model(c | 0xFF000000);
    } else {
        epsilon_guard_camera_sample_phase = 0;
        if (arg1 == 1) {
            body->draw();
        } else {
            body->draw_motion_model();
        }
    }
    TParticleCtrl::end_effect_render();
    if (body->flags & 2) {
        set_chunk_model_node_callback((s32)NULL);
    }
    pop_matrix();
    body->update_primary_light();
    if (r->updateFromCamera(&body->m_2fc) != 0) {
        r->clear_flag_and_notify();
    } else if ((body->fade.has_visible_opacity() != 0) && (TObjEneMe3SinowZoa__sub_800D72A4(&body->fade) != 0)) {
        body->fade.clear_flag_and_notify();
    }
    model_render_flags = saved_model_render_flags;
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
}

void TObjEneEpsilonBody::render_body_effect() {
    f32 temp_f1;
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200) {
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, 24.0f, 0.0f);
        rotate_matrix_y(0, rotation_y);
        temp_f1 = m_4f8;
        scale_matrix(0, temp_f1, 1.0f, temp_f1);
        TObjFish::set_global_param(texlist);
        TObjPlayer::toggle_particle_effect();
        get_bml_model(lbl_805D6FA0, 4);
        draw_chunk_object();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjEneEpsilonGuard::record_camera_angle_samples() {
    switch (epsilon_guard_camera_sample_phase) {
    case 0x1C:
    case 0x26:
    case 0x30:
    case 0x3A:
        get_camera_ctrl__9TObjEneDDFv(lbl_805439F0, epsilon_guard_camera_sample_read_ptr);
        *epsilon_guard_angle_sample_write_ptr = (s32)(10430.38043493439 * atan2_float(
            epsilon_guard_camera_sample_read_ptr->x - epsilon_guard_camera_sample_end_ptr->x,
            epsilon_guard_camera_sample_read_ptr->z - epsilon_guard_camera_sample_end_ptr->z));
        epsilon_guard_camera_sample_read_ptr++;
        epsilon_guard_angle_sample_write_ptr++;
        break;
    }
    epsilon_guard_camera_sample_phase++;
}
void TObjEneEpsilonBody::vfunc_106() {  }
void TObjEneEpsilonBody::set_guard_state() {
    if (flags & 2) {
        guarded = 1;
        model = (void *)get_bml_model(lbl_805D6FA0, 0);
        requested_action = 0;
        set_indexed_flags(1, 1);
        clear_player_status_flag(0, 1);
    } else {
        guarded = 0;
        model = (void *)get_bml_model(lbl_805D6FA0, 1);
        requested_action = 1;
        set_indexed_flags(0, 1);
        clear_player_status_flag(1, 1);
    }
    advance_animation();
}

void TObjEneEpsilonBody::tick_timer_set_flag() {
    fire_phase_timer--;
    if (fire_phase_timer <= 0) {
        flags |= 8;
    }
}

void TObjEneEpsilonBody::tick_stun_timer() {
    guard_phase_timer--;
    if (guard_phase_timer <= 0) {
        flags |= 4;
    }
}
void TObjEneEpsilonGuard::update_attack_pattern(void *arg0) {
    TObjEneEpsilonBody *body = (TObjEneEpsilonBody *)arg0;
    EpsilonGuardAttackPatterns t = epsilon_guard_attack_pattern_table;
    s32 *row;
    s32 i;
    if (body->flags & 0x400) {
        body->attack_pattern_timer--;
        if (body->attack_pattern_timer <= 0) {
            row = t.v[(s32)(20.0f * body->random_ratio()) % 20];
            for (i = 0; i < 4; i++) {
                if (row[i] == 1) {
                    TObjEneEpsilonGuard__sub_8035F844(body, i);
                }
            }
            body->flags &= ~0x400;
        }
    } else if (TObjEneEpsilonGuard__sub_8035FC20(body) != 0) {
        body->flags |= 0x400;
        body->attack_pattern_timer = lbl_805D6F8C->m_20;
    }
}

// Picks the player for guard slot `slot`: the up to four nearest players in
// range with a clear path, sorted by distance and repeated to fill four slots.
u32 TObjEneEpsilonGuard__sub_8035FD50(TObjEneEpsilonBody *body, s32 slot) {
    EpsilonGuardSlotValues order = lbl_80479E5C;
    EnemyTargetCandidate list[4];
    Vec d;
    EnemyTargetCandidate tmp;
    s32 n;
    s32 id;
    s32 extra;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    TObjPlayer *player;
    f32 dist;

    list[0].id = 0xFFFF;
    list[0].distance_squared = 0.0f;
    n = 0;
    extra = body->vfunc_99();
    count = registered_player_count;
    if (extra != 0) {
        count += lbl_805D5870;
    }
    for (id = 0; id < count; id++) {
        player = TObjPlayer::get_player_data(id);
        if (TObjPlayer::is_valid_and_active((u32)player) == 0) continue;
        if (player->actorFlags & 0x2000800) continue;
        VecCopy(&d, player->body_center());
        subtract_vector(&d, body->body_center());
        dist = d.x * d.x + d.z * d.z;
        if (!(dist < 160000.0f)) continue;
        if (check_path_obstructed(body, &player->m_2fc) == 1) continue;
        list[n].distance_squared = dist;
        list[n].id = id;
        n++;
        if (n >= 4) break;
    }
    if (n <= 0) {
        return 0xFFFF;
    }
    if (n >= 2) {
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (list[i].distance_squared > list[j].distance_squared) {
                    tmp.copy_from(&list[i]);
                    list[i].copy_from(&list[j]);
                    list[j].copy_from(&tmp);
                }
            }
        }
    }
    for (k = n; k < 4; k++) {
        list[k].copy_from(&list[k % n]);
    }
    return list[order.v[slot % 4]].id;
}

s32 TObjEneEpsilonGuard__sub_8035FCEC(TObjEneEpsilonBody *body) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[i]))->is_guard_ready() == 0) {
            return 0;
        }
    }
    return 1;
}

s32 TObjEneEpsilonGuard::all_children_gone() {
    TObjEneEpsilonBody *body = (TObjEneEpsilonBody *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (find_entity_by_id(body->guard_ids[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

s32 TObjEneEpsilonGuard__sub_8035FC20(TObjEneEpsilonBody *body) {
    s32 i;
    TObjEneEpsilonGuard *guard;
    for (i = 0; i < 4; i++) {
        if ((guard = (TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[i])) != 0 && guard->is_state_flag_set() == 0) {
            return 0;
        }
    }
    return 1;
}

s32 TObjEneEpsilonGuard__sub_8035FBBC(TObjEneEpsilonBody *body) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[i]))->is_guard_active() == 0) {
            return 0;
        }
    }
    return 1;
}

void TObjEneEpsilonGuard__sub_8035FB44(TObjEneEpsilonBody *body) {
    s32 i;
    TObjCollidable *guard;
    body->flags &= ~0x20;
    for (i = 0; i < 4; i++) {
        if ((guard = find_entity_by_id(body->guard_ids[i])) != 0 && TObjEneEpsilonGuard__sub_8035DD68((TObjEneEpsilonGuard *)guard) == 1) {
            body->flags |= 0x20;
        }
    }
}
s32 TObjEneEpsilonGuard__sub_8035FAA8(TObjEneEpsilonBody *body) {
    s32 i;
    TObjEneEpsilonGuard *guard;
    for (i = 0; i < 4; i++) {
        if ((guard = (TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[i])) != 0 && guard->is_guard_ready() == 0) {
            return 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((guard = (TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[i])) != 0) {
            guard->set_flag_8_and_notify();
        }
    }
    return 1;
}

void TObjEneEpsilonGuard__sub_8035FA50(TObjEneEpsilonBody *body) {
    s32 i;
    TObjCollidable *guard;
    for (i = 0; i < 4; i++) {
        if ((guard = find_entity_by_id(body->guard_ids[i])) != 0) {
            TObjEneEpsilonGuard__sub_8035DEC0((TObjEneEpsilonGuard *)guard);
        }
    }
}

s32 TObjEneEpsilonGuard::assign_guard_targets() {
    s32 i;
    s32 near;
    TObjEneEpsilonGuard *guard;
    TObjEneEpsilonBody *body = (TObjEneEpsilonBody *)this;
    for (i = 0; i < 4; i++) {
        guard = (TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[i]);
        if (guard != 0 && TObjEneEpsilonGuard__sub_8035DD74(guard) == 0) {
            return 0;
        }
    }
    near = random_ratio() < 0.5;
    for (i = 0; i < 4; i++) {
        guard = (TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[i]);
        if (guard != 0) {
            guard->set_target((s32)&body->guard_position[i], body->guard_rotation_y[i], near);
        }
    }
    return 1;
}
int TObjEneEpsilonGuard__sub_8035F968(void) { return 0; }
int TObjEneEpsilonGuard__sub_8035F95C(TObjEneEpsilonBody *body) { return ((u32)body->flags >> 5) & 1; }

int TObjEneEpsilonGuard__sub_8035F950(TObjEneEpsilonBody *body) { return ((u32)body->flags >> 11) & 1; }

s16 TObjEneEpsilonBody::get_table_value_by_index() {
    s16 i = this->color_index;
    EpsilonGuardSlotValues t = epsilon_guard_table_value_set;
    if (i < 0 || i > 3) {
        return 0;
    }
    return t.v[i];
}

s16 TObjEneEpsilonBody::sub_8035F8A8() {
    s16 i = this->color_index;
    EpsilonGuardSlotValues16 t = lbl_80479E7C;
    if (i < 0 || i > 3) {
        return 0;
    }
    return t.v[i];
}

void TObjEneEpsilonGuard__sub_8035F844(TObjEneEpsilonBody *body, s32 slot) {
    TObjEneEpsilonGuard *guard;
    if (slot < 0 || slot >= 4) {
        return;
    }
    guard = (TObjEneEpsilonGuard *)find_entity_by_id(body->guard_ids[slot]);
    if (guard != 0 && guard->is_state_flag_set() == 1) {
        guard->clear_and_flag_state();
    }
}

f32 TObjEneEpsilonBody::receive_direct_attack(void *attacker, DirectAttackPayload payload, void *source, s32 arg3, s32 arg4) {
    s32 flags = this->flags;
    if (!(flags & 2) && !(flags & 0x40)) {
        if (payload.kind != get_table_value_by_index()) {
            return TObjChara::receive_direct_attack(attacker, payload, source, arg3, arg4);
        }
    } else if (payload.kind == 0x14) {
        return TObjChara::receive_direct_attack(attacker, payload, source, arg3, arg4);
    }
    try_apply_damage((u32)&m_2fc, 0);
    return 0.0f;
}

f32 TObjEneEpsilonBody::receive_physical_attack(void *arg1_arg, f32 farg0) {
    s32 temp_r5;
    temp_r5 = this->flags;
    if (!(temp_r5 & 2) && !(temp_r5 & 0x40)) {
        return TObjChara::receive_physical_attack(arg1_arg, farg0);
    }
    try_apply_damage((u32)&m_2fc, 0);
    return 0.0f;
}
f32 TObjEneEpsilonBody::receive_weapon_special_attack(void *src, void *hit) {
    if (!(flags & 2) && !(flags & 0x40)) {
        s16 kind = ((TObjPlayer *)src)->obj_getS16_116();
        s32 strong;
        obj_getS16_118((u8 *)src);
        strong = 0;
        if (src == NULL || get_entity_id((TObjBase *)src) == 0xFFFF) {
            show_miss_popup(&position.x);
            return 0.0f;
        }
        if (obj_testFlags30(0x04000000) != 0) {
            strong = 1;
        }
        if (hit != NULL && (((CollisionBody *)hit)->flags & 0x02000000)) {
            strong = 1;
        }
        if (strong != 0) {
            switch (kind) {
            case 0:
                break;
            case 1:
            case 2:
            case 5:
            case 6:
            case 7:
            case 9:
            case 10:
                try_apply_damage((u32)&m_2fc, 0);
                break;
            case 3:
            case 4:
            case 8:
            case 11:
            case 12:
            case 13:
                show_miss_popup(&m_2fc);
                break;
            }
            return 0.0f;
        }
        if (((TObjPlayer *)src)->obj_getS16_116() != sub_8035F8A8()) {
            return TObjChara::receive_weapon_special_attack(src, hit);
        }
    }
    try_apply_damage((u32)&m_2fc, 0);
    return 0.0f;
}
}

