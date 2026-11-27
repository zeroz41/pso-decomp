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
const char *TWindowUserSort::class_name = "TWindowUserSort";

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


void TWindowUserSort::render() {
    WindowDrawContext *context;
    context = draw_default_entry();
    draw_window_frame(context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>(&entry_list),
        context);
}

void TWindowUserSort::run_task() { update_window(); update_fade(); update_window_entry_list(&entry_list); }

TWindowUserSort::~TWindowUserSort() {}

TWindowUserSort::TWindowUserSort(saddr position, GuildCardRecord *record) : TWindowBase((u8 *)&window_user_sort_settings, (s16)4, (u8 *)position) {
    m_name = TWindowUserSort::class_name;
    this->record = record;
    ((TWindowSubStatusDisp *)&entry_list)->fill_card_text_entries(record);
}

void TWindowMainMenu1P::on_submenu_closed() { if (close_active_submenu() != 0) { this->create_char_select_slot(); } }

void TWindowMainMenu1P::on_menu_opened() {
    s32 flags;

    flags = menu_flags;
    if (!(flags & 2)) {
        menu_flags = (s32) (flags | 2);
        backdrop.begin_override();
    }
}

void TWindowMainMenu1P::close_main_menu() {
    if (menu_flags & 1) {
        TWindowMainMenu::close_and_clear_flags();
    }
}
void TWindowMainMenu1P::open_main_menu() {
    u8 *player;
    if (!(menu_flags & 1)) {
        player = (u8 *)(get_player_by_client_id(client_index));
        if (player != NULL) {
            if (((TObjPlayer *)player)->is_android() != 0) {
                this->open(main_menu_1p_android_entries);
            } else {
                this->open(main_menu_1p_entries);
            }
            this->create_char_select_slot();
            this->on_menu_opened();
        }
    }
}

