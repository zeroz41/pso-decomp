#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/wolf/TObjEneBm5Wolf.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"

extern "C" {
f32 random_ratio__9TObjCharaFv(s32);
f32 atan2_float(f64, f64);
s32 approach_angle_limited(int, int, int);
void *find_entity_by_id(u16 id);
void advance_pose_turn__14TObjEneBm5WolfFPvi(TObjEneBm5Wolf *wolf, s32 target);
}
extern "C" {
s32 rotate_xz_pair_by_angle(void *, void *, s32);
TObjEneBm5Wolf *find_pack_leader__14TObjEneBm5WolfFi(s32 id);
void *fn_800B8B00(void *p);
u16 get_entity_id(TObjBase *object);
void run_task__14TObjEneBm5WolfFv(u8 *arg0);
void vfunc_62__14TObjEneBm5WolfFv(void* p);
void vfunc_63__14TObjEneBm5WolfFv(void *arg0);
void vfunc_88__14TObjEneBm5WolfFv(void *arg0);
extern u32 TObjEneBm5Wolf__instance_list[];
extern u32 TObjEneBm5Wolf__pack_member_list[];
extern const f32 TObjEneBm5Wolf__data_805D9DB4;
BmlResource *TObjEneBm5Wolf__bml_resource;
extern const char lbl_8043B3C8[];
extern const char lbl_8043B3DC[];
extern const char lbl_8043B3F0[];
extern const char lbl_8043B408[];
extern const char lbl_8043B424[];
extern const char lbl_8043B440[];
extern const char lbl_8043B458[];
extern const char lbl_8043B470[];
extern const char lbl_8043B488[];
extern const char lbl_8043B4A0[];
extern const char lbl_8043B4B8[];
extern const char lbl_8043B4D0[];
extern const char lbl_8043B4E8[];
extern const char lbl_8043B504[];
extern const char lbl_8043B520[];
extern const char lbl_8043B538[];
extern const char lbl_8043B550[];
void *bm5_wolf_decision_row[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
CollisionBody TObjEneBm5Wolf__collider_params[3] = {
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x8003 },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9d03 },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9d03 },
};
const char *bm_ene_bm5_wolf_model_names[3] = {
    lbl_8043B3C8, lbl_8043B3DC, NULL,
};
const char *bm_ene_bm5_wolf_motion_names[15] = {
    lbl_8043B3F0, lbl_8043B408, lbl_8043B424, lbl_8043B440,
    lbl_8043B458, lbl_8043B470, lbl_8043B488, lbl_8043B4A0,
    lbl_8043B4B8, lbl_8043B4D0, lbl_8043B4E8, lbl_8043B504,
    lbl_8043B520, lbl_8043B538, NULL,
};
BmlResourceDescriptor bm_ene_bm5_wolf_resource_descriptor = {
    lbl_8043B550, bm_ene_bm5_wolf_model_names, bm_ene_bm5_wolf_motion_names, 2, 14,
};
TObjMotionAction wolf_action_table[19] = {
    { 1, 0, 12, 0.8f, 0x0 },
    { 1, 0, 13, 1.0f, 0x0 },
    { 1, 0, 9, 1.0f, 0x0 },
    { 1, 0, 9, 1.0f, 0x0 },
    { 3, 0, 10, 0.5f, 0x0 },
    { 3, 0, 11, 0.5f, 0x0 },
    { 3, 0, 0, 1.0f, 0x0 },
    { 2, 8, 1, 1.5f, 0x0 },
    { 3, 0, 6, 0.5f, 0x0 },
    { 2, 10, 2, 1.5f, 0x0 },
    { 3, 0, 7, 0.5f, 0x0 },
    { 3, 0, 4, 0.4f, 0x0 },
    { 3, 0, 5, 1.5f, 0x0 },
    { 3, 0, 3, 0.8f, 0x0 },
    { 3, 0, 1, 1.0f, 0x0 },
    { 3, 0, 2, 1.0f, 0x0 },
    { 2, 11, 11, 0.5f, 0x0 },
    { 3, 0, 5, 1.0f, 0x0 },
    { 3, 0, 9, 1.0f, 0x0 },
};
__declspec(section ".data") s32 TObjEneBm5Wolf__stat_params[2];
__declspec(section ".data") s32 wolf_stat_handle_a_table[2];
__declspec(section ".data") s32 wolf_stat_handle_b_table[2];
__declspec(section ".data") s32 lbl_80500B58[2];
}

extern "C" {
s32 is_vec_xz_cross_negative(void *, void *);
f32 calc_circle_offset__14TObjEneBm5WolfFPvPvPv(TObjEneBm5Wolf *wolf, Vec *target, Vec *out);
extern const f32 TObjEneBm5Wolf__data_805D9D78;
extern const f32 TObjEneBm5Wolf__data_805D9D80;
extern const f32 TObjEneBm5Wolf__data_805D9DAC;
extern const f32 lbl_805D9DCC;
extern const f32 TObjEneBm5Wolf__data_805D9DD0;
extern const f32 lbl_805D9DF8;
extern const f32 lbl_805D9DFC;
extern const f32 lbl_805D9E00;
extern const f32 lbl_805D9E04;
extern const f32 lbl_805D9E08;
extern const f32 lbl_805D9E0C;
f32 calc_death_slide_speed__14TObjEneBm5WolfFPvf(TObjEneBm5Wolf *wolf, f32 speed);
s32 select_death_direction__14TObjEneBm5WolfFPvPv(TObjEneBm5Wolf *wolf, s32 *heading);
}






extern "C" {
s32 enemy_validate_retained_target(void *);
extern const f32 TObjEneBm5Wolf__data_805D9DEC;
extern const f32 lbl_805D9E38;
void enemy_clear_target__12TObjEneDD_STFUs(void *);
}
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
extern const f32 TObjEneBm5Wolf__data_805D9D8C;
extern const f32 TObjEneBm5Wolf__data_805D9DA4;
extern const f32 TObjEneBm5Wolf__data_805D9DA8;
extern const f32 TObjEneBm5Wolf__data_805D9DB0;
extern const f32 lbl_805D9DC4;
extern const f32 TObjEneBm5Wolf__data_805D9DC8;
extern const f32 TObjEneBm5Wolf__data_805D9DE0;
extern const f32 TObjEneBm5Wolf__data_805D9DF4;
extern const f32 lbl_805D9E10;
extern const f32 TObjEneBm5Wolf__data_805D9D84;
extern const f32 TObjEneBm5Wolf__data_805D9DBC;
extern const f32 lbl_805D9E14;
extern const f32 lbl_805D9E18;
extern const f32 lbl_805D9E1C;
extern const f32 lbl_805D9E20;
extern const f32 lbl_805D9E24;
extern const f32 lbl_805D9E28;
extern const f32 lbl_805D9E2C;
extern const f32 lbl_805D9E30;
extern "C" {
void queue_destruction__7TObjectFv(void *self);
s32 TBoss8Dragon__sub_800BB7D4(void *, int);
extern const f32 lbl_805D9DA0;
extern const f32 lbl_805D9E34;
s32 is_main_phase_15__9TObjEneDDFv();
void draw_blob_shadow(s32 arg0);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 TObjEneBm5Wolf__spawn_timer;
s32 TObjEneBm5Wolf__data_805D5128;
extern const f32 lbl_805D9D70;
extern const f32 TObjEneBm5Wolf__data_805D9D74;
extern const f32 TObjEneBm5Wolf__data_805D9D7C;
extern const f32 lbl_805D9D88;
extern const f32 lbl_805D9D90;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void render__14TObjEneBm5WolfFv(u8 *arg0);
extern const f32 lbl_805D9DB8;
extern const f32 lbl_805D9DC0;
s32 vec3_add_to(void *, void *);
extern const f32 lbl_805D9D94;
extern const f32 lbl_805D9D98;
extern const f32 lbl_805D9D9C;
s32 TObjEneDD__sub_800BA378(void *, void *);
extern const f32 lbl_805D9DD8;
extern const f32 lbl_805D9DDC;
extern const f32 lbl_805D9DE4;
extern const f32 TObjEneBm5Wolf__data_805D9DE8;
extern const f32 TObjEneBm5Wolf__data_805D9DF0;

s32 get_target_info__9TObjEneDDFv();

void TObjEneBm3FlyNest::render_shadows() {  }

s32 pack_debug_text_position(s32 arg0, s32 arg1);
s32 debug_draw_line(void *, void *, int, int);
extern char lbl_8043B584[];
extern char lbl_8043B590[];
extern char lbl_8043B59C[];

#pragma push
#pragma opt_common_subs off
void render_debug__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) {
    f32 frame;
    s32 idx;
    u32 n;
    AnimationMotion *motion;
    TObjEneBm5Wolf *leader;

    if (get_target_info__9TObjEneDDFv() != 0) {
        debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B584, wolf->m_3dc);
        if (wolf->m_3d8 != 0) {
            debug_printf_at(pack_debug_text_position(0, 1), lbl_8043B590);
        } else {
            debug_printf_at(pack_debug_text_position(0, 1), lbl_8043B59C);
        }
    }
    if (wolf->update_object_view_visibility(lbl_805D9D70, TObjEneBm5Wolf__data_805D9D74) != 0) {
        wolf->draw_ground_shadow(0, 0);
        TObjFish::set_global_param(wolf->texlist);
        push_matrix();
        post_translate_matrix(&wolf->position);
        rotate_matrix_y(0, wolf->rotation_y);
        idx = (s32) wolf->parameters[3];
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x13) {
            idx = 0x12;
        }
        motion = wolf->motion_list[wolf->action_table[idx].motion].motion;
        frame = wolf->parameters[4];
        if (frame < TObjEneBm5Wolf__data_805D9D78) {
            frame = TObjEneBm5Wolf__data_805D9D78;
        } else {
            n = motion->frameCount;
            if (frame > (n - 1)) {
                frame = (f32) n;
            }
        }
        translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D7C);
        TObjPlayer::toggle_particle_effect();
        set_motion_packed_rotation();
        draw_model_motion(wolf->model, motion, frame);
        clear_motion_packed_rotation();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    leader = find_pack_leader__14TObjEneBm5WolfFi(wolf->m_3dc);
    if (leader != 0) {
        debug_draw_line(&wolf->m_2fc, &leader->m_2fc, 0xFFC0C0C0, 0xFF6060FF);
        return;
    }
    {
    Vec v;
    VecCopy(&v, (const Vec *)&wolf->m_2fc);
    v.y += TObjEneBm5Wolf__data_805D9D80;
    debug_draw_line(&wolf->m_2fc, &v, 0xFFC0C0C0, 0xFF6060FF);
    }
}
#pragma pop

__declspec(section ".rodata") extern const f64 TObjEneBm5Wolf__data_8043B5B0 = 10430.38043493439;

void update_state__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) {
    s32 old_subtype;

    if (wolf->get_target_info() != 0) {
        old_subtype = wolf->m_3d8;
        wolf->select_subtype();
        if (old_subtype != wolf->m_3d8) {
            if (old_subtype != 0) {
                wolf->update_default();
            } else {
                wolf->apply_global_to_position();
            }
        }
        wolf->update_collision_center();
    }
}

