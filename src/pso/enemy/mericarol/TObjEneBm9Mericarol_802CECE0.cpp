#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/math/AngleUnits.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/vector.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_EffCurse3.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_Bomb.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"

struct Sub_800ACA10 { u8 pad[0x18]; s32 level; };

s32 tick_period_counter(s32 arg0, s32 *arg1, s32 arg2);

extern "C" {
extern const f32 lbl_805DE6F4;
extern const f32 lbl_805DE704;
extern const f32 lbl_805DE70C;
extern const f32 lbl_805DE710;
extern const f32 lbl_805DE714;
extern const f32 lbl_805DE718;
extern const f32 lbl_805DE71C;
extern const f32 lbl_805DE720;
extern const f32 lbl_805DE724;
extern const f32 lbl_805DE728;
extern const f32 lbl_805DE72C;
extern const f32 lbl_805DE730;
extern const f32 lbl_805DE734;
extern const f32 lbl_805DE738;
extern s32 game_difficulty_selection;
extern SampledMotionPoints *TBoss4Type3_shared_instance;
extern SampledMotionPoints *lbl_805D6864;
extern s32 lbl_805D686C;
void vec3_add_to(Vec *dst, const Vec *src);
void TBoss8Dragon__sub_800BB7D4(TObjEneBm9Mericarol *self, s32 arg1);
f64 atan2_float(f32 y, f32 x);
void fill_value_array(AreaAttackHistory *history);
s32 enemy_validate_retained_target(TObjEneBm9Mericarol *self);
s32 approach_angle_limited(s32 from, s32 to, s32 max_step);
s32 angle_difference_abs(s32 a, s32 b);
void fn_802CE510(TObjEneBm9Mericarol *self);
s32 obj_is_hit_receivable();
void obj_setFlags30(void *object, s32 flags);
s32 attack_target_history_add(AreaAttackHistory *history, TObjChara *target);
void mult_vec_array__10TObjPlayerFUll(u32 matrix, Vec *src, Vec *dst, s32 count);
s32 push_matrix();
s32 post_translate_matrix(const Vec *v);
void create__9TTecKafunFllllllff(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1);
void enemy_set_target_id(TObjEneBm9Mericarol *self, u16 id);
u16 set_squared_value__9TObjEneDDFf(TObjEneBm9Mericarol *self, f32 range);
u16 enemy_find_nearest_player_in_range(TObjEneBm9Mericarol *self, f32 range);
}

void TObjEneBm9Mericarol::update_particle_effect() {
    switch (lbl_805D686C) {
    case 0x21:
    case 0x2B:
    case 0x64:
        TParticleCtrl::begin_effect_render();
        break;
    default:
        TParticleCtrl::end_effect_render();
        break;
    }
    lbl_805D686C += 1;
}

void TObjEneBm9Mericarol::vfunc_105() {  }
void TObjEneBm9Mericarol::sub_802CED40() {
    m_438 |= 2;
}

s32 TObjEneBm9Mericarol::get_clamped_level() {
    Sub_800ACA10 *p = (Sub_800ACA10 *)m_2b0;
    s32 v = 0;
    if (p != 0) {
        v = p->level;
        if (v < 0) {
            return 0;
        }
        if (game_difficulty_selection == 3) {
            if (v > 0x1D) {
                v = 0x1D;
            }
            return v;
        }
        if (v > 0xE) {
            v = 0xE;
        }
    }
    return v;
}

