#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 TObjPlayer__sub_801C19C8(f32);
s32 TObjPlayer::init_sub_object(saddr lobby) {
    TObjPlayer::init_sub_object_vectors(lobby);
    return lobby;
}
void TObjPlayer::init_sub_object_vectors(saddr lobby) {
    TObjPlayer__sub_801C19C8(0.0f);
    ((TLobby *)lobby)->set_float_4(0.0f);
    ((TLobby *)lobby)->set_pos_z(1.0f);
    ((TLobby *)lobby)->set_scale(1.0f);
}

}
