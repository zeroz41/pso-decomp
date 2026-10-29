#include "types.h"
#include "pso/item/WeaponAttackActions.h"
#include "pso/item/TUnk_804A4D70.h"
#include "pso/player/TObjPlayer.h"

struct Base_8011F5E0 { char pad[0x18]; };
struct VObj_8011F5E0 : Base_8011F5E0 {
    virtual void v0();
#define VV(n) virtual void v##n();
VV(1)VV(2)VV(3)VV(4)VV(5)VV(6)VV(7)VV(8)VV(9)VV(10)
VV(11)VV(12)VV(13)VV(14)VV(15)VV(16)VV(17)VV(18)VV(19)VV(20)
VV(21)VV(22)VV(23)VV(24)VV(25)VV(26)VV(27)VV(28)VV(29)VV(30)
VV(31)VV(32)VV(33)VV(34)VV(35)VV(36)VV(37)VV(38)VV(39)VV(40)
VV(41)VV(42)VV(43)VV(44)VV(45)VV(46)VV(47)VV(48)VV(49)VV(50)
VV(51)VV(52)VV(53)VV(54)VV(55)VV(56)VV(57)VV(58)VV(59)VV(60)
VV(61)VV(62)VV(63)VV(64)
#undef VV
    virtual void v67(f32);
};

extern "C" {


struct Base_8011F578 { char pad[0x18]; };
struct VObj_8011F578 : Base_8011F578 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(f32);
};

void TUnk_804A4D70::apply_scale_if_active(f32 farg0) {

    if (((TItemWeapon *)this)->is_active_in_game() != 0) {
        ((TItemWeapon *)this)->remap_extra_attack_type();
        ((VObj_8011F578 *)(this->owner))->m65(farg0);
        ((TItemWeapon *)this)->restore_action_type();
    }
}

extern f32 lbl_805DAC9C;

void TObjPlayer::update_active_game_effect() {

    if (((TItemWeapon *)this)->is_active_in_game() != 0) {
        ((TItemWeapon *)this)->remap_extra_attack_type();
        ((VObj_8011F5E0 *)(*(void * *)&this->blend.frame[1]))->v67(lbl_805DAC9C);
        ((TItemWeapon *)this)->restore_action_type();
    }
}

}
