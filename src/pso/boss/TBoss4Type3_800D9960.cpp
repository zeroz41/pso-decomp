#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/TBoss4Type3_800D9960.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TCameraCtrl_803D6538.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/memory.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_800D9960_lbl_80500FA4 {
    s32 value;
    u8 remaining[0x8];
};

typedef struct Vec_800D9ABC {
    f32 x, y, z;
} Vec_800D9ABC;

typedef struct Trail_800D9ABC {
    Vec_800D9ABC *buf;
    s32 segs;
    s32 len;
    f32 start;
    f32 end;
    f32 step;
} Trail_800D9ABC;

struct Vec_800D9994 { f32 x, y, z; };

struct Arg_800D9994 { s32 a; s32 b; s32 count; f32 start; u8 pad10[4]; f32 step; };

extern "C" {
extern RecoveredGlobal_800D9960_lbl_80500FA4 lbl_80500FA4;
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
f32 get_status_value_f32__23TObjEneMe1CanadinLeaderFv(f32);
void *mem_alloc(u32 size);
extern const f32 lbl_805DA3EC;
extern const f32 lbl_805DA3F0;
Trail_800D9ABC *init_trail_buffer__11TBoss4Type3FPvifff(Trail_800D9ABC *arg0, s32 segs, f32 start, f32 end, f32 step);
void transform_motion_node_points(void *, s32, s32);
void push_matrix(Vec_800D9994 *);
extern Vec_800D9994 lbl_80500F80;
extern s32 lbl_805D5230;
extern s32 lbl_805D5234;
extern s32 motion_trail_node_index;
extern s32 lbl_805D523C;
extern s32 TBoss4Type3__motion_trail_points;
void mem_free(void *p);

typedef char RecoveredGlobal_800D9960_lbl_80500FA4_size[sizeof(RecoveredGlobal_800D9960_lbl_80500FA4) == 0xC ? 1 : -1];
void draw_trail_with_colors(u8 *boss4_type3, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)((s8 *)&lbl_80500FA4.value + 0) = arg3;
    *(s32 *)((s8 *)&lbl_80500FA4.value + 4) = arg4;
    ((TBoss4Type3 *)boss4_type3)->draw_motion_trail(arg1, arg2, (s32)((s32) &lbl_80500FA4.value), 0);
}

void TBoss4Type3::draw_motion_trail(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 f;
    s32 i;
    set_motion_packed_rotation();
    lbl_80500F80.x = lbl_805DA3EC;
    lbl_80500F80.y = lbl_805DA3EC;
    lbl_80500F80.z = lbl_805DA3EC;
    lbl_805D5230 = ((Arg_800D9994 *)this)->a;
    lbl_805D5234 = ((Arg_800D9994 *)this)->b;
    lbl_805D523C = arg3;
    TBoss4Type3__motion_trail_points = arg4;
    push_matrix(&lbl_80500F80);
    f = ((Arg_800D9994 *)this)->start;
    for (i = 0; i < ((Arg_800D9994 *)this)->count; i++) {
        motion_trail_node_index = 0;
        set_matrix_identity(0);
        bind_motion_context(arg2, f);
        transform_motion_node_points(this, arg1, 0);
        f += ((Arg_800D9994 *)this)->step;
    }
    pop_matrix();
    clear_motion_packed_rotation();
}

s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        mem_free((void *)(*arg0));
        *arg0 = 0;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}
Trail_800D9ABC *init_trail_buffer__11TBoss4Type3FPvifff(Trail_800D9ABC *arg0, s32 segs, f32 start, f32 end, f32 step) {
    s32 n;
    s32 i;
    arg0->step = step;
    arg0->segs = segs;
    arg0->start = get_random_float__21TObjEneMe3ShinowaRealFv(start / arg0->step);
    arg0->end = get_status_value_f32__23TObjEneMe1CanadinLeaderFv(end / arg0->step);
    arg0->len = (s32)(lbl_805DA3F0 + (arg0->end - arg0->start));
    arg0->start *= arg0->step;
    arg0->end *= arg0->step;
    n = arg0->len * arg0->segs;
    arg0->buf = (Vec_800D9ABC *)mem_alloc(n * 0xC);
    for (i = 0; i < n; i++) {
        arg0->buf[i].x = lbl_805DA3EC;
        arg0->buf[i].y = lbl_805DA3EC;
        arg0->buf[i].z = lbl_805DA3EC;
    }
    return arg0;
}

}
