#include "types.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/system/memory.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

struct StripRef_800F5BC0 { s16 *strip; s16 *uv; };

struct Provider_800F5BC0 { s32 unk0; s32 count; StripRef_800F5BC0 *refs; };

extern "C" {
void scroll_strip_uvs(Provider_800F5BC0 *arg0, s16 arg1, s16 arg2);

void scroll_strip_uvs(Provider_800F5BC0 *arg0, s16 scroll_u, s16 scroll_v) {
    s32 i;
    s16 *strip;
    s16 *uv;
    u32 n;
    u32 j;
    s32 len;
    s32 k;
    scroll_u %= 256;
    scroll_v %= 256;
    for (i = 0; i < arg0->count; i++) {
        strip = arg0->refs[i].strip;
        uv = arg0->refs[i].uv;
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
}

void *destroy_buffer_pair(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        mem_free((void *)(*(saddr *)((s8 *)arg0 + 0xC)));
        *(s32 *)((s8 *)arg0 + 0xC) = 0;
        mem_free((void *)(*(saddr *)((s8 *)arg0 + 8)));
        *(s32 *)((s8 *)arg0 + 8) = 0;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}
