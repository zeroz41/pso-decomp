#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A535C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A535C[];
extern s32 rocket_punch_wall_impact[];
extern s32 rocket_punch_target_impact[];
extern s32 rocket_punch_create_shot[];
extern const f32 lbl_805DAEF0;
struct VOff_8012C868_arg0_8012c868 { char pad_0[0x1F8]; char f_1F8[1]; };

void *TUnk_804A535C::init_trade_action() {
    struct VOff_8012C868_arg0_8012c868 *self = (struct VOff_8012C868_arg0_8012c868 *)this;
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A535C;
    __ct__8FlagWordFv((self->f_1F8));
    ((FlagWord *)((char *)this + 376))->set(32);
    set_weapon_flags(515);
    (*(s32 * *)((u8 *)this + 0x1EC)) = rocket_punch_wall_impact;
    (*(s32 * *)((u8 *)this + 0x1F4)) = rocket_punch_target_impact;
    *(s32 **)((s8 *)this + 0x1F0) = rocket_punch_create_shot;
    *(f32 *)&(*(float *)((u8 *)this + 0x1E4)) = lbl_805DAEF0;
    ((FlagWord *)(self->f_1F8))->reset();
    return this;
}

}
