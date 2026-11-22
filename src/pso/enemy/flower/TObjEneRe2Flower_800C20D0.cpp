#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/dd/TObjEneDD_800C2614.h"
#include "pso/unk/text_800C3A60.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D853C.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

// The Re2 flower's draw functions open the flower's translation unit: their
// literal pool (400.0, 25.0, 600.0) repeats values the Lappy
// pool before it already holds, so they are not part of the Lappy file.
extern Vec lbl_8043BBC0[];
extern Vec lbl_8043BBB4[];
extern s32 re2_flower_node_index;
extern s32 re2_flower_node_yaw;
extern f32 *re2_flower_node_points;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FB0;
extern const f32 lbl_805D9FB4;
extern const f32 lbl_805D9FB8;

struct Prm_800C2628 { f32 a, b, c, d, e; };
extern "C" {
extern Prm_800C2628 enemy_dd_attack_param_block;
extern Prm_800C2628 lbl_8043BBA0;
extern f32 *const re2_flower_movement_params;
extern const f32 lbl_805D9FBC;
extern const f32 lbl_805D9FC0;
}

void TObjEneRe2Flower::render_demo() {
    s32 save8;
    s32 save14;
    if (update_object_view_visibility(400.0f, 25.0f) == 0) {
        return;
    }
    Vec v = lbl_8043BBC0[0];
    draw_ground_shadow(&v, 0);
    if (get_flag_11() == 0 && is_rare_variant() != 0) {
        save8 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
        save14 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
    }
    TObjFish::set_global_param(texlist);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    TObjEneDD::clear_global_flag_400();
    TObjPlayer::toggle_particle_effect();
    set_alpha_ref_override(0);
    draw_chunk_object(model);
    restore_alpha_ref();
    TParticleCtrl::end_effect_render();
    pop_matrix();
    if (get_flag_11() == 0 && is_rare_variant() != 0) {
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = save8;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = save14;
    }
}

void TObjEneRe2Flower::render() {
    s32 visible;
    s32 save8;
    s32 save14;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    if (mode == 11) {
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (get_flag_11() != 0) {
            visible = classify_actor_view_detail(600.0f, 600.0f, 25.0f);
        } else {
            visible = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 25.0f);
        }
    } else if (update_object_view_visibility(400.0f, 25.0f) != 0) {
        visible = 1;
    } else {
        visible = 0;
    }
    if (visible != 0) {
        if (mode != 10) {
            Vec v = lbl_8043BBB4[0];
            draw_ground_shadow(&v, 0);
        }
        update_secondary_light();
        if (get_flag_11() == 0 && is_rare_variant() != 0) {
            save8 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
            save14 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
        }
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, m_3c0);
        saved_model_render_flags = model_render_flags;
        set_alpha_ref_override(0);
        TObjEneDD::clear_global_flag_400();
        translate_matrix(0, lbl_805D9FAC, m_3c8, lbl_805D9FAC);
        re2_flower_node_yaw = rotation_y - m_3c0;
        re2_flower_node_points = &m_3dc[0].x;
        m_3dc[0].x = lbl_805D9FAC;
        m_3dc[0].y = lbl_805D9FB0;
        m_3dc[0].z = lbl_805D9FAC;
        m_3dc[1].x = lbl_805D9FAC;
        m_3dc[1].y = lbl_805D9FB4;
        m_3dc[1].z = lbl_805D9FAC;
        scale_matrix(0, lbl_805D9FB8, lbl_805D9FB8, lbl_805D9FB8);
        set_chunk_model_node_callback(TObjPlayer::update_effect_sequence);
        if (mode == 8) {
            s32 c = (m_3d8 & 0xFF) << 16;
            re2_flower_node_index = -1;
            TObjPlayer::toggle_particle_effect();
            draw_with_alt_model(c);
            TParticleCtrl::end_effect_render();
        } else {
            re2_flower_node_index = 0;
            TObjPlayer::toggle_particle_effect();
            if (m_3c4 & 8) {
                if (m_3f4.has_visible_opacity() != 0) {
                    m_3f4.set_flags_and_apply_damage_color();
                    if (defer_render() == 0) {
                        draw();
                    }
                    m_3f4.clear_flag_and_notify();
                }
            } else if (visible == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            TParticleCtrl::end_effect_render();
        }
        set_chunk_model_node_callback(0);
        restore_alpha_ref();
        model_render_flags = saved_model_render_flags;
        pop_matrix();
        update_primary_light();
        if (get_flag_11() == 0 && is_rare_variant() != 0) {
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = save8;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = save14;
        }
        return;
    }
    m_3dc[0].x = position.x;
    m_3dc[0].y = lbl_805D9FB0 + position.y;
    m_3dc[0].z = position.z;
    m_3dc[1].x = position.x;
    m_3dc[1].y = lbl_805D9FB4 + position.y;
    m_3dc[1].z = position.z;
}
extern "C" {
void TObjPlayer::update_effect_sequence(NJS_OBJECT *) {
    switch ((s32) re2_flower_node_index) {
    case 1:
        rotate_matrix_y(0, re2_flower_node_yaw);
        break;
    case 14:
        push_matrix();
        forward_split_screen_view_matrix();
        matrix_mult_vec_array(NULL, (const Vec *)re2_flower_node_points, (Vec *)re2_flower_node_points, 2);
        pop_matrix();
        break;
    }
    re2_flower_node_index += 1;
}

void TObjEneRe2Flower::run_demo_task() {  }

void TObjEneDD__sub_800C2618(void* p) { *(u32*)((char*)p + 0x3c4) |= 0x2; }
}

