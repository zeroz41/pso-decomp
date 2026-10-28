#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/unk/text_8011B620.h"

#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void *lookup_item_pmt_record(u8 *item);
s32 set_weapon_trail_joints(void *, int, int, int);
s32 memcpy(void *, void *, int);
s32 memset(void *, int, int);
extern const f32 lbl_805DAC98;
extern u8 lbl_805DACA4;
extern const f32 lbl_805DACB0;
}

TItemWeapon::TItemWeapon(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    s32 identified;
    u8 special;
    set_attach_slot(6);
    parameters = (WeaponParams *)lookup_item_pmt_record(item);
    technique_boosts = (const TechniqueBoostParam *)TObjPlayer::get_shield_pmt_entry(*(u8 *)((s8 *)parameters + 0x26));
    photon_color_id = (s16) (s8) *(u8 *)((s8 *)parameters + 0x17);
    grind = item[3];
    identified = ((TItemData *)item)->check_item_flags();
    special = parameters->special;
    if (special == 0) {
        special_selector = (u8) (item[4] & 0xFFFFFFBF);
    } else {
        special_selector = special;
    }
    if (identified == 0) {
        special_selector = (u8) (special_selector | lbl_805DACA4);
    }
    memcpy(attributes, item + 6, 6);
    impact_callback = 0;
    hit_callback = 0;
    shot_callback = (WeaponShotCallback)create_gun_shot;
    *(s16 *)((s8 *)this + 0x1CE) = (s16) *(u8 *)((s8 *)parameters + 0x1B);
    set_weapon_trail_joints(this, 0, parameters->trail_joints[0], parameters->trail_joints[1]);
    set_weapon_trail_joints(this, 1, parameters->trail_joints[2], parameters->trail_joints[3]);
    set_weapon_trail_joints(this, 2, -1, -1);
    set_weapon_trail_joints(this, 3, -1, -1);
    memset(trails, 0, 0x10);
    weapon_flags = 0;
    shot_speed = lbl_805DACB0;
    technique_roll = 0;
    previous_technique_roll = 0;
    technique_roll_range = 0;
    u32 group = get_item_group();
    if (group < 0xAA) {
        motion_type = get_weapon_class_motion_type(group);
        if (photon_color_id != -1) {
            *(s16 *)((s8 *)this + 0x1CC) = (s16) *(u8 *)((s8 *)parameters + 0x20);
        } else {
            *(s16 *)((s8 *)this + 0x1CC) = -1;
        }
    } else {
        motion_type = 1;
        *(s16 *)((s8 *)this + 0x1CC) = -1;
    }
    stage = -1;
    motion_frame = lbl_805DAC98;
    if (get_item_group() == 0) {
        photon_color_id = -1;
    } else {
        item_render_state.reset();
        photon_phase = lbl_805DAC98;
    }
    set_weapon_category_flags();
    if (*(u8 *)((s8 *)parameters + 0x27) & 1) {
        effect_flags.set(0x20);
    }
    if (*(u8 *)((s8 *)parameters + 0x27) & 2) {
        ((TItemWeapon *)this)->set_weapon_flags(0x40000);
    }
    if (*(u8 *)((s8 *)parameters + 0x27) & 4) {
        ((TItemWeapon *)this)->set_weapon_flags(0x80000);
    }
}
