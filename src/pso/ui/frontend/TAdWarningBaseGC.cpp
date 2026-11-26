#include "types.h"
#include <dolphin/ar.h>
#include <dolphin/os/OSCache.h>
#include "pso/system/GbaAramCache.h"
#include "pso/system/TGbaAramUploadTask.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/TLobby.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MallocLoadFilePrc.h"

ARQRequest ad_warning_arq_request;
u32 ad_warning_aram_base;
u32 TAdWarningBaseGC::aram_capacity;
s32 warning_aram_load_done_flag;
int TAdWarningBaseGC::aram_alloc_size;
int lobby_count_value;
s32 aram_request_busy_flag;
const char *TAdWarningBaseGC_class_name = "TAdWarningBaseGC";
static const f32 warning_window_position[2] = {46.0f, 131.0f};
static const f32 warning_window_size[2] = {548.0f, 220.0f};

TAdWarningBaseGC::TAdWarningBaseGC(TObject *parent) : TObject(parent) {
    m_name = TAdWarningBaseGC_class_name;
    frames = 0;
    state = 0;
    next_state = 0;
    message_window = NULL;
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
}

TAdWarningBaseGC::~TAdWarningBaseGC() {
    if (message_window != NULL) {
        message_window->queue_destruction();
        message_window = NULL;
    }
}

void TAdWarningBaseGC::update_state() {
    ControllerInputContext *a;
    ControllerInputContext *b;
    prev_state = state;
    switch (state) {
    case 0:
        message_window = (TWindowBase *)create_message_window();
        state = 1;
        break;
    case 1:
        play_sound_effect(0x53F06, 0, 0, 0);
        state = 2;
        break;
    case 2:
        if (test_pressed_buttons_packed(a = &controller_physical_port_bank.controllers[0], 4) != 0 ||
            test_controller_flag_4c_color(b = &controller_input_state.keyboard, 4) != 0 ||
            test_pressed_buttons_packed(a, 2) != 0 ||
            test_controller_flag_4c_color(b, 2) != 0) {
            state = 3;
            next_state = 4;
        }
        break;
    case 3:
        if (message_window != NULL) {
            message_window->close();
            message_window = NULL;
        }
        if ((f32)++frames > 4.5f) {
            state = next_state;
        }
        break;
    case 4:
        on_close();
        break;
    }
    if (prev_state != state) {
        frames = 0;
    }
}

saddr TAdWarningBaseGC::create_message_window() {
    saddr r = (saddr)create_message_window_for_size((NJS_POINT2 *)warning_window_position, (NJS_POINT2 *)warning_window_size);
    ((TWindowMessage *)r)->append_line(get_message_text(), 3);
    return r;
}

void TAdWarningBaseGC::render_dialog() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void clear_aram_request_busy(uaddr request) { aram_request_busy_flag = 0; }

void TAdWarningBaseGC::init_heap() {
    TAdWarningBaseGC::aram_capacity = 0x80000;
    ad_warning_aram_base = ARAlloc(0x80000);
    TAdWarningBaseGC::aram_alloc_size = 0;
    warning_aram_load_done_flag = 0;
    lobby_count_value = 0;
}

void reset_aram_state(void) {
    TAdWarningBaseGC::aram_capacity = 0;
    ad_warning_aram_base = 0;
    TAdWarningBaseGC::aram_alloc_size = 0;
    warning_aram_load_done_flag = 0;
    lobby_count_value = 0;
}

void TAdWarningBaseGC::create() { new TGbaAramUploadTask(tl_00); }

TGbaAramUploadTask::TGbaAramUploadTask(TObject *parent) : TObject(parent) { state = 0; }

TGbaAramUploadTask::~TGbaAramUploadTask() {}

s32 TAdWarningBaseGC::post_aram_request(void *buf, int size) {
    u32 aligned = (size + 0x1F) & ~0x1F;
    TAdWarningBaseGC::aram_alloc_size = size;
    if (aligned > TAdWarningBaseGC::aram_capacity) {
        return 0;
    }
    DCFlushRange(buf, aligned);
    aram_request_busy_flag = 1;
    ARQPostRequest(&ad_warning_arq_request, 4, 0, 1, reinterpret_cast<uaddr>(buf), ad_warning_aram_base, aligned, clear_aram_request_busy);
    return 1;
}

int get_aligned_aram_alloc_size(void) { return (TAdWarningBaseGC::aram_alloc_size + 0x1F) & ~0x1F; }

int TAdWarningBaseGC::get_alloc_size() { return TAdWarningBaseGC::aram_alloc_size; }

s32 TAdWarningBaseGC::load_from_aram_sync(void *buf) {
    u32 size;
    if (warning_aram_load_done_flag == 0) {
        return 0;
    }
    size = (TAdWarningBaseGC::aram_alloc_size + 0x1F) & ~0x1F;
    DCInvalidateRange(buf, size);
    aram_request_busy_flag = 1;
    ARQPostRequest(&ad_warning_arq_request, 4, 1, 1, ad_warning_aram_base, reinterpret_cast<uaddr>(buf), size, clear_aram_request_busy);
    for (;;) {
        if (aram_request_busy_flag == 0) {
            break;
        }
        run_frame();
    }
    DCInvalidateRange(buf, size);
    return 1;
}

void TGbaAramUploadTask::run_task() {
    static void (TGbaAramUploadTask::*tbl[4])() = {
        &TGbaAramUploadTask::enter_request_state,
        &TGbaAramUploadTask::request_aram_load_state,
        &TGbaAramUploadTask::wait_aram_request,
        &TGbaAramUploadTask::destroy,
    };
    (this->*tbl[state])();
}

void TGbaAramUploadTask::enter_request_state() { state = 1; }

void TGbaAramUploadTask::request_aram_load_state() {
    QuestDownloadRecord *file = get_quest_download_file_header();
    if (file != NULL) {
        s32 size = file->size;
        if (size > 0) {
            u8 *data = file->data;
            if (data != NULL && TAdWarningBaseGC::post_aram_request(data, size) != 0) {
                state = 2;
                return;
            }
        }
    }
    state = 3;
}

void TGbaAramUploadTask::wait_aram_request() {
    if (aram_request_busy_flag == 0) {
        state = 3;
        warning_aram_load_done_flag = 1;
    }
}

void TGbaAramUploadTask::destroy() { queue_destruction(); }

void reset_warning_aram_cache(void) { TAdWarningBaseGC::aram_alloc_size = 0; warning_aram_load_done_flag = 0; }

