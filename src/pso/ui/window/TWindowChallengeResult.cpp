#pragma defer_codegen on

#include "types.h"
#include "pso/ui/window/TWindowChallengeResult.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/WindowLayout.h"
#pragma push
#pragma readonly_strings on

const char *TWindowChallengeResult__name = "TWindowChallengeResult";
#pragma pop

extern "C" {

struct ResultEntry {
    u8 unknown_00[8];
    f32 x;
    u8 unknown_0c[4];
    f32 width;
    u8 unknown_14[0xC];
    s32 value;
};

extern const char lbl_8044E7BC[];

struct ChallengeResultLayout {
    u32 columns;
    u32 rows;
    TextLayoutRecord text[5];
    ValueLayoutRecord deaths;
};

ChallengeResultLayout challenge_result_window_layout = {
    6, 1,
    {
        {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
        {3, {233.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
        {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
        {3, {233.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
        {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    },
    {4, {233.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
};

WindowDescriptor lbl_804CE298 = {
    {466.0f, 88.0f}, 50100.0f, &challenge_result_window_layout, 0x23,
};
#pragma push
#pragma readonly_strings on
const char *lbl_804CE2AC[3] = {
    "Team Name : ", "Clear Time : ", "Death : ",
};
#pragma pop
}

TWindowChallengeResult::TWindowChallengeResult(const char *team_name, s32 clear_seconds, s32 death_count)
    : TWindowBase((u8 *)&lbl_804CE298, 4, (u8 *)get_window_layout_position(0x3F)) {
    s32 i;
    ResultEntry *e;
    s32 hours;

    m_name = TWindowChallengeResult__name;
    for (i = 0; i < 3; i++) {
        e = (ResultEntry *)get_array_entry(i * 2);
        set_text_entry_string((u8 *)e, (uaddr)lbl_804CE2AC[i], 0);
        measure_message_text_width_default(e);
        e->x = 233.0f - e->width;
    }
    set_text_entry_string((u8 *)(get_array_entry(1)), (uaddr)team_name, 0x20);
    e = (ResultEntry *)get_array_entry(3);
    text_builder_reset();
    hours = clear_seconds / 3600;
    clear_seconds = clear_seconds % 3600;
    if (hours > 99) {
        text_builder_append((u8 *)lbl_8044E7BC);
    } else {
        append_padded_number(hours, 2);
        text_builder_append((u8 *)":");
        s32 minutes = clear_seconds / 60;
        clear_seconds = clear_seconds % 60;
        append_padded_number(minutes, 2);
        text_builder_append((u8 *)":");
        append_padded_number(clear_seconds, 2);
    }
    set_text_entry_string((u8 *)e, (uaddr)(get_shared_text_buffer()), 0x20);
    e = (ResultEntry *)get_array_entry(5);
    e->value = death_count;
    draw_right_aligned_number(e);
    e->x = 233.0f + e->width;
    if (TCameraCtrl::get_camera_id() == 4) {
        scale_x = 0.68f;
        scale_y = 0.68f;
    } else {
        scale_x = 1.0f;
        scale_y = 1.0f;
    }
}

TWindowChallengeResult::~TWindowChallengeResult() {}

void TWindowChallengeResult::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_window_entry_list(&entry_list);
}

void TWindowChallengeResult::render() {
    WindowDrawContext *context = setup_window_draw_context(&scale_x);
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
}

// The capped clear time, defined after its use so the constructor addresses it on its own.
__declspec(section ".rodata") const char lbl_8044E7BC[] = "99:59:59";
