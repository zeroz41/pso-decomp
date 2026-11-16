#include "types.h"
#include "pso/unk/TUnk_804C3248.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/key/TOKeyMachine01.h"

    extern const float lbl_805DC0C0;
void TObjPlayer::reset_state_block() { *(int*)((char*)this + 0x0) = 0; *(int*)((char*)this + 0x4) = -1; *(int*)((char*)this + 0x8) = 0; *(int*)((char*)this + 0xc) = 0; *(short*)((char*)this + 0x10) = 0; *(short*)((char*)this + 0x12) = 0; *(short*)((char*)this + 0x14) = 0; *(short*)((char*)this + 0x16) = 0; *(short*)((char*)this + 0x18) = 0; *(short*)((char*)this + 0x1a) = 0; *(int*)((char*)this + 0x1c) = 0; *(int *)&this->m_20 = 0; *(float *)&this->texlist = lbl_805DC0C0; *(float *)&this->room = lbl_805DC0C0; }
