#include "types.h"
#include "pso/misc/TKeyBoardControl_803DE9C4.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802C50EC.h"
#include "pso/unk/text_80299420.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdPlyPltAnimCtrlGC.h"

struct RecoveredGlobal_802C658C_TAdMultiPlyChrSelectGC__data_804E0A48 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_802C6848_lbl_804E0B00 {
    s32 value;
    u8 remaining[0xC];
};

typedef struct S_802C59EC {
    u8 pad0[0x444];
    s32 a[4][3];
    u8 pad474[0x4DC - 0x474];
    s32 f4DC[3];
    u8 pad4E8[0x500 - 0x4E8];
    s32 b[4][3];
} S_802C59EC;

typedef struct G_802C6A10 { s32 value; u8 remaining[0xC]; } G_802C6A10;

struct S_802C5594 {
    u8 pad0[0x4DC];
    s32 x[3];
    u8 pad4E8[0x500 - 0x4E8];
    s32 y[4][3];
    s32 f530;
};

struct E_802C5944 { f32 x; f32 y; u8 pad[0x18]; };

struct V_802C5944 { f32 x; f32 y; };

struct S_802C5944 {
    u8 pad0[0x24];
    E_802C5944 e[4][3];
    u8 pad1a4[0x384 - 0x1A4];
    V_802C5944 v[4][3];
    u8 pad3e4[0x444 - 0x3E4];
    s32 a[4][3];
    u8 pad474[0x4A4 - 0x474];
    f32 ox;
    f32 oy;
};

struct E_802C5314 { f32 x; f32 y; f32 z; f32 w; u8 pad[0x10]; };

struct S_802C5314 {
    u8 pad0[0x24];
    E_802C5314 e[4][3];
    u8 pad1a4[0x324 - 0x1A4];
    f32 r324[8];
    f32 r344[8];
    f32 r364[8];
    u8 pad384[0x474 - 0x384];
    s32 sel[4][3];
    u8 pad4a4[0x500 - 0x4A4];
    s32 y[4][3];
};

struct S_802C6008 {
    u8 pad0[0x1C];
    s32 f1C;
    u8 pad20[0x4AC - 0x20];
    s32 sel[4][3];
    s32 f4DC[4];
    s32 f4EC;
    u8 pad4f0[0x8];
    s32 f4F8;
};

struct S_802C61E4 {
    u8 pad0[0x1C];
    s32 f1C;
    u8 pad20[0x4AC - 0x20];
    s32 sel[4][3];
    s32 f4DC[4];
    s32 f4EC;
    u8 pad4f0[0x8];
    s32 f4F8;
};

typedef struct Jump_802C5C84 {
    s32 v[4];
} Jump_802C5C84;

typedef struct Self_802C5C84 {
    u8 pad0[0x4AC];
    s32 f4AC[5][3];
    u8 pad4E8[0x4EC - 0x4E8];
    s32 f4EC;
} Self_802C5C84;

struct S_802C6AC8 {
    u8 pad0[0x20];
    s32 f20;
    u8 pad24[0x444 - 0x24];
    s32 alpha[4][3];
    s32 col[4][3];
    u8 pad4a4[8];
    s32 sel[4][3];
    s32 f4DC[4];
    s32 f4EC;
    u8 pad4f0[0x8];
    s32 f4F8;
    s32 f4FC;
    u8 pad500[0x530 - 0x500];
    s32 f530;
    s32 f534;
};

struct Pad_802C6AC8 { u8 pad[0x20]; u8 ctl[0x30]; };

/* Selection-screen view: per player row/column quads (x0,y0,x1,y1,u0,v0,u1,v1), the three
   cursor quads, home positions, and per-player column state. */
struct Quad_802C50EC { f32 x, y, z, w, u0, v0, u1, v1; };
struct V2_802C50EC { f32 x, y; };
struct S_802C50EC {
    u8 pad0[0x24];
    Quad_802C50EC quad[8][3];
    f32 cursor[3][8];
    V2_802C50EC home[4][3];
    u8 pad3e4[0x444 - 0x3E4];
    s32 a[4][3];
    u8 pad474[0x4A4 - 0x474];
    f32 ox;
    f32 oy;
    s32 sel[4][3];
    s32 f4DC[4];
    s32 f4EC;
    u8 pad4f0[0x500 - 0x4F0];
    s32 b[4][3];
};

