#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 memmove(void *dst, const void *src, u32 n);
void TLobby::move_data(const void * _w1, u32 _w2) {
    memmove(this, (const void *)(_w1), _w2);
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
