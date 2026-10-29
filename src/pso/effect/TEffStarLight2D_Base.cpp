#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/TObjMapWarp_80141C68.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/TEffStarLight2D_Base.h"
#include "pso/effect/TEffStarLight2D.h"
#include "pso/effect/TEffStarLightChild.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

extern "C" {
extern TObject *tl_particle;
extern const f32 lbl_805D9450;
extern const f32 lbl_805D9454;
extern const f32 lbl_805D9458;
extern const f32 lbl_805D945C;
}
void set_additive_blend();
void set_default_alpha_blend();

extern const char TEffStarLightChild_class_name[] = "TEffStarLightChild";
extern const char TEffStarLight2D_class_name[] = "TEffStarLight2D";
const char *TEffStarLightChild__name = TEffStarLightChild_class_name;
const char *TEffStarLight2D__name = TEffStarLight2D_class_name;

__declspec(section ".rodata") NJS_ARGB star_light_2d_base_color = {0.5f, 1.0f, 1.0f, 1.0f};

void *TEffStarLight2D_Base::create(void *set_data) {
    return new TEffStarLight2D_Base(tl_particle, set_data);
}

void TEffStarLight2D_Base::render() {
    NJS_ARGB color = star_light_2d_base_color;
    TObjRoomId__sub_80141CF4(&position, &color, lbl_805D9450);
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

TEffStarLight2D_Base::~TEffStarLight2D_Base() {
    if (light != NULL) {
        light->queue_destruction();
        light = NULL;
    }
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

void TEffStarLight2D::copy_position(const Vec *source) {
    VecCopy(&position, source);
}

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
    f32 clamped_start = start_alpha < lbl_805D9454 ? lbl_805D9454
        : start_alpha < lbl_805D9458 ? start_alpha : lbl_805D9458;
    f32 clamped_end = end_alpha < lbl_805D9454 ? lbl_805D9454
        : end_alpha < lbl_805D9458 ? end_alpha : lbl_805D9458;
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
    ((TWindowCtrlMain *)&polygon)->draw_strip_swap_color(4, 7, lbl_805D945C);
}
#pragma pop

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

void TEffStarLight2D::queue_child_destruction() {
    if (m_down != NULL && m_down->all_parents_unqueued_for_destruction() != 0) {
        m_down->queue_destruction();
    }
}
