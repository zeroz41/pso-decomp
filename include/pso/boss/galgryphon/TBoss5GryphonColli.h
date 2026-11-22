#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli_C.h"
#include <stddef.h>

// The Gal Gryphon's blocking sphere chain.
class TBoss5GryphonColli : public TObject {
public:
    TBoss5GryphonColli_C *objects[1];
public:
    TBoss5GryphonColli(TObject *parent);
    virtual ~TBoss5GryphonColli();
    void enable_blocking_bodies(Vec *pos, s32 angle);
    void disable_blocking_bodies();
};

LAYOUT_ASSERT(TBoss5GryphonColliObjectsOffset, offsetof(TBoss5GryphonColli, objects) == 0x1C);

#endif
