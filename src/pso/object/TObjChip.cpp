#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/ChunkMaterialState.h"
#include "pso/system/task/TObject.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"

#include "types.h"
#include "pso/camera/TCameraCtrl.h"

extern "C" {
void draw_ginja_object(void *child);
void set_color_blend_mode(int, int, int, int, s32, s32);
}

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/TObjChip.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };
struct Color_8017FE58 { f32 a; s32 b; s32 c; s32 d; };
extern "C" {
s32 post_translate_matrix(void *);
void project_world_to_screen(int, Vec *, NJS_POINT2 *, Vec *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

#pragma readonly_strings on
const char *obj_chip_class_name_ptr = "TObjChip";

}


// Built with -inline off,deferred: functions are written last to first.

TObjChipSpawnParams *TObjChip::copy_transform(TObjChipSpawnParams *spawn, TObjChipParams *params) {
    TObjChipParams *src = params;
    TObjChipParams &dst = spawn->chip;
    dst.bounce = src->bounce;
    dst.drag = src->drag;
    dst.gravity = src->gravity;
    VecCopy(&spawn->chip.pos, &params->pos);
    VecCopy(&spawn->chip.velocity_range, &params->velocity_range);
    copy_xyz(spawn->chip.spin_range, (void *)params->spin_range);
    dst.count = src->count;
    dst.life = src->life;
    dst.floor_y = src->floor_y;
    dst.scale = src->scale;
    dst.model = src->model;
    dst.textures = src->textures;
    dst.flags = src->flags;
    spawn->pad_54 = 0;
    spawn->angle_y = 0;
    spawn->pad_4C = 0;
    return spawn;
}


TObjChip::TObjChip(TObject *parent, const TObjChipParams *params) : TObject(parent) {
    m_name = obj_chip_class_name_ptr;
    copy_debris_params(&this->params, params);
    pad_1c = 200.0f;
    pad_20 = 40.0f;
    pad_230 = 1;
    if (init_chips() == 0) {
        pad_230 = 0;
    }
}

#pragma push
#pragma scheduling off
void TObjChip::copy_debris_params(TObjChipParams *dst, const TObjChipParams *src) {
    dst->bounce = src->bounce;
    dst->drag = src->drag;
    dst->gravity = src->gravity;
    *reinterpret_cast<ByteBlock_C *>(&dst->pos) = *reinterpret_cast<const ByteBlock_C *>(&src->pos);
    *reinterpret_cast<ByteBlock_C *>(&dst->velocity_range) = *reinterpret_cast<const ByteBlock_C *>(&src->velocity_range);
    *reinterpret_cast<ByteBlock_C *>(dst->spin_range) = *reinterpret_cast<const ByteBlock_C *>(src->spin_range);
    dst->count = src->count;
    dst->life = src->life;
    dst->floor_y = src->floor_y;
    dst->scale = src->scale;
    dst->model = src->model;
    dst->textures = src->textures;
    dst->flags = src->flags;
}
#pragma pop
TObjChip::TObjChip(TObject *parent, TObjChipSpawnParams *params) : TObject(parent) {
    m_name = obj_chip_class_name_ptr;
    copy_debris_params(&this->params, &params->chip);
    pad_1c = 200.0f;
    pad_20 = 40.0f;
    pad_230 = 1;
    if (spawn_chips(&params->pad_4C) == 0) {
        pad_230 = 0;
    }
}
TObjChip::~TObjChip() {}

void TObjChip::run_task() {
    tick_chips();
    if (vfunc_8() == 1) {
        queue_destruction();
    }
}

void TObjChip::render() {
    render_chips();
}

s32 TObjChip::vfunc_8() {
    return pad_230 == 0;
}

#pragma push
#pragma fp_contract on
s32 TObjChip::is_in_view(Vec *center, f32 max_depth, f32 radius) {
    Vec v;
    NJS_POINT2 o1;
    NJS_POINT2 o2;
    matrix_mult_vec(0, center, &v);
    if (v.z > 0.0f) {
        return 0;
    }
    if (v.z < -max_depth) {
        return 0;
    }
    if (v.x < 0.0f) {
        v.x = center->x - camera_right.x * radius;
        v.y = center->y + camera_right.y * radius;
        v.z = center->z + camera_right.z * radius;
        project_world_to_screen(0, &v, &o1, &camera_right);
        if (o1.x < 0.0f) {
            return 0;
        }
    } else {
        v.x = center->x + camera_right.x * radius;
        v.y = center->y - camera_right.y * radius;
        v.z = center->z - camera_right.z * radius;
        project_world_to_screen(0, &v, &o2, &camera_right);
        if (o2.x > 640.0f) {
            return 0;
        }
    }
    return 1;
}
#pragma pop
#pragma push
#pragma fp_contract on
s32 TObjChip::init_chips() {
    TObjChipPiece *c;
    s32 i;
    f32 v;
    if (params.count > 8) {
        return 0;
    }
    c = pieces;
    for (i = 0; i < params.count; i++, c++) {
        VecCopy(&c->pos, &params.pos);
        v = params.velocity_range.x;
        c->velocity.x = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->velocity.y = params.velocity_range.y * ((3.0517578e-05f) * (f32)rand());
        v = params.velocity_range.z;
        c->velocity.z = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->rotation[2] = c->rotation[1] = c->rotation[0] = 0;
        c->angular_velocity[0] = (s32)((f32)params.spin_range[0] * ((3.0517578e-05f) * (f32)rand()));
        c->angular_velocity[1] = (s32)((f32)params.spin_range[1] * ((3.0517578e-05f) * (f32)rand()));
        c->angular_velocity[2] = (s32)((f32)params.spin_range[2] * ((3.0517578e-05f) * (f32)rand()));
        c->alpha = (1.0f);
        c->life = params.life;
    }
    return 1;
}
#pragma pop
#pragma push
#pragma fp_contract on
s32 TObjChip::spawn_chips(s32 *rotation) {
    TObjChipPiece *c;
    s32 i;
    f32 v;
    if (params.count > 8) {
        return 0;
    }
    c = pieces;
    for (i = 0; i < params.count; i++, c++) {
        VecCopy(&c->pos, &params.pos);
        v = params.velocity_range.x;
        c->velocity.x = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->velocity.y = params.velocity_range.y * ((3.0517578e-05f) * (f32)rand());
        v = params.velocity_range.z;
        c->velocity.z = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->rotation[0] = rotation[0];
        c->rotation[1] = rotation[1];
        c->rotation[2] = rotation[2];
        c->angular_velocity[0] = (s32)((f32)params.spin_range[0] * ((3.0517578e-05f) * (f32)rand()));
        c->angular_velocity[1] = (s32)((f32)params.spin_range[1] * ((3.0517578e-05f) * (f32)rand()));
        c->angular_velocity[2] = (s32)((f32)params.spin_range[2] * ((3.0517578e-05f) * (f32)rand()));
        c->alpha = (1.0f);
        c->life = params.life;
    }
    return 1;
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjChip::tick_chips() {
    s32 active;
    TObjChipPiece *c;
    s32 i;
    c = pieces;
    active = 0;
    for (i = 0; i < params.count; i++, c++) {
        if (c->life == 0) {
            if (!(params.flags & 4)) {
                continue;
            }
            c->alpha -= (0.1f);
            if (c->alpha > (0.0f)) {
                active++;
            }
        } else {
            c->life--;
            active++;
        }
        c->velocity.x = -c->velocity.x * params.drag + c->velocity.x;
        c->velocity.y = c->velocity.y + ((0.1f) * -c->velocity.y - params.gravity);
        c->velocity.z = -c->velocity.z * params.drag + c->velocity.z;
        c->pos.x += c->velocity.x;
        c->pos.y += c->velocity.y;
        c->pos.z += c->velocity.z;
        c->rotation[0] += c->angular_velocity[0];
        c->rotation[1] += c->angular_velocity[1];
        c->rotation[2] += c->angular_velocity[2];
        if ((params.flags & 2) && c->pos.y < params.floor_y && c->velocity.y < (0.0f)) {
            c->pos.y = params.floor_y;
            c->velocity.x *= (0.9f);
            c->velocity.y *= -params.bounce;
            c->velocity.z *= (0.9f);
            c->angular_velocity[0] = (s32)((0.5f) * (f32)c->angular_velocity[0]);
            c->angular_velocity[1] = (s32)((0.5f) * (f32)c->angular_velocity[1]);
            c->angular_velocity[2] = (s32)((0.5f) * (f32)c->angular_velocity[2]);
        }
    }
    if (active == 0) {
        pad_230 = 0;
    }
}
#pragma pop
void TObjChip::render_chips() {
    TObjFish::set_global_param(params.textures);
    if (params.flags & 0x10) {
        vfunc_12();
        return;
    }
    draw_chips();
}
void TObjChip::draw_chips() {
    TObjChipPiece *c = pieces;
    if (params.flags & 8) {
        if (params.flags & 4) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            model_render_flags = model_render_flags | 0x810;
            set_chunk_material_override_pair(-1, 0x800);
            for (s32 i = 0; i < params.count; i++, c++) {
                Color_8017FE58 col = { 0.0f, 0x3F800000, 0x3F800000, 0x3F800000 };
                col.a = c->alpha;
                set_constant_material((const NJS_ARGB *)(((f32 *)&col)));
                push_matrix();
                post_translate_matrix(&c->pos);
                rotate_matrix_yxz(0, c->rotation[0], c->rotation[1], c->rotation[2]);
                scale_matrix(0, params.scale, params.scale, params.scale);
                draw_chunk_object(params.model);
                pop_matrix();
                set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            }
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        } else {
            for (s32 i = 0; i < params.count; i++, c++) {
                push_matrix();
                post_translate_matrix(&c->pos);
                rotate_matrix_yxz(0, c->rotation[0], c->rotation[1], c->rotation[2]);
                scale_matrix(0, params.scale, params.scale, params.scale);
                draw_chunk_object(params.model);
                pop_matrix();
            }
        }
    } else if (params.flags & 4) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags = model_render_flags | 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        for (s32 i = 0; i < params.count; i++, c++) {
            Color_8017FE58 col = { 0.0f, 0x3F800000, 0x3F800000, 0x3F800000 };
            col.a = c->alpha;
            set_constant_material((const NJS_ARGB *)(((f32 *)&col)));
            push_matrix();
            post_translate_matrix(&c->pos);
            rotate_matrix_yxz(0, c->rotation[0], c->rotation[1], c->rotation[2]);
            scale_matrix(0, params.scale, params.scale, params.scale);
            draw_chunk_object(params.model);
            pop_matrix();
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        }
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    } else {
        for (s32 i = 0; i < params.count; i++, c++) {
            push_matrix();
            post_translate_matrix(&c->pos);
            rotate_matrix_yxz(0, c->rotation[0], c->rotation[1], c->rotation[2]);
            scale_matrix(0, params.scale, params.scale, params.scale);
            draw_chunk_object(params.model);
            pop_matrix();
        }
    }
}
void TObjChip::vfunc_12() {
    TObjChipPiece *p = pieces;
    s32 i;
    s32 j;
    if (params.flags & 4) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x8011;
        set_color_blend_mode(1, 4, 5, 0, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask);
        for (i = 0; i < params.count; i++, p++) {
            NJS_ARGB color = { p->alpha, 1.0f, 1.0f, 1.0f };
            set_constant_material(&color);
            push_matrix();
            post_translate_matrix(&p->pos);
            rotate_matrix_yxz(0, p->rotation[0], p->rotation[1], p->rotation[2]);
            scale_matrix(0, params.scale, params.scale, params.scale);
            draw_ginja_object(params.model);
            pop_matrix();
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        }
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    } else {
        for (j = 0; j < params.count; j++, p++) {
            push_matrix();
            post_translate_matrix(&p->pos);
            rotate_matrix_yxz(0, p->rotation[0], p->rotation[1], p->rotation[2]);
            scale_matrix(0, params.scale, params.scale, params.scale);
            draw_ginja_object(params.model);
            pop_matrix();
        }
    }
}
