#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/charcreate/TObjCMHexTile.h"
#include "pso/unk/text_802948A8.h"
#include "types.h"

class TObjCMHexTile : public TObject {
public:
    virtual ~TObjCMHexTile();
    virtual void run_task();
    virtual void render();
};
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

#pragma readonly_strings on

extern "C" {
const char *TObjCMHexTile__name = "TObjCMHexTile";
}


struct H_80294324 { u8 pad0[0x34]; f32 f34; f32 f38; f32 f3c; f32 f40; u8 pad44[4]; f32 f48; f32 f4c; };

extern "C" {
void draw_ui_sprite_scaled(int, void *, void *, f32, f32);
void render__13TObjCMHexTileFv(H_80294324 *arg0);

void render__13TObjCMHexTileFv(H_80294324 *arg0) {
    f32 sp10[2];
    f32 sp8[2];
    f32 sc = 0.2f * arg0->f4c;
    sp10[0] = sp10[1] = 0.5f * arg0->f48;
    sp8[0] = arg0->f3c + arg0->f34;
    sp8[1] = arg0->f40 + arg0->f38;
    draw_ui_sprite_scaled(3, sp8, sp10, -1.49f, sc);
}

void run_task__13TObjCMHexTileFv(u8 *object) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    switch (*(s32 *)((s8 *)object + 0x1C)) {
    case 0:
        temp_f1 = (f32) *(s32 *)((s8 *)object + 0x50) / (f32) *(s32 *)((s8 *)object + 0x20);
        *(f32 *)((s8 *)object + 0x4C) = temp_f1;
        temp_f1_2 = 1.0f - temp_f1;
        *(f32 *)((s8 *)object + 0x34) = (f32) (temp_f1_2 * *(f32 *)((s8 *)object + 0x2C));
        *(f32 *)((s8 *)object + 0x38) = (f32) (temp_f1_2 * *(f32 *)((s8 *)object + 0x30));
        break;
    case 1:
        *(f32 *)((s8 *)object + 0x4C) = 1.0f;
        *(f32 *)((s8 *)object + 0x48) = 1.0f;
        *(f32 *)((s8 *)object + 0x38) = 0.0f;
        *(f32 *)((s8 *)object + 0x34) = 0.0f;
        break;
    case 2:
        *(f32 *)((s8 *)object + 0x48) = (f32) (*(f32 *)((s8 *)object + 0x48) + *(f32 *)((s8 *)object + 0x44));
        temp_r5 = *(s32 *)((s8 *)object + 0x28);
        temp_f2 = (f32) (temp_r5 - *(s32 *)((s8 *)object + 0x50)) / (f32) (temp_r5 - *(s32 *)((s8 *)object + 0x24));
        *(f32 *)((s8 *)object + 0x4C) = (f32) (temp_f2 * temp_f2);
        temp_f1_3 = -(1.0f - temp_f2);
        *(f32 *)((s8 *)object + 0x34) = (f32) (temp_f1_3 * *(f32 *)((s8 *)object + 0x2C));
        *(f32 *)((s8 *)object + 0x38) = (f32) (temp_f1_3 * *(f32 *)((s8 *)object + 0x30));
        break;
    }
    temp_r6 = *(s32 *)((s8 *)object + 0x50) + 1;
    *(s32 *)((s8 *)object + 0x50) = temp_r6;
    temp_r5_2 = *(s32 *)((s8 *)object + 0x1C);
    if (temp_r6 >= ((s32 *)(object + 0x20))[temp_r5_2]) {
        *(s32 *)((s8 *)object + 0x1C) = (s32)(temp_r5_2 + 1);
        if ((s32) *(s32 *)((s8 *)object + 0x1C) == 3) {
            queue_destruction__7TObjectFv(object);
        }
    }
}

}

TObjCMHexTile::~TObjCMHexTile() {}

#pragma push
#pragma fp_contract on
extern "C" {

struct Hex_80294578 {
    const char *name;
    u8 pad4[0x18 - 0x4];
    void *vt;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x3C - 0x34];
    f32 pos[2];
    f32 f44;
    f32 f48;
    f32 f4C;
    s32 f50;
};

void __ct__7TObjectFP7TObject(void *, void *);
int rand(void);
extern void *__vt__13TObjCMHexTile[];
extern const char *TObjCMHexTile__name;

#pragma push
#pragma opt_lifetimes off
Hex_80294578 *__ct__13TObjCMHexTileFv(Hex_80294578 *self, void *parent, void *pos) {
    s32 v;

    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__13TObjCMHexTile;
    self->name = TObjCMHexTile__name;
    self->f20 = v = 22.0f * (0.000030517578f * (f32)rand()) + 7.0f;
    self->f24 = v = (f32)v + (7.0f * (0.000030517578f * (f32)rand()) + 22.0f);
    v = (f32)v + (45.0f * (0.000030517578f * (f32)rand()) + 30.0f);
    self->f28 = v;
    self->f44 = 0.033333335f * (0.000030517578f * (f32)rand()) + 0.008333334f;
    self->f2C = 20.0f * (0.000030517578f * (f32)rand()) - 10.0f;
    self->f30 = 20.0f * (0.000030517578f * (f32)rand()) - 10.0f;
    ((TWindowSubSymbolChatPartsSet *)(self->pos))->copy_vec2(pos);
    self->f4C = 0.0f;
    self->f48 = 1.0f;
    self->f50 = 0;
    self->f1C = 0;
    return self;
}
#pragma pop

#pragma pop

struct V2_802947A8 {
    f32 x;
    f32 y;
};


void fn_802947A8(void) {
    f32 limY;
    f32 stepY;
    f32 limX;
    f32 stepX;
    f32 evenX;
    f32 oddX;
    V2_802947A8 p;
    s32 odd = 0;

    p.y = -11.5f;
    stepX = 40.0f;
    limX = 680.0f;
    stepY = 11.5f;
    limY = 571.5f;
    oddX = -20.0f;
    evenX = -40.0f;
    for (; p.y < limY; p.y += stepY) {
        if (odd != 0) {
            p.x = oddX;
        } else {
            p.x = evenX;
        }
        for (; p.x < limX; p.x += stepX) {
            create_TObjCMHexTile(&p);
        }
        odd ^= 1;
    }
}

}
