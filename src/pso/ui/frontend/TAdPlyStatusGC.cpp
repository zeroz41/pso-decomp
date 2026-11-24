#include "pso/player/TPlyCharData.h"
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
#include "pso/ui/charcreate/CharacterPreview.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdGuideButtonGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/system/ControllerInput.h"
#include <stdio.h>
#include <string.h>
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowComCard.h"


struct Save_8033F6A8 { u8 pad[0xC]; u32 fC; };

extern "C" {
extern s32 TAdPlyStatusGC__window_offset_index;
extern s32 TAdPlyStatusGC__is_shown;
void draw_status_window__14TAdPlyStatusGCFPvPv(void *arg0, void *arg1);
TWindowBase *TAdPlyStatusGC__sub_8033F8B0(void *arg0, const void *arg1);
saddr get_localized_text_entry(s32 arg0, s32 arg1);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i);
}
extern "C" {
extern u32 ply_status_index;
TAdPlyStatusGC *ply_status_gc_instance;
CharacterPreview *ply_status_chcr_load_afs;
s32 TAdPlyStatusGC__window_offset_index;
u32 ply_status_index;
s32 TAdPlyStatusGC__is_shown;

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
void TAdPlyStatusGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

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
void draw_window_frame__11TWindowBaseFPv(void *);
void draw_status_window__14TAdPlyStatusGCFPvPv(void *window_base, void *arg1) {
    Item_8033F3D8 items[3];
    Box_8033F3D8 box;
    NJS_POINT2 pts[3];
    NJS_POINT2 pts2[3];
    s32 i;

    ((TWindowBase *)window_base)->draw_window_frame(arg1);
    if (ply_status_chcr_load_afs != NULL && ply_status_chcr_load_afs->is_unloaded() != 0 && TAdPlyStatusGC__is_shown != 0 &&
        ply_status_chcr_load_afs->get_status_sub()->textures[0].texture != NULL) {
        box = TAdPlyStatusGC__status_window_box;
        box.v[0] = TAdPlyStatusGC__status_window_box.v[0] + OFF_8033F3D8.x;
        box.v[2] = TAdPlyStatusGC__status_window_box.v[2] + OFF_8033F3D8.x;
        box.v[1] = TAdPlyStatusGC__status_window_box.v[1] + OFF_8033F3D8.y;
        box.v[3] = TAdPlyStatusGC__status_window_box.v[3] + OFF_8033F3D8.y;
        TObjFish::set_global_param(ply_status_chcr_load_afs->get_status_sub());
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
    TPlyCharData *c;
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
        c = TAdSinglePlyChrSelectGC::get_char_index(0xFFFF);
        break;
    case 1:
        p = (Save_8033F6A8 *)TAdSinglePlyChrSelectGC__sub_801FE3E4(ply_status_index);
        if (p != 0) {
            time = p->fC;
        }
        plate = TAdMultiPlyChrSelectGC::get_card_instance();
        if (plate != NULL) {
            if (TAdSinglePlyChrSelectGC__sub_801FE800(plate->get_active_card_slot()) != 0) {
                c = TAdSinglePlyChrSelectGC::get_entry(plate->get_active_card_slot());
            }
        }
        if (c == 0) {
            return;
        }
        break;
    }
    if (c != 0) {
        disp_data_part2 card = c->m_disp_part2;
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
        flags = *reinterpret_cast<const s8 *>(&card.v2_flags);
        if (flags & 2) {
            sprintf(buf, ":%s", get_localized_text_entry(0x26, 0));
        } else {
            sprintf(buf, ":%s", get_class_name_text(*reinterpret_cast<const s8 *>(&card.char_class)));
        }
        if (flags & 1) {
            sprintf(buf + 0x10, ":%s", get_localized_text_entry(0x26, 0));
        } else {
            sprintf(buf + 0x10, ":%s", TObjLuker::get_stat_table_entry(*reinterpret_cast<const s8 *>(&card.section_id)));
        }
        sprintf(buf + 0x20, ":%04d:%02d'", hours, mins);
    }
}

TWindowBase *TAdPlyStatusGC__sub_8033F8B0(void *arg0, const void *ad_enter_serial_access_gc) {
    TWindowBase *r = (TWindowBase *)TAdEnterSerialAccessGC::create_callback((void *)ad_enter_serial_access_gc,
                                              (void *)&ply_status_window_position,
                                              draw_status_window__14TAdPlyStatusGCFPvPv);
    r->set_depth(60000.0f);
    return r;
}

void TAdPlyStatusGC::set_load_state(s32 arg1) {
    s32 var_r4;
    if (arg1 > 0) {
        if (state == 0) {
            var_r4 = 2;
            if ((s32) TAdPlyStatusGC__is_shown != 0) {
                var_r4 = 1;
            }
            state = var_r4;
        }
        return;
    }
    state = 0;
}

void TAdPlyStatusGC::update_hidden() {
    TAdGuideButtonGC *guide_button;
    s32 port;
    TAdPlyStatusGC__is_shown = 0;
    if (window != NULL) {
        window->close();
        window = NULL;
    }
    if ((s32) TAdPlyStatusGC__window_offset_index < 3) {
        guide_button = TAdPlyStatusGC::get_player_index();
        if (guide_button != NULL) {
            guide_button->allow_rendering();
            guide_button->setup_button(&buttons[1]);
        }
        port = TAdMultiPlyChrSelectGC::get_status();
        if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[port], 0x400) != 0) {
            state = 1;
        }
    }
}

