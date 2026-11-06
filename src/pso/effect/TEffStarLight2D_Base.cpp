#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/TEffStarLight2D_Base.h"
#include "pso/effect/TEffStarLight2D.h"
#include "pso/effect/TEffStarLightChild.h"
#include "types.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

extern "C" {
extern TObject *tl_particle;
}
void set_additive_blend();
void set_default_alpha_blend();

extern const char TEffStarLightChild_class_name[] = "TEffStarLightChild";
extern const char TEffStarLight2D_class_name[] = "TEffStarLight2D";
const char *TEffStarLightChild__name = TEffStarLightChild_class_name;
const char *TEffStarLight2D__name = TEffStarLight2D_class_name;

__declspec(section ".rodata") NJS_ARGB star_light_2d_base_color = {0.5f, 1.0f, 1.0f, 1.0f};


struct Vec_800851B0 { f32 x; f32 y; f32 z; };

struct P2_800851B0 { f32 x; f32 z; };

struct Star_800851B0 {
    u8 pad0[0x1C];
    f32 curX;
    f32 curZ;
    f32 prevX;
    f32 prevZ;
    Vec_800851B0 pos;
    f32 f38;
    f32 f3C;
};

struct O_80085388 { const char *f0; u8 pad4[0x14]; void *vptr; f32 f1c; f32 f20; f32 f24; f32 f28; };

struct P2_80085388 { f32 x; f32 z; };


struct Star_80085424 {
    u8 pad0[0x1C];
    f32 angle;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
};

struct Vec_800855F8 { f32 x, y, z; };

struct Pt_800855F8 { f32 x, y; };

struct Star_800855F8 {
    const char *name;
    u8 pad4[0x18 - 0x4];
    void *vt;
    f32 angle;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
};

extern "C" {
void *__nw__7TObjectFUl(u32);
void matrix_mult_vec(int, void *, void *);
void __ct__7TObjectFP7TObject(void *, void *);
void project_world_to_screen(int, void *, void *);
void queue_destruction__7TObjectFv(void *arg0);
f32 vector_length(void *);
s32 normalize_vector(void *);
f32 newton_sqrtf(f32);
extern void *__vt__18TEffStarLightChild[];
void run_task__15TEffStarLight2DFv(Star_800851B0 *self);
void run_task__18TEffStarLightChildFv(Star_80085424 *self);
Star_800855F8 *__ct__18TEffStarLightChildFv(Star_800855F8 *self, Pt_800855F8 *a, Pt_800855F8 *b, void *parent, f32 w, f32 speed);
}

#pragma defer_codegen on

#pragma push
#pragma fp_contract on
Star_800855F8 *__ct__18TEffStarLightChildFv(Star_800855F8 *self, Pt_800855F8 *a, Pt_800855F8 *b, void *parent, f32 w, f32 speed) {
    Vec_800855F8 d;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__18TEffStarLightChild;
    self->name = TEffStarLightChild__name;
    if (speed <= 0.0f) {
        speed = 1.0f;
    }
    d.x = b->x - a->x;
    d.y = b->y - a->y;
    d.z = 0.0f;
    if (0.0f != vector_length(&d)) {
        normalize_vector(&d);
    } else {
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
    }
    self->x0 = d.y * w + b->x;
    self->y0 = d.x * w + b->y;
    self->x1 = -d.y * w + b->x;
    self->y1 = -d.x * w + b->y;
    if (self->y0 <= self->y1) {
        f32 t0 = self->y0;
        f32 t1 = self->y1;
        self->y1 = t0;
        self->y0 = t1;
    }
    self->angle = newton_sqrtf((self->x0 - self->x1) * (self->x0 - self->x1) + (self->y0 - self->y1) * (self->y0 - self->y1)) / 2.0f / speed;
    return self;
}
#pragma pop

TEffStarLightChild::~TEffStarLightChild() {}

