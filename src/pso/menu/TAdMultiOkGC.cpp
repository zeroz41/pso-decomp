#include "pso/TAdMultiOkGC.h"
#include "pso/menu/TAdMultiOkGC.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_80141D1C.h"
struct E_80306AC8 { u8 pad[0x1c]; u32 flags; u8 pad2[0xc4 - 0x20]; };
struct O_80306AC8 { E_80306AC8 e[12]; u8 pad[0x97c - 12 * 0xc4]; s32 count; };
extern "C" {
void release_texture_list(void *);
extern unsigned char multi_confirm_texture_archive_name[];
void *multi_confirm_texture_entries[3] = { multi_confirm_texture_archive_name, 0, 0 };
struct MultiConfirmTextureList { void *entries; u32 count; };
__declspec(section ".data") MultiConfirmTextureList multi_confirm_texture_descriptor = { multi_confirm_texture_entries, 1 };
}
#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
struct Ok_80306C10 { u8 pad[0x97C]; s32 count; };

struct Ok_80306F84 { u8 pad[0x97C]; s32 count; };

struct Q_80306C70 { f32 a; f32 b; f32 c; f32 d; u8 pad[0x10]; };

struct E_80306C70 { u8 pad0[0x1C]; s32 flags; s32 t; f32 x; f32 y; u8 pad[0x14]; Q_80306C70 q[4]; u8 pad2[4]; };

struct O_80306C70 { E_80306C70 e[1]; };

struct E_80306DF4 { u8 pad0[0x1C]; s32 flags; s32 t; u8 pad[0xC4 - 0x24]; };

struct O_80306DF4 { E_80306DF4 e[12]; u8 pad[0x1C]; s32 port[4]; u8 pad2[0x980 - 0x95C]; s32 flags; };

struct Ports_80306DF4 { s32 v[4]; };

struct Pad_80306DF4 { u8 pad[0x20]; u8 btn[0x30]; };

struct Q_80306B04 { f32 a; f32 b; f32 c; f32 d; u8 pad[0x10]; };

struct E_80306B04 { u8 pad0[0x1C]; s32 flags; s32 t; f32 x; f32 y; s32 vals[5]; Q_80306B04 q[4]; u8 pad2[4]; };

typedef struct {
    f32 x, y, x2, y2;
    f32 u0, v0, u1, v1;
} Quad_80307034;

typedef struct {
    s32 f0;
    s32 f4;
    f32 x;
    f32 y;
    u32 col[5];
    Quad_80307034 q[5];
} Item_80307034;

typedef struct {
    const char *name;
    u8 pad4[0x18 - 0x04];
    void *vt;
    Item_80307034 items[12];
    s32 idx[12];
    s32 count;
    s32 f980;
} Ok_80307034;

typedef struct {
    s32 count;
    u32 mask;
} Cfg_80307034;

typedef struct { f32 x, y, step; } P3_80307034;

typedef struct { P3_80307034 v[11]; } Pos_80307034;

typedef struct { u32 c[12]; } Col_80307034;

