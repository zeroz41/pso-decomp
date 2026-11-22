#ifndef PSO_PLAYER_TUNK_804928CC_H
#define PSO_PLAYER_TUNK_804928CC_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_804928CC : public TObjCollidable {
public:
    TUnk_804928CC(TObject *, TObjBase *);
    TUnk_804928CC(TObject *, TObjBase *, const CollisionBody *, s32);
    virtual ~TUnk_804928CC();
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
    TObjBase *owner;   // the actor that fired this hitbox
};
LAYOUT_ASSERT(TUnk_804928CC_size, sizeof(TUnk_804928CC) == 0xB0);

extern "C" void *__dt__13TUnk_804928CCFv(void *, s16);
extern "C" void *__ct__13TUnk_804928CCFP7TObjectP8TObjBasePC13CollisionBodyl(void *, void *, void *, const void *, s32);

#endif
