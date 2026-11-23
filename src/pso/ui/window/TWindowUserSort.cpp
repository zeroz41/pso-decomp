#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
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
#include "pso/player/PlayerSlots.h"

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

void TWindowUserSort::render() {
    saddr context;
    context = reinterpret_cast<saddr>(draw_default_entry());
    draw_window_frame((void *)context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>(&entry_list),
        reinterpret_cast<WindowDrawContext *>(context));
}

void TWindowUserSort::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_fade(); update_window_entry_list(&entry_list); }

TWindowUserSort::~TWindowUserSort() {}

#define self ((u8 *)this)
TWindowUserSort::TWindowUserSort(saddr arg1, GuildCardRecord *record) : TWindowBase((u8 *)&window_user_sort_settings, (s16)4, (u8 *)arg1) {
    m_name = TWindowUserSort__name;
    m_60 = record;
    ((TWindowSubStatusDisp *)(self + 0x24))->fill_card_text_entries(record);
}
#undef self

void TWindowMainMenu1P::on_submenu_closed() { if (close_active_submenu() != 0) { this->create_char_select_slot(); } }

void TWindowMainMenu1P::on_menu_opened() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    temp_r3 = *(s32 *)((s8 *)arg0 + 0x4C);
    if (!(temp_r3 & 2)) {
        *(s32 *)((s8 *)arg0 + 0x4C) = (s32) (temp_r3 | 2);
        backdrop.begin_override();
    }
}

void TWindowMainMenu1P::close_main_menu() {
    if (*(s32 *)((s8 *)this + 0x4C) & 1) {
        TWindowMainMenu::close_and_clear_flags();
    }
}
void TWindowMainMenu1P::open_main_menu() {
    u8 *arg0 = (u8 *)this;
    u8 *player;
    if (!(*(s32 *)((s8 *)arg0 + 0x4C) & 1)) {
        player = (u8 *)(get_player_by_client_id(*(u32 *)((s8 *)arg0 + 0x54)));
        if (player != NULL) {
            if (((TObjPlayer *)player)->is_android() != 0) {
                ((TWindowMainMenu *)arg0)->open((saddr)main_menu_1p_android_entries);
            } else {
                ((TWindowMainMenu *)arg0)->open((saddr)main_menu_1p_entries);
            }
            ((TWindowMainMenu1P *)arg0)->create_char_select_slot();
            this->on_menu_opened();
        }
    }
}

}
