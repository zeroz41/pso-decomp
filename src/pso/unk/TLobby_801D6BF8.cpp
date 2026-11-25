#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"

void TLobby::update_all_children() { TObjPlayer::reset_particle_ctrl((s32 *)this); ((DamageStatSlot *)((char*)this + 0x8))->reset(); ((DamageStatSlot *)((char*)this + 0x18))->reset(); ((DamageStatSlot *)((char*)this + 0x28))->reset(); ((DamageStatSlot *)((char*)this + 0x38))->reset(); ((DamageStatSlot *)((char*)this + 0x48))->reset(); }
