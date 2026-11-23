#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/TEF_LensFlare.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "pso/effect/TEF_PvrWave.h"
#include "pso/unk/TTextureWave.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

__declspec(section ".rodata") extern const char lens_flare_class_name_string[] = "TEF_LensFlare";
const char *TEF_LensFlare::class_name = lens_flare_class_name_string;

// The reflections the constructor hands to every flare (render() draws the first nine).
LensFlareElement lens_flare_reflected_element_descriptors[10] = {
    {1, 0.1f, 0.8f, 0.0f, 0.7f, -10.0f},
    {2, 0.4f, 0.6f, 0.5f, 0.7f, -10.1f},
    {3, 0.6f, 0.8f, 0.6f, 0.7f, -10.2f},
    {1, 0.8f, 1.2f, 0.6f, 0.4f, -10.3f},
    {3, 1.0f, 1.2f, -0.3f, 0.7f, -10.4f},
    {4, 1.2f, 0.7f, 1.0f, 0.7f, -10.5f},
    {2, 1.4f, 1.7f, 0.0f, 0.7f, -10.6f},
    {5, 1.5f, 0.6f, 1.0f, 0.7f, -10.7f},
    {6, 1.8f, 1.5f, 0.0f, 0.7f, -10.8f},
    {2, 0.0f, 4.0f, 2.0f, 0.4f, -10.9f},
};

TEF_LensFlare::~TEF_LensFlare() {

}

