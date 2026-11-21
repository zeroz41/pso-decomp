#ifndef PSO_UNK_TLOC_END_H
#define PSO_UNK_TLOC_END_H
#include "types.h"
#include "pso/unk/TUnk_804A7260.h"

class TLOC_End : public TUnk_804A7260 {
public:
    TLOC_End(TObject *parent, u16 id);
    virtual ~TLOC_End();
    virtual void run_task();
};
LAYOUT_ASSERT(TLOC_End_size, sizeof(TLOC_End) == 0x24);

#endif
