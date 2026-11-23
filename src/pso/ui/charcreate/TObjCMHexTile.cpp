#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TObjCMHexTile.h"
#include "pso/ui/UISprite.h"
#include "pso/unk/text_802948A8.h"
#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/NinjaTypes.h"
#include <stdlib.h>
#include "pso/system/vector.h"

#pragma readonly_strings on


const char *cm_hex_tile_name = "TObjCMHexTile";


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
    f32 t;
    f32 inv_t;
    f32 neg_inv_t;
    f32 fade_t;
    s32 end_frame;
    s32 cur_state;
    s32 next_frame;
    switch (state) {
    case 0:
        t = (f32) frame / (f32) state_end_frame[0];
        alpha = t;
        inv_t = 1.0f - t;
        offset.x = (f32) (inv_t * drift_offset.x);
        offset.y = (f32) (inv_t * drift_offset.y);
        break;
    case 1:
        alpha = 1.0f;
        scale = 1.0f;
        offset.y = 0.0f;
        offset.x = 0.0f;
        break;
    case 2:
        scale = (f32) (scale + scale_rate);
        end_frame = state_end_frame[2];
        fade_t = (f32) (end_frame - frame) / (f32) (end_frame - state_end_frame[1]);
        alpha = (f32) (fade_t * fade_t);
        neg_inv_t = -(1.0f - fade_t);
        offset.x = (f32) (neg_inv_t * drift_offset.x);
        offset.y = (f32) (neg_inv_t * drift_offset.y);
        break;
    }
    next_frame = frame + 1;
    frame = next_frame;
    cur_state = state;
    if (next_frame >= state_end_frame[cur_state]) {
        state = (cur_state + 1);
        if ((s32) state == 3) {
            queue_destruction();
        }
    }
}

TObjCMHexTile::~TObjCMHexTile() {}

#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_lifetimes off
TObjCMHexTile::TObjCMHexTile(TObject *parent, void *pos) : TObject(parent) {
    s32 v;
    this->m_name = cm_hex_tile_name;
    this->state_end_frame[0] = v = 22.0f * (0.000030517578f * (f32)rand()) + 7.0f;
    this->state_end_frame[1] = v = (f32)v + (7.0f * (0.000030517578f * (f32)rand()) + 22.0f);
    v = (f32)v + (45.0f * (0.000030517578f * (f32)rand()) + 30.0f);
    this->state_end_frame[2] = v;
    this->scale_rate = 0.033333335f * (0.000030517578f * (f32)rand()) + 0.008333334f;
    this->drift_offset.x = 20.0f * (0.000030517578f * (f32)rand()) - 10.0f;
    this->drift_offset.y = 20.0f * (0.000030517578f * (f32)rand()) - 10.0f;
    copy_vec2(&this->pos, pos);
    this->alpha = 0.0f;
    this->scale = 1.0f;
    this->frame = 0;
    this->state = 0;
}
extern "C" {
#pragma pop

#pragma pop


void fn_802947A8(void) {
    f32 limY;
    f32 stepY;
    f32 limX;
    f32 stepX;
    f32 evenX;
    f32 oddX;
    NJS_POINT2 p;
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
