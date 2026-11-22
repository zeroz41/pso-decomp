#include "pso/system/TrailStrip.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLight.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffDischarge.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLine.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLineFade.h"
#include "pso/boss/TUnk_80484840.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include <stdlib.h>
#include "pso/boss/darkfalz/TOBoss4Rock.h"

// The unit is compiled with deferred code generation: functions are emitted last to first, so the source runs
// from the LineFade constructor (the unit's last function) back to EffLight::render (its first).

const char *TObjEneMe1Canadin_EffLineFade__class_name = "TObjEneMe1Canadin_EffLineFade";
const char *TObjEneMe1Canadin_EffLine__name = "TObjEneMe1Canadin_EffLine";
const char *TObjEneMe1Canadin_EffDischarge__name = "TObjEneMe1Canadin_EffDischarge";
const char *TObjEneMe1Canadin_EffLight__name = "TObjEneMe1Canadin_EffLight";

extern "C" {
extern Vec camera_pitch_rotated_up_vector;
void draw_line_list(VoloptLineList *lines, s32 count, u32 flags);
}

TObjEneMe1Canadin_EffLineFade::TObjEneMe1Canadin_EffLineFade(TObject *parent, Vec *from, Vec *to) : TObject(parent) {
    m_name = TObjEneMe1Canadin_EffLineFade__class_name;
    VecCopy(&points[0], from);
    VecCopy(&points[1], to);
    colors[0].rgba = 0xFFFF0033;
    colors[1].rgba = 0xFFFF0033;
}

TObjEneMe1Canadin_EffLineFade::~TObjEneMe1Canadin_EffLineFade() {}

void TObjEneMe1Canadin_EffLineFade::run_task() {
    s32 alpha;

    alpha = colors[0].c.a;
    alpha -= 0x10;
    if (alpha < 0) {
        alpha = 0;
        queue_destruction();
    }
    colors[0].c.a = alpha;
    colors[1].c.a = alpha;
}

void TObjEneMe1Canadin_EffLineFade::render() {
    VoloptLineList lines;
    lines.points = points;
    lines.colors = &colors[0].c;
    lines.pad_8 = 0;
    lines.pad_c = 2;
    set_additive_blend();
    draw_line_list(&lines, 1, 5);
}

#pragma push
#pragma opt_propagation off
TObjEneMe1Canadin_EffLine::TObjEneMe1Canadin_EffLine(TObject *parent, Vec *from, Vec *to) : TObject(parent) {
    m_name = TObjEneMe1Canadin_EffLine__name;
    m_20 = from;
    m_24 = to;
    VecCopy(&m_28, m_20);
    VecCopy(&m_34, m_24);
    m_40 = 0xFFFF0033;
    m_44 = 0xFFFF0033;
    m_1C = 5.0f * ((1.0f / 32768.0f) * (f32)rand());
}
#pragma pop

TObjEneMe1Canadin_EffLine::~TObjEneMe1Canadin_EffLine() {}

