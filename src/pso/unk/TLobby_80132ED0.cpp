#include "versions.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern s32 text_language_group_table;
extern "C" {
s32 get_localized_text_entry(s32 arg0, s32 arg1);
#if VERSION == VERSION_GPOP8P
void fn_80145D2C(void);
#endif
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
#if VERSION == VERSION_GPOP8P
    fn_80145D2C();
#endif
}
s32 get_localized_text_entry(s32 arg0, s32 arg1) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)(text_language_group_table + (arg0 * 4)) + 0) + (arg1 * 4)) + 0);
}
void TLobby::free_keyboard_soft_resources() {
    TLanguage::free_alphabet_textures();
    TLanguage::free_text_resources();
}

#if VERSION == VERSION_GPOP8P
void fn_801331C0(void) {
    current_language = (language) TLanguage::get_default_language();
}

#endif
void TLobby::update_keyboard_menu() {
    TLobby::update_menu_cursor();
    TLanguage::load_text_resources(current_language);
    TLanguage::load_fonts(current_language);
}

}
