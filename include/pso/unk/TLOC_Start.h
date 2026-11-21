#ifndef PSO_UNK_TLOC_START_H
#define PSO_UNK_TLOC_START_H
#include "types.h"
#include "pso/unk/TUnk_804A7260.h"

class TLOC_Start : public TUnk_804A7260 {
public:
    TLOC_Start(TObject *parent, u16 id);
    virtual ~TLOC_Start();
    virtual void run_task();
};
LAYOUT_ASSERT(TLOC_Start_size, sizeof(TLOC_Start) == 0x24);

#endif
