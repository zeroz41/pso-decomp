#include "types.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2F28.h"

extern "C" {
extern const Vec player_sub_802ce68c_zero_vec;
extern const Vec lbl_8047249C;
extern const Vec lbl_80472490;
extern const f32 lbl_805DE700;
extern const f32 lbl_805DE704;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805DE70C;
extern s32 lbl_805D686C;
s32 is_main_phase_15__9TObjEneDDFv();
}

void TObjEneBm9Mericarol::sub_802CE68C(Vec *out, s32 node) {
    set_motion_packed_rotation();
    push_matrix_from(&identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[node]);
    Vec v = player_sub_802ce68c_zero_vec;
    matrix_mult_vec(0, &v, out);
    pop_matrix();
    clear_motion_packed_rotation();
}

void TObjEneBm9Mericarol::draw_color_variant() {
    u32 s0;
    u32 s1;
    u32 s2;
    if (update_object_view_visibility(lbl_805DE700, lbl_805DE704) != 0) {
        Vec v = lbl_8047249C;
        draw_ground_shadow(&v, 0);
        switch (variant) {
        case 1:
            s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
            s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
            s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[4].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[5].texaddr;
            break;
        case 2:
            s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
            s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
            s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[6].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[7].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[8].texaddr;
            break;
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
        if (variant == 1 || variant == 2) {
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = s0;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = s1;
            ((NJS_TEXLIST *)texlist)->textures[2].texaddr = s2;
        }
    }
}

void TObjEneBm9Mericarol::render() {
    s32 vis;
    RenderFadeState *fade;
    s16 saved;
    s32 detail;
    s32 cam;
    u32 s0;
    u32 s1;
    u32 s2;
    s16 *plist;
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_color_variant();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    fade = &m_3c8[cam];
    fade->update();
    vis = fade->updateFromCamera(&m_2fc);
    if (this->mode == 0xC) {
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        if (get_current_floor_area() == AREA_TOWER) {
            detail = classify_actor_view_detail(600.0f, 600.0f, lbl_805DE704);
        } else {
            detail = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, lbl_805DE704);
        }
    } else if (update_object_view_visibility(lbl_805DE700, lbl_805DE704) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail == 0) {
        return;
    }
    if (this->mode != 0xB) {
        Vec v = lbl_80472490;
        draw_ground_shadow(&v, 0);
    }
    update_secondary_light();
    switch (get_phase()) {
    case 1:
        s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
        s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
        s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[4].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[5].texaddr;
        break;
    case 2:
        s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
        s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
        s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[6].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[7].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[8].texaddr;
        break;
    }
    saved_model_render_flags = model_render_flags;
    TObjFish::set_global_param(texlist);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_alpha_ref_override(0);
    TObjEneDD::clear_global_flag_400();
    translate_matrix(0, lbl_805DE70C, m_43c, lbl_805DE70C);
    lbl_805D686C = 0;
    TObjPlayer::toggle_particle_effect();
    if (!(m_438 & 0x10)) {
        plist = ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->sibling->sibling->model)->polygon_list;
        saved = plist[5];
        plist[5] = (u8)plist[5];
        set_chunk_model_node_callback((s32)TObjEneBm9Mericarol::update_particle_effect);
    }
    if (m_438 & 8) {
        if (m_46c.has_visible_opacity() != 0) {
            m_46c.set_flags_and_apply_damage_color();
            if (defer_render() == 0) {
                draw();
            }
            m_46c.clear_flag_and_notify();
        }
    } else if (vis != 0) {
        fade->set_flags_and_apply_damage_color();
        if (defer_render() == 0) {
            if (detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
        }
        fade->clear_flag_and_notify();
    } else if (detail == 1) {
        draw();
    } else {
        draw_motion_model();
    }
    if (!(m_438 & 0x10)) {
        set_chunk_model_node_callback(NULL);
        ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->sibling->model)->polygon_list[5] = saved;
    }
    TParticleCtrl::end_effect_render();
    restore_alpha_ref();
    pop_matrix();
    model_render_flags = saved_model_render_flags;
    update_primary_light();
    if (get_phase() != 0) {
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = s0;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = s1;
        ((NJS_TEXLIST *)texlist)->textures[2].texaddr = s2;
    }
}