void TObjEneBm9Mericarol::sub_802CEDA0(s32 arg1) {
    Vec pos;
    switch (arg1) {
    case 4:
        requested_action = 2;
        set_field_378(3);
        m_438 &= ~8;
        m_438 |= 0x20;
        m_490 = 0;
        m_494 = mericarol_phase_param_table[get_phase()]->m_24;
        break;
    case 3:
        switch (m_490) {
        case 3:
            transition_enemy_state(3);
            break;
        case 2:
            transition_enemy_state(8);
            break;
        }
        break;
    case 0:
        advance_animation();
        switch (m_490) {
        case 0:
            m_494--;
            if (m_494 <= 0) {
                f32 lim = mericarol_phase_param_table[get_phase()]->m_14;
                if (random_ratio() <= lim) {
                    m_490 = 2;
                } else {
                    requested_action = 0;
                    m_490 = 1;
                }
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            vfunc_89();
            if (m_494 % 14 == 0) {
                play_sound_effect(remap_sound_for_area(0x3A809), &position, 0, 0);
            }
            break;
        case 1:
            if (is_passing_frame(lbl_805DE710) != 0) {
                VecCopy(&pos, &position);
                pos.y += lbl_805DE704;
                ((void (*)(void *, void *, s32, s32, s32, f32, s32, f32))create__9TTecKafunFllllllff)(this, &pos, 5, 0x20B, 0x20C,
                    mericarol_phase_param_table[get_phase()]->m_4, get_clamped_level(),
                    mericarol_phase_param_table[get_phase()]->m_10);
                play_sound_effect(remap_sound_for_area(0x3A80A), &position, 0, 0);
            }
            if (get_flag_b4() != 0) {
                m_490 = 3;
            }
            break;
        }
        break;
    case 5:
        break;
    }
}

void TObjEneBm9Mericarol::handle_motion_event(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 7;
        vfunc_96();
        sub_802D093C();
        m_438 &= ~0x28;
        set_field_378(3);
        m_490 = 0;
        play_sound_effect(remap_sound_for_area(0x3AD0F), &position, 0, 0);
        return;
    case 3:
        if (is_passing_frame(frame_count - lbl_805DE6F4) != 0) {
            transition_enemy_state(3);
        }
        vfunc_102();
        vfunc_88();
        return;
    case 0:
        advance_animation();
        m_490 = m_490 + 1;
        sub_802D073C();
        return;
    case 5:
        m_438 &= ~2;
    case 1:
        return;
    }
}

void TObjEneBm9Mericarol::handle_state_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction();
        return;
    }
}

