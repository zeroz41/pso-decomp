#include "pso/object/ending/TObjOnlineEndingHexLine.h"
#include "pso/system/task/TObject.h"
#include "pso/object/ending/TObjOnlineEndingHexMove.h"
#include "types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/render/ColorLineList.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

NJS_TEXLIST *multiplay_texture_f512_handle;

const char *online_ending_hex_move_name = "TObjOnlineEndingHexMove";
static const NJS_POINT2 ending_hex_screen_center[] = {{320.0f, 240.0f}};
const char *online_ending_hex_line_name = "TObjOnlineEndingHexLine";

EndingHexLineParams online_ending_hex_line_defaults = { 0.25f, 1.0f, 0, 10.0f };
EndingHexLineParams TObjOnlineEndingHexLine::hex_line_params = online_ending_hex_line_defaults;
EndingHexLineParams online_ending_hex_line_param = online_ending_hex_line_defaults;
EndingHexPoint online_ending_hex_corner_offsets[4] = { {0, 0}, {21, 0}, {0, 19}, {21, 19} };
EndingHexLineParams online_ending_hex_move_default_params = { 0.0f, 0.0f, 0, 0.0f };
EndingHexPoint online_ending_hex_direction_table[18] = {
    { -1, 0 }, { 0, -1 }, { 0, 1 },
    { 0, 0 }, { 0, 0 }, { 0, 0 },
    { 1, 0 }, { -1, -1 }, { -1, 1 },
    { 1, 0 }, { 0, -1 }, { 0, 1 },
    { -1, 0 }, { 1, -1 }, { 1, 1 },
    { 0, 0 }, { 0, 0 }, { 0, 0 },
};

// Built with -inline off,deferred: functions are emitted last to first, so they are written in reverse.

void reset_hex_line_params(void) {
    TObjOnlineEndingHexMove::copy_move_params(&TObjOnlineEndingHexLine::hex_line_params,
        TObjOnlineEndingHexMove::copy_move_params(&online_ending_hex_line_param, &online_ending_hex_line_defaults));
}

void *TObjOnlineEndingHexMove::create(void *parent) {
    return new TObjOnlineEndingHexMove(static_cast<TObject *>(parent));
}

#pragma push
#pragma scheduling off
EndingHexLineParams *TObjOnlineEndingHexMove::copy_move_params(EndingHexLineParams *dest, const EndingHexLineParams *src) {
    dest->speed = src->speed;
    dest->scale = src->scale;
    dest->angle = src->angle;
    dest->count = src->count;
    return dest;
}
#pragma pop

TObjOnlineEndingHexMove::TObjOnlineEndingHexMove(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = online_ending_hex_move_name;
    for (i = 0; i < 4; i++) {
        TObjOnlineEndingHexLine::create(parent, &online_ending_hex_corner_offsets[i]);
    }
    copy_move_params(&online_ending_hex_line_state, &online_ending_hex_move_default_params);
    timer = 0x1E;
}

TObjOnlineEndingHexMove::~TObjOnlineEndingHexMove() {}

