#ifndef PSO_MISC_TWINDOWCHATSYMBOL_H
#define PSO_MISC_TWINDOWCHATSYMBOL_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowChatSymbol : public TWindowBase {
    virtual ~TWindowChatSymbol();
    virtual void render();
    u8 unk_1C[0x4];
    void * m_20;
    void* m_24;
    u8 unk_28[0x4];
    s32 m_2c;
    u8 unk_30[0x18];
    f32 m_48;
    u8 unk_4C[0x10];
    u32 m_5c;
    u32 m_60;
    u32 m_64;
    virtual void run_task();
    void *destroy(s16 arg1);
};

typedef char TWindowChatSymbol_size[sizeof(TWindowChatSymbol) == 0x68 ? 1 : -1];
#endif
