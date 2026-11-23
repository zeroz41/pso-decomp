#ifndef PSO_UNK_TUNK_804999A0_H
#define PSO_UNK_TUNK_804999A0_H
#include "types.h"
#include "pso/boss/TUnk_804999E8.h"

// Window tint fade that player death starts: alpha climbs to 128, the tint
// goes to the window of viewport_index, then the callback runs.
class TUnk_804999A0 : public TUnk_804999E8 {
public:
    TUnk_804999A0(TObject *parent, void (*callback)(), s32 viewport_index);
    virtual ~TUnk_804999A0();
    virtual void run_task();
    virtual void render();
    s32 viewport_index; // passed to TWindowCtrlMain::set_value
    void (*callback)(); // called once alpha reaches 128
};
LAYOUT_ASSERT(TUnk_804999A0_size, sizeof(TUnk_804999A0) == 0x2C);

#endif
