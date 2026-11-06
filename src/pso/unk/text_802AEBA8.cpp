#include "types.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
struct Obj_802AEBA8 { u8 pad[0xa4]; s32 a4; s32 a8; s32 ac; u8 pad2[0x6bc - 0xb0]; s32 arr[16]; s32 f6fc; s32 f700; };

typedef struct { f32 x, y; } V2_802AEBE4;
typedef struct { f32 x, y, x2, y2; f32 pad[4]; } Quad_802AEBE4;

typedef struct {
    u8 pad0[0x1C];
    V2_802AEBE4 pts[16];
    f32 w;
    f32 h;
    u32 pad_a4;
    u32 count;
    u8 padAC[0xBC - 0xAC];
    Quad_802AEBE4 q0[16];
    Quad_802AEBE4 q1[16];
    Quad_802AEBE4 q2[16];
} Obj_802AEBE4;


void TAdEnterSerialAccessGC::reset_input_state() {
    Obj_802AEBA8 *self = (Obj_802AEBA8 *)this;
    s32 i;
    self->a4 = 0;
    self->a8 = 0;
    self->ac = 0;
    self->f6fc = -1;
    self->f700 = 0;
    for (i = 0; i < 16; i++) self->arr[i] = 0;
}

void TLevelSelect::add_item_rect(void *src) {
    Obj_802AEBE4 *self = (Obj_802AEBE4 *)this;
    if (self->count < 16) {
        ((TWindowSubSymbolChatPartsSet *)(&self->pts[self->count]))->copy_vec2(src);
        self->q0[self->count].x = 16.0f + self->pts[self->count].x;
        self->q0[self->count].y = self->pts[self->count].y;
        self->q0[self->count].x2 = self->q0[self->count].x + (self->w - 32.0f);
        self->q0[self->count].y2 = self->q0[self->count].y + self->h;
        self->q1[self->count].x = self->pts[self->count].x;
        self->q1[self->count].y = self->pts[self->count].y;
        self->q1[self->count].x2 = 16.0f + self->q1[self->count].x;
        self->q1[self->count].y2 = self->q1[self->count].y + self->h;
        self->q2[self->count].x = self->pts[self->count].x + (self->w - 16.0f);
        self->q2[self->count].y = self->pts[self->count].y;
        self->q2[self->count].x2 = 16.0f + self->q2[self->count].x;
        self->q2[self->count].y2 = self->q2[self->count].y + self->h;
        self->count++;
    }
}
