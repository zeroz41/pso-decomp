#ifndef PSO_UI_WINDOW_TUNK_804EF4E0_H
#define PSO_UI_WINDOW_TUNK_804EF4E0_H

#include "pso/ui/window/TUnk_804D0948.h"

// Named from the "TWindowMenuTeamStatus" class-name string vfunc_6 stores to m_name.
class TWindowMenuTeamStatus : public TWindowShop {
public:
    struct Entry {
        u8 unk_00[0xC];
        f32 m_0c;
    };

    TWindowMenuTeamStatus(s32 arg);
    virtual ~TWindowMenuTeamStatus();
    virtual void vfunc_6(u32 count, s32 id);
};

LAYOUT_ASSERT(TWindowMenuTeamStatus_size, sizeof(TWindowMenuTeamStatus) == 0x8C);

#endif
