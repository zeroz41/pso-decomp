#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TBoss5GryphonColli : public TObject {
public:
    TObject *objects[1];
public:
    TBoss5GryphonColli(TObject *parent);
    virtual ~TBoss5GryphonColli();
};

LAYOUT_ASSERT(TBoss5GryphonColliObjectsOffset, offsetof(TBoss5GryphonColli, objects) == 0x1C);

#endif
