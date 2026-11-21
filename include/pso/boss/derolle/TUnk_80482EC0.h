#ifndef PSO_BOSS_DEROLLE_TUNK_80482EC0_H
#define PSO_BOSS_DEROLLE_TUNK_80482EC0_H
#include "types.h"
#include "pso/boss/derolle/TBoss2Mine.h"

class TUnk_80482EC0 : public TBoss2Mine {
public:
    TUnk_80482EC0(TObject *parent, u16 entity_id, s32 set_index);
    virtual ~TUnk_80482EC0();
    virtual void state_launch(s32 reason);
    virtual void state_armed(s32 reason);
    virtual void update_body_colliders();
};
LAYOUT_ASSERT(TUnk_80482EC0_size, sizeof(TUnk_80482EC0) == 0x3F0);

#endif
