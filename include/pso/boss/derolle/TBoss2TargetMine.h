#ifndef PSO_BOSS_DEROLLE_TBOSS2TARGETMINE_H
#define PSO_BOSS_DEROLLE_TBOSS2TARGETMINE_H
#include "types.h"
#include "pso/boss/derolle/TBoss2Mine.h"

class TBoss2TargetMine : public TBoss2Mine {
public:
    TBoss2TargetMine(TObject *parent, u16 entity_id, s32 set_index);
    virtual ~TBoss2TargetMine();
    virtual void state_launch(s32 reason);
    virtual void state_armed(s32 reason);
    void move_mine();
    void init_launch(Vec *pos, TObjBase *owner, s32 slot);
    virtual void update_body_colliders();
    // Set by init_launch and followed by move_mine (names inferred):
    TObjBase *owner;     // the object the mine rides on
    s32 slot;           // its launch slot, 0-2
    Vec owner_offset;   // where it sits relative to the owner
    Vec direction;      // its launch direction
};
LAYOUT_ASSERT(TBoss2TargetMine_size, sizeof(TBoss2TargetMine) == 0x410);

#endif
