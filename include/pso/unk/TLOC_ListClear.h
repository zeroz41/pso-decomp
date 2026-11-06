#ifndef PSO_UNK_TLOC_LISTCLEAR_H
#define PSO_UNK_TLOC_LISTCLEAR_H
#include "types.h"
#include "pso/unk/TUnk_804A7260.h"

class TLOC_ListClear : public TUnk_804A7260 {
public:
    virtual ~TLOC_ListClear();
    void*init_lockon();
    virtual void run_task();
    u8 unk_1C[0x8];
};
typedef char TLOC_ListClear_size[sizeof(TLOC_ListClear) == 0x24 ? 1 : -1];

#endif
