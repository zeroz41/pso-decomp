#include "types.h"
#include "pso/item/TUnk_804A09B0.h"
#include "pso/player/TObjPlayer.h"

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
u8 * init_vtable_804A08B8__13TUnk_804A08B8Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;

u8 *TObjPlayer::create_vtable_804A08B8(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_vtable_804A08B8__13TUnk_804A08B8Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_804A09B0::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)arg0)->get_gun_point(&sp8);
        ((VObj_18 *)(arg0))->m49(&sp8, 0, 0, 1);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}
