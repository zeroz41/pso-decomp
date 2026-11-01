#ifndef PSO_MISC_TWINDOWDD_WS_SCROLLBAR_H
#define PSO_MISC_TWINDOWDD_WS_SCROLLBAR_H
#include "types.h"
#include "pso/misc/TWindowBase.h"

class TWindowDD_WS_ScrollBar : public TWindowBase {
public:
    virtual ~TWindowDD_WS_ScrollBar();
    void *dt(s16);
    u8 unk_1C[0x54];
};
typedef char TWindowDD_WS_ScrollBar_size[sizeof(TWindowDD_WS_ScrollBar) == 0x70 ? 1 : -1];

#endif
