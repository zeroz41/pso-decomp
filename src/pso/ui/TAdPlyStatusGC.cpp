#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/TChCrLoadAfs.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/TAdGuideButtonGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"

struct RecoveredGlobal_8033F93C_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_8033FB8C___vt__14TAdPlyStatusGC { s32 value; u8 remaining[0x14]; };

struct RecoveredFields_8033F9DC_arg0 {
    u8 unknown_0[0x1C];
    s32 field_1C;
    u8 unknown_20[0x4C];
    u32 field_6C;
};

struct RecoveredGlobal_8033F9DC_lbl_804783E0 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8033F9DC_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Elem_8033FC14 {
    s32 mode;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 handle;
};

struct TAdPlyStatusGC_8033FC14 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    s32 f1C;
    s32 f20;
    Elem_8033FC14 elems[2];
    s32 f6C;
};

struct Card_8033F6A8 {
    u8 pad0[0x30];
    s8 f30;
    s8 f31;
    s8 f32;
    u8 pad33[0x1D];
};

struct Save_8033F6A8 { u8 pad[0xC]; u32 fC; };

extern "C" {
s32 allow_rendering__7TObjectFv();
s32 TWindowShortListCtrl__check_controller_button(void *, int, int);
void TWindow__close(u8 *arg0);
u32 get_player_index__14TAdPlyStatusGCFv();
extern RecoveredGlobal_8033F93C_lbl_8050E3B8 controller_physical_port_bank;
extern s32 TAdPlyStatusGC__window_offset_index;
extern s32 TAdPlyStatusGC__is_shown;
void update_hidden__14TAdPlyStatusGCFv(u8 *arg0);
u8 * __dt__7TObjectFv(void *, s16);
void queue_destruction__7TObjectFv(void *);
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_8033FB8C___vt__14TAdPlyStatusGC __vt__14TAdPlyStatusGC;
extern u32 ply_status_gc_instance;
u8 *__dt__14TAdPlyStatusGCFv(u8 *arg0, s16 arg1);
void update_shown__14TAdPlyStatusGCFv(struct RecoveredFields_8033F9DC_arg0 *arg0);
void set_load_state__14TAdPlyStatusGCFPvi(u8 *arg0, s32 arg1);
void set_field_1c__6TLobbyFf(f32);
s32 create_callback__22TAdEnterSerialAccessGCFPvPvPv(void *, void *, void *);
void draw_status_window__14TAdPlyStatusGCFPvPv(void *arg0, void *arg1);
extern u8 lbl_804783D8[];
extern const f32 lbl_805DFAEC;
s32 TAdPlyStatusGC__sub_8033F8B0(void *arg0, void *arg1);
s32 disallow_rendering__7TObjectFv();
s32 get_localized_text_entry(s32 arg0, s32 arg1);
void __ct__7TObjectFP7TObject(void *, void *);
void *__construct_array(void *, void *, void *, u32, u32);
extern s32 lbl_805D42C0;
extern s32 ply_status_chcr_load_afs;
extern const f32 lbl_805DFAF0;
extern const f32 lbl_805DFAF4;
TAdPlyStatusGC_8033FC14 *TAdPlyStatusGC__ct(TAdPlyStatusGC_8033FC14 *self, void *parent, s32 arg2);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i);
s32 get_entry__23TAdSinglePlyChrSelectGCFi(s32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i);
s32 get_character_save_record(u32 arg0);
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
}
s32 get_class_name_text(s32 arg0);
extern "C" {
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(s32);
int sprintf(char *, const char *, ...);
void *memset(void *, int, u32);
extern char lbl_80478408[];
extern u32 ply_status_index;
extern char lbl_805DFAE8[4];
void format_status_strings__14TAdPlyStatusGCFPv(char *buf);
u32 ply_status_gc_instance;
s32 ply_status_chcr_load_afs;
s32 TAdPlyStatusGC__window_offset_index;
u32 ply_status_index;
s32 TAdPlyStatusGC__is_shown;
void close_window__14TAdPlyStatusGCFv(void *arg0);
void render__14TAdPlyStatusGCFv(void* p);

void *TAdPlyStatusGC__status_window_box[8] = {
    (void *)0x42a60000, (void *)0x41200000, (void *)0x42e60000, (void *)0x42280000,
    (void *)0x0, (void *)0x0, (void *)0x3f800000, (void *)0x3f800000,
};
void *ply_status_window_points_first[6] = {
    (void *)0x40800000, (void *)0x42280000, (void *)0x40800000, (void *)0x42780000,
    (void *)0x40800000, (void *)0x42a40000,
};
void *ply_status_window_points_second[6] = {
    (void *)0x42700000, (void *)0x42280000, (void *)0x42700000, (void *)0x42780000,
    (void *)0x42700000, (void *)0x42a40000,
};
void render__14TAdPlyStatusGCFv(void* p) { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

typedef char RecoveredGlobal_8033F93C_lbl_8050E3B8_size[sizeof(RecoveredGlobal_8033F93C_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

#define TAdPlyStatusGC__status_window_box (*(Box_8033F3D8 *)TAdPlyStatusGC__status_window_box)
#define ply_status_window_points_first ((Vec2_8033F3D8 *)ply_status_window_points_first)
#define ply_status_window_points_second ((Vec2_8033F3D8 *)ply_status_window_points_second)
#define OFF_8033F3D8 (ply_status_window_offset_table[TAdPlyStatusGC__window_offset_index])
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec2_8033F3D8 { f32 x, y; };
struct Box_8033F3D8 { f32 v[8]; };
struct Item_8033F3D8 { s8 valid; u8 pad[0xF]; };
struct Status_8033F3D8 { u8 pad[8]; u32 f8; };

void draw_window_frame__13TUnk_804CE018FPv(void *);
Status_8033F3D8 **get_status_sub__14TAdPlyStatusGCFv(s32);
extern const f32 lbl_805DFAE0;
extern const f32 lbl_805DFAE4;
extern Vec2_8033F3D8 ply_status_window_offset_table[];
void draw_status_window__14TAdPlyStatusGCFPvPv(void *arg0, void *arg1) {
    Item_8033F3D8 items[3];
    Box_8033F3D8 box;
    Vec2_8033F3D8 pts[3];
    Vec2_8033F3D8 pts2[3];
    s32 i;

    draw_window_frame__13TUnk_804CE018FPv(arg0);
    if ((u32)ply_status_chcr_load_afs != 0 && ((TChCrLoadAfs *)ply_status_chcr_load_afs)->is_unloaded() != 0 && TAdPlyStatusGC__is_shown != 0 &&
        (*get_status_sub__14TAdPlyStatusGCFv(ply_status_chcr_load_afs))->f8 != 0) {
        box = TAdPlyStatusGC__status_window_box;
        box.v[0] = TAdPlyStatusGC__status_window_box.v[0] + OFF_8033F3D8.x;
        box.v[2] = TAdPlyStatusGC__status_window_box.v[2] + OFF_8033F3D8.x;
        box.v[1] = TAdPlyStatusGC__status_window_box.v[1] + OFF_8033F3D8.y;
        box.v[3] = TAdPlyStatusGC__status_window_box.v[3] + OFF_8033F3D8.y;
        TObjFish::set_global_param((s32)(get_status_sub__14TAdPlyStatusGCFv(ply_status_chcr_load_afs)));
        begin_screen_draw(1);
        set_draw_texture_and_color(0, -1);
        draw_textured_quad_at_depth((f32 *)&box, lbl_805DFAE0);
        TWindowSubStatusDisp::get_player();
    }
    format_status_strings__14TAdPlyStatusGCFPv((char *)items);
    set_text_draw_params((s32)arg1, 1, 1, (f32)lbl_805DFAE0, (f32)lbl_805DFAE4);
    for (i = 0; i < 3; i++) {
        pts[i].x = ply_status_window_points_first[i].x + OFF_8033F3D8.x;
        pts[i].y = ply_status_window_points_first[i].y + OFF_8033F3D8.y;
    }
    draw_window_text((f32 *)&pts[0], (const char *)((void *)get_localized_text_entry(0x26, 1)), -1, 0, (f32)lbl_805DFAE4);
    draw_window_text((f32 *)&pts[1], (const char *)((void *)get_localized_text_entry(0x26, 2)), -1, 0, (f32)lbl_805DFAE4);
    draw_window_text((f32 *)&pts[2], (const char *)((void *)get_localized_text_entry(0x26, 3)), -1, 0, (f32)lbl_805DFAE4);
    for (i = 0; i < 3; i++) {
        pts2[i].x = ply_status_window_points_second[i].x + OFF_8033F3D8.x;
        pts2[i].y = ply_status_window_points_second[i].y + OFF_8033F3D8.y;
    }
    if (items[0].valid == 0 || items[1].valid == 0 || items[2].valid == 0) {
        return;
    }
    draw_window_text((f32 *)&pts2[0], (const char *)&items[0], -1, 0, (f32)lbl_805DFAE4);
    draw_window_text((f32 *)&pts2[1], (const char *)&items[1], -1, 0, (f32)lbl_805DFAE4);
    draw_window_text((f32 *)&pts2[2], (const char *)&items[2], -1, 0, (f32)lbl_805DFAE4);
}
#undef OFF_8033F3D8
#define ply_status_window_offset_table (*(RecoveredGlobal_8033F9DC_lbl_804783E0 *)ply_status_window_offset_table)
#undef TAdPlyStatusGC__status_window_box
#undef ply_status_window_points_first
#undef ply_status_window_points_second

void format_status_strings__14TAdPlyStatusGCFPv(char *buf) {
    u8 *c;
    u32 time;
    u32 mins;
    s32 flags;
    u32 hours;
    s32 m;
    Save_8033F6A8 *p;
    u32 t;
    memset(buf, 0, 0x10);
    memset(buf + 0x10, 0, 0x10);
    memset(buf + 0x20, 0, 0x10);
    c = 0;
    switch (TAdPlyStatusGC__window_offset_index) {
    case 0:
    case 2:
        p = (Save_8033F6A8 *)get_character_save_record(0xFFFF);
        if (p != 0) {
            time = p->fC;
        }
        c = (u8 *)get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF);
        break;
    case 1:
        p = (Save_8033F6A8 *)TAdSinglePlyChrSelectGC__sub_801FE3E4(ply_status_index);
        if (p != 0) {
            time = p->fC;
        }
        m = TAdMultiPlyChrSelectGC::get_card_instance();
        if (m != 0) {
            if (TAdSinglePlyChrSelectGC__sub_801FE800(TAdMultiPlyChrSelectGC__sub_802DFFE8(m)) != 0) {
                c = (u8 *)get_entry__23TAdSinglePlyChrSelectGCFi(TAdMultiPlyChrSelectGC__sub_802DFFE8(m));
            }
        }
        if (c == 0) {
            return;
        }
        break;
    }
    if (c != 0) {
        Card_8033F6A8 card = *(Card_8033F6A8 *)(c + 0x370);
        t = time / 60;
        hours = t / 60;
        mins = t % 60;
        if (hours > 9999) {
            hours = 9999;
            mins = 59;
        }
        if (mins > 59) {
            mins = 59;
        }
        flags = card.f32;
        if (flags & 2) {
            sprintf(buf, lbl_805DFAE8, get_localized_text_entry(0x26, 0));
        } else {
            sprintf(buf, lbl_805DFAE8, get_class_name_text(card.f31));
        }
        if (flags & 1) {
            sprintf(buf + 0x10, lbl_805DFAE8, get_localized_text_entry(0x26, 0));
        } else {
            sprintf(buf + 0x10, lbl_805DFAE8, TObjLuker::get_stat_table_entry(card.f30));
        }
        sprintf(buf + 0x20, lbl_80478408, hours, mins);
    }
}

s32 TAdPlyStatusGC__sub_8033F8B0(void *arg0, void *ad_enter_serial_access_gc) {
    s32 r = create_callback__22TAdEnterSerialAccessGCFPvPvPv(ad_enter_serial_access_gc, lbl_804783D8, (void *)draw_status_window__14TAdPlyStatusGCFPvPv);
    set_field_1c__6TLobbyFf(lbl_805DFAEC);
    return r;
}

void set_load_state__14TAdPlyStatusGCFPvi(u8 *arg0, s32 arg1) {
    s32 var_r4;
    if (arg1 > 0) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 0) {
            var_r4 = 2;
            if ((s32) TAdPlyStatusGC__is_shown != 0) {
                var_r4 = 1;
            }
            *(s32 *)((s8 *)arg0 + 0x1C) = var_r4;
        }
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
}

void update_hidden__14TAdPlyStatusGCFv(u8 *arg0) {
    s32 temp_r3;
    s32 temp_r5;
    TAdPlyStatusGC__is_shown = 0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x6C) != 0U) {
        TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x6C)));
        *(u32 *)((s8 *)arg0 + 0x6C) = 0U;
    }
    if ((s32) TAdPlyStatusGC__window_offset_index < 3) {
        temp_r3 = ((s32)get_player_index__14TAdPlyStatusGCFv());
        if (temp_r3 != 0) {
            allow_rendering__7TObjectFv();
            ((TAdGuideButtonGC *)temp_r3)->setup_button((GuideButtonSpec *)(arg0 + 0x48));
        }
        temp_r5 = TAdMultiPlyChrSelectGC::get_status() * 0x50;
        if (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_physical_port_bank.value + temp_r5 + 0x20), 0x400, temp_r5) != 0) {
            *(s32 *)((s8 *)arg0 + 0x1C) = 1;
        }
    }
}

