#include "types.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/system/vector.h"

struct RecoveredGlobal_802E4A4C_lbl_804E355C { s32 value; u8 remaining[0x18]; };
typedef char RecoveredGlobal_802E4A4C_lbl_804E355C_size[sizeof(RecoveredGlobal_802E4A4C_lbl_804E355C) == 0x1C ? 1 : -1];

extern "C" {
s32 memset(void *, int, int);
s32 get_type__10TObjPlayerFPv(void *);
void *get_player_by_client_id(s32 i);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_802E4A4C_lbl_804E355C __vt__13TUnk_804E355C;
extern const f32 lbl_805DE914;
u8 *construct_attack_collision(u8 *arg0, s32 arg1, u8 *arg2);
u8 *construct_attack_collision(u8 *arg0, s32 arg1, u8 *arg2) {
    u32 player;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_804E355C.value;
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) lbl_805DE914;
    ((TUnk_804E355C *)arg0)->m_38 = (f32) lbl_805DE914;
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805DE914;
    ((TUnk_804E355C *)arg0)->m_40 = (f32) *(f32 *)((s8 *)arg2 + 0xC);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) lbl_805DE914;
    ((TUnk_804E355C *)arg0)->m_48 = 0;
    *(s32 *)((s8 *)arg0 + 0x4C) = 0x41F07;
    ((TUnk_804E355C *)arg0)->m_50 = (f32) lbl_805DE914;
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) lbl_805DE914;
    ((TUnk_804E355C *)arg0)->m_58 = (f32) lbl_805DE914;
    *(f32 *)((s8 *)arg0 + 0x5C) = (f32) lbl_805DE914;
    *(u8 **)((s8 *)arg0 + 0x1C) = (unsigned char *) (arg0 + 0x34);
    ((TUnk_804E355C *)arg0)->m_20 = 1;
    VecCopy((Vec *)(arg0 + 0x24), (const Vec *)(arg2));
    memset(arg0 + 0x60, 0, 0x40);
    ((TUnk_804E355C *)arg0)->m_a0 = 0;
    ((TUnk_804E355C *)arg0)->m_a4 = (s32) *(s32 *)((s8 *)arg2 + 0x10);
    ((TUnk_804E355C *)arg0)->m_a8 = (u16) *(u16 *)((s8 *)arg2 + 0x14);
    *(s16 *)((s8 *)arg0 + 0xAA) = (s16) *(s16 *)((s8 *)arg2 + 0x16);
    ((TUnk_804E355C *)arg0)->m_ac = (s32) *(s32 *)((s8 *)arg2 + 0x18);
    *(f32 *)((s8 *)arg0 + 0xB0) = (f32) *(f32 *)((s8 *)arg2 + 0x1C);
    ((TUnk_804E355C *)arg0)->m_b4 = (f32) *(f32 *)((s8 *)arg2 + 0x20);
    *(s32 *)((s8 *)arg0 + 0xB8) = (s32) *(s32 *)((s8 *)arg2 + 0x24);
    *(s32 *)((s8 *)arg0 + 0xC0) = 1;
    player = (u32)get_player_by_client_id(((s32) *(u16 *)((s8 *)arg2 + 0x14)));
    if (player != 0U) {
        if (get_type__10TObjPlayerFPv((void *)(player + 0x828)) != 0) {
            ((TUnk_804E355C *)arg0)->m_bc = 1;
        } else {
            ((TUnk_804E355C *)arg0)->m_bc = 0;
        }
    } else {
        ((TUnk_804E355C *)arg0)->m_bc = 0;
    }
    return arg0;
}

}
