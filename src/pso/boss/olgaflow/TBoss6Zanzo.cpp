#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/render/ColorCopy.h"
#include "pso/render/TriangleFan3D.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/player/TObjPlayer.h"
#include "types.h"

#include "pso/render/render_util.h"
#include "pso/system/memory.h"
#include "pso/boss/olgaflow/TBoss6Zanzo.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
const char *TBoss6Zanzo__name = "TBoss6Zanzo";

extern "C" {

void TBoss6Zanzo::set_effect_points(const Vec *points, const u32 *colors) {
    Boss6TrailPoint *p;
    Boss6TrailPoint *end;
    const Vec *a2 = points;
    const u32 *b2 = colors;
    current->active = 1;
    p = current->points;
    end = p + point_count;
    for (; p < end; ++p, ++a2, ++b2) {
        VecCopy(&p->position, a2);
        copy4(&p->color, (void *)b2);
    }
}

void TBoss6Zanzo::copy_trail_buffer(Boss6TrailFrame *dest, Boss6TrailFrame *source) {
    Boss6TrailPoint *src;
    Boss6TrailPoint *dst;
    Boss6TrailPoint *end;
    dest->active = source->active;
    if (dest->active != 0) {
        s32 count = point_count;
        dst = dest->points;
        end = dst + count;
        src = source->points;
        for (; dst < end; ++dst, ++src) TBoss6Zanzo__sub_803205A0(dst, src);
    }
}

#pragma push
#pragma scheduling off
void TBoss6Zanzo__sub_803205A0(Boss6TrailPoint *dest, const Boss6TrailPoint *source) {
    *dest = *source;
}
#pragma pop

// Draws the after-image trail: a strip of quads between each pair of consecutive frames, fading out with age.
void TBoss6Zanzo::sub_803205C4() {
    Boss6TrailFrame *frame;
    Boss6TrailFrame *end;
    Boss6TrailFrame *prev;
    f32 step;
    f32 alpha;
    f32 prev_alpha;
    f32 next_alpha;
    s32 drawn;
    s32 i;
    u32 colors[4];
    NJS_POINT3COL quad;
    Vec positions[4];

    step = 1.0f / frame_count;
    alpha = 1.0f;
    frame = frames;
    end = frame + frame_count;
    drawn = 0;
    for (; frame < end; frame++) {
        if (frame == frames || frame->active == 0 || prev->active == 0) {
            drawn = 0;
        } else {
            if (!drawn) {
                prev_alpha = 0.0f;
            }
            next_alpha = alpha;
            if (frame == end - 1 || frame[1].active == 0) {
                next_alpha = 0.0f;
            }
            quad.col = colors;
            quad.tex = NULL;
            quad.num = 4;
            quad.p = positions;
            // Each packed RGBA color retains RGB while its alpha fades.
            for (i = 0; i < point_count - 1; i++) {
                {
                    Boss6TrailPoint *p = &prev->points[i];
                    copy4(&colors[0], (void *)&p->color);
                    ((u8 *)colors)[3] = prev_alpha * ((const u8 *)&p->color)[3];
                    VecCopy(&positions[0], &p->position);
                }
                {
                    Boss6TrailPoint *p = prev->points + i + 1;
                    copy4(&colors[1], (void *)&p->color);
                    ((u8 *)colors)[7] = prev_alpha * ((const u8 *)&p->color)[3];
                    VecCopy(&positions[1], &p->position);
                }
                {
                    Boss6TrailPoint *p = frame->points + i + 1;
                    copy4(&colors[2], (void *)&p->color);
                    ((u8 *)colors)[11] = next_alpha * ((const u8 *)&p->color)[3];
                    VecCopy(&positions[2], &p->position);
                }
                {
                    Boss6TrailPoint *p = &frame->points[i];
                    copy4(&colors[3], (void *)&p->color);
                    ((u8 *)colors)[15] = next_alpha * ((const u8 *)&p->color)[3];
                    VecCopy(&positions[3], &p->position);
                }
                draw_tri_fan_3d(&quad, 4, 7);
            }
            drawn = 1;
        }
        prev_alpha = alpha;
        prev = frame;
        alpha -= step;
    }
}

int set_depth_buffer_settings_1__Fv(void *);
void TBoss6Zanzo::render() { set_depth_buffer_settings_1__Fv(this); sub_803205C4(); restore_saved_depth_alpha_state(); }

void TBoss6Zanzo::run_task() {
    Boss6TrailFrame *base;
    Boss6TrailFrame *p;
    if (TObjPlayer::check_demo_mode() == 0) {
        base = frames;
        for (p = base + frame_count - 1; p > base; p--) copy_trail_buffer(p, p - 1);
        copy_trail_buffer(p, current);
        current->active = 0;
    }
}

}
TBoss6Zanzo::~TBoss6Zanzo() {
    Boss6TrailFrame *p;
    Boss6TrailFrame *end;
    mem_free(current->points);
    ::operator delete(current);
    for (p = frames, end = p + frame_count; p < end; p++) {
        mem_free(p->points);
    }
    mem_free(frames);
}

TBoss6Zanzo::TBoss6Zanzo(TObject *object, s32 points, s32 trail_length) : TObject(object) {
    Boss6TrailFrame *p;
    Boss6TrailFrame *end;
    m_name = TBoss6Zanzo__name;
    point_count = points;
    if (point_count < 2) point_count = 2;
    frame_count = trail_length;
    if (frame_count < 2) frame_count = 2;
    frames = (Boss6TrailFrame *)mem_alloc(frame_count * sizeof(Boss6TrailFrame));
    for (p = frames, end = p + frame_count; p < end; p++) {
        p->active = 0;
        p->points = (Boss6TrailPoint *)mem_alloc(point_count * sizeof(Boss6TrailPoint));
    }
    current = (Boss6TrailFrame *)::operator new(sizeof(Boss6TrailFrame));
    current->active = 0;
    current->points = (Boss6TrailPoint *)mem_alloc(point_count * sizeof(Boss6TrailPoint));
}
