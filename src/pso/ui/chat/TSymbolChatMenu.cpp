#include "pso/ui/chat/SymbolChatPreset.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/unk/TSymbolChatMenu.h"

// The symbol chat preset selection: its vtable follows a 4-byte pad after
// TWindowChatSymbol's vtable (pad + 8-aligned start = new TU).

void TSymbolChatMenu::render() {  }

void TSymbolChatMenu::run_task() {
    chat_symbol->set_from_key(preset_list->get_selected_value());
}

TSymbolChatMenu::~TSymbolChatMenu() {
    if (chat_symbol != NULL) { chat_symbol->close(); chat_symbol = NULL; }
    if (preset_list != NULL) { preset_list->close(); preset_list = NULL; }
}


TSymbolChatMenu::TSymbolChatMenu(TObject *parent) : TObject(parent) {
    // preset_list_pos: where the list of the 12 symbol chat presets opens.
    static const NJS_POINT2 preset_list_pos = {30.0f, 314.0f};
    static const NJS_POINT2 symbol_chat_menu_position = {250.0f, 314.0f};
    static const NJS_POINT2 symbol_chat_menu_size = {168.0f, 120.0f};
    s32 i;
    u8 *text;
    SymbolChatPreset *symbol_chat_preset;
    preset_list = (TWindowSubComCardList *)create_window_menu_default(&preset_list_pos, 0xC);
    i = 0;
    do {
        symbol_chat_preset = get_symbol_chat_preset(i);
        text = (u8 *)(symbol_chat_preset->get_symbol_chat_data());
        if (is_symbol_chat_preset_in_use(symbol_chat_preset) != 0) {
            preset_list->add_text_entry((const char *)text, 0x66, i);
        } else {
            add_gray_text_entry(preset_list, (const char *)text, 0x46, i);
        }
        i += 1;
    } while (i < 0xC);
    preset_list->set_flag70_bit10();
    preset_list->set_scroll_target(220.0f, 120.0f);
    align_menu_entry_positions(preset_list);
    chat_symbol = new TWindowChatSymbol(&symbol_chat_menu_position, &symbol_chat_menu_size);
}
