#ifndef PSO_OBJECT_BASE_TATTACKCOLLIDER_H
#define PSO_OBJECT_BASE_TATTACKCOLLIDER_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/AreaAttackContact.h"

class AreaAttackHistory;

class TAttackCollider : public TObjCollidable {
public:
    TAttackCollider(TObject *, TObjBase *);
    TAttackCollider(TObject *, TObjBase *, const CollisionBody *, s32);
    virtual ~TAttackCollider();
    void update_body_contact_flag(f32);
    virtual s32 call_vt13_with_default(const AreaAttackContact *contact, DirectAttackPayload *attack,
                                       AreaAttackHistory *history);
    virtual s32 area_attack_deliver_direct(const AreaAttackContact *contact, DirectAttackPayload *attack,
                                           AreaAttackHistory *history, f32 range);
    // Delivers attack to every eligible player in reach, with no hit history (inferred name).
    virtual s32 deliver_direct_no_history(const AreaAttackContact *contact, DirectAttackPayload *attack);
    virtual void call_vt16_with_default(const AreaAttackContact *contact, AreaAttackHistory *history);
    virtual s32 area_attack_deliver_physical(const AreaAttackContact *contact, AreaAttackHistory *history, f32 range);
    // Delivers a physical hit to every eligible player in reach, with no hit history (inferred name).
    virtual void deliver_physical_no_history(const AreaAttackContact *contact);
    virtual void area_attack_apply_recoil(TObjChara *target, f32 recoil);
    virtual void area_attack_receive_direct(TObjChara *target, const f32 *recoil, DirectAttackPayload *attack);
    virtual void apply_hit_if_active(TObjChara *target, const f32 *recoil);
    // Takes the firing actor and its room.
    void set_owner(TObjBase *actor);
    void set_position_from(const Vec *pos);
    s32 is_target_eligible(u32 actor_flags);
    TObjBase *owner;   // the actor that fired this hitbox
};
LAYOUT_ASSERT(TAttackCollider_size, sizeof(TAttackCollider) == 0xB0);

#endif