struct RecoveredGlobal_802C64D0_TAdMultiPlyChrSelectGC__data_804E0A48 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
int TAdMultiPlyChrSelectGC__sub_802C6920(void);
    extern int TAdMultiPlyChrSelectGC__data_805D67D8;
extern s32 TAdMultiPlyChrSelectGC__select_mode;
extern s32 TAdMultiPlyChrSelectGC__selected_slot;
extern RecoveredGlobal_802C6848_lbl_804E0B00 multiplayer_controller_device_codes;
extern const f32 TAdMultiPlyChrSelectGC__data_805DE56C;
extern s32 multi_ply_chr_select_default_slot_table[][5];
extern s32 TAdMultiPlyChrSelectGC__data_804E0A68[][5];
void copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *);
s32 get_field_20__22TAdMultiPlyChrSelectGCFv();
extern s32 lbl_805D67D4;
extern const f32 lbl_805DE57C;
extern const f32 lbl_805DE580;
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 play_sound_effect(int, void *, int, int);
s32 TAdMultiPlyChrSelectGC__sub_802C5F1C(void *, int);
extern u8 controller_physical_port_bank[];
extern Jump_802C5C84 multi_chr_select_cursor_jump_table[][5];
extern void *TAdMultiPlyChrSelectGC__data_804E0A48[4];
void TAdMultiPlyChrSelectGC__sub_802C50EC(s32);
void TAdMultiPlyChrSelectGC__sub_802C522C(s32);
extern s32 lbl_805D67D0;
extern const f32 lbl_805DE560;
extern const f32 lbl_805DE564;
extern const f32 lbl_805DE568;
extern const f32 lbl_805DE570;
extern const f32 lbl_805DE574;
extern const f32 lbl_805DE578;

void *TAdMultiPlyChrSelectGC__data_804E0A48[4] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TAdMultiPlyChrSelectGC__selected_slot_order[4] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
s32 TAdMultiPlyChrSelectGC__data_804E0A68[6][5] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};
void *TAdMultiPlyChrSelectGC__data_804E0AE0[4] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TAdMultiPlyChrSelectGC__data_804E0AF0[4] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
#define TAdMultiPlyChrSelectGC__data_804E0A48 (*(RecoveredGlobal_802C658C_TAdMultiPlyChrSelectGC__data_804E0A48 *)TAdMultiPlyChrSelectGC__data_804E0A48)
#define TAdMultiPlyChrSelectGC__selected_slot_order ((s32 *)TAdMultiPlyChrSelectGC__selected_slot_order)
#define TAdMultiPlyChrSelectGC__data_804E0AE0 ((s32 *)TAdMultiPlyChrSelectGC__data_804E0AE0)
#define TAdMultiPlyChrSelectGC__data_804E0AF0 ((f32 *)TAdMultiPlyChrSelectGC__data_804E0AF0)

#pragma push
#pragma fp_contract on
void TAdMultiPlyChrSelectGC__sub_802C50EC(s32 arg0) {
    S_802C50EC *self = (S_802C50EC *)arg0;
    u32 i;
    Quad_802C50EC q;
    for (i = 0; i < 4; i++) {
        if (TAdMultiPlyChrSelectGC__data_804E0AE0[i] == 1) {
            begin_screen_draw(1);
            TObjFish::set_global_param(lbl_805D67D0);
            set_draw_texture_and_color(0, ((s32)(lbl_805DE564 * TAdMultiPlyChrSelectGC__data_804E0AF0[i] + lbl_805DE560) << 24) | 0xFFFFFF);
            q.u0 = self->quad[i + 4][0].u0;
            q.u1 = self->quad[i + 4][0].u1;
            q.v0 = self->quad[i + 4][0].v0;
            q.v1 = self->quad[i + 4][0].v1;
            q.x = lbl_805DE568 + self->quad[i + 4][0].x;
            q.z = lbl_805DE568 + self->quad[i + 4][0].z;
            q.y = self->quad[i + 4][0].y;
            q.w = self->quad[i + 4][0].w;
            if (q.x > TAdMultiPlyChrSelectGC__data_805DE56C) {
                draw_textured_quad_at_depth(&q.x, lbl_805DE570);
            }
            TAdMultiPlyChrSelectGC__data_804E0AF0[i] += lbl_805DE574;
            TAdMultiPlyChrSelectGC__data_804E0AF0[i] = TAdMultiPlyChrSelectGC__data_804E0AF0[i] >= lbl_805DE578 ? lbl_805DE578 : TAdMultiPlyChrSelectGC__data_804E0AF0[i];
            TWindowSubStatusDisp::get_player();
        }
    }
}

