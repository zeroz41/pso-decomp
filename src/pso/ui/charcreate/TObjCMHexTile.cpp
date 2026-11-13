#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TObjCMHexTile.h"
#include "pso/ui/UISprite.h"
#include "pso/unk/text_802948A8.h"
#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

#pragma readonly_strings on

extern "C" {
const char *TObjCMHexTile__name = "TObjCMHexTile";
}


void TObjCMHexTile::render() {
    vec2f size;
    vec2f position;
    f32 sc = 0.2f * alpha;
    size.x = size.y = 0.5f * scale;
    position.x = pos.x + offset.x;
    position.y = pos.y + offset.y;
    draw_ui_sprite_scaled(3, &position, &size, -1.49f, sc);
}

void TObjCMHexTile::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    switch (state) {
    case 0:
        temp_f1 = (f32) frame / (f32) state_end_frame[0];
        alpha = temp_f1;
        temp_f1_2 = 1.0f - temp_f1;
        offset.x = (f32) (temp_f1_2 * m_2c.x);
        offset.y = (f32) (temp_f1_2 * m_2c.y);
        break;
    case 1:
        alpha = 1.0f;
        scale = 1.0f;
        offset.y = 0.0f;
        offset.x = 0.0f;
        break;
    case 2:
        scale = (f32) (scale + m_44);
        temp_r5 = state_end_frame[2];
        temp_f2 = (f32) (temp_r5 - frame) / (f32) (temp_r5 - state_end_frame[1]);
        alpha = (f32) (temp_f2 * temp_f2);
        temp_f1_3 = -(1.0f - temp_f2);
        offset.x = (f32) (temp_f1_3 * m_2c.x);
        offset.y = (f32) (temp_f1_3 * m_2c.y);
        break;
    }
    temp_r6 = frame + 1;
    frame = temp_r6;
    temp_r5_2 = state;
    if (temp_r6 >= state_end_frame[temp_r5_2]) {
        state = (s32)(temp_r5_2 + 1);
        if ((s32) state == 3) {
            queue_destruction();
        }
    }
}

TObjCMHexTile::~TObjCMHexTile() {}

#pragma push
#pragma fp_contract on
extern "C" {

void __ct__7TObjectFP7TObject(void *, void *);
int rand(void);
extern void *__vt__13TObjCMHexTile[];
extern const char *TObjCMHexTile__name;

#pragma push
#pragma opt_lifetimes off
TObjCMHexTile *__ct__13TObjCMHexTileFv(TObjCMHexTile *self, TObject *parent, void *pos) {
    s32 v;

    __ct__7TObjectFP7TObject(self, parent);
    *(void ***)((u8 *)self + 0x18) = __vt__13TObjCMHexTile;
    self->m_name = TObjCMHexTile__name;
    self->state_end_frame[0] = v = 22.0f * (0.000030517578f * (f32)rand()) + 7.0f;
    self->state_end_frame[1] = v = (f32)v + (7.0f * (0.000030517578f * (f32)rand()) + 22.0f);
    v = (f32)v + (45.0f * (0.000030517578f * (f32)rand()) + 30.0f);
    self->state_end_frame[2] = v;
    self->m_44 = 0.033333335f * (0.000030517578f * (f32)rand()) + 0.008333334f;
    self->m_2c.x = 20.0f * (0.000030517578f * (f32)rand()) - 10.0f;
    self->m_2c.y = 20.0f * (0.000030517578f * (f32)rand()) - 10.0f;
    ((TWindowSubSymbolChatPartsSet *)&self->pos)->copy_vec2(pos);
    self->alpha = 0.0f;
    self->scale = 1.0f;
    self->frame = 0;
    self->state = 0;
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
