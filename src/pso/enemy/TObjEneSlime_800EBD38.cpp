#include "types.h"
#include "pso/enemy/TObjEneSlime_800EBBC8.h"
#include "pso/enemy/TObjEneSlime.h"

extern "C" {

void *load_resource_from_descriptor(void *, s32, s32 *, s32, s32, s32);
s32 TObjControl__ct(s32, s32);
s32 __nw__7TObjectFUl(s32);

extern s32 slime_pair_resource_descriptor[];
extern void *slime_bml_resource;
extern f32 lbl_805DA66C;
extern f32 lbl_805DA6B4;

void TObjEneSlime::spawn_pair() {
    void *temp_r4;
    void *temp_r5;
    void *temp_r5_2;

    temp_r4 = ::operator new(0x440);
    if (temp_r4 != NULL) {
        temp_r4 = load_resource_from_descriptor(temp_r4, 1, slime_pair_resource_descriptor, 0, 0, 0);
    }
    slime_bml_resource = temp_r4;
    temp_r5 = *(void **)((s8 *)temp_r4 + 0x42C);
    TObjEneSlime::spawn_child(0x28, *(s32 *)((s8 *)temp_r5 + 0x48), *(s32 *)((s8 *)temp_r5 + 0x4C), lbl_805DA66C, lbl_805DA6B4);
    temp_r5_2 = *(void **)((s8 *)slime_bml_resource + 0x42C);
    TObjEneSlime::spawn_child(0x29, *(s32 *)((s8 *)temp_r5_2 + 0x58), *(s32 *)((s8 *)temp_r5_2 + 0x5C), lbl_805DA66C, lbl_805DA6B4);
}

extern s32 tl_04;

s32 TObjEneSlime::create(s32 arg0) {
    s32 ene_slime;
    s32 var_r4;

    ene_slime = __nw__7TObjectFUl(0x3D8);
    if (ene_slime != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        ene_slime = (s32)TObjEneSlime__ct((TObjEneSlime *)((u8 *)ene_slime), var_r4, (u8 *)arg0);
    }
    return ene_slime;
}

}
