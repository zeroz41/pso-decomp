#include "types.h"
#include "pso/effect/TEF_LensFlare.h"
#include "pso/effect/TEF_PvrWave.h"
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

struct Base_8008194C_80081278 { char pad[0x50]; };
struct VObj_8008194C_80081278 : Base_8008194C_80081278 {
    virtual void m0();
    virtual void m1();
};

struct RecoveredGlobal_800818D8_lbl_8048E130 {
    s32 value;
    u8 remaining[0x34];
};

// The reflections TEF_LensFlare__ct hands to every flare (render() draws the first nine).
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

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__13TEF_LensFlare[];
extern s32 TEF_LensFlare__class_name;
u8 *TEF_LensFlare__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__13TEF_LensFlareFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

}
TEF_LensFlare::~TEF_LensFlare() {

}

// A screen sprite as the particle code keeps it: position, offset, scale,
// ARGB colour, animation frame and angle (layout of the particle tail at 0x70).
struct FlareSprite {
    Vec pos;
    Vec offset;
    f32 scale_x;
    f32 scale_y;
    u32 color;
    u8 frame;
    s16 angle;

    FlareSprite() {
        pos.x = 0.0f;
        pos.y = 0.0f;
        pos.z = 0.0f;
        offset.x = 0.0f;
        offset.y = 0.0f;
        offset.z = 0.0f;
        scale_x = 0.0f;
        scale_y = 0.0f;
        color = 0;
        frame = 0;
        angle = 0;
    }
};


// An entry of the particle sprite table (lbl_804C5820, 0x28 bytes each).
struct FlareSpriteTexture {
    u32 flags;
    s32 param;
    s32 tex;
    u8 pad_c[0x8];
    f32 sx;
    f32 sy;
    u8 pad_1c[0xC];
};

struct FlareQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