extern const f32 lbl_805DF04C;
extern const f32 lbl_805DF050;
extern const f32 lbl_805DF054;
extern const f32 lbl_805DF058;
extern const f32 lbl_805DF05C;
extern const f32 lbl_805DF060;
extern const f32 lbl_805DF064;
extern "C" {
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 play_sound_effect(int, void *, int, int);
extern Ports_80306DF4 multi_ok_player_port_index_table;
extern Pad_80306DF4 controller_physical_port_bank[];
extern s32 multi_confirm_texture_list;
extern const f32 lbl_805DF040;
extern const f32 lbl_805DF044;
extern const f32 lbl_805DF048;
void __ct__7TObjectFP7TObject(void *, void *);
extern void *__vt__12TAdMultiOkGC[];
extern Pos_80307034 ad_multi_ok_layout_table;
extern Col_80307034 multi_ok_button_colors;
extern const char *lbl_805D4080;
extern const f32 lbl_805DF068;
extern const f32 lbl_805DF06C;
extern const f32 lbl_805DF070;
Ok_80307034 *__ct__12TAdMultiOkGCFv(Ok_80307034 *self, void *parent, Cfg_80307034 *cfg);
}
int multi_confirm_cancel_requested(void* p) { return *(u32*)((char*)p + 0x980) & 0x1; }
extern "C" {

s32 are_all_entries_finished(O_80306AC8 *self) {
    s32 i;
    for (i = 0; i < self->count; i++) {
        if (!(self->e[i].flags & 4)) return 0;
    }
    return 1;
}

#pragma push
#pragma fp_contract on
void TAdMultiOkGC::draw_entry(int arg1) {
    E_80306B04 *e;
    s32 i;
    f32 base;
    e = (E_80306B04 *)this;
    if (e[arg1].flags & 2) {
        begin_screen_draw(1);
        TObjFish::set_global_param(multi_confirm_texture_list);
        e += arg1;
        base = lbl_805DF040 * (f32)arg1;
        for (i = 0; i < 5; i++) {
            set_draw_texture_and_color(0, e->vals[i]);
            if (e->t - (i - 1) >= 0) {
                f32 t = lbl_805DF048 * (f32)i + lbl_805DF044;
                draw_textured_quad_at_depth((f32 *)&e->q[i], t + base);
            }
        }
        TWindowSubStatusDisp::get_player();
    }
}
#pragma pop

void TAdMultiOkGC::render() {
    Ok_80306C10 *o = (Ok_80306C10 *)this;
    s32 i;
    if (TMainTask::get_render_pass() != 1) {
        set_additive_blend();
        for (i = 0; i < o->count; i++) {
            draw_entry(i);
        }
        set_default_alpha_blend();
    }
}
#pragma push
#pragma fp_contract on
void TAdMultiOkGC::update_entry_animation(int arg1) {
    E_80306C70 *e;
    s32 i;
    s32 d;
    f32 f;
    e = &((O_80306C70 *)this)->e[arg1];
    if (e->flags & 2) {
        e->t++;
        for (i = 0; i < 5; i++) {
            d = e->t - (i - 1);
            if (e->flags & 1) {
                if (d > 10) {
                    e->flags |= 4;
                } else if (d >= 0) {
                    f = lbl_805DF04C - lbl_805DF050 * (f32)d;
                    e->q[i].a = lbl_805DF054 * f + e->x;
                    e->q[i].b = lbl_805DF058 * f + e->y;
                    e->q[i].c = lbl_805DF05C * f + e->x;
                    e->q[i].d = lbl_805DF060 * f + e->y;
                }
            } else if (d > 5) {
                e->flags &= ~2;
            } else if (d >= 0) {
                f = lbl_805DF064 - lbl_805DF050 * (f32)d;
                e->q[i].a = lbl_805DF054 * f + e->x;
                e->q[i].b = lbl_805DF058 * f + e->y;
                e->q[i].c = lbl_805DF05C * f + e->x;
                e->q[i].d = lbl_805DF060 * f + e->y;
            }
        }
    }
}
#pragma pop

void TAdMultiOkGC::handle_player_buttons(int arg1) {
    O_80306DF4 *o = (O_80306DF4 *)this;
    Ports_80306DF4 ports = multi_ok_player_port_index_table;
    if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank[ports.v[o->port[arg1]]].btn, 4) != 0) {
        E_80306DF4 *e = &o->e[arg1];
        if (e->flags & 4) {
            e->t = -1;
            e->flags &= ~1;
            e->flags &= ~4;
            play_sound_effect(0x52F16, 0, 0, 0);
        } else if (!(e->flags & 2)) {
            e->t = -1;
            e->flags |= 1;
            e->flags |= 2;
            play_sound_effect(0x52D01, 0, 0, 0);
        }
    } else if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank[ports.v[o->port[arg1]]].btn, 2) != 0) {
        if (!(o->e[arg1].flags & 2)) {
            o->flags |= 1;
            play_sound_effect(0x52F16, 0, 0, 0);
        }
    }
}

void TAdMultiOkGC::run_task() {
    Ok_80306F84 *o = (Ok_80306F84 *)this;
    s32 i;
    for (i = 0; i < o->count; i++) {
        handle_player_buttons(i);
        update_entry_animation(i);
    }
}
}

TAdMultiOkGC::~TAdMultiOkGC() {}
#pragma push
#pragma fp_contract on

Ok_80307034 *__ct__12TAdMultiOkGCFv(Ok_80307034 *self, void *parent, Cfg_80307034 *cfg) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__12TAdMultiOkGC;
    Pos_80307034 pos = ad_multi_ok_layout_table;
    Col_80307034 cols = multi_ok_button_colors;
    s32 n;
    s32 i;
    s32 k;
    self->name = lbl_805D4080;
    self->count = cfg->count;
    self->f980 = 0;
    if (self->count < 2) {
        self->count = 2;
    } else if (self->count > 12) {
        self->count = 12;
    }
    n = 0;
    for (i = 0; i < 12; i++) {
        if (cfg->mask & (1 << i)) {
            self->idx[n++] = i;
            if (n >= self->count) {
                break;
            }
        }
    }
    if (n < self->count) {
        self->count = n;
    }
    for (i = 0; i < self->count; i++) {
        f32 y = pos.v[self->count - 2].y;
        f32 x = pos.v[self->count - 2].x + (f32)i * pos.v[self->count - 2].step;
        u32 a = ((cols.c[self->idx[i]] >> 24) / 5) << 24;
        self->items[i].f0 = 0;
        self->items[i].f4 = -1;
        self->items[i].x = lbl_805DF05C + x;
        self->items[i].y = lbl_805DF060 + y;
        f32 x2;
        f32 y2;
        y2 = lbl_805DF05C + y;
        x2 = lbl_805DF068 + x;
        for (k = 0; k < 5; k++) {
            self->items[i].col[k] = a | (cols.c[self->idx[i]] & 0xFFFFFF);
            self->items[i].q[k].x = x;
            self->items[i].q[k].y = y;
            self->items[i].q[k].x2 = x2;
            self->items[i].q[k].y2 = y2;
            self->items[i].q[k].u0 = lbl_805DF06C;
            self->items[i].q[k].v0 = lbl_805DF06C;
            self->items[i].q[k].u1 = lbl_805DF064;
            self->items[i].q[k].v1 = lbl_805DF070;
        }
    }
    return self;
}
#pragma pop

void free_multi_confirm_textures(void) {
    if ((u32) multi_confirm_texture_list != 0U) {
        release_texture_list((void*)multi_confirm_texture_list);
        multi_confirm_texture_list = 0U;
    }
}
void load_multi_confirm_textures(void) { multi_confirm_texture_list = (int)&multi_confirm_texture_descriptor; TLobby__sub_8023E4B4((s32)multi_confirm_texture_archive_name, (s32)&multi_confirm_texture_descriptor); }
