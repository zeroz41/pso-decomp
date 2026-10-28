#include "types.h"
#include "pso/item/TUnk_804A0DB0.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_801220A4.h"
#include "pso/player/TObjPlayer_80122014.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern "C" {

int scale_current_matrix(void*);
int get_player_list__10TObjPlayerFv(void*);
}

void belra_cannon_return_timer(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
    }
}

void TObjPlayer::notify_tentacle_if_mode1() { if (get_player_list__10TObjPlayerFv(this) == 1) { scale_current_matrix((char*)this + 0x1f8); } }

void TUnk_804A0DB0::emit_marker_effects() { this->m_1fc = 0.1f; }

void TUnk_804A0DB0::update_weapon() {
    f32 temp_f2;
    temp_f2 = this->m_1fc;
    if (temp_f2 < 1.0f) {
        this->m_1fc += 0.1f;
        if (1.0f <= this->m_1fc) {
            this->m_1fc = (f32) 1.0f;
        }
    }
}

extern s32 lbl_804A0DB0[];

void *__dt__13TUnk_804A0DB0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A0DB0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int TItemWeapon__ct(void);

void*TUnk_804A0DB0::init_state_vector() { TItemWeapon__ct(); *(int*)((char*)this + 0x18) = (int)lbl_804A0DB0; *(float *)&this->unk_200 = 1.0f; *(float *)&(*(s32 *)&this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}

extern "C" {
u8 * init_state_vector__13TUnk_804A0DB0Fv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_state_vector_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_state_vector__13TUnk_804A0DB0Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
}
