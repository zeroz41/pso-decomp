#include "types.h"
#include "pso/item/TUnk_804A3928.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80128158.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_801281C4.h"
#include "pso/item/TItem.h"

struct Obj_80128128 { u8 pad[0x200]; f32 c; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;

void TUnk_804A3928::update_idle() {
    Obj_80128128 *self = (Obj_80128128 *)this;
    if (0.08f < self->c) {
        self->c -= 0.3f;
        if (self->c < 0.08f) {
            self->c = 0.08f;
        }
    }
}

}

extern "C" {

int scale_current_matrix(void*);
int get_player_list__10TObjPlayerFv(void*);

void TUnk_804A3928::update_attack() {
    f32 temp_f2;

    temp_f2 = *(f32 *)&this->unk_200;
    if (temp_f2 < 1.0f) {
        *(f32 *)&this->unk_200 += 0.3f;
        if (1.0f < *(f32 *)&this->unk_200) {
            *(f32 *)&this->unk_200 = (f32) 1.0f;
        }
    }
}

void TUnk_804A3928::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 0) { scale_current_matrix((char*)this + 0x1f8); } }

}

extern s32 __vt__13TUnk_804A3928[];

TUnk_804A3928::~TUnk_804A3928() {}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

void*TUnk_804A3928::init_shot_params() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)__vt__13TUnk_804A3928; *(float *)&this->unk_200 = 1.0f; *(float *)&(this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}

extern "C" {
u8 * init_shot_params__13TUnk_804A3928Fv(void *, s32, s32);
u8 *TObjPlayer::create_shot_params_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_shot_params__13TUnk_804A3928Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