void TObjEneBm5Wolf::render() {
    s32 rot[3];
    s32 var_r31;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_debug();
        return;
    }
    if (!(this->m_408 & 2) && ((s16) this->mode != 0x11)) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            var_r31 = this->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, TObjEneBm5Wolf__data_805D9D74);
        } else if (this->update_object_view_visibility(lbl_805D9D70, TObjEneBm5Wolf__data_805D9D74) != 0) {
            var_r31 = 1;
        } else {
            var_r31 = 0;
        }
        if (var_r31 != 0) {
            if ((s16) this->mode != 0x10) {
                direction_to_rotation_xz((u8 *)&this->ground_normal, &rot[0], &rot[2]);
                push_matrix();
                post_translate_matrix(&this->position);
                translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D84, TObjEneBm5Wolf__data_805D9D78);
                rotate_matrix_z(0, rot[2]);
                rotate_matrix_x(0, rot[0]);
                rotate_matrix_y(0, this->rotation_y);
                translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D7C);
                scale_matrix(0, lbl_805D9D88, TObjEneBm5Wolf__data_805D9D8C, lbl_805D9D90);
                rotate_matrix_x(0, -0x4000);
                draw_blob_shadow(0);
                pop_matrix();
            }
            this->update_secondary_light();
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            post_translate_matrix(&this->position);
            rotate_matrix_y(0, this->rotation_y);
            translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D7C);
            if (this->m_408 & 4) {
                translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, this->m_40c, TObjEneBm5Wolf__data_805D9D78);
            }
            TObjEneBm5Wolf__spawn_timer = 0;
            TObjEneBm5Wolf__data_805D5128 = -(this->turnOffset / 2);
            set_chunk_model_node_callback((s32)((void *)TObjEneBm5Wolf::advance_spawn_timer));
            TObjEneDD::clear_global_flag_400();
            TObjPlayer::toggle_particle_effect();
            if (var_r31 == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            set_chunk_model_node_callback((s32)NULL);
            pop_matrix();
            this->update_primary_light();
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneBm5Wolf::advance_spawn_timer() {
    if (((s32) TObjEneBm5Wolf__spawn_timer >= 0x16) && ((s32) TObjEneBm5Wolf__spawn_timer < 0x18)) {
        rotate_matrix_y(0, TObjEneBm5Wolf__data_805D5128);
    }
    TObjEneBm5Wolf__spawn_timer += 1;
}

void TObjEneBm5Wolf::despawn_state(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction__7TObjectFv(this);
        break;
    }
}

