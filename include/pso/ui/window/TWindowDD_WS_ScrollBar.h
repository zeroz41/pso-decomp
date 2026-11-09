#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_SCROLLBAR_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_SCROLLBAR_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowDD_WS_ScrollBar : public TWindowBase {
public:
    virtual ~TWindowDD_WS_ScrollBar();
    void *dt(s16);
    u8 unk_1C[0x24];
    f32 pad_40; // bar rectangle x, y, w, h (read by its render 0x80340A78)
    f32 pad_44;
    f32 pad_48;
    f32 pad_4C;
    u8 pad_50[4];
    f32 pad_54; // depth: fed to the depth helper TWindowDD__sub_80348AD4 by its render
    u8 pad_58[8];
    f32 pad_60; // thumb length = track * pad_60 * pad_68; offset = track * pad_60 * pad_6C
    f32 pad_64; // no thumb travel while pad_64 <= pad_68
    f32 pad_68;
    f32 pad_6C;
};

extern "C" {
void TWindowDD__sub_80340A78(TWindowDD_WS_ScrollBar *self);
}
typedef char TWindowDD_WS_ScrollBar_size[sizeof(TWindowDD_WS_ScrollBar) == 0x70 ? 1 : -1];

#endif
