#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_80132ED0.h"

extern "C" {
void TLobby::update_menu_cursor() {
    void *global_state;

    global_state = TAdSinglePlyChrSelectGC::get_global_state();
    if (global_state == NULL) {
        current_language = (language) TLanguage::get_default_language();
        return;
    }
    if ((s8) *(u8 *)((s8 *)global_state + 7) >= 5) {
        *(u8 *)((s8 *)global_state + 7) = 1U;
    }
    current_language = (language) (s8) *(u8 *)((s8 *)global_state + 7);
}
saddr get_localized_text_entry(s32 group, s32 id) {
    return (saddr)text_language_group_table[group][id];
}
void TLobby::free_keyboard_soft_resources() {
    TLanguage::free_alphabet_textures();
    TLanguage::free_text_resources();
}

void TLobby::update_keyboard_menu() {
    TLobby::update_menu_cursor();
    TLanguage::load_text_resources(current_language);
    TLanguage::load_fonts(current_language);
}

}
