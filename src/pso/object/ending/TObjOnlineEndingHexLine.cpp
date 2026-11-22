#include "pso/object/ending/TObjOnlineEndingHexLine.h"
#include "pso/system/task/TObject.h"
#include "pso/object/ending/TObjOnlineEndingHexMove.h"
#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/camera/TCameraCtrl_801A6E60.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "pso/network/client_id.h"

struct Param_802E5CB0 { f32 a; f32 b; s32 c; f32 d; };

struct Desc_802E55B8 { NJS_POINT2 *pts; u32 *cols; s32 z; s32 n; };


GinjaTextureList *multiplay_texture_f512_handle;

const char *TObjOnlineEndingHexMove__name = "TObjOnlineEndingHexMove";
static const NJS_POINT2 lbl_80472C00[] = {{320.0f, 240.0f}};
const char *TObjOnlineEndingHexLine__name = "TObjOnlineEndingHexLine";

struct Pkt_802E5EFC { s32 hdr; s32 idx; f32 val; };


extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
void TObjOnlineEndingHexLine__sub_802E55A4(EndingHexPoint *point, const EndingHexPoint *source);
extern void *__vt__23TObjOnlineEndingHexLine[];
TObjOnlineEndingHexLine *__ct__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexLine *arg0, TObject *parent, EndingHexPoint *arg2);
Param_802E5CB0 lbl_804E3A98 = { 0.25f, 1.0f, 0, 10.0f };
Param_802E5CB0 TObjOnlineEndingHexLine__hex_line_params = lbl_804E3A98;
Param_802E5CB0 online_ending_hex_line_param = lbl_804E3A98;
EndingHexPoint TObjOnlineEndingHexLine_corner_offsets[4] = { {0, 0}, {21, 0}, {0, 19}, {21, 19} };
Param_802E5CB0 TObjOnlineEndingHexMove__default_move_params = { 0.0f, 0.0f, 0, 0.0f };
EndingHexPoint TObjOnlineEndingHexLine__direction_table[18] = {
    { -1, 0 }, { 0, -1 }, { 0, 1 },
    { 0, 0 }, { 0, 0 }, { 0, 0 },
    { 1, 0 }, { -1, -1 }, { -1, 1 },
    { 1, 0 }, { 0, -1 }, { 0, 1 },
    { -1, 0 }, { 1, -1 }, { 1, 1 },
    { 0, 0 }, { 0, 0 }, { 0, 0 },
};
void *__dt__23TObjOnlineEndingHexLineFv(void *arg0, s16 arg1);
void run_task__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexLine *arg0);
void render__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexLine *arg0);
void render_shadows__7TObjectFv(void);
void *__vt__23TObjOnlineEndingHexLine[6] = {
    (void *)0, (void *)0,
    (void *)__dt__23TObjOnlineEndingHexLineFv,
    (void *)run_task__23TObjOnlineEndingHexLineFv,
    (void *)render__23TObjOnlineEndingHexLineFv,
    (void *)render_shadows__7TObjectFv,
};

extern Param_802E5CB0 online_ending_hex_line_state;
extern u8 controller_input_state[];
extern s32 __vt__23TObjOnlineEndingHexMove[];

s32 draw_color_lines(Desc_802E55B8 *, s32, s32, f32);

s32 calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(NJS_POINT2 *, EndingHexPoint *);
void update_line_params__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexMove *);
TObjOnlineEndingHexMove *TObjOnlineEndingHexMove__ct(TObjOnlineEndingHexMove *object, TObject *parent);
Param_802E5CB0 *copy_move_params__23TObjOnlineEndingHexMoveFPvPv(Param_802E5CB0 *dest, const Param_802E5CB0 *src);
void *fn_802E6218(void *arg0);
void fn_802E6260(void);

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
        TObjOnlineEndingHexLine__sub_802E55A4(&points[i], &points[i - 1]);
    }
    base = ((s16)(points[0].x % 3) + (s16)(points[0].y & 1) * 3) * 3;
    dirs = &TObjOnlineEndingHexLine__direction_table[base];
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