void TObjEneBm5Wolf::update_dying_state(s32 arg1) {
    s32 *tgt;
    TObjEneBm5WolfListNode *n;
    TObjEneBm5Wolf *e;
    f32 k;
    Vec pos;
    Vec vel;
    f32 c;
    tgt = &this->m_42c;
    switch (arg1) {
    case 4:
        this->vfunc_96();
        this->refresh_and_send_entity_flags();
        play_sound_effect(this->remap_sound_for_area(0x3AD1D), &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        if (select_death_direction__14TObjEneBm5WolfFPvPv(this, tgt) == 0) {
            this->requested_action = 0xF;
        } else {
            this->requested_action = 0xE;
        }
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        this->roamingSubstate = 0;
        this->stoppingDistance = calc_death_slide_speed__14TObjEneBm5WolfFPvf(this, this->action_table[9].speed);
        this->m_37c = this->m_43c = TObjEneBm5Wolf__data_805D9D78;
        if (this->m_3d8 != 0) {
            k = TObjEneBm5Wolf__data_805D9D80;
            for (n = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__pack_member_list)->head; n != NULL; n = n->next) {
                e = play_sound__14TObjEneBm5WolfFPv(n);
                if (e != NULL && e->m_3dc == this->m_3dc) {
                    schedule_pack_reaction__14TObjEneBm5WolfFPvis(e, (s32)(k * this->random_ratio()) + 0x14, this->m_2d4);
                }
            }
        }
        this->set_active();
        break;
    case 3:
        if (this->roamingSubstate == 2) {
            this->transition_enemy_state(0x11);
        }
        break;
    case 1:
        break;
    case 0:
        switch (this->roamingSubstate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->roamingSubstate = 1;
                pos.y = TObjEneBm5Wolf__data_805D9D78;
                if (this->requested_action == 0xE) {
                    pos.x = lbl_805D9D94;
                    pos.z = TObjEneBm5Wolf__data_805D9D7C;
                } else {
                    pos.x = lbl_805D9D98;
                    pos.z = TObjEneBm5Wolf__data_805D9D7C;
                }
                rotate_xz_pair_by_angle(&pos.x, &pos.z, this->rotation_y);
                vec3_add_to(&pos, &this->position);
                TObjPlayer::spawn_dead_spot_type2((s32)&pos, 0x32);
                ((TObjPlayer *)(&pos))->spawn_effect_at_ground(0x46);
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, *tgt, 0x300);
            this->rotation_y = (s16)this->rotation_y;
            if (this->m_37c < lbl_805D9D9C) {
                this->m_37c = this->m_37c + this->stoppingDistance;
            }
            VecCopy(&vel, (const Vec *)&this->x_speed);
            c = normalize_vector_xz(&vel);
            this->move_clamped_on_ground(vel.x, vel.z, c);
            if (this->is_passing_frame(lbl_805D9DA0) != 0) {
                spawn_recoil_dust__14TObjEneBm5WolfFiPv(this, &vel);
            }
            this->x_speed = this->x_speed * TObjEneBm5Wolf__data_805D9DA4;
            this->m_310 = this->m_310 * TObjEneBm5Wolf__data_805D9DA4;
            advance_pose_turn__14TObjEneBm5WolfFPvi(this, this->rotation_y);
            this->vfunc_88();
            break;
        case 1:
            this->position.y = this->position.y - TObjEneBm5Wolf__data_805D9DA8;
            this->m_43c = this->m_43c + TObjEneBm5Wolf__data_805D9DA8;
            if (this->m_43c > TObjEneBm5Wolf__data_805D9D74) {
                this->roamingSubstate = 2;
            }
            break;
        }
        break;
    case 5:
        this->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::hurt_state(s32 arg1) {
    switch (arg1) {
    case 4:
        this->vfunc_96();
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        this->roamingTimer = 0;
        this->m_42c = 0;
        this->requested_action = 6;
        this->roamingSubstate = 0;
        if (this->referenceHp - this->hp < 0x14) {
            play_sound_effect(this->remap_sound_for_area(0x3AB1B), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x500);
        }
        this->set_active();
        break;
    case 3:
        if ((this->motion_flags) & 0x10) {
            switch (this->m_378) {
            case 11:
                this->transition_enemy_state(0xD);
                break;
            case 2:
                this->transition_enemy_state(7);
                break;
            default:
                this->transition_enemy_state(this->m_378);
                break;
            }
        }
        break;
    case 0: {
        Vec v;
        this->advance_animation();
        VecCopy(&v, (const Vec *)&this->x_speed);
        {
        f32 c = normalize_vector_xz(&v);
        this->move_with_wall_slide_on_ground(v.x, v.z, c);
        }
        if (this->roamingSubstate == 0) {
            this->x_speed *= TObjEneBm5Wolf__data_805D9DAC;
            this->m_310 *= TObjEneBm5Wolf__data_805D9DAC;
        } else {
            this->x_speed *= TObjEneBm5Wolf__data_805D9DB0;
            this->m_310 *= TObjEneBm5Wolf__data_805D9DB0;
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0x300);
            this->rotation_y = (s16) this->rotation_y;
            if (this->is_passing_frame(lbl_805D9DA0) != 0) {
                spawn_recoil_dust__14TObjEneBm5WolfFiPv(this, &v);
            }
        }
        this->vfunc_89();
        break;
    }
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::action(s32 arg1) {
    switch (arg1) {
    case 4:
        this->vfunc_96();
        this->set_field_378(7);
        this->requested_action = 0xB;
        this->roamingSubstate = 0;
        find_pack_leader__14TObjEneBm5WolfFi(this->m_3dc);
        return;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(7);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        advance_pose_turn__14TObjEneBm5WolfFPvi(this, this->rotation_y);
        if (this->is_passing_frame(TObjEneBm5Wolf__data_805D9DB4) != 0) {
            play_sound_effect(this->remap_sound_for_area(0x3AA1A), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x100);
        }
        this->roamingSubstate = (this->roamingSubstate + 1);
        if (this->roamingSubstate == 0x1E) {
            apply_mourning_zalure();
        } else if (this->roamingSubstate == 0x28) {
            apply_mourning_jellen();
        }
        this->vfunc_89();
        break;
    }
}

void TObjEneBm5Wolf::repositioning_state(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xD);
        this->vfunc_96();
        this->roamingSubstate = 0;
        this->m_42c = 0;
        this->roamingTimer = 0;
        return;
    case 3:
        if (this->roamingSubstate == 2) {
            if (this->target != 0U) {
                this->transition_enemy_state(0xA);
            } else {
                this->transition_enemy_state(7);
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->roamingSubstate) {
        case 0: {
            f32 dx;
            f32 dz;
            this->m_42c = ((this->roamingTimer >> 1) << 0xC) + 0x1800;
            if (this->roamingTimer & 1) {
                this->m_42c = -this->m_42c;
            }
            if (get_flag_bit0__14TObjEneBm5WolfFPv(this) == 0) {
                this->m_42c = -this->m_42c;
            }
            this->m_42c += this->rotation_y;
            (this->roamingTimer)++;
            if (this->roamingTimer > 8) {
                this->roamingSubstate = 2;
            }
            dx = lbl_805D9DB8 * sin_table_lookup(this->m_42c);
            dz = lbl_805D9DB8 * cos_table_lookup(this->m_42c);
            this->m_410->position.x = this->position.x + dx;
            this->m_410->position.y = this->position.y;
            this->m_410->position.z = this->position.z + dz;
            ((TObjPlayer *)(this->m_410))->update_collisions();
            if (!(this->m_410->bodies->flags & 0x380000)) {
                dx *= TObjEneBm5Wolf__data_805D9DBC;
                dz *= TObjEneBm5Wolf__data_805D9DBC;
                if (((TBoss5Gryphon *)this)->enemy_probe_wall_ahead(dx, dz, TObjEneBm5Wolf__data_805D9D8C) == 0U) {
                    Vec v;
                    VecCopy(&v, (const Vec *)&this->m_2fc);
                    v.x += dx;
                    v.z += dz;
                    if (csnVectorUnder(&v, (u32 *)&this->m_120, 0x15) != NULL) {
                        this->roamingSubstate = 1;
                        this->requested_action = 0x12;
                        this->destinationDirection.x = sin_table_lookup(this->m_42c);
                        this->destinationDirection.y = TObjEneBm5Wolf__data_805D9D78;
                        this->destinationDirection.z = cos_table_lookup(this->m_42c);
                    }
                }
            }
            break;
        }
        case 1:
            if (this->get_flag_b4() != 0) {
                select_target__14TObjEneBm5WolfFPv(this);
                this->roamingSubstate = 2;
            }
            play_proximity_effect();
            this->move_with_wall_slide_on_ground(this->destinationDirection.x, this->destinationDirection.z, lbl_805D9DC0);
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0xF00);
            advance_pose_turn__14TObjEneBm5WolfFPvi(this, this->m_42c);
            this->vfunc_89();
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void returning_state__14TObjEneBm5WolfFPvi(TObjEneBm5Wolf *actor, s32 arg1) {
    Vec *home = &actor->m_450;
    f32 lim = actor->stoppingDistance;
    switch (arg1) {
    case 4:
        actor->requested_action = 1;
        actor->set_field_378(0xC);
        actor->vfunc_96();
        actor->desiredSpeed = lbl_805D9DC4;
        actor->roamingSubstate = 0;
        VecCopy(home, &actor->position);
        TObjBoss2Tunnel::calc_scaled_value(0x200, lbl_805D9DC4);
        actor->m_430 = actor->rotation_y;
        if (actor->enemy_has_live_target() != 0) {
            Vec a;
            Vec d;
            TObjChara *t;
            a.x = sin_table_lookup(actor->rotation_y);
            a.z = cos_table_lookup(actor->rotation_y);
            t = actor->target;
            d.x = t->position.x - actor->position.x;
            d.z = t->position.z - actor->position.z;
            if (is_vec_xz_cross_negative(&a, &d) != 0) {
                actor->m_42c = 0x5000;
            } else {
                actor->m_42c = -0x5000;
            }
        } else if (actor->random_ratio() < TObjEneBm5Wolf__data_805D9DAC) {
            actor->m_42c = 0x5000;
        } else {
            actor->m_42c = -0x5000;
        }
        actor->m_42c = actor->m_42c + actor->m_430;
        break;
    case 3:
        if (actor->target == NULL || actor->roamingSubstate > 0x96) {
            actor->transition_enemy_state(7);
        } else if (actor->destinationDistance < lim) {
            actor->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        actor->roamingSubstate++;
        actor->advance_animation();
        if (((TObjEneEpsilon *)actor)->update_death_check() != 0) {
            play_footsteps__14TObjEneBm5WolfFPv(actor);
            actor->m_42c = approach_angle_limited(actor->m_42c, actor->m_430, 0x100);
            actor->destination.x = TObjEneBm5Wolf__data_805D9DC8 * sin_table_lookup(actor->m_42c) + home->x;
            actor->destination.z = TObjEneBm5Wolf__data_805D9DC8 * cos_table_lookup(actor->m_42c) + home->z;
            actor->update_velocity();
            approach_target__14TObjEneBm5WolfFPvf(actor, lbl_805D9DCC);
            actor->play_speed = TObjEneBm5Wolf__data_805D9DD0 * actor->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)actor, 0x500, actor->currentSpeed);
            actor->turn_pose_to_target();
            actor->vfunc_89();
        }
        break;
    }
}
#pragma pop

__declspec(section ".sdata2") extern const f32 lbl_805D9D70 = 400.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D74 = 20.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D78 = 0.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D7C = -10.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D80 = 50.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D84 = 0.30000001192092896f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D88 = 1.2000000476837158f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D8C = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D90 = 3.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D94 = 12.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D98 = -12.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D9C = 28.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DA0 = 22.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DA4 = 0.800000011920929f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DA8 = 0.10000000149011612f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DAC = 0.5f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DB0 = 0.8999999761581421f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DB4 = 10.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DB8 = 16.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DBC = 2.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DC0 = 1.7999999523162842f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DC4 = 1.600000023841858f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DC8 = 90.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DCC = 0.20000000298023224f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DD0 = 1.100000023841858f;
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::update_lunge(s32 arg1) {
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_r4;
    switch (arg1) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(0xD);
        this->vfunc_96();
        this->m_408 = (s32) (this->m_408 & 0xFFFFFFFD);
        temp_r4 = this->m_408 | 4;
        this->m_408 = temp_r4;
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        this->m_42c = calc_lunge_aim__14TObjEneBm5WolfFPv(this);
        this->m_430 = 0;
        if (this->destinationDistance > 40.0f) {
            this->destinationDistance = 40.0f;
        }
        temp_f3 = this->destinationDistance / lbl_805D9DD8;
        this->desiredSpeed = temp_f3;
        this->currentSpeed = temp_f3;
        this->nearTarget = 0;
        this->m_40c = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        this->stoppingDistance = (f32) this->position.y;
        this->m_43c = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D74);
        this->m_438 = (f32) lbl_805D9DDC;
        return;
    case 3:
        if (this->roamingSubstate == 2) {
            this->transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (this->roamingSubstate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                if (this->nearTarget != 0) {
                    this->roamingSubstate = 2;
                } else {
                    this->roamingSubstate = 1;
                    this->roamingTimer = 0;
                }
            }
            if (this->is_passing_frame(TObjEneBm5Wolf__data_805D9DE0) != 0) {
                spawn_particle_effect(&this->position, 0xF3);
            }
            if (this->is_passing_frame(lbl_805D9DE4) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3E420), &this->position, 0, 0);
            }
            if (this->is_passing_frame(TObjEneBm5Wolf__data_805D9DE8) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x4003A821), &this->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x500);
            }
            if (this->is_passing_frame((f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9D74))) != 0) {
                this->nearTarget = 0;
                if (enemy_validate_retained_target(this) != 0) {
                    if (this->target->select_melee_contact_body(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0) {
                        this->target->receive_physical_attack(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                        this->target->apply_knockback_from_attacker((u8 *)this, TObjEneBm5Wolf__data_805D9DEC);
                        this->nearTarget = 1;
                        if ((TObjEneDD::check_v2_mode() != 0) && (this->random_ratio() <= (*(f32 *)&TObjEneBm5Wolf__data_805D9DA8))) {
                            if (this->m_3d8 != 0) {
                                TObjEneDD__sub_800BA378(this, this->target);
                            } else {
                                TObjEneDD::send_damage_message((s32)this, (u8 *)this->target);
                            }
                        }
                    }
                }
            }
            approach_target__14TObjEneBm5WolfFPvf(this, (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DA8)));
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0x1000);
            this->rotation_y = (s32) (s16) this->rotation_y;
            advance_pose_turn__14TObjEneBm5WolfFPvi(this, this->rotation_y);
            if (this->frame <= TObjEneBm5Wolf__data_805D9DF0) {
                this->move_with_wall_slide_on_ground((f32) (this->destinationDirection.x), (f32) (this->destinationDirection.z), this->currentSpeed);
                temp_f2 = this->frame - TObjEneBm5Wolf__data_805D9DF4;
                this->m_40c = (f32) ((this->stoppingDistance + ((this->m_438 * (temp_f2 * temp_f2)) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D74))) - this->position.y);
            } else {
                if (this->nearTarget == 0) {
                    this->currentSpeed = (f32) (this->currentSpeed * (*(f32 *)&TObjEneBm5Wolf__data_805D9DA4));
                    this->move_with_wall_slide_on_ground((f32) (this->destinationDirection.x), (f32) (this->destinationDirection.z), this->currentSpeed);
                }
                this->m_40c = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
            }
            break;
        case 1:
            this->advance_animation();
            this->roamingTimer = (this->roamingTimer + 1);
            if (this->roamingTimer >= 0xA) {
                this->roamingSubstate = 2;
            }
            advance_pose_turn__14TObjEneBm5WolfFPvi(this, this->rotation_y);
            if (this->nearTarget == 0) {
                this->currentSpeed = (f32) (this->currentSpeed * (*(f32 *)&TObjEneBm5Wolf__data_805D9DA4));
                this->move_with_wall_slide_on_ground((f32) (this->destinationDirection.x), (f32) (this->destinationDirection.z), this->currentSpeed);
            }
            break;
        }
        this->vfunc_89();
        return;
    case 5:
        this->m_40c = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::circling_state(s32 arg1) {
    Vec *b;
    Vec *a;
    f32 vx;
    f32 vz;
    a = &this->m_444;
    b = &this->m_450;
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(10);
        this->vfunc_96();
        this->desiredSpeed = lbl_805D9DF8;
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        this->randomPhase = 0;
        this->m_428 = 0;
        this->m_42c = 0;
        this->stoppingDistance = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        this->m_438 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        a->x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        a->y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        a->z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        b->x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        b->y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        b->z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        this->set_active();
        break;
    case 3:
        if (this->target == NULL) {
            this->transition_enemy_state(7);
            break;
        }
        if (this->roamingSubstate > 450) {
            this->roamingSubstate = 0;
            if (this->random_ratio() < (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC)) {
                this->transition_enemy_state(11);
            }
        } else if (this->roamingSubstate > 45) {
            f32 dz = this->position.z - this->target->position.z;
            f32 dx = this->position.x - this->target->position.x;
            f32 d = dx * dx + dz * dz;
            if (d >= lbl_805D9DFC) {
                ((void (*)(void *))set_state_by_timer__14TObjEneBm5WolfFi)(this);
            } else if (d < lbl_805D9E00) {
                this->transition_enemy_state(11);
            } else {
                f32 c;
                vx = sin_table_lookup(this->target->rotation_y);
                c = cos_table_lookup(this->target->rotation_y);
                vz = vx * b->x + c * b->z;
                if (vz < cos_table_lookup(0x6AAA)) {
                    this->transition_enemy_state(11);
                }
            }
        }
        break;
    case 0:
        this->advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            if (this->randomPhase == 0) {
                Vec fwd;
                Vec to;
                this->randomPhase = 1;
                VecCopy(a, &this->target->position);
                this->stoppingDistance = calc_circle_offset__14TObjEneBm5WolfFPvPvPv(this, a, b);
                this->m_438 = this->rand_range((*(f32 *)&TObjEneBm5Wolf__data_805D9D80), lbl_805D9E04);
                fwd.x = sin_table_lookup(this->rotation_y);
                fwd.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
                fwd.z = cos_table_lookup(this->rotation_y);
                to.x = this->target->position.x - this->position.x;
                to.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
                to.z = this->target->position.z - this->position.z;
                if (is_vec_xz_cross_negative(&fwd, &to) != 0) {
                    this->m_42c = -1;
                } else {
                    this->m_42c = 1;
                }
            }
            this->roamingSubstate++;
            play_footsteps__14TObjEneBm5WolfFPv(this);
            if (this->m_428 > 0) {
                this->m_428--;
                if (this->m_42c > 0) {
                    this->stoppingDistance -= (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC);
                } else {
                    this->stoppingDistance += (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC);
                }
            } else {
                f32 cur = this->stoppingDistance;
                f32 tgt = this->m_438;
                f32 diff = cur - tgt;
                if (diff > (*(f32 *)&lbl_805D9DCC)) {
                    this->stoppingDistance = cur - (*(f32 *)&lbl_805D9DCC);
                } else if (diff < lbl_805D9E08) {
                    this->stoppingDistance = cur + (*(f32 *)&lbl_805D9DCC);
                } else {
                    this->stoppingDistance = tgt;
                }
            }
            switch (this->randomPhase) {
            case 1: {
                this->desiredSpeed = lbl_805D9DF8;
                approach_target__14TObjEneBm5WolfFPvf(this, lbl_805D9E0C);
                calc_circle_offset__14TObjEneBm5WolfFPvPvPv(this, a, b);
                if (this->m_42c >= 0) {
                    vx = b->z;
                    vz = -b->x;
                } else {
                    vz = b->x;
                    vx = -b->z;
                }
                if (this->has_move_failures(1) != 0) {
                    this->set_active();
                } else {
                    this->clear_field_388();
                }
                this->move_with_wall_slide_on_ground(vx, vz, this->currentSpeed);
                if (this->has_move_failures(10) != 0) {
                    this->roamingTimer = 0;
                    this->randomPhase = 2;
                }
                break;
            }
            case 2: {
                s32 ang;
                f32 sx;
                f32 cz;
                this->desiredSpeed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC);
                approach_target__14TObjEneBm5WolfFPvf(this, lbl_805D9E0C);
                this->roamingTimer++;
                if (this->roamingTimer >= 40) {
                    ang = this->rotation_y;
                } else {
                    ang = this->rotation_y + (this->m_42c << 11);
                }
                sx = sin_table_lookup(ang);
                cz = cos_table_lookup(ang);
                if (this->has_move_failures(2) != 0) {
                    this->roamingTimer = 0;
                    this->set_active();
                } else {
                    this->clear_field_388();
                }
                this->move_with_wall_slide_on_ground(sx, cz, this->currentSpeed);
                if (this->roamingTimer >= 80) {
                    this->randomPhase = 0;
                }
                break;
            }
            }
            this->rotation_y = approach_angle_limited(this->rotation_y,
                (s32)((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float(this->position.x - this->prev_position.x, this->position.z - this->prev_position.z)),
                0x200);
            this->rotation_y = (s16)this->rotation_y;
            this->play_speed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DD0) * this->currentSpeed;
            this->turn_pose_to_target();
            this->vfunc_89();
            if (this->bodies->flags & 0x380000) {
                this->m_428 = 20;
            }
        }
        break;
    case 5:
        this->clear_field_388();
        break;
    }
}
#pragma pop

