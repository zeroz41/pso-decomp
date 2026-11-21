#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_80132ED0.h"

extern saddr text_language_group_table;
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
saddr get_localized_text_entry(s32 arg0, s32 arg1) {
    return *(saddr *)((s8 *)(*(saddr *)((s8 *)(text_language_group_table + (arg0 * 4)) + 0) + (arg1 * 4)) + 0);
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
