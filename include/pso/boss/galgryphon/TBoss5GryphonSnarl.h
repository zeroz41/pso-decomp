#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONSNARL_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONSNARL_H
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include <stddef.h>
class TBoss5GryphonSnarl : public TObject {
public:
    TBoss5GryphonSnarl(TObject *parent, void *arg2);
    virtual ~TBoss5GryphonSnarl();
    virtual void run_task();
    virtual void render();
    s32 state;
    TObject *children_20[32];
    TObject *children_a0[32];
    Vec position;
    s32 frame;
public:
};
LAYOUT_ASSERT(TBoss5GryphonSnarlChildren20, offsetof(TBoss5GryphonSnarl, children_20) == 0x20);
LAYOUT_ASSERT(TBoss5GryphonSnarlChildrenA0, offsetof(TBoss5GryphonSnarl, children_a0) == 0xA0);
LAYOUT_ASSERT(TBoss5GryphonSnarlPosition, offsetof(TBoss5GryphonSnarl, position) == 0x120);
LAYOUT_ASSERT(TBoss5GryphonSnarlSize, sizeof(TBoss5GryphonSnarl) == 0x130);

extern "C" {
void TBoss5GryphonSnarl__sub_80066E84(void);
void TBoss5GryphonSnarl__sub_80066E88(void);
void TLobby__sub_80066EC0(void);
}

// --- C functions defined in TBoss5GryphonSnarl.cpp ---
extern "C" {
void TBoss5GryphonSnarl__sub_80066E84(void);
void TBoss5GryphonSnarl__sub_80066E88(void);
void TLobby__sub_80066EC0(void);
}
// --- end of C functions

#endif
