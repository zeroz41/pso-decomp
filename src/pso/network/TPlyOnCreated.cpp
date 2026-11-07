#include "types.h"
#include "pso/network/TPlyOnCreated.h"

struct RecoveredGlobal_801C6178___vt__13TPlyOnCreated {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_801C6178___vt__13TPlyOnCreated __vt__13TPlyOnCreated;
extern s32 TPlyOnCreated__name;
extern u8 *tl_06;
u8 *__ct__13TPlyOnCreatedFv(u8 *arg0, s16 arg1, s32 arg2);
void *get_player_by_client_id(s32 i);
void queue_destruction__7TObjectFv(void *arg0);

void TPlyOnCreated::run_task() {
    s32 (*temp_r12)();

    if (get_player_by_client_id(*(u16 *)((s8 *)this + 0x1C)) != 0U) {
        temp_r12 = *(s32 (**)())((s8 *)this + 0x20);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        queue_destruction__7TObjectFv(this);
    }
}
typedef char RecoveredGlobal_801C6178___vt__13TPlyOnCreated_size[sizeof(RecoveredGlobal_801C6178___vt__13TPlyOnCreated) == 0x18 ? 1 : -1];
u8 *__ct__13TPlyOnCreatedFv(u8 *object, s16 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(object, tl_06);
    *(s32 **)((s8 *)object + 0x18) = &__vt__13TPlyOnCreated.value;
    *(s32 *)((s8 *)object + 0) = (s32) TPlyOnCreated__name;
    *(s16 *)((s8 *)object + 0x1C) = arg1;
    *(s32 *)((s8 *)object + 0x20) = arg2;
    return object;
}

extern char TPlyOnCreated__class_name_string[];
s32 TPlyOnCreated__name = (s32)TPlyOnCreated__class_name_string;
}
