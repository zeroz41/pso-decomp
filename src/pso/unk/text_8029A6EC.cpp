#include "types.h"
#include "pso/TAdBackGC.h"
#include "pso/TObjCMHairMenu.h"

struct Fan_8029A6EC { f32 *pos; u32 *col; s32 first; s32 count; };


void TAdBackGC::sub_8029A6EC() {
    f32 pos[8];
    Fan_8029A6EC fan;
    u32 col[4];

    fan.pos = pos;
    fan.col = col;
    fan.first = 0;
    fan.count = 4;
    fan.pos[0] = 0.0f;
    fan.pos[1] = 0.0f;
    fan.col[0] = 0xFF;
    fan.pos[2] = 0.0f;
    fan.pos[3] = 479.0f;
    fan.col[1] = 0xFF;
    fan.pos[4] = 639.0f;
    fan.pos[5] = 479.0f;
    fan.col[2] = 0xFF;
    fan.pos[6] = 639.0f;
    fan.pos[7] = 0.0f;
    fan.col[3] = 0xFF;
    ((TObjCMHairMenu *)&fan)->draw_tri_fan_2d(4, 3, *(f32 *)((u8 *)this + 0x1C) - 0.01f);
}