#pragma push
#pragma scheduling off
void TObjOnlineEndingHexLine__sub_802E55A4(EndingHexPoint *point, const EndingHexPoint *source) {
    point->x = source->x;
    point->y = source->y;
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void render__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexLine *arg0) {
    NJS_POINT2 q1;
    NJS_POINT2 q0;
    NJS_POINT2 p1;
    NJS_POINT2 p0;
    Desc_802E55B8 d;
    u32 cols[32];
    NJS_POINT2 pts[32];
    NJS_POINT2 *pq1 = &q1;
    NJS_POINT2 *pp1 = &p1;
    s32 n;
    s32 i;
    s32 last;
    n = (s32) TObjOnlineEndingHexLine__hex_line_params.d;
    last = n - 1;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(&q0, &arg0->points[0]);
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(pq1, &arg0->points[1]);
            pts[0].x = arg0->progress * (q0.x - q1.x) + q1.x;
            pts[0].y = arg0->progress * (q0.y - q1.y) + q1.y;
        } else if (i == last) {
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(&p0, &arg0->points[last - 1]);
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(pp1, &arg0->points[last]);
            pts[last].x = arg0->progress * (p0.x - p1.x) + p1.x;
            pts[last].y = arg0->progress * (p0.y - p1.y) + p1.y;
        } else {
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(&pts[i], &arg0->points[i]);
        }
        cols[i] = 0x20FFFFFF;
    }
    d.pts = pts;
    d.cols = cols;
    d.z = 0;
    d.n = n;
    draw_color_lines(&d, n, 0x15, -117.0f);
}
#pragma pop

void run_task__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexLine *online_ending_hex_line) {
    online_ending_hex_line->progress = (f32) (online_ending_hex_line->progress + TObjOnlineEndingHexLine__hex_line_params.a);
    if (online_ending_hex_line->progress >= 1.0f) {
        online_ending_hex_line->step_line();
    }
}

void __dt__7TObjectFv(void *, int);

void *__dt__23TObjOnlineEndingHexLineFv(void *object, s16 arg1) {
    if (object != NULL) {
        *(void **)((s8 *)object + 0x18) = __vt__23TObjOnlineEndingHexLine;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}

TObjOnlineEndingHexLine *__ct__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexLine *arg0, TObject *parent, EndingHexPoint *arg2) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0, parent);
    *reinterpret_cast<void ***>(reinterpret_cast<u8 *>(arg0) + 0x18) = __vt__23TObjOnlineEndingHexLine;
    arg0->m_name = TObjOnlineEndingHexLine__name;
    EndingHexPoint pos = *arg2;
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
        TObjOnlineEndingHexLine__sub_802E55A4(&arg0->points[i], &pos);
    }
    arg0->progress = 1.0f;
    return arg0;
}

void *TObjOnlineEndingHexLine::create(void *arg0, void *arg1) {
    void *o;
    o = TObject::operator new(sizeof(TObjOnlineEndingHexLine));
    if (o != NULL) {
        o = __ct__23TObjOnlineEndingHexLineFv(static_cast<TObjOnlineEndingHexLine *>(o), static_cast<TObject *>(arg0), static_cast<EndingHexPoint *>(arg1));
    }
    return o;
}
}

#define BASE_802E5930 TObjOnlineEndingHexLine__hex_line_params

void handle_6x92(u8 *arg0) {
    f32 v;
    f32 d;
    s32 idx;

    bswap_6x92__14TAdGameStartGCFPv(arg0);
    idx = *(s32 *)((s8 *)arg0 + 4);
    v = *(f32 *)((s8 *)arg0 + 8);
    idx = idx % 4;
    if (get_player_by_client_id(idx) != 0U) {
        switch (idx) {
        case 0:
            if (v < (1.0f / 30.0f) || v > 0.5f) {
                return;
            }
            online_ending_hex_line_param.a = v;
            online_ending_hex_line_state.a = (1.0f / 30.0f) * (v - BASE_802E5930.a);
            break;
        case 1:
            if (v < 1.0f || v > 2.0f) {
                return;
            }
            d = v - BASE_802E5930.b;
            online_ending_hex_line_param.b = v;
            online_ending_hex_line_state.b = (1.0f / 30.0f) * d;
            break;
        case 2:
            online_ending_hex_line_param.c = (s32) v;
            online_ending_hex_line_state.c = (s32) ((1.0f / 30.0f) * (f32) angle_diff_s16(BASE_802E5930.c, online_ending_hex_line_param.c));
            break;
        case 3:
            if (v < 3.0f || v > 32.0f) {
                return;
            }
            d = v - BASE_802E5930.d;
            online_ending_hex_line_param.d = v;
            online_ending_hex_line_state.d = (1.0f / 30.0f) * d;
            break;
        }
    }
}