void TObjEneBm5Wolf::flanking_state(s32 arg1) {
    s32 *ang = &this->m_42c;
    Vec *dst = &this->m_444;
    Vec *src = &this->m_450;
    switch (arg1) {
    case 4:
        this->requested_action = 3;
        set_field_378(9);
        this->vfunc_96();
        this->desiredSpeed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DBC);
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, 0x1C71, src, ang);
        VecCopy(dst, src);
        this->m_430 = *ang;
        break;
    case 3:
        if (this->target == 0U) {
            this->transition_enemy_state(7);
        } else if (is_passing_frame(this->frame_count - (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0 && this->destinationDistance < (*(f32 *)&TObjEneBm5Wolf__data_805D9DC8)) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)((u8 *)this))->update_death_check() != 0) {
            if (is_passing_frame(TObjEneBm5Wolf__data_805D9DE0) != 0) {
                spawn_particle_effect(&this->position, 0xF3);
            }
            this->play_proximity_effect();
            if (is_passing_frame(TObjEneBm5Wolf__data_805D9DF4) != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                if (this->roamingTimer == 0) {
                    this->roamingTimer = 1;
                    calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, -0x1C71, src, ang);
                } else {
                    this->roamingTimer = 0;
                    calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, 0x1C71, src, ang);
                }
            }
            if (is_passing_frame(this->frame_count - (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0) {
                VecCopy(dst, src);
                this->m_430 = *ang;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_430, 0x800);
            this->rotation_y = (s16)this->rotation_y;
            if (this->frame >= TObjEneBm5Wolf__data_805D9DF4) {
                this->currentSpeed *= (*(f32 *)&TObjEneBm5Wolf__data_805D9DB0);
                this->play_speed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC) * this->currentSpeed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->currentSpeed);
            } else {
                approach_target__14TObjEneBm5WolfFPvf(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                this->play_speed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC) * this->currentSpeed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->currentSpeed);
            }
            this->turn_pose_to_target();
            this->vfunc_89();
        }
        break;
    }
}

void TObjEneBm5Wolf::chasing_state(s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    switch (arg1) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(8);
        this->vfunc_96();
        this->desiredSpeed = (f32) (*(f32 *)&lbl_805D9DC4);
        this->roamingSubstate = 0;
        break;
    case 3:
        if ((u32) this->target == 0U) {
            this->transition_enemy_state(7);
            break;
        }
        if (this->has_move_failures(0xA) != 0) {
            this->transition_enemy_state(9);
            break;
        }
        if ((this->roamingSubstate == 0) && (this->is_passing_frame(this->frame_count - (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0) && (this->destinationDistance < (*(f32 *)&TObjEneBm5Wolf__data_805D9DC8))) {
            this->transition_enemy_state(0xA);
            break;
        }
    case 5:
    case 1:
        break;
    case 0:
        this->advance_animation();
        if (this->is_passing_frame(TObjEneBm5Wolf__data_805D9DE0) != 0) {
            spawn_particle_effect(&this->position, 0xF3);
        }
        if ((s16) this->requested_action == 2) {
            play_proximity_effect();
        }
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            if (this->frame >= TObjEneBm5Wolf__data_805D9DF4) {
                this->currentSpeed = (f32) (this->currentSpeed * (*(f32 *)&TObjEneBm5Wolf__data_805D9DB0));
                this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DA4) * this->currentSpeed);
                temp_f1 = this->currentSpeed;
                enemy_turn_and_move_on_ground((u8 *)this, (lbl_805D9E10 * temp_f1), temp_f1);
            } else {
                approach_target__14TObjEneBm5WolfFPvf(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9DA8));
                this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DA4) * this->currentSpeed);
                temp_f1_2 = this->currentSpeed;
                enemy_turn_and_move_on_ground((u8 *)this, (lbl_805D9E10 * temp_f1_2), temp_f1_2);
            }
            turn_pose_to_target();
            this->vfunc_89();
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::roaming_state(int event) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f31;
    f32 temp_f3;
    f32 square;
    s32 temp_r30;
    TObjChara *temp_r3;
    switch (event) {
    case 4:
        this->requested_action = 1;
        set_field_378(7);
        this->vfunc_96();
        this->roamingTimer = 0;
        this->roamingSubstate = 0;
        this->randomPhase = actor_rand_int((s32)this, 0x14);
        this->nearTarget = 0;
        temp_r30 = (s32) (lbl_805D9E14 * this->random_ratio());
        temp_f31 = lbl_805D9E18 * this->random_ratio();
        this->destination.x = (f32) ((temp_f31 * sin_table_lookup(temp_r30)) + this->groupAnchor.x);
        this->destination.z = (f32) ((temp_f31 * cos_table_lookup(temp_r30)) + this->groupAnchor.z);
        this->desiredSpeed = (f32) ((lbl_805D9DF8 * this->random_ratio()) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D84));
        this->currentSpeed = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        this->stoppingDistance = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
        this->update_velocity();
        return;
    case 3:
        if (this->nearTarget != 0) {
            set_state_by_timer__14TObjEneBm5WolfFi(this);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (play_variant_sound__14TObjEneBm5WolfFPv(this) != 0) {
            temp_r3 = this->target;
            temp_f3 = temp_r3->position.x - this->position.x;
            temp_f1 = temp_r3->position.z - this->position.z;
            square = temp_f3 * temp_f3;
            square = (temp_f1 * temp_f1) + square;
            if (square < lbl_805D9E1C) {
                this->nearTarget = 1;
            }
            turn_pose_to_target();
        } else {
            advance_pose_turn__14TObjEneBm5WolfFPvi(this, this->rotation_y);
        }
        switch (this->roamingSubstate) {
        case 0:
            play_footsteps__14TObjEneBm5WolfFPv(this);
            this->update_velocity();
            approach_target__14TObjEneBm5WolfFPvf(this, lbl_805D9E20);
            this->roamingTimer = (this->roamingTimer + 1);
            if ((this->destinationDistance < this->stoppingDistance) || (this->roamingTimer > 0x64)) {
                this->roamingSubstate = 1;
                this->desiredSpeed = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
            } else if (((s32)has_move_failures(0x14)) != 0) {
                this->roamingTimer = 0;
                choose_roaming_destination();
                this->desiredSpeed = this->rand_range((*(f32 *)&TObjEneBm5Wolf__data_805D9D84), (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                this->stoppingDistance = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
            }
            this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DD0) * this->currentSpeed);
            temp_f1_2 = this->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)this, (s32)(lbl_805D9E24 * temp_f1_2), (f32)temp_f1_2);
            break;
        case 1:
            play_footsteps__14TObjEneBm5WolfFPv(this);
            this->update_velocity();
            approach_target__14TObjEneBm5WolfFPvf(this, lbl_805D9E28);
            if (this->currentSpeed <= (*(f32 *)&TObjEneBm5Wolf__data_805D9DA8)) {
                this->roamingSubstate = 2;
                this->roamingTimer = (s32) this->rand_range(lbl_805D9E2C, lbl_805D9E30);
                this->requested_action = 0;
            }
            this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DD0) * this->currentSpeed);
            temp_f1_3 = this->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)this, (s32)(lbl_805D9E24 * temp_f1_3), (f32)temp_f1_3);
            break;
        case 2:
            this->requested_action = 0;
            this->roamingTimer = (this->roamingTimer - 1);
            if (this->roamingTimer <= 0) {
                choose_roaming_destination();
                this->desiredSpeed = this->rand_range((*(f32 *)&TObjEneBm5Wolf__data_805D9D84), (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                this->currentSpeed = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
                this->stoppingDistance = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
                this->roamingSubstate = 0;
                this->requested_action = 1;
            }
            this->vfunc_102();
            break;
        }
        this->vfunc_89();
        break;
    }
}
#pragma pop

void TObjEneBm5Wolf::empty_state() {  }

