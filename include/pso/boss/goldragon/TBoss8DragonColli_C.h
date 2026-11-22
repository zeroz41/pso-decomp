#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_C_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// One of the Gol Dragon's blocking sphere chains, as TBoss1DragonColli_C.
class TBoss8DragonColli_C : public TObjCollidable {
public:
    TBoss8DragonColli_C(TObject *parent, s32 count, Vec *offset, f32 scale);
    virtual ~TBoss8DragonColli_C();
    void set_segment_flags();
    void clear_segment_flags();
    void enable_at(Vec *pos, s32 angle);
    void disable();
    virtual void render();
    Vec local_position;  // the chain's center relative to the dragon (enable_at places it)
};
LAYOUT_ASSERT(TBoss8DragonColli_C_size, sizeof(TBoss8DragonColli_C) == 0xB8);

#endif
