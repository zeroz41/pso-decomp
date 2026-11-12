#include "types.h"
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

// The Re2 flower's draw functions open the flower's translation unit: their
// literal pool (400.0, 25.0, 600.0 at 0x805D9FA0) repeats values the Lappy
// pool before it already holds, so they are not part of the Lappy file.
extern Vec lbl_8043BBC0[];
extern Vec lbl_8043BBB4[];
extern "C" {
s32 is_main_phase_15__9TObjEneDDFv(void);
extern s32 lbl_805D5178;
extern s32 lbl_805D517C;
extern f32 *lbl_805D5180;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FB0;
extern const f32 lbl_805D9FB4;
extern const f32 lbl_805D9FB8;
}

void TObjEneRe2Flower::vfunc_106() {
    s32 save8;
    s32 save14;
    if (update_object_view_visibility(400.0f, 25.0f) == 0) {
        return;
    }
    Vec v = lbl_8043BBC0[0];
    draw_ground_shadow(&v, 0);
    if (get_flag_11() == 0 && sub_800C3B8C() != 0) {
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
    if (get_flag_11() == 0 && sub_800C3B8C() != 0) {
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = save8;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = save14;
    }
}

void TObjEneRe2Flower::render() {
    s32 visible;
    s32 save8;
    s32 save14;
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_106();
        return;
    }
    if (mode == 11) {
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
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
        if (get_flag_11() == 0 && sub_800C3B8C() != 0) {
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
        lbl_805D517C = rotation_y - m_3c0;
        lbl_805D5180 = &m_3dc[0].x;
        m_3dc[0].x = lbl_805D9FAC;
        m_3dc[0].y = lbl_805D9FB0;
        m_3dc[0].z = lbl_805D9FAC;
        m_3dc[1].x = lbl_805D9FAC;
        m_3dc[1].y = lbl_805D9FB4;
        m_3dc[1].z = lbl_805D9FAC;
        scale_matrix(0, lbl_805D9FB8, lbl_805D9FB8, lbl_805D9FB8);
        set_chunk_model_node_callback((s32)((void *)TObjPlayer::update_effect_sequence));
        if (mode == 8) {
            s32 c = (m_3d8 & 0xFF) << 16;
            lbl_805D5178 = -1;
            TObjPlayer::toggle_particle_effect();
            draw_with_alt_model(c);
            TParticleCtrl::end_effect_render();
        } else {
            lbl_805D5178 = 0;
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
        if (get_flag_11() == 0 && sub_800C3B8C() != 0) {
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
