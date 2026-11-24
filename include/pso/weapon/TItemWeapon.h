#ifndef PSO_WEAPON_TITEMWEAPON_H
#define PSO_WEAPON_TITEMWEAPON_H
#include "types.h"
#include <stddef.h>
#include "pso/item/TItemEquipBase.h"
#include "pso/weapon/WeaponEffectDescriptor.h"

struct TItem;
struct TItemData;
class TItemEffectWeapon;
class TObjChara;
struct WeaponVector { f32 x,y,z; };

struct WeaponMotionRecord { u32 unknown; u32 frame_count; };

// A weapon's item parameter record (lookup_item_pmt_record).
struct WeaponParams {
    u8 pad_0[0x17];
    u8 photon_color;               // signed; -1: no photon colour
    u8 special;                    // the weapon's fixed special, 0 for none
    u8 pad_19[0x1B - 0x19];
    u8 gun_point_joint;            // where shots start
    u8 trail_joints[4];            // start and end joints of trails 0 and 1
    u8 color_node;                 // model node drawn in the photon colour
    u8 effect_nodes[3];            // model nodes apply_weapon_node_material draws with the effect render
    u8 pad_24[0x26 - 0x24];
    u8 technique_boost;            // get_shield_pmt_entry index of the technique boosts
    u8 flags;                      // 1, 2, 4: effect flag 0x20, weapon flags 0x40000, 0x80000
};

// impact_callback / hit_callback: (task layer, weapon, target, extra).
typedef s32 (*WeaponHitCallback)(s32 layer, void *weapon, u16 target, s32 extra);
// shot_callback: draws a shot from origin to end over frames.
typedef s32 (*WeaponShotCallback)(void *weapon, void *origin, f32 *end, f32 frames);

// The base of every weapon: the equipped weapon's attacks, its trails and
// the technique it rolls.
struct TItemWeapon : public TItemEquipBase {
    TItemWeapon(TObject *parent, u8 *item);
    virtual ~TItemWeapon();
    saddr get_tp();
    void update_active_game_effect();
    void launch_rare_weapon_special(void *, s32, f32);
    void fill_status_info(S_802E451C *params);
    void drain_owner_hp_fraction(f32);
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
    // Run last by on_equip and on_unequip; subclasses reset their own state.
    virtual void on_equipped();
    virtual void on_unequipped();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    virtual void vfunc_60();
    // attack_kind 0 physical, 1 physical with knockback, 2 the weapon
    // special; body indexes the target's collision bodies.
    virtual void deliver_hit(TObjPlayer *attacker, TObjChara *target, s32 attack_kind, f32 scale, s32 body);

    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    void fire_shot_at_target(void *origin, void *model, s32 angle);
    // csnVector from the owner's centre at point's height to point: the
    // wall in between, or NULL.
    u8 *trace_from_owner(u8 *point);
    void remap_extra_attack_type();
    void draw_weapon_model();
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
    void set_technique_roll_range(s32 range);
    void set_color_node(s16 node);
    // get_joint_position of gun_point_joint, where shots start.
    void get_gun_point(Vec *out);
    void sample_dual_muzzles(Vec *primary, Vec *secondary);

