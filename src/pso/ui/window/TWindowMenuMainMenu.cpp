#include "types.h"
#include "pso/ui/window/TWindowMenuMainMenu.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/unk/WindowLayoutRecord.h"

struct W_802AE864 { u8 pad[0x124]; void *a[8]; };

WindowDescriptor window_menu_main_menu_params = {
    {116.0f, 0.0f}, 50050.0f, NULL, 0x803,
};

extern "C" {
s32 setup_content_frame__15TWindowMainMenuFPv();
extern const char *TWindowMenuMainMenu__class_name;

void render__19TWindowMenuMainMenuFv(saddr arg0) {
    saddr frame;
    frame = setup_content_frame__15TWindowMainMenuFPv();
    ((TWindowMenuMainMenu *)arg0)->draw_frame((WindowDrawContext *)frame);
    ((TWindowMainMenu *)arg0)->draw_entries_reversed((u8 *)frame);
}

void TWindowMenuMainMenu::run_task() {
    s32 i;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 *var_r30;

    temp_r3 = this->m_60;
    if (temp_r3 & 8) {
        this->m_60 = (u8) (temp_r3 | 4);
    }
    var_r30 = (u8 *)this + 0x64;
    i = 0;
    do {
        ((TWindowMainMenu *)var_r30)->update_item_tween();
        i += 1;
        var_r30 += 0x18;
    } while (i < 8);
    this->handle_navigation_input();
    ((TWindowDD *)this)->initialize_subwindow();
    this->update_slide_position();
    update_fade();
    temp_r3_2 = this->m_60;
    if (temp_r3_2 & 8) {
        this->m_60 = (u8) (temp_r3_2 & 0xFFFFFFF3);
    }
}

TWindowMenuMainMenu::~TWindowMenuMainMenu() {}
TWindowMenuMainMenu::TWindowMenuMainMenu(saddr arg1, s16 arg2) : TWindowBase((u8 *)&window_menu_main_menu_params, (s16)arg2, (u8 *)arg1) {
    s32 i;
    u8 *p;

    p = (u8 *)this + 0x64;
    i = 0;
    this->m_name = TWindowMenuMainMenu__class_name;
    this->m_60 = 4;
    this->m_61 = 0;
    this->m_62 = 0;
    this->client_index = arg2;
    do {
        ((TWindowMainMenu *)p)->init_color();
        i++;
        p += 0x18;
    } while (i < 8);
    for (i = 0; i < 8; i++) {
        ((W_802AE864 *)this)->a[i] = 0;
    }
    update_scaled_position();
    ((TWindowBase *)this)->save_position();
}

}