void TObjEneBm5Wolf::howling_state(s32 arg1) {
    TObjEneBm5WolfListNode *p;
    TObjEneBm5Wolf *r;
    switch (arg1) {
    case 4:
        this->requested_action = 0x10;
        set_field_378(7);
        this->vfunc_95();
        this->roamingSubstate = 0;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(7);
        }
        break;
    case 5:
        break;
    case 0:
        (this->roamingSubstate)++;
        advance_animation();
        if (this->requested_action == 0x10) {
            is_passing_frame(TObjEneBm5Wolf__data_805D9DEC);
        } else if (this->requested_action == 0xB && is_passing_frame(lbl_805D9E34) != 0) {
            play_sound_effect(this->remap_sound_for_area(0x3A819), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (this->roamingSubstate == 0x3C) {
            for (p = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->head; p != NULL; p = p->next) {
                r = play_sound__14TObjEneBm5WolfFPv(p);
                if (this->m_3dc == get_group_id__14TObjEneBm5WolfFPv(r)) {
                    r->set_attack_flag();
                }
            }
        }
        if (enemy_validate_retained_target(this) != 0) {
            if (this->requested_action == 0x10) {
                this->turn_pose_to_target();
            } else {
                this->turnOffset = 0;
            }
        } else {
            play_variant_sound__14TObjEneBm5WolfFPv(this);
        }
        this->vfunc_102();
        this->vfunc_88();
        break;
    }
}

void TObjEneBm5Wolf::standing_state(s32 arg1) {
  switch (arg1)
  {
    case 4:
      this->requested_action = 5;
      this->set_field_378(7);
      (this->vfunc_95());
      this->roamingSubstate = 0;
      return;
    case 3:
      if ((this->roamingSubstate) > 0x3C)
    {
      this->transition_enemy_state(7);
    }
    case 5:
      return;
    case 0:
      this->roamingSubstate = (s32) ((this->roamingSubstate) + 1);
      this->advance_animation();
      this->is_passing_frame(TObjEneBm5Wolf__data_805D9DEC);
      if (enemy_validate_retained_target(this) != 0)
    {
      this->enemy_copy_target_destination();
      this->update_velocity();
      turn_pose_to_target();
    }
    else
    {
      play_variant_sound__14TObjEneBm5WolfFPv(this);
    }
      (this->vfunc_102());
      (this->vfunc_88());
      break;
  }
  return;
}

void TObjEneBm5Wolf::alerted_state(s32 arg1) {
  s32 new_var;
  switch (arg1)
  {
    case 4:
      this->requested_action = 4;
      this->set_field_378(4);
      (this->vfunc_95());
      new_var = (s32) (((s32) (lbl_805D9E38 * this->random_ratio())) + 0xA);
      this->roamingSubstate = new_var;
      return;
    case 3:
      if ((this->roamingSubstate) <= 0)
    {
      set_anim_state();
    }
    case 5:
      return;
      return;
    case 0:
      this->roamingSubstate = (s32) ((this->roamingSubstate) - 1);
      play_variant_sound__14TObjEneBm5WolfFPv(this);
      this->advance_animation();
      (this->vfunc_102());
      (this->vfunc_88());
      break;
  }
}

void TObjEneBm5Wolf::sleeping_state(s32 arg1) {
  TObjEneBm5Wolf *entity;
  switch (arg1)
  {
    case 4:
      this->requested_action = 4;
      this->set_field_378(2);
      (this->vfunc_95());
      enemy_clear_target__12TObjEneDD_STFUs(this);
      this->turnOffset = 0;
      this->m_408 = (s32) ((this->m_408) & 0xFFFFFFFE);
      return;
    case 3:
      if ((this->m_408) & 1)
    {
      this->transition_enemy_state(4);
      return;
      return;
    }
      if (this->target != 0)
    {
      this->enemy_copy_target_destination();
      set_anim_state();
      entity = (TObjEneBm5Wolf *)find_entity_by_id(this->m_3e0);
      if (entity != 0)
      {
        entity->set_attack_flag();
      }
    }
      return;
    case 0:
      play_variant_sound__14TObjEneBm5WolfFPv(this);
      this->advance_animation();
      (this->vfunc_102());
      (this->vfunc_88());
      return;
    case 5:
      this->m_408 = (s32) ((this->m_408) & 0xFFFFFFFE);
      break;
  }
}

extern const f32 lbl_805D9E3C;
extern const f32 lbl_805D9E40;
#pragma push
#pragma fp_contract on
void appearing_state__14TObjEneBm5WolfFPvi(TObjEneBm5Wolf *o, s32 arg1) {
    Vec *home = &o->m_444;
    f32 t;

    switch (arg1) {
    case 4:
        o->requested_action = 0x11;
        o->set_field_378(7);
        o->vfunc_95();
        o->m_408 &= ~3;
        o->m_408 |= 4;
        enemy_clear_target__12TObjEneDD_STFUs(o);
        o->turnOffset = 0;
        VecCopy(home, &o->position);
        o->position.x -= lbl_805D9E3C * sin_table_lookup(o->rotation_y);
        o->position.z -= lbl_805D9E3C * cos_table_lookup(o->rotation_y);
        o->stoppingDistance = lbl_805D9E40;
        o->m_40c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        o->m_438 = o->position.y;
        break;
    case 3:
        if (o->get_flag_b4() != 0) {
            if (select_target__14TObjEneBm5WolfFPv(o) != 0) {
                o->transition_enemy_state(7);
            } else {
                o->transition_enemy_state(2);
            }
        }
        break;
    case 0:
        o->advance_animation();
        if (!(o->motion_flags & 4)) {
            if (o->is_passing_frame(TObjEneBm5Wolf__data_805D9DE0) != 0 ||
                o->is_passing_frame(TObjEneBm5Wolf__data_805D9DF0) != 0) {
                spawn_particle_effect(&o->position, 0xF3);
            }
            if (o->is_passing_frame(lbl_805D9DE4) != 0) {
                play_sound_effect(o->remap_sound_for_area(0x3E420), &o->position, 0, 0);
            }
            if (o->is_passing_frame(TObjEneBm5Wolf__data_805D9DE8) != 0) {
                play_sound_effect(o->remap_sound_for_area(0x4003A821), &o->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x500);
            }
            if (o->frame <= TObjEneBm5Wolf__data_805D9DF0) {
                t = o->frame - TObjEneBm5Wolf__data_805D9DF4;
                o->m_40c = (o->m_438 + (lbl_805D9DDC * (t * t) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D74))) - o->position.y;
            } else {
                o->stoppingDistance *= (*(f32 *)&TObjEneBm5Wolf__data_805D9DA4);
            }
            o->position.x += o->stoppingDistance * sin_table_lookup(o->rotation_y);
            o->position.z += o->stoppingDistance * cos_table_lookup(o->rotation_y);
        }
        o->vfunc_102();
        o->vfunc_88();
        break;
    case 5:
        o->m_40c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        break;
    }
}

