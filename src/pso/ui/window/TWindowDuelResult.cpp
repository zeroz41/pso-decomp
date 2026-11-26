#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/PageIndicator.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowDuelResult_801C2528.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/player/PlayerSlots.h"
#include "pso/map/area/AreaScene.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/WindowTextEntry.h"


#pragma readonly_strings on


extern "C" {
const char *window_duel_result_class_name = "TWindowDuelResult";

extern const char *window_duel_result_class_name;
saddr get_shared_text_buffer(s32);
void text_builder_append_int(s32);
s32 text_builder_append(s32);
}
void set_text_entry_string(u8 *text_entry, uaddr str, s32 flags);
void text_builder_reset(void);

extern "C" const char duel_result_time_separator[] = ":";
void *TWindowDuelResult::layout_entries[140] = {
    (void *)0x13, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&duel_result_time_separator, (void *)0x3,
    (void *)0x42aa0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&duel_result_time_separator, (void *)0x3,
    (void *)0x42aa0000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&duel_result_time_separator, (void *)0x3,
    (void *)0x42aa0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&duel_result_time_separator, (void *)0x3,
    (void *)0x42aa0000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x6, (void *)0x428c0000, (void *)0x43040000,
    (void *)0x41900000, (void *)0x41900000, (void *)0x43320000, (void *)0x434b0000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)&hud_texlist, (void *)0x0,
    (void *)0x14, (void *)0x3, (void *)0x42b00000, (void *)0x43040000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x100, (void *)0x0,
};
void *duel_result_window_layout_table[119] = {
    (void *)0x10, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x43870000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&duel_result_time_separator, (void *)0x4, (void *)0x43be0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43870000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&duel_result_time_separator, (void *)0x4,
    (void *)0x43be0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x43870000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&duel_result_time_separator,
    (void *)0x4, (void *)0x43be0000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43870000,
    (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&duel_result_time_separator, (void *)0x4, (void *)0x43be0000, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x6, (void *)0x428c0000, (void *)0x43040000, (void *)0x41900000,
    (void *)0x41900000, (void *)0x43320000, (void *)0x434b0000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)&hud_texlist, (void *)0x0, (void *)0x14,
    (void *)0x3, (void *)0x42b00000, (void *)0x43040000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x100, (void *)0x0,
};
WindowDescriptor window_duel_result_descriptor = {
    {388.0f, 164.0f}, 50043.0f, NULL, 3,
};

void TWindowDuelResult::update_stats_page() {  }

void TWindowDuelResult::build_stats_page() {
    s32 vals[4];
    TObjPlayer *pl;
    s32 i;
    u8 *a;
    u8 *b;
    u8 *c;
    init_window_layout_entries(&entry_list, duel_result_window_layout_table, client_index);
    a = (u8 *)get_array_entry(0);
    set_default_status(a, get_localized_text_entry(0x10, 0));
    c = (u8 *)get_array_entry(0xF);
    set_default_status(c, get_localized_text_entry(0x10, 5));
    pl = get_player_by_client_id(client_index);
    if (pl != 0) {
        set_text_entry_string((WindowTextEntry *)(get_array_entry(1)), (uaddr)pl->name, 0x20);
        vals[0] = pl->battle_score.kills.get_total();
        vals[1] = pl->battle_score.deaths.get_total();
        vals[2] = pl->battle_score.damage_given.get_total();
        vals[3] = pl->battle_score.damage_taken.get_total();
        for (i = 0; i < 4; i++) {
            a = (u8 *)get_array_entry(i * 3 + 2);
            b = (u8 *)get_array_entry(i * 3 + 4);
            set_default_status(a, get_localized_text_entry(0x10, i + 1));
            *(s32 *)(b + 0x20) = vals[i];
        }
    }
}

void TWindowDuelResult::update_ranking_page() {  }

