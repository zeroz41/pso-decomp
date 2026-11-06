#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

void TLobby::update_all_children() { TObjPlayer::reset_particle_ctrl((s32 *)this); ((TLobby *)((char*)this + 0x8))->update_child_player(); ((TLobby *)((char*)this + 0x18))->update_child_player(); ((TLobby *)((char*)this + 0x28))->update_child_player(); ((TLobby *)((char*)this + 0x38))->update_child_player(); ((TLobby *)((char*)this + 0x48))->update_child_player(); }
