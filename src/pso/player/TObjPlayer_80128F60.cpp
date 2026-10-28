#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A403C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void set_status_flags__10TObjPlayerFUl(void *, int);
void construct_srank_weapon(void *);

extern s32 lbl_804A403C[];
extern s32 notify_hit_target__10TObjPlayerFUlUlUlUl[];
extern s32 TObjPlayer__sub_80128A74[];
extern s32 spawn_shot_effect__10TObjPlayerFlllf[];
extern const f32 lbl_805DADF8;
struct VOff_80128F60_arg0_80128f60 { char pad_0[0x1FC]; char f_1FC[1]; };

void *TUnk_804A403C::init_event_callbacks() {
    struct VOff_80128F60_arg0_80128f60 *self = (struct VOff_80128F60_arg0_80128f60 *)this;
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A403C;
    __ct__8FlagWordFv((self->f_1FC));
    ((FlagWord *)((char *)this + 376))->set(32);
    set_status_flags__10TObjPlayerFUl(this, 515);
    (*(s32 * *)((u8 *)this + 0x1EC)) = notify_hit_target__10TObjPlayerFUlUlUlUl;
    (*(s32 * *)((u8 *)this + 0x1F4)) = TObjPlayer__sub_80128A74;
    *(s32 **)((s8 *)this + 0x1F0) = spawn_shot_effect__10TObjPlayerFlllf;
    *(f32 *)&(*(float *)((u8 *)this + 0x1E4)) = lbl_805DADF8;
    ((FlagWord *)(self->f_1FC))->reset();
    return this;
}

}
