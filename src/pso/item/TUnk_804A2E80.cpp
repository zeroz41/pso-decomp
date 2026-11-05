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

extern "C" {
u8 * init_shot_effect__13TUnk_804A2E80Fv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_shot_effect_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_shot_effect__13TUnk_804A2E80Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
