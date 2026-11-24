#include "pso/system/memory.h"
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_803DE778.h"


void move_data(void *dst, const void *src, s32 n) {
    memmove(dst, src, n);
}

#pragma push
#pragma scheduling off
#pragma peephole off
void TLobby::copy_u16_array(u16 *src, s32 n) {
    u16 *dst = (u16 *)this;
    memmove(dst, src, n * sizeof(u16));
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void move_words(void *dst, const void *src, s32 count) {
    memmove(dst, src, count * sizeof(u32));
}
#pragma pop
