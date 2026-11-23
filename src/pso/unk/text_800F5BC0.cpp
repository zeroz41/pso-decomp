#include "types.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/memory.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

void StripBufferPair::scroll_uvs(s16 scroll_u, s16 scroll_v) {
    s32 i;
    s16 *strip;
    s16 *uv;
    u32 n;
    u32 j;
    s32 len;
    s32 k;
    scroll_u %= 256;
    scroll_v %= 256;
    for (i = 0; i < strip_count; i++) {
        strip = strips[i].strip;
        uv = strips[i].uv;
        n = *strip++ & 0x3FFF;
        for (j = 0; j < n; j++) {
            len = *strip++;
            if (len < 0) {
                len = -len;
            }
            for (k = 0; k < len; k++) {
                strip[1] = uv[0] + scroll_u;
                strip[2] = uv[1] + scroll_v;
                uv += 2;
                strip += 3;
            }
        }
    }
}

StripBufferPair::~StripBufferPair() {
    mem_free(uvs);
    uvs = NULL;
    mem_free(strips);
    strips = NULL;
}