typedef char RecoveredGlobal_8033F9DC_lbl_804783E0_size[sizeof(RecoveredGlobal_8033F9DC_lbl_804783E0) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8033F9DC_lbl_8050E3B8_size[sizeof(RecoveredGlobal_8033F9DC_lbl_8050E3B8) == 0x1B0 ? 1 : -1];
void update_shown__14TAdPlyStatusGCFv(struct RecoveredFields_8033F9DC_arg0 *arg0) {
    s32 temp_r3;
    s32 temp_r5;
    TAdPlyStatusGC__is_shown = 1;
    if ((s32) TAdPlyStatusGC__window_offset_index < 3) {
        if ((u32) arg0->field_6C == 0) {
            arg0->field_6C = TAdPlyStatusGC__sub_8033F8B0(arg0, (void *)((s32) ((u8 *)&ply_status_window_offset_table.value + (TAdPlyStatusGC__window_offset_index * 8))));
        }
        temp_r3 = ((s32)get_player_index__14TAdPlyStatusGCFv());
        if (temp_r3 != 0) {
            allow_rendering__7TObjectFv();
            ((TAdGuideButtonGC *)temp_r3)->setup_button((GuideButtonSpec *)(&arg0->unknown_20[4]));
        }
        temp_r5 = TAdMultiPlyChrSelectGC::get_status() * 0x50;
        if (TWindowShortListCtrl__check_controller_button((u8 *)(((u8 *)(&(*(RecoveredGlobal_8033F9DC_lbl_8050E3B8 *)&controller_physical_port_bank).value) + temp_r5)) + 0x20, 0x400, temp_r5) != 0) {
            arg0->field_1C = 2;
        }
    }
}

void close_window__14TAdPlyStatusGCFv(void *arg0) {
    void *temp_r3 = *(void **)((s8 *)arg0 + 0x6C);
    if ((u32) temp_r3 != 0U) {
        TWindow__close((u8 *)temp_r3);
        *(u32 *)((s8 *)arg0 + 0x6C) = 0U;
    }
    if (get_player_index__14TAdPlyStatusGCFv() != 0U) {
        disallow_rendering__7TObjectFv();
    }
}
struct TAdPlyStatusGC {
    u8 pad[0x1C];
    s32 idx;
    s32 last;
    void close_window();
    void update_shown();
    void update_hidden();
};
typedef TAdPlyStatusGC C_8033FAD8;

void run_task__14TAdPlyStatusGCFv(C_8033FAD8 *self) {
    static void (C_8033FAD8::*tbl[3])() = {
        &TAdPlyStatusGC::close_window, &TAdPlyStatusGC::update_shown, &TAdPlyStatusGC::update_hidden,
    };
    (self->*tbl[self->idx])();
    self->last = self->idx;
}
u8 *__dt__14TAdPlyStatusGCFv(u8 *arg0, s16 arg1) {
    u8 *object;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__14TAdPlyStatusGC.value;
        object = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6C));
        if (object != NULL) {
            queue_destruction__7TObjectFv(object);
            *(u8 **)((s8 *)arg0 + 0x6C) = NULL;
        }
        if ((u32) ply_status_gc_instance != 0U) {
            ply_status_gc_instance = 0U;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}
