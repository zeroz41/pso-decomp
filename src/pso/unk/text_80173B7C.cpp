#include "types.h"
#include "pso/unk/text_80173B7C.h"
#include "pso/misc/TORockCaveBL01.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80173B7C_lbl_804B3BA8 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_80173B7C___vt__14TORockCaveBL01 {
    s32 value;
    u8 remaining[0x4C];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
void *__ct__18TORockCaveBrakableFv(void *arg0);
extern RecoveredGlobal_80173B7C_lbl_804B3BA8 cave_rock_collision_body_templates;
extern RecoveredGlobal_80173B7C___vt__14TORockCaveBL01 __vt__14TORockCaveBL01;
extern s32 lbl_805D3134;
extern u8 *cave_rock_resource_bundle;
extern const f32 lbl_805DB970;
typedef char RecoveredGlobal_80173B7C_lbl_804B3BA8_size[sizeof(RecoveredGlobal_80173B7C_lbl_804B3BA8) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_80173B7C___vt__14TORockCaveBL01_size[sizeof(RecoveredGlobal_80173B7C___vt__14TORockCaveBL01) == 0x50 ? 1 : -1];
u8 *TORockCaveBL01__ct(TORockCaveBL01 *rock_cave_bl01, s32 arg1) {
    s32 temp_r0;
    __ct__18TORockCaveBrakableFv(rock_cave_bl01);
    *(s32 **)((s8 *)rock_cave_bl01 + 0x18) = &__vt__14TORockCaveBL01.value;
    *(s32 *)((s8 *)rock_cave_bl01 + 0) = (s32) lbl_805D3134;
    ((TORockCaveBL01 *)(rock_cave_bl01))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)rock_cave_bl01 + 0x34) = get_bml_model(cave_rock_resource_bundle, 0);
    rock_cave_bl01->texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    rock_cave_bl01->m_b0 = (f32) lbl_805DB970;
    init_collision_body_parts(rock_cave_bl01, (s32) ((u8 *)&cave_rock_collision_body_templates.value + 0x58), 1);
    ((TObjCollidable *)rock_cave_bl01)->refresh_collision_body_centers();
    ((TObjPlayer *)rock_cave_bl01)->register_object_by_id();
    rock_cave_bl01->m_b8 = (s32) rock_cave_bl01->set_params[0];
    temp_r0 = rock_cave_bl01->m_b8;
    if ((temp_r0 < 0) || (temp_r0 >= 0x100)) {
        rock_cave_bl01->m_b8 = -1;
    }
    return (u8 *)rock_cave_bl01;
}

}