#pragma pop
void TObjEneBm5Wolf::anchor_state(s32 arg1) {
    TObjEneBm5Wolf *leader;

    switch (arg1) {
    case 4:
        this->roamingTimer = 0;
        this->set_field_378(0);
        this->vfunc_95();
        this->m_408 = (s32) (this->m_408 | 2);
        return;
    case 3:
        if (this->roamingTimer > 0) {
            this->transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        leader = find_pack_leader__14TObjEneBm5WolfFi(this->m_3dc);
        if (leader != 0) {
            this->m_3e0 = get_entity_id(leader);
        }
        if ((this->m_3d8 != 0) || (leader == 0)) {
            VecCopy(&this->groupAnchor, (const Vec *)&this->m_3e8);
        } else {
            VecCopy(&this->groupAnchor, (const Vec *)(fn_800B8B00(leader)));
        }
        this->roamingTimer = (this->roamingTimer + 1);
        break;
    }
}

extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
void vfunc_6__8TObjBaseFPsl(void);
void apply_object_set_data__8TObjBaseFPv(void);
void reset_motion_fields__9TObjCharaFv(void);
void get_center__9TObjCharaFv(void);
void update_object_view_visibility__8TObjBaseFff(void);
void classify_actor_view_detail__8TObjBaseFfff(void);
void get_name__9TObjEnemyFv(void);
void interact__14TObjCollidableFl(void);
void add_actor_exp__9TObjCharaFl(void);
void consume_timer_field__9TObjCharaFl(void);
void get_actor_level_index__9TObjCharaFv(void);
void update_actor_ground_y__9TObjCharaFv(void);
void vfunc_18__9TObjCharaFPUc(void);
void is_actor_cadence_frame__9TObjCharaFl(void);
void select_melee_contact_body__9TObjCharaFPvf(void);
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf(void);
void receive_physical_attack__9TObjCharaFPvf(void);
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void);
void receive_weapon_special_attack__9TObjCharaFPvPv(void);
void apply_defense_stat_status__9TObjCharaFPv();
void apply_knockback_from_attacker__9TObjCharaFPUcf(void);
void try_start_action__9TObjCharaFll(void);
void roll_physical_accuracy__9TObjCharaFPvlf(void);
void vfunc_28__14TObjEneBm5WolfFv(void);
void vfunc_29__9TObjCharaFv(void);
void is_target_in_attack_range__9TObjCharaFv(void);
void update_poison_status__9TObjCharaFv(void);
void update_action_hold_status__9TObjCharaFv(void);
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv(void);
void update_movement_status__9TObjCharaFv(void);
void update_shock_clock__9TObjCharaFv(void);
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void vfunc_43__9TObjCharaFv(void);
void apply_poison_status__9TObjCharaFv(void);
void apply_paralysis__9TObjCharaFv(void);
void apply_slow_status__9TObjCharaFv(void);
void apply_confusion_status__9TObjCharaFv(void);
void apply_movement_ailment__9TObjCharaFl(void);
void apply_shock_status__9TObjCharaFv(void);
void clear_harmful_statuses__9TObjCharaFv(void);
void apply_attack_stat_status__9TObjCharaFPv(void);
void cure_poison_ailment__9TObjCharaFv(void);
void cure_paralysis__9TObjCharaFv(void);
void clear_all_status_effects__9TObjCharaFv(void);
void apply_action_hold_status__9TObjCharaFf(void);
void apply_anti_technique__9TObjCharaFl(void);
void vfunc_58__9TObjCharaFv(void);
void vfunc_59__9TObjCharaFv(void);
void vfunc_60__9TObjCharaFv(void);
void vfunc_61__14TObjEneBm5WolfFv(void);
void reset_pose__9TObjCharaFv(void);
void get_anim_node_position__9TObjCharaFlP3Vec(void);
void vfunc_66__9TObjCharaFv(void);
void vfunc_67__9TObjCharaFf(void);
void get_pos__9TObjCharaFl(void);
void apply_switch_attack__9TObjCharaFv(void);
void enemy_spawn_jellen_effect__9TObjCharaFv(void);
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void enemy_spawn_zalure_effect__9TObjCharaFv(void);
void recalc_stats__9TObjCharaFv(void);
void vfunc_74__9TObjEnemyFl(void);
void vfunc_75__9TObjCharaFf(void);
void vfunc_76__9TObjCharaFf(void);
void vfunc_77__9TObjCharaFv(void);
void vfunc_78__9TObjCharaFl(void);
void vfunc_79__9TObjEneDDFPl(void);
void apply_hit_message_flags__9TObjEnemyFPv(void);
void apply_set_data__9TObjEnemyFPv(void);
void clear_lobby_object_state__9TObjEnemyFv(void);
void vfunc_83__12TObjEneDD_STFv(void);
void vfunc_84__9TObjEneDDFv(void);
void vfunc_85__9TObjEneDDFv(void);
void vfunc_86__9TObjEneDDFv(void);
void vfunc_89__9TObjEneDDFv(void);
void vfunc_90__9TObjEneDDFv(void);
void vfunc_91__9TObjEneDDFv(void);
void vfunc_92__9TObjEneDDFv(void);
void vfunc_93__9TObjEneDDFv(void);
void vfunc_94__9TObjEneDDFv(void);
void vfunc_95__9TObjEneDDFv(void);
void vfunc_96__9TObjEneDDFv(void);
void vfunc_97__9TObjEneDDFv(void);
void vfunc_98__9TObjEneDDFv(void);
void vfunc_99__9TObjEneDDFv(void);
void vfunc_100__9TObjEneDDFv(void);
void vfunc_101__9TObjEneDDFPUc(void);
void vfunc_102__9TObjEneDDFv(void);
void vfunc_103__9TObjEneDDFPUc(void);
int vfunc_104__12TObjEneDD_STFf(void *p);
void *lbl_804922F8[107] = {
    0,
    0,
    (void *)__dt__14TObjEneBm5WolfFv,
    (void *)run_task__14TObjEneBm5WolfFv,
    (void *)render__14TObjEneBm5WolfFv,
    (void *)render_shadows__9TObjEnemyFv,
    (void *)vfunc_6__8TObjBaseFPsl,
    (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv,
    (void *)get_center__9TObjCharaFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__9TObjEnemyFv,
    (void *)interact__14TObjCollidableFl,
    (void *)add_actor_exp__9TObjCharaFl,
    (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv,
    (void *)update_actor_ground_y__9TObjCharaFv,
    (void *)vfunc_18__9TObjCharaFPUc,
    (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf,
    (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (void *)receive_physical_attack__9TObjCharaFPvf,
    (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv,
    (void *)apply_knockback_from_attacker__9TObjCharaFPUcf,
    (void *)try_start_action__9TObjCharaFll,
    (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__14TObjEneBm5WolfFv,
    (void *)vfunc_29__9TObjCharaFv,
    (void *)is_target_in_attack_range__9TObjCharaFv,
    (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv,
    (void *)&has_flag_0x800__9TObjCharaFv,
    (void *)&test_flag_1000__9TObjCharaFv,
    (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv,
    (void *)vfunc_37__9TObjCharaFv,
    (void *)update_flag30_timer__9TObjCharaFv,
    (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv,
    (void *)update_attack_stat_status__9TObjCharaFv,
    (void *)update_defense_stat_status__9TObjCharaFv,
    (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv,
    (void *)apply_paralysis__9TObjCharaFv,
    (void *)apply_slow_status__9TObjCharaFv,
    (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl,
    (void *)apply_shock_status__9TObjCharaFv,
    (void *)clear_harmful_statuses__9TObjCharaFv,
    (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv,
    (void *)cure_poison_ailment__9TObjCharaFv,
    (void *)cure_paralysis__9TObjCharaFv,
    (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf,
    (void *)apply_anti_technique__9TObjCharaFl,
    (void *)vfunc_58__9TObjCharaFv,
    (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv,
    (void *)vfunc_61__14TObjEneBm5WolfFv,
    (void *)vfunc_62__14TObjEneBm5WolfFv,
    (void *)vfunc_63__14TObjEneBm5WolfFv,
    (void *)reset_pose__9TObjCharaFv,
    (void *)get_anim_node_position__9TObjCharaFlP3Vec,
    (void *)vfunc_66__9TObjCharaFv,
    (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl,
    (void *)apply_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_jellen_effect__9TObjCharaFv,
    (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv,
    (void *)recalc_stats__9TObjCharaFv,
    (void *)vfunc_74__9TObjEnemyFl,
    (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFf,
    (void *)vfunc_77__9TObjCharaFv,
    (void *)vfunc_78__9TObjCharaFl,
    (void *)vfunc_79__9TObjEneDDFPl,
    (void *)apply_hit_message_flags__9TObjEnemyFPv,
    (void *)apply_set_data__9TObjEnemyFPv,
    (void *)clear_lobby_object_state__9TObjEnemyFv,
    (void *)vfunc_83__12TObjEneDD_STFv,
    (void *)vfunc_84__9TObjEneDDFv,
    (void *)vfunc_85__9TObjEneDDFv,
    (void *)vfunc_86__9TObjEneDDFv,
    (void *)dispatch_state__14TObjEneBm5WolfFPvUii,
    (void *)vfunc_88__14TObjEneBm5WolfFv,
    (void *)vfunc_89__9TObjEneDDFv,
    (void *)vfunc_90__9TObjEneDDFv,
    (void *)vfunc_91__9TObjEneDDFv,
    (void *)vfunc_92__9TObjEneDDFv,
    (void *)vfunc_93__9TObjEneDDFv,
    (void *)vfunc_94__9TObjEneDDFv,
    (void *)vfunc_95__9TObjEneDDFv,
    (void *)vfunc_96__9TObjEneDDFv,
    (void *)vfunc_97__9TObjEneDDFv,
    (void *)vfunc_98__9TObjEneDDFv,
    (void *)vfunc_99__9TObjEneDDFv,
    (void *)vfunc_100__9TObjEneDDFv,
    (void *)vfunc_101__9TObjEneDDFPUc,
    (void *)vfunc_102__9TObjEneDDFv,
    (void *)vfunc_103__9TObjEneDDFPUc,
    (void *)vfunc_104__12TObjEneDD_STFf,
    (void *)update_state__14TObjEneBm5WolfFPv,
    (void *)render_debug__14TObjEneBm5WolfFPv,
};
}
typedef void (*State_800B73A8)(u8 *, s32);
void dispatch_state__14TObjEneBm5WolfFPvUii(TObjEneBm5Wolf *wolf, u32 state, s32 event) {
    switch (state) {
    case 0:
        wolf->anchor_state(event);
        break;
    case 1:
        appearing_state__14TObjEneBm5WolfFPvi(wolf, event);
        break;
    case 2:
        wolf->sleeping_state(event);
        break;
    case 3:
        ((State_800B73A8)TObjEneBm5Wolf::empty_state)((u8 *)wolf, event);
        break;
    case 4:
        wolf->alerted_state(event);
        break;
    case 5:
        wolf->standing_state(event);
        break;
    case 6:
        wolf->howling_state(event);
        break;
    case 7:
        wolf->roaming_state(event);
        break;
    case 8:
        wolf->chasing_state(event);
        break;
    case 9:
        wolf->flanking_state(event);
        break;
    case 10:
        wolf->circling_state(event);
        break;
    case 11:
        wolf->update_lunge(event);
        break;
    case 12:
        returning_state__14TObjEneBm5WolfFPvi(wolf, event);
        break;
    case 13:
        wolf->repositioning_state(event);
        break;
    case 14:
        wolf->action(event);
        break;
    case 15:
        wolf->hurt_state(event);
        break;
    case 16:
        wolf->update_dying_state(event);
        break;
    case 17:
        wolf->despawn_state(event);
        break;
    }
}

void TObjEneBm5Wolf::apply_mourning_jellen() {
    TObjEneBm5Wolf *target = (TObjEneBm5Wolf *)find_entity_by_id(this->m_3e0);
    if (target != 0) {
        DirectAttackPayload attack;
        attack.kind = 0xb;
        attack.power = *(f32 *)&TObjEneBm5Wolf__data_805D9D8C;
        this->receive_direct_attack(target, attack, 0, -1, -1);
    }
}

void TObjEneBm5Wolf::apply_mourning_zalure() {
    TObjEneBm5Wolf *target = (TObjEneBm5Wolf *)find_entity_by_id(this->m_3e0);
    if (target != 0) {
        DirectAttackPayload attack;
        attack.kind = 0xc;
        attack.power = *(f32 *)&TObjEneBm5Wolf__data_805D9D8C;
        this->receive_direct_attack(target, attack, 0, -1, -1);
    }
}
}

#include <stddef.h>

extern "C" {
s32 transform_relative_position__9TObjEneDDFPv(void *, int);
extern const f32 lbl_805D9E44;
f32 newton_sqrtf(f32);

void schedule_pack_reaction__14TObjEneBm5WolfFPvis(TObjEneBm5Wolf *wolf, s32 delay, u16 value) {
    wolf->m_414 = delay;
    wolf->m_418 = value;
}

#pragma push
#pragma fp_contract on
s32 calc_lunge_aim__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) {
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    if (transform_relative_position__9TObjEneDDFPv(wolf, (int)wolf->target) != 0) {
        wolf->enemy_copy_target_destination();
        wolf->update_velocity();
        if (((s32)get_flag_bit0__14TObjEneBm5WolfFPv(wolf)) != 0) {
            var_f0 = TObjEneBm5Wolf__data_805D9DEC;
        } else {
            var_f0 = lbl_805D9E44;
        }
        temp_f5 = wolf->destinationDirection.z;
        temp_f4 = wolf->destinationDirection.x;
        wolf->destination.x = (f32) (wolf->destination.x + (((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) * temp_f4) + (temp_f5 * var_f0)));
        wolf->destination.z = (f32) (wolf->destination.z + (((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) * temp_f5) - (temp_f4 * var_f0)));
        wolf->update_velocity();
        return (s32) ((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float((f64) wolf->destinationDirection.x, (f64) wolf->destinationDirection.z));
    }
    wolf->destinationDirection.x = sin_table_lookup(wolf->rotation_y);
    wolf->destinationDirection.y = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->destinationDirection.z = cos_table_lookup(wolf->rotation_y);
    VecCopy(&wolf->destination, &wolf->position);
    wolf->destination.x = (f32) ((TObjEneBm5Wolf__data_805D9DF0 * wolf->destinationDirection.x) + wolf->destination.x);
    wolf->destination.z = (f32) ((TObjEneBm5Wolf__data_805D9DF0 * wolf->destinationDirection.z) + wolf->destination.z);
    wolf->destinationDistance = (f32) TObjEneBm5Wolf__data_805D9DF0;
    return wolf->rotation_y;
}
#pragma pop

int get_flag_bit0__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) { return wolf->entity_id & 0x1; }

extern const f32 lbl_805D9E48;

f32 calc_death_slide_speed__14TObjEneBm5WolfFPvf(TObjEneBm5Wolf *wolf, f32 speed) {
    return (*(f32 *)&lbl_805D9D9C) / ((wolf->motion_list[wolf->action_table[9].motion].motion->frameCount - 1) / speed);
}

void TObjEneBm5Wolf::play_proximity_effect() {
    if (this->is_passing_frame(lbl_805D9E48) != 0) {
        play_sound_effect(this->remap_sound_for_area(0x3C618), &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x1000);
    }
}

extern f32 lbl_805D9E4C;
extern f32 lbl_805D9E50;

void play_footsteps__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) {
    if ((wolf->is_passing_frame(TObjEneBm5Wolf__data_805D9DEC) != 0) || (wolf->is_passing_frame(TObjEneBm5Wolf__data_805D9DE8) != 0)) {
        play_sound_effect(wolf->remap_sound_for_area(0x3C618), &wolf->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x1000);
    }
}

#pragma push
#pragma fp_contract on
void spawn_recoil_dust__14TObjEneBm5WolfFiPv(TObjEneBm5Wolf *wolf, Vec *dir) {
    Vec pos;
    VecCopy(&pos, &wolf->position);
    pos.x += TObjEneBm5Wolf__data_805D9DE0 * dir->x;
    pos.z += TObjEneBm5Wolf__data_805D9DE0 * dir->z;
    spawn_particle_effect(&pos, 0xF3);
}
#pragma pop

s32 play_variant_sound__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) {
    if (wolf->m_3d8 != 0) {
        return wolf->update_linked_position(lbl_805D9E4C);
    }
    return wolf->update_linked_position(lbl_805D9E50);
}

s32 select_target__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) {
    if (wolf->m_3d8 != 0) {
        return wolf->select_and_apply_target(lbl_805D9E4C);
    }
    return wolf->select_and_apply_target(lbl_805D9E50);
}

void TObjEneBm5Wolf::set_attack_flag() { this->m_408 |= 0x1; }

s32 select_death_direction__14TObjEneBm5WolfFPvPv(TObjEneBm5Wolf *wolf, s32 *heading) {
    Vec v;
    Vec side;
    s32 ret;
    VecCopy(&v, (const Vec *)&wolf->x_speed);
    v.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    if ((*(f32 *)&TObjEneBm5Wolf__data_805D9D78) != normalize_vector_xz(&v)) {
        *heading = (s32)((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float(v.x, v.z));
        side.x = sin_table_lookup(wolf->rotation_y);
        side.z = cos_table_lookup(wolf->rotation_y);
        if (is_vec_xz_cross_negative(&side, &v) != 0) {
            ret = 0;
            *heading += 0x4000;
        } else {
            ret = 1;
            *heading -= 0x4000;
        }
    } else {
        ret = 0;
        *heading = wolf->rotation_y;
    }
    *heading = (s16)*heading;
    return ret;
}

#pragma push
#pragma fp_contract on
f32 calc_circle_offset__14TObjEneBm5WolfFPvPvPv(TObjEneBm5Wolf *wolf, Vec *target, Vec *out) {
    f32 dx;
    f32 dz;
    dz = wolf->position.z - target->z;
    dx = wolf->position.x - target->x;
    f32 distSq = dx * dx + dz * dz;
    f32 inv = (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C) / ((f32 (*)(f32, f32))newton_sqrtf)(distSq, wolf->position.x);
    out->x = dx * inv;
    out->y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    out->z = dz * inv;
    return distSq * inv;
}
#pragma pop

void TObjEneBm5Wolf::set_anim_state() {
    if (this->m_3d8 != 0) {
        this->transition_enemy_state(6);
        return;
    }
    this->transition_enemy_state(5);
}

void set_state_by_timer__14TObjEneBm5WolfFi(TObjEneBm5Wolf *wolf) {
    if (wolf->random_ratio() < (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC)) {
        wolf->transition_enemy_state(8);
        return;
    }
    wolf->transition_enemy_state(9);
}

}

__declspec(section ".sdata2") extern const f32 lbl_805D9DD8 = 13.333333015441895f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DDC = -0.08888889104127884f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DE0 = 5.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DE4 = 6.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DE8 = 24.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DEC = 7.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DF0 = 30.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DF4 = 15.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DF8 = 0.699999988079071f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DFC = 10000.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E00 = 900.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E04 = 80.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E08 = -0.20000000298023224f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E0C = 0.11999999731779099f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E10 = 768.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E14 = 65536.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E18 = 120.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E1C = 22500.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E20 = 0.05000000074505806f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E24 = 512.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E28 = 0.020000001415610313f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E2C = 240.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E30 = 360.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E34 = 9.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E38 = 60.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E3C = 100.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E40 = 3.3333332538604736f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E44 = -7.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E48 = 18.0f;
__declspec(section ".sdata2") f32 lbl_805D9E4C = 350.0f;
__declspec(section ".sdata2") f32 lbl_805D9E50 = 250.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E54 = 32768.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E58 = 25.0f;

#pragma fp_contract on

extern "C" {

void calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(TObjEneBm5Wolf *wolf, s32 angle, Vec *out, s32 *heading) {
    f32 c;
    f32 s;

    s = sin_table_lookup(angle);
    c = cos_table_lookup(angle);
    out->z = (f32) ((c * wolf->destinationDirection.z) - (s * wolf->destinationDirection.x));
    out->x = (f32) ((s * wolf->destinationDirection.z) + (c * wolf->destinationDirection.x));
    *heading = (s32) ((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float(out->x, out->z));
}

}

extern "C" {
s32 angle_diff_s16(s32, s32);

void approach_target__14TObjEneBm5WolfFPvf(TObjEneBm5Wolf *wolf, f32 step) {
    f32 desired;
    f32 current;

    current = wolf->currentSpeed;
    desired = wolf->desiredSpeed;
    if (current != desired) {
        if (current > desired) {
            wolf->currentSpeed = (f32) (current - step);
            if (wolf->currentSpeed < wolf->desiredSpeed) {
                wolf->currentSpeed = wolf->desiredSpeed;
            }
        } else {
            wolf->currentSpeed = (f32) (current + step);
            if (wolf->currentSpeed > wolf->desiredSpeed) {
                wolf->currentSpeed = wolf->desiredSpeed;
            }
        }
    }
}

void TObjEneBm5Wolf::choose_roaming_destination() {
    Vec dir;
    f32 temp_f3;
    f32 temp_f3_2;
    CsnHit *hit;
    dir.x = this->position.x - this->groupAnchor.x;
    dir.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    dir.z = this->position.z - this->groupAnchor.z;
    normalize_vector_xz(&dir);
    rotate_xz_pair_by_angle(&dir.x, &dir.z, (s32) ((*(f32 *)&lbl_805D9E54) * this->random_ratio()) + 0x4000);
    temp_f3 = (*(f32 *)&lbl_805D9E18) * this->rand_range((*(f32 *)&TObjEneBm5Wolf__data_805D9D84), (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
    this->destination.x = (f32) ((dir.x * temp_f3) + this->groupAnchor.x);
    this->destination.z = (f32) ((dir.z * temp_f3) + this->groupAnchor.z);
    hit = csnVector((Vec *)&this->m_2fc, &this->destination, 0x88E0U);
    if (hit != NULL) {
        dir.x = hit->contact->point.x - this->position.x;
        dir.z = hit->contact->point.z - this->position.z;
        temp_f3_2 = normalize_vector_xz(&dir) - (*(f32 *)&lbl_805D9E58);
        this->destination.x = (f32) ((dir.x * temp_f3_2) + this->position.x);
        this->destination.z = (f32) ((dir.z * temp_f3_2) + this->position.z);
    }
}

void TObjEneBm5Wolf::turn_pose_to_target() {
    f32 x;
    f32 z;
    sin_table_lookup(this->rotation_y);
    x = this->position.x + (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    cos_table_lookup(this->rotation_y);
    z = this->position.z + (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    f32 dx = this->target->position.x - x;
    f32 dz = this->target->position.z - z;
    z = atan2_float((0, dx), dz);
    advance_pose_turn__14TObjEneBm5WolfFPvi(this, (s32) ((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * z));
}

void advance_pose_turn__14TObjEneBm5WolfFPvi(TObjEneBm5Wolf *wolf, s32 target) {
    s32 d;
    d = angle_diff_s16(wolf->rotation_y, target);
    if (d > 0x4000) {
        d = 0x4000;
    } else if (d < -0x4000) {
        d = -0x4000;
    }
    if (wolf->turnOffset * d >= 0) {
        wolf->turnOffset = approach_angle_limited(wolf->turnOffset, d, 0x800);
    } else if (wolf->turnOffset * angle_diff_s16(wolf->turnOffset, d) >= 0) {
        if (wolf->turnOffset >= 0) {
            wolf->turnOffset -= 0x800;
        } else {
            wolf->turnOffset += 0x800;
        }
    } else {
        wolf->turnOffset = approach_angle_limited(wolf->turnOffset, d, 0x800);
    }
    wolf->turnOffset = (s16)wolf->turnOffset;
}

void TObjEneBm5Wolf::select_subtype() {
    this->m_3dc = (s32) floor_to_float((f32) (this->parameters[0]));
    if (this->parameters[1] >= (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) {
        this->m_3d8 = 1;
        this->model = (void *)TObjEneBm5Wolf__bml_resource->models[1].model;
        this->texlist = TObjEneBm5Wolf__bml_resource->models[0].m_c;
        return;
    }
    this->m_3d8 = 0;
    this->model = (void *)TObjEneBm5Wolf__bml_resource->models[0].model;
    this->texlist = TObjEneBm5Wolf__bml_resource->models[0].m_c;
}

void TObjEneBm5Wolf::vfunc_88() {
    this->bodies->offset.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9DB4) + this->m_40c;
}

}



extern "C" {
s32 all_parents_unqueued_for_destruction__7TObjectFv();
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
s32 __ct__12TObjEneDD_STFP7TObject(void *, void *);
s32 reset_hp__9TObjEneDDFPUcPUcPUc(void *, int, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFl(void *, int);
s32 init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, int);
s32 invoke_initialization_hook__9TObjEneDDFPv(void *, void *);
s32 init_collision_body_parts(void *, void *, int);
void *__ct__14TObjCollidableFP7TObject(void *, int);
void *__nw__7TObjectFUl(int);
extern s32 bm5_wolf_class_name;
void free_bin_model_request(void*, int);

void TObjEneBm5Wolf::update_collision_center() {

    this->m_2fc = (f32) this->position.x;
    this->m_300 = (f32) ((this->m_40c) + ((*(f32 *)&TObjEneBm5Wolf__data_805D9DB4) + this->position.y));
    this->m_304 = (f32) this->position.z;
    VecCopy(&this->center, (const Vec *)&this->m_2fc);
}

void TObjEneBm5Wolf::vfunc_61() {  }
void TObjEneBm5Wolf::vfunc_62() { if (this->mode != 15) { this->transition_enemy_state(15); } }
void TObjEneBm5Wolf::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0x10) && (temp_r0 != 0x11)) {
        this->transition_enemy_state(0x10);
    }
}
void TObjEneBm5Wolf::vfunc_28() {  }

void TObjEneBm5Wolf::run_task() {
    s16 temp_r0;
    s16 temp_r3_2;
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_state();
        return;
    }
    if (find_entity_by_id((this->m_3e0)) != 0U) {
        all_parents_unqueued_for_destruction__7TObjectFv();
    }
    if (this->vfunc_83() != 4) {
        temp_r3 = this->m_414;
        if (temp_r3 != 0) {
            this->m_414 = (temp_r3 - 1);
            if (this->m_414 == 0) {
                temp_r0 = this->mode;
                if ((temp_r0 != 0x10) && (temp_r0 != 0x11)) {
                    this->transition_enemy_state(0xE);
                }
            }
        }
        this->vfunc_85();
    } else {
        temp_r3_2 = this->mode;
        if (temp_r3_2 == 0) {
            this->vfunc_85();
        } else if (temp_r3_2 == 1) {
            VecCopy(&this->position, &this->home_position);
            this->transition_enemy_state(7);
            this->vfunc_85();
        }
    }
    this->update_collision_center();
    this->submit_default_cursor_candidate();
    this->vfunc_100();
}

u8 *__dt__14TObjEneBm5WolfFv(TObjEneBm5Wolf *wolf, s16 arg1) {
    if (wolf != NULL) {
        *(void ***)((u8 *)wolf + 0x18) = lbl_804922F8;
        if (wolf->m_410 != NULL) {
            free_collision_body_parts(wolf->m_410);
            delete wolf->m_410;
            wolf->m_410 = NULL;
        }
        wolf->update_with_default_state();
        if (wolf->m_3d8 != 0) {
            wolf->update_default();
        }
        free_collision_body_parts(wolf);
        destroy__14TObjEneBm5WolfFis(&wolf->m_3cc, -1);
        destroy__14TObjEneBm5WolfFis(&wolf->m_3c0, -1);
        __dt__12TObjEneDD_STFv(wolf, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(wolf);
        }
    }
    return (u8 *)wolf;
}
#pragma push
#pragma bool off
u8 *TObjEneBm5Wolf__ct(TObjEneBm5Wolf *wolf, void *arg1, void *arg2) {
    s32 n;
    void *o;
    __ct__12TObjEneDD_STFP7TObject(wolf, arg1);
    *(void ***)((u8 *)wolf + 0x18) = lbl_804922F8;
    TObjEneBm5Wolf__sub_800B8A24(&wolf->m_3c0);
    TObjEneBm5Wolf__sub_800B8A24(&wolf->m_3cc);
    *(s32 *)&wolf->m_name = bm5_wolf_class_name;
    invoke_initialization_hook__9TObjEneDDFPv(wolf, arg2);
    wolf->select_subtype();
    wolf->init_position_vectors();
    init_model__9TObjEneDDFP13CollisionBodyl(wolf, TObjEneBm5Wolf__collider_params, 1);
    wolf->set_field_d8((s32)((void *)wolf_action_table));
    wolf->set_field_dc((s32)TObjEneBm5Wolf__bml_resource->motions);
    wolf->requested_action = 0;
    wolf->set_animation(wolf->requested_action);
    wolf->set_field_b8(wolf->requested_action);
    n = wolf->m_3d8;
    reset_hp__9TObjEneDDFPUcPUcPUc(wolf, TObjEneBm5Wolf__stat_params[n != 0], wolf_stat_handle_a_table[n != 0], wolf_stat_handle_b_table[n != 0], n);
    wolf->check_state_flag_1();
    wolf->movementParameters = bm5_wolf_decision_row;
    if (wolf->m_3d8 != 0) {
        initialize_enemy_state__9TObjEneDDFl(wolf, 8);
    } else {
        initialize_enemy_state__9TObjEneDDFl(wolf, 7);
    }
    wolf->m_37c = (*(f32 *)&TObjEneBm5Wolf__data_805D9DF4);
    wolf->enemy_init_acquire_period(0x14);
    wolf->enemy_init_validate_period(0x14);
    ((TObjEneBm5Wolf *)&wolf->m_3c0)->set_field8_from_obj((s32)wolf);
    wolf->apply_position_to_node_list();
    if (wolf->m_3d8 != 0) {
        ((TObjEneBm5Wolf *)&wolf->m_3cc)->set_field8_from_obj((s32)wolf);
        wolf->apply_global_to_position();
    }
    wolf->m_3e0 = 0xFFFF;
    wolf->turnOffset = 0;
    VecCopy(&wolf->m_3e8, &wolf->position);
    VecCopy(&wolf->groupAnchor, &wolf->position);
    wolf->desiredSpeed = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->currentSpeed = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_408 = 0;
    wolf->m_40c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    o = __nw__7TObjectFUl(0xAC);
    if (o != NULL) {
        o = __ct__14TObjCollidableFP7TObject(o, 0);
    }
    wolf->m_410 = (TObjCollidable *)o;
    init_collision_body_parts(wolf->m_410, &TObjEneBm5Wolf__collider_params[1], 1);
    wolf->m_414 = 0;
    wolf->m_418 = 0xFFFF;
    wolf->vfunc_98();
    wolf->roamingSubstate = 0;
    wolf->roamingTimer = 0;
    wolf->randomPhase = 0;
    wolf->m_428 = 0;
    wolf->m_42c = 0;
    wolf->m_430 = 0;
    wolf->stoppingDistance = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_438 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_43c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_440 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_444.x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_444.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_444.z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_450.x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_450.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_450.z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_45c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_460 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->m_464 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    wolf->nearTarget = 0;
    wolf->update_collision_center();
    wolf->vfunc_88();
    wolf->transform_part_positions();
    wolf->mode = 0;
    wolf->dispatch_action(wolf->mode, 4);
    return (u8 *)wolf;
}
#pragma pop

TObjEneBm5Wolf *find_pack_leader__14TObjEneBm5WolfFi(s32 id) {
    TObjEneBm5WolfListNode *n;
    for (n = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->head; n != 0; n = n->next) {
        TObjEneBm5Wolf *w = play_sound__14TObjEneBm5WolfFPv(n);
        if (w != 0 && w->m_3dc == id) {
            return w;
        }
    }
    return 0;
}

void TObjEneBm5Wolf::update_default() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__instance_list)->update(&this->m_3cc);
}

void TObjEneBm5Wolf::apply_global_to_position() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__instance_list)->apply_to_position(&this->m_3cc);
}

void TObjEneBm5Wolf::update_with_default_state() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__pack_member_list)->update(&this->m_3c0);
}

void TObjEneBm5Wolf::apply_position_to_node_list() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__pack_member_list)->apply_to_position(&this->m_3c0);
}

void TObjEneBm5Wolf::release_global_805D5120() {
    if (TObjEneBm5Wolf__bml_resource != 0) {
        free_bin_model_request(TObjEneBm5Wolf__bml_resource, 1);
        TObjEneBm5Wolf__bml_resource = 0;
    }
}

}




struct Globals_800B8A40 {
    u8 pad[0x2c];
    u8 chain0[0xc];
    u8 list0[0x8];
    u8 chain1[0xc];
    u8 list1[0x8];
};

extern "C" {
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
BmlResource *load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
extern s32 lbl_8043B3A8[];
extern s32 lbl_8043B3B0[];
extern s32 lbl_8043B3B8[];
extern s32 lbl_8043B3C0[];
extern const DelDepthAnimationBinding bm5_wolf_spawn_descriptor;
extern u8 lbl_8043B5C0[];
Vec lbl_80500B60;
u32 lbl_80500B6C[3];
u32 TObjEneBm5Wolf__pack_member_list[5];
u32 TObjEneBm5Wolf__instance_list[3];
void __register_global_object(void *obj, void *dtor, void *chain);
void __dl__FPv(void);

extern void *tl_04;

void *TObjEneBm5Wolf::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x46C);
    if (o != NULL) {
        o = TObjEneBm5Wolf__ct((TObjEneBm5Wolf *)o, tl_04, arg0);
    }
    return o;
}

void TObjEneBm5Wolf::load_resources() {
    s32 i;

    if (TObjEneDD::check_v2_mode() != 0) {
        TObjEneBm5Wolf__bml_resource = load_enemy_bml_resource_named(&bm_ene_bm5_wolf_resource_descriptor, lbl_8043B5C0);
    } else {
        TObjEneBm5Wolf__bml_resource = (BmlResource *)load_enemy_bml_resource((u8 *)&bm_ene_bm5_wolf_resource_descriptor);
    }
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__pack_member_list)->reset_fields();
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__instance_list)->reset_fields();
    TObjEneBm5Wolf__spawn_timer = 0;
    TObjEneBm5Wolf__data_805D5128 = 0;
    lbl_80500B60.x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    lbl_80500B60.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    lbl_80500B60.z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    for (i = 0; i < 2; i++) {
        TObjEneBm5Wolf__stat_params[i] = register_boss__6TLobbyFl(lbl_8043B3A8[i]);
        wolf_stat_handle_a_table[i] = dispatch_shared_handler_b__6TLobbyFl(lbl_8043B3B0[i]);
        wolf_stat_handle_b_table[i] = register_object__6TLobbyFl(lbl_8043B3B8[i]);
        lbl_80500B58[i] = dispatch_shared_handler_a__6TLobbyFl(lbl_8043B3C0[i]);
    }
    {
    DelDepthAnimationBinding sp = bm5_wolf_spawn_descriptor;
    sp.motions = TObjEneBm5Wolf__bml_resource->motions;
    TLobby::spawn_npc_enemy(9, TObjEneBm5Wolf__bml_resource->models[1].model, (NJS_TEXLIST *)TObjEneBm5Wolf__bml_resource->models[0].m_c, &sp, TObjEneBm5Wolf__collider_params[0].radius, (*(f32 *)&TObjEneBm5Wolf__data_805D9D78));
    TLobby::spawn_npc_enemy(10, TObjEneBm5Wolf__bml_resource->models[0].model, (NJS_TEXLIST *)TObjEneBm5Wolf__bml_resource->models[0].m_c, &sp, TObjEneBm5Wolf__collider_params[0].radius, (*(f32 *)&TObjEneBm5Wolf__data_805D9D78));
    }
}

void TObjEneBm5Wolf::update(void* a1) {
    TObjEneBm5WolfList *list = (TObjEneBm5WolfList *)this;
    ((TObjEneBm5Wolf *)a1)->unlink_list_node((void ***)&list->head, (void **)&list->tail);
}
void TObjEneBm5Wolf::apply_to_position(void* a1) {
    TObjEneBm5WolfList *list = (TObjEneBm5WolfList *)this;
    ((TObjEneBm5Wolf *)a1)->push_list_node((void **)&list->head, (void **)&list->tail);
}
void TObjEneBm5Wolf::reset_fields() {
    TObjEneBm5WolfList *list = (TObjEneBm5WolfList *)this;
    list->head = NULL;
    list->tail = NULL;
}
s32 __dt__14TObjEneBm5WolfFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void*TObjEneBm5Wolf::reset() { reset_fields(); return this; }
TObjEneBm5Wolf *play_sound__14TObjEneBm5WolfFPv(TObjEneBm5WolfListNode *node) {
    return (TObjEneBm5Wolf *)find_entity_by_id(node->entity_id);
}
void TObjEneBm5Wolf::set_field8_from_obj(s32 arg1) {
    ((TObjEneBm5WolfListNode *)this)->entity_id = get_entity_id((TObjBase *)arg1);
}

void TObjEneBm5Wolf::push_list_node(void **arg1, void **arg2) {
    TObjEneBm5WolfListNode *node = (TObjEneBm5WolfListNode *)this;
    TObjEneBm5WolfListNode **head = (TObjEneBm5WolfListNode **)arg1;
    TObjEneBm5WolfListNode **tail = (TObjEneBm5WolfListNode **)arg2;
    if (*tail != NULL) {
        node->prev = *tail;
        (*tail)->next = node;
    } else {
        node->prev = NULL;
        *head = node;
    }
    *tail = node;
    node->next = NULL;
}

void TObjEneBm5Wolf::unlink_list_node(void ***arg1, void **arg2) {
    TObjEneBm5WolfListNode *node = (TObjEneBm5WolfListNode *)this;
    TObjEneBm5WolfListNode **head = (TObjEneBm5WolfListNode **)arg1;
    TObjEneBm5WolfListNode **tail = (TObjEneBm5WolfListNode **)arg2;
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        *head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
        return;
    }
    *tail = node->prev;
}

TObjEneBm5WolfListNode *destroy__14TObjEneBm5WolfFis(TObjEneBm5WolfListNode *node, s16 arg1) {
    if ((node != NULL) && (arg1 > 0)) {
        __dl__FPv();
    }
    return node;
}

void TObjEneBm5Wolf__sub_800B8A24(TObjEneBm5WolfListNode *node) {
    node->prev = NULL;
    node->next = NULL;
    node->entity_id = 0xFFFF;
}

void TObjEneBm5Wolf::register_global_objects() {
    Globals_800B8A40 *g = (Globals_800B8A40 *)TObjEneBm5Wolf__stat_params;
    __register_global_object(((void *)((TObjEneBm5Wolf *)(g->list0))->reset()), (void *)__dt__14TObjEneBm5WolfFis, g->chain0);
    __register_global_object(((void *)((TObjEneBm5Wolf *)(g->list1))->reset()), (void *)__dt__14TObjEneBm5WolfFis, g->chain1);
}
}

s32 actor_rand_int(s32 actor, s32 arg1) {
    return (s32) ((f32) arg1 * random_ratio__9TObjCharaFv(actor));
}
extern "C" {

s32 get_group_id__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf) { return wolf->m_3dc; }
}


__declspec(section ".ctors") static void *const __sinit_TObjEneBm5Wolf_cpp_ref = (void *)TObjEneBm5Wolf::register_global_objects;
