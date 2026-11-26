#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuTeamStatus.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TGameListRow.h"

extern "C" {
u8 *get_window_layout_position(s32);
}

void TWindowMenuTeamStatus::add_entry(s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mode, s8 episode, s32 index) {
    if (entry_count < entry_capacity) {
        static_cast<TGameListRow *>(get_array_entry(entry_count))->fill(locked, name, player_count, max_players, difficulty, mode, episode, index);
        entry_count++;
    }
}

// The class-name string TWindowMenuTeamStatus::init stores to m_name.
const char *TWindowMenuTeamStatus::class_name = "TWindowMenuTeamStatus";

void TWindowMenuTeamStatus::init(u32 count, s32 id) {
    s32 i;
    TGameListRow *row;

    m_name = TWindowMenuTeamStatus::class_name;
    client_index = id;
    entry_count = 0;
    cursor = 0;
    entry_capacity = count;
    saved_cursor = 0;
    saved_cursor_value = 0;
    state_flags = 0;
    status_display = 0;
    scroll_bar = 0;
    for (i = 0; i < (s32)count; i++) {
        row = (TGameListRow *)get_array_entry(i);
        row->y = i * 20;
    }
}

TWindowMenuTeamStatus *TWindowMenuTeamStatus::create(const char *tbl) {
    return new TWindowMenuTeamStatus(tbl);
}

TWindowMenuTeamStatus::~TWindowMenuTeamStatus() {}

// The window descriptor the constructor hands to the base constructor, with its layout words.
s32 team_status_window_layout_entries[3] = {1, 0x40, 0xC};
WindowDescriptor team_status_window_layout = {
    {605.0f, 184.0f}, 50050.0f, team_status_window_layout_entries, 3,
};

TWindowMenuTeamStatus::TWindowMenuTeamStatus(const char *arg)
    : TWindowShop(get_window_layout_position(0xB0), arg, 0x40, (u8 *)&team_status_window_layout) {}
