#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 TObjPlayer::init_sub_object(saddr lobby) {
    TObjPlayer::init_sub_object_vectors(lobby);
    return lobby;
}
void TObjPlayer::init_sub_object_vectors(saddr lobby) {
    DamageStatSlot *slot = (DamageStatSlot *)lobby;
    slot->set_total(0.0f);
    slot->set_accumulated(0.0f);
    slot->set_normal_weight(1.0f);
    slot->set_bonus_weight(1.0f);
}

}
