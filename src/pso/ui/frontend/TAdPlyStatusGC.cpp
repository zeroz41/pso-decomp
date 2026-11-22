#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdGuideButtonGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include <stdio.h>
#include <string.h>

struct RecoveredGlobal_8033FB8C___vt__14TAdPlyStatusGC { s32 value; u8 remaining[0x14]; };

struct RecoveredFields_8033F9DC_arg0 {
    u8 unknown_0[0x1C];
    s32 field_1C;
    u8 unknown_20[0x4C];
    u32 field_6C;
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
    const char *name;
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
extern s32 TAdPlyStatusGC__window_offset_index;
extern s32 TAdPlyStatusGC__is_shown;
void update_hidden__14TAdPlyStatusGCFv(u8 *arg0);
extern RecoveredGlobal_8033FB8C___vt__14TAdPlyStatusGC __vt__14TAdPlyStatusGC;
extern u32 ply_status_gc_instance;
void update_shown__14TAdPlyStatusGCFv(struct RecoveredFields_8033F9DC_arg0 *arg0);
void draw_status_window__14TAdPlyStatusGCFPvPv(void *arg0, void *arg1);
s32 TAdPlyStatusGC__sub_8033F8B0(void *arg0, const void *arg1);
saddr get_localized_text_entry(s32 arg0, s32 arg1);
void __ct__7TObjectFP7TObject(void *, void *);
void *__construct_array(void *, void *, void *, u32, u32);
extern saddr ply_status_chcr_load_afs;
TAdPlyStatusGC_8033FC14 *TAdPlyStatusGC__ct(TAdPlyStatusGC_8033FC14 *self, void *parent, s32 arg2);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i);
saddr get_entry__23TAdSinglePlyChrSelectGCFi(s32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i);
saddr get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
}
s32 get_class_name_text(s32 arg0);
extern "C" {
extern u32 ply_status_index;
u32 ply_status_gc_instance;
saddr ply_status_chcr_load_afs;
s32 TAdPlyStatusGC__window_offset_index;
u32 ply_status_index;
s32 TAdPlyStatusGC__is_shown;
void close_window__14TAdPlyStatusGCFv(void *arg0);
void render__14TAdPlyStatusGCFv(void* p);

// Status window position handed to TAdEnterSerialAccessGC::create_callback.
static const NJS_POINT2 ply_status_window_position = {199.0f, 112.0f};
// Status window offset per TAdPlyStatusGC__window_offset_index.
static const NJS_POINT2 ply_status_window_offset_table[3] = {
    {426.0f, 250.0f},
    {223.0f, 243.0f},
    {223.0f, 243.0f},
};

const char *TAdPlyStatusGC__class_name = "TAdPlyStatusGC";

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

#define TAdPlyStatusGC__status_window_box (*(Box_8033F3D8 *)TAdPlyStatusGC__status_window_box)
#define ply_status_window_points_first ((NJS_POINT2 *)ply_status_window_points_first)
#define ply_status_window_points_second ((NJS_POINT2 *)ply_status_window_points_second)
#define OFF_8033F3D8 (ply_status_window_offset_table[TAdPlyStatusGC__window_offset_index])
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Box_8033F3D8 { f32 v[8]; };
struct Item_8033F3D8 { s8 valid; u8 pad[0xF]; };
struct Status_8033F3D8 { u8 pad[8]; u32 f8; };

void draw_window_frame__11TWindowBaseFPv(void *);
void draw_status_window__14TAdPlyStatusGCFPvPv(void *window_base, void *arg1) {
    Item_8033F3D8 items[3];
    Box_8033F3D8 box;
    NJS_POINT2 pts[3];
    NJS_POINT2 pts2[3];
    s32 i;

    ((TWindowBase *)window_base)->draw_window_frame(arg1);
    if ((u32)ply_status_chcr_load_afs != 0 && ((TChCrLoadAfs *)ply_status_chcr_load_afs)->is_unloaded() != 0 && TAdPlyStatusGC__is_shown != 0 &&
        (*(Status_8033F3D8 **)((TAdPlyStatusGC *)ply_status_chcr_load_afs)->get_status_sub())->f8 != 0) {
        box = TAdPlyStatusGC__status_window_box;
        box.v[0] = TAdPlyStatusGC__status_window_box.v[0] + OFF_8033F3D8.x;
        box.v[2] = TAdPlyStatusGC__status_window_box.v[2] + OFF_8033F3D8.x;
        box.v[1] = TAdPlyStatusGC__status_window_box.v[1] + OFF_8033F3D8.y;
        box.v[3] = TAdPlyStatusGC__status_window_box.v[3] + OFF_8033F3D8.y;
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>((Status_8033F3D8 **)((TAdPlyStatusGC *)ply_status_chcr_load_afs)->get_status_sub()));
        begin_screen_draw(1);
        set_draw_texture_and_color(0, -1);
        draw_textured_quad_at_depth((f32 *)&box, 0.8f);
        TWindowSubStatusDisp::get_player();
    }
    ((TAdPlyStatusGC *)items)->format_status_strings();
    set_text_draw_params(reinterpret_cast<WindowDrawContext *>(arg1), 1, 1, 0.8f, 100000.0f);
    for (i = 0; i < 3; i++) {
        pts[i].x = ply_status_window_points_first[i].x + OFF_8033F3D8.x;
        pts[i].y = ply_status_window_points_first[i].y + OFF_8033F3D8.y;
    }
    draw_window_text((f32 *)&pts[0], (const char *)((void *)get_localized_text_entry(0x26, 1)), -1, 0, 100000.0f);
    draw_window_text((f32 *)&pts[1], (const char *)((void *)get_localized_text_entry(0x26, 2)), -1, 0, 100000.0f);
    draw_window_text((f32 *)&pts[2], (const char *)((void *)get_localized_text_entry(0x26, 3)), -1, 0, 100000.0f);
    for (i = 0; i < 3; i++) {
        pts2[i].x = ply_status_window_points_second[i].x + OFF_8033F3D8.x;
        pts2[i].y = ply_status_window_points_second[i].y + OFF_8033F3D8.y;
    }
    if (items[0].valid == 0 || items[1].valid == 0 || items[2].valid == 0) {
        return;
    }
    draw_window_text((f32 *)&pts2[0], (const char *)&items[0], -1, 0, 100000.0f);
    draw_window_text((f32 *)&pts2[1], (const char *)&items[1], -1, 0, 100000.0f);
    draw_window_text((f32 *)&pts2[2], (const char *)&items[2], -1, 0, 100000.0f);
}
#undef OFF_8033F3D8
#undef TAdPlyStatusGC__status_window_box
#undef ply_status_window_points_first
#undef ply_status_window_points_second

