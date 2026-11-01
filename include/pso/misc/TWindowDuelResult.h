#ifndef PSO_MISC_TWINDOWDUELRESULT_H
#define PSO_MISC_TWINDOWDUELRESULT_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowDuelResult : public TWindowBase {
    virtual ~TWindowDuelResult();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 _pad28[0x40];
    u32 m_68;
    void *init(void *arg1, void *arg2, void *arg3);
    static int set_default_status(void* p, int a1);
};

typedef char TWindowDuelResult_size[sizeof(TWindowDuelResult) == 0x6C ? 1 : -1];
#endif
