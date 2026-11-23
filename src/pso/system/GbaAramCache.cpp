#include "types.h"
#include <dolphin/ar.h>
#include <dolphin/os/OSCache.h>
#include "pso/system/GbaAramCache.h"
#include "pso/system/TGbaAramUploadTask.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby.h"

ARQRequest ad_warning_arq_request;

u32 ad_warning_aram_base;
u32 TAdWarningBaseGC__aram_capacity;
s32 warning_aram_load_done_flag;
int TAdWarningBaseGC__aram_alloc_size;
int lobby_count_value;
s32 aram_request_busy_flag;

void TLobby__sub_8032CDEC(void) { TAdWarningBaseGC__aram_alloc_size = 0; warning_aram_load_done_flag = 0; }

void TGbaAramUploadTask::destroy() { queue_destruction(); }

void TGbaAramUploadTask::wait_aram_request() {
    if (aram_request_busy_flag == 0) {
        state = 3;
        warning_aram_load_done_flag = 1;
    }
}

void TGbaAramUploadTask::request_aram_load_state() {
    QuestDownloadRecord *file = get_quest_download_file_header();
    if (file != NULL) {
        s32 size = file->size;
        if (size > 0) {
            u8 *data = file->data;
            if (data != NULL && TAdWarningBaseGC::post_aram_request((int)data, size) != 0) {
                state = 2;
                return;
            }
        }
    }
    state = 3;
}

void TGbaAramUploadTask::enter_request_state() { state = 1; }

void TGbaAramUploadTask::run_task() {
    static void (TGbaAramUploadTask::*tbl[4])() = {
        &TGbaAramUploadTask::enter_request_state,
        &TGbaAramUploadTask::request_aram_load_state,
        &TGbaAramUploadTask::wait_aram_request,
        &TGbaAramUploadTask::destroy,
    };
    (this->*tbl[state])();
}

s32 TAdWarningBaseGC::load_from_aram_sync(int buf) {
    u32 size;
    if (warning_aram_load_done_flag == 0) {
        return 0;
    }
    size = (TAdWarningBaseGC__aram_alloc_size + 0x1F) & ~0x1F;
    DCInvalidateRange((void *)buf, size);
    aram_request_busy_flag = 1;
    ARQPostRequest(&ad_warning_arq_request, 4, 1, 1, ad_warning_aram_base, buf, size, clear_aram_request_busy);
    for (;;) {
        if (aram_request_busy_flag == 0) {
            break;
        }
        TLobby::run_frame();
    }
    DCInvalidateRange((void *)buf, size);
    return 1;
}

int TAdWarningBaseGC::get_alloc_size() { return TAdWarningBaseGC__aram_alloc_size; }

int TAdWarningBaseGC__sub_8032D020(void) { return (TAdWarningBaseGC__aram_alloc_size + 0x1F) & ~0x1F; }

s32 TAdWarningBaseGC::post_aram_request(int buf, int size) {
    u32 aligned = (size + 0x1F) & ~0x1F;
    TAdWarningBaseGC__aram_alloc_size = size;
    if (aligned > TAdWarningBaseGC__aram_capacity) {
        return 0;
    }
    DCFlushRange((void *)buf, aligned);
    aram_request_busy_flag = 1;
    ARQPostRequest(&ad_warning_arq_request, 4, 0, 1, buf, ad_warning_aram_base, aligned, clear_aram_request_busy);
    return 1;
}

TGbaAramUploadTask::~TGbaAramUploadTask() {}

TGbaAramUploadTask::TGbaAramUploadTask(TObject *parent) : TObject(parent) { state = 0; }

void TAdWarningBaseGC::create() { new TGbaAramUploadTask(tl_00); }

void TAdWarningBaseGC__sub_8032D188(void) {
    TAdWarningBaseGC__aram_capacity = 0;
    ad_warning_aram_base = 0;
    TAdWarningBaseGC__aram_alloc_size = 0;
    warning_aram_load_done_flag = 0;
    lobby_count_value = 0;
}

void TAdWarningBaseGC::init_heap() {
    TAdWarningBaseGC__aram_capacity = 0x80000;
    ad_warning_aram_base = ARAlloc(0x80000);
    TAdWarningBaseGC__aram_alloc_size = 0;
    warning_aram_load_done_flag = 0;
    lobby_count_value = 0;
}
