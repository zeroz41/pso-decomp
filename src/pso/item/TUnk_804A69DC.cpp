#include "types.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TUnk_804A69C0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TUnk_804A69DC.h"
#include "pso/TItemAttacker.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer_80130520.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemShootModel_dtor.h"
#include "pso/player/TObjPlayer_80130778.h"
#include "pso/item/TUnk_804A6AD8.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 is_owner_alive__15TItemShootModelFv();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *);

void TUnk_804A69C0::render() {
    u8 *arg0 = (u8 *)this;
    if ((is_owner_alive__15TItemShootModelFv() != 0) && ((u32) this->m_58 != 0U) && ((u32) this->m_5C != 0U)) {
        push_matrix();
        set_texlist(*(u32 *)&this->m_5C);
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28);
        draw_ginja_object(this->m_58);
        pop_matrix();
    }
}

void TUnk_804A69C0::hook() {
    this->m_28 = (this->m_28 + 0xCCC);
}

extern s32 __vt__13TUnk_804A69C0[];

void *TUnk_804A69C0::init_shoot_model() {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A69C0;
    this->m_28 = 0;
    return this;
}

}

struct VBase_18_382324
{
  char pad[0x18];
};

struct VObj_18_382324 : VBase_18_382324 {
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

extern "C" {
s32 get_current_floor();
s32 update_technique_slot__10TTecRaFoieFl(int, int, int);
s32 play_sound_effect(int, int, int, int);
s32 init_shoot_model__13TUnk_804A69C0Fv(int, void *, void *, void *, f32);
s32 __nw__7TObjectFUl(int);
s32 create_shoot_model__10TObjPlayerFiiif(s32 arg0, s32 arg1, s32 arg2, f32 farg0);
void TObjPlayer__sub_801307D0(void *arg0);
typedef struct VBase_18_382324 VBase_18_382324;
typedef struct VObj_18_382324 VObj_18_382324;
#define PSO_VCALL_VObj_18_382324_m49(_self, _arg0, _arg1, _arg2, _arg3) (((VObj_18_382324 *)(_self))->m49((_arg0), (_arg1), (_arg2), (_arg3)))

s32 create_shoot_model__10TObjPlayerFiiif(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    s32 temp_r3;
    s32 var_r0;
    s32 var_r3;
    var_r3 = 0;
    if (arg0 != 0) {
        temp_r3 = __nw__7TObjectFUl(0x6C);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = init_shoot_model__13TUnk_804A69C0Fv((int)temp_r3, (void *)arg0, (void *)arg1, (void *)arg2, (f32)farg0);
        }
        var_r3 = var_r0;
    }
    return var_r3;
}

void TUnk_804A69DC::activate_effect(s32) {
    u8 *arg0 = (u8 *)this;
  s32 temp_r31;
  if ((((u32) (*((u32 *) (((s8 *) arg0) + 0xF0)))) != 0U) && (is_current_area_item_enabled() != 0))
  {
    ;
    if ((get_current_floor() == ((TObjPlayer *)(*((u32 *) (((s8 *) arg0) + 0xF0))))->get_floor()) && (((TItem *)arg0)->get_mode() == 2))
    {
      if (!arg0)
      {
      }
      update_technique_slot__10TTecRaFoieFl((int) play_sound_effect(0x4001AA05, (int) ((*((u32 *) (((s8 *) arg0) + 0xF0))) + 0x38), 0, 0), 0x300, 0);
      PSO_VCALL_VObj_18_382324_m49(arg0, arg0 + 0x208, 0, 0, 1);
    }
  }
}
void TUnk_804A69DC::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)arg0)->get_gun_point((arg0 + 0x208));
        if ((s32) this->m_1fc > 0x1999) {
            ((TItem *)arg0)->send_activate_effect(0);
            TItemAttacker::spawn_item_timer((TObject *)arg0, (ItemTimerCallback)TObjPlayer__sub_801307D0, 0x1E);
            this->m_204 = 0;
            return;
        }
        ((TUnk_804A69DC *)arg0)->for_each_target_in_range(324.0f);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}

extern "C" {

int get_player_list__10TObjPlayerFv(void*);

void TUnk_804A69DC::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 3) { rotate_matrix_x(0, this->unk_1F8); } }

void TUnk_804A69DC::reserved_53() {
    s32 *temp_r31;

    if ((u32) *(u32 *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1] != 0U) {
        temp_r31 = *(s32 **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)*(void **)&(*(s16 *)((u8 *)this + 0xF4)) + 0x2C)) + 0x30)) + 0x30);
        if ((s32) this->m_204 == 0) {
            *temp_r31 |= 0x10;
        }
        ((TItemWeapon *)this)->draw_weapon_model();
        ((TItemWeapon *)this)->update_trail_slot(0);
        if ((s32) this->m_204 == 0) {
            *temp_r31 &= 0xFFFFFFEF;
        }
    }
}

void TUnk_804A69DC::update_idle() {
    s32 temp_r4;

    temp_r4 = this->m_1fc;
    if (temp_r4 > 0xCCC) {
        this->m_1fc = (temp_r4 - 0xB6);
    }
}

void TUnk_804A69DC::update_attack() {
    s32 temp_r4;

    *(s32 *)&this->unk_200 = (s32) (*(s32 *)&this->unk_200 + 1);
    if (!(*(s32 *)&this->unk_200 & 3)) {
        temp_r4 = this->m_1fc;
        if (temp_r4 < 0x3333) {
            this->m_1fc = (temp_r4 + 0xB6);
        }
    }
}

void TUnk_804A69DC::update_weapon() {
    advance_angle_wrap(&this->unk_1F8, this->m_1fc);
}

}

extern s32 lbl_804A69DC[];

void *__dt__13TUnk_804A69DCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A69DC;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TUnk_804A69DC::init_state_35() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A69DC;
    set_weapon_flags(35);
    *(s32 **)((s8 *)this + 0x1F0) = (s32 *)create_shoot_model__10TObjPlayerFiiif;
    *(u32 *)((s8 *)this + 0x1F8) = 0;
    *(u32 *)&(this->m_1fc) = 3276;
    *(u32 *)((s8 *)this + 0x200) = 0;
    *(u32 *)&(this->m_204) = 1;
    return this;
}

}

extern "C" {
u8 * init_state_35__13TUnk_804A69DCFv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_state_35_alt(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x214));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_state_35__13TUnk_804A69DCFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

TUnk_804A69C0::~TUnk_804A69C0() {

}


void TObjPlayer__sub_801307D0(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x204) = 1;
    }
}

