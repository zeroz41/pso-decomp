#ifndef PSO_OBJECT_TUNK_8049442C_H
#define PSO_OBJECT_TUNK_8049442C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_8049442C : public TObjCollidable {
public:
    // TObjEneGyaranzo::spawn_missile's shot: owner's room and id, launch
    // position, yaw and turn rate.
    TUnk_8049442C(TObjBase *owner, Vec *pos, s32 angle, s32 spin);
    virtual ~TUnk_8049442C();
    void sub_800D4200();
    void update_ground_fall(s32 *, f32);
    virtual void render();
    virtual void run_task();
    Vec velocity;
    s32 m_b8;
    s32 m_bc;
    s32 unk_C0;
    s32 m_c4;
    s32 unk_C8;
    s32 m_cc;
    s32 unk_D0;
    f32 m_d4;
    u16 owner_id;  // get_entity_id of the owner, find_entity_by_id'd on impact
    u8 pad_DA[0x2];
    s32 m_dc;
    Vec unk_E0;
    s32 m_ec;
};
typedef char TUnk_8049442C_size[sizeof(TUnk_8049442C) == 0xF0 ? 1 : -1];

#endif
