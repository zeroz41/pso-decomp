#include "types.h"
#include "pso/player/TObjPlayer_80121D88.h"
#include "pso/player/TObjPlayer_80122014.h"
#include "pso/unk/text_80121E94.h"
#include "pso/item/TUnk_804A0CB8.h"
#include "pso/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"
struct Vec_80121CB8 { f32 x, y, z; };

struct Base_80121CB8 { u8 pad0[0x18]; };

struct Pl_80121CB8 : Base_80121CB8 {
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
    virtual s32 m49(void *, s32, s32, s32);
};

struct Self_80121CB8 : Pl_80121CB8 {
    u8 pad1C[0x1F0 - 0x1C];
    void *fn1f0;
    u8 pad1F4[4];
    s32 f1f8;
};

extern const f32 lbl_805DACD0;
void TUnk_804A0CB8::emit_marker_effects() {
    Self_80121CB8 *self = (Self_80121CB8 *)this;
    Vec_80121CB8 v;
    if (((TItemWeapon *)self)->is_mode_two_and_ready() != 0) {
        self->fn1f0 = (void *)belra_cannon_create_extra_shot;
        self->f1f8 = 0;
        TItemAttacker::spawn_item_timer((s32)self, (s32)((void *)belra_cannon_return_timer), 0x1E);
        ((TObjPlayer *)self)->launch_rare_weapon_special(0, 1, lbl_805DACD0);
    } else {
        self->fn1f0 = (void *)belra_cannon_create_shot;
        self->f1f8 = 0;
        TItemAttacker::spawn_item_timer((s32)self, (s32)((void *)belra_cannon_return_timer), 0x1E);
        ((TItemWeapon *)self)->get_joint_position(1, &v);
        self->m49(&v, 0, 0, 1);
    }
}
