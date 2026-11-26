#include "pso/system/TGStream.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/RlcArchive.h"
#include "pso/system/ControllerInputState.h"
#include "types.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/AramPool.h"
#include <dolphin/ar.h>

void upload_player_motion_data() { aram_transfer_sync(1, player_motion_archive->get_buffer(), player_motion_aram_addr, player_motion_aram_size); }

void TWindowSnapShot__sub_802A7DA0(void) {  }

void alloc_player_motion_aram() {
    s32 file_size = TGStream::get_resource_file_size(get_player_motion_filename());
    player_motion_aram_size = (file_size + 31) & ~31;
    player_motion_aram_addr = ARAlloc(file_size);
}

struct Stack_802A7F00 {
    f32 sp8;
    f32 spC;
};

#pragma push
#pragma readonly_strings on
const char *TWindowSnapShot::class_name = "TWindowSnapShot";
#pragma pop

// inferred: window_snapshot_layout_entries, the layout table window_snapshot_layout points at
// (a sprite part and a text line).
struct SnapShotWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
};


SnapShotWindowLayout window_snapshot_layout_entries = {
    2, 1,
    {6, {372.0f, 240.0f}, {18.0f, 18.0f}, 178.0f, 203.0f, 0.5f, -1, &hud_texlist, 0, 4},
    {3, {399.0f, 240.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};

WindowDescriptor window_snapshot_layout = {
    {512.0f, 280.0f}, 50100.0f, &window_snapshot_layout_entries, 3,
};

extern "C" {
s32 draw_screen_snapshot(f32 *, f32);
}

void free_player_motion_archive() {
    player_motion_archive->update_both();
    delete player_motion_archive;
    player_motion_archive = NULL;
}

s32 load_player_motion_data(void) {
    if (player_motion_archive != NULL) {
        return 0;
    }
    player_motion_archive = new RlcArchive;
    if (player_motion_archive == NULL) {
        return 0;
    }
    player_motion_archive->start_capture((saddr)player_motion_data_filename_ptr);
    return 1;
}

RlcHeader *RlcArchive::get_header() { return header; }
u8 *RlcArchive::get_buffer() { return buffer; }
int get_player_motion_max_entries() { return 600; }

const char *get_player_motion_filename(void) { return player_motion_data_filename_ptr; }

void TWindowSnapShot::play_open_sound() {
    play_sound_effect(0x52F16, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
}

void TWindowSnapShot::render() {
    Stack_802A7F00 stack;
    WindowDrawContext *context = draw_default_entry();
    draw_window_frame(context);
    draw_visible_window_entries(this, &this->entry_list, context);
    if (!(m_60 & 2)) {
        if (context->open_tick > 0) {
            stack.sp8 = 18.0f + context->inner_x;
            stack.spC = context->inner_y;
            draw_screen_snapshot(&stack.sp8, 18.0f);
        }
    } else {
        draw_window_text(&context->inner_x, (const char *)(get_localized_text_entry(0x24, 7)), -1, 0, 1000000.0f);
    }
}

void TWindowSnapShot::run_task() {
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_open_sound();
    }
    update_window();
    this->update_fade();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowSnapShot::~TWindowSnapShot() {}
TWindowSnapShot::TWindowSnapShot(saddr arg1) : TWindowBase((u8 *)&window_snapshot_layout, (s16)4, (u8 *)arg1) {
    saddr entry_1;
    m_name = TWindowSnapShot::class_name;
    this->m_60 = 0U;
    if (!TObjBoss2Tunnel::verify_snapshot_checksum()) {
        this->m_60 = (u8) (this->m_60 | 2);
    }
    entry_1 = reinterpret_cast<saddr>(this->get_array_entry(1));
    TWindowDuelResult::set_default_status((void *) entry_1, get_localized_text_entry(0xF, 0x13));
}

RlcArchive *player_motion_archive;
RlcHeader *player_motion_directory;
s32 player_motion_directory_size;
s32 player_motion_aram_addr;
int player_motion_aram_size;
