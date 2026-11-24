#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/TGStream.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/RlcArchive.h"
#include "pso/system/ControllerInputState.h"
#include "types.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/unk/TLobby.h"
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

extern "C" {
extern s32 lbl_805D669C;
}

extern "C" {

u32 ARAlloc(u32);

    extern int snapshot_aligned_buffer_size;
void TWindowSnapShot::init_default() { TLobby::aram_transfer_sync((saddr)((void*)1), (uaddr)((void*)shared_snapshot_capture->get_field_8()), lbl_805D669C, snapshot_aligned_buffer_size); }

void TWindowSnapShot__sub_802A7DA0(void) {  }

void TWindowSnapShot::alloc_buffer() {
    s32 file_size = TGStream::get_resource_file_size(get_player_motion_filename());
    snapshot_aligned_buffer_size = (file_size + 31) & ~31;
    lbl_805D669C = ARAlloc(file_size);
}

}

struct Stack_802A7F00 {
    f32 sp8;
    f32 spC;
};

#pragma push
#pragma readonly_strings on
const char *TWindowSnapShot__name = "TWindowSnapShot";
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
s32 play_sound_effect(s32, s32, s32, s32);

void TWindowSnapShot::free_shared_instance() {
    shared_snapshot_capture->update_both();
    delete shared_snapshot_capture;
    shared_snapshot_capture = NULL;
}
}

s32 load_player_motion_data(void) {
    if (shared_snapshot_capture != NULL) {
        return 0;
    }
    shared_snapshot_capture = new RlcArchive;
    if (shared_snapshot_capture == NULL) {
        return 0;
    }
    shared_snapshot_capture->start_capture((saddr)player_motion_data_filename_ptr);
    return 1;
}

saddr RlcArchive::get_size() { return (saddr)header; }
saddr RlcArchive::get_field_8() { return (saddr)buffer; }
int TWindowSnapShot::get_height() { return 600; }

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
    u8 *arg0 = (u8 *)this;
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_open_sound();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowSnapShot::~TWindowSnapShot() {}
TWindowSnapShot::TWindowSnapShot(saddr arg1) : TWindowBase((u8 *)&window_snapshot_layout, (s16)4, (u8 *)arg1) {
    saddr temp_r31;
    m_name = TWindowSnapShot__name;
    this->m_60 = 0U;
    if (!TObjBoss2Tunnel::verify_snapshot_checksum()) {
        this->m_60 = (u8) (this->m_60 | 2);
    }
    temp_r31 = reinterpret_cast<saddr>(((TWindowBase *)this)->get_array_entry(1));
    TWindowDuelResult::set_default_status((void *) temp_r31, get_localized_text_entry(0xF, 0x13));
}

RlcArchive *shared_snapshot_capture;
u32 snapshot_image_buffer;
s32 snapshot_buffer_size;
s32 lbl_805D669C;
int snapshot_aligned_buffer_size;
