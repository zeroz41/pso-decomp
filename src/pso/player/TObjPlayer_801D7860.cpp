#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 TObjPlayer__sub_801C19C8(f32);
s32 TObjPlayer::init_sub_object(s32 arg0) {
    TObjPlayer::init_sub_object_vectors(arg0);
    return arg0;
}
void TObjPlayer::init_sub_object_vectors(s32 arg0) {
    TObjPlayer__sub_801C19C8(0.0f);
    ((TLobby *)arg0)->set_float_4(0.0f);
    ((TLobby *)arg0)->set_pos_z(1.0f);
    ((TLobby *)arg0)->set_scale(1.0f);
}

}
