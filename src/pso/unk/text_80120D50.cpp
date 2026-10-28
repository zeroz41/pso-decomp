#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/unk/text_8011B620.h"
#include "pso/unk/text_80120D50.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"

struct Pad_80120D50 { u8 pad[0x18]; };

struct V_80120D50 : Pad_80120D50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(s32);
};

extern "C" {
u8 get_item_group__5TItemFv(void *);
void *lookup_item_pmt_record(u8 *item);
s32 set_weapon_trail_joints(void *, int, int, int);
s32 memcpy(void *, void *, int);
s32 memset(void *, int, int);
extern void *__vt__11TItemWeapon[];
extern const f32 lbl_805DAC98;
extern u8 lbl_805DACA4;
extern const f32 lbl_805DACB0;
u8 *TItemWeapon__ct(TItemWeapon *arg0, void *parent, u8 *item) {
    s32 temp_r3;
    u8 temp_r0;
    u8 *temp_r6;
    u8 *temp_r6_2;
    __ct__14TItemEquipBaseFP7TObjectPUc(arg0, parent, item);
    *(void ***)((s8 *)arg0 + 0x18) = __vt__11TItemWeapon;
    ((V_80120D50 *)arg0)->v17(6);
    arg0->parameters = (WeaponParams *)lookup_item_pmt_record(item);
    *(s32 *)((s8 *)arg0 + 0x1E0) = TObjPlayer::get_shield_pmt_entry(*(u8 *)((s8 *)arg0->parameters + 0x26));
    *(s16 *)((s8 *)arg0 + 0x1E8) = (s16) (s8) *(u8 *)((s8 *)((unsigned char *) (arg0->parameters)) + 0x17);
    *(u8 *)((s8 *)arg0 + 0x1D1) = (u8) *(u8 *)((s8 *)item + 3);
    temp_r3 = ((TItemData *)item)->check_item_flags();
    temp_r0 = *(u8 *)((s8 *)arg0->parameters + 0x18);
    if (temp_r0 == 0) {
        arg0->special_selector = (u8) (*(u8 *)((s8 *)item + 4) & 0xFFFFFFBF);
    } else {
        arg0->special_selector = temp_r0;
    }
    if (temp_r3 == 0) {
        arg0->special_selector = (u8) (arg0->special_selector | lbl_805DACA4);
    }
    memcpy((u8 *)arg0 + 0x1A4, item + 6, 6);
    *(s32 *)((s8 *)arg0 + 0x1EC) = 0;
    *(s32 *)((s8 *)arg0 + 0x1F4) = 0;
    *(void **)((s8 *)arg0 + 0x1F0) = (void *)create_gun_shot;
    *(s16 *)((s8 *)arg0 + 0x1CE) = (s16) *(u8 *)((s8 *)arg0->parameters + 0x1B);
    temp_r6 = (unsigned char *) (arg0->parameters);
    set_weapon_trail_joints(arg0, 0, (int) (*(u8 *)((s8 *)temp_r6 + 0x1C)), (int) (*(u8 *)((s8 *)temp_r6 + 0x1D)));
    temp_r6_2 = (unsigned char *) (arg0->parameters);
    set_weapon_trail_joints(arg0, 1, (int) (*(u8 *)((s8 *)temp_r6_2 + 0x1E)), (int) (*(u8 *)((s8 *)temp_r6_2 + 0x1F)));
    set_weapon_trail_joints(arg0, 2, (int) (-1U), (int) (-1U));
    set_weapon_trail_joints(arg0, 3, (int) (-1U), (int) (-1U));
    memset((u8 *)arg0 + 0x18C, 0, 0x10);
    *(s32 *)((s8 *)arg0 + 0x1B8) = 0;
    *(f32 *)((s8 *)arg0 + 0x1E4) = (f32) lbl_805DACB0;
    arg0->technique_roll = 0;
    arg0->previous_technique_roll = 0;
    arg0->technique_roll_range = 0;
    u8 ed = ((u32 (*)(void *))get_item_group__5TItemFv)(arg0);
    if (ed < 0xAA) {
        arg0->motion_type = get_weapon_class_motion_type(ed);
        if ((s16) *(s16 *)((s8 *)arg0 + 0x1E8) != -1) {
            *(s16 *)((s8 *)arg0 + 0x1CC) = (s16) *(u8 *)((s8 *)arg0->parameters + 0x20);
        } else {
            *(s16 *)((s8 *)arg0 + 0x1CC) = -1;
        }
    } else {
        arg0->motion_type = 1;
        *(s16 *)((s8 *)arg0 + 0x1CC) = -1;
    }
    arg0->stage = -1;
    arg0->motion_frame = (f32) lbl_805DAC98;
    if (get_item_group__5TItemFv(arg0) == 0) {
        *(s16 *)((s8 *)arg0 + 0x1E8) = -1;
    } else {
        item_render_state.reset();
        *(f32 *)((s8 *)arg0 + 0x1C8) = (f32) lbl_805DAC98;
    }
    arg0->set_weapon_category_flags();
    if (*(u8 *)((s8 *)arg0->parameters + 0x27) & 1) {
        ((FlagWord *)((u8 *)arg0 + 0x178))->set(0x20);
    }
    if (*(u8 *)((s8 *)arg0->parameters + 0x27) & 2) {
        ((TObjPlayer *)arg0)->set_status_flags(0x40000);
    }
    if (*(u8 *)((s8 *)arg0->parameters + 0x27) & 4) {
        ((TObjPlayer *)arg0)->set_status_flags(0x80000);
    }
    return (u8 *)arg0;
}

}
