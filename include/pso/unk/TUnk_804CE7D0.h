#ifndef PSO_UNK_TUNK_804CE7D0_H
#define PSO_UNK_TUNK_804CE7D0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CE7D0 : public TObject {
public:
    virtual ~TUnk_804CE7D0();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
};
typedef char TUnk_804CE7D0_size[sizeof(TUnk_804CE7D0) == 0x24 ? 1 : -1];

#endif
