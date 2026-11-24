#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/GinjaMaterialState.h"
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
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/DragonAttackParams.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

// The Re2 flower's draw functions open the flower's translation unit: their
// literal pool (400.0, 25.0, 600.0) repeats values the Lappy
// pool before it already holds, so they are not part of the Lappy file.
extern Vec re2_flower_demo_shadow_scale[];
extern Vec re2_flower_shadow_scale[];
extern s32 re2_flower_node_index;
extern s32 re2_flower_node_yaw;
extern f32 *re2_flower_node_points;
extern const f32 lbl_805D9FAC;
extern const f32 re2_flower_node_point0_y;
extern const f32 re2_flower_node_point1_y;
extern const f32 re2_flower_draw_scale;

// FlowerRe2Data.cpp
extern DragonAttackParams enemy_dd_attack_param_block;
extern DragonAttackParams re2_flower_tower_attack_params;
extern f32 *const re2_flower_movement_params;
extern const f32 lbl_805D9FBC;
extern const f32 lbl_805D9FC0;

void TObjEneRe2Flower::render_demo() {
    s32 save8;
    s32 save14;
    if (update_object_view_visibility(400.0f, 25.0f) == 0) {
        return;
    }
    Vec v = re2_flower_demo_shadow_scale[0];
    draw_ground_shadow(&v, 0);
    if (is_tower_variant() == 0 && is_rare_variant() != 0) {
        save8 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
        save14 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
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
    if (is_tower_variant() == 0 && is_rare_variant() != 0) {
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
        if (is_tower_variant() != 0) {
            visible = classify_actor_view_detail(600.0f, 600.0f, 25.0f);
        } else {
            visible = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 25.0f);
        }
    } else if (update_object_view_visibility(400.0f, 25.0f) != 0) {
        visible = 1;
    } else {
        visible = 0;
    }
    if (visible != 0) {
        if (mode != 10) {
            Vec v = re2_flower_shadow_scale[0];
            draw_ground_shadow(&v, 0);
        }
        update_secondary_light();
        if (is_tower_variant() == 0 && is_rare_variant() != 0) {
            save8 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
            save14 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, base_yaw);
        saved_model_render_flags = model_render_flags;
        set_alpha_ref_override(0);
        TObjEneDD::clear_global_flag_400();
        translate_matrix(0, lbl_805D9FAC, draw_offset_y, lbl_805D9FAC);
        re2_flower_node_yaw = rotation_y - base_yaw;
        re2_flower_node_points = &node_points[0].x;
        node_points[0].x = lbl_805D9FAC;
        node_points[0].y = re2_flower_node_point0_y;
        node_points[0].z = lbl_805D9FAC;
        node_points[1].x = lbl_805D9FAC;
        node_points[1].y = re2_flower_node_point1_y;
        node_points[1].z = lbl_805D9FAC;
        scale_matrix(0, re2_flower_draw_scale, re2_flower_draw_scale, re2_flower_draw_scale);
        set_chunk_model_node_callback(TObjPlayer::update_effect_sequence);
        if (mode == 8) {
            s32 c = (blink_level & 0xFF) << 16;
            re2_flower_node_index = -1;
            TObjPlayer::toggle_particle_effect();
            draw_with_alt_model(c);
            TParticleCtrl::end_effect_render();
        } else {
            re2_flower_node_index = 0;
            TObjPlayer::toggle_particle_effect();
            if (flags & 8) {
                if (appear_fade.has_visible_opacity() != 0) {
                    appear_fade.set_flags_and_apply_damage_color();
                    if (defer_render() == 0) {
                        draw();
                    }
                    appear_fade.clear_flag_and_notify();
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
        if (is_tower_variant() == 0 && is_rare_variant() != 0) {
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = save8;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = save14;
        }
        return;
    }
    node_points[0].x = position.x;
    node_points[0].y = re2_flower_node_point0_y + position.y;
    node_points[0].z = position.z;
    node_points[1].x = position.x;
    node_points[1].y = re2_flower_node_point1_y + position.y;
    node_points[1].z = position.z;
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

}

void TObjEneRe2Flower::notify_bomb_hit() { flags |= 0x2; }

void TObjEneRe2Flower::state_self_destruct(s32 reason) {
    s32 step;
    Vec v;
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        clear_child_flags();
        flags &= ~8;
        set_field_378(8);
        if (!(flags & 4)) {
            flags |= 4;
            state_step = 0;
            target_angle = 0;
            state_timer = 1;
            blink_level = 0;
            hit_cooldown = 0;
        }
        break;
    case 1:
    case 5:
        break;
    case 3:
        if (state_step > 0x1C2) {
            actorFlags |= 0x800;
            transition_enemy_state(0xA);
            VecCopy(&v, &position);
            v.y += lbl_805D9FBC;
            spawn_particle_effect_with_flags(&v, 0xD3, 0x40);
            {
                DragonAttackParams prm = re2_flower_tower_attack_params;
                prm.contact.recoil = prm.power = *re2_flower_movement_params;
                if (is_tower_variant() != 0) {
                    TObjEneDD__sub_800BA5A4(this, &prm);
                } else {
                    TObjEneDD__sub_800BA5A4(this, &enemy_dd_attack_param_block);
                }
            }
            play_sound_effect(remap_sound_for_variant(0x4003A311), &position, 0, 0);
        }
        break;
    case 0:
        advance_animation();
        if (hit_cooldown > 0) {
            hit_cooldown--;
            if (hit_cooldown == 0) {
                clear_attack_receipts();
            }
        }
        if (TObjEneDD::check_v2_mode() != 0) {
            state_step += 0x14;
        } else {
            state_step += 1;
        }
        if (state_step < 0x12C) {
            step = 0x11;
            rotation_y += 0x400;
        } else if (state_step < 0x168) {
            step = 0x22;
            rotation_y += 0x800;
        } else if (state_step < 0x1B3) {
            step = 0x44;
            rotation_y += 0x1000;
        } else {
            step = 0x44;
        }
        if (state_step < 0x1B3) {
            if (state_timer == 0) {
                blink_level += step;
                if (blink_level > 0xFF) {
                    blink_level = 0xFF - (blink_level - 0xFF);
                    state_timer = 1;
                    play_sound_effect(remap_sound_for_variant(0x4003AD10), &position, 0, 0);
                }
            } else {
                blink_level -= step;
                if (blink_level < 0) {
                    blink_level = -blink_level;
                    state_timer = 0;
                }
            }
        } else {
            blink_level = 0xFF;
        }
        update_ground_contact();
        update_body_colliders();
        noop();
        break;
    }
}

void TObjEneRe2Flower::state_laugh(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 6;
        clear_intangible();
        clear_child_flags();
        flags &= ~8;
        set_field_378(3);
        state_step = 0;
        play_sound_effect(remap_sound_for_variant(0x4003A315), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        return;
    case 3:
        if (is_passing_frame(frame_count - lbl_805D9FC0) != 0) {
            transition_enemy_state(3);
        }
        update_ground_contact();
        update_body_colliders();
        return;
    case 0:
        advance_animation();
        state_step++;
        noop();
        return;
    case 5:
        flags &= ~2;
    case 1:
        return;
    }
}

// Literals of the flower file that the units split from it (text_800C2A88, text_800C2CE0, TObjEneRe2Flower.cpp)
// share; they follow this unit's own literals in .sdata2.
__declspec(section ".sdata2") extern const f32 lbl_805D9FAC = 0.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_node_point0_y = 2.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_node_point1_y = 7.0f;
__declspec(section ".sdata2") extern const f32 re2_flower_draw_scale = 1.3f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FBC = 5.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FC0 = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9FC4 = 10.0f;
