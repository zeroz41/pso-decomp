#include "types.h"
#include "pso/render/GinjaTextureHeader.h"

#pragma push
#pragma scheduling off
#pragma peephole off
void swap_u32_bytes(u32 *word) {
    u32 v = *word;
    *word = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}
#pragma pop