void TAdMultiPlyChrSelectGC__sub_802C522C(s32 arg0) {
    S_802C50EC *self = (S_802C50EC *)arg0;
    u32 i;
    for (i = 0; i < 4; i++) {
        if (TAdMultiPlyChrSelectGC__data_804E0AE0[i] == 1) {
            s32 alpha = (s32)(lbl_805DE564 * TAdMultiPlyChrSelectGC__data_804E0AF0[i] + lbl_805DE560);
            begin_screen_draw(1);
            TObjFish::set_global_param(lbl_805D67D0);
            set_draw_texture_and_color(0, (alpha << 24) | 0xFFFFFF);
            draw_textured_quad_at_depth(&self->quad[i + 4][0].x, lbl_805DE570);
            TWindowSubStatusDisp::get_player();
            TAdMultiPlyChrSelectGC__data_804E0AF0[i] += lbl_805DE574;
            TAdMultiPlyChrSelectGC__data_804E0AF0[i] = TAdMultiPlyChrSelectGC__data_804E0AF0[i] >= lbl_805DE578 ? lbl_805DE578 : TAdMultiPlyChrSelectGC__data_804E0AF0[i];
        }
    }
}
#pragma pop

void TAdMultiPlyChrSelectGC::draw_selection_cursors() {
    S_802C5314 *self = (S_802C5314 *)this;
    u32 i;
    u32 j;
    s32 n;
    s32 m;
    if (TAdMultiPlyChrSelectGC__select_mode == 0) {
        n = TAdMultiPlyChrSelectGC::count_ready();
        m = TAdMultiPlyChrSelectGC__sub_802C6558();
        if (m == n) {
            return;
        }
    }
    if (TAdMultiPlyChrSelectGC__select_mode == 1) {
        TAdMultiPlyChrSelectGC::get_state();
        TAdMultiPlyChrSelectGC::get_state();
        if (get_field_20__22TAdMultiPlyChrSelectGCFv() < 0xD) {
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (self->y[i][j] != 0) {
                self->r324[0] = lbl_805DE57C + self->e[i][j].x;
                self->r324[2] = self->e[i][j].z - lbl_805DE57C;
                self->r324[1] = self->e[i][j].y;
                self->r324[3] = self->e[i][j].w;
                self->r344[0] = self->e[i][j].x;
                self->r344[2] = lbl_805DE57C + self->r344[0];
                self->r344[1] = self->e[i][j].y;
                self->r344[3] = self->e[i][j].w;
                self->r364[0] = self->e[i][j].z - lbl_805DE57C;
                self->r364[2] = lbl_805DE57C + self->r364[0];
                self->r364[1] = self->e[i][j].y;
                self->r364[3] = self->e[i][j].w;
                set_color_blending_mode(0, 8);
                set_color_blending_mode(1, 0xA);
                begin_screen_draw(1);
                TObjFish::set_global_param(lbl_805D67D4);
                set_draw_texture_and_color(0, self->sel[i][j]);
                draw_textured_quad_at_depth(self->r324, lbl_805DE580);
                draw_textured_quad_at_depth(self->r344, lbl_805DE580);
                draw_textured_quad_at_depth(self->r364, lbl_805DE580);
                TWindowSubStatusDisp::get_player();
                set_color_blending_mode(0, 8);
                set_color_blending_mode(1, 6);
            }
        }
    }
}

