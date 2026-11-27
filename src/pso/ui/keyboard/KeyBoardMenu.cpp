#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"

void update_menu_cursor() {
    SystemSaveData *global_state;

    global_state = TAdSinglePlyChrSelectGC::get_global_state();
    if (global_state == NULL) {
        current_language = (language) TLanguage::get_default_language();
        return;
    }
    if (global_state->language >= 5) {
        global_state->language = 1;
    }
    current_language = (language) global_state->language;
}
const char *get_localized_text_entry(s32 group, s32 id) {
    return text_language_group_table[group][id];
}
void free_keyboard_soft_resources() {
    TLanguage::free_alphabet_textures();
    TLanguage::free_text_resources();
}

void update_keyboard_menu() {
    update_menu_cursor();
    TLanguage::load_text_resources(current_language);
    TLanguage::load_fonts(current_language);
}