void TObjOnlineEndingHexMove::run_task() {
    G_Unknown_6x92 pkt;
    void *pad;
    f32 v;
    f32 step;
    f32 max;
    f32 min;
    s32 ang;

    if (--timer < 0) {
        timer = 0;
    }
    if (timer == 0) {
        pad = &controller_input_state.controllers[0];
        if (test_previous_buttons_packed(pad, 0x30000) != 0) {
            TAdGameStartGC::init_6x92(&pkt);
            pkt.client_id = local_client_id % 4;
            switch (pkt.client_id) {
            case 0:
            case 1:
            case 3:
                switch (pkt.client_id) {
                case 0:
                    step = 0.093333334f;
                    max = 0.5f;
                    v = TObjOnlineEndingHexLine::hex_line_params.speed;
                    min = (1.0f / 30.0f);
                    break;
                case 1:
                    step = 0.2f;
                    max = 2.0f;
                    v = TObjOnlineEndingHexLine::hex_line_params.scale;
                    min = 1.0f;
                    break;
                case 3:
                    step = 5.8f;
                    max = 32.0f;
                    v = TObjOnlineEndingHexLine::hex_line_params.count;
                    min = 3.0f;
                    break;
                }
                if (test_previous_buttons_packed(pad, 0x10000) != 0) {
                    v += step;
                    if (v > max) {
                        v = max;
                    }
                } else {
                    v -= step;
                    if (v < min) {
                        v = min;
                    }
                }
                pkt.value = v;
                break;
            case 2:
                ang = TObjOnlineEndingHexLine::hex_line_params.angle;
                if (test_previous_buttons_packed(pad, 0x10000) != 0) {
                    ang += 0x1999;
                } else {
                    ang -= 0x1999;
                }
                pkt.value = (s32)(u16)ang;
                break;
            }
            TAdGameStartGC::send_6x92(&pkt);
            timer = 0x1E;
        }
    }
    update_line_params();
}

void TObjOnlineEndingHexMove::update_line_params() {
    f32 d;
    f32 t;
    s32 n;

    if (0.0f != online_ending_hex_line_state.speed) {
        d = online_ending_hex_line_param.speed - TObjOnlineEndingHexLine::hex_line_params.speed;
        if (d * online_ending_hex_line_state.speed < 0.0f) {
            online_ending_hex_line_state.speed = 0.0f;
        } else {
            t = fabs_float(online_ending_hex_line_state.speed);
            if (fabs_float(d) < t) {
                TObjOnlineEndingHexLine::hex_line_params.speed = online_ending_hex_line_param.speed;
                online_ending_hex_line_state.speed = 0.0f;
            } else {
                TObjOnlineEndingHexLine::hex_line_params.speed = TObjOnlineEndingHexLine::hex_line_params.speed + online_ending_hex_line_state.speed;
            }
        }
    }
    if (0.0f != online_ending_hex_line_state.scale) {
        d = online_ending_hex_line_param.scale - TObjOnlineEndingHexLine::hex_line_params.scale;
        if (d * online_ending_hex_line_state.scale < 0.0f) {
            online_ending_hex_line_state.scale = 0.0f;
        } else {
            t = fabs_float(online_ending_hex_line_state.scale);
            if (fabs_float(d) < t) {
                TObjOnlineEndingHexLine::hex_line_params.scale = online_ending_hex_line_param.scale;
                online_ending_hex_line_state.scale = 0.0f;
            } else {
                TObjOnlineEndingHexLine::hex_line_params.scale = TObjOnlineEndingHexLine::hex_line_params.scale + online_ending_hex_line_state.scale;
            }
        }
    }
    if (online_ending_hex_line_state.angle != 0) {
        n = angle_difference_abs(TObjOnlineEndingHexLine::hex_line_params.angle, online_ending_hex_line_param.angle);
        if (n < angle_difference_abs(0, online_ending_hex_line_state.angle)) {
            TObjOnlineEndingHexLine::hex_line_params.angle = online_ending_hex_line_param.angle;
            online_ending_hex_line_state.angle = 0;
        } else {
            TObjOnlineEndingHexLine::hex_line_params.angle = TObjOnlineEndingHexLine::hex_line_params.angle + online_ending_hex_line_state.angle;
        }
    }
    if (0.0f != online_ending_hex_line_state.count) {
        d = online_ending_hex_line_param.count - TObjOnlineEndingHexLine::hex_line_params.count;
        if (d * online_ending_hex_line_state.count < 0.0f) {
            online_ending_hex_line_state.count = 0.0f;
        } else {
            t = fabs_float(online_ending_hex_line_state.count);
            if (fabs_float(d) < t) {
                TObjOnlineEndingHexLine::hex_line_params.count = online_ending_hex_line_param.count;
                online_ending_hex_line_state.count = 0.0f;
            } else {
                TObjOnlineEndingHexLine::hex_line_params.count = TObjOnlineEndingHexLine::hex_line_params.count + online_ending_hex_line_state.count;
            }
        }
    }
}

