#ifndef PSO_UNK_TSCREENFADEIN_H
#define PSO_UNK_TSCREENFADEIN_H
#include "types.h"
#include "pso/unk/TScreenFade.h"

// Screen fade task that fades out from alpha 255 to 0.
class TScreenFadeIn : public TScreenFade {
public:
    // parent is not used: the fade always lives under tl_fade.
    TScreenFadeIn(TObject *parent, void (*callback)(TObject *fade));
    virtual ~TScreenFadeIn();
    virtual void run_task();
    void (*callback)(TObject *fade); // called with the fade once it ends
};
LAYOUT_ASSERT(TScreenFadeIn_size, sizeof(TScreenFadeIn) == 0x28);

#endif