    TItemEffectWeapon *trails[4];
    s8 trail_start_joints[4];      // set_weapon_trail_joints
    s8 trail_end_joints[4];
    u8 attributes[6];              // the item's three attribute pairs
    u8 pad_1aa[0x1AC - 0x1AA];
    Vec held_position;             // the owner's joint 0x30, where get_center puts it
    u32 weapon_flags;
    s32 technique_roll;
    s32 previous_technique_roll;
    s32 technique_roll_range;
    f32 photon_phase;              // 0..1, advance_weapon_photon_phase
    s16 color_node;                // WeaponParams::color_node, -1 without a photon colour
    s16 gun_point_joint;           // get_gun_point
    u8 pad_1d0[0x1D1 - 0x1D0];
    u8 grind;
    u8 special_selector;
    u8 motion_type;                // get_motion_type
    s32 stage;
    f32 motion_frame;
    WeaponParams *parameters;      // the weapon's item parameter record
    // The technique boosts it gives (register_technique_boosts).
    const TechniqueBoostParam *technique_boosts;
    f32 shot_speed;                // distance a shot covers per frame
    s16 photon_color_id;           // get_photon_color_record, -1 for none
    u8 pad_1ea[0x1EC - 0x1EA];
    WeaponHitCallback impact_callback;  // when a shot hits a wall (spawn_land_hit_effect)
    WeaponShotCallback shot_callback;   // draws the shot (create_gun_shot)
    WeaponHitCallback hit_callback;     // deliver_hit, on the target hit
};

struct WeaponMarkerPacket { s8 kind,variant; u8 pad[2]; TObjPlayer* player; s32 unobserved[3]; };

LAYOUT_ASSERT(WeaponTrailsOffset, offsetof(TItemWeapon,trails)==0x18C);
LAYOUT_ASSERT(WeaponTechniqueRollOffset, offsetof(TItemWeapon,technique_roll)==0x1BC);
LAYOUT_ASSERT(WeaponPreviousTechniqueRollOffset, offsetof(TItemWeapon,previous_technique_roll)==0x1C0);
LAYOUT_ASSERT(WeaponTechniqueRollRangeOffset, offsetof(TItemWeapon,technique_roll_range)==0x1C4);
LAYOUT_ASSERT(WeaponSpecialSelectorOffset, offsetof(TItemWeapon,special_selector)==0x1D2);
LAYOUT_ASSERT(WeaponAttributesOffset, offsetof(TItemWeapon,attributes)==0x1A4);
LAYOUT_ASSERT(WeaponGrindOffset, offsetof(TItemWeapon,grind)==0x1D1);
LAYOUT_ASSERT(WeaponStageOffset, offsetof(TItemWeapon,stage)==0x1D4);
LAYOUT_ASSERT(WeaponFrameOffset, offsetof(TItemWeapon,motion_frame)==0x1D8);
LAYOUT_ASSERT(WeaponTechniqueBoostsOffset, offsetof(TItemWeapon,technique_boosts)==0x1E0);
LAYOUT_ASSERT(WeaponPhotonPhaseOffset, offsetof(TItemWeapon,photon_phase)==0x1C8);
LAYOUT_ASSERT(WeaponPhotonColorOffset, offsetof(TItemWeapon,photon_color_id)==0x1E8);
LAYOUT_ASSERT(WeaponParamsSpecialOffset, offsetof(WeaponParams,special)==0x18);
LAYOUT_ASSERT(WeaponFlagsOffset, offsetof(TItemWeapon,weapon_flags)==0x1B8);
LAYOUT_ASSERT(WeaponShotSpeedOffset, offsetof(TItemWeapon,shot_speed)==0x1E4);
LAYOUT_ASSERT(WeaponShotCallbackOffset, offsetof(TItemWeapon,shot_callback)==0x1F0);
LAYOUT_ASSERT(WeaponGunPointOffset, offsetof(TItemWeapon,gun_point_joint)==0x1CE);
LAYOUT_ASSERT(WeaponHitCallbackOffset, offsetof(TItemWeapon,hit_callback)==0x1F4);
LAYOUT_ASSERT(WeaponBaseSize, sizeof(TItemWeapon)==0x1F8);
LAYOUT_ASSERT(WeaponMarkerPacketSize, sizeof(WeaponMarkerPacket)==0x14);
extern "C" {
void set_weapon_trail_joints(TItemWeapon *weapon, s32 trail, s32 start_joint, s32 end_joint);
// TItemWeapon's destructor under its own symbol, for the derived classes
// still written as C functions.
void *__dt__11TItemWeaponFv(void *item, s16 deleting);
}
#endif