#pragma push
#pragma fp_contract on

s32 TObjOnlineEndingHexLine::calc_rotated_hex_point(NJS_POINT2 *out, EndingHexPoint *ending_hex_point) {
    NJS_POINT2 p;
    f32 s;
    f32 c;
    f32 sc;
    s32 ang;

    if (ending_hex_point->y & 1) {
        p.x = 30.0f * (0.5f + (f32) ending_hex_point->x);
    } else {
        p.x = (f32) (ending_hex_point->x * 0x1E);
    }
    f32 y = (f32) (ending_hex_point->y * 0x19);
    NJS_POINT2 ctr = ending_hex_screen_center[0];
    ang = hex_line_params.angle;
    p.x = p.x - ctr.x;
    p.y = y;
    p.y = p.y - ctr.y;
    s = sin_table_lookup(ang);
    c = cos_table_lookup(hex_line_params.angle);
    sc = hex_line_params.scale;
    NJS_POINT2 q = p;
    p.x = c * q.x - s * q.y;
    p.y = s * q.x + c * q.y;
    p.x = p.x * sc;
    p.y = p.y * sc;
    p.x = p.x + ctr.x;
    p.y = p.y + ctr.y;
    copy_vec2(out, &p);
    return 1;
}
#pragma pop

void handle_6x92(u8 *packet) {
    G_Unknown_6x92 *cmd;
    f32 v;
    f32 d;
    s32 idx;

    TAdGameStartGC::bswap_6x92(packet);
    cmd = reinterpret_cast<G_Unknown_6x92 *>(packet);
    idx = static_cast<s32>(cmd->client_id);
    v = cmd->value;
    idx = idx % 4;
    if (get_player_by_client_id(idx) != 0U) {
        switch (idx) {
        case 0:
            if (v < (1.0f / 30.0f) || v > 0.5f) {
                return;
            }
            online_ending_hex_line_param.speed = v;
            online_ending_hex_line_state.speed = (1.0f / 30.0f) * (v - TObjOnlineEndingHexLine::hex_line_params.speed);
            break;
        case 1:
            if (v < 1.0f || v > 2.0f) {
                return;
            }
            d = v - TObjOnlineEndingHexLine::hex_line_params.scale;
            online_ending_hex_line_param.scale = v;
            online_ending_hex_line_state.scale = (1.0f / 30.0f) * d;
            break;
        case 2:
            online_ending_hex_line_param.angle = (s32) v;
            online_ending_hex_line_state.angle = (s32) ((1.0f / 30.0f) * (f32) angle_diff_s16(TObjOnlineEndingHexLine::hex_line_params.angle, online_ending_hex_line_param.angle));
            break;
        case 3:
            if (v < 3.0f || v > 32.0f) {
                return;
            }
            d = v - TObjOnlineEndingHexLine::hex_line_params.count;
            online_ending_hex_line_param.count = v;
            online_ending_hex_line_state.count = (1.0f / 30.0f) * d;
            break;
        }
    }
}

void *TObjOnlineEndingHexLine::create(void *parent, void *start) {
    return new TObjOnlineEndingHexLine(static_cast<TObject *>(parent), static_cast<EndingHexPoint *>(start));
}

TObjOnlineEndingHexLine::TObjOnlineEndingHexLine(TObject *parent, EndingHexPoint *start) : TObject(parent) {
    s32 i;
    m_name = online_ending_hex_line_name;
    EndingHexPoint pos = *start;
    if (pos.y & 1) {
        if (pos.x % 3 == 2) {
            if (pos.x + 1 < 0x16) {
                pos.x++;
            } else {
                pos.x--;
            }
        }
    } else if (pos.x % 3 == 1) {
        if (pos.x + 1 < 0x16) {
            pos.x++;
        } else {
            pos.x--;
        }
    }
    for (i = 0; i < 32; i++) {
        copy_ending_hex_point(&points[i], &pos);
    }
    progress = 1.0f;
}

