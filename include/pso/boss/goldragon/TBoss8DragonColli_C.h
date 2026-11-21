#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_C_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONCOLLI_C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TBoss8DragonColli_C : public TObjCollidable {
public:
    TBoss8DragonColli_C(TObject *parent, s32 count, Vec *offset, f32 scale);
    virtual ~TBoss8DragonColli_C();
    void clear_segment_flags();
    virtual void render();
    Vec unk_AC;
};
LAYOUT_ASSERT(TBoss8DragonColli_C_size, sizeof(TBoss8DragonColli_C) == 0xB8);

#endif
