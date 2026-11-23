#define TOBJECT_OUT_OF_LINE_HELPERS
#include <stdio.h>
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/render/TDLGraph.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/MenuText.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

const char *TDLGraph::class_name = "TDLGraph";
TDLGraph *TDLGraph::graph_object;

static const NJS_POINT2 bar_pos = {473.0f, 440.0f};
static const NJS_POINT2 bar_size = {142.0f, 8.0f};

// Built with -inline off,deferred: the functions are emitted last to first, so they are written here in
// reverse address order.
#pragma fp_contract on

void *TDLGraph::create() {
    return new TDLGraph(tl_clipout);
}

TDLGraph::TDLGraph(TObject *parent) : TObject(parent) {
    m_name = class_name;
    m_progress = 0.0f;
    m_frame = 0;
    m_eta_state = -1;
    m_eta = -1;
    m_eta_frame = -1;
    reset_bar_colors();
    init_dl_graph_entries();
    m_flags = 3;
    graph_object = this;
}

TDLGraph::~TDLGraph() {
    graph_object = NULL;
}

// Starts the graph when done is 0 and removes it on a restart; otherwise passes the progress on.
void TDLGraph::update_graph(s32 done, s32 total) {
    if (done < 0 || total <= 0) {
        return;
    }
    if (done == 0) {
        if (graph_object != NULL) {
            graph_object->queue_destruction();
            return;
        }
        create();
    } else if (graph_object == NULL) {
        return;
    }
    if (graph_object != NULL) {
        graph_object->set_progress(done, total);
    }
}

void TDLGraph::set_graph_param(s32 flags) {
    m_flags = flags;
}

void TDLGraph::run_task() {}

void TDLGraph::render() {
    set_default_alpha_blend();
    TCameraCtrl::restore_full_screen_view();
    draw_progress_bar(bar_pos, bar_size);
    draw_countdown_timer(543.0f, 418.0f);
    draw_percent_text(615.0f, 418.0f);
    TCameraCtrl::restore_saved_view();
    update_bar_colors();
    m_frame++;
}

void TDLGraph::reset_bar_colors() {
    m_pulse = 0;
    update_bar_colors();
}

// Pulses the bar colours: the fill's alpha and red, the empty part's alpha, red and green.
void TDLGraph::update_bar_colors() {
    u32 fill = 32.0f * fabs_float(sin_table_lookup(m_pulse << 11)) + 64.0f;
    u32 empty;

    m_fill_color = (fill << 24) | ((fill & 0xFF) << 16) | 0xFFFF;
    empty = 128.0f * (1.0f - fabs_float(sin_table_lookup(m_pulse << 7))) + 64.0f;
    m_empty_color = (empty << 24) | ((empty & 0xFF) << 16) | ((empty & 0xFF) << 8) | 0xFF;
    m_pulse++;
}

void TDLGraph::init_dl_graph_entries() {
    s32 i;

    m_sample_count = 0;
    for (i = 0; i < 4; i++) {
        m_samples[i].frame = -1;
        m_samples[i].progress = -1.0f;
    }
}

void copy_graph_sample(TDLGraphSample *dst, TDLGraphSample *src) {
    dst->frame = src->frame;
    dst->progress = src->progress;
}

// Records a reading unless the frame or the progress is unchanged; returns whether it did.
s32 TDLGraph::push_sample(s32 frame, f32 progress) {
    s32 i;

    if (frame == m_samples[0].frame || progress == m_samples[0].progress) {
        return 0;
    }
    for (i = 3; i > 0; i--) {
        copy_graph_sample(&m_samples[i], &m_samples[i - 1]);
    }
    m_samples[0].frame = frame;
    m_samples[0].progress = progress;
    m_sample_count++;
    return 1;
}

// Frames left at the average rate of the last three intervals, or -1 with fewer than nine readings
// or a reading that did not move forward.
s32 TDLGraph::estimate_remaining_frames(f32 progress) {
    f32 rate;
    f32 frames;
    f32 delta;
    s32 i;

    if (m_sample_count < 9) {
        return -1;
    }
    rate = 0.0f;
    for (i = 0; i < 3; i++) {
        frames = (f32)(m_samples[i].frame - m_samples[i + 1].frame);
        delta = m_samples[i].progress - m_samples[i + 1].progress;
        if (frames <= 1e-05f || delta <= 1e-05f) {
            return -1;
        }
        rate += frames / delta;
    }
    rate /= 3.0f;
    return (s32)((1.0f - progress) * rate);
}

