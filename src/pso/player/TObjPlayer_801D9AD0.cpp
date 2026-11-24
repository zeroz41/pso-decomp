#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastGauge.h"

extern "C" {
u8 *TObjPlayer__sub_801D9E18(s32, s32);
void TObjPlayer::set_slot_type_state(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    PhotonBlastTarget *target = (PhotonBlastTarget *)TObjPlayer__sub_801D9E18(arg0, arg1);
    target->set_entity_id(arg2);
    target->set_index(arg3);
}

}
