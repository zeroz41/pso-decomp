#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_800A02AC.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLight.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffDischarge.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLine.h"
#include "pso/boss/TUnk_80484840.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include <stdlib.h>

extern "C" {
__declspec(section ".rodata") extern const char TObjEneMe1Canadin_EffLine__class_name[] ATTRIBUTE_ALIGN(4) = "TObjEneMe1Canadin_EffLine";
__declspec(section ".rodata") extern const char TObjEneMe1Canadin_EffDischarge__class_name[] ATTRIBUTE_ALIGN(4) = "TObjEneMe1Canadin_EffDischarge";
__declspec(section ".rodata") extern const char TObjEneMe1Canadin_EffLight__class_name[] ATTRIBUTE_ALIGN(4) = "TObjEneMe1Canadin_EffLight";

extern Vec camera_pitch_rotated_up_vector;
extern const f32 canadin_effect_negative_one;
extern const f32 canadin_effect_zero;
extern const f32 canadin_light_width_cutoff;
extern const f32 canadin_light_width_decay;
extern const f32 canadin_discharge_motion_scale;
extern const f32 canadin_line_initial_phase_range;
struct CanadinRandomScale { f32 value; u32 padding; };
__declspec(section ".sdata2") extern const CanadinRandomScale canadin_random_scale;
extern const char *TObjEneMe1Canadin_EffLight__name;
extern const char *TObjEneMe1Canadin_EffDischarge__name;
extern const char *TObjEneMe1Canadin_EffLine__name;
void *mem_alloc(u32 size);
void mem_free(void *ptr);
void draw_line_list(VoloptLineList *lines, s32 count, u32 flags);
extern s32 __vt__26TObjEneMe1Canadin_EffLight[];
extern s32 __vt__30TObjEneMe1Canadin_EffDischarge[];
void __dt__7TObjectFv(void *object, s16 flags);
void __dl__7TObjectFPv(void *object);
}

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin_EffLight::render() {
    Vec up;
    TObjEneMe1Canadin_EffLightVertex *v;
    s32 i;
    TObjEneMe1Canadin_EffLightPoint *p;
    f32 w;
    u32 c;
    s32 j;
    s32 k;
    s32 last;
    s32 n;
    last = m_20 - 1;
    if (m_24 == last) {
        return;
    }
    VecCopy(&up, &camera_pitch_rotated_up_vector);
    v = m_28;
    if (m_24 > last) {
        n = m_20 + (m_1C - m_24);
        for (i = m_20 - 1; i >= 0; i--) {
            p = &m_2C[i];
            w = p->width;
            c = p->color;
            v[0].pos.x = up.x * w + p->pos.x;
            v[0].pos.y = up.y * w + p->pos.y;
            v[0].pos.z = up.z * w + p->pos.z;
            v[0].color = c;
            w *= canadin_effect_negative_one;
            v[1].pos.x = up.x * w + p->pos.x;
            v[1].pos.y = up.y * w + p->pos.y;
            v[1].pos.z = up.z * w + p->pos.z;
            v[1].color = c;
            v += 2;
        }
        for (j = m_1C - 1; j >= m_24; j--) {
            p = &m_2C[j];
            w = p->width;
            c = p->color;
            v[0].pos.x = up.x * w + p->pos.x;
            v[0].pos.y = up.y * w + p->pos.y;
            v[0].pos.z = up.z * w + p->pos.z;
            v[0].color = c;
            w *= canadin_effect_negative_one;
            v[1].pos.x = up.x * w + p->pos.x;
            v[1].pos.y = up.y * w + p->pos.y;
            v[1].pos.z = up.z * w + p->pos.z;
            v[1].color = c;
            v += 2;
        }
    } else {
        n = m_20 - m_24;
        for (k = m_20 - 1; k >= m_24; k--) {
            p = &m_2C[k];
            w = p->width;
            c = p->color;
            v[0].pos.x = up.x * w + p->pos.x;
            v[0].pos.y = up.y * w + p->pos.y;
            v[0].pos.z = up.z * w + p->pos.z;
            v[0].color = c;
            w *= canadin_effect_negative_one;
            v[1].pos.x = up.x * w + p->pos.x;
            v[1].pos.y = up.y * w + p->pos.y;
            v[1].pos.z = up.z * w + p->pos.z;
            v[1].color = c;
            v += 2;
        }
    }
    set_additive_blend();
    ((TObjPlayer *)m_28)->draw_trail_strip((void *)(n * 2), 1);
}
#pragma pop