void TObjEneBm9Mericarol::state_burrow(s32 arg1) {
    f32 x;
    Vec pos;
    switch (arg1) {
    case 4:
        requested_action = 6;
        vfunc_96();
        sub_802D093C();
        m_438 &= ~0x28;
        refresh_and_send_entity_flags();
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        m_490 = 0;
        m_4a4 = lbl_805DE70C;
        play_sound_effect(remap_sound_for_area(0x3AA0B), &position, 0, 0);
        return;
    case 3:
        if (m_490 == 2) {
            transition_enemy_state(0xC);
        }
    case 5:
        return;
    case 0:
        switch (m_490) {
        case 0:
            advance_animation();
            if (get_flag_b4() != 0) {
                m_490 = 1;
                x = lbl_805DE710 * sin_table_lookup(rotation_y);
                pos.y = lbl_805DE70C;
                pos.x = x;
                pos.z = lbl_805DE710 * cos_table_lookup(rotation_y);
                vec3_add_to(&pos, &position);
                TObjPlayer::spawn_dead_spot_here((s32)&pos, 0x32);
                ((TObjPlayer *)&pos)->spawn_ground_effect(0x46);
            }
            vfunc_102();
            return;
        case 1:
            position.y = position.y - lbl_805DE714;
            m_4a4 = m_4a4 + lbl_805DE714;
            if (m_4a4 > lbl_805DE718) {
                m_490 = 2;
            }
            break;
        }
        break;
    }
}
void TObjEneBm9Mericarol::sub_802CF368(s32 arg1) {
    s16 max;
    s16 cur;
    switch (arg1) {
    case 4:
        requested_action = 5;
        vfunc_96();
        sub_802D093C();
        m_438 &= ~0x28;
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        play_sound_effect(remap_sound_for_area(0x3AA0C), &position, 0, 0);
        return;
    case 3:
        if (get_flag_b4() != 0) {
            max = hpmax;
            cur = hp;
            if (cur <= max / 2 && cur >= max / 5 && random_ratio() <= m_440) {
                transition_enemy_state(6);
                return;
            }
            if (random_ratio() < lbl_805DE71C) {
                transition_enemy_state(7);
                return;
            }
            transition_enemy_state(m_378);
        }
        return;
    case 0:
        advance_animation();
        vfunc_102();
        vfunc_88();
        sub_802D073C();
        return;
    case 5:
        actorFlags &= ~0x200;
        m_438 &= ~2;
        clear_attack_receipts();
        break;
    }
}
void TObjEneBm9Mericarol::sub_802CF4F8(s32 arg1) {
    s32 count;
    TObjPlayer *target;
    switch (arg1) {
    case 4:
        requested_action = 2;
        vfunc_96();
        vfunc_91();
        sub_802D093C();
        m_438 &= ~8;
        m_438 |= 0x20;
        m_490 = 0;
        m_494 = 0;
        return;
    case 3:
        if (m_490 >= 0x1E) {
            transition_enemy_state(3);
        }
        return;
    case 0:
        advance_animation();
        count = m_490;
        if (count == 6) {
            target = find_nearby_target();
            if (target != NULL) {
                new TObjEneBm9Mericarol_EffCurse3(this, target);
                m_390 = target;
                m_494 = 1;
                play_sound_effect(remap_sound_for_area(0x3A808), &position, 0, 0);
            }
        } else if (count == 0x19 && m_494 != 0 && m_390->is_alive() != 0) {
            ((TObjPlayer *)m_390)->set_tp(0);
        }
        m_490++;
        vfunc_102();
        vfunc_88();
        sub_802D073C();
        return;
    case 5:
        actorFlags &= ~0x4000000;
        m_438 &= ~2;
        break;
    }
}

s32 TObjEneBm9Mericarol::check_attack_hits() {
    s32 ret;
    s32 i;
    TObjChara *p;
    ret = 0;
    TObjPlayer::init_all_slots();
    check_object_collisions();
    if (bodies->flags & 0x80000) {
        ret = 1;
        for (i = 0; i < 16; i++) {
            p = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (p == NULL) {
                break;
            }
            if (obj_is_hit_receivable() != 0 && attack_target_history_add(m_488, p) != 0) {
                DirectAttackPayload t;
                t.kind = 0;
                t.power = mericarol_phase_param_table[get_phase()]->m_0;
                DirectAttackPayload payload = t;
                if (p->receive_direct_attack(this, payload, 0, -1, -1) > lbl_805DE70C) {
                    obj_setFlags30(p, 0x600);
                }
            }
        }
    }
    return ret;
}