void run_task__18TEffStarLightChildFv(Star_80085424 *self) {
    Vec a;
    Vec b;
    Vec c;
    s32 inside = 0;
    c.z = 0.0f;
    c.x = 0.5f * (self->x0 + self->x1);
    c.y = 0.5f * (self->y0 + self->y1);
    a.z = 0.0f;
    a.x = self->x0;
    a.y = self->y0;
    b.z = 0.0f;
    b.x = self->x1;
    b.y = self->y1;
    approach_vector_fixed_distance(&a, &c, &a, self->angle);
    self->x0 = a.x;
    self->y0 = a.y;
    approach_vector_fixed_distance(&b, &c, &b, self->angle);
    self->x1 = b.x;
    self->y1 = b.y;
    if (self->x0 >= -100.0f && self->x0 <= 740.0f) {
        if (self->y0 >= -100.0f && self->y0 <= 580.0f) {
            if (self->x1 >= -100.0f && self->x1 <= 740.0f) {
                if (self->y1 >= -100.0f && self->y1 <= 580.0f) {
                    inside = 1;
                }
            }
        }
    }
    if (inside == 0) {
        queue_destruction__7TObjectFv(self);
    } else if (c.x == b.x && c.y == b.y) {
        queue_destruction__7TObjectFv(self);
    }
}

void TEffStarLightChild::render() {  }

#pragma push
#pragma opt_common_subs off
TEffStarLight2D::TEffStarLight2D(void *arg1, void *arg2, TObject *object) : TObject(object) {
    P2_80085388 p;
    ((O_80085388 *)this)->f0 = TEffStarLight2D__name;
    ((TEffStarLight2D *)((u8 *)this + 0x38))->copy_from(arg2);
    VecCopy((Vec *)((u8 *)this + 0x2C), (const Vec *)arg1);
    project_world_to_screen(0, (u8 *)this + 0x2C, &p);
    ((O_80085388 *)this)->f24 = p.x;
    ((O_80085388 *)this)->f28 = p.z;
    ((O_80085388 *)this)->f1c = ((O_80085388 *)this)->f24;
    ((O_80085388 *)this)->f20 = ((O_80085388 *)this)->f28;
}

#pragma pop

TEffStarLight2D::~TEffStarLight2D() {}

void TEffStarLight2D::copy_from(void* q) { *(f32 *)&this->m_name = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(u8 *)&this->m_prev = *(u8*)((char*)q + 0x8); *(u8*)((char*)this + 0x9) = *(u8*)((char*)q + 0x9); *(u8*)((char*)this + 0xa) = *(u8*)((char*)q + 0xa); *(u8*)((char*)this + 0xb) = *(u8*)((char*)q + 0xb); *(u32 *)&this->m_next = *(u32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); }

void TEffStarLight2D::copy_from_subobject(void* a1) { ((TEffStarLight2D *)((char*)this + 0x38))->copy_from(a1); }

extern "C" {
void run_task__15TEffStarLight2DFv(Star_800851B0 *self) {
    P2_800851B0 scr;
    Vec_800851B0 view;
    f32 dx;
    f32 dz;
    void *child;

    matrix_mult_vec(0, &self->pos, &view);
    if (view.z > 0.0f) {
        return;
    }
    project_world_to_screen(0, &self->pos, &scr);
    if (scr.x >= -100.0f && scr.x <= 740.0f && scr.z >= -100.0f && scr.z <= 580.0f) {
        self->prevX = self->curX;
        self->prevZ = self->curZ;
        self->curX = scr.x;
        self->curZ = scr.z;
        dx = self->curX - self->prevX;
        dz = self->curZ - self->prevZ;
        if (dx * dx + dz * dz >= 1.0f) {
            child = __nw__7TObjectFUl(0x30);
            if (child != NULL) {
                ((void *(*)(void *, void *, void *, void *, f32, f32))__ct__18TEffStarLightChildFv)(child, &self->prevX, &self->curX, self, self->f38, self->f3C);
            }
        }
    }
}
}

void TEffStarLight2D::queue_child_destruction() {
    if (m_down != NULL && m_down->all_parents_unqueued_for_destruction() != 0) {
        m_down->queue_destruction();
    }
}