void TAdMultiPlyChrSelectGC::update() {
    s32 arg0 = (s32)this;
    if (TMainTask::get_render_pass() != 1) {
        draw_selection_cursors();
        switch ((s32) TAdMultiPlyChrSelectGC__select_mode) {
        case 0:
            TAdMultiPlyChrSelectGC__sub_802C522C(arg0);
            return;
        case 1:
            TAdMultiPlyChrSelectGC__sub_802C50EC(arg0);
            break;
        }
    }
}

u32 get_multiplayer_controller_active_index(int param_1) {
  int iVar3;
  int iVar2;
  int iVar1;
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < param_1 + 1; iVar2 = iVar2 + 1) {
    iVar1 = TAdMultiPlyChrSelectGC__sub_802C6848(iVar2);
    if (iVar1 == 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return param_1 - iVar3 & ~(param_1 - iVar3 >> 0x1f);
}

void TAdMultiPlyChrSelectGC::reset_cursor_state() {
    S_802C5594 *arg0 = (S_802C5594 *)this;
    u32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        TAdMultiPlyChrSelectGC__data_804E0AE0[i] = 0;
        TAdMultiPlyChrSelectGC__data_804E0AF0[i] = TAdMultiPlyChrSelectGC__data_805DE56C;
        for (j = 0; j < 3; j++) {
            arg0->y[i][j] = 0;
            arg0->x[j] = 0;
        }
    }
    (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) = 0;
    arg0->f530 = 0;
}

void TAdMultiPlyChrSelectGC__sub_802C561C(S_802C50EC *self) {
    V2_802C50EC pos;
    TAdPlyPltAnimCtrlGC *anim;
    pos.x = self->quad[self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC]][self->f4EC].x;
    pos.y = self->quad[self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC]][self->f4EC].y;
    anim = (TAdPlyPltAnimCtrlGC *)TAdMultiPlyChrSelectGC::get_selected_slot();
    if (anim != NULL) {
        anim->init(&pos);
    }
}

void TAdMultiPlyChrSelectGC::init_slot_position(s32 arg1, s32 arg2, s32 arg3) {
    S_802C5944 *arg0 = (S_802C5944 *)this;
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv(&arg0->v[arg2][arg3]);
    arg0->e[arg2][arg3].x = arg0->v[arg2][arg3].x;
    arg0->e[arg2][arg3].y = arg0->v[arg2][arg3].y;
    arg0->e[arg2][arg3].x = arg0->v[arg2][arg3].x + arg0->ox;
    arg0->e[arg2][arg3].y = arg0->v[arg2][arg3].y + arg0->oy;
    arg0->a[arg2][arg3] = 0;
}

void TAdMultiPlyChrSelectGC::clear_slot_entries(s32 arg1) {
    S_802C59EC *arg0 = (S_802C59EC *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        arg0->a[i][arg1] = 0;
        TAdMultiPlyChrSelectGC__data_804E0AF0[i] = TAdMultiPlyChrSelectGC__data_805DE56C;
        arg0->b[i][arg1] = 0;
    }
    arg0->f4DC[arg1] = 0;
}

/* src is passed through untouched to copy_vec2 as its second argument. */
void TAdMultiPlyChrSelectGC__sub_802C5A44(S_802C50EC *self, const void *src, s32 col) {
    if ((u32)self->f4DC[col] < 4) {
        copy_vec2__28TWindowSubSymbolChatPartsSetFPv(&self->home[self->f4DC[col]][col]);
        self->quad[self->f4DC[col]][col].x = self->home[self->f4DC[col]][col].x;
        self->quad[self->f4DC[col]][col].y = self->home[self->f4DC[col]][col].y;
        self->quad[self->f4DC[col]][col].z = self->home[self->f4DC[col]][col].x + self->ox;
        self->quad[self->f4DC[col]][col].w = self->home[self->f4DC[col]][col].y + self->oy;
        self->a[self->f4DC[col]][col] = 0;
        self->b[self->f4DC[col]][col] = 1;
        self->f4DC[col]++;
    }
}

