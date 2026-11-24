#ifndef PSO_OBJECT_BASE_TATTACKCOLLIDER_H
#define PSO_OBJECT_BASE_TATTACKCOLLIDER_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TAttackCollider : public TObjCollidable {
public:
    TAttackCollider(TObject *, TObjBase *);
    TAttackCollider(TObject *, TObjBase *, const CollisionBody *, s32);
    virtual ~TAttackCollider();
    void update_body_contact_flag(f32);
    virtual s32 call_vt13_with_default(void *, void *, saddr);
    virtual s32 area_attack_deliver_direct(void *, saddr, void *, f32);
    virtual s32 vfunc_16(void *, void *);
    virtual void call_vt16_with_default(void *, void *);
    virtual s32 area_attack_deliver_physical(void *, void *, f32);
    virtual void vfunc_19(void *);
    virtual void area_attack_apply_recoil(void *, f32);
    virtual void area_attack_receive_direct(void *, f32 *, void *);
    virtual void apply_hit_if_active(void *, f32 *);
    // Takes the firing actor and its room.
    void set_owner(TObjBase *actor);
    void set_position_from(const Vec *pos);
    s32 is_target_eligible(u32 actor_flags);
    TObjBase *owner;   // the actor that fired this hitbox
};
LAYOUT_ASSERT(TAttackCollider_size, sizeof(TAttackCollider) == 0xB0);

#endif
