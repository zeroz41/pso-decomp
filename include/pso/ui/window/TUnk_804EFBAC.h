#ifndef PSO_UI_WINDOW_TUNK_804EFBAC_H
#define PSO_UI_WINDOW_TUNK_804EFBAC_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TUnk_804EFBAC : public TWindowBase {
public:
    virtual ~TUnk_804EFBAC();
    u8 unk_1C[0x50];
};
typedef char TUnk_804EFBAC_size[sizeof(TUnk_804EFBAC) == 0x6C ? 1 : -1];

#endif
