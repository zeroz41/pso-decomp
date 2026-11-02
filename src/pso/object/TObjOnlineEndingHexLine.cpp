#include "pso/TObjOnlineEndingHexLine.h"
#include "pso/TObject.h"
#include "pso/TObjOnlineEndingHexMove.h"
#include "types.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct Param_802E5CB0 { f32 a; f32 b; s32 c; f32 d; };
typedef char Param_802E5CB0_size[sizeof(Param_802E5CB0) == 0x10 ? 1 : -1];

struct V2_802E55B8 { f32 x, y; };
struct P2_802E55B8 { s16 x, y; };
struct Hex_802E55B8 { u8 pad[0x1C]; P2_802E55B8 pts[32]; };
struct Desc_802E55B8 { V2_802E55B8 *pts; u32 *cols; s32 z; s32 n; };

struct P2_802E530C { s16 x, y; };
struct Hex_802E530C { u8 pad[0x1C]; P2_802E530C pts[32]; f32 f9C; };

struct V2_802E5B0C { f32 x, y; };

struct Pkt_802E5EFC { s32 hdr; s32 idx; f32 val; };
struct Self_802E5EFC { u8 pad[0x1c]; s32 timer; };

typedef struct V4_802E62A4 { s32 a, b, c, d; } V4_802E62A4;

struct Pos_802E57E0 { s16 x; s16 y; };

struct Line_802E57E0 { u8 b[4]; };

struct Hex_802E57E0 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    Line_802E57E0 lines[32];
    f32 f9C;
};

extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
void TObjOnlineEndingHexLine__sub_802E55A4(void *arg0, void *arg1);
extern void *__vt__23TObjOnlineEndingHexLine[];
extern s32 lbl_805D3FA4;
Hex_802E57E0 *__ct__23TObjOnlineEndingHexLineFv(Hex_802E57E0 *arg0, s32 arg1, Pos_802E57E0 *arg2);
V4_802E62A4 lbl_804E3A98[1] = {
    { 0x3E800000, 0x3F800000, 0x00000000, 0x41200000 },
};
Param_802E5CB0 TObjOnlineEndingHexLine__hex_line_params = { 0.0f, 0.0f, 0, 0.0f };
Param_802E5CB0 online_ending_hex_line_param = { 0.0f, 0.0f, 0, 0.0f };
u32 TObjOnlineEndingHexLine_corner_offsets[4] = { 0x00000000, 0x00150000, 0x00000013, 0x00150013 };
u32 TObjOnlineEndingHexMove__default_move_params[4] = { 0, 0, 0, 0 };
P2_802E530C TObjOnlineEndingHexLine__direction_table[18] = {
    { -1, 0 }, { 0, -1 }, { 0, 1 },
    { 0, 0 }, { 0, 0 }, { 0, 0 },
    { 1, 0 }, { -1, -1 }, { -1, 1 },
    { 1, 0 }, { 0, -1 }, { 0, 1 },
    { -1, 0 }, { 1, -1 }, { 1, 1 },
    { 0, 0 }, { 0, 0 }, { 0, 0 },
};
void *__dt__23TObjOnlineEndingHexLineFv(void *arg0, s16 arg1);
void run_task__23TObjOnlineEndingHexLineFv(TObjOnlineEndingHexLine *arg0);
void render__23TObjOnlineEndingHexLineFv(u8 *arg0);
void render_shadows__7TObjectFv(void);
void *__vt__23TObjOnlineEndingHexLine[6] = {
    (void *)0, (void *)0,
    (void *)__dt__23TObjOnlineEndingHexLineFv,
    (void *)run_task__23TObjOnlineEndingHexLineFv,
    (void *)render__23TObjOnlineEndingHexLineFv,
    (void *)render_shadows__7TObjectFv,
};

extern Param_802E5CB0 online_ending_hex_line_state;
extern V2_802E5B0C lbl_80472C00[];
extern u8 controller_input_state[];
extern s32 local_client_id;
extern s32 lbl_805D3FA0;
extern s32 __vt__23TObjOnlineEndingHexMove[];

