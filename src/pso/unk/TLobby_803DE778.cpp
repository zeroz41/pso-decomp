#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_803DE778.h"

extern "C" {
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
void TLobby::move_words(u32 *src, s32 n) {
    u32 *dst = (u32 *)this;
    memmove(dst, (const void *)(src), (u32)(n * sizeof(u32)));
}
#pragma pop

}
