#include "types.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/player/TUnk_804A4648.h"
#include "pso/player/TObjPlayer.h"

struct VBase_18_8622c5 { char pad[0x18]; };

struct VObj_18_8622c5 : VBase_18_8622c5 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual s32 m49(s32 *, s32, s32, s32);
};

struct RecoveredGlobal_80129DD4_lbl_8043E968 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
extern RecoveredGlobal_80129DD4_lbl_8043E968 lbl_8043E968;
typedef char RecoveredGlobal_80129DD4_lbl_8043E968_size[sizeof(RecoveredGlobal_80129DD4_lbl_8043E968) == 0x18 ? 1 : -1];
void TUnk_804A4648::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    TObjPlayer__sub_80128A70();
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 0, *(s32 *)((s8 *)&lbl_8043E968.value + 0), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 1, *(s32 *)((s8 *)&lbl_8043E968.value + 4), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 2, *(s32 *)((s8 *)&lbl_8043E968.value + 8), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 3, *(s32 *)((s8 *)&lbl_8043E968.value + 0xC), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 4, *(s32 *)((s8 *)&lbl_8043E968.value + 0x10), 1);
}

}
