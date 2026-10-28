#include "types.h"
#include "pso/player/TObjPlayer_80126EA8.h"
#include "pso/item/TUnk_804A2F78.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80126F40.h"
#include "pso/item/TItem.h"

extern "C" {

int scale_current_matrix(void*);
int get_player_list__10TObjPlayerFv(void*);

void TObjPlayer::handle_tentacle_state_2() { if (get_player_list__10TObjPlayerFv(this) == 2) { scale_current_matrix((char*)this + 0x1f8); } }

void TUnk_804A2F78::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x200), (f32)(-0.6f), (f32)1.0f);
}

void TUnk_804A2F78::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x200), (f32)0.6f, (f32)4.0f);
}

void TObjPlayer__sub_80126F3C(void) {  }

}

extern s32 lbl_804A2F78[];

void *__dt__13TUnk_804A2F78Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2F78;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

void*TUnk_804A2F78::setup_effect() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A2F78; *(float *)&this->unk_200 = 1.0f; *(float *)&(this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}