TObjOnlineEndingHexLine::~TObjOnlineEndingHexLine() {}

void TObjOnlineEndingHexLine::run_task() {
    progress = (f32) (progress + hex_line_params.speed);
    if (progress >= 1.0f) {
        step_line();
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void TObjOnlineEndingHexLine::render() {
    NJS_POINT2 q1;
    NJS_POINT2 q0;
    NJS_POINT2 p1;
    NJS_POINT2 p0;
    ColorLineList d;
    u32 cols[32];
    NJS_POINT2 pts[32];
    NJS_POINT2 *pq1 = &q1;
    NJS_POINT2 *pp1 = &p1;
    s32 n;
    s32 i;
    s32 last;
    n = (s32) hex_line_params.count;
    last = n - 1;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            calc_rotated_hex_point(&q0, &points[0]);
            calc_rotated_hex_point(pq1, &points[1]);
            pts[0].x = progress * (q0.x - q1.x) + q1.x;
            pts[0].y = progress * (q0.y - q1.y) + q1.y;
        } else if (i == last) {
            calc_rotated_hex_point(&p0, &points[last - 1]);
            calc_rotated_hex_point(pp1, &points[last]);
            pts[last].x = progress * (p0.x - p1.x) + p1.x;
            pts[last].y = progress * (p0.y - p1.y) + p1.y;
        } else {
            calc_rotated_hex_point(&pts[i], &points[i]);
        }
        cols[i] = 0x20FFFFFF;
    }
    d.verts = reinterpret_cast<ColorLineVertex *>(pts);
    d.colors = cols;
    d.tex = NULL;
    d.count = n;
    draw_color_lines(&d, n, 0x15, -117.0f);
}
#pragma pop

#pragma push
#pragma scheduling off
void copy_ending_hex_point(EndingHexPoint *point, const EndingHexPoint *source) {
    point->x = source->x;
    point->y = source->y;
}
#pragma pop

void TObjOnlineEndingHexLine::step_line() {
    s16 dx;
    s16 dy;
    s32 bad[3];
    s32 same[3];
    EndingHexPoint *dirs;
    s32 base;
    s32 sel;
    s32 i;
    s32 nbad;
    s32 j;
    s32 last;

    dx = points[1].x - points[0].x;
    dy = points[1].y - points[0].y;
    progress = 0.0f;
    for (i = 31; i >= 1; i--) {
        copy_ending_hex_point(&points[i], &points[i - 1]);
    }
    base = ((s16)(points[0].x % 3) + (s16)(points[0].y & 1) * 3) * 3;
    dirs = &online_ending_hex_direction_table[base];
    nbad = 0;
    last = -1;
    for (j = 0; j < 3; j++) {
        EndingHexPoint t = dirs[j];
        if (t.x == dx && t.y == dy) {
            same[j] = 1;
        } else {
            same[j] = 0;
        }
        t.x += points[0].x;
        t.y += points[0].y;
        if (t.x < 0 || t.x >= 0x16 || t.y < 0 || t.y >= 0x14) {
            bad[j] = 1;
            nbad++;
        } else {
            bad[j] = 0;
            last = j;
        }
    }
    switch (nbad) {
    case 2:
        sel = last;
        break;
    case 1:
        for (sel = 0; sel < 3; sel++) {
            if (bad[sel] == 0 && same[sel] == 0) {
                break;
            }
        }
        break;
    case 0:
        sel = (s32)(2.99f * ((1.0f / 32768.0f) * (f32)rand()));
        for (i = 0; i < 3; i++) {
            if (bad[sel] == 0 && same[sel] == 0) {
                break;
            }
            sel++;
            if (sel >= 3) {
                sel = 0;
            }
        }
        break;
    }
    points[0].x += dirs[sel].x;
    points[0].y += dirs[sel].y;
}

EndingHexLineParams online_ending_hex_line_state;
