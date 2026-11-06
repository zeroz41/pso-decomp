#ifndef PSO_UI_FRONTEND_TADTIMESETGC_H
#define PSO_UI_FRONTEND_TADTIMESETGC_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TAdTimeSetGC : public TObject {
public:
    virtual ~TAdTimeSetGC();
    void sub_802E1F14();
    void change_state(s32);
    s32 poll_load_status();
    virtual void run_task();
    s32 state_index;
    u8 unk_20[0x4];
    s32 m_24;
    u8 unk_28[0x4];
    s32 m_2c;
    u8 unk_30[0x4];
    s32 m_34;
    u8 unk_38[0x4];
    s32 m_3c;
    u8 unk_40[0x4];
    s32 load_status;
    u8 unk_48[0x4];
    s32 m_4c;
    TObject *owned_object;
    void *window;
    TObject *queued_object;
    u32 unknown_5c;
    s32 timer;

};

typedef void (TAdTimeSetGC::*TAdTimeSetGCStateAction)();
struct TAdTimeSetGCStateActions {
    TAdTimeSetGCStateAction first;
    TAdTimeSetGCStateAction task;
};

typedef char TAdTimeSetGC_owned_object_offset[offsetof(TAdTimeSetGC, owned_object) == 0x50 ? 1 : -1];
typedef char TAdTimeSetGC_window_offset[offsetof(TAdTimeSetGC, window) == 0x54 ? 1 : -1];
typedef char TAdTimeSetGC_queued_object_offset[offsetof(TAdTimeSetGC, queued_object) == 0x58 ? 1 : -1];
typedef char TAdTimeSetGC_state_index_offset[offsetof(TAdTimeSetGC, state_index) == 0x1c ? 1 : -1];
typedef char TAdTimeSetGC_load_status_offset[offsetof(TAdTimeSetGC, load_status) == 0x44 ? 1 : -1];
typedef char TAdTimeSetGC_timer_offset[offsetof(TAdTimeSetGC, timer) == 0x60 ? 1 : -1];
typedef char TAdTimeSetGCActionSize[sizeof(TAdTimeSetGCStateAction) == 12 ? 1 : -1];
typedef char TAdTimeSetGCEntrySize[sizeof(TAdTimeSetGCStateActions) == 24 ? 1 : -1];
typedef char TAdTimeSetGCStateTaskOffset[offsetof(TAdTimeSetGCStateActions, task) == 12 ? 1 : -1];

extern "C" {
void *TAdTimeSetGC__ct(void *arg0);
void TAdTimeSetGC__sub_802E34A4(void);
void TAdTimeSetGC__sub_802E34A8(void);
}

// --- C functions defined in TAdTimeSetGC.cpp ---
extern "C" {
void *TAdTimeSetGC__ct(void *ad_time_set_gc);
}
// --- end of C functions

#endif
