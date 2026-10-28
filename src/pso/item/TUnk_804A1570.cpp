#include "types.h"
#include "pso/item/TUnk_804A1570.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80122F3C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItem.h"

struct Obj_80122E60 { u8 pad[0x1f8]; f32 a; f32 b; f32 c; };

void TUnk_804A1570::update_idle() {
    Obj_80122E60 *self = (Obj_80122E60 *)this;
    if (1e-05f < self->c) {
        self->c -= 0.3f;
        if (self->c < 1e-05f) {
            self->c = 1e-05f;
        }
        self->a = self->b = self->c;
    }
}

void TUnk_804A1570::update_attack() {
    f32 temp_f0;
    f32 temp_f2;

    temp_f2 = *(f32 *)&this->unk_200;
    if (temp_f2 < 1.0f) {
        *(f32 *)&this->unk_200 += 0.3f;
        if (1.0f < *(f32 *)&this->unk_200) {
            *(f32 *)&this->unk_200 = (f32) 1.0f;
        }
        temp_f0 = *(f32 *)&this->unk_200;
        *(f32 *)&this->m_1fc = temp_f0;
        *(f32 *)&this->unk_1F8 = temp_f0;
    }
}

extern "C" {
void update_trail_slot__11TItemWeaponFPvi(void *, s32);
void TUnk_804A1570::reserved_53() {
  s32 temp_r31;
  s32 new_var;
  temp_r31 = *((s32 *) (((s8 *) ((u8 *)this)) + 0xF4));
  new_var = (s32) this;
  draw_weapon_at_joint(new_var, 0x2F);
  update_trail_slot__11TItemWeaponFPvi(this, 0);
  update_trail_slot__11TItemWeaponFPvi(this, 1);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0xF4)) = (s32)this->second_model;
  draw_weapon_at_joint(new_var, 0x22);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0xF4)) = temp_r31;
}
}

extern s32 lbl_804A1570[];

void *__dt__13TUnk_804A1570Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A1570;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int TItemWeapon__ct(void);
int set_status_flags__10TObjPlayerFUl(void*, void*);

void*TUnk_804A1570::enter_state_513() { TItemWeapon__ct(); *(int*)((char*)this + 0x18) = (int)lbl_804A1570; set_status_flags__10TObjPlayerFUl(this, (void*)513); *(float *)&this->unk_200 = 0.0f; *(float *)&(this->m_1fc) = 0.0f; *(float*)((char*)this + 0x1f8) = 0.0f; return this; }

}

extern "C" {
u8 * enter_state_513__13TUnk_804A1570Fv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_state_513(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(enter_state_513__13TUnk_804A1570Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
