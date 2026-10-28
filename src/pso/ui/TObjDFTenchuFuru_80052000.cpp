#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/object/TObjDFUsoTower.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

typedef struct Vec_80052090 {
    f32 x, y, z;
} Vec_80052090;

typedef struct Obj_80052090 {
    u8 pad0[0x38];
    Vec_80052090 pos;
    u8 pad44[0x90 - 0x44];
    s32 state;
    f32 f94;
} Obj_80052090;

extern "C" {
f32 vector_length(Vec_80052090 *);
void subtract_vector(Vec_80052090 *, Vec_80052090 *);
extern u8 *camera_ctrl_instance;
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A34;
extern const f32 lbl_805D8A5C;
extern const f32 lbl_805D8AC4;
extern const f32 lbl_805D8AC8;
extern const f32 lbl_805D8ACC;
extern const f32 lbl_805D8AD0;
extern const f32 lbl_805D8AD4;
s32 post_translate_matrix(void *);
s32 TObjPlayer__sub_80052390();
s32 push_matrix();

void TObjDFUsoTower::render() {
    f32 temp_f1;

    temp_f1 = *(f32 *)&this->unk_94;
    if (lbl_805D8A30 != temp_f1) {
        if (temp_f1 < lbl_805D8A34) {
            TObjPlayer__sub_80052390();
            set_color_blend_mode(1, 4, 5, 0);
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
        if (*(f32 *)&this->unk_94 < lbl_805D8A34) {
            TObjPlayer::sync_player_globals();
        }
    }
}
#pragma opt_common_subs off
void TObjDFUsoTower::run_task() {
    Obj_80052090 *arg0 = (Obj_80052090 *)this;
    f32 d;
    f32 r;
    switch (this->m_90) {
    case 0: {
        Vec_80052090 v = *(Vec_80052090 *)(camera_ctrl_instance + 0x178);
        subtract_vector(&v, &arg0->pos);
        v.y = lbl_805D8A30;
        d = vector_length(&v);
        if (d <= lbl_805D8AC4) {
            r = lbl_805D8A30;
        } else if (d >= lbl_805D8AC8) {
            r = lbl_805D8A34;
        } else {
            r = (d - lbl_805D8AC4) / lbl_805D8A5C;
        }
        arg0->f94 = lbl_805D8ACC * r;
        break;
    }
    case 1:
        r = arg0->f94 + lbl_805D8AD0;
        arg0->f94 = r;
        if (r > lbl_805D8A34) {
            arg0->f94 = lbl_805D8A34;
        }
        break;
    case 2:
        r = arg0->f94 + lbl_805D8AD4;
        arg0->f94 = r;
        if (r < lbl_805D8A30) {
            arg0->f94 = lbl_805D8A30;
        }
        break;
    }
}

}
