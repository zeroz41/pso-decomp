#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TObjDFYutai.h"
#include "pso/player/TObjPlayer.h"

typedef struct Vec_800502FC {
    f32 x, y, z;
} Vec_800502FC;

struct Range_800502FC {
    f32 min;
    f32 max;
    f32 lerp(f32 t) const { return t * (max - min) + min; }
};

typedef struct Data_800502FC {
    u8 pad0[0x20];
    Range_800502FC r20;
    Range_800502FC r28;
    Range_800502FC r30;
} Data_800502FC;

typedef struct Obj_800502FC {
    u8 pad0[0x20];
    u16 id;
    u8 pad22[2];
    f32 t;
} Obj_800502FC;

extern "C" {
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A34;
void *get_player_by_client_id(s32 i);
void scale_matrix(s32, f32, f32, f32);
void rotate_matrix_y(s32, s32);
void push_matrix();
void post_translate_matrix(void *);

void *lbl_804858A8[3] = {
    (void *)0x0, (void *)0x0, (void *)0xc2a20000,
};
void *dark_falz_jisin_zero_vec[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *TObjDFJisin__particle_emitter_id_table[2] = {
    (void *)0xe0, (void *)0xf4,
};
__declspec(section ".data") void *lbl_804858C8[2] = {
    (void *)0x41200000, (void *)0x0,
};
__declspec(section ".data") void *lbl_804858D0[2] = {
    (void *)0x40000000, (void *)0x3f800000,
};
__declspec(section ".data") void *lbl_804858D8[2] = {
    (void *)0x0, (void *)0x3f400000,
};
#define lbl_804858C8 (*(Range_800502FC *)lbl_804858C8)
#define lbl_804858D0 (*(Range_800502FC *)lbl_804858D0)
#define lbl_804858D8 (*(Range_800502FC *)lbl_804858D8)
#pragma fp_contract on
#pragma dont_inline off
#pragma inline_depth(1)
void TObjDFYutai::render() {
    Obj_800502FC *arg0 = (Obj_800502FC *)this;
    Vec_800502FC v;
    u8 *p;
    f32 s;
    f32 w;
    p = (u8 *)get_player_by_client_id(arg0->id);
    if (p == NULL || TBoss4Type3__sub_8005254C(arg0->id) == 0) {
        return;
    }
    s = lbl_804858D0.lerp(arg0->t);
    w = lbl_804858D8.lerp(arg0->t);
    VecCopy((Vec *)&v, (const Vec *)(p + 0x38));
    v.y += lbl_804858C8.min + arg0->t * (lbl_804858C8.max - lbl_804858C8.min);
    push_matrix();
    post_translate_matrix(&v);
    rotate_matrix_y(0, *(s32 *)(p + 0x60));
    scale_matrix(0, s, s, s);
    TObjPlayer::draw_player_model_by_id(arg0->id, w);
    pop_matrix();
}

#pragma push
#pragma opt_common_subs off
void TObjDFYutai::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    if (TBoss4Type3__sub_8005254C((*(u16 *)((s8 *)arg0 + 0x20))) == 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) (*(f32 *)((s8 *)arg0 + 0x24) + *(f32 *)((s8 *)arg0 + 0x28));
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x24);
    if (temp_f1 <= lbl_805D8A30) {
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D8A30;
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if (temp_f1 >= lbl_805D8A34) {
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D8A34;
        queue_destruction__7TObjectFv((arg0));
    }
}
#pragma pop

}
