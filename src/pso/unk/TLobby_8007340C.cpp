#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"

void TLobby::set_loss_flag() { *(u16*)((char*)this + 0x70) |= 0x200; }
