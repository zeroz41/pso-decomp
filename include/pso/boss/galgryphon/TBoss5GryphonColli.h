#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONCOLLI_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TBoss5GryphonColli : public TObject {
public:
    TObject *objects[1];
public:
    virtual ~TBoss5GryphonColli();
};

typedef char TBoss5GryphonColliObjectsOffset[offsetof(TBoss5GryphonColli, objects) == 0x1C ? 1 : -1];

extern "C" {
u8 *TBoss5GryphonColli__ct(u8 *object, s32 arg1);
}

#endif
