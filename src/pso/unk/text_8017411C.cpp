#include "types.h"
#include "pso/unk/text_8017411C.h"
#include "pso/misc/TORockCaveSL02.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8017411C_lbl_804B3BA8 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_8017411C___vt__14TORockCaveSL02 {
    s32 value;
    u8 remaining[0x3C];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
void *TORockCaveSimple__ct(void *arg0);
extern RecoveredGlobal_8017411C_lbl_804B3BA8 cave_rock_collision_body_templates;
extern RecoveredGlobal_8017411C___vt__14TORockCaveSL02 __vt__14TORockCaveSL02;
extern s32 lbl_805D312C;
extern u8 *cave_rock_resource_bundle;
extern const f32 lbl_805DB970;
typedef char RecoveredGlobal_8017411C_lbl_804B3BA8_size[sizeof(RecoveredGlobal_8017411C_lbl_804B3BA8) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_8017411C___vt__14TORockCaveSL02_size[sizeof(RecoveredGlobal_8017411C___vt__14TORockCaveSL02) == 0x40 ? 1 : -1];
u8 *TORockCaveSL02__ct(u8 *rock_cave_simple, s32 arg1) {
    TORockCaveSimple__ct(rock_cave_simple);
    *(s32 **)((s8 *)rock_cave_simple + 0x18) = &__vt__14TORockCaveSL02.value;
    *(s32 *)((s8 *)rock_cave_simple + 0) = (s32) lbl_805D312C;
    ((TORockCaveSL02 *)(rock_cave_simple))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)rock_cave_simple + 0x34) = get_bml_model(cave_rock_resource_bundle, 3);
    ((TORockCaveSL02 *)rock_cave_simple)->texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 3);
    ((TORockCaveSL02 *)rock_cave_simple)->m_b0 = (f32) lbl_805DB970;
    init_collision_body_parts(rock_cave_simple, (s32) ((u8 *)&cave_rock_collision_body_templates.value + 0x58), 1);
    ((TObjCollidable *)rock_cave_simple)->refresh_collision_body_centers();
    ((TObjPlayer *)rock_cave_simple)->register_object_by_id();
    return rock_cave_simple;
}

}
