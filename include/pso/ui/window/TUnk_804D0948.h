#ifndef PSO_UI_WINDOW_TUNK_804D0948_H
#define PSO_UI_WINDOW_TUNK_804D0948_H
#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

// Named from the "TWindowShop" class-name string both constructors (via sub_8026DE94) store to m_name.
class TWindowShop : public TWindowMenuIconLine {
public:
    TWindowShop(u8 *parent, s32 arg, u32 count, u8 *descriptor);
    TWindowShop(s32 arg, u32 count, s32 client);
    virtual ~TWindowShop();
    void sub_8026DE94(s32 arg);
    virtual void render();
    virtual void run_task();
    s32 unk_88;
};
typedef char TWindowShop_size[sizeof(TWindowShop) == 0x8C ? 1 : -1];

#endif
