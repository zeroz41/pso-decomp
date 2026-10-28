#include "types.h"
#include "pso/unk/text_80173E60.h"
#include "pso/misc/TORockCaveM03.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80173E60_lbl_804B3BA8 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_80173E60___vt__13TORockCaveM03 {
    s32 value;
    u8 remaining[0x3C];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
void *__ct__10TORockCaveFv(void *arg0);
extern RecoveredGlobal_80173E60_lbl_804B3BA8 cave_rock_collision_body_templates;
extern RecoveredGlobal_80173E60___vt__13TORockCaveM03 __vt__13TORockCaveM03;
extern s32 lbl_805D3120;
extern u8 *cave_rock_resource_bundle;
extern const f32 lbl_805DB970;
typedef char RecoveredGlobal_80173E60_lbl_804B3BA8_size[sizeof(RecoveredGlobal_80173E60_lbl_804B3BA8) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_80173E60___vt__13TORockCaveM03_size[sizeof(RecoveredGlobal_80173E60___vt__13TORockCaveM03) == 0x40 ? 1 : -1];
u8 *TORockCaveM03__ct(u8 *rock_cave, s32 arg1) {
    __ct__10TORockCaveFv(rock_cave);
    *(s32 **)((s8 *)rock_cave + 0x18) = &__vt__13TORockCaveM03.value;
    *(s32 *)((s8 *)rock_cave + 0) = (s32) lbl_805D3120;
    ((TORockCaveM03 *)(rock_cave))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)rock_cave + 0x34) = get_bml_model(cave_rock_resource_bundle, 1);
    ((TORockCaveM03 *)rock_cave)->texlist = TObjFish__sub_8001EDB0(cave_rock_resource_bundle, 1);
    ((TORockCaveM03 *)rock_cave)->m_b0 = (f32) lbl_805DB970;
    init_collision_body_parts(rock_cave, (s32) ((u8 *)&cave_rock_collision_body_templates.value + 0x2C), 1);
    ((TObjCollidable *)rock_cave)->refresh_collision_body_centers();
    ((TObjPlayer *)rock_cave)->register_object_by_id();
    return rock_cave;
}

}