#undef BASE_802E5930

#pragma push
#pragma fp_contract on

s32 calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(NJS_POINT2 *arg0, EndingHexPoint *arg1) {
    NJS_POINT2 p;
    f32 s;
    f32 c;
    f32 sc;
    s32 ang;

    if (arg1->y & 1) {
        p.x = 30.0f * (0.5f + (f32) arg1->x);
    } else {
        p.x = (f32) (arg1->x * 0x1E);
    }
    f32 y = (f32) (arg1->y * 0x19);
    NJS_POINT2 ctr = lbl_80472C00[0];
    ang = TObjOnlineEndingHexLine__hex_line_params.c;
    p.x = p.x - ctr.x;
    p.y = y;
    p.y = p.y - ctr.y;
    s = sin_table_lookup(ang);
    c = cos_table_lookup(TObjOnlineEndingHexLine__hex_line_params.c);
    sc = TObjOnlineEndingHexLine__hex_line_params.b;
    NJS_POINT2 q = p;
    p.x = c * q.x - s * q.y;
    p.y = s * q.x + c * q.y;
    p.x = p.x * sc;
    p.y = p.y * sc;
    p.x = p.x + ctr.x;
    p.y = p.y + ctr.y;
    copy_vec2(arg0, &p);
    return 1;
}
#pragma pop

#define CUR_802E5CB0 TObjOnlineEndingHexLine__hex_line_params

void update_line_params__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexMove *) {
    f32 d;
    f32 t;
    s32 n;

    if (0.0f != online_ending_hex_line_state.a) {
        d = online_ending_hex_line_param.a - CUR_802E5CB0.a;
        if (d * online_ending_hex_line_state.a < 0.0f) {
            online_ending_hex_line_state.a = 0.0f;
        } else {
            t = fabs_float(online_ending_hex_line_state.a);
            if (fabs_float(d) < t) {
                CUR_802E5CB0.a = online_ending_hex_line_param.a;
                online_ending_hex_line_state.a = 0.0f;
            } else {
                CUR_802E5CB0.a = CUR_802E5CB0.a + online_ending_hex_line_state.a;
            }
        }
    }
    if (0.0f != online_ending_hex_line_state.b) {
        d = online_ending_hex_line_param.b - CUR_802E5CB0.b;
        if (d * online_ending_hex_line_state.b < 0.0f) {
            online_ending_hex_line_state.b = 0.0f;
        } else {
            t = fabs_float(online_ending_hex_line_state.b);
            if (fabs_float(d) < t) {
                CUR_802E5CB0.b = online_ending_hex_line_param.b;
                online_ending_hex_line_state.b = 0.0f;
            } else {
                CUR_802E5CB0.b = CUR_802E5CB0.b + online_ending_hex_line_state.b;
            }
        }
    }
    if (online_ending_hex_line_state.c != 0) {
        n = angle_difference_abs(CUR_802E5CB0.c, online_ending_hex_line_param.c);
        if (n < angle_difference_abs(0, online_ending_hex_line_state.c)) {
            CUR_802E5CB0.c = online_ending_hex_line_param.c;
            online_ending_hex_line_state.c = 0;
        } else {
            CUR_802E5CB0.c = CUR_802E5CB0.c + online_ending_hex_line_state.c;
        }
    }
    if (0.0f != online_ending_hex_line_state.d) {
        d = online_ending_hex_line_param.d - CUR_802E5CB0.d;
        if (d * online_ending_hex_line_state.d < 0.0f) {
            online_ending_hex_line_state.d = 0.0f;
        } else {
            t = fabs_float(online_ending_hex_line_state.d);
            if (fabs_float(d) < t) {
                CUR_802E5CB0.d = online_ending_hex_line_param.d;
                online_ending_hex_line_state.d = 0.0f;
            } else {
                CUR_802E5CB0.d = CUR_802E5CB0.d + online_ending_hex_line_state.d;
            }
        }
    }
}

