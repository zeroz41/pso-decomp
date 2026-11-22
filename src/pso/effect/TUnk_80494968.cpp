#include "pso/system/TrailStrip.h"
#include "types.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_800D7950.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/task/TObject.h"

typedef struct Ent_800D76E8 {
    f32 ax, ay, az;
    s32 ta;
    f32 bx, by, bz;
    s32 tb;
} Ent_800D76E8;

typedef struct Trail_800D76E8 {
    u8 pad0[0x1C];
    s32 count;
    Ent_800D76E8 e[1];
} Trail_800D76E8;


void TUnk_80494968::render() {
    if (((s32)this->defer_render() == 0) && ((s32) this->segment_count > 1)) {
        set_additive_blend();
        draw_trail_strip(vertices, (this->segment_count * 2), 1);
    }
}

void TUnk_80494968::run_task() {
    Trail_800D76E8 *arg0 = (Trail_800D76E8 *)this;
    s32 ta;
    s32 tb;
    s32 r;
    if (arg0->count <= 0) {
        return;
    }
    ta = arg0->e[0].ta;
    r = TObjBoss2Tunnel::decrement_packed_timer((u32 *)&ta, 0x20);
    tb = arg0->e[0].tb;
    if (r & TObjBoss2Tunnel::decrement_packed_timer((u32 *)&tb, 0x20)) {
        Ent_800D76E8 *dst = &arg0->e[0];
        Ent_800D76E8 *src = &arg0->e[1];
        s32 i;
        arg0->count--;
        for (i = 0; i < arg0->count; i++) {
            dst->ax = src->ax;
            dst->ay = src->ay;
            dst->az = src->az;
            dst->bx = src->bx;
            dst->by = src->by;
            dst->bz = src->bz;
            src++;
            dst++;
        }
        return;
    }
    if (arg0->count > 1) {
        Ent_800D76E8 *p = &arg0->e[arg0->count - 1];
        Ent_800D76E8 *q = p - 1;
        s32 j;
        for (j = 1; j < arg0->count; j++) {
            p->ta = q->ta;
            p[-1].tb = q[-1].tb;
            q--;
            p--;
        }
    }
    arg0->e[0].ta = ta;
    arg0->e[0].tb = tb;
}

void TUnk_80494968::set_edge_colors(u32 color_a, u32 color_b) {
    edge_colors[0] = color_a;
    edge_colors[1] = color_b;
}


// Appends one segment (the two edge points) to the strip; a full strip drops its oldest segment first.
void TUnk_80494968::add_segment(Vec *edge_a, Vec *edge_b) {
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

void TUnk_80494968::shift_line_buffer_down() {
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
        TAdDrawLineTask__sub_80019A8C(p++, q++);
    }
    this->segment_count = this->segment_count - 1;
}

TUnk_80494968::~TUnk_80494968() {

}

TUnk_80494968::TUnk_80494968(TObject *parent, u32 color_a, u32 color_b) : TAttackTrace(parent) {
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
