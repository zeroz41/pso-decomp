#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowBreakIn.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/unk/TWindowLayoutEntry.h"

#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowLayout.h"

#pragma push
#pragma readonly_strings on
const char *TWindowBreakIn::class_name = "TWindowBreakIn";
#pragma pop


BreakInWindowLayout window_break_in_layout_entries = {
    8, 1,
    {
        {6, {72.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {76.0f, 0.0f}, {32.0f, 30.0f}, 185.0f, 62.0f, 0.6f, -1, &hud_texlist, 0, 10},
        {6, {48.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {52.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 185.0f, 0.6f, -1, &hud_texlist, 0, 10},
        {6, {24.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {28.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 152.0f, 0.6f, -1, &hud_texlist, 0, 10},
        {6, {0.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {4.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 119.0f, 0.6f, -1, &hud_texlist, 0, 10},
    },
};

WindowDescriptor window_break_in_layout = {
    {112.0f, 30.0f}, 50000.0f, &window_break_in_layout_entries, 0x823,
};


void TWindowBreakIn::update_entry_visibility() {
    TWindowLayoutEntry *entry7;
    TWindowLayoutEntry *entry6;
    TWindowLayoutEntry *entry5;
    TWindowLayoutEntry *entry4;
    TWindowLayoutEntry *entry3;
    TWindowLayoutEntry *entry2;
    TWindowLayoutEntry *entry1;
    TWindowLayoutEntry *entry0;
    entry7 = (TWindowLayoutEntry *)this->get_array_entry(7);
    entry6 = (TWindowLayoutEntry *)this->get_array_entry(6);
    entry5 = (TWindowLayoutEntry *)this->get_array_entry(5);
    entry4 = (TWindowLayoutEntry *)this->get_array_entry(4);
    entry3 = (TWindowLayoutEntry *)this->get_array_entry(3);
    entry2 = (TWindowLayoutEntry *)this->get_array_entry(2);
    entry1 = (TWindowLayoutEntry *)this->get_array_entry(1);
    entry0 = (TWindowLayoutEntry *)this->get_array_entry(0);
    if (is_guild_card_receive_active() != 0) {
        if (entry7 != NULL) {
            entry7->show();
        }
        if (entry6 != NULL) {
            entry6->show();
        }
    } else {
        if (entry7 != NULL) {
            entry7->hide();
        }
        if (entry6 != NULL) {
            entry6->hide();
        }
    }
    if (is_com_card_active() != 0) {
        if (entry5 != NULL) {
            entry5->show();
        }
        if (entry4 != NULL) {
            entry4->show();
        }
    } else {
        if (entry5 != NULL) {
            entry5->hide();
        }
        if (entry4 != NULL) {
            entry4->hide();
        }
    }
    if (TWindowSubShortMail::is_active() != 0) {
        if (entry3 != NULL) {
            entry3->show();
        }
        if (entry2 != NULL) {
            entry2->show();
        }
    } else {
        if (entry3 != NULL) {
            entry3->hide();
        }
        if (entry2 != NULL) {
            entry2->hide();
        }
    }
    if (is_trade_active() != 0) {
        if (entry1 != NULL) {
            entry1->show();
        }
        if (entry0 != NULL) {
            entry0->show();
        }
    } else {
        if (entry1 != NULL) {
            entry1->hide();
        }
        if (entry0 != NULL) {
            entry0->hide();
        }
    }
}

void TWindowBreakIn::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_visible_window_entries(this, &entry_list, context);
}

void TWindowBreakIn::run_task() { update_entry_visibility(); update_window(); update_window_entry_list(&entry_list); }

TWindowBreakIn::~TWindowBreakIn() {}
TWindowBreakIn::TWindowBreakIn() : TWindowBase((u8 *)&window_break_in_layout, (s16)(4), (u8 *)(get_window_layout_position(0xAA))) {
    m_name = TWindowBreakIn::class_name;
}

s32 is_trade_active(void) {
    return ((u16) short_mail_flags >> 3U) & 1;
}

s32 TWindowSubShortMail::is_active() {
    return short_mail_flags & 1;
}

s32 is_com_card_active(void) {
    return ((u16) short_mail_flags >> 2U) & 1;
}

s32 is_guild_card_receive_active(void) {
    return ((u16) short_mail_flags >> 1U) & 1;
}
