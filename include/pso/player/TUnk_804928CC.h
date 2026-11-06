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
    virtual void call_vt13_with_default(void*, void*, s32);
    virtual s32 area_attack_deliver_direct(void *, s32, void *, f32);
    virtual void vfunc_16(void *, void *);
    virtual void call_vt16_with_default(void *, void *);
    virtual s32 area_attack_deliver_physical(void *, void *, f32);
    virtual void vfunc_19(void *);
    virtual void area_attack_apply_recoil(void *, f32);
    virtual void area_attack_receive_direct(void *, f32 *, void *);
    virtual void apply_hit_if_active(void *, f32 *);
    void sub_800BC3E8(u8 *);
    u32 owner;   // the actor that fired this hitbox (a TObjBase *; sub_800BC3E8 stores it and copies its room)
};
typedef char TUnk_804928CC_size[sizeof(TUnk_804928CC) == 0xB0 ? 1 : -1];

extern "C" void *__dt__13TUnk_804928CCFv(void *, s16);
extern "C" void *__ct__13TUnk_804928CCFP7TObjectP8TObjBasePC13CollisionBodyl(void *, void *, void *, const void *, s32);

#endif