void TAdMultiPlyChrSelectGC::reset_slot_selection_table() {
    u32 i;
    s32 j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            TAdMultiPlyChrSelectGC__data_804E0A68[i][j] = multi_ply_chr_select_default_slot_table[i][j];
        }
    }
}

void TAdMultiPlyChrSelectGC::split_slot_index(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 var_r3;
    var_r3 = TAdMultiPlyChrSelectGC__sub_802C658C(arg0);
    *arg1 = var_r3 > 3;
    if (var_r3 > 3) {
        var_r3 -= 4;
    }
    *arg2 = var_r3;
}

void TAdMultiPlyChrSelectGC::find_first_open_cell(s32 arg0, u32 *arg1) {
    u32 p;
    s32 q;
    for (p = 1; p < 3; p++) {
        for (q = 1; q < 5; q++) {
            if (TAdMultiPlyChrSelectGC__data_804E0A68[q][p] == 1) {
                arg1[0] = q;
                arg1[1] = p;
                return;
            }
        }
    }
}

#define WIN_802C6008 ((void *)(controller_physical_port_bank + TAdMultiPlyChrSelectGC__selected_slot * 0x50 + 0x20))

void TAdMultiPlyChrSelectGC::move_cursor(s32 x_, s32 y_, s32 dx, s32 dy, s32 depth) {
    Self_802C5C84 *self = (Self_802C5C84 *)this;
    s32 x = x_;
    s32 y = y_;
    s32 dir;
    s32 nx;
    s32 ny;
    s32 cnt;
    s32 k;
    x++;
    y++;
    if (dy == -1) dir = 0;
    if (dy == 1) dir = 1;
    if (dx == -1) dir = 2;
    if (dx == 1) dir = 3;
    ny = y + dy;
    nx = x + dx;
    if (TAdMultiPlyChrSelectGC__data_804E0A68[ny][nx] == 1) {
        x += dx;
        y += dy;
        play_sound_effect(0x54100, NULL, 0, 0);
        self->f4EC = x - 1;
        self->f4AC[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC] = y - 1;
        return;
    }
    if (TAdMultiPlyChrSelectGC__data_804E0A68[ny][nx] == 0) {
        Jump_802C5C84 j = multi_chr_select_cursor_jump_table[ny][nx];
        switch (dir) {
        case 0:
        case 1:
            ny += j.v[dir];
            break;
        case 2:
        case 3:
            nx += j.v[dir];
            break;
        }
        ny -= dy;
        nx -= dx;
        move_cursor(nx - 1, ny - 1, dx, dy, depth - 1);
        return;
    }
    if (TAdMultiPlyChrSelectGC__data_804E0A68[ny][nx] == -1) {
        if (dy != 0) {
            cnt = 0;
            for (k = 0; k < 4; k++) {
                if (TAdMultiPlyChrSelectGC__data_804E0A68[k + 1][self->f4EC + 1] == -1) {
                    cnt++;
                }
            }
            if (cnt == 4) {
                nx = 3 - x;
                move_cursor(nx - 1, y - 1, dx, dy, 4);
            } else {
                move_cursor(nx - 1, ny - 1, dx, dy, 4);
            }
            return;
        }
        cnt = 0;
        for (k = 0; k < 4; k++) {
            if (TAdMultiPlyChrSelectGC__data_804E0A68[k + 1][nx] == -1) {
                cnt++;
            }
        }
        if (cnt == 4) {
            return;
        }
        switch (x) {
        case 0:
            nx = 1;
            break;
        case 3:
            nx = 2;
            break;
        default:
            nx = 3 - x;
            break;
        }
        if (y < 3) {
            ny = 0;
            dx = 0;
            dy = 1;
        } else {
            ny = 5;
            dx = 0;
            dy = -1;
        }
        move_cursor(nx - 1, ny - 1, dx, dy, 4);
    }
}

