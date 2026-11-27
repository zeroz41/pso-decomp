#include "pso/player/TPlyCharData.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/charcreate/CharacterPreview.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/TextureState.h"
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
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/window/TWindowCallBack.h"




TAdPlyStatusGC *ply_status_gc_instance;
CharacterPreview *ply_status_preview;
s32 TAdPlyStatusGC::window_offset_index;
u32 ply_status_index;
s32 TAdPlyStatusGC::is_shown;

// Status window size handed to TAdEnterSerialAccessGC::create_callback.
static const NJS_POINT2 ply_status_window_position = {199.0f, 112.0f};
// Status window position per TAdPlyStatusGC::window_offset_index.
static const NJS_POINT2 ply_status_window_offset_table[3] = {
    {426.0f, 250.0f},
    {223.0f, 243.0f},
    {223.0f, 243.0f},
};

const char *TAdPlyStatusGC::class_name = "TAdPlyStatusGC";

// The character portrait inside the status window.
StatusPortraitQuad ply_status_portrait_quad = {83.0f, 10.0f, 115.0f, 42.0f, 0.0f, 0.0f, 1.0f, 1.0f};
// The label column (class, section id, play time).
NJS_POINT2 ply_status_window_points_first[3] = {{4.0f, 42.0f}, {4.0f, 62.0f}, {4.0f, 82.0f}};
// The value column format_status_strings fills.
NJS_POINT2 ply_status_window_points_second[3] = {{60.0f, 42.0f}, {60.0f, 62.0f}, {60.0f, 82.0f}};

void TAdPlyStatusGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 10);
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TAdPlyStatusGC::draw_status_window(void *window, void *context) {
    WindowDrawContext *draw_context = (WindowDrawContext *)context;
    char text[3][16];
    StatusPortraitQuad quad;
    NJS_POINT2 labels[3];
    NJS_POINT2 values[3];
    s32 i;

    ((TWindowBase *)window)->draw_window_frame(draw_context);
    if (ply_status_preview != NULL && ply_status_preview->is_unloaded() != 0 && is_shown != 0 &&
        ply_status_preview->get_status_sub()->textures->texaddr != 0) {
        quad = ply_status_portrait_quad;
        quad.values[0] = ply_status_portrait_quad.values[0] + ply_status_window_offset_table[window_offset_index].x;
        quad.values[2] = ply_status_portrait_quad.values[2] + ply_status_window_offset_table[window_offset_index].x;
        quad.values[1] = ply_status_portrait_quad.values[1] + ply_status_window_offset_table[window_offset_index].y;
        quad.values[3] = ply_status_portrait_quad.values[3] + ply_status_window_offset_table[window_offset_index].y;
        set_texture_list(ply_status_preview->get_status_sub());
        begin_screen_draw(1);
        set_draw_texture_and_color(0, -1);
        draw_textured_quad_at_depth(&quad.values[0], 0.8f);
        end_screen_draw();
    }
    format_status_strings(text);
    set_text_draw_params(draw_context, 1, 1, 0.8f, 100000.0f);
    for (i = 0; i < 3; i++) {
        labels[i].x = ply_status_window_points_first[i].x + ply_status_window_offset_table[window_offset_index].x;
        labels[i].y = ply_status_window_points_first[i].y + ply_status_window_offset_table[window_offset_index].y;
    }
    draw_window_text(&labels[0].x, get_localized_text_entry(0x26, 1), -1, 0, 100000.0f);
    draw_window_text(&labels[1].x, get_localized_text_entry(0x26, 2), -1, 0, 100000.0f);
    draw_window_text(&labels[2].x, get_localized_text_entry(0x26, 3), -1, 0, 100000.0f);
    for (i = 0; i < 3; i++) {
        values[i].x = ply_status_window_points_second[i].x + ply_status_window_offset_table[window_offset_index].x;
        values[i].y = ply_status_window_points_second[i].y + ply_status_window_offset_table[window_offset_index].y;
    }
    if (text[0][0] == 0 || text[1][0] == 0 || text[2][0] == 0) {
        return;
    }
    draw_window_text(&values[0].x, text[0], -1, 0, 100000.0f);
    draw_window_text(&values[1].x, text[1], -1, 0, 100000.0f);
    draw_window_text(&values[2].x, text[2], -1, 0, 100000.0f);
}

