#ifndef PSO_ITEMS_TITEMWEAPON_H
#define PSO_ITEMS_TITEMWEAPON_H
#include "types.h"
#include <stddef.h>
#include "pso/item/TItemEquipBase.h"

struct TItem;
struct TItemData;
class TItemEffectWeapon;
struct WeaponVector { f32 x,y,z; };

struct WeaponMotionRecord { u32 unknown; u32 frame_count; };

// A weapon's item parameter record (lookup_item_pmt_record).
struct WeaponParams {
    u8 pad_0[0x18];
    u8 special;                    // the weapon's fixed special, 0 for none
    u8 pad_19[0x1C - 0x19];
    u8 trail_joints[4];            // start and end joints of trails 0 and 1
    u8 pad_20[0x28 - 0x20];
};

// The base of every weapon: the equipped weapon's attacks, its trails and
// the technique it rolls.
struct TItemWeapon : public TItemEquipBase {
    TItemWeapon(TObject *parent, u8 *item);
    virtual ~TItemWeapon();
    virtual void *get_center();
    virtual void update_owned();
    virtual void update_equipped();
    // A technique roll (send_activate_effect from roll_technique).
    virtual void activate_effect(s32 effect);
    virtual void write_item_data(TItemData *data);
    virtual void render_equipped();
    virtual void render_equipped_shadow();
    virtual void render_equipped_deferred();
    virtual void perform_action();
    virtual u32 get_attack_flags();
    virtual void refresh_special();
    virtual s32 is_identified();
    virtual u8 get_motion_type();
    virtual void on_equip();
    virtual void on_unequip();
    virtual void request_equipped_model();
    virtual void release_model();
    virtual void apply_owner_bonuses();
    virtual void remove_owner_bonuses();
    virtual void on_model_loaded();
    // The virtuals every weapon adds.
    virtual s32 launch_shot(u8 *origin, s32 target, s32 angle, s32 apply);
    virtual void emit_marker_effects();
    virtual void update_attack();
    virtual void update_idle();
    virtual void reserved_53();
    virtual void update_weapon();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void deliver_hit(s32 arg1, u8 *arg2, s32 arg3, s32 arg4, f32 farg0);

    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    void fire_shot_at_target(void *, void *, s32);
    void sub_8011E56C(u8 *);
    void remap_extra_attack_type();
    s32 draw_weapon_model();
    void create_weapon_trail_effects();
    void apply_model_params();
    void spawn_light_task();
    void set_weapon_category_flags();
    // weapon_flags
    u32 test_weapon_flags(u32 mask);
    void set_weapon_flags(u32 mask);
    void clear_weapon_flags(u32 mask);
    void set_flag_8();
    void sub_80121208(s32);
    void advance_weapon_photon_phase();
    s32 is_active_in_game();
    void roll_technique();
    // The owner is on the third step of a combo and the weapon is identified.
    s32 is_mode_two_and_ready();
    u8 get_special_selector();
    void restore_action_type();
    s32 get_attack_stage();
    void update_trails();
    // Extends trail slot from its start to its end joint (draw_icon).
    void update_trail_slot(s32 slot);
    // Where a joint of the owner's model is on screen (-1, -2: the owner's
    // own points), stored as a Vec at out; 0 without an owner.
    s32 get_joint_position(s32 joint, void *out);
    // get_joint_position of gun_point_joint, where shots start.
    void get_gun_point(void *out);

    TItemEffectWeapon *trails[4];
    s8 trail_start_joints[4];      // set_weapon_trail_joints
    s8 trail_end_joints[4];
    u8 attributes[6];              // the item's three attribute pairs
    u8 pad_1aa[0x1B8 - 0x1AA];
    u32 weapon_flags;
    s32 technique_roll;
    s32 previous_technique_roll;
    s32 technique_roll_range;
    u8 pad_1c8[0x1CE - 0x1C8];
    s16 gun_point_joint;           // get_gun_point
    u8 pad_1d0[0x1D1 - 0x1D0];
    u8 grind;
    u8 special_selector;
    u8 motion_type;                // get_motion_type
    s32 stage;
    f32 motion_frame;
    WeaponParams *parameters;      // the weapon's item parameter record
    void* material;
    f32 shot_speed;                // distance a shot covers per frame
    u8 pad_1e8[0x1EC - 0x1E8];
    void *impact_callback;         // spawn_land_hit_effect when a shot hits a wall
    void *shot_callback;           // draws the shot (create_gun_shot)
    u8 pad_1f4[0x1F8 - 0x1F4];
};

struct WeaponMarkerPacket { s8 kind,variant; u8 pad[2]; TObjPlayer* player; s32 unobserved[3]; };

typedef char WeaponTrailsOffset[(offsetof(TItemWeapon,trails)==0x18C)?1:-1];
typedef char WeaponTechniqueRollOffset[(offsetof(TItemWeapon,technique_roll)==0x1BC)?1:-1];
typedef char WeaponPreviousTechniqueRollOffset[(offsetof(TItemWeapon,previous_technique_roll)==0x1C0)?1:-1];
typedef char WeaponTechniqueRollRangeOffset[(offsetof(TItemWeapon,technique_roll_range)==0x1C4)?1:-1];
typedef char WeaponSpecialSelectorOffset[(offsetof(TItemWeapon,special_selector)==0x1D2)?1:-1];
typedef char WeaponAttributesOffset[(offsetof(TItemWeapon,attributes)==0x1A4)?1:-1];
typedef char WeaponGrindOffset[(offsetof(TItemWeapon,grind)==0x1D1)?1:-1];
typedef char WeaponStageOffset[(offsetof(TItemWeapon,stage)==0x1D4)?1:-1];
typedef char WeaponFrameOffset[(offsetof(TItemWeapon,motion_frame)==0x1D8)?1:-1];
typedef char WeaponMaterialOffset[(offsetof(TItemWeapon,material)==0x1E0)?1:-1];
typedef char WeaponParamsSpecialOffset[(offsetof(WeaponParams,special)==0x18)?1:-1];
typedef char WeaponFlagsOffset[(offsetof(TItemWeapon,weapon_flags)==0x1B8)?1:-1];
typedef char WeaponShotSpeedOffset[(offsetof(TItemWeapon,shot_speed)==0x1E4)?1:-1];
typedef char WeaponShotCallbackOffset[(offsetof(TItemWeapon,shot_callback)==0x1F0)?1:-1];
typedef char WeaponGunPointOffset[(offsetof(TItemWeapon,gun_point_joint)==0x1CE)?1:-1];
typedef char WeaponBaseSize[(sizeof(TItemWeapon)==0x1F8)?1:-1];
typedef char WeaponMarkerPacketSize[(sizeof(WeaponMarkerPacket)==0x14)?1:-1];
extern "C" {
// TItemWeapon's destructor under its own symbol, for the derived classes
// still written as C functions.
void *__dt__11TItemWeaponFv(void *item, s16 deleting);
}
#endif
