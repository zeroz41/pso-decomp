#include "types.h"
#include "pso/player/TObjPlayer_80126D30.h"
#include "pso/item/TUnk_804A2E80.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80126DAC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern "C" {

int scale_current_matrix(void*);
int get_player_list__10TObjPlayerFv(void*);
}

void harisen_battle_fan_scale_node(void* p) { if (get_player_list__10TObjPlayerFv(p) == 1) { scale_current_matrix((char*)p + 0x1f8); } }

void TUnk_804A2E80::emit_marker_effects() { this->m_1fc = 0.1f; }

void TUnk_804A2E80::update_weapon() {
    f32 temp_f2;
    temp_f2 = this->m_1fc;
    if (temp_f2 < 1.0f) {
        this->m_1fc += 0.1f;
        if (1.0f <= this->m_1fc) {
            this->m_1fc = (f32) 1.0f;
        }
    }
}

extern s32 lbl_804A2E80[];

void *__dt__13TUnk_804A2E80Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2E80;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

void*TUnk_804A2E80::init_shot_effect() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A2E80; *(float *)&this->unk_200 = 1.0f; *(float *)&(*(s32 *)&this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}