void TAdPlyStatusGC::format_status_strings() {
    char *buf = (char *)this;
    u8 *c;
    u32 time;
    u32 mins;
    s32 flags;
    u32 hours;
    TAdChrSelPlyPlateGC *plate;
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
        plate = TAdMultiPlyChrSelectGC::get_card_instance();
        if (plate != NULL) {
            if (TAdSinglePlyChrSelectGC__sub_801FE800(plate->get_active_card_slot()) != 0) {
                c = (u8 *)get_entry__23TAdSinglePlyChrSelectGCFi(plate->get_active_card_slot());
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
            sprintf(buf, ":%s", get_localized_text_entry(0x26, 0));
        } else {
            sprintf(buf, ":%s", get_class_name_text(card.f31));
        }
        if (flags & 1) {
            sprintf(buf + 0x10, ":%s", get_localized_text_entry(0x26, 0));
        } else {
            sprintf(buf + 0x10, ":%s", TObjLuker::get_stat_table_entry(card.f30));
        }
        sprintf(buf + 0x20, ":%04d:%02d'", hours, mins);
    }
}

s32 TAdPlyStatusGC__sub_8033F8B0(void *arg0, const void *ad_enter_serial_access_gc) {
    saddr r = (saddr)TAdEnterSerialAccessGC::create_callback((void *)ad_enter_serial_access_gc,
                                              (void *)&ply_status_window_position,
                                              draw_status_window__14TAdPlyStatusGCFPvPv);
    ((TWindowBase *)r)->set_depth(60000.0f);
    return r;
}

void TAdPlyStatusGC::set_load_state(s32 arg1) {
    s32 var_r4;
    if (arg1 > 0) {
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x1C) == 0) {
            var_r4 = 2;
            if ((s32) TAdPlyStatusGC__is_shown != 0) {
                var_r4 = 1;
            }
            *(s32 *)((s8 *)((u8 *)this) + 0x1C) = var_r4;
        }
        return;
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = 0;
}

