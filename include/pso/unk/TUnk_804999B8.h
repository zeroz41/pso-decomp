#ifndef PSO_UNK_TUNK_804999B8_H
#define PSO_UNK_TUNK_804999B8_H
#include "types.h"
#include "pso/boss/TUnk_804999E8.h"

// Screen fade task that fades out from alpha 255 to 0.
class TUnk_804999B8 : public TUnk_804999E8 {
public:
    // parent is not used: the fade always lives under tl_fade.
    TUnk_804999B8(TObject *parent, void (*callback)(TObject *fade));
    virtual ~TUnk_804999B8();
    virtual void run_task();
    void (*callback)(TObject *fade); // called with the fade once it ends
};
LAYOUT_ASSERT(TUnk_804999B8_size, sizeof(TUnk_804999B8) == 0x28);

#endif
