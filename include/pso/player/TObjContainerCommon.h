#ifndef PSO_PLAYER_TOBJCONTAINERCOMMON_H
#define PSO_PLAYER_TOBJCONTAINERCOMMON_H
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/camera/CameraDistanceFade.h"

// The containers' common base (TObjContainerItem's TU emits its vtable).
class TObjContainerCommon : public TObjChara {
public:
    TObjContainerCommon(TObject *parent, void *set_data);
    virtual void render();
    virtual void run_task();
    virtual ~TObjContainerCommon();
    virtual void spawn_break_effects() const;
    virtual void update_state();
    virtual void draw_model();
    virtual void debug_print_item_box_info();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    void request_configured_item_drop(TObjContainerCommon *container);
    virtual void vfunc_6(s16 *, s32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(void *, s32, f32);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *target, f32 range);
    f32 view_range; // 0x334: render() passes it to update_object_view_visibility (inferred name, as TOBoss4)
    f32 model_radius; // 0x338: the radius argument of that test (inferred name)
    f32 melee_range_sq; // 0x33C: squared reach tested by select_melee_contact_body (inferred name)
    CameraDistanceFade distance_fade;
    s32 random_item; // 0x360: debug_print_item_box_info prints "<- RANDOM ITEM" when set, "<- FIXED ITEM" otherwise
    s32 in_view; // 0x364: set by render() when the view test passes, cleared by run_task() after update_state (inferred name)
};

#endif