void TObjEneMe1Canadin_EffLine::run_task() {
    VecCopy(&m_28, m_20);
    VecCopy(&m_34, m_24);
    m_1C = m_1C + 1;
    if (m_1C > 5) {
        m_1C = 0;
        new TObjEneMe1Canadin_EffLineFade(m_up, &m_28, &m_34);
    }
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

TObjEneMe1Canadin_EffDischarge::TObjEneMe1Canadin_EffDischarge(TObjEneMe1Canadin *parent, Vec *from, Vec *to)
    : TObject(parent) {
    m_name = TObjEneMe1Canadin_EffDischarge__name;
    m_1C = parent;
    VecCopy(&m_38, from);
    VecCopy(&m_44, to);
    VecCopy(&m_5C, &m_44);
    subtract_vector(&m_5C, &m_38);
    m_5C.y = 0.0f;
    m_34 = normalize_vector_xz(&m_5C);
    if (m_34 > 20.0f) {
        m_2C = 20.0f;
        m_30 = m_34 - m_2C;
    } else {
        m_2C = m_34;
        m_30 = 0.0f;
    }
    m_24 = m_38.y;
    m_20 = (m_44.y - m_38.y) / (m_2C * m_2C);
    m_28 = 0.0f;
    m_5C.x *= 20.0f;
    m_5C.z *= 20.0f;
    VecCopy(&m_50, &m_38);
}

TObjEneMe1Canadin_EffDischarge::~TObjEneMe1Canadin_EffDischarge() {}

void TObjEneMe1Canadin_EffDischarge::run_task() {
    Vec v;
    f32 scale;
    s32 done;

    done = 0;
    m_28 += 20.0f;
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
    scale = normalize_vector_safe(&v);
    TTecZondeEff *eff = (TTecZondeEff *)TObject::operator new(0x260);
    if (eff != NULL) {
        eff->construct((u8 *)tl_05, (u8 *)&m_38, (u8 *)&v, scale);
    }
    VecCopy(&m_38, &m_50);
    if (done != 0) {
        m_1C->fn_8009E1D4(&m_44);
        queue_destruction();
    }
}

void TObjEneMe1Canadin_EffDischarge::render() {}

TObjEneMe1Canadin_EffLight::TObjEneMe1Canadin_EffLight(TObject *parent, s32 count) : TObject(parent) {
    s32 i;
    m_name = TObjEneMe1Canadin_EffLight__name;
    m_1C = count;
    m_20 = 0;
    m_24 = 0;
    m_28 = (TObjEneMe1Canadin_EffLightVertex *)mem_alloc(m_1C << 5);
    m_2C = (TObjEneMe1Canadin_EffLightPoint *)mem_alloc(m_1C * 0x14);
    for (i = 0; i < m_1C; i++) {
        m_2C[i].width = 0.0f;
        m_2C[i].color = 0;
        m_2C[i].pos.x = 0.0f;
        m_2C[i].pos.y = 0.0f;
        m_2C[i].pos.z = 0.0f;
    }
    m_30 = 0x30;
    m_34 = 0.85f;
}

TObjEneMe1Canadin_EffLight::~TObjEneMe1Canadin_EffLight() {
    mem_free(m_2C);
    m_2C = NULL;
    mem_free(m_28);
    m_28 = NULL;
}

s32 TObjEneMe1Canadin_EffLightPoint::fade_alpha_step(f32 scale, s32 step) {
    s32 a;
    if (0.0f == width) {
        return 1;
    }
    width = width * scale;
    if (width < 0.01f) {
        width = 0.0f;
        return 1;
    }
    a = (color >> 24) - step;
    color &= 0xFFFFFF;
    if (a <= 0) {
        return 1;
    }
    color |= a << 24;
    return 0;
}

void TObjEneMe1Canadin_EffLight::push_history_entry(f32 width, Vec *pos, u32 color) {
    s32 i = m_20;
    m_2C[i].width = width;
    m_2C[i].color = color;
    VecCopy(&m_2C[i].pos, pos);
    m_20++;
    if (m_20 >= m_1C) {
        m_20 = 0;
    }
}

void TObjEneMe1Canadin_EffLight::run_task() {
    s32 i;
    m_24 = m_20 - 1;
    for (i = m_20 - 1; i >= 0; i--) {
        if (m_2C[i].fade_alpha_step(m_34, m_30) == 0) {
            m_24 = i;
        }
    }
    for (i = m_1C - 1; i >= m_20; i--) {
        if (m_2C[i].fade_alpha_step(m_34, m_30) == 0) {
            m_24 = i;
        }
    }
}

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
    saddr n;
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
            w *= -1.0f;
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
            w *= -1.0f;
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
            w *= -1.0f;
            v[1].pos.x = up.x * w + p->pos.x;
            v[1].pos.y = up.y * w + p->pos.y;
            v[1].pos.z = up.z * w + p->pos.z;
            v[1].color = c;
            v += 2;
        }
    }
    set_additive_blend();
    draw_trail_strip(m_28, (n * 2), 1);
}
