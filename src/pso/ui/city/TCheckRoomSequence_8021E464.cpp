#include "types.h"
#include "pso/ui/city/TCheckRoomSequence_8021E464.h"
#include "pso/ui/city/TCheckRoomSequence.h"

extern "C" {

void *TCheckRoomSequence__ct(void *arg0, s32 arg1, s32 arg2_);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TCheckRoomSequence::create(void *arg2_) {
    void *o = __nw__7TObjectFUl(0x4C);
    if (o != NULL) {
        o = TCheckRoomSequence__ct(o, (s32)tl_05, (s32)arg2_);
    }
    return o;
}
}

    extern int TCheckRoomSequence__slot_active_flags[];
int get_check_room_slot_active_flag(int a0) {  return TCheckRoomSequence__slot_active_flags[a0]; }
