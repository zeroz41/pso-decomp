#include "types.h"
#include "pso/ui/city/TCheckRoomSequence_8021E464.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

void *TCheckRoomSequence::create(void *arg2_) {
    return new TCheckRoomSequence(tl_05, (TObjPlayer *)arg2_);
}
}

    extern int TCheckRoomSequence__slot_active_flags[];
int get_check_room_slot_active_flag(int a0) {  return TCheckRoomSequence__slot_active_flags[a0]; }