void TAdMultiPlyChrSelectGC::update_option_cursor() {
    S_802C6008 *self = (S_802C6008 *)this;
    TAdMultiPlyChrSelectGC__sub_802C5F1C(self, self->f1C++);
    if (self->f4DC[self->f4EC] != 0 && self->f4F8 == 0) {
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C6008, 0x10, 6, 1) != 0) {
            play_sound_effect(0x54100, 0, 0, 0);
            self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC]--;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C6008, 0x20, 6, 1) != 0) {
            play_sound_effect(0x54100, 0, 0, 0);
            self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC]++;
        }
        if (self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC] > self->f4DC[self->f4EC] - 1) {
            self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC] = 0;
        }
        if (self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC] < 0) {
            self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC] = self->f4DC[self->f4EC] - 1;
        }
    }
    if (TWindowShortListCtrl__check_controller_button(WIN_802C6008, 4) != 0 && self->f4F8 == 0) {
        self->f4F8 = 1;
    }
}

#define WIN_802C61E4 ((void *)(controller_physical_port_bank + TAdMultiPlyChrSelectGC__data_805D67D8 * 0x50 + 0x20))
void TAdMultiPlyChrSelectGC::handle_dpad_input() {
    S_802C61E4 *self = (S_802C61E4 *)this;
    s32 n;
    s32 m;
    TAdMultiPlyChrSelectGC__sub_802C5F1C(self, self->f1C++);
    n = TAdMultiPlyChrSelectGC::count_ready();
    m = TAdMultiPlyChrSelectGC__sub_802C6558();
    if (m != n && self->f4DC[self->f4EC] != 0 && self->f4F8 == 0) {
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x10, 6, 1) != 0) {
            move_cursor(self->f4EC, self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC], 0, -1, self->f4DC[self->f4EC]);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x20, 6, 1) != 0) {
            move_cursor(self->f4EC, self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC], 0, 1, self->f4DC[self->f4EC]);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x80, 6, 1) != 0) {
            move_cursor(self->f4EC, self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC], 1, 0, 2);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x40, 6, 1) != 0) {
            move_cursor(self->f4EC, self->sel[TAdMultiPlyChrSelectGC__data_805D67D8][self->f4EC], -1, 0, 2);
        }
    }
    if (TWindowShortListCtrl__check_controller_button(WIN_802C61E4, 4) != 0 && self->f4F8 == 0) {
        self->f4F8 = 1;
    }
}

void TAdMultiPlyChrSelectGC::init() { TAdMultiPlyChrSelectGC__data_805D67D8 = TAdMultiPlyChrSelectGC__sub_802C6920(); TAdMultiPlyChrSelectGC__sub_802C6920(); ((int (*)(void))TAdMultiPlyChrSelectGC__sub_802C65C0)(); }
s32 TAdMultiPlyChrSelectGC::get_status() {
    s32 var_r3 = (s32) (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8);
    if (var_r3 == 0) {
        return 0;
    }
    switch ((s32) TAdMultiPlyChrSelectGC__select_mode) {
    case 0:
        return var_r3;
    case 1:
        return (s32) TAdMultiPlyChrSelectGC__selected_slot;
    default:
        return 0;
    }
}
s32 TAdMultiPlyChrSelectGC::is_selection_confirmed() {
    if (TAdMultiPlyChrSelectGC__sub_80299454() != 0) {
        if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
            return ((s32)TAdMultiPlyChrSelectGC__sub_802C6920());
        }
        return 0;
    }
    return 0;
}

typedef char RecoveredGlobal_802C64D0_TAdMultiPlyChrSelectGC__data_804E0A48_size[sizeof(RecoveredGlobal_802C64D0_TAdMultiPlyChrSelectGC__data_804E0A48) == 0x10 ? 1 : -1];
bool is_multiplayer_character_slot_selected(s32 arg0) {
    if ((arg0 < 0) || ((u32) arg0 > 3U)) {
        return 0;
    }
    return ((s32 *)&TAdMultiPlyChrSelectGC__data_804E0A48)[arg0] != -1;
}

s32 TAdMultiPlyChrSelectGC::count_ready() {
    s32 var_r31;
    s32 var_r30;
    var_r31 = 0;
    var_r30 = 0;
    do {
        if (TAdMultiPlyChrSelectGC__sub_802C6848(var_r30) != 0) {
            var_r31 += 1;
        }
        var_r30 += 1;
    } while (var_r30 < 4);
    return var_r31;
}