int rand(void);
f32 fabs_float(f32);
s32 angle_difference_abs(int, int);
s32 angle_diff_s16(s32, s32);
u32 get_player_by_client_id(int);
s32 bswap_6x92__14TAdGameStartGCFPv(void *);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 draw_color_lines(Desc_802E55B8 *, s32, s32, f32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
void send_6x92__14TAdGameStartGCFPv(void *p);
void TAdGameStartGC__sub_802E6368(void *p);
void *__nw__7TObjectFUl(int);

s32 calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(V2_802E55B8 *, P2_802E55B8 *);
void update_line_params__23TObjOnlineEndingHexLineFv(void);
u8 *TObjOnlineEndingHexMove__ct(u8 *arg0, void *arg1);
void copy_move_params__23TObjOnlineEndingHexMoveFPvPv(void *p, void *q);
void *fn_802E6218(void *arg0);
void fn_802E6260(void);

void TObjOnlineEndingHexLine::step_line() {
    Hex_802E530C *h = (Hex_802E530C *)this;
    s16 dx;
    s16 dy;
    s32 bad[3];
    s32 same[3];
    P2_802E530C *dirs;
    s32 base;
    s32 sel;
    s32 i;
    s32 nbad;
    s32 j;
    s32 last;

    dx = h->pts[1].x - h->pts[0].x;
    dy = h->pts[1].y - h->pts[0].y;
    h->f9C = 0.0f;
    for (i = 31; i >= 1; i--) {
        TObjOnlineEndingHexLine__sub_802E55A4(&h->pts[i], &h->pts[i - 1]);
    }
    base = ((s16)(h->pts[0].x % 3) + (s16)(h->pts[0].y & 1) * 3) * 3;
    dirs = &TObjOnlineEndingHexLine__direction_table[base];
    nbad = 0;
    last = -1;
    for (j = 0; j < 3; j++) {
        P2_802E530C t = dirs[j];
        if (t.x == dx && t.y == dy) {
            same[j] = 1;
        } else {
            same[j] = 0;
        }
        t.x += h->pts[0].x;
        t.y += h->pts[0].y;
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
        sel = (s32)(2.99f * (3.0517578e-05f * (f32)rand()));
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
    h->pts[0].x += dirs[sel].x;
    h->pts[0].y += dirs[sel].y;
}

void TObjOnlineEndingHexLine__sub_802E55A4(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void render__23TObjOnlineEndingHexLineFv(u8 *arg0) {
    V2_802E55B8 q1;
    V2_802E55B8 q0;
    V2_802E55B8 p1;
    V2_802E55B8 p0;
    Desc_802E55B8 d;
    u32 cols[32];
    V2_802E55B8 pts[32];
    V2_802E55B8 *pq1 = &q1;
    V2_802E55B8 *pp1 = &p1;
    s32 n;
    s32 i;
    s32 last;
    n = (s32) TObjOnlineEndingHexLine__hex_line_params.d;
    last = n - 1;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(&q0, &((Hex_802E55B8 *) arg0)->pts[0]);
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(pq1, &((Hex_802E55B8 *) arg0)->pts[1]);
            pts[0].x = *(f32 *)((s8 *)arg0 + 0x9C) * (q0.x - q1.x) + q1.x;
            pts[0].y = *(f32 *)((s8 *)arg0 + 0x9C) * (q0.y - q1.y) + q1.y;
        } else if (i == last) {
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(&p0, &((Hex_802E55B8 *) arg0)->pts[last - 1]);
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(pp1, &((Hex_802E55B8 *) arg0)->pts[last]);
            pts[last].x = *(f32 *)((s8 *)arg0 + 0x9C) * (p0.x - p1.x) + p1.x;
            pts[last].y = *(f32 *)((s8 *)arg0 + 0x9C) * (p0.y - p1.y) + p1.y;
        } else {
            calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(&pts[i], &((Hex_802E55B8 *) arg0)->pts[i]);
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
    *(f32 *)((s8 *)online_ending_hex_line + 0x9C) = (f32) (*(f32 *)((s8 *)online_ending_hex_line + 0x9C) + TObjOnlineEndingHexLine__hex_line_params.a);
    if (*(f32 *)((s8 *)online_ending_hex_line + 0x9C) >= 1.0f) {
        online_ending_hex_line->step_line();
    }
}

void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);

void *__dt__23TObjOnlineEndingHexLineFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = __vt__23TObjOnlineEndingHexLine;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Hex_802E57E0 *__ct__23TObjOnlineEndingHexLineFv(Hex_802E57E0 *arg0, s32 arg1, Pos_802E57E0 *arg2) {
    s32 i;
    ((void (*)(void *))__ct__7TObjectFP7TObject)(arg0);
    arg0->vt = __vt__23TObjOnlineEndingHexLine;
    arg0->f0 = lbl_805D3FA4;
    Pos_802E57E0 pos = *arg2;
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
        TObjOnlineEndingHexLine__sub_802E55A4(&arg0->lines[i], &pos);
    }
    arg0->f9C = 1.0f;
    return arg0;
}

void *TObjOnlineEndingHexLine::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0xA0);
    if (o != NULL) {
        o = __ct__23TObjOnlineEndingHexLineFv((Hex_802E57E0 *)(o), (s32)arg0, (Pos_802E57E0 *)(arg1));
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
            if (v < 0.033333335f || v > 0.5f) {
                return;
            }
            online_ending_hex_line_param.a = v;
            online_ending_hex_line_state.a = 0.033333335f * (v - BASE_802E5930.a);
            break;
        case 1:
            if (v < 1.0f || v > 2.0f) {
                return;
            }
            d = v - BASE_802E5930.b;
            online_ending_hex_line_param.b = v;
            online_ending_hex_line_state.b = 0.033333335f * d;
            break;
        case 2:
            online_ending_hex_line_param.c = (s32) v;
            online_ending_hex_line_state.c = (s32) (0.033333335f * (f32) angle_diff_s16(BASE_802E5930.c, online_ending_hex_line_param.c));
            break;
        case 3:
            if (v < 3.0f || v > 32.0f) {
                return;
            }
            d = v - BASE_802E5930.d;
            online_ending_hex_line_param.d = v;
            online_ending_hex_line_state.d = 0.033333335f * d;
            break;
        }
    }
}

