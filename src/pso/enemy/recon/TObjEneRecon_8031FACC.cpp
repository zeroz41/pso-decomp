#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/map/CsnQuery.h"
#include "pso/enemy/recon/TObjEneRecon_8031FACC.h"
#include "pso/system/vector.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/ui/window/TWindowSubComCard.h"

struct Stack_8031FB6C {
    s32 sp8;
    f32 spC;
};

struct Obj_8031FACC { u8 pad[0x3F4]; s32 f3F4; s32 f3F8; u8 pad2[0x410 - 0x3FC]; s32 f410; s32 f414; };

extern "C" {
extern const f32 lbl_805DF450;
extern const f32 lbl_805DF460;
s32 has_child_in_anim_5__12TObjEneReconFv();
extern const f32 lbl_805DF45C;
u8 TObjEneRecon__sub_8031FACC(Obj_8031FACC *arg0);

u8 TObjEneRecon__sub_8031FACC(Obj_8031FACC *arg0) {
    s32 r;
    s32 t;
    if (has_child_in_anim_5__12TObjEneReconFv() == 1) {
        return 0;
    }
    t = (s32)TWindowSubComCard::trunc_float((f32)arg0->f3F8 * lbl_805DF45C);
    r = 0;
    if (arg0->f410 <= t && arg0->f414 < arg0->f3F4) {
        r = 1;
    }
    return (u8)r;
}

void TObjEneRecon__sub_8031FB6C(u8 *ene_recobox) {
    Stack_8031FB6C stack;
    u8 *temp_r3;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(ene_recobox + 0x2FC));
    if ((s32) ((TObjEneRecobox *)ene_recobox)->m_3f8 == 1) {
        stack.spC -= lbl_805DF450;
    } else {
        stack.spC += lbl_805DF450;
    }
    temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (u32 *)(ene_recobox + 0x120), 0x15));
    if ((temp_r3 == NULL) || (((TObjEneRecobox *)ene_recobox)->m_300 >= (lbl_805DF460 + *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4)))) {
        ((TObjEneRecobox *)(ene_recobox))->vfunc_97();
    }
    ((TObjEneDD *)ene_recobox)->set_part_local_pos(ene_recobox + 0x2FC, 0);
}

}