void TWindowDuelResult::build_ranking_page() {
    s32 i;
    s32 none;
    BattleRanking *e;
    u8 *p;
    u8 *a;
    u8 *b;
    u8 *c;
    WindowTextEntry *d;
    init_window_layout_entries(&entry_list, TWindowDuelResult::layout_entries, client_index);
    a = (u8 *)get_array_entry(0);
    set_default_status(a, get_localized_text_entry(0x10, 0));
    b = (u8 *)get_array_entry(0x12);
    set_default_status(b, get_localized_text_entry(0x10, 5));
    none = 1;
    e = get_battle_rankings();
    for (i = 0; i < 4; i++, e++) {
        p = (e->client_id == 0xFFFF) ? NULL : (u8 *)get_player_by_client_id(e->client_id);
        if (p != NULL && e->place != 0) {
            none = 0;
        }
    }
    e = get_battle_rankings();
    for (i = 0; i < 4; i++, e++) {
        a = (u8 *)get_array_entry(i * 4 + 1);
        b = (u8 *)get_array_entry(i * 4 + 2);
        c = (u8 *)get_array_entry(i * 4 + 3);
        d = (WindowTextEntry *)get_array_entry(i * 4 + 4);
        p = (e->client_id == 0xFFFF) ? NULL : (u8 *)get_player_by_client_id(e->client_id);
        if (p == NULL) {
            *(u16 *)a |= 2;
            *(u16 *)b |= 2;
            *(u16 *)c |= 2;
            d->flags |= 2;
        } else {
            if (none) {
                set_default_status(a, get_localized_text_entry(0x10, 0xA));
            } else if (lobby_rule_settings.get_is_teams() == 1) {
                if (e->place == 0) {
                    set_default_status(a, get_localized_text_entry(0x10, 0xB));
                } else {
                    set_default_status(a, get_localized_text_entry(0x10, 0xC));
                }
            } else {
                set_default_status(a, get_localized_text_entry(0x10, e->place + 6));
            }
            set_text_entry_string((WindowTextEntry *)c, (uaddr)(p + 0x85C), 0x20);
            text_builder_reset();
            text_builder_append_int(e->score);
            set_text_entry_string(d, (uaddr)((void *)get_shared_text_buffer(text_builder_append(get_localized_text_entry(0x10, 0xD)))), 0x20);
            measure_message_text_width_default(d);
            d->x = (372.0f) - d->width;
        }
    }
}

#pragma defer_codegen on
void TWindowDuelResult::build_page() {
    typedef void (TWindowDuelResult::*PageMethod)();
    static PageMethod build[] = { &TWindowDuelResult::build_ranking_page, &TWindowDuelResult::build_stats_page };
    entry_list.destroy_all_items();
    s8 page = page_indicator->get_type();
    (this->*build[page])();
    update_page();
}

void TWindowDuelResult::update_page() {
    typedef void (TWindowDuelResult::*PageMethod)();
    static PageMethod update[] = { &TWindowDuelResult::update_ranking_page, &TWindowDuelResult::update_stats_page };
    s8 page = page_indicator->get_type();
    (this->*update[page])();
}
#pragma defer_codegen off

void TWindowDuelResult::render() {
    WindowDrawContext *context = setup_window_draw_context(&scale_x);
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_list_page_indicator(page_indicator, context);
}

void TWindowDuelResult::run_task() {
    if (!(window_flags & 2)) {
        open_tick = 0x01000000;
    }
    if (handle_list_page_flip_input(page_indicator) != 0) {
        build_page();
    }
    update_page();
    update_window();
    update_window_entry_list(&entry_list);
}

TWindowDuelResult::~TWindowDuelResult() {
    delete_if_allocated(page_indicator, 1);
}

TWindowDuelResult::TWindowDuelResult(s32 client)
    : TWindowBase((u8 *)&window_duel_result_descriptor, (s16)client, (u8 *)get_window_layout_position(0x24)) {
    m_name = window_duel_result_class_name;
    page_indicator = new PageIndicator(0, 2, client_index);
    if (TCameraCtrl::get_camera_id() > 2) {
        scale_x = 0.8f;
        scale_y = 0.8f;
    } else if (TCameraCtrl::get_camera_id() == 2) {
        scale_x = 1.0f;
        scale_y = 1.0f;
    } else {
        scale_x = 1.0f;
        scale_y = 1.0f;
    }
    build_page();
}
