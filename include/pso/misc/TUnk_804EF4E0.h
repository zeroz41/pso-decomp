#ifndef PSO_MISC_TUNK_804EF4E0_H
#define PSO_MISC_TUNK_804EF4E0_H

#include "pso/misc/TUnk_804D0948.h"

class TUnk_804EF4E0 : public TUnk_804D0948 {
public:
    struct Entry {
        u8 unk_00[0xC];
        f32 m_0c;
    };

    virtual ~TUnk_804EF4E0();
    virtual void vfunc_6(u32 count, s32 id);
};

typedef char TUnk_804EF4E0_size[sizeof(TUnk_804EF4E0) == 0x8C ? 1 : -1];

#endif