void TObjEneBm9Mericarol::sub_802CF7B4(s32 arg1) {
    s32 hit_wall;
    switch (arg1) {
    case 4:
        sync_center_position();
        if (((TBoss5Gryphon *)this)->enemy_probe_wall_ahead(m_3a0.x, m_3a0.z, lbl_805DE720) != 0U) {
            requested_action = 3;
            m_490 = 3;
            return;
        }
        requested_action = 2;
        set_field_378(3);
        m_438 &= ~0x28;
        m_490 = 0;
        m_494 = 0;
        m_498 = 0xA;
        m_4a4 = m_444;
        m_4a8 = lbl_805DE70C;
        fill_value_array(m_488);
        set_active();
        return;
    case 3:
        if (m_490 == 3) {
            transition_enemy_state(3);
        }
        return;
    case 0:
        advance_animation();
        switch (m_490) {
        case 0:
            sync_center_position();
            if (((TBoss5Gryphon *)this)->enemy_probe_wall_ahead(m_3a0.x, m_3a0.z, lbl_805DE720) != 0U) {
                requested_action = 3;
                m_490 = 3;
                play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
                return;
            }
            m_498 = m_498 - 1;
            if (m_498 <= 0) {
                requested_action = 1;
                m_490 = 1;
                m_438 |= 0x20;
                bodies->flags |= 0x700;
                play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(m_3a0.x, m_3a0.z));
            rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
            vfunc_89();
            return;
        case 1:
            fn_802CE510(this);
            hit_wall = 0;
            sync_center_position();
            if (((TBoss5Gryphon *)this)->enemy_probe_wall_ahead(m_3a0.x, m_3a0.z, lbl_805DE718 * m_444) != 0U) {
                hit_wall = 1;
            }
            move_clamped_on_ground(m_3a0.x, m_3a0.z, m_444);
            if (has_move_failures(1) != 0) {
                hit_wall = 1;
            }
            update_enemy_collision_flags();
            if (bodies->flags & 0x200000) {
                hit_wall = 1;
            }
            check_attack_hits();
            m_4a8 = m_4a8 + m_444;
            if (m_4a8 >= lbl_805DE724) {
                hit_wall = 1;
            }
            if (hit_wall != 0) {
                m_490 = 2;
                m_494 = 0;
                m_438 &= ~0x20;
                set_field_378(3);
                return;
            }
            break;
        case 2:
            m_494 = m_494 + 1;
            m_4a4 = m_4a4 * lbl_805DE728;
            if (m_494 >= 0xA) {
                requested_action = 3;
                m_490 = 3;
            }
            vfunc_89();
            move_clamped_on_ground(m_3a0.x, m_3a0.z, m_4a4);
            return;
        }
        break;
    case 5:
        m_438 &= ~0x20;
        bodies->flags &= ~0x700;
        clear_field_388();
        break;
    }
}
void TObjEneBm9Mericarol::sub_802CFB64(s32 arg1) {
    Vec trail0[2];
    Vec trail1[2];
    s32 i;
    Vec *points1;
    Vec *points0;
    TObjChara *p;
    switch (arg1) {
    case 4:
        requested_action = 8;
        vfunc_96();
        sub_802D0940();
        m_438 &= ~8;
        m_438 |= 0x20;
        set_field_378(3);
        m_490 = 0;
        m_494 = 0;
        break;
    case 3:
        if (m_490 == 2) {
            transition_enemy_state(3);
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        enemy_validate_retained_target(this);
        switch (m_490) {
        case 2:
            break;
        case 0:
            if (is_passing_frame(frame_count - lbl_805DE6F4 - play_speed) != 0) {
                m_490 = 1;
                m_438 &= ~0x20;
                requested_action = 3;
                m_494 = 0;
                play_speed = lbl_805DE70C;
            } else {
                if (is_passing_frame(lbl_805DE72C) != 0) {
                    VecCopy(&m_48c->position, &position);
                    TObjPlayer::init_all_slots();
                    m_48c->check_object_collisions();
                    if (m_48c->bodies->flags & 0x80000) {
                        for (i = 0; i < 0x10; i++) {
                            p = (TObjChara *)TObjPlayer::get_battle_param(i);
                            if (p == NULL) {
                                break;
                            }
                            if (obj_is_hit_receivable() != 0 && p->select_melee_contact_body(this, lbl_805DE6F4) != 0) {
                                p->apply_knockback_from_attacker((u8 *)this, lbl_805DE6F4);
                                p->receive_physical_attack(this, lbl_805DE6F4);
                            }
                        }
                    }
                } else if (is_passing_frame(lbl_805DE730) != 0) {
                    play_sound_effect(remap_sound_for_area(0x3A40D), &position, 0, 0);
                }
                points0 = TBoss4Type3_shared_instance->lookup(frame);
                points1 = lbl_805D6864->lookup(frame);
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position);
                rotate_matrix_y(0, rotation_y);
                mult_vec_array__10TObjPlayerFUll(0, points0, trail0, 2);
                mult_vec_array__10TObjPlayerFUll(0, points1, trail1, 2);
                pop_matrix();
                if (m_3c0[0] != NULL) {
                    m_3c0[0]->vfunc_6(&trail0[0], &trail0[1]);
                }
                if (m_3c0[1] != NULL) {
                    m_3c0[1]->vfunc_6(&trail1[0], &trail1[1]);
                }
            }
            break;
        case 1:
            m_494++;
            if (m_494 >= mericarol_phase_param_table[get_phase()]->m_28) {
                m_490 = 2;
            }
            break;
        }
        enemy_copy_target_destination();
        update_velocity();
        m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(m_3a0.x, m_3a0.z));
        rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        vfunc_102();
        vfunc_88();
        sub_802D073C();
        break;
    case 5:
        m_438 &= ~2;
        break;
    }
}
void TObjEneBm9Mericarol::handle_shot_state(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0;
        vfunc_96();
        sub_802D0940();
        m_438 &= ~8;
        m_438 |= 0x20;
        set_field_378(3);
        m_4ac = 0;
        break;
    case 3:
        if (try_set_mode8_if_flag2() == 0 && get_flag_b4() != 0) {
            transition_enemy_state(3);
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        if (is_passing_frame(lbl_805DE710) != 0) {
            sub_802CE68C(&m_460, 0x43);
            new TObjEneBm9Mericarol_Bomb(this, &m_460, &m_390->position,
                mericarol_phase_param_table[get_phase()]->m_8, mericarol_phase_param_table[get_phase()]->m_c,
                random_ratio() <= (f32)mericarol_phase_param_table[get_phase()]->m_2c / lbl_805DE720);
            play_sound_effect(remap_sound_for_area(0x3A307), &m_460, 0, 0);
        }
        enemy_copy_target_destination();
        update_velocity();
        m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(m_3a0.x, m_3a0.z));
        rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        vfunc_102();
        vfunc_88();
        sub_802D073C();
        break;
    case 5:
        if (m_4ac != 0) {
            m_4ac->queue_destruction();
            m_4ac = 0;
        }
        break;
    }
}
void TObjEneBm9Mericarol::sub_802D01D8(s32 arg1) {
    f32 distance;
    u16 target;
    switch (arg1) {
    case 4:
        if (mode == 2) {
            requested_action = 4;
            play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
        } else {
            requested_action = 3;
        }
        vfunc_96();
        sub_802D0940();
        m_438 &= ~0x28;
        set_field_378(3);
        m_494 = 0;
        m_4a0 = 0;
        break;
    case 3:
        if (try_set_mode8_if_flag2() != 0) {
            break;
        }
        distance = m_3ac;
        if (distance > lbl_805DE734 || m_390 == 0) {
            transition_enemy_state(2);
            break;
        }
        if (distance < lbl_805DE738) {
            if (angle_difference_abs(rotation_y, m_4a0) < 0x4000) {
                if (random_ratio() <= m_448) {
                    transition_enemy_state(9);
                    break;
                }
                transition_enemy_state(5);
            }
        } else if (m_494 > mericarol_phase_param_table[get_phase()]->m_20) {
            transition_enemy_state(4);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        target = 0xFFFF;
        if (tick_period_counter((s32)this, &m_450, 0x14) != 0) {
            if (m_3ac > lbl_805DE718) {
                if (vfunc_99() != 0) {
                    target = set_squared_value__9TObjEneDDFf(this, m_3ac - lbl_805DE718);
                }
                if (target == 0xFFFF) {
                    target = enemy_find_nearest_player_in_range(this, m_3ac - lbl_805DE718);
                }
                if (target != 0xFFFF) {
                    enemy_set_target_id(this, target);
                }
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        enemy_copy_target_destination();
        update_velocity();
        m_494++;
        m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(m_3a0.x, m_3a0.z));
        rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        vfunc_102();
        vfunc_88();
        sub_802D073C();
        break;
    }
}
