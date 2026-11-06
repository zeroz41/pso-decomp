#ifndef PSO_UNK_TLOC_START_H
#define PSO_UNK_TLOC_START_H
#include "types.h"
#include "pso/unk/TUnk_804A7260.h"

class TLOC_Start : public TUnk_804A7260 {
public:
    virtual ~TLOC_Start();
    void*init();
    virtual void run_task();
    u8 unk_1C[0x8];
};
typedef char TLOC_Start_size[sizeof(TLOC_Start) == 0x24 ? 1 : -1];

#endif
