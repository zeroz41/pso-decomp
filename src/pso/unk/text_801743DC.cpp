#include "types.h"
#include "pso/unk/text_801743DC.h"
#include "pso/misc/TORockCaveSS02.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801743DC_lbl_804B3BA8 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_801743DC___vt__14TORockCaveSS02 {
    s32 value;
    u8 remaining[0x3C];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 init_collision_body_parts(void *, void *, int);
s32 TORockCaveSimple__ct();
extern RecoveredGlobal_801743DC_lbl_804B3BA8 cave_rock_collision_body_templates;
extern RecoveredGlobal_801743DC___vt__14TORockCaveSS02 __vt__14TORockCaveSS02;
extern s32 lbl_805D310C;
extern s32 cave_rock_resource_bundle;
extern const f32 lbl_805DB970;
typedef char RecoveredGlobal_801743DC_lbl_804B3BA8_size[sizeof(RecoveredGlobal_801743DC_lbl_804B3BA8) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_801743DC___vt__14TORockCaveSS02_size[sizeof(RecoveredGlobal_801743DC___vt__14TORockCaveSS02) == 0x40 ? 1 : -1];
u8 *TORockCaveSS02__ct(u8 *arg0, s32 arg1) {
    TORockCaveSimple__ct();
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__14TORockCaveSS02.value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D310C;
    ((TORockCaveSS02 *)(arg0))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *)cave_rock_resource_bundle, 5);
    ((TORockCaveSS02 *)arg0)->texlist = TObjFish__sub_8001EDB0((void *)cave_rock_resource_bundle, 5);
    ((TORockCaveSS02 *)arg0)->m_b0 = (f32) lbl_805DB970;
    init_collision_body_parts(arg0, &cave_rock_collision_body_templates.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

}
