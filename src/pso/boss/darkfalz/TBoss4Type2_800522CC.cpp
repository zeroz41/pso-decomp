#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include <stdlib.h>

// Its own TU: the u32-to-float bias double and the 1/32768 scale are pooled again here, after
// TObjDFJisin's copies of both.
s32 TBoss4Type2::pick_weighted_random(s32 n, f32 *w, s32 *t) {
    s32 i;
    f32 acc;
    f32 r;
    r = 3.0517578e-05f * (f32)rand();
    acc = w[0];
    for (i = 0; i < n - 1; i++) {
        if (r < acc) {
            return t[i];
        }
        acc += w[i];
    }
    return t[n - 1];
}

__declspec(section ".sdata2") extern const f32 lbl_805D8ADC = 0.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D8AE0 = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D8AE4 = 0.5f;
__declspec(section ".sdata2") extern const u32 lbl_805D8AE8 = 0x00008829;
__declspec(section ".sdata2") extern const f32 lbl_805D8AEC = -1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D8AF0 = 32768.0f;
