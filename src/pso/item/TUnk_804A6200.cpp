#include "types.h"
#include "pso/item/TItemProArmor.h"
#include "pso/player/TObjPlayer_8012F05C.h"
#include "pso/item/TUnk_804A6200.h"
#include "pso/unk/text_8012F0F8.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F1F4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_8012F298.h"

extern "C" {

int scale_current_matrix(void*);
s32 get_owner_client__5TItemFv(void *);
s32 init_item_timer_event__13TUnk_804A0648Fv(s32, u32, s32, s32);
int get_player_list__10TObjPlayerFv(void*);
s32 __nw__15TItemHeapObjectFUl(s32);
}

void madam_parasol_scale_canopy(void* p) { if (get_player_list__10TObjPlayerFv(p) == 2) { scale_current_matrix((char*)p + 0x1f8); } }

void madam_parasol_start_regen(void *item_pro_armor) {
    s32 temp_r3;

    if ((u32) ((TItemProArmor *)item_pro_armor)->effect_objects != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            init_item_timer_event__13TUnk_804A0648Fv(temp_r3, (u32)((TItemProArmor *)item_pro_armor)->effect_objects, get_owner_client__5TItemFv(item_pro_armor), 0x5A);
        }
    }
}

extern "C" {
s32 play_sound_effect(int, int, int, int);

void TUnk_804A6200::update_idle() {
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

void TUnk_804A6200::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)(-0.14f), (f32)0.3f);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)0.04000001f, (f32)1.2f);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x200), (f32)(-0.14f), (f32)0.3f);
}

extern s32 lbl_804A6200[];

void *__dt__13TUnk_804A6200Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6200;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

void*TUnk_804A6200::set_mode_vector() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A6200; *(float *)&this->unk_200 = 1.0f; *(float *)&(this->m_1fc) = 1.0f; *(float*)((char*)this + 0x1f8) = 1.0f; return this; }

}

extern "C" {
u8 * set_mode_vector__13TUnk_804A6200Fv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_8012F298(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(set_mode_vector__13TUnk_804A6200Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
