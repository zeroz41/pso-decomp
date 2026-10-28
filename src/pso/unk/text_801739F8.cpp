#include "types.h"
#include "pso/unk/text_801739F8.h"
#include "pso/misc/TORockCaveBL02.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801739F8_lbl_804B3BA8 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_801739F8___vt__14TORockCaveBL02 {
    s32 value;
    u8 remaining[0x4C];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
void *TORockCaveBrakable__ct(void *arg0);
extern RecoveredGlobal_801739F8_lbl_804B3BA8 cave_rock_collision_body_templates;
extern RecoveredGlobal_801739F8___vt__14TORockCaveBL02 __vt__14TORockCaveBL02;
extern s32 lbl_805D3138;
extern u8 *cave_rock_resource_bundle;
extern const f32 lbl_805DB970;
typedef char RecoveredGlobal_801739F8_lbl_804B3BA8_size[sizeof(RecoveredGlobal_801739F8_lbl_804B3BA8) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_801739F8___vt__14TORockCaveBL02_size[sizeof(RecoveredGlobal_801739F8___vt__14TORockCaveBL02) == 0x50 ? 1 : -1];
u8 *TORockCaveBL02__ct(TORockCaveBL02 *rock_cave_bl02, s32 arg1) {
    s32 temp_r0;
    TORockCaveBrakable__ct(rock_cave_bl02);
    *(s32 **)((s8 *)rock_cave_bl02 + 0x18) = &__vt__14TORockCaveBL02.value;
    *(s32 *)((s8 *)rock_cave_bl02 + 0) = (s32) lbl_805D3138;
    ((TORockCaveBL02 *)(rock_cave_bl02))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)rock_cave_bl02 + 0x34) = get_bml_model(cave_rock_resource_bundle, 0);
    rock_cave_bl02->texture_id = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 0);
    rock_cave_bl02->m_b0 = (f32) lbl_805DB970;
    init_collision_body_parts(rock_cave_bl02, (s32) ((u8 *)&cave_rock_collision_body_templates.value + 0x58), 1);
    ((TUnk_804AF8A0 *)rock_cave_bl02)->refresh_collision_body_centers();
    ((TObjPlayer *)rock_cave_bl02)->reset_photon_effect();
    rock_cave_bl02->m_b8 = (s32) rock_cave_bl02->set_params[0];
    temp_r0 = rock_cave_bl02->m_b8;
    if ((temp_r0 < 0) || (temp_r0 >= 0x100)) {
        rock_cave_bl02->m_b8 = -1;
    }
    return (u8 *)rock_cave_bl02;
}

}
