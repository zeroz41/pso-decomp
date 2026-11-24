#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
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
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/chat/TWindowChat.h"

#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/unk/text_80266BD0.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/network/client_id.h"

const char *TWindowShortCut__name = "TWindowShortCut";


// The shortcut window's entries: three rows of label, ":" and icons or text, filled by
// show_shortcut (entries 0, 2, 3, 4, 6, 7, 8 and 10).
struct ShortCutWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    SpritePartLayoutRecord rec_2;
    SpritePartLayoutRecord rec_3;
    TextLayoutRecord rec_4;
    TextLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    TextLayoutRecord rec_7;
    TextLayoutRecord rec_8;
    TextLayoutRecord rec_9;
    TextLayoutRecord rec_10;
};
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

extern "C" {
void measure_message_text_width(void *entry, f32 max_width);
}

// A shortcut's preview text entry: its flags word and the measured size of its text.
struct ShortcutPreviewEntry {
    u16 flags;
    u8 pad_02[0xE];
    f32 width;
    f32 height;
};

// Sprite origin in pixels on the window's sprite sheet.
struct SpriteOrigin {
    f32 u;
    f32 v;
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

    u8 *shortcut_label = (u8 *)get_array_entry(0);
    ShortcutPreviewEntry *shortcut_icon = (ShortcutPreviewEntry *)get_array_entry(2);
    u8 *detail_icon = (u8 *)get_array_entry(3);
    u8 *kind_label = (u8 *)get_array_entry(4);
    u8 *kind_icon = (u8 *)get_array_entry(6);
    u8 *kind_name = (u8 *)get_array_entry(7);
    u8 *preview_label = (u8 *)get_array_entry(8);
    ShortcutPreviewEntry *preview = (ShortcutPreviewEntry *)get_array_entry(10);

    kind = shortcut[0];
    set_text_entry_string(shortcut_label, (uaddr)TWindowSubStatusDisp::get_message_10(0xC4), 0);
    fn_80266BD0(index, &icon, &icon_detail, client_index);
    if (icon != 0x33) {
        SpriteOrigin *origin = (SpriteOrigin *)TWindowSubStatusDisp::get_entry_ptr(icon);
        shortcut_icon->flags &= ~2;
        set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(shortcut_icon), origin->u, origin->v);
    } else {
        shortcut_icon->flags |= 2;
    }

    SpriteOrigin *detail_origin = (SpriteOrigin *)TWindowSubStatusDisp::get_entry_ptr(icon_detail);
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(detail_icon), detail_origin->u, detail_origin->v);
    set_text_entry_string(kind_label, (uaddr)TWindowSubStatusDisp::get_message_10(0xC5), 0);
    set_text_entry_string(kind_name, (uaddr)TWindowSubStatusDisp::get_message_10(0xC0 + kind), 0);
    s32 kind_sprite = shortcut_kind_sprites[kind - 1];
    SpriteOrigin *kind_origin = (SpriteOrigin *)TWindowSubStatusDisp::get_entry_ptr(kind_sprite);
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(kind_icon), kind_origin->u, kind_origin->v);

    position.x = 211.0f;
    position.y = 380.0f;
    set_text_entry_string(preview_label, (uaddr)TWindowSubStatusDisp::get_message_10(0x35), 0);

    switch (kind) {
    case 0:
        break;
    case 1: {
        char *text = fn_80076BC4(shortcut + 1);
        set_text_entry_string((u8 *)preview, (uaddr)text, 0);
        measure_message_text_width(preview, 200.0f);
        preview->flags |= 2;
        size.x = 0.1f + (8.0f + preview->width);
        size.y = 3.0f + (20.0f + preview->height);
        position.x = TWindowSubStatusDisp::round_away_from_zero(position.x - 0.5f * size.x);
        position.y = TWindowSubStatusDisp::round_away_from_zero(position.y - 0.5f * size.y);
        preview_window = create_quest_message_window_at(&position, &size);
        dispatch_message_window_text(preview_window, (saddr)text, 0x402);
        preview_window->set_depth(50060.0f);
        break;
    }
    case 2: {
        s32 *buffer = get_shared_text_buffer();
        u16 player = (u16)local_client_id;
        TWindowDD::format_message(reinterpret_cast<WordSelectMessage *>(shortcut + 1), reinterpret_cast<char *>(buffer), player);
        set_text_entry_string((u8 *)preview, (uaddr)get_shared_text_buffer(), 0);
        measure_message_text_width_default(preview);
        preview->flags |= 2;
        size.x = 0.1f + (8.0f + preview->width);
        size.y = 3.0f + (20.0f + preview->height);
        position.x = TWindowSubStatusDisp::round_away_from_zero(position.x - 0.5f * size.x);
        position.y = TWindowSubStatusDisp::round_away_from_zero(position.y - 0.5f * size.y);
        preview_window = create_quest_message_window_at(&position, &size);
        dispatch_message_window_text(preview_window, (saddr)get_shared_text_buffer(), 2);
        preview_window->set_depth(50060.0f);
        break;
    }
    case 3: {
        SymbolChatPreset *preset = TWindowChat::open_symbol_chat(shortcut + 1);
        set_text_entry_string((u8 *)preview, (uaddr)preset->get_symbol_chat_data(), 0);
        f32 height;
        f32 width;
        width = 203.0f;
        height = 78.0f;
        size.x = width;
        position.x -= 0.5f * width;
        size.y = height;
        position.y -= 0.5f * height;
        TWindowChatSymbol *symbol = (TWindowChatSymbol *)new TWindowChatSymbol((saddr)&position, (saddr)&size);
        symbol_preview = symbol;
        symbol_preview->set_selection(preset);
        symbol_preview->set_depth(50060.0f);
        break;
    }
    }
}
#pragma pop


void TWindowShortCut::render() {
    saddr ctx;
    ctx = reinterpret_cast<saddr>(draw_default_entry());
    draw_window_frame((void *)ctx);
    draw_visible_window_entries(this, &this->entry_list, reinterpret_cast<WindowDrawContext *>(ctx));
    ((TWindowSubStatusDisp *)this->heading)->forward_render((void *)ctx);
}

void TWindowShortCut::run_task() { ((TWindowSubStatusDisp *)(this->heading))->update_subwindow(); ((TWindowDD *)this)->initialize_subwindow(); update_fade(); update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)this + 0x24)); }

TWindowShortCut::~TWindowShortCut() {
    if (this->symbol_preview != NULL) {
        ((TWindowBase *)this->symbol_preview)->close();
        this->symbol_preview = NULL;
    }
    if (this->preview_window != NULL) {
        this->preview_window->close();
        this->preview_window = NULL;
    }
    TWindowSubStatusDisp::destroy_status_display(this->heading, 1);
}
TWindowShortCut::TWindowShortCut(saddr arg1, s32 index, s32 *chat_shortcut) : TWindowBase((u8 *)&window_short_cut_layout, (s16)4, (u8 *)arg1) {
    saddr var_r31;
    m_name = TWindowShortCut__name;
    var_r31 = (saddr)::operator new(0x24);
    if (var_r31 != 0) {
        var_r31 = (saddr)((TWindowSubStatusDisp *)var_r31)->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x35), this->client_index);
    }
    this->heading = var_r31;
    this->preview_window = NULL;
    this->symbol_preview = NULL;
    this->shortcut_index = index;
    this->shortcut = chat_shortcut;
    this->show_shortcut(index, chat_shortcut);
}