void TObjEneMe1Canadin_EffLight::run_task() {
    s32 i;
    m_24 = m_20 - 1;
    for (i = m_20 - 1; i >= 0; i--) {
        if (fade_alpha_step__17TObjEneMe1CanadinFPvif(&m_2C[i], m_34, m_30) == 0) {
            m_24 = i;
        }
    }
    for (i = m_1C - 1; i >= m_20; i--) {
        if (fade_alpha_step__17TObjEneMe1CanadinFPvif(&m_2C[i], m_34, m_30) == 0) {
            m_24 = i;
        }
    }
}

extern "C" {
void TObjEneMe1Canadin::push_history_entry(void *trail, f32 width, void *pos, int color) {
    TObjEneMe1Canadin_EffLight *light = (TObjEneMe1Canadin_EffLight *)trail;
    s32 i = light->m_20;
    light->m_2C[i].width = width;
    light->m_2C[i].color = color;
    VecCopy(&light->m_2C[i].pos, (const Vec *)pos);
    light->m_20++;
    if (light->m_20 >= light->m_1C) {
        light->m_20 = 0;
    }
}

s32 fade_alpha_step__17TObjEneMe1CanadinFPvif(TObjEneMe1Canadin_EffLightPoint *point, f32 scale, s32 step) {
    s32 a;
    if (canadin_effect_zero == point->width) {
        return 1;
    }
    point->width = point->width * scale;
    if (point->width < canadin_light_width_cutoff) {
        point->width = canadin_effect_zero;
        return 1;
    }
    a = (point->color >> 24) - step;
    point->color &= 0xFFFFFF;
    if (a <= 0) {
        return 1;
    }
    point->color |= a << 24;
    return 0;
}
}

