#ifndef PSO_UNK_TUNK_804EFA88_H
#define PSO_UNK_TUNK_804EFA88_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EFA88 : public TObject {
public:
    virtual ~TUnk_804EFA88();
    virtual void run_task();
    virtual void render();
    u8 unk_1C[0x4];
    s32 m_20;
};
typedef char TUnk_804EFA88_size[sizeof(TUnk_804EFA88) == 0x24 ? 1 : -1];

#endif
