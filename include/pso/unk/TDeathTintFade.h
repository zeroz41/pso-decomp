#ifndef PSO_UNK_TDEATHTINTFADE_H
#define PSO_UNK_TDEATHTINTFADE_H
#include "types.h"
#include "pso/unk/TScreenFade.h"

// Window tint fade that player death starts: alpha climbs to 128, the tint
// goes to the window of viewport_index, then the callback runs.
class TDeathTintFade : public TScreenFade {
public:
    TDeathTintFade(TObject *parent, void (*callback)(), s32 viewport_index);
    virtual ~TDeathTintFade();
    virtual void run_task();
    virtual void render();
    s32 viewport_index; // passed to TWindowCtrlMain::set_value
    void (*callback)(); // called once alpha reaches 128
};
LAYOUT_ASSERT(TDeathTintFade_size, sizeof(TDeathTintFade) == 0x2C);

#endif