#undef CUR_802E5CB0

void TObjOnlineEndingHexMove::run_task() {
    Pkt_802E5EFC pkt;
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
        pad = controller_input_state + 0x20;
        if (test_previous_buttons_packed(pad, 0x30000) != 0) {
            TAdGameStartGC__sub_802E6368(&pkt);
            pkt.idx = local_client_id % 4;
            switch (pkt.idx) {
            case 0:
            case 1:
            case 3:
                switch (pkt.idx) {
                case 0:
                    step = 0.093333334f;
                    max = 0.5f;
                    v = TObjOnlineEndingHexLine__hex_line_params.a;
                    min = (1.0f / 30.0f);
                    break;
                case 1:
                    step = 0.2f;
                    max = 2.0f;
                    v = TObjOnlineEndingHexLine__hex_line_params.b;
                    min = 1.0f;
                    break;
                case 3:
                    step = 5.8f;
                    max = 32.0f;
                    v = TObjOnlineEndingHexLine__hex_line_params.d;
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
                pkt.val = v;
                break;
            case 2:
                ang = TObjOnlineEndingHexLine__hex_line_params.c;
                if (test_previous_buttons_packed(pad, 0x10000) != 0) {
                    ang += 0x1999;
                } else {
                    ang -= 0x1999;
                }
                pkt.val = (s32)(u16)ang;
                break;
            }
            send_6x92__14TAdGameStartGCFPv(&pkt);
            timer = 0x1E;
        }
    }
    update_line_params__23TObjOnlineEndingHexLineFv(this);
}

TObjOnlineEndingHexMove::~TObjOnlineEndingHexMove() {}

TObjOnlineEndingHexMove *TObjOnlineEndingHexMove__ct(TObjOnlineEndingHexMove *object, TObject *origin) {
    s32 i;
    __ct__7TObjectFP7TObject(object, origin);
    *(s32 **)((s8 *)object + 0x18) = __vt__23TObjOnlineEndingHexMove;
    object->m_name = TObjOnlineEndingHexMove__name;
    for (i = 0; i < 4; i++) {
        TObjOnlineEndingHexLine::create(origin, &TObjOnlineEndingHexLine_corner_offsets[i]);
    }
    copy_move_params__23TObjOnlineEndingHexMoveFPvPv(&online_ending_hex_line_state, &TObjOnlineEndingHexMove__default_move_params);
    object->timer = 0x1E;
    return object;
}

#pragma push
#pragma scheduling off
Param_802E5CB0 *copy_move_params__23TObjOnlineEndingHexMoveFPvPv(Param_802E5CB0 *dest, const Param_802E5CB0 *src) {
    dest->a = src->a;
    dest->b = src->b;
    dest->c = src->c;
    dest->d = src->d;
    return dest;
}
#pragma pop

void * fn_802E6218(void *origin) {
    void *o;
    o = TObject::operator new(sizeof(TObjOnlineEndingHexMove));
    if (o != NULL) {
        o = TObjOnlineEndingHexMove__ct(static_cast<TObjOnlineEndingHexMove *>(o), static_cast<TObject *>(origin));
    }
    return o;
}

void fn_802E6260(void) {
    copy_move_params__23TObjOnlineEndingHexMoveFPvPv(&TObjOnlineEndingHexLine__hex_line_params,
        copy_move_params__23TObjOnlineEndingHexMoveFPvPv(&online_ending_hex_line_param, &lbl_804E3A98));
}

Param_802E5CB0 online_ending_hex_line_state;
