#include "pso/packet_classes.h"
#include "pso/player/TPlySmth.h"

struct ByteBlock_8 { u8 bytes[0x8]; };

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {
int __ct__16TPlyGuildCardTagFv(void*);
int fn_80077AA4(void*);

void __as__8TPlySmthFRC8TPlySmth(s32 arg0, s32 arg1) {
    *(ByteBlock_8 *)(arg0) = *(const ByteBlock_8 *)(arg1);
}

void*TPlySmth::construct() { __ct__16TPlyGuildCardTagFv((void*)((char*)this + 0x4)); __ct__8TPlySmthFv((void*)((char*)this + 0xc)); fn_80077AA4((char*)this + 0xec); return this; }

void __ct__8TPlySmthFv(void*) {

}

}

#pragma push
#pragma auto_inline off
#pragma dont_inline on
TCreateGame::TCreateGame() {}
#pragma pop
