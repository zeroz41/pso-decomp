#include "types.h"
#include "pso/item/TUnk_804A2A58.h"

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
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
extern "C" {
s32 is_model_shown__5TItemFv(void *, int);
void TUnk_804A2A58::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    s32 temp_r4;
    temp_r4 = this->m_1fc;
    this->m_1fc = (temp_r4 + 0x2AAA);
    if (is_model_shown__5TItemFv(arg0, temp_r4) != 0) {
        ((TItemWeapon *)arg0)->get_joint_position(2, &sp8);
        ((VObj_18 *)(arg0))->m49(&sp8, 0, 0x4FA, 1);
        ((TItemWeapon *)arg0)->get_joint_position(3, &sp8);
        ((VObj_18 *)(arg0))->m49(&sp8, 1, 0xE38, 1);
        ((TItemWeapon *)arg0)->get_joint_position(4, &sp8);
        ((VObj_18 *)(arg0))->m49(&sp8, 2, -0x4FA, 1);
        ((TItemWeapon *)arg0)->get_joint_position(5, &sp8);
        ((VObj_18 *)(arg0))->m49(&sp8, 3, -0xE38, 1);
    }
}

}
