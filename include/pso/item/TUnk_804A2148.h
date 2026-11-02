#ifndef PSO_ITEM_TUNK_804A2148_H
#define PSO_ITEM_TUNK_804A2148_H
#include "types.h"
#include "pso/TItemShootModel.h"

class TUnk_804A2148 : public TItemShootModel {
public:
    virtual ~TUnk_804A2148();
    virtual void hook();
    virtual void render();
};
typedef char TUnk_804A2148_size[sizeof(TUnk_804A2148) == 0x6C ? 1 : -1];

#endif
