#include "types.h"
#include "pso/item/TItemProArmor_80116F68.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_8049FC90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemObject.h"
#include "pso/item/TUnk_8049FD48.h"
#include "pso/unk/TUnk_8049FBC0.h"
#include "pso/item/TItemProArmor.h"

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
s32 get_item_index__5TItemFv(void *);
void TItemObject__ct(void *);
u8 get_tool_pmt_amount_byte__11TItemObjectFv();
s32 launch_technique__10TObjPlayerFv(s32, s32, s32);
void *__dt__11TItemObjectFv(void *arg0, s16 arg1);
int obj_getS16_2BA(void*);

extern s32 lbl_8049FBC0[];

void *TUnk_8049FBC0::construct_material(void *_w1, void *_w2) {
    TItemObject__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_8049FBC0;
    return this;
}
}

extern s32 lbl_8049FC90[];

u8 *create_material_item(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x104));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_8049FBC0 *)temp_r3)->construct_material((void *)tl_05, (void *)arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_8049FC90::vfunc_44() {
  u8 temp_r31;
    s32 arg0 = (s32)this;
  temp_r31 = get_item_index__5TItemFv((void *) arg0);
  ((TItem *)arg0)->set_owner_technique_level(((s16) (((TItemObject *)arg0)->sub_80115D7C() & 0xFF)), ((s16) (temp_r31 & 0xFFFFFFFFu)));
}

void *__dt__13TUnk_8049FC90Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8049FC90;
        __dt__11TItemObjectFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
void *construct_technique_disk_item(void *arg0, void * _w1, void * _w2) {
    TItemObject__ct(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_8049FC90;
    return arg0;
}

u8 *create_technique_disk_item(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x104));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)construct_technique_disk_item((void *)temp_r3, (void *)tl_05, (void *)arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_8049FD48::vfunc_44() {
    launch_technique__10TObjPlayerFv(0xE, 0, (s32)this->owner);
}

extern s32 lbl_8049FD48[];

void *__dt__13TUnk_8049FD48Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8049FD48;
        __dt__11TItemObjectFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void *TUnk_8049FD48::init(void *_w1, void *_w2) {
    TItemObject__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_8049FD48;
    return this;
}

u8 *create_telepipe_item(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x104));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_8049FD48 *)temp_r3)->init((void *)tl_05, (void *)arg0)));
        }
        return var_r0;
    }
    return NULL;
}

int TItemProArmor::get_stat_value() { return obj_getS16_2BA(*(void* *)&this->owner); }

extern s32 game_difficulty_selection;

s16 TItemProArmor::calc_scaled_offset() {
    return (s16) ((game_difficulty_selection * 0x32) + get_tool_pmt_amount_byte__11TItemObjectFv());
}