TAdPlyStatusGC_8033FC14 *TAdPlyStatusGC__ct(TAdPlyStatusGC_8033FC14 *self, void *parent, s32 arg2) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = &__vt__14TAdPlyStatusGC;
    __construct_array(self->elems, (void *) init_guide_button_params, 0, 0x24, 2);
    self->f0 = lbl_805D42C0;
    self->f1C = 0;
    self->f20 = self->f1C;
    self->f6C = 0;
    ply_status_chcr_load_afs = 0;
    TAdPlyStatusGC__window_offset_index = arg2;
    TAdPlyStatusGC__is_shown = 1;
    self->elems[0].mode = 2;
    self->elems[0].a = lbl_805DFAF0;
    self->elems[0].b = lbl_805DFAF4;
    self->elems[0].c = lbl_805DFAF0;
    self->elems[0].d = lbl_805DFAF4;
    self->elems[0].handle = get_localized_text_entry(0x26, 4);
    self->elems[0].f14 = 0;
    self->elems[0].f18 = 8;
    self->elems[0].f1C = 0x1E;
    self->elems[1].mode = 2;
    self->elems[1].a = lbl_805DFAF0;
    self->elems[1].b = lbl_805DFAF4;
    self->elems[1].c = lbl_805DFAF0;
    self->elems[1].d = lbl_805DFAF4;
    self->elems[1].handle = get_localized_text_entry(0x26, 5);
    self->elems[1].f14 = 0;
    self->elems[1].f18 = 8;
    self->elems[1].f1C = 0x1E;
    create_guide_button((TObject *)self, (GuideButtonSpec *)self->elems);
    if (get_player_index__14TAdPlyStatusGCFv() != 0U) {
        disallow_rendering__7TObjectFv();
    }
    return self;
}
}
#pragma pop
#undef ply_status_window_offset_table
