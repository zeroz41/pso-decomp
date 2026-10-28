#include "types.h"
#include "pso/item/TUnk_804A67D0.h"
#include "pso/unk/text_8012FDEC.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012FEE8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern "C" {
s32 play_sound_effect(int, int, int, int);

void TUnk_804A67D0::update_idle() {
    f32 temp_f2;
    s32 var_r31;
    var_r31 = 0;
    temp_f2 = *(f32 *)((s8 *)((u8 *)this) + 0x1F8);
    if (temp_f2 < 1.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x1F8) += 0.14f;
        if (1.0f <= *(f32 *)((s8 *)((u8 *)this) + 0x1F8)) {
            *(f32 *)((s8 *)((u8 *)this) + 0x1F8) = (f32) 1.0f;
            var_r31 = 1;
        }
    }
    TItemEffOrgaFlowShot::approach_value((f32 *)(((u8 *)this) + 0x1FC), (f32)(-0.04000001f), (f32)1.0f);
    TItemEffOrgaFlowShot::approach_value((f32 *)(((u8 *)this) + 0x200), (f32)0.14f, (f32)1.0f);
    if (var_r31 == 1) {
        play_sound_effect(0x4001AA24, (int) (*(s32 *)((s8 *)((u8 *)this) + 0xF0) + 0x38), 0, 0);
    }
}

}

void TUnk_804A67D0::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)(-0.14f), (f32)0.3f);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)0.04000001f, (f32)1.2f);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x200), (f32)(-0.14f), (f32)0.3f);
}

extern s32 lbl_804A67D0[];

void *__dt__13TUnk_804A67D0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A67D0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int TItemWeapon__ct(void);

void*TUnk_804A67D0::init_fields() { TItemWeapon__ct(); *(int*)((char*)this + 0x18) = (int)lbl_804A67D0; *(float *)&this->unk_200 = 1.0f; *(float *)&(this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}