void update_hidden__14TAdPlyStatusGCFv(u8 *arg0) {
    saddr player_index;
    s32 status;
    TAdPlyStatusGC__is_shown = 0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x6C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x6C)))->close();
        *(u32 *)((s8 *)arg0 + 0x6C) = 0U;
    }
    if ((s32) TAdPlyStatusGC__window_offset_index < 3) {
        player_index = ((s32)TAdPlyStatusGC::get_player_index());
        if (player_index != 0) {
            ((TObject *)player_index)->allow_rendering();
            ((TAdGuideButtonGC *)player_index)->setup_button((GuideButtonSpec *)(arg0 + 0x48));
        }
        status = TAdMultiPlyChrSelectGC::get_status() * 0x50;
        if (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_physical_port_bank + status + 0x20), 0x400) != 0) {
            *(s32 *)((s8 *)arg0 + 0x1C) = 1;
        }
    }
}

void update_shown__14TAdPlyStatusGCFv(struct RecoveredFields_8033F9DC_arg0 *arg0) {
    saddr player_index;
    s32 status;
    TAdPlyStatusGC__is_shown = 1;
    if ((s32) TAdPlyStatusGC__window_offset_index < 3) {
        if ((u32) arg0->field_6C == 0) {
            arg0->field_6C = TAdPlyStatusGC__sub_8033F8B0(arg0, &ply_status_window_offset_table[TAdPlyStatusGC__window_offset_index]);
        }
        player_index = ((s32)TAdPlyStatusGC::get_player_index());
        if (player_index != 0) {
            ((TObject *)player_index)->allow_rendering();
            ((TAdGuideButtonGC *)player_index)->setup_button((GuideButtonSpec *)(&arg0->unknown_20[4]));
        }
        status = TAdMultiPlyChrSelectGC::get_status() * 0x50;
        if (TWindowShortListCtrl__check_controller_button((u8 *)(((u8 *)&controller_physical_port_bank + status)) + 0x20, 0x400) != 0) {
            arg0->field_1C = 2;
        }
    }
}

void close_window__14TAdPlyStatusGCFv(void *arg0) {
    void *window_base = *(void **)((s8 *)arg0 + 0x6C);
    if ((uaddr) window_base != 0U) {
        ((TWindowBase *)window_base)->close();
        *(u32 *)((s8 *)arg0 + 0x6C) = 0U;
    }
    {
        saddr player_index = TAdPlyStatusGC::get_player_index();
        if ((uaddr)player_index != 0U) {
            ((TObject *)player_index)->disallow_rendering();
        }
    }
}
}
void TAdPlyStatusGC::run_task() {
    static void (TAdPlyStatusGC::*tbl[3])() = {
        &TAdPlyStatusGC::close_window, &TAdPlyStatusGC::update_shown, &TAdPlyStatusGC::update_hidden,
    };
    (this->*tbl[state])();
    prev_state = state;
}
TAdPlyStatusGC::~TAdPlyStatusGC() {
    if (window != NULL) {
        window->queue_destruction();
        window = NULL;
    }
    if (ply_status_gc_instance != 0U) {
        ply_status_gc_instance = 0U;
    }
}

TAdPlyStatusGC_8033FC14 *TAdPlyStatusGC__ct(TAdPlyStatusGC_8033FC14 *self, void *parent, s32 arg2) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = &__vt__14TAdPlyStatusGC;
    __construct_array(self->elems, (void *) init_guide_button_params, 0, 0x24, 2);
    self->name = TAdPlyStatusGC__class_name;
    self->f1C = 0;
    self->f20 = self->f1C;
    self->f6C = 0;
    ply_status_chcr_load_afs = 0;
    TAdPlyStatusGC__window_offset_index = arg2;
    TAdPlyStatusGC__is_shown = 1;
    self->elems[0].mode = 2;
    self->elems[0].a = 432.0f;
    self->elems[0].b = 421.0f;
    self->elems[0].c = 432.0f;
    self->elems[0].d = 421.0f;
    self->elems[0].handle = get_localized_text_entry(0x26, 4);
    self->elems[0].f14 = 0;
    self->elems[0].f18 = 8;
    self->elems[0].f1C = 0x1E;
    self->elems[1].mode = 2;
    self->elems[1].a = 432.0f;
    self->elems[1].b = 421.0f;
    self->elems[1].c = 432.0f;
    self->elems[1].d = 421.0f;
    self->elems[1].handle = get_localized_text_entry(0x26, 5);
    self->elems[1].f14 = 0;
    self->elems[1].f18 = 8;
    self->elems[1].f1C = 0x1E;
    create_guide_button((TObject *)self, (GuideButtonSpec *)self->elems);
    {
        saddr player_index = TAdPlyStatusGC::get_player_index();
        if ((uaddr)player_index != 0U) {
            ((TObject *)player_index)->disallow_rendering();
        }
    }
    return self;
}
#pragma pop
