#ifndef PSO_SYSTEM_TDEATHTINTFADE_H
#define PSO_SYSTEM_TDEATHTINTFADE_H
#include "types.h"
#include "pso/system/TScreenFade.h"

// Window tint fade that player death starts: alpha climbs to 128, the tint
// goes to the window of viewport_index, then the callback runs.
class TDeathTintFade : public TScreenFade {
public:
    TDeathTintFade(TObject *parent, void (*callback)(TDeathTintFade *fade), s32 viewport_index);
    virtual ~TDeathTintFade();
    virtual void run_task();
    virtual void render();
    s32 get_viewport_index();
    s32 viewport_index; // passed to TWindowCtrlMain::set_fill_color
    void (*callback)(TDeathTintFade *fade); // called once alpha reaches 128
};
LAYOUT_ASSERT(TDeathTintFade_size, sizeof(TDeathTintFade) == 0x2C);

#endif
