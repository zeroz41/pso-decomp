#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERBASE_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERBASE_H
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/camera/CameraDistanceFade.h"

struct QuestObjectEntry;

// The containers' common base: its constructor stores "TObjContainerBase" in m_name (TObjContainerItem's TU
// emits its vtable).
class TObjContainerBase : public TObjChara {
public:
    TObjContainerBase(TObject *parent, ObjectSetData *set_data);
    virtual void render();
    virtual void run_task();
    virtual ~TObjContainerBase();
    virtual void spawn_break_effects() const;
    virtual void update_state();
    virtual void draw_model();
    virtual void debug_print_item_box_info();
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    void request_configured_item_drop(TObjContainerBase *container);
    virtual void apply_saved_state(QuestObjectEntry *, s32);
    virtual s32 roll_physical_accuracy(TObjChara *, s32, f32);
    virtual s32 try_start_action(TObjChara *, s32, f32);
    virtual void apply_knockback_from_attacker(TObjBase *, f32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual s32 select_melee_contact_body(TObjChara *target, f32 range);
    f32 view_range; // 0x334: render() passes it to update_object_view_visibility (inferred name, as TOBoss4)
    f32 model_radius; // 0x338: the radius argument of that test (inferred name)
    f32 melee_range_sq; // 0x33C: squared reach tested by select_melee_contact_body (inferred name)
    CameraDistanceFade distance_fade;
    s32 random_item; // 0x360: debug_print_item_box_info prints "<- RANDOM ITEM" when set, "<- FIXED ITEM" otherwise
    s32 in_view; // 0x364: set by render() when the view test passes, cleared by run_task() after update_state (inferred name)
};

#endif