extern "C" {
extern TCameraCtrl *camera_ctrl_instance;
extern FlareSpriteTexture lbl_804C5820[];
void normalize_vector(Vec *v);
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TEF_LensFlare::render() {
    if (TMainTask::get_render_pass() != 0 && camera_ctrl_instance != NULL) {
        FlareSprite sprite;
        set_additive_blend();
        if (scale.x >= 0.0f) {
            f32 range = 10.0f * scale.x;
            if (is_player_near(range * range)) {
                return;
            }
        }
        TParticleCtrl::begin_effect_render();
        Vec dir;
        dir.x = position.x - camera_ctrl_instance->pos_x;
        dir.y = position.y - camera_ctrl_instance->pos_y;
        dir.z = position.z - camera_ctrl_instance->pos_z;
        if (vec_squared_length(&dir) != 0.0f) {
            normalize_vector(&dir);
        }
        push_matrix_from(&identity_matrix);
        Vec view;
        Vec forward = {0.0f, 0.0f, -1.0f};
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
        rotate_matrix_x(0, camera_ctrl_instance->pitch);
        rotate_vector_by_matrix(0, &forward, &view);
        pop_matrix();
        f32 d = vec3_dot(&view, &dir);
        if (d > 0.0f) {
            f32 screen[2];
            Vec at;
            f32 t;
            f32 dx;
            f32 dy;
            s32 i;
            LensFlareElement *e;

            set_depth_buffer_settings_1();
            project_world_to_screen(0, &position, screen);
            if (d > 0.99f) {
                NJS_COLOR glow;
                FlareQuad quad;
                f32 w;
                f32 h;
                f32 s = 50.0f * (d - 0.98f);
                s = s * s;
                glow.argb.r = 0xFF;
                glow.argb.g = 0xFF;
                glow.argb.b = 0xFF;
                at.x = screen[0];
                at.y = screen[1];
                at.z = 0.0f;
                glow.argb.a = 255.0f * (0.9f * s);
                sprite.color = glow.color;
                VecCopy(&sprite.pos, &at);
                sprite.scale_x = sprite.scale_y = 20.0f * s;
                begin_screen_draw(1);
                TObjFish::set_global_param(lbl_804C5820[15].param);
                set_draw_texture_and_color(lbl_804C5820[15].tex, -1);
                w = lbl_804C5820[15].sx * (2.0f * sprite.scale_x);
                h = lbl_804C5820[15].sy * (2.0f * sprite.scale_y);
                quad.x0 = at.x - w;
                quad.x1 = at.x + w;
                quad.y0 = at.y - h;
                quad.y1 = at.y + h;
                quad.u0 = 0.0f;
                quad.v0 = 0.0f;
                quad.u1 = 1.0f;
                quad.v1 = 1.0f;
                set_constant_material_color(sprite.color);
                draw_textured_quad_at_depth(&quad.x0, 0.5f);
                TWindowSubStatusDisp::get_player();
            }
            if (d > 0.6f) {
                t = 3.0f * (d - 0.6f);
            } else {
                t = 0.0f;
            }
            {
                NJS_COLOR white;
                FlareQuad quad;
                f32 w;
                f32 h;
                t = t * t * t * t;
                dx = 320.0f - screen[0];
                dy = 240.0f - screen[1];
                white.argb.a = 0xFF;
                white.argb.r = 0xFF;
                white.argb.g = 0xFF;
                white.argb.b = 0xFF;
                at.x = screen[0];
                sprite.color = white.color;
                at.y = screen[1];
                at.z = 0.0f;
                VecCopy(&sprite.pos, &at);
                sprite.scale_x = sprite.scale_y = 1.0f;
                begin_screen_draw(1);
                TObjFish::set_global_param(lbl_804C5820[9].param);
                set_draw_texture_and_color(lbl_804C5820[9].tex, -1);
                w = lbl_804C5820[9].sx * (2.0f * sprite.scale_x);
                h = lbl_804C5820[9].sy * (2.0f * sprite.scale_y);
                quad.x0 = at.x - w;
                quad.x1 = at.x + w;
                quad.y0 = at.y - h;
                quad.y1 = at.y + h;
                quad.u0 = 0.0f;
                quad.v0 = 0.0f;
                quad.u1 = 1.0f;
                quad.v1 = 1.0f;
                set_constant_material_color(sprite.color);
                draw_textured_quad_at_depth(&quad.x0, 0.5f);
                TWindowSubStatusDisp::get_player();
            }
            e = elements;
            for (i = 0; i < 9; i++) {
                NJS_COLOR tint;
                FlareQuad quad;
                f32 w;
                f32 h;
                f32 size = e->size * (1.0f - (1.0f - t) * e->shrink);
                if (size < 0.0f) {
                    size = 0.0f;
                }
                tint.argb.r = 0xFF;
                tint.argb.g = 0xFF;
                tint.argb.b = 0xFF;
                tint.argb.a = 255.0f * (t * e->brightness);
                sprite.color = tint.color;
                at.x = dx * e->position + screen[0];
                at.y = dy * e->position + screen[1];
                at.z = 0.0f;
                VecCopy(&sprite.pos, &at);
                sprite.scale_y = sprite.scale_x = size;
                begin_screen_draw(1);
                TObjFish::set_global_param(lbl_804C5820[e->sprite + 9].param);
                set_draw_texture_and_color(lbl_804C5820[e->sprite + 9].tex, -1);
                w = lbl_804C5820[e->sprite + 9].sx * (2.0f * sprite.scale_x);
                h = lbl_804C5820[e->sprite + 9].sy * (2.0f * sprite.scale_y);
                quad.x0 = at.x - w;
                quad.x1 = at.x + w;
                quad.y0 = at.y - h;
                quad.y1 = at.y + h;
                quad.u0 = 0.0f;
                quad.v0 = 0.0f;
                quad.u1 = 1.0f;
                quad.v1 = 1.0f;
                set_constant_material_color(sprite.color);
                draw_textured_quad_at_depth(&quad.x0, 0.5f);
                TWindowSubStatusDisp::get_player();
                e++;
            }
            restore_saved_depth_alpha_state();
        }
        TParticleCtrl::end_effect_render();
    }
}
extern "C" {

typedef char RecoveredGlobal_800818D8_lbl_8048E130_size[sizeof(RecoveredGlobal_800818D8_lbl_8048E130) == 0x38 ? 1 : -1];
u8 *TEF_LensFlare__ct(u8 *ef_lens_flare, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)ef_lens_flare, (void *)parent);
    *(s32 **)((s8 *)ef_lens_flare + 0x18) = &(*(RecoveredGlobal_800818D8_lbl_8048E130 *)&__vt__13TEF_LensFlare).value;
    *(s32 *)((s8 *)ef_lens_flare + 0) = (s32) TEF_LensFlare__class_name;
    ((TEF_LensFlare *)(ef_lens_flare))->apply_object_set_data((void *)arg2);
    ((TEF_LensFlare *)ef_lens_flare)->elements = lens_flare_reflected_element_descriptors;
    return ef_lens_flare;
}

void TEF_LensFlare::run_task() {  }
void TEF_PvrWave::render() {  }

void TEF_PvrWave::run_task() {
    struct VObj_8008194C_80081278 *o = (struct VObj_8008194C_80081278 *)*(void **)((s8 *)this + 0x1C);
    o->m1();
}

}
