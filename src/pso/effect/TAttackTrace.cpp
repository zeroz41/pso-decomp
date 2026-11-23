#include "pso/system/TrailStrip.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

const char *TAttackTrace::class_name = "TAttackTrace";

// Functions are written last to first (deferred code generation).
#pragma defer_codegen on

TAttackTrace::TAttackTrace(TObject *parent) : TObject(parent) {
    m_name = class_name;
    segment_count = 0;
}

TAttackTrace::~TAttackTrace() {}

void TAttackTraceStrip::clear_segments() {
    segment_count = 0;
}

TAttackTraceStrip::TAttackTraceStrip(TObject *parent, u32 color_a, u32 color_b) : TAttackTrace(parent) {
    s32 i;
    TrailStripVertex *v;
    set_edge_colors(color_a, color_b);
    v = vertices;
    for (i = 0; i < 8; i++) {
        v[0].color = edge_colors[0];
        v[1].color = edge_colors[1];
        v += 2;
    }
}

TAttackTraceStrip::~TAttackTraceStrip() {

}

void TAttackTraceStrip::shift_line_buffer_down() {
    TrailStripVertex *p;
    TrailStripVertex *q;
    s32 lim;
    s32 i;
    s32 n = this->segment_count;
    if (n <= 1) {
        this->segment_count = 0;
        return;
    }
    p = vertices;
    q = vertices + 2;
    lim = (n - 1) * 2;
    for (i = 0; i < lim; i++) {
        copy_line_vertex(p++, q++);
    }
    this->segment_count = this->segment_count - 1;
}

// Appends one segment (the two edge points) to the strip; a full strip drops its oldest segment first.
void TAttackTraceStrip::add_segment(Vec *edge_a, Vec *edge_b) {
    TrailStripVertex *v;
    if (segment_count >= 16) {
        shift_line_buffer_down();
    }
    v = &vertices[segment_count * 2];
    v[0].x = edge_a->x;
    v[0].y = edge_a->y;
    v[0].z = edge_a->z;
    v[0].color = edge_colors[0];
    v[1].x = edge_b->x;
    v[1].y = edge_b->y;
    v[1].z = edge_b->z;
    v[1].color = edge_colors[1];
    segment_count++;
}

void TAttackTraceStrip::set_edge_colors(u32 color_a, u32 color_b) {
    edge_colors[0] = color_a;
    edge_colors[1] = color_b;
}

// Fades the strip's oldest colours, passing them on toward the newest
// segment; once the oldest pair has faded out, that segment is dropped.
void TAttackTraceStrip::run_task() {
    u32 color_a;
    u32 color_b;
    s32 faded;
    if (segment_count <= 0) {
        return;
    }
    color_a = vertices[0].color;
    faded = TObjBoss2Tunnel::decrement_packed_timer(&color_a, 0x20);
    color_b = vertices[1].color;
    if (faded & TObjBoss2Tunnel::decrement_packed_timer(&color_b, 0x20)) {
        TrailStripVertex *dst = &vertices[0];
        TrailStripVertex *src = &vertices[2];
        s32 i;
        segment_count--;
        for (i = 0; i < segment_count; i++) {
            dst[0].x = src[0].x;
            dst[0].y = src[0].y;
            dst[0].z = src[0].z;
            dst[1].x = src[1].x;
            dst[1].y = src[1].y;
            dst[1].z = src[1].z;
            src += 2;
            dst += 2;
        }
        return;
    }
    if (segment_count > 1) {
        TrailStripVertex *to = &vertices[(segment_count - 1) * 2];
        TrailStripVertex *from = to - 2;
        s32 j;
        for (j = 1; j < segment_count; j++) {
            to[0].color = from[0].color;
            to[-1].color = from[-1].color;
            from -= 2;
            to -= 2;
        }
    }
    vertices[0].color = color_a;
    vertices[1].color = color_b;
}

void TAttackTraceStrip::render() {
    if (((s32)this->defer_render() == 0) && ((s32) this->segment_count > 1)) {
        set_additive_blend();
        draw_trail_strip(vertices, (this->segment_count * 2), 1);
    }
}
