#ifndef PSO_UNK_TUNK_804C2298_H
#define PSO_UNK_TUNK_804C2298_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C2298 : public TObject {
public:
    TUnk_804C2298();
    virtual ~TUnk_804C2298();
    void *destroy(s16);
    void sub_801A4CA4();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x2];
    u16 m_1e;
    s32 m_20;
    u8 unk_24[0x4];
    void * m_28;
    u8 unk_2C[0x4];
};
typedef char TUnk_804C2298_size[sizeof(TUnk_804C2298) == 0x30 ? 1 : -1];

#endif
