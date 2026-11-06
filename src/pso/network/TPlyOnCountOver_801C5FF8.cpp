#include "types.h"
#include "pso/network/TPlyOnCountOver_801C5FF8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/network/TPlyOnCountOver.h"

struct RecoveredGlobal_801C606C___vt__15TPlyOnCountOver {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_801C606C___vt__15TPlyOnCountOver __vt__15TPlyOnCountOver;
extern s32 TPlyOnCountOver__name;
extern u8 *tl_06;
void *get_player_by_client_id(s32 i);
typedef char RecoveredGlobal_801C606C___vt__15TPlyOnCountOver_size[sizeof(RecoveredGlobal_801C606C___vt__15TPlyOnCountOver) == 0x18 ? 1 : -1];

void TPlyOnCountOver::run_task() {
    u8 *arg0 = (u8 *)this;
    void (*cb)(u32);
    u32 p;
    p = (u32)get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0x1C));
    if (p == 0U) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (--*(s16 *)((s8 *)arg0 + 0x1E) < 0) {
        cb = *(void (**)(u32))((s8 *)arg0 + 0x20);
        if (cb != NULL) {
            cb(p);
        }
        queue_destruction__7TObjectFv(arg0);
    }
}

u8 *__ct__15TPlyOnCountOverFv(u8 *object, s16 arg1, s16 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject(object, tl_06);
    *(s32 **)((s8 *)object + 0x18) = &__vt__15TPlyOnCountOver.value;
    *(s32 *)((s8 *)object + 0) = (s32) TPlyOnCountOver__name;
    *(s16 *)((s8 *)object + 0x1C) = arg1;
    *(s16 *)((s8 *)object + 0x1E) = arg2;
    *(s32 *)((s8 *)object + 0x20) = arg3;
    return object;
}

}
