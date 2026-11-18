#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/text_80268384.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {
extern s32 __vt__19TWindowSubEquipKind[];
extern s32 TWindowSubEquipKind__class_name;
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 run_task__19TWindowMenuIconLineFv();
s32 draw_window_scrollbar(s32, s32, void *);
void __dl__7TObjectFPv(void *);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);

void render__19TWindowSubEquipKindFv(u8 *arg0) {
    s32 temp_r3;

    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    ((TWindowMenuIconLine *)arg0)->draw_selected_list_entry(temp_r3);
    if ((s16) ((TWindowSubEquipKind *)arg0)->m_88 != 4) {
        ((TWindowSubEquipKind *)arg0)->draw_tab_label((void *)temp_r3);
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
        forward_render__20TWindowSubStatusDispFv(*(u32 *)((s8 *)arg0 + 0x80), temp_r3);
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x84) != 0U) {
        draw_window_scrollbar(*(u32 *)((s8 *)arg0 + 0x84), temp_r3, arg0 + 0x68);
    }
}

void TWindowSubEquipKind::run_task() {
    int temp_r3;

    run_task__19TWindowMenuIconLineFv();
    temp_r3 = this->m_8a;
    if (temp_r3 != 0) {
        this->m_8a = (temp_r3 - 1);
    }
}

void *__dt__19TWindowSubEquipKindFv(void *window_sub_status_disp, s16 arg1) {
    if (window_sub_status_disp != NULL) {
        *(s32 **)((s8 *)window_sub_status_disp + 0x18) = __vt__19TWindowSubEquipKind;
        __dt__19TWindowMenuIconLineFv(window_sub_status_disp, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}
u8 *TWindowSubEquipKind__ct(u8 *window_sub_equip_kind, s32 arg1, s16 arg2) {
    fn_802683F4((window_sub_equip_kind), (arg1), 0x1F, (arg2));
    *(s32 **)((s8 *)window_sub_equip_kind + 0x18) = __vt__19TWindowSubEquipKind;
    *(s32 *)((s8 *)window_sub_equip_kind + 0) = (s32) TWindowSubEquipKind__class_name;
    ((TWindowMenuIconLine *)window_sub_equip_kind)->create_menu_scroll_bar();
    ((TWindowSubEquipKind *)window_sub_equip_kind)->m_88 = 4;
    ((TWindowSubEquipKind *)window_sub_equip_kind)->m_8a = 0;
    return window_sub_equip_kind;
}

}
