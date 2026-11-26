#include "pso/math/FloatRound.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowShortCut.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/HeadingEntry.h"

#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/ItemListRow.h"

const char *TWindowShortCut::class_name = "TWindowShortCut";


ShortCutWindowLayout window_short_cut_layout_entries = {
    11, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
    {3, {100.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0x40, ":"},
    {6, {112.0f, 0.0f}, {18.0f, 18.0f}, 0.0f, 0.0f, 0.5f, -1, &hud_texlist, 1, 4},
    {6, {130.0f, 0.0f}, {18.0f, 18.0f}, 0.0f, 0.0f, 0.5f, -1, &hud_texlist, 1, 4},
    {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
    {3, {100.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0x40, ":"},
    {6, {112.0f, 20.0f}, {18.0f, 18.0f}, 0.0f, 0.0f, 0.5f, -1, &hud_texlist, 1, 4},
    {3, {130.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
    {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
    {3, {100.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0x40, ":"},
    {3, {112.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
};
WindowDescriptor window_short_cut_layout = {
    {405.0f, 188.0f}, 50100.0f, &window_short_cut_layout_entries, 0x63,
};


// Icon sprite of each shortcut kind, indexed by kind - 1: text, word select, symbol chat.
static const u8 shortcut_kind_sprites[] = {0x12, 0x10, 0x11};

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TWindowShortCut::show_shortcut(s32 index, s32 *shortcut) {
    u8 icon;
    u8 icon_detail;
    NJS_POINT2 position;
    s32 kind;
    NJS_POINT2 size;

    WindowTextEntry *shortcut_label = (WindowTextEntry *)get_array_entry(0);
    WindowSpritePart *shortcut_icon = static_cast<WindowSpritePart *>(get_array_entry(2));
    WindowSpritePart *detail_icon = static_cast<WindowSpritePart *>(get_array_entry(3));
    WindowTextEntry *kind_label = (WindowTextEntry *)get_array_entry(4);
    WindowSpritePart *kind_icon = static_cast<WindowSpritePart *>(get_array_entry(6));
    WindowTextEntry *kind_name = (WindowTextEntry *)get_array_entry(7);
    WindowTextEntry *preview_label = (WindowTextEntry *)get_array_entry(8);
    WindowTextEntry *preview = (WindowTextEntry *)get_array_entry(10);

    kind = shortcut[0];
    set_text_entry_string(shortcut_label, (uaddr)TWindowSubStatusDisp::get_message_10(0xC4), 0);
    get_shortcut_entry_codes(index, &icon, &icon_detail, client_index);
    if (icon != 0x33) {
        const NJS_POINT2 *origin = get_entry_ptr(icon);
        shortcut_icon->flags &= ~2;
        shortcut_icon->set_sprite_uv_from_pixels(origin->x, origin->y);
    } else {
        shortcut_icon->flags |= 2;
    }

    const NJS_POINT2 *detail_origin = get_entry_ptr(icon_detail);
    detail_icon->set_sprite_uv_from_pixels(detail_origin->x, detail_origin->y);
    set_text_entry_string(kind_label, (uaddr)TWindowSubStatusDisp::get_message_10(0xC5), 0);
    set_text_entry_string(kind_name, (uaddr)TWindowSubStatusDisp::get_message_10(0xC0 + kind), 0);
    s32 kind_sprite = shortcut_kind_sprites[kind - 1];
    const NJS_POINT2 *kind_origin = get_entry_ptr(kind_sprite);
    kind_icon->set_sprite_uv_from_pixels(kind_origin->x, kind_origin->y);

    position.x = 211.0f;
    position.y = 380.0f;
    set_text_entry_string(preview_label, (uaddr)TWindowSubStatusDisp::get_message_10(0x35), 0);

    switch (kind) {
    case 0:
        break;
    case 1: {
        char *text = fn_80076BC4(shortcut + 1);
        set_text_entry_string(preview, (uaddr)text, 0);
        preview->measure_text(200.0f);
        preview->flags |= 2;
        size.x = 0.1f + (8.0f + preview->width);
        size.y = 3.0f + (20.0f + preview->height);
        position.x = round_away_from_zero(position.x - 0.5f * size.x);
        position.y = round_away_from_zero(position.y - 0.5f * size.y);
        preview_window = create_quest_message_window_at(&position, &size);
        dispatch_message_window_text(preview_window, (saddr)text, 0x402);
        preview_window->set_depth(50060.0f);
        break;
    }
    case 2: {
        s32 *buffer = get_shared_text_buffer();
        u16 player = (u16)local_client_id;
        TWindowDD::format_message(reinterpret_cast<WordSelectMessage *>(shortcut + 1), reinterpret_cast<char *>(buffer), player);
        set_text_entry_string(preview, (uaddr)get_shared_text_buffer(), 0);
        measure_message_text_width_default(preview);
        preview->flags |= 2;
        size.x = 0.1f + (8.0f + preview->width);
        size.y = 3.0f + (20.0f + preview->height);
        position.x = round_away_from_zero(position.x - 0.5f * size.x);
        position.y = round_away_from_zero(position.y - 0.5f * size.y);
        preview_window = create_quest_message_window_at(&position, &size);
        dispatch_message_window_text(preview_window, (saddr)get_shared_text_buffer(), 2);
        preview_window->set_depth(50060.0f);
        break;
    }
    case 3: {
        SymbolChatPreset *preset = TWindowChat::open_symbol_chat(shortcut + 1);
        set_text_entry_string(preview, (uaddr)preset->get_symbol_chat_data(), 0);
        f32 height;
        f32 width;
        width = 203.0f;
        height = 78.0f;
        size.x = width;
        position.x -= 0.5f * width;
        size.y = height;
        position.y -= 0.5f * height;
        TWindowChatSymbol *symbol = (TWindowChatSymbol *)new TWindowChatSymbol(&position, (saddr)&size);
        symbol_preview = symbol;
        symbol_preview->set_selection(preset);
        symbol_preview->set_depth(50060.0f);
        break;
    }
    }
}
#pragma pop


void TWindowShortCut::render() {
    WindowDrawContext *ctx;
    ctx = draw_default_entry();
    draw_window_frame(ctx);
    draw_visible_window_entries(this, &this->entry_list, ctx);
    this->heading->render(ctx);
}

void TWindowShortCut::run_task() { this->heading->update(); update_window(); update_fade(); update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)this + 0x24)); }

TWindowShortCut::~TWindowShortCut() {
    if (this->symbol_preview != NULL) {
        this->symbol_preview->close();
        this->symbol_preview = NULL;
    }
    if (this->preview_window != NULL) {
        this->preview_window->close();
        this->preview_window = NULL;
    }
    delete this->heading;
}
TWindowShortCut::TWindowShortCut(saddr arg1, s32 index, s32 *chat_shortcut) : TWindowBase((u8 *)&window_short_cut_layout, (s16)4, (u8 *)arg1) {
    WindowHeading *heading;
    m_name = TWindowShortCut::class_name;
    heading = new WindowHeading((saddr)TWindowSubStatusDisp::get_message_10(0x35), this->client_index);
    this->heading = heading;
    this->preview_window = NULL;
    this->symbol_preview = NULL;
    this->shortcut_index = index;
    this->shortcut = chat_shortcut;
    this->show_shortcut(index, chat_shortcut);
}