s32 TAdMultiPlyChrSelectGC__sub_802C6558(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((s32 *)&TAdMultiPlyChrSelectGC__data_804E0A48)[i] != -1) n++;
    }
    return n;
}

s32 TAdMultiPlyChrSelectGC__sub_802C658C(s32 arg0) {
    s32 temp_r3;
    s32 var_r3;
    var_r3 = arg0;
    if ((var_r3 > 3) || (var_r3 < 0)) {
        var_r3 = 3;
    }
    temp_r3 = *(s32 *)((s8 *)((u8 *)&TAdMultiPlyChrSelectGC__data_804E0A48.value + (var_r3 * 4)) + 0);
    if (temp_r3 == -1) {
        return 0;
    }
    return temp_r3;
}

void TAdMultiPlyChrSelectGC__sub_802C65C0(s32 arg0) {
    s32 c;
    s32 r;
    TAdMultiPlyChrSelectGC__data_804E0AE0[arg0] = 0;
    TAdMultiPlyChrSelectGC__data_804E0AF0[arg0] = TAdMultiPlyChrSelectGC__data_805DE56C;
    TAdMultiPlyChrSelectGC::split_slot_index(arg0, &c, &r);
    s32 ri = r + 1;
    s32 ci = c + 1;
    TAdMultiPlyChrSelectGC__data_804E0A68[ri][ci] = multi_ply_chr_select_default_slot_table[ri][ci];
    ((s32 *)&TAdMultiPlyChrSelectGC__data_804E0A48)[arg0] = -1;
    TAdMultiPlyChrSelectGC::remove_selected_slot(arg0);
}

typedef char RecoveredGlobal_802C6848_lbl_804E0B00_size[sizeof(RecoveredGlobal_802C6848_lbl_804E0B00) == 0x10 ? 1 : -1];
s32 TAdMultiPlyChrSelectGC__sub_802C6848(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 3)) {
        return 0;
    }
    return *(s32 *)((s8 *)(*(s32 **)((s8 *)(TKeyBoardControl__sub_803DEB74(*(u32 *)((s8 *)((u8 *)&multiplayer_controller_device_codes.value + (arg0 * 4)) + 0))) + 0x30)) + 0) & 1;
}

void TAdMultiPlyChrSelectGC::remove_selected_slot(s32 arg0) {
    u32 i;
    u32 j;
    for (i = 0; i < 4; i++) {
        if (arg0 == TAdMultiPlyChrSelectGC__selected_slot_order[i]) {
            for (j = i; j < 4; j++) {
                if (j < 3) {
                    TAdMultiPlyChrSelectGC__selected_slot_order[j] = TAdMultiPlyChrSelectGC__selected_slot_order[j + 1];
                }
            }
            TAdMultiPlyChrSelectGC__selected_slot_order[3] = -1;
            return;
        }
    }
}

int TAdMultiPlyChrSelectGC__sub_802C6920(void) {
    s32 i;
    s32 slot;
    if (TAdMultiPlyChrSelectGC__data_805D67D8 < 0 || (u32)TAdMultiPlyChrSelectGC__data_805D67D8 >= 4) {
        TAdMultiPlyChrSelectGC__data_805D67D8 = 0;
    }
    for (i = 3; i >= 0; i--) {
        slot = TAdMultiPlyChrSelectGC__selected_slot_order[i];
        if (slot != -1) {
            s32 result = slot;
            if (result < 0 || (u32)result > 4) {
                result = 0;
            }
            return result;
        }
    }
    return 0;
}

void TAdMultiPlyChrSelectGC::add_selected_slot() {
    s32 i;
    if ((*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) < 0 || (u32)(*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) >= 4) {
        (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) = 0;
    }
    for (i = 0; i < 4; i++) {
        if (TAdMultiPlyChrSelectGC__selected_slot_order[i] == -1) {
            TAdMultiPlyChrSelectGC__selected_slot_order[i] = (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8);
            return;
        }
    }
    TAdMultiPlyChrSelectGC__selected_slot_order[3] = (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8);
}

s32 TAdMultiPlyChrSelectGC::get_clamped_cursor() {
    if (((s32) (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) < 0) || ((s32) (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) > 3)) {
        (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) = 0;
    }
    return (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8);
}

