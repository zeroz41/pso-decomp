#include "types.h"
#include "pso/unk/text_80174C14.h"
#include "pso/misc/TORockCaveS01.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80174C14_lbl_804B3BA8 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_80174C14___vt__13TORockCaveS01 {
    s32 value;
    u8 remaining[0x3C];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__10TORockCaveFv();
extern RecoveredGlobal_80174C14_lbl_804B3BA8 cave_rock_collision_body_templates;
extern RecoveredGlobal_80174C14___vt__13TORockCaveS01 __vt__13TORockCaveS01;
extern s32 lbl_805D3104;
extern s32 cave_rock_resource_bundle;
extern const f32 lbl_805DB970;
typedef char RecoveredGlobal_80174C14_lbl_804B3BA8_size[sizeof(RecoveredGlobal_80174C14_lbl_804B3BA8) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_80174C14___vt__13TORockCaveS01_size[sizeof(RecoveredGlobal_80174C14___vt__13TORockCaveS01) == 0x40 ? 1 : -1];
u8 *TORockCaveS01__ct(u8 *arg0, s32 arg1) {
    __ct__10TORockCaveFv();
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TORockCaveS01.value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3104;
    ((TORockCaveS01 *)(arg0))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *)cave_rock_resource_bundle, 2);
    ((TORockCaveS01 *)arg0)->texlist = TObjFish__sub_8001EDB0((void *)cave_rock_resource_bundle, 2);
    ((TORockCaveS01 *)arg0)->m_b0 = (f32) lbl_805DB970;
    init_collision_body_parts(arg0, &cave_rock_collision_body_templates.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

}
