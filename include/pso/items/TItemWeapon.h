#ifndef PSO_ITEMS_TITEMWEAPON_H
#define PSO_ITEMS_TITEMWEAPON_H
#include "types.h"

struct TItem;
struct TItemData;
#include <stddef.h>
struct WeaponVector { f32 x,y,z; };

struct WeaponObjectPrefix { u8 object[0x18]; };

struct WeaponPlayerPrefix { u8 object[0x60]; s32 heading; };

struct WeaponMotionRecord { u32 unknown; u32 frame_count; };

struct TItemWeapon : WeaponObjectPrefix {
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
    s8 get_attach_joint();
    int test_flags_1b8(u32);
    void sub_80121208(s32);
    void clear_equip_flags(u32);
    void advance_weapon_photon_phase();
    u8 is_active_in_game();
    virtual void reserved_0();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    virtual void vfunc_6();
    virtual void apply_object_set_data();
    virtual void reset_motion_fields();
    virtual void vfunc_9();
    virtual void update_object_view_visibility();
    virtual void classify_actor_view_detail();
    virtual const char *get_name();
    virtual void interact(s32 client);
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(s32 value);
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void destroy();
    virtual void perform_action();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void snap_to_owner();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void release();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void deliver_projectile(WeaponVector*, s32, s32, s32);
    virtual void emit_marker_effects();
    virtual void update_attack();
    virtual void update_idle();
    virtual void reserved_53();
    virtual void update_weapon();
    u8 object_to_heading[0x60-0x1C];
    s32 heading;
    u8 object_to_player[0xF0-0x64];
    WeaponPlayerPrefix* player;
    u8 equipment_to_motion[0x17C-0xF4];
    WeaponMotionRecord* motion;
    u8 equipment_to_projectile[0x188-0x180];
    s32 projectile;
    void* trails[4];
    u8 weapon_to_technique_roll[0x1BC-0x19C];
    s32 technique_roll;
    s32 previous_technique_roll;
    s32 technique_roll_range;
    u8 weapon_to_special_selector[0x1D2-0x1C8];
    u8 special_selector;
    u8 special_to_stage[0x1D4-0x1D3];
    s32 stage;
    f32 motion_frame;
    void* parameters;
    void* material;
    u8 remaining_weapon_fields[0x1F8-0x1E4];
    void roll_technique();
    u8 get_special_selector();
    void restore_action_type();
    u8 *get_motion_ptr();
    static void copy_item_to_data(s32 arg0);
    s32 get_attack_stage();
    u32 get_attack_flags();
    void update_trails();
    s32 launch_shot(u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    void deliver_hit(s32 arg1, u8 *arg2, s32 arg3, s32 arg4, f32 farg0);
};

struct WeaponMarkerPacket { s8 kind,variant; u8 pad[2]; WeaponPlayerPrefix* player; s32 unobserved[3]; };

typedef char WeaponHeadingOffset[(offsetof(TItemWeapon,heading)==0x60)?1:-1];
typedef char WeaponPlayerOffset[(offsetof(TItemWeapon,player)==0xF0)?1:-1];
typedef char WeaponMotionOffset[(offsetof(TItemWeapon,motion)==0x17C)?1:-1];
typedef char WeaponProjectileOffset[(offsetof(TItemWeapon,projectile)==0x188)?1:-1];
typedef char WeaponTrailsOffset[(offsetof(TItemWeapon,trails)==0x18C)?1:-1];
typedef char WeaponTechniqueRollOffset[(offsetof(TItemWeapon,technique_roll)==0x1BC)?1:-1];
typedef char WeaponPreviousTechniqueRollOffset[(offsetof(TItemWeapon,previous_technique_roll)==0x1C0)?1:-1];
typedef char WeaponTechniqueRollRangeOffset[(offsetof(TItemWeapon,technique_roll_range)==0x1C4)?1:-1];
typedef char WeaponSpecialSelectorOffset[(offsetof(TItemWeapon,special_selector)==0x1D2)?1:-1];
typedef char WeaponStageOffset[(offsetof(TItemWeapon,stage)==0x1D4)?1:-1];
typedef char WeaponFrameOffset[(offsetof(TItemWeapon,motion_frame)==0x1D8)?1:-1];
typedef char WeaponMaterialOffset[(offsetof(TItemWeapon,material)==0x1E0)?1:-1];
typedef char WeaponBaseSize[(sizeof(TItemWeapon)==0x1F8)?1:-1];
typedef char WeaponMarkerPacketSize[(sizeof(WeaponMarkerPacket)==0x14)?1:-1];
#endif