#pragma push
#pragma opt_propagation off
void TEffStarLight2D::render() {
    s32 index = 0;
    TEffStarLightChild *next;
    TEffStarLightChild *child;
    for (child = (TEffStarLightChild *)m_down; child != NULL; child = (TEffStarLightChild *)child->m_next) {
        if (child != NULL && child->m_next != NULL) {
            next = (TEffStarLightChild *)child->m_next;
            if (child->all_parents_unqueued_for_destruction() != 0 &&
                next->all_parents_unqueued_for_destruction() != 0) {
                draw_segment(&child->edges[0], &child->edges[1], &next->edges[1], &next->edges[0], index);
                index++;
            }
        }
    }
    set_default_alpha_blend();
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TEffStarLight2D::draw_segment(ColorLineVertex *a, ColorLineVertex *b,
                                 ColorLineVertex *c, ColorLineVertex *d, s32 index) {
    ColorLineVertex vertices[4];
    ColorLineList polygon;
    u32 colors[4];
    StarLightColor start_color;
    StarLightColor end_color;
    u8 alpha = parameters.color.channels.a;
    f32 step = parameters.alpha_step;
    f32 start_alpha = (f32)index * step + (f32)alpha;
    f32 end_alpha = (f32)(index + 1) * step + (f32)alpha;
    f32 clamped_start = start_alpha < 0.0f ? 0.0f
        : start_alpha < 255.0f ? start_alpha : 255.0f;
    f32 clamped_end = end_alpha < 0.0f ? 0.0f
        : end_alpha < 255.0f ? end_alpha : 255.0f;
    if (parameters.blend_mode == 0) {
        set_additive_blend();
    }
    u8 r = parameters.color.channels.r;
    u8 g = parameters.color.channels.g;
    u8 b_color = parameters.color.channels.b;
    start_color.channels.a = clamped_start;
    polygon.verts = vertices;
    polygon.colors = colors;
    polygon.unk_8 = 0;
    polygon.count = 4;
    end_color.channels.a = clamped_end;
    polygon.verts[0].x = a->x;
    polygon.verts[0].y = a->y;
    start_color.channels.r = r;
    start_color.channels.g = g;
    start_color.channels.b = b_color;
    polygon.colors[0] = start_color.packed;
    polygon.verts[1].x = b->x;
    polygon.verts[1].y = b->y;
    polygon.colors[1] = start_color.packed;
    end_color.channels.r = r;
    end_color.channels.g = g;
    end_color.channels.b = b_color;
    polygon.verts[2].x = c->x;
    polygon.verts[2].y = c->y;
    polygon.colors[2] = end_color.packed;
    polygon.verts[3].x = d->x;
    polygon.verts[3].y = d->y;
    polygon.colors[3] = end_color.packed;
    ((TWindowCtrlMain *)&polygon)->draw_strip_swap_color(4, 7, -15.0f);
}
#pragma pop

void TEffStarLight2D::copy_position(const Vec *source) {
    VecCopy(&position, source);
}

TEffStarLight2D_Base::TEffStarLight2D_Base(TObject *parent, void *set_data) : TObjBase(parent) {
    StarLightParameters parameters;
    apply_object_set_data(set_data);
    parameters.width = scale.x;
    parameters.speed = scale.y;
    parameters.color.channels.a = scale.z;
    parameters.color.channels.r = set_params[0];
    parameters.color.channels.g = set_params[1];
    parameters.color.channels.b = set_params[2];
    parameters.blend_mode = 0;
    light = new TEffStarLight2D(&position, &parameters, tl_particle);
}

TEffStarLight2D_Base::~TEffStarLight2D_Base() {
    if (light != NULL) {
        light->queue_destruction();
        light = NULL;
    }
}

void TEffStarLight2D_Base::run_task() {
    StarLightParameters parameters;
    if (light == NULL) {
        return;
    }
    light->copy_position(&position);
    parameters.width = scale.x;
    parameters.speed = scale.y;
    parameters.color.channels.a = scale.z;
    parameters.color.channels.r = (f32)set_params[0];
    parameters.color.channels.g = (f32)set_params[1];
    parameters.color.channels.b = (f32)set_params[2];
    parameters.blend_mode = 0;
    light->copy_from_subobject(&parameters);
}

void TEffStarLight2D_Base::render() {
    NJS_ARGB color = star_light_2d_base_color;
    debug_draw_sphere(&position, &color, 2.0f);
}

void *TEffStarLight2D_Base::create(void *set_data) {
    return new TEffStarLight2D_Base(tl_particle, set_data);
}
