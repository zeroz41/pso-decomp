#include "pso/system/TLanguage.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/system/task/TObject.h"
#include "pso/math/Vec2Constants.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/object/TObjLuker.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowTextEntry.h"


ComCardLayout com_card_layout_entries = {
    6, 1,
    {
        {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {198.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    },
};

WindowDescriptor com_card_window_descriptor = {
    {206.0f, 180.0f}, 50100.0f, &com_card_layout_entries, 0x23,
};

const char *TWindowComCard::class_name = "TWindowComCard";
const char *com_card_status_text_table[6] = {
    "Jpn.", "Eng.", "Ger.", "Fr.", "Span.", "??????",
};
const ComCardHelpRect com_card_help_panel_rect_table[14] = {
    {0.0f, 180.0f}, {32.0f, 180.0f}, {64.0f, 180.0f}, {96.0f, 180.0f}, {128.0f, 180.0f},
    {0.0f, 208.0f}, {32.0f, 208.0f}, {64.0f, 208.0f}, {96.0f, 208.0f}, {128.0f, 208.0f},
    {72.0f, 167.0f}, {104.0f, 167.0f}, {136.0f, 167.0f}, {168.0f, 167.0f},
};

void update_com_card_display(WindowLayoutEntries *entries, GuildCardEntry *card);



s32 get_chain_help_mode(s32 chain_slot) { return chain_slot + 10; }

void WindowSpritePart::set_help_mode(s32 help_mode) {
    const ComCardHelpRect *rect;

    if (help_mode == 0xE) {
        flags = (u16)(flags | 2);
        return;
    }
    flags = (u16)(flags & 0xFFFFFFFD);
    if (help_mode < 0xA) {
        kind = 1;
    } else {
        kind = 2;
    }
    rect = &com_card_help_panel_rect_table[help_mode];
    this->set_sprite_uv_from_pixels(rect->x, rect->y);
}

s32 get_class_name_text(s32 class_index) {
    return (saddr)text_language_group_table[7][class_index];
}

s8 GuildCardEntry::get_language() { return language; }

s8 GuildCardEntry::get_section_id() { return section_id; }

char *GuildCardEntry::get_text() { return text; }

TWindowComCard::TWindowComCard(const NJS_POINT2 *position, void *data)
    : TWindowBase((u8 *)&com_card_window_descriptor, 4, (u8 *)position) {
    m_name = TWindowComCard::class_name;
    update_com_card_display(&entry_list, (GuildCardEntry *)data);
}

TWindowComCard::~TWindowComCard() {}

void TWindowComCard::run_task() {
    update_window();
    update_fade();
    update_window_entry_list(&entry_list);
}

void TWindowComCard::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
}

TWindowComCard *TWindowSubComCard::create_com_card_window(const NJS_POINT2 *position) {
    GuildCardEntry *own_card = TWindowSubComCard::get_own_guild_card();
    if (own_card == NULL) {
        return 0;
    }
    if (is_guild_card_invalid(own_card) != 0) {
        own_card->clear_and_fill_from_char(local_client_id);
    }
    return new TWindowComCard(position, own_card);
}

TWindowComCard *TWindowComCard::create(const NJS_POINT2 *position, s32 index) {
    void *entry = TWindowSubComCard::get_card_entry(index);
    if (entry == NULL) {
        return NULL;
    }
    return new TWindowComCard(position, entry);
}

TWindowComCard *TWindowComCard::create_for_card(const NJS_POINT2 *position, s32 index, saddr records) {
    if (index < 0) {
        return NULL;
    }
    saddr data = records + index * 0x90;
    return new TWindowComCard(position, (void *)data);
}

void TWindowComCard::set_display_value(s32 card_index, s32 cards) {
    saddr temp = cards + (card_index << 8);
    if (temp != 0) {
        update_com_card_display(&entry_list, (GuildCardEntry *)temp);
    }
}

void TWindowComCard::set_display_entry(s32 card_index, s32 records) {
    saddr temp = records + (card_index * 0x90);
    if (temp != 0) {
        update_com_card_display(&entry_list, (GuildCardEntry *)temp);
    }
}

void update_com_card_display(WindowLayoutEntries *entries, GuildCardEntry *card) {
    WindowTextEntry *t4;
    WindowTextEntry *t14;
    WindowTextEntry *t0;
    void *tC;
    void *t8;
    void *t10;
    void **s;
    s32 n;
    s32 id;
    s = entries->items;
    t0 = (WindowTextEntry *)s[0];
    tC = s[3];
    t8 = s[2];
    t10 = s[4];
    t4 = (WindowTextEntry *)s[1];
    t14 = (WindowTextEntry *)s[5];
    set_text_entry_string(t0, (uaddr)card->get_name(), 0x220);
    n = card->get_language();
    if (n > 5) {
        n = 5;
    }
    TWindowDuelResult::set_default_status(tC, (saddr)com_card_status_text_table[n]);
    n = card->get_char_class();
    if (n > 0xC) {
        n = 0xC;
    }
    TWindowDuelResult::set_default_status(t8, get_class_name_text(n));
    n = card->get_section_id();
    if (n > 0xA) {
        n = 0xA;
    }
    TWindowDuelResult::set_default_status(t10, reinterpret_cast<saddr>(TObjLuker::get_stat_table_entry(n)));
    if (card->is_own_card() != 0) {
        id = card->get_card_id();
        if (id == 0) {
            t4->flags |= 2;
        } else {
            text_builder_reset();
            text_builder_append_int(id);
            set_text_entry_string(t4, (uaddr)((void *)get_shared_text_buffer()), 0x20);
            measure_message_text_width_default(t4);
            t4->x = 198.0f - t4->width;
            t4->flags &= ~2;
        }
    } else {
        t4->flags |= 2;
    }
    set_text_entry_string(t14, (uaddr)card->get_text(), 0x220);
}