#define F(T, off) (*(T *)(arg0 + (off)))
extern "C" {
void TObjEneDD__sub_800C2628(u8 *arg0, s32 reason) {
    s32 step;
    Vec v;
    switch (reason) {
    case 4:
        F(s16, 0xB8) = 1;
        ((TObjEneDD *)(arg0))->clear_intangible();
        ((TObjEneRe2Flower *)arg0)->clear_child_flags();
        F(u32, 0x3C4) &= ~8;
        ((TObjEneDD *)arg0)->set_field_378(8);
        if (!(F(u32, 0x3C4) & 4)) {
            F(u32, 0x3C4) |= 4;
            F(s32, 0x410) = 0;
            F(s32, 0x420) = 0;
            F(s32, 0x414) = 1;
            F(s32, 0x3D8) = 0;
            F(s32, 0x3D4) = 0;
        }
        break;
    case 1:
    case 5:
        break;
    case 3:
        if (F(s32, 0x410) > 0x1C2) {
            F(u32, 0x30) |= 0x800;
            ((TObjEneDD *)arg0)->transition_enemy_state(0xA);
            VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x38));
            v.y += lbl_805D9FBC;
            spawn_particle_effect_with_flags(&v, 0xD3, 0x40);
            {
                Prm_800C2628 prm = lbl_8043BBA0;
                prm.d = prm.b = *re2_flower_movement_params;
                if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0) {
                    TObjEneDD__sub_800BA5A4(arg0, &prm);
                } else {
                    TObjEneDD__sub_800BA5A4(arg0, &enemy_dd_attack_param_block);
                }
            }
            play_sound_effect(remap_sound_for_variant((saddr)arg0, 0x4003A311), arg0 + 0x38, 0, 0);
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (F(s32, 0x3D4) > 0) {
            F(s32, 0x3D4)--;
            if (F(s32, 0x3D4) == 0) {
                ((TObjEneDD *)arg0)->clear_attack_receipts();
            }
        }
        if (TObjEneDD::check_v2_mode() != 0) {
            F(s32, 0x410) += 0x14;
        } else {
            F(s32, 0x410) += 1;
        }
        if (F(s32, 0x410) < 0x12C) {
            step = 0x11;
            F(s32, 0x60) += 0x400;
        } else if (F(s32, 0x410) < 0x168) {
            step = 0x22;
            F(s32, 0x60) += 0x800;
        } else if (F(s32, 0x410) < 0x1B3) {
            step = 0x44;
            F(s32, 0x60) += 0x1000;
        } else {
            step = 0x44;
        }
        if (F(s32, 0x410) < 0x1B3) {
            if (F(s32, 0x414) == 0) {
                F(s32, 0x3D8) += step;
                if (F(s32, 0x3D8) > 0xFF) {
                    F(s32, 0x3D8) = 0xFF - (F(s32, 0x3D8) - 0xFF);
                    F(s32, 0x414) = 1;
                    play_sound_effect(remap_sound_for_variant((saddr)arg0, 0x4003AD10), arg0 + 0x38, 0, 0);
                }
            } else {
                F(s32, 0x3D8) -= step;
                if (F(s32, 0x3D8) < 0) {
                    F(s32, 0x3D8) = -F(s32, 0x3D8);
                    F(s32, 0x414) = 0;
                }
            }
        } else {
            F(s32, 0x3D8) = 0xFF;
        }
        ((TObjEneDD *)(arg0))->update_ground_contact();
        ((TObjEneDD *)(arg0))->update_body_colliders();
        ((TObjEneDD *)arg0)->noop();
        break;
    }
}
}

#undef F
extern "C" {
void TObjEneRe2Flower::handle_event(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        this->requested_action = 6;
        this->clear_intangible();
        ((TObjEneRe2Flower *)arg0)->clear_child_flags();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFF7);
        ((TObjEneDD *)arg0)->set_field_378(3);
        *(s32 *)((s8 *)arg0 + 0x410) = 0;
        play_sound_effect(remap_sound_for_variant((saddr)arg0, 0x4003A315), (u8 *)&this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        return;
    case 3:
        if (is_passing_frame(this->frame_count - lbl_805D9FC0) != 0) {
            ((TObjEneDD *)arg0)->transition_enemy_state(3);
        }
        this->update_ground_contact();
        this->update_body_colliders();
        return;
    case 0:
        advance_animation();
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x410);
        *(s32 *)((s8 *)arg0 + 0x410) = (temp_r4 + 1);
        ((TObjEneDD *)arg0)->noop();
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFD);
    case 1:
        return;
    }
}
}

// Literals of the flower file that the units split from it (text_800C2A88, text_800C2CE0, TObjEneRe2Flower.cpp)
// share; they follow this unit's own literals in .sdata2.
__declspec(section ".sdata2") extern const f32 lbl_805D9FAC = 0.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FB0 = 2.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FB4 = 7.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FB8 = 1.3f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FBC = 5.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FC0 = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FC4 = 10.0f;
