#ifndef PSO_BOSS_DEROLLE_TBOSS2FLOORMINE_H
#define PSO_BOSS_DEROLLE_TBOSS2FLOORMINE_H
#include "types.h"
#include "pso/boss/derolle/TBoss2Mine.h"

class TBoss2FloorMine : public TBoss2Mine {
public:
    TBoss2FloorMine(TObject *parent, u16 entity_id, s32 set_index);
    virtual ~TBoss2FloorMine();
    virtual void state_launch(s32 reason);
    virtual void state_armed(s32 reason);
    virtual void update_body_colliders();
};
LAYOUT_ASSERT(TBoss2FloorMine_size, sizeof(TBoss2FloorMine) == 0x3F0);

#endif
