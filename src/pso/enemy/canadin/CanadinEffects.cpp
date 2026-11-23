#include "pso/system/TrailStrip.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
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
    tracked_from = from;
    tracked_to = to;
    VecCopy(&start, tracked_from);
    VecCopy(&end, tracked_to);
    start_color = 0xFFFF0033;
    end_color = 0xFFFF0033;
    timer = 5.0f * ((1.0f / 32768.0f) * (f32)rand());
}
#pragma pop

TObjEneMe1Canadin_EffLine::~TObjEneMe1Canadin_EffLine() {}

void TObjEneMe1Canadin_EffLine::run_task() {
    VecCopy(&start, tracked_from);
    VecCopy(&end, tracked_to);
    timer = timer + 1;
    if (timer > 5) {
        timer = 0;
        new TObjEneMe1Canadin_EffLineFade(m_up, &start, &end);
    }
}

void TObjEneMe1Canadin_EffLine::render() {
    VoloptLineList lines;
    lines.points = &start;
    lines.colors = (VoloptLineColor *)&start_color;
    lines.pad_8 = 0;
    lines.pad_c = 2;
    set_additive_blend();
    draw_line_list(&lines, 1, 5);
}

TObjEneMe1Canadin_EffDischarge::TObjEneMe1Canadin_EffDischarge(TObjEneMe1Canadin *parent, Vec *from, Vec *to)
    : TObject(parent) {
    m_name = TObjEneMe1Canadin_EffDischarge__name;
    owner = parent;
    VecCopy(&seg_start, from);
    VecCopy(&target, to);
    VecCopy(&step, &target);
    subtract_vector(&step, &seg_start);
    step.y = 0.0f;
    total_length = normalize_vector_xz(&step);
    if (total_length > 20.0f) {
        arc_length = 20.0f;
        flat_length = total_length - arc_length;
    } else {
        arc_length = total_length;
        flat_length = 0.0f;
    }
    start_height = seg_start.y;
    arc_curve = (target.y - seg_start.y) / (arc_length * arc_length);
    travelled = 0.0f;
    step.x *= 20.0f;
    step.z *= 20.0f;
    VecCopy(&seg_end, &seg_start);
}

TObjEneMe1Canadin_EffDischarge::~TObjEneMe1Canadin_EffDischarge() {}

void TObjEneMe1Canadin_EffDischarge::run_task() {
    Vec v;
    f32 scale;
    s32 done;

    done = 0;
    travelled += 20.0f;
    if (travelled > total_length) {
        VecCopy(&seg_end, &target);
        done = 1;
    } else {
        if (travelled < flat_length) {
            seg_end.y = start_height;
        } else {
            f32 t = travelled - flat_length;
            seg_end.y = t * (arc_curve * t) + start_height;
        }
        seg_end.x = seg_end.x + step.x;
        seg_end.z = seg_end.z + step.z;
    }
    VecCopy(&v, &seg_end);
    subtract_vector(&v, &seg_start);
    scale = normalize_vector_safe(&v);
    new TTecZondeEff(tl_05, &seg_start, &v, scale);
    VecCopy(&seg_start, &seg_end);
    if (done != 0) {
        owner->deliver_discharge_attack(&target);
        queue_destruction();
    }
}

void TObjEneMe1Canadin_EffDischarge::render() {}

TObjEneMe1Canadin_EffLight::TObjEneMe1Canadin_EffLight(TObject *parent, s32 count) : TObject(parent) {
    s32 i;
    m_name = TObjEneMe1Canadin_EffLight__name;
    capacity = count;
    head = 0;
    tail = 0;
    vertices = (TObjEneMe1Canadin_EffLightVertex *)mem_alloc(capacity << 5);
    points = (TObjEneMe1Canadin_EffLightPoint *)mem_alloc(capacity * 0x14);
    for (i = 0; i < capacity; i++) {
        points[i].width = 0.0f;
        points[i].color = 0;
        points[i].pos.x = 0.0f;
        points[i].pos.y = 0.0f;
        points[i].pos.z = 0.0f;
    }
    alpha_step = 0x30;
    width_decay = 0.85f;
}

TObjEneMe1Canadin_EffLight::~TObjEneMe1Canadin_EffLight() {
    mem_free(points);
    points = NULL;
    mem_free(vertices);
    vertices = NULL;
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
    s32 i = head;
    points[i].width = width;
    points[i].color = color;
    VecCopy(&points[i].pos, pos);
    head++;
    if (head >= capacity) {
        head = 0;
    }
}

void TObjEneMe1Canadin_EffLight::run_task() {
    s32 i;
    tail = head - 1;
    for (i = head - 1; i >= 0; i--) {
        if (points[i].fade_alpha_step(width_decay, alpha_step) == 0) {
            tail = i;
        }
    }
    for (i = capacity - 1; i >= head; i--) {
        if (points[i].fade_alpha_step(width_decay, alpha_step) == 0) {
            tail = i;
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
    last = head - 1;
    if (tail == last) {
        return;
    }
    VecCopy(&up, &camera_pitch_rotated_up_vector);
    v = vertices;
    if (tail > last) {
        n = head + (capacity - tail);
        for (i = head - 1; i >= 0; i--) {
            p = &points[i];
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
        for (j = capacity - 1; j >= tail; j--) {
            p = &points[j];
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
        n = head - tail;
        for (k = head - 1; k >= tail; k--) {
            p = &points[k];
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
    draw_trail_strip(vertices, (n * 2), 1);
}
