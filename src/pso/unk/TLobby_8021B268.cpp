#include "types.h"
#include "pso/unk/TLobby_8021B268.h"
#include "pso/unk/TLobby.h"

void TLobby::set_position(f32 a, f32 b) { *(f32*)((char*)this + 0xa8) = a; *(f32*)((char*)this + 0xac) = b; }

    extern int lbl_80513D68[];
int TLobby__sub_8021B274(int a0) {  return lbl_80513D68[a0]; }
