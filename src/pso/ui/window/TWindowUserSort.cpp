#include "types.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
struct TCameraCtrl;

#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowUserSort.h"
#include "pso/ui/window/TWindowDD.h"
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

struct RecoveredGlobal_80288490_lbl_804D0460 { s32 value; u8 remaining[0x3C]; };
typedef char RecoveredGlobal_80288490_lbl_804D0460_size[sizeof(RecoveredGlobal_80288490_lbl_804D0460) == 0x40 ? 1 : -1];

struct RecoveredGlobal_80288490_lbl_804D04A0 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80288490_lbl_804D04A0_size[sizeof(RecoveredGlobal_80288490_lbl_804D04A0) == 0x38 ? 1 : -1];

struct RecoveredGlobal_80288380___vt__15TWindowUserSort {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
void *get_player_by_client_id(s32 i);
extern RecoveredGlobal_80288490_lbl_804D0460 lbl_804D0460;
extern RecoveredGlobal_80288490_lbl_804D04A0 lbl_804D04A0;
extern s32 __vt__15TWindowUserSort[];
u8 *TWindowUserSort__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__15TWindowUserSortFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
s32 close_and_clear_flags__15TWindowMainMenuFv();

void render__15TWindowUserSortFv(s32 arg0) {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)temp_r3);
}

void TWindowUserSort::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_fade(); update_window_entry_list((char*)this + 0x24); }

void *__dt__15TWindowUserSortFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TWindowUserSort;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80288380___vt__15TWindowUserSort_size[sizeof(RecoveredGlobal_80288380___vt__15TWindowUserSort) == 0x18 ? 1 : -1];
u8 *TWindowUserSort__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TWindowDD *)arg0)->construct_base((u8 *)&window_user_sort_settings, (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80288380___vt__15TWindowUserSort *)&__vt__15TWindowUserSort).value;
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
                ((TWindowMainMenu *)arg0)->open((s32) &lbl_804D04A0.value);
            } else {
                ((TWindowMainMenu *)arg0)->open((s32) &lbl_804D0460.value);
            }
            ((TWindowMainMenu1P *)arg0)->create_char_select_slot();
            this->vfunc_7();
        }
    }
}

}