void TAdPlyStatusGC::format_status_strings(char (*text)[16]) {
    TPlyCharData *c;
    u32 time;
    u32 mins;
    s32 flags;
    u32 hours;
    TAdChrSelPlyPlateGC *plate;
    CharacterSaveRecord *record;
    CardSlotSummary *summary;
    u32 t;
    memset(text[0], 0, sizeof(text[0]));
    memset(text[1], 0, sizeof(text[1]));
    memset(text[2], 0, sizeof(text[2]));
    c = 0;
    switch (TAdPlyStatusGC::window_offset_index) {
    case 0:
    case 2:
        record = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
        if (record != 0) {
            time = record->play_time;
        }
        c = TAdSinglePlyChrSelectGC::get_char_index(0xFFFF);
        break;
    case 1:
        summary = get_secondary_slot_summary(ply_status_index);
        if (summary != 0) {
            time = summary->play_time;
        }
        plate = TAdMultiPlyChrSelectGC::get_card_instance();
        if (plate != NULL) {
            if (is_secondary_slot_active(plate->get_active_card_slot()) != 0) {
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
            sprintf(text[0], ":%s", get_localized_text_entry(0x26, 0));
        } else {
            sprintf(text[0], ":%s", get_class_name_text(*reinterpret_cast<const s8 *>(&card.char_class)));
        }
        if (flags & 1) {
            sprintf(text[1], ":%s", get_localized_text_entry(0x26, 0));
        } else {
            sprintf(text[1], ":%s", TObjLuker::get_stat_table_entry(*reinterpret_cast<const s8 *>(&card.section_id)));
        }
        sprintf(text[2], ":%04d:%02d'", hours, mins);
    }
}

TWindowBase *TAdPlyStatusGC::create_status_window(const NJS_POINT2 *position) {
    TWindowBase *status_window = TAdEnterSerialAccessGC::create_callback(
        position, &ply_status_window_position, draw_status_window);
    status_window->set_depth(60000.0f);
    return status_window;
}

void TAdPlyStatusGC::set_load_state(s32 load_result) {
    s32 new_state;
    if (load_result > 0) {
        if (state == 0) {
            new_state = 2;
            if ((s32) TAdPlyStatusGC::is_shown != 0) {
                new_state = 1;
            }
            state = new_state;
        }
        return;
    }
    state = 0;
}

void TAdPlyStatusGC::update_hidden() {
    TAdGuideButtonGC *guide_button;
    s32 port;
    TAdPlyStatusGC::is_shown = 0;
    if (window != NULL) {
        window->close();
        window = NULL;
    }
    if ((s32) TAdPlyStatusGC::window_offset_index < 3) {
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
    TAdPlyStatusGC::is_shown = 1;
    if ((s32) TAdPlyStatusGC::window_offset_index < 3) {
        if (window == NULL) {
            window = create_status_window(&ply_status_window_offset_table[window_offset_index]);
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

TAdPlyStatusGC::TAdPlyStatusGC(TObject *parent, s32 offset_index) : TObject(parent) {
    m_name = TAdPlyStatusGC::class_name;
    state = 0;
    prev_state = state;
    window = NULL;
    ply_status_preview = NULL;
    window_offset_index = offset_index;
    TAdPlyStatusGC::is_shown = 1;
    buttons[0].kind = 2;
    buttons[0].from.x = 432.0f;
    buttons[0].from.y = 421.0f;
    buttons[0].to.x = 432.0f;
    buttons[0].to.y = 421.0f;
    buttons[0].label = get_localized_text_entry(0x26, 4);
    buttons[0].alpha = 0;
    buttons[0].alpha_step = 8;
    buttons[0].duration = 0x1E;
    buttons[1].kind = 2;
    buttons[1].from.x = 432.0f;
    buttons[1].from.y = 421.0f;
    buttons[1].to.x = 432.0f;
    buttons[1].to.y = 421.0f;
    buttons[1].label = get_localized_text_entry(0x26, 5);
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
