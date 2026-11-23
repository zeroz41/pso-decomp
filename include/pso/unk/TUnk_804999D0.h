#ifndef PSO_UNK_TUNK_804999D0_H
#define PSO_UNK_TUNK_804999D0_H
#include "types.h"
#include "pso/boss/TUnk_804999E8.h"

// Screen fade task that fades in from alpha 0 to 255.
class TUnk_804999D0 : public TUnk_804999E8 {
public:
    // parent is not used: the fade always lives under tl_fade.
    TUnk_804999D0(TObject *parent, void (*callback)(TObject *fade));
    virtual ~TUnk_804999D0();
    virtual void run_task();
    void (*callback)(TObject *fade); // called with the fade once it ends
};
LAYOUT_ASSERT(TUnk_804999D0_size, sizeof(TUnk_804999D0) == 0x28);

#endif
