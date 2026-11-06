#ifndef PSO_UNK_TUNK_804EEF80_H
#define PSO_UNK_TUNK_804EEF80_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EEF80 : public TObject {
public:
    virtual ~TUnk_804EEF80();
    void *construct(void *);
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
};
typedef char TUnk_804EEF80_size[sizeof(TUnk_804EEF80) == 0x24 ? 1 : -1];

#endif
