#ifndef PSO_UI_WINDOW_TUNK_804EFBAC_H
#define PSO_UI_WINDOW_TUNK_804EFBAC_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TUnk_804EFBAC : public TWindowBase {
public:
    virtual ~TUnk_804EFBAC();
    s32 pad_60; // nonzero hides the selected row's highlight
    s32 pad_64; // rows below this index draw grey, the rest white
    s32 pad_68; // selected row
};
typedef char TUnk_804EFBAC_size[sizeof(TUnk_804EFBAC) == 0x6C ? 1 : -1];

#endif
