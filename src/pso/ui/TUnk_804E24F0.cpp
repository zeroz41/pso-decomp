#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/ui/TUnk_804E24F0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_80087278.h"
#include "pso/items/TItemWeapon.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffOrgaFlowShot.h"

typedef struct A_802D6390 { u8 pad0[0x188]; s32 f188; } A_802D6390;

typedef struct B_802D6390 {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x40 - 0x14];
    u32 f40;
    s32 f44;
    u8 pad48[4];
    f32 f4C;
    u8 pad50[0x60 - 0x50];
    u8 v60[0x10];
    void *f70;
} B_802D6390;

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);
extern u8 forward_item_effect_callback__10TObjPlayerFll[];

void TAdPlayerLoadGC__sub_802D6390(A_802D6390 *arg0, B_802D6390 *arg1);

void TAdPlayerLoadGC::play_load_sound() {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, *(f32 *)((s8 *)this + 0x1F8), 0.0f);
    }
}

void TAdPlayerLoadGC__sub_802D6390(A_802D6390 *weapon, B_802D6390 *arg1) {
    u8 sp8[16];
    arg1->f40 |= 0x11C;
    get_weapon_color__11TItemWeaponFPv(sp8, weapon);
    copy_argb((NJS_ARGB *)arg1->v60, (NJS_ARGB *)sp8);
    arg1->f44 = weapon->f188;
    arg1->f10 = 4;
    arg1->f4C = 2.0f;
    arg1->f70 = forward_item_effect_callback__10TObjPlayerFll;
}

void TUnk_804E24F0::emit_marker_effects() {
    s32 sp8;
    s32 arg0 = (s32)this;

    ((TItemWeapon *)arg0)->get_gun_point(&sp8);
    spawn_particle_effect(&sp8, 9);
    ((TItemWeapon *)arg0)->spawn_light_task();
    ((TItemWeapon *)arg0)->fire_shot_at_target(&sp8, 0, 0);
}

}

void TUnk_804E24F0::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.5f, (f32)4.0f);
}

void TUnk_804E24F0::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)(-1.0f), (f32)0.0f);
}

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char lbl_804E24F0[];
    
void*TUnk_804E24F0::init_object(s32 _w1, void *_w2) { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804E24F0; set_weapon_flags(2); *(float *)&this->unk_1F8 = 0.0f; return this; }
u8 *TAdPlayerLoadGC::create_instance() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804E24F0 *)temp_r3)->init_object(tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}

}
