#include "types.h"
#include "pso/item/SpecialProjectileWeapons.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A66D8.h"

struct VBase_8012FB08 { char pad[0x18]; };

struct VObj_8012FB08 : VBase_8012FB08 {
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

struct Self_8012FB08 : VObj_8012FB08 {
    u8 pad1C[0xF0 - 0x1C];
    u8 *owner;
    u8 padF4[0x1EC - 0xF4];
    void *f1EC;
    void *f1F0;
    u8 pad1F4[4];
    u8 f1F8[0xC];
    u8 f204[0xC];
};

extern "C" {
u8 * initialize_effect_object__10TObjPlayerFv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void launch_rare_weapon_special__10TObjPlayerFPvlf(void *, void *, s32, f32);
extern const f32 lbl_805DAFC8;

u8 *TObjPlayer::create_effect_object(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x260));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(initialize_effect_object__10TObjPlayerFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_804A66D8::emit_marker_effects() {
    u8 *p;
    s32 i;
    if (((TObjPlayer *)this)->is_mode_two_and_ready() != 0) {
        p = ((Self_8012FB08 *)this)->owner + 0x7CC;
        for (i = 0; i != 2; i++) {
            increment_burst_counter(p);
        }
        ((Self_8012FB08 *)this)->f1F0 = (void *)create_shoot_model_rot_z;
        ((Self_8012FB08 *)this)->f1EC = (void *)spawn_weapon_impact_effect;
        launch_rare_weapon_special__10TObjPlayerFPvlf(((Self_8012FB08 *)this), ((Self_8012FB08 *)this)->f1F8, 1, lbl_805DAFC8);
        launch_rare_weapon_special__10TObjPlayerFPvlf(((Self_8012FB08 *)this), ((Self_8012FB08 *)this)->f204, 0, lbl_805DAFC8);
    } else {
        ((Self_8012FB08 *)this)->f1F0 = (void *)create_gun_shot;
        ((Self_8012FB08 *)this)->f1EC = (void *)spawn_weapon_impact_effect;
        if (((Self_8012FB08 *)this)->m49(((Self_8012FB08 *)this)->f1F8, 0, 0, 1) != 0) {
            ((Self_8012FB08 *)this)->m49(((Self_8012FB08 *)this)->f204, 0, 0, 0);
        } else {
            ((Self_8012FB08 *)this)->m49(((Self_8012FB08 *)this)->f204, 0, 0, 1);
        }
    }
}

void TUnk_804A66D8::reserved_53() {
    u8 *arg0 = (u8 *)this;
    ((TObjPlayer *)arg0)->draw_status_icons(arg0 + 0x1F8, arg0 + 0x204);
}

}