#undef BASE_802E5930

#pragma push
#pragma fp_contract on

s32 calc_rotated_hex_point__23TObjOnlineEndingHexLineFPvPv(V2_802E55B8 *arg0, P2_802E55B8 *arg1) {
    V2_802E5B0C p;
    f32 s;
    f32 c;
    f32 sc;
    s32 ang;

    if (*(s16 *)((s8 *)arg1 + 2) & 1) {
        p.x = 30.0f * (0.5f + (f32) *(s16 *)((s8 *)arg1 + 0));
    } else {
        p.x = (f32) (*(s16 *)((s8 *)arg1 + 0) * 0x1E);
    }
    f32 y = (f32) (*(s16 *)((s8 *)arg1 + 2) * 0x19);
    V2_802E5B0C ctr = lbl_80472C00[0];
    ang = *(s32 *)((s8 *)&TObjOnlineEndingHexLine__hex_line_params + 8);
    p.x = p.x - ctr.x;
    p.y = y;
    p.y = p.y - ctr.y;
    s = sin_table_lookup(ang);
    c = cos_table_lookup(*(s32 *)((s8 *)&TObjOnlineEndingHexLine__hex_line_params + 8));
    sc = *(f32 *)((s8 *)&TObjOnlineEndingHexLine__hex_line_params + 4);
    V2_802E5B0C q = p;
    p.x = c * q.x - s * q.y;
    p.y = s * q.x + c * q.y;
    p.x = p.x * sc;
    p.y = p.y * sc;
    p.x = p.x + ctr.x;
    p.y = p.y + ctr.y;
    ((TWindowSubSymbolChatPartsSet *)arg0)->copy_vec2(&p);
    return 1;
}
#pragma pop

#define CUR_802E5CB0 TObjOnlineEndingHexLine__hex_line_params

void update_line_params__23TObjOnlineEndingHexLineFv(void) {
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
    Self_802E5EFC *self = (Self_802E5EFC *)this;
    Pkt_802E5EFC pkt;
    void *pad;
    f32 v;
    f32 step;
    f32 max;
    f32 min;
    s32 ang;

    if (--self->timer < 0) {
        self->timer = 0;
    }
    if (self->timer == 0) {
        pad = controller_input_state + 0x20;
        if (is_on_current_screen__11TCameraCtrlFv(pad, 0x30000) != 0) {
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
                    min = 0.033333335f;
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
                if (is_on_current_screen__11TCameraCtrlFv(pad, 0x10000) != 0) {
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
                if (is_on_current_screen__11TCameraCtrlFv(pad, 0x10000) != 0) {
                    ang += 0x1999;
                } else {
                    ang -= 0x1999;
                }
                pkt.val = (s32)(u16)ang;
                break;
            }
            send_6x92__14TAdGameStartGCFPv(&pkt);
            self->timer = 0x1E;
        }
    }
    ((void (*)(void *))update_line_params__23TObjOnlineEndingHexLineFv)(self);
}

TObjOnlineEndingHexMove::~TObjOnlineEndingHexMove() {}

u8 *TObjOnlineEndingHexMove__ct(u8 *object, void *origin) {
    s32 i;
    __ct__7TObjectFP7TObject(object, origin);
    *(s32 **)((s8 *)object + 0x18) = __vt__23TObjOnlineEndingHexMove;
    *(s32 *)((s8 *)object + 0) = lbl_805D3FA0;
    for (i = 0; i < 4; i++) {
        TObjOnlineEndingHexLine::create(origin, &TObjOnlineEndingHexLine_corner_offsets[i]);
    }
    copy_move_params__23TObjOnlineEndingHexMoveFPvPv(&online_ending_hex_line_state, TObjOnlineEndingHexMove__default_move_params);
    *(s32 *)((s8 *)object + 0x1C) = 0x1E;
    return object;
}

void copy_move_params__23TObjOnlineEndingHexMoveFPvPv(void* p, void* q) { *(f32*)((char*)p + 0x0) = *(f32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); *(u32*)((char*)p + 0x8) = *(u32*)((char*)q + 0x8); *(f32*)((char*)p + 0xc) = *(f32*)((char*)q + 0xc); }

void * fn_802E6218(void *origin) {
    void *o;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjOnlineEndingHexMove__ct((u8 *)o, (void *)origin);
    }
    return o;
}

void fn_802E6260(void) {
    copy_move_params__23TObjOnlineEndingHexMoveFPvPv(&TObjOnlineEndingHexLine__hex_line_params,
        ((void *(*)(void *, void *))copy_move_params__23TObjOnlineEndingHexMoveFPvPv)(&online_ending_hex_line_param, lbl_804E3A98));
}

Param_802E5CB0 online_ending_hex_line_state;