void TAdMultiPlyChrSelectGC::reset_slot_selections() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TAdMultiPlyChrSelectGC__data_804E0A48)[i] = -1;
        TAdMultiPlyChrSelectGC__selected_slot_order[i] = -1;
    }
    TAdMultiPlyChrSelectGC::reset_slot_selection_table();
    (*(s32 *)&TAdMultiPlyChrSelectGC__data_805D67D8) = 0;
}

s32 find_active_slot__22TAdMultiPlyChrSelectGCFv(void) {
    s32 var_r31;
    var_r31 = 0;
loop_1:
    if ((TAdMultiPlyChrSelectGC__sub_802C6848(var_r31) != 0) && (((s32 (*)(s32))is_multiplayer_character_slot_selected)(var_r31) == 0)) {
        return var_r31;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return 3;
    }
    goto loop_1;
}
#define FIND_SLOT(o) ((s32 (*)(void *))find_active_slot__22TAdMultiPlyChrSelectGCFv)(o)
void TAdMultiPlyChrSelectGC::update_selection() {
    S_802C6AC8 *o = (S_802C6AC8 *)this;
    u32 i;
    u32 j;
    u32 k;
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0 && *(s32 *)&this->m_20 < TAdMultiPlyChrSelectGC::count_ready()) {
        TAdMultiPlyChrSelectGC__data_805D67D8 = FIND_SLOT(o);
        switch (TAdMultiPlyChrSelectGC__select_mode) {
        case 1:
            break;
        case 0: {
            u32 buf[2];
            TAdMultiPlyChrSelectGC::find_first_open_cell((s32)o, buf);
            o->f4EC = buf[1] - 1;
            o->sel[TAdMultiPlyChrSelectGC__data_805D67D8][o->f4EC] = buf[0] - 1;
            break;
        }
        }
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(0) == 0 || TAdMultiPlyChrSelectGC::count_ready() < 2) {
        o->f534 = 0;
    } else {
        o->f534 = 1;
    }
    if (o->f534 != 0) {
        switch (TAdMultiPlyChrSelectGC__select_mode) {
        case 0:
            ((TAdMultiPlyChrSelectGC *)o)->handle_dpad_input();
            if (TAdMultiPlyChrSelectGC::get_clamped_cursor() == 3 && ((s32 (*)(s32))is_multiplayer_character_slot_selected)(3) != 0) {
                s32 n = TAdMultiPlyChrSelectGC::count_ready();
                if (TAdMultiPlyChrSelectGC__sub_802C6558() < n) {
                    TAdMultiPlyChrSelectGC__data_805D67D8 = FIND_SLOT(o);
                }
            }
            break;
        case 1:
            ((TAdMultiPlyChrSelectGC *)o)->update_option_cursor();
            break;
        }
    }
    o->f530 = 0;
    if (o->f534 != 0) {
        for (i = 0; i < 4; i++) {
            if (TWindowShortListCtrl__check_controller_button(((Pad_802C6AC8 *)controller_physical_port_bank)[i].ctl, 8) != 0 && TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
                o->f530 = 1;
            }
        }
    }
    for (k = 0; k < 4; k++) {
        for (j = 0; j < 3; j++) {
            o->alpha[k][j] -= 0x16;
            if (o->alpha[k][j] < 0) {
                o->alpha[k][j] = 0;
            }
        }
    }
    o->alpha[o->sel[TAdMultiPlyChrSelectGC__data_805D67D8][o->f4EC]][o->f4EC] = 0xFF;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            o->col[i][j] = (o->alpha[i][j] << 24) | 0xFFFFFF;
        }
    }
    if (o->f4FC != 0) {
        o->f4F8 = 0;
        o->f4FC = 0;
    }
    *(s32 *)&this->m_20 = TAdMultiPlyChrSelectGC::count_ready();
}

typedef char RecoveredGlobal_802C658C_TAdMultiPlyChrSelectGC__data_804E0A48_size[sizeof(RecoveredGlobal_802C658C_TAdMultiPlyChrSelectGC__data_804E0A48) == 0x10 ? 1 : -1];

}
