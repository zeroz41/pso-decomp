#include "types.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct RecoveredGlobal_800BC4C8_lbl_804928A0 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_800BC4C8_lbl_804928CC {
    s32 value;
    u8 remaining[0x58];
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_800BC4C8_lbl_804928A0 construct_collision_body_parts;
extern RecoveredGlobal_800BC4C8_lbl_804928CC collision_body_vtable;
typedef char RecoveredGlobal_800BC4C8_lbl_804928A0_size[sizeof(RecoveredGlobal_800BC4C8_lbl_804928A0) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_800BC4C8_lbl_804928CC_size[sizeof(RecoveredGlobal_800BC4C8_lbl_804928CC) == 0x5C ? 1 : -1];
u8 *construct_collision_body(u8 *arg0, s32 arg1, u32 arg2) {
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &collision_body_vtable.value;
    init_collision_body_parts(arg0, &construct_collision_body_parts.value, 1);
    if (arg2 != 0U) {
        ((TUnk_804928CC *)arg0)->sub_800BC3E8((u8 *)arg2);
    } else {
        ((TUnk_804928CC *)arg0)->m_ac = 0;
    }
    return arg0;
}

}
