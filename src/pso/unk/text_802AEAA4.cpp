#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"


void TAdSelectCurGC::update_texture_rectangles(s32 frame) {
    s32 i;
    for (i = 0; i < static_cast<s32>(entry_count); i++) {
        switch (confirmation_result()) {
        case 0:
            quads[i].u0 = 0.0625f;
            quads[i].v0 = 0.875f;
            quads[i].u1 = 0.125f;
            quads[i].v1 = 0.9453125f;
            (quads + 16)[i].u0 = 0.0f;
            (quads + 16)[i].v0 = 0.875f;
            (quads + 16)[i].u1 = 0.0625f;
            (quads + 16)[i].v1 = 0.9453125f;
            (quads + 32)[i].u0 = 0.125f;
            (quads + 32)[i].v0 = 0.875f;
            (quads + 32)[i].u1 = 0.1875f;
            (quads + 32)[i].v1 = 0.9453125f;
            break;
        case 1:
            quads[i].u0 = 0.25390625f;
            quads[i].v0 = 0.875f;
            quads[i].u1 = 0.31640625f;
            quads[i].v1 = 0.9453125f;
            (quads + 16)[i].u0 = 0.19140625f;
            (quads + 16)[i].v0 = 0.875f;
            (quads + 16)[i].u1 = 0.25390625f;
            (quads + 16)[i].v1 = 0.9453125f;
            (quads + 32)[i].u0 = 0.31640625f;
            (quads + 32)[i].v0 = 0.875f;
            (quads + 32)[i].u1 = 0.37890625f;
            (quads + 32)[i].v1 = 0.9453125f;
            break;
        }
    }
}
