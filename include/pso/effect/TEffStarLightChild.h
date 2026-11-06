#ifndef PSO_TEFFSTARLIGHTCHILD_H
#define PSO_TEFFSTARLIGHTCHILD_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/unk/TLobby_801E2F94.h"

class TEffStarLightChild : public TObject {
public:
    virtual ~TEffStarLightChild();
    virtual void run_task();
public:
    virtual void render();
    f32 shrink_distance;
    ColorLineVertex edges[2];
};

typedef char TEffStarLightChildSize[sizeof(TEffStarLightChild) == 0x30 ? 1 : -1];

#endif
