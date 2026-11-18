#include "types.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
struct TCameraCtrl;

#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowUserSort.h"

#include "pso/ui/window/TWindowMainMenu1P.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/WindowLayoutRecord.h"

#pragma push
#pragma readonly_strings on
const char *TWindowUserSort__name = "TWindowUserSort";

// inferred: window_user_sort_layout_entries, the layout table window_user_sort_settings points at
// (label/value rows for name, ship, block and team; fill_card_text_entries fills the values).
struct UserSortWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec[9];
};
UserSortWindowLayout window_user_sort_layout_entries = {
    9, 1,
    {
        {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0x40, "Name"},
        {3, {63.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0x40, "Ship"},
        {3, {63.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0x40, "Block"},
        {3, {63.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0x40, "Team"},
        {3, {63.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
    },
};
#pragma pop

WindowDescriptor window_user_sort_settings = {
    {243.0f, 184.0f}, 50100.0f, &window_user_sort_layout_entries, 0x23,
};

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
void *get_player_by_client_id(s32 i);
extern s32 __vt__15TWindowUserSort[];
u8 *TWindowUserSort__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 close_and_clear_flags__15TWindowMainMenuFv();

void TWindowUserSort::render() {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(this, &entries, (int)temp_r3);
}

void TWindowUserSort::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_fade(); update_window_entry_list(&entries); }

TWindowUserSort::~TWindowUserSort() {}

u8 *TWindowUserSort__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__11TWindowBaseFPUcsPUc(arg0, (u8 *)&window_user_sort_settings, (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TWindowUserSort;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TWindowUserSort__name;
    ((TWindowUserSort *)arg0)->m_60 = arg2;
    ((TWindowSubStatusDisp *)(arg0 + 0x24))->fill_card_text_entries(arg2);
    return arg0;
}

void TWindowMainMenu1P::vfunc_9() { if (close_active_submenu() != 0) { this->create_char_select_slot(); } }

void TWindowMainMenu1P::vfunc_7() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    temp_r3 = *(s32 *)((s8 *)arg0 + 0x4C);
    if (!(temp_r3 & 2)) {
        *(s32 *)((s8 *)arg0 + 0x4C) = (s32) (temp_r3 | 2);
        ((CameraViewParams *)(arg0 + 0x64))->begin_override();
    }
}

void TWindowMainMenu1P::vfunc_8() {
    if (*(s32 *)((s8 *)this + 0x4C) & 1) {
        close_and_clear_flags__15TWindowMainMenuFv();
    }
}
void TWindowMainMenu1P::vfunc_6() {
    u8 *arg0 = (u8 *)this;
    u8 *player;
    if (!(*(s32 *)((s8 *)arg0 + 0x4C) & 1)) {
        player = (u8 *)(get_player_by_client_id(*(u32 *)((s8 *)arg0 + 0x54)));
        if (player != NULL) {
            if (((TObjPlayer *)player)->is_android() != 0) {
                ((TWindowMainMenu *)arg0)->open((s32)main_menu_1p_android_entries);
            } else {
                ((TWindowMainMenu *)arg0)->open((s32)main_menu_1p_entries);
            }
            ((TWindowMainMenu1P *)arg0)->create_char_select_slot();
            this->vfunc_7();
        }
    }
}

}