// Draws the bar at pos: a 2-pixel frame, the first m_progress of size in m_fill_color and the rest in
// m_empty_color.
void TDLGraph::draw_progress_bar(const NJS_POINT2 &pos, const NJS_POINT2 &size) {
    NJS_COLOR col[4];
    NJS_POINT2 p[4];
    NJS_POINT2COL poly = {p, col, NULL, 4};

    col[0].color = col[1].color = col[2].color = col[3].color = 0xFF;
    p[0].x = p[3].x = pos.x - 2.0f;
    p[1].x = p[2].x = 2.0f + (pos.x + size.x);
    p[0].y = p[1].y = pos.y - 2.0f;
    p[2].y = p[3].y = 2.0f + (pos.y + size.y);
    draw_polygon_2d(&poly, 4, 2, -2.0f);

    col[0].color = col[1].color = col[2].color = col[3].color = m_fill_color;
    p[0].x = p[3].x = pos.x;
    p[1].x = p[2].x = size.x * m_progress + pos.x;
    p[0].y = p[1].y = pos.y;
    p[2].y = p[3].y = size.y + pos.y;
    draw_polygon_2d(&poly, 4, 2, -1.0f);

    col[0].color = col[1].color = col[2].color = col[3].color = m_empty_color;
    p[0].x = p[3].x = size.x + pos.x;
    draw_polygon_2d(&poly, 4, 2, -1.0f);
}

// Draws the time left as minutes"seconds.tenths and counts it down; every 2.5 s it is
// re-estimated from the frames taken so far.
void TDLGraph::draw_countdown_timer(f32 x, f32 y) {
    char buf[16];
    s32 frames;
    s32 minutes;
    s32 seconds;
    s32 tenths;

    if (!(m_flags & 1)) {
        return;
    }
    buf[0] = 0;
    frames = m_eta;
    if (frames <= 0) {
        return;
    }
    minutes = frames / 1800;
    seconds = (frames / 30) % 60;
    tenths = (frames % 30) / 3;
    if (minutes > 0) {
        sprintf(buf, "%d\"%02d.%d ", minutes, seconds, tenths);
    } else {
        sprintf(buf, "%d.%d ", seconds, tenths);
    }
    draw_outlined_string_right_aligned(x, y, buf);
    if (m_eta_frame > 0 && m_frame - m_eta_frame > 75 && m_progress > 1e-05f) {
        m_eta = (1.0f / m_progress - 1.0f) * m_frame;
        if (m_eta > 17999) {
            m_eta = 17999;
        }
        m_eta_frame = m_frame;
    }
    if (m_eta > 5) {
        m_eta--;
    }
}

void TDLGraph::draw_percent_text(f32 x, f32 y) {
    char buf[8];
    s32 percent;

    if (m_flags & 2) {
        buf[0] = 0;
        percent = 100.0f * m_progress;
        if (percent < 0) {
            percent = 0;
        } else if (percent > 100) {
            percent = 100;
        }
        sprintf(buf, "%3d%", percent);
        draw_outlined_string_right_aligned(x, y, buf);
    }
}

// Draws str in white with a black outline, its right edge at x.
void TDLGraph::draw_outlined_string_right_aligned(s32 x, s32 y, char *str) {
    f32 left = x - calc_text_width(str);
    f32 top = y;
    f32 right;
    f32 bottom;

    draw_menu_text(left - 2.0f, top - 2.0f, str, 0xFF000000);
    draw_menu_text(left, top - 2.0f, str, 0xFF000000);
    right = 2.0f + left;
    draw_menu_text(right, top - 2.0f, str, 0xFF000000);
    draw_menu_text(left - 2.0f, top, str, 0xFF000000);
    draw_menu_text(right, top, str, 0xFF000000);
    bottom = 2.0f + top;
    draw_menu_text(left - 2.0f, bottom, str, 0xFF000000);
    draw_menu_text(left, bottom, str, 0xFF000000);
    draw_menu_text(right, bottom, str, 0xFF000000);
    draw_menu_text(left, top, str, 0xFFFFFFFF);
}

// Sets the progress to done / total and, from the last four readings, the time left to show.
// The graph removes itself once the progress reaches 1.
void TDLGraph::set_progress(s32 done, s32 total) {
    s32 eta;

    m_progress = (f32)done / (f32)total;
    if (m_progress < 0.0f) {
        m_progress = 0.0f;
    } else if (m_progress > 1.0f) {
        m_progress = 1.0f;
    }
    if (m_eta_state != 0 && push_sample(m_frame, m_progress)) {
        eta = estimate_remaining_frames(m_progress);
        if (eta >= 0) {
            eta += (s32)(30.0f * (eta / 1800.0f) + 30.0f);
            if (eta > 17999) {
                eta = 17999;
            }
            switch (m_eta_state) {
            case 0:
                break;
            case -1:
                if (eta >= 300) {
                    m_eta_state = 1;
                    m_eta = eta;
                    m_eta_frame = m_frame;
                }
                break;
            case 1:
                if (m_eta > eta) {
                    m_eta = eta;
                } else if (eta - m_eta >= 75) {
                    m_eta = eta;
                }
                m_eta_frame = m_frame;
                break;
            }
        }
    }
    if (1.0f == m_progress) {
        queue_destruction();
    }
}
