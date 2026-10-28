#include "types.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A0EA8.h"

struct Base_801221A0 { u8 pad0[0x18]; };

struct Pl_801221A0 : Base_801221A0 {
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

struct Self_801221A0 : Pl_801221A0 {
    u8 pad1C[0x1EC - 0x1C];
    void *fn1ec;
    void *fn1f0;
    u8 pad1F4[4];
    u8 a1f8[0xC];
    u8 a204[0xC];
};

extern "C" {
void TUnk_804A0EA8::emit_marker_effects() {
    Self_801221A0 *self = (Self_801221A0 *)this;
    if (((TItemWeapon *)self)->is_mode_two_and_ready() != 0) {
        self->fn1f0 = (void *)create_shoot_model_rot_z;
        self->fn1ec = NULL;
    } else {
        self->fn1f0 = (void *)create_gun_shot;
        self->fn1ec = (void *)spawn_weapon_impact_effect;
    }
    if (self->m49(self->a1f8, 0, 0, 1) != 0) {
        self->m49(self->a204, 0, 0, 0);
    } else {
        self->m49(self->a204, 0, 0, 1);
    }
}

}
