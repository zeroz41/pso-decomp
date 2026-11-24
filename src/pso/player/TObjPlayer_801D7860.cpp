#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 TObjPlayer::init_sub_object(saddr lobby) {
    TObjPlayer::init_sub_object_vectors(lobby);
    return lobby;
}
void TObjPlayer::init_sub_object_vectors(saddr lobby) {
    ((DamageStatSlot *)lobby)->set_total(0.0f);
    ((DamageStatSlot *)lobby)->set_accumulated(0.0f);
    ((DamageStatSlot *)lobby)->set_normal_weight(1.0f);
    ((DamageStatSlot *)lobby)->set_bonus_weight(1.0f);
}

}
