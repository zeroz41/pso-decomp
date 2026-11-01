#include "types.h"
#include "pso/misc/TWindowMenuMainMenu.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TWindowSubComCard.h"

struct W_802AE864 { u8 pad[0x124]; void *a[8]; };

extern "C" {
s32 draw_frame__19TWindowMenuMainMenuFv(void *, int);
s32 setup_content_frame__15TWindowMainMenuFPv();
extern s32 window_menu_main_menu_params[];
extern s32 __vt__19TWindowMenuMainMenu[];
extern s32 lbl_805D3E68;
void __dl__7TObjectFPv(void *);

void render__19TWindowMenuMainMenuFv(s32 arg0) {
    s32 temp_r3;
    temp_r3 = setup_content_frame__15TWindowMainMenuFPv();
    draw_frame__19TWindowMenuMainMenuFv((void *)arg0, (int)temp_r3);
    ((TWindowMainMenu *)arg0)->draw_entries_reversed((u8 *)temp_r3);
}

void run_task__19TWindowMenuMainMenuFv(TWindowMenuMainMenu *window_menu_main_menu) {
    s32 var_r31;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 *var_r30;

    temp_r3 = window_menu_main_menu->m_60;
    if (temp_r3 & 8) {
        window_menu_main_menu->m_60 = (u8) (temp_r3 | 4);
    }
    var_r30 = (u8 *)window_menu_main_menu + 0x64;
    var_r31 = 0;
    do {
        ((TWindowMainMenu *)var_r30)->update_item_tween();
        var_r31 += 1;
        var_r30 += 0x18;
    } while (var_r31 < 8);
    window_menu_main_menu->handle_navigation_input();
    ((TWindowDD *)window_menu_main_menu)->initialize_subwindow();
    ((TWindowMainMenu *)window_menu_main_menu)->update_slide_position();
    ((TWindowBase *)window_menu_main_menu)->update_fade();
    temp_r3_2 = window_menu_main_menu->m_60;
    if (temp_r3_2 & 8) {
        window_menu_main_menu->m_60 = (u8) (temp_r3_2 & 0xFFFFFFF3);
    }
}

void *__dt__19TWindowMenuMainMenuFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowMenuMainMenu;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TWindowMenuMainMenu__ct(TWindowMenuMainMenu *window_menu_main_menu, s32 arg1, s16 arg2) {
    s32 i;
    u8 *p;
    ((TWindowDD *)window_menu_main_menu)->construct_base((u8 *)window_menu_main_menu_params, (s16)arg2, (u8 *)arg1);
    *(s32 **)((s8 *)window_menu_main_menu + 0x18) = __vt__19TWindowMenuMainMenu;
    p = (u8 *)window_menu_main_menu + 0x64;
    i = 0;
    *(s32 *)((s8 *)window_menu_main_menu + 0) = lbl_805D3E68;
    window_menu_main_menu->m_60 = 4;
    window_menu_main_menu->m_61 = 0;
    window_menu_main_menu->m_62 = 0;
    window_menu_main_menu->m_20 = arg2;
    do {
        ((TWindowMainMenu *)p)->init_color();
        i++;
        p += 0x18;
    } while (i < 8);
    for (i = 0; i < 8; i++) {
        ((W_802AE864 *)window_menu_main_menu)->a[i] = 0;
    }
    ((TWindowMainMenu *)window_menu_main_menu)->update_scaled_position();
    ((TWindowBase *)window_menu_main_menu)->save_position();
    return (u8 *)window_menu_main_menu;
}

}
