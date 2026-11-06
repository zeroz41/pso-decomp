#include "types.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"

void TCheckRoomSequence::set_ready_flag() { *(u16*)((char*)this + 0x70) |= 0x1; }
