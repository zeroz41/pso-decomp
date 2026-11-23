#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TUnk_804EF4E0.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/WindowLayoutRecord.h"

struct O_80338D58 { u8 pad[0x72]; s16 idx; u8 pad2[2]; s16 count; };

extern "C" {
u8 *get_window_layout_position(s32);
s32 TWindowSubStatusDisp__sub_80338740(void *, void *, void *, void *, void *, void *, void *, void *, void *);

void fn_80338D58(O_80338D58 *arg0, void *flag, void *name, void *a3, void *a4, void *a5, void *a6, void *a7, void *index) {
    if (arg0->idx < arg0->count) {
        TWindowSubStatusDisp__sub_80338740((void *)((TWindowBase *)arg0)->get_array_entry(arg0->idx), flag, name, a3, a4, a5, a6, a7, index);
        arg0->idx += 1;
    }
}

}

// The class-name string TWindowMenuTeamStatus::init stores to m_name.
const char *TWindowMenuTeamStatus__name = "TWindowMenuTeamStatus";

void TWindowMenuTeamStatus::init(u32 count, s32 id) {
    s32 i;
    TWindowMenuTeamStatus::Entry *entry;

    m_name = TWindowMenuTeamStatus__name;
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
        entry = (TWindowMenuTeamStatus::Entry *)get_array_entry(i);
        entry->m_0c = i * 20;
    }
}

void *TLobby::create_object(void *tbl) {
    return new TWindowMenuTeamStatus((saddr)tbl);
}

TWindowMenuTeamStatus::~TWindowMenuTeamStatus() {}

// The window descriptor the constructor hands to the base constructor, with its layout words (the
// lbl_804D05F8/lbl_804D0604 pair of TWindowSubStatusDisp_802671F0.cpp has the same shape).
s32 lbl_804EF4C0[3] = {1, 0x40, 0xC};
WindowDescriptor lbl_804EF4CC = {
    {605.0f, 184.0f}, 50050.0f, lbl_804EF4C0, 3,
};

TWindowMenuTeamStatus::TWindowMenuTeamStatus(s32 arg)
    : TWindowShop(get_window_layout_position(0xB0), arg, 0x40, (u8 *)&lbl_804EF4CC) {}
