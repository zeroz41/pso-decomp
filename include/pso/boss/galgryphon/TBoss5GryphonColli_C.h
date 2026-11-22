#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_C_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TBoss5GryphonColli_C : public TObjCollidable {
public:
    TBoss5GryphonColli_C(TObject *parent, s32 count, const Vec *pos, f32 len);
    virtual ~TBoss5GryphonColli_C();
    void set_segment_flags();
    void clear_segment_flags();
    void enable_at(Vec *pos, s32 angle);
    void disable();
    virtual void render();
    Vec local_position;  // the chain's center relative to the gryphon (enable_at places it)
};
LAYOUT_ASSERT(TBoss5GryphonColli_C_size, sizeof(TBoss5GryphonColli_C) == 0xB8);

#endif
