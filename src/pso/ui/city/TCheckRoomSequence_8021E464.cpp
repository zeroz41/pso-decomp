#include "types.h"
#include "pso/ui/city/TCheckRoomSequence_8021E464.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"


void *TCheckRoomSequence::create(void *player) {
    return new TCheckRoomSequence(tl_05, (TObjPlayer *)player);
}

int get_check_room_slot_active_flag(int a0) {  return TCheckRoomSequence::slot_active_flags[a0]; }