void TAdPlyStatusGC::update_shown() {
    TAdGuideButtonGC *guide_button;
    s32 port;
    TAdPlyStatusGC__is_shown = 1;
    if ((s32) TAdPlyStatusGC__window_offset_index < 3) {
        if (window == NULL) {
            window = TAdPlyStatusGC__sub_8033F8B0(this, &ply_status_window_offset_table[TAdPlyStatusGC__window_offset_index]);
        }
        guide_button = TAdPlyStatusGC::get_player_index();
        if (guide_button != NULL) {
            guide_button->allow_rendering();
            guide_button->setup_button(&buttons[0]);
        }
        port = TAdMultiPlyChrSelectGC::get_status();
        if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[port], 0x400) != 0) {
            state = 2;
        }
    }
}

void TAdPlyStatusGC::close_window() {
    if (window != NULL) {
        window->close();
        window = NULL;
    }
    {
        TAdGuideButtonGC *guide_button = TAdPlyStatusGC::get_player_index();
        if (guide_button != NULL) {
            guide_button->disallow_rendering();
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
    if (ply_status_gc_instance != NULL) {
        ply_status_gc_instance = NULL;
    }
}

TAdPlyStatusGC::TAdPlyStatusGC(TObject *parent, s32 window_offset_index) : TObject(parent) {
    m_name = TAdPlyStatusGC__class_name;
    state = 0;
    prev_state = state;
    window = NULL;
    ply_status_chcr_load_afs = 0;
    TAdPlyStatusGC__window_offset_index = window_offset_index;
    TAdPlyStatusGC__is_shown = 1;
    buttons[0].kind = 2;
    buttons[0].from.x = 432.0f;
    buttons[0].from.y = 421.0f;
    buttons[0].to.x = 432.0f;
    buttons[0].to.y = 421.0f;
    buttons[0].label = (const char *)get_localized_text_entry(0x26, 4);
    buttons[0].alpha = 0;
    buttons[0].alpha_step = 8;
    buttons[0].duration = 0x1E;
    buttons[1].kind = 2;
    buttons[1].from.x = 432.0f;
    buttons[1].from.y = 421.0f;
    buttons[1].to.x = 432.0f;
    buttons[1].to.y = 421.0f;
    buttons[1].label = (const char *)get_localized_text_entry(0x26, 5);
    buttons[1].alpha = 0;
    buttons[1].alpha_step = 8;
    buttons[1].duration = 0x1E;
    create_guide_button(this, buttons);
    {
        TAdGuideButtonGC *guide_button = TAdPlyStatusGC::get_player_index();
        if (guide_button != NULL) {
            guide_button->disallow_rendering();
        }
    }
}
#pragma pop

TAdPlyStatusGC *TAdPlyStatusGC::get_instance(TObject *parent, s32 window_offset_index) {
    if (ply_status_gc_instance == NULL) {
        ply_status_gc_instance = new TAdPlyStatusGC(parent, window_offset_index);
    }
    return ply_status_gc_instance;
}

TAdGuideButtonGC *TAdPlyStatusGC::get_player_index() { return guide_button_instance; }