#pragma push
#pragma opt_propagation off
void TEF_LensFlare::render() {
    Vec *sprite_pos;
    if (TMainTask::get_render_pass() != 0 && camera_ctrl_instance != NULL) {
        QuadSpriteNode sprite_storage;
        QuadSpriteNode *sprite = &sprite_storage;
        sprite->pos.x = 0.0f;
        sprite->pos.y = 0.0f;
        sprite->pos.z = 0.0f;
        sprite->offset.x = 0.0f;
        sprite->offset.y = 0.0f;
        sprite->offset.z = 0.0f;
        sprite->scale_x = 0.0f;
        sprite->scale_y = 0.0f;
        sprite->color = 0;
        sprite->uv_index = 0;
        sprite->angle = 0;
        sprite_pos = &sprite_storage.pos;
        set_additive_blend();
        if (scale.x >= 0.0f) {
            f32 range = 10.0f * scale.x;
            if (is_player_out_of_range(range * range)) {
                return;
            }
        }
        TParticleCtrl::begin_effect_render();
        Vec dir;
        dir.x = position.x - camera_ctrl_instance->pos.x;
        dir.y = position.y - camera_ctrl_instance->pos.y;
        dir.z = position.z - camera_ctrl_instance->pos.z;
        if (0.0f != vec_squared_length(&dir)) {
            normalize_vector(&dir);
        }
        push_matrix_from(&identity_matrix);
        Vec view;
        Vec forward = {0.0f, 0.0f, -1.0f};
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
        rotate_matrix_x(0, camera_ctrl_instance->pitch);
        rotate_vector_by_matrix(0, &forward, &view);
        pop_matrix();
        f32 dx, dy, fade, t;
        f32 d = vec3_dot(&view, &dir);
        if (d > 0.0f) {
            set_depth_buffer_settings_1();
            f32 screen[2];
            project_world_to_screen(0, &position, screen);
            Vec at;
            if (d > 0.99f) {
                f32 s = 50.0f * (d - 0.98f);
                s *= s;
                FlareGlareColor glow;
                glow.argb.r = 0xFF;
                glow.argb.g = 0xFF;
                glow.argb.b = 0xFF;
                glow.argb.a = 255.0f * (0.9f * s);
                at.x = screen[0];
                at.y = screen[1];
                at.z = 0.0f;
                __memcpy(&sprite->color, &glow, sizeof(glow));
                VecCopy(sprite_pos, &at);
                sprite->scale_x = 20.0f * s;
                sprite->scale_y = sprite->scale_x;
                begin_screen_draw(1);
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(particle_definitions[15].texlist));
                set_draw_texture_and_color(particle_definitions[15].texture, -1);
                f32 x = at.x;
                f32 y = at.y;
                f32 sx;
                f32 two;
                f32 w = particle_definitions[15].width;
                f32 h = particle_definitions[15].height;
                two = 2.0f;
                sx = two * sprite->scale_x;
                f32 sy = two * sprite->scale_y;
                w *= sx;
                h *= sy;
                f32 quad[8];
                quad[0] = x - w;
                quad[2] = x + w;
                quad[1] = y - h;
                quad[3] = y + h;
                quad[4] = 0.0f;
                quad[5] = 0.0f;
                quad[6] = 1.0f;
                quad[7] = 1.0f;
                set_constant_material_color(sprite->color);
                draw_textured_quad_at_depth(quad, 0.5f);
                TWindowSubStatusDisp::get_player();
            }

            if (d > 0.6f) {
                t = 3.0f * (d - 0.6f);
            } else {
                t = 0.0f;
            }
            FlareColor white;
            white.argb.a = 0xFF;
            white.argb.r = 0xFF;
            white.argb.g = 0xFF;
            white.argb.b = 0xFF;
            t *= t * t * t;
            __memcpy(&sprite->color, &white, sizeof(white));
            const f32 screen_x = screen[0];
            dx = 320.0f - screen_x;
            at.x = screen_x;
            const f32 screen_y = screen[1];
            dy = 240.0f - screen_y;
            at.y = screen_y;
            at.z = 0.0f;
            VecCopy(sprite_pos, &at);
            sprite->scale_x = 1.0f;
            sprite->scale_y = sprite->scale_x;
            begin_screen_draw(1);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(particle_definitions[9].texlist));
            set_draw_texture_and_color(particle_definitions[9].texture, -1);
            f32 x = at.x;
            f32 y = at.y;
            f32 sx;
            f32 two;
            f32 w = particle_definitions[9].width;
            f32 h = particle_definitions[9].height;
            two = 2.0f;
            sx = two * sprite->scale_x;
            f32 sy = two * sprite->scale_y;
            w *= sx;
            h *= sy;
            f32 quad[8];
            quad[0] = x - w;
            quad[2] = x + w;
            quad[1] = y - h;
            quad[3] = y + h;
            quad[4] = 0.0f;
            quad[5] = 0.0f;
            quad[6] = 1.0f;
            quad[7] = 1.0f;
            set_constant_material_color(sprite->color);
            draw_textured_quad_at_depth(quad, 0.5f);
            TWindowSubStatusDisp::get_player();
            s32 i;
            LensFlareElement *e = elements;
            fade = 1.0f - t;
            i = 0;
            while (i++ < 9) {
                f32 size = e->size * (1.0f - fade * e->shrink);
                if (size < 0.0f) {
                    size = 0.0f;
                }
                FlareColor tint;
                tint.argb.r = 0xFF;
                tint.argb.g = 0xFF;
                tint.argb.b = 0xFF;
                tint.argb.a = (s32)(255.0f * (t * e->brightness));
                __memcpy(&sprite->color, &tint, sizeof(tint));
                at.x = dx * e->position + screen[0];
                at.y = dy * e->position + screen[1];
                at.z = 0.0f;
                VecCopy(sprite_pos, &at);
                sprite->scale_x = size;
                sprite->scale_y = sprite->scale_x;
                begin_screen_draw(1);
                NJS_TEXLIST *texlist = particle_definitions[9 + e->sprite].texlist;
                TObjFish::set_global_param(texlist);
                set_draw_texture_and_color(particle_definitions[9 + e->sprite].texture, -1);
                f32 sy;
                f32 sx = 2.0f * sprite->scale_x;
                const f32 x = at.x;
                f32 w = particle_definitions[9 + e->sprite].width;
                f32 h = particle_definitions[9 + e->sprite].height;
                sy = 2.0f * sprite->scale_y;
                h *= sy;
                f32 quad[8];
                quad[4] = 0.0f;
                w *= sx;
                quad[0] = x - w;
                quad[5] = 0.0f;
                quad[6] = 1.0f;
                quad[2] = x + w;
                quad[1] = at.y - h;
                quad[3] = at.y + h;
                quad[7] = 1.0f;
                set_constant_material_color(sprite->color);
                draw_textured_quad_at_depth(quad, 0.5f);
                TWindowSubStatusDisp::get_player();
                ++e;
            }
            restore_saved_depth_alpha_state();
        }
        TParticleCtrl::end_effect_render();
    }
}
#pragma pop


TEF_LensFlare::TEF_LensFlare(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    elements = lens_flare_reflected_element_descriptors;
}

void TEF_LensFlare::run_task() {  }
void TEF_PvrWave::render() {  }

void TEF_PvrWave::run_task() {
    wave->update_texture_wave_image();
}

