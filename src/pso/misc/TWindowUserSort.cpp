#include "types.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/misc/TWindowBase.h"
struct TCameraCtrl;

#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TWindowUserSort.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowMainMenu1P.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80288490_lbl_804D0460 { s32 value; u8 remaining[0x3C]; };
typedef char RecoveredGlobal_80288490_lbl_804D0460_size[sizeof(RecoveredGlobal_80288490_lbl_804D0460) == 0x40 ? 1 : -1];

struct RecoveredGlobal_80288490_lbl_804D04A0 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80288490_lbl_804D04A0_size[sizeof(RecoveredGlobal_80288490_lbl_804D04A0) == 0x38 ? 1 : -1];

struct RecoveredGlobal_80288380_lbl_804D304C {
    s32 value;
    u8 remaining[0x10];
};

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
extern RecoveredGlobal_80288380_lbl_804D304C window_user_sort_settings;
extern s32 __vt__15TWindowUserSort[];
extern s32 TWindowUserSort__name;
u8 *TWindowUserSort__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__15TWindowUserSortFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
s32 close_and_clear_flags__15TWindowMainMenuFv();
int initialize_subwindow__9TWindowDDFv(void*);

void render__15TWindowUserSortFv(s32 arg0) {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)temp_r3);
}

void TWindowUserSort::run_task() { initialize_subwindow__9TWindowDDFv(this); update_fade(); update_window_entry_list((char*)this + 0x24); }

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

typedef char RecoveredGlobal_80288380_lbl_804D304C_size[sizeof(RecoveredGlobal_80288380_lbl_804D304C) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80288380___vt__15TWindowUserSort_size[sizeof(RecoveredGlobal_80288380___vt__15TWindowUserSort) == 0x18 ? 1 : -1];
u8 *TWindowUserSort__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TWindowDD *)arg0)->construct_base((u8 *)((s32) &window_user_sort_settings.value), (s16)4, (u8 *)arg1);
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
