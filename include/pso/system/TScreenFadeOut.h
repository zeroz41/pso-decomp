#ifndef PSO_SYSTEM_TSCREENFADEOUT_H
#define PSO_SYSTEM_TSCREENFADEOUT_H
#include "types.h"
#include "pso/system/TScreenFade.h"

// Screen fade task that fades in from alpha 0 to 255.
class TScreenFadeOut : public TScreenFade {
public:
    // parent is not used: the fade always lives under tl_fade.
    TScreenFadeOut(TObject *parent, void (*callback)(TObject *fade));
    virtual ~TScreenFadeOut();
    virtual void run_task();
    void (*callback)(TObject *fade); // called with the fade once it ends
};
LAYOUT_ASSERT(TScreenFadeOut_size, sizeof(TScreenFadeOut) == 0x28);

#endif
