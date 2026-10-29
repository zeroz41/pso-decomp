#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/misc/TOWreckAncientBrakable_8017D444.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/misc/TOWreckAncientBrakable.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_8017D448 { f32 x, y, z; };

struct Arr_8017D448 { Vec_8017D448 v[9]; };

struct Param_8017D448 {
    s32 f0;
    s32 f4;
    s32 f8;
    Vec_8017D448 pos;
    u8 pad18[0x20];
    f32 f38;
    s32 f3c;
    s32 f40;
    s32 f44;
    s32 f48;
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
void *__nw__7TObjectFUl(u32);
void vec3_add_to(Vec_8017D448 *, Vec_8017D448 *);
void rotate_vector_by_matrix(int, Vec_8017D448 *, Vec_8017D448 *);
void rotate_matrix_y(int, int);
extern Arr_8017D448 TOWreckAncientBrakable__debris_table;
extern Param_8017D448 TOWreckAncientBrakable__debris_param_table;
extern u8 identity_matrix[];
extern void *wreck_ancient_brakable_bml_resource;
extern s32 tl_05;

void TOWreckAncientBrakable__sub_8017D444(void) {  }
void TOWreckAncientBrakable::spawn_debris() {
    u8 *arg0 = (u8 *)this;
    Vec_8017D448 tmp;
    Arr_8017D448 arr = TOWreckAncientBrakable__debris_table;
    Param_8017D448 p = TOWreckAncientBrakable__debris_param_table;
    s32 i;
    void *obj;
    p.pos.x = *(f32 *)(arg0 + 0x38);
    p.pos.y = *(f32 *)(arg0 + 0x3C);
    p.pos.z = *(f32 *)(arg0 + 0x40);
    p.f38 = p.pos.y;
    for (i = 0; i < 9; i++) {
        VecCopy((Vec *)&tmp, (const Vec *)&arr.v[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
        rotate_vector_by_matrix(0, &tmp, &tmp);
        pop_matrix();
        VecCopy((Vec *)&p.pos, (const Vec *)((Vec_8017D448 *)(arg0 + 0x38)));
        vec3_add_to(&p.pos, &tmp);
        p.f40 = get_bml_model(wreck_ancient_brakable_bml_resource, i);
        p.f44 = TObjFish__sub_8001EDB0(wreck_ancient_brakable_bml_resource, i);
        obj = __nw__7TObjectFUl(0x234);
        if (obj != 0) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)obj, (u8 *)tl_05, (u8 *)&p);
        }
    }
}

}
