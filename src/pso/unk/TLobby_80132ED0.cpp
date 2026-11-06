#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/Language.h"

extern s32 text_language_group_table;
extern "C" {
s32 get_localized_text_entry(s32 arg0, s32 arg1);
}
extern "C" {
void *get_global_state__23TAdSinglePlyChrSelectGCFv();

void TLobby::update_menu_cursor() {
    void *temp_r3;

    temp_r3 = get_global_state__23TAdSinglePlyChrSelectGCFv();
    if (temp_r3 == NULL) {
        current_language = (language) TLanguage::get_default_language();
        return;
    }
    if ((s8) *(u8 *)((s8 *)temp_r3 + 7) >= 5) {
        *(u8 *)((s8 *)temp_r3 + 7) = 1U;
    }
    current_language = (language) (s8) *(u8 *)((s8 *)temp_r3 + 7);
}
s32 get_localized_text_entry(s32 arg0, s32 arg1) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)(text_language_group_table + (arg0 * 4)) + 0) + (arg1 * 4)) + 0);
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
