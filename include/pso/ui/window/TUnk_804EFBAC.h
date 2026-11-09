#ifndef PSO_UI_WINDOW_TUNK_804EFBAC_H
#define PSO_UI_WINDOW_TUNK_804EFBAC_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TUnk_804EFBAC : public TWindowBase {
public:
    virtual ~TUnk_804EFBAC();
    u8 pad_1C[0x38];
    f32 pad_54; // depth: fed to the 0.299 depth helper TWindowDD__sub_80348AD4 by its render (0x8034055C)
    u8 pad_58[4];
    s32 pad_5C;
    s32 pad_60; // nonzero hides the selected row's highlight
    s32 pad_64; // rows below this index draw grey, the rest white
    s32 pad_68; // selected row
};
typedef char TUnk_804EFBAC_size[sizeof(TUnk_804EFBAC) == 0x6C ? 1 : -1];

#endif
