#include "types.h"
#include "pso/item/TUnk_804A2F78.h"
#include "pso/player/TObjPlayer_80126EA8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80126F40.h"
#include "pso/item/TItem.h"

extern "C" {

int scale_current_matrix(void*);
int get_player_list__10TObjPlayerFv(void*);

void TUnk_804A2F78::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 2) { scale_current_matrix((char*)this + 0x1f8); } }

void TUnk_804A2F78::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x200), (f32)(-0.6f), (f32)1.0f);
}

void TUnk_804A2F78::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x200), (f32)0.6f, (f32)4.0f);
}

void TUnk_804A2F78::vfunc_57() {  }

}

extern s32 __vt__13TUnk_804A2F78[];

TUnk_804A2F78::~TUnk_804A2F78() {}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

void*TUnk_804A2F78::setup_effect() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)__vt__13TUnk_804A2F78; *(float *)&this->unk_200 = 1.0f; *(float *)&(this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}

extern "C" {
u8 * setup_effect__13TUnk_804A2F78Fv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_effect_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(setup_effect__13TUnk_804A2F78Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
