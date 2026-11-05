#include "types.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A403C.h"

extern s32 lbl_804A403C[];

void *__dt__13TUnk_804A403CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A403C;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void construct_srank_weapon(void *);

extern s32 notify_hit_target__10TObjPlayerFUlUlUlUl[];
extern s32 TObjPlayer__sub_80128A74[];
extern s32 spawn_shot_effect__10TObjPlayerFlllf[];
struct VOff_80128F60_arg0_80128f60 { char pad_0[0x1FC]; char f_1FC[1]; };

void *TUnk_804A403C::init_event_callbacks() {
    struct VOff_80128F60_arg0_80128f60 *self = (struct VOff_80128F60_arg0_80128f60 *)this;
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A403C;
    __ct__8FlagWordFv((self->f_1FC));
    ((FlagWord *)((char *)this + 376))->set(32);
    ((TItemWeapon *)this)->set_weapon_flags(515);
    (*(s32 * *)((u8 *)this + 0x1EC)) = notify_hit_target__10TObjPlayerFUlUlUlUl;
    (*(s32 * *)((u8 *)this + 0x1F4)) = TObjPlayer__sub_80128A74;
    *(s32 **)((s8 *)this + 0x1F0) = spawn_shot_effect__10TObjPlayerFlllf;
    *(f32 *)&(*(float *)((u8 *)this + 0x1E4)) = 10.0f;
    ((FlagWord *)(self->f_1FC))->reset();
    return this;
}

}
