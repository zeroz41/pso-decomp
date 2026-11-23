#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/render/render_util.h"
#include "pso/effect/particle/LightGlare.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticle.h"
#include "pso/effect/particle/TParticleBallistic.h"


#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/network/client_id.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/PlayerSlots.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/sprite/TQuadSprite.h"

#pragma defer_codegen on

s32 light_glare_enabled = 1;

TLightGlare::TLightGlare(void *set_data, TObject *parent) : TObjBase(parent) {
    apply_object_set_data(set_data);
    alpha = 225.0f;
    light_glare_enabled = 1;
}

TLightGlare::~TLightGlare() {

}

#pragma fp_contract on
void TLightGlare::run_task() {
    Vec forward;
    Vec to_glare;
    f32 strength;
    f32 alignment;
    if (camera_ctrl_instance != NULL) {
        to_glare.x = position.x - camera_ctrl_instance->pos.x;
        to_glare.y = 0.0f;
        to_glare.z = position.z - camera_ctrl_instance->pos.z;
        if (0.0f != vec_squared_length(&to_glare)) {
            normalize_vector(&to_glare);
        }
        push_matrix_from(identity_matrix);
        Vec ahead = { 0.0f, 0.0f, -1.0f };
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
        rotate_vector_by_matrix(0, &ahead, &forward);
        pop_matrix();
        facing = vec3_dot(&forward, &to_glare);
        alignment = fabs_float(facing);
        if (facing >= 0.0f) {
            strength = fabs_float(1.0f - alignment);
            if (strength > 0.6f) {
                strength = 0.6f;
            }
        } else {
            strength = 0.0f;
        }
        glare_size = 50.0f * strength + 25.0f;
        Vec eye = camera_ctrl_instance->pos;
        if (csnVector(&eye, &position, 0x100) != 0) {
            occluded = 1;
        } else {
            occluded = 0;
        }
    }
}

#pragma fp_contract reset
void TLightGlare::render() {
    NJS_COLOR color;
    QuadSpriteRect quad;
    f32 limit;
    f32 v;
    f32 size;
    f32 w;
    f32 h;

    limit = 225.0f;
    if (light_glare_enabled == 0) {
        return;
    }
    if (occluded != 0) {
        limit = 50.0f;
    }
    if (alpha < limit) {
        v = 3.0f + alpha;
        alpha = v < 0.0f ? 0.0f : (v < limit ? v : limit);
    } else {
        v = alpha - 3.0f;
        alpha = v < limit ? limit : (v < 255.0f ? v : 255.0f);
    }
    TParticleCtrl::begin_effect_render();
    if (facing > 0.0f) {
        project_world_to_screen(0, &position, screen_position);
        if (screen_position[0] > 650.0f) {
            screen_position[0] = 650.0f;
        }
        if (screen_position[0] < -10.0f) {
            screen_position[0] = -10.0f;
        }
        if (screen_position[1] > 490.0f) {
            screen_position[1] = 490.0f;
        }
        if (screen_position[1] < -10.0f) {
            screen_position[1] = -10.0f;
        }
    }
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(particle_definitions[31].texlist));
    set_draw_texture_and_color(particle_definitions[31].texture, -1);
    if (facing < 0.0f) {
        color.argb.a = 0;
    } else if (facing <= 0.5f) {
        v = facing * (2.5f * alpha);
        color.argb.a = v < 0.0f ? 0.0f : (v < 255.0f ? v : 255.0f);
    } else {
        color.argb.a = alpha;
    }
    if (scale.x < 0.0f) {
        color.argb.r = 0x80;
        color.argb.g = 0x80;
        color.argb.b = 0x80;
    } else if (scale.x >= 10.0f) {
        color.argb.r = 0x55;
        color.argb.g = 0x23;
        color.argb.b = 0;
    } else {
        color.argb.r = 0xFF;
        color.argb.g = 0x80;
        color.argb.b = 0x40;
    }
    w = particle_definitions[31].width;
    h = particle_definitions[31].height;
    size = 0.5f * glare_size;
    w *= size;
    h *= size;
    quad.x0 = screen_position[0] - w;
    quad.x1 = screen_position[0] + w;
    quad.y0 = screen_position[1] - h;
    quad.y1 = screen_position[1] + h;
    quad.u0 = 0.0f;
    quad.v0 = 0.0f;
    quad.u1 = 1.0f;
    quad.v1 = 1.0f;
    set_constant_material_color(color.color);
    draw_textured_quad_at_depth(&quad.x0, 0.1f);
    TWindowSubStatusDisp::get_player();
    TParticleCtrl::end_effect_render();
}

void *TLightGlare::create(void *set_data) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TLightGlare(set_data, tl_particle);
}

void *TLightGlareSwitch::create(void *set_data) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TLightGlareSwitch(set_data, tl_particle);
}

TLightGlareSwitch::TLightGlareSwitch(void *set_data, TObject *parent) : TObjBase(parent) {
    apply_object_set_data(set_data);
}

TLightGlareSwitch::~TLightGlareSwitch() {

}

void TLightGlareSwitch::run_task() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL && horizontal_distance_squared(&player->position, &position) < 400.0f) {
        if (scale.x > 0.0f) {
            light_glare_enabled = 1;
            return;
        }
        light_glare_enabled = 0;
    }
}

void TLightGlareSwitch::render() {
    if (TObjPlayer::check_demo_mode() != 0) {
        NJS_ARGB color = { 0.5f, 0.0f, 1.0f, 1.0f };
        debug_draw_sphere(&position, &color, 40.0f);
    }
}
