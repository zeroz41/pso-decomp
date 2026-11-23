#include "pso/ui/chat/SymbolChatPreset.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/unk/TUnk_804CE7D0.h"

// The symbol chat preset selection (inferred): its vtable 0x804CE7D0 follows a 4-byte pad after
// TWindowChatSymbol's vtable (pad + 8-aligned start = new TU); .text 0x80248774-0x80248940,
// .rodata 0x8044EAC0-0x8044EAD8 and .sdata2 0x805DCBA0-0x805DCBA8 are its ctor's.

void TUnk_804CE7D0::render() {  }

void TUnk_804CE7D0::run_task() {
    chat_symbol->set_from_key(preset_list->get_selected_value());
}

TUnk_804CE7D0::~TUnk_804CE7D0() {
    if (chat_symbol != NULL) { chat_symbol->close(); chat_symbol = NULL; }
    if (preset_list != NULL) { preset_list->close(); preset_list = NULL; }
}

extern "C" {
}

TUnk_804CE7D0::TUnk_804CE7D0(TObject *parent) : TObject(parent) {
    // preset_list_pos: where the list of the 12 symbol chat presets opens.
    static const NJS_POINT2 preset_list_pos = {30.0f, 314.0f};
    static const NJS_POINT2 lbl_8044EAC8 = {250.0f, 314.0f};
    static const NJS_POINT2 lbl_8044EAD0 = {168.0f, 120.0f};
    s32 i;
    u8 *text;
    u8 *symbol_chat_preset;
    preset_list = (TWindowSubComCardList *)(u8 *)(saddr)create_window_menu_default((saddr)(&preset_list_pos), 0xC);
    i = 0;
    do {
        symbol_chat_preset = (u8 *)(get_symbol_chat_preset(i));
        text = (u8 *)(reinterpret_cast<SymbolChatPreset *>(symbol_chat_preset)->get_symbol_chat_data());
        if (is_symbol_chat_preset_in_use(reinterpret_cast<const SymbolChatPreset *>(symbol_chat_preset)) != 0) {
            preset_list->add_text_entry((saddr)text, 0x66, i);
        } else {
            add_gray_text_entry((TWindowMenu *)preset_list, (const char *)text, 0x46, (s32)i);
        }
        i += 1;
    } while (i < 0xC);
    preset_list->set_flag70_bit10();
    preset_list->set_scroll_target(220.0f, 120.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(preset_list));
    chat_symbol = new TWindowChatSymbol((saddr)&lbl_8044EAC8, (saddr)&lbl_8044EAD0);
}
