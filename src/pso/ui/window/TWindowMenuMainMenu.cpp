#include "types.h"
#include "pso/ui/window/TWindowMenuMainMenu.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/unk/WindowLayoutRecord.h"

WindowDescriptor window_menu_main_menu_params = {
    {116.0f, 0.0f}, 50050.0f, NULL, 0x803,
};

extern "C" {
extern const char *TWindowMenuMainMenu__class_name;

void TWindowMenuMainMenu::render() {
    WindowDrawContext *frame = setup_content_frame();
    draw_frame(frame);
    draw_entries_reversed(frame);
}

void TWindowMenuMainMenu::run_task() {
    s32 i;
    u8 temp_r3;
    u8 temp_r3_2;

    TMainMenuEntry *entry;
    temp_r3 = state_flags;
    if (temp_r3 & 8) {
        state_flags = (u8) (temp_r3 | 4);
    }
    entry = entries;
    i = 0;
    do {
        entry->update_item_tween();
        i += 1;
        entry += 1;
    } while (i < 8);
    handle_navigation_input();
    ((TWindowDD *)this)->initialize_subwindow();
    update_slide_position();
    update_fade();
    temp_r3_2 = state_flags;
    if (temp_r3_2 & 8) {
        state_flags = (u8) (temp_r3_2 & 0xFFFFFFF3);
    }
}

TWindowMenuMainMenu::~TWindowMenuMainMenu() {}
TWindowMenuMainMenu::TWindowMenuMainMenu(const NJS_POINT2 *position, s32 client)
    : TWindowBase((u8 *)&window_menu_main_menu_params, (s16)client, (u8 *)position) {
    s32 i;
    TMainMenuEntry *entry;
    entry = entries;
    i = 0;
    m_name = TWindowMenuMainMenu__class_name;
    state_flags = 4;
    selected_slot = 0;
    parked_row_count = 0;
    client_index = client;
    do {
        entry->init_color();
        i++;
        entry++;
    } while (i < 8);
    for (i = 0; i < 8; i++) {
        slots[i] = 0;
    }
    update_scaled_position();
    save_position();
}

}