extern "C" {
TObjEneMe1Canadin_EffLight *__dt__26TObjEneMe1Canadin_EffLightFv(TObjEneMe1Canadin_EffLight *self, s16 flags) {
    if (self != NULL) {
        *(s32 **)((u8 *)self + 0x18) = __vt__26TObjEneMe1Canadin_EffLight;
        mem_free(self->m_2C);
        self->m_2C = NULL;
        mem_free(self->m_28);
        self->m_28 = NULL;
        __dt__7TObjectFv(self, 0);
        if (flags > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

TObjEneMe1Canadin_EffLight::TObjEneMe1Canadin_EffLight(TObject *parent, s32 count) : TObject(parent) {
    s32 i;
    m_name = TObjEneMe1Canadin_EffLight__name;
    m_1C = count;
    m_20 = 0;
    m_24 = 0;
    m_28 = (TObjEneMe1Canadin_EffLightVertex *)mem_alloc(m_1C << 5);
    m_2C = (TObjEneMe1Canadin_EffLightPoint *)mem_alloc(m_1C * 0x14);
    for (i = 0; i < m_1C; i++) {
        m_2C[i].width = canadin_effect_zero;
        m_2C[i].color = 0;
        m_2C[i].pos.x = canadin_effect_zero;
        m_2C[i].pos.y = canadin_effect_zero;
        m_2C[i].pos.z = canadin_effect_zero;
    }
    m_30 = 0x30;
    m_34 = canadin_light_width_decay;
}

void TObjEneMe1Canadin_EffDischarge::render() {}

#pragma fp_contract on

void TObjEneMe1Canadin_EffDischarge::run_task() {
    Vec v;
    f32 scale;
    s32 done;

    done = 0;
    m_28 = m_28 + canadin_discharge_motion_scale;
    if (m_28 > m_34) {
        VecCopy(&m_50, &m_44);
        done = 1;
    } else {
        if (m_28 < m_30) {
            m_50.y = m_24;
        } else {
            f32 t = m_28 - m_30;
            m_50.y = t * (m_20 * t) + m_24;
        }
        m_50.x = m_50.x + m_5C.x;
        m_50.z = m_50.z + m_5C.z;
    }
    VecCopy(&v, &m_50);
    subtract_vector(&v, &m_38);
    scale = ((TObjBoss2Tunnel *)&v)->update_scale();
    TTecZondeEff *eff = (TTecZondeEff *)TObject::operator new(0x260);
    if (eff != NULL) {
        eff->construct((u8 *)tl_05, (u8 *)&m_38, (u8 *)&v, scale);
    }
    VecCopy(&m_38, &m_50);
    if (done != 0) {
        fn_8009E1D4(m_1C, &m_44);
        queue_destruction();
    }
}

extern "C" {
TObjEneMe1Canadin_EffDischarge *__dt__30TObjEneMe1Canadin_EffDischargeFv(TObjEneMe1Canadin_EffDischarge *self, s16 flags) {
    if (self != NULL) {
        *(s32 **)((u8 *)self + 0x18) = __vt__30TObjEneMe1Canadin_EffDischarge;
        __dt__7TObjectFv(self, 0);
        if (flags > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

TObjEneMe1Canadin_EffDischarge::TObjEneMe1Canadin_EffDischarge(TObjEneMe1Canadin *parent, Vec *from, Vec *to)
    : TObject(parent) {
    m_name = TObjEneMe1Canadin_EffDischarge__name;
    m_1C = parent;
    VecCopy(&m_38, from);
    VecCopy(&m_44, to);
    VecCopy(&m_5C, &m_44);
    subtract_vector(&m_5C, &m_38);
    m_5C.y = canadin_effect_zero;
    m_34 = normalize_vector_xz(&m_5C);
    if (m_34 > canadin_discharge_motion_scale) {
        m_2C = canadin_discharge_motion_scale;
        m_30 = m_34 - m_2C;
    } else {
        m_2C = m_34;
        m_30 = canadin_effect_zero;
    }
    m_24 = m_38.y;
    m_20 = (m_44.y - m_38.y) / (m_2C * m_2C);
    m_28 = canadin_effect_zero;
    m_5C.x *= canadin_discharge_motion_scale;
    m_5C.z *= canadin_discharge_motion_scale;
    VecCopy(&m_50, &m_38);
}

void TObjEneMe1Canadin_EffLine::render() {
    VoloptLineList lines;
    lines.points = &m_28;
    lines.colors = (VoloptLineColor *)&m_40;
    lines.pad_8 = 0;
    lines.pad_c = 2;
    set_additive_blend();
    draw_line_list(&lines, 1, 5);
}

void TObjEneMe1Canadin_EffLine::run_task() {
    VecCopy(&m_28, m_20);
    VecCopy(&m_34, m_24);
    m_1C = m_1C + 1;
    if (m_1C > 5) {
        m_1C = 0;
        u8 *fade = (u8 *)TObject::operator new(0x3C);
        if (fade != NULL) {
            fn_800A02AC(fade, (u8 *)m_up, (u8 *)&m_28, (u8 *)&m_34);
        }
    }
}

TObjEneMe1Canadin_EffLine::~TObjEneMe1Canadin_EffLine() {}

#pragma opt_propagation off
TObjEneMe1Canadin_EffLine::TObjEneMe1Canadin_EffLine(TObject *parent, Vec *from, Vec *to) : TObject(parent) {
    m_name = TObjEneMe1Canadin_EffLine__name;
    m_20 = from;
    m_24 = to;
    VecCopy(&m_28, m_20);
    VecCopy(&m_34, m_24);
    m_40 = 0xFFFF0033;
    m_44 = 0xFFFF0033;
    m_1C = canadin_line_initial_phase_range * (canadin_random_scale.value * (f32)rand());
}

extern "C" {
void render_shadows__7TObjectFv();
void run_task__26TObjEneMe1Canadin_EffLightFv();
void render__26TObjEneMe1Canadin_EffLightFv();
void run_task__30TObjEneMe1Canadin_EffDischargeFv();
void render__30TObjEneMe1Canadin_EffDischargeFv();
s32 __vt__26TObjEneMe1Canadin_EffLight[] = {
    0, 0, (s32)__dt__26TObjEneMe1Canadin_EffLightFv,
    (s32)run_task__26TObjEneMe1Canadin_EffLightFv,
    (s32)render__26TObjEneMe1Canadin_EffLightFv, (s32)render_shadows__7TObjectFv
};
s32 __vt__30TObjEneMe1Canadin_EffDischarge[] = {
    0, 0, (s32)__dt__30TObjEneMe1Canadin_EffDischargeFv,
    (s32)run_task__30TObjEneMe1Canadin_EffDischargeFv,
    (s32)render__30TObjEneMe1Canadin_EffDischargeFv, (s32)render_shadows__7TObjectFv
};
__declspec(section ".sdata2") const f32 canadin_effect_negative_one = -1.0f;
__declspec(section ".sdata2") const f32 canadin_effect_zero = 0.0f;
__declspec(section ".sdata2") const f32 canadin_light_width_cutoff = 0.01f;
__declspec(section ".sdata2") const f32 canadin_light_width_decay = 0.85f;
__declspec(section ".sdata2") const f32 canadin_discharge_motion_scale = 20.0f;
__declspec(section ".sdata2") const f32 canadin_line_initial_phase_range = 5.0f;
__declspec(section ".sdata2") const CanadinRandomScale canadin_random_scale = {0.000030517578125f, 0};
}
