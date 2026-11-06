#ifndef PSO_BOSS_TUNK_804835D8_H
#define PSO_BOSS_TUNK_804835D8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804835D8 : public TObject {
public:
    virtual ~TUnk_804835D8();
    void *init();
    virtual void run_task();
    u8 unk_1C[0x4];
    f32 m_20;
};
typedef char TUnk_804835D8_size[sizeof(TUnk_804835D8) == 0x24 ? 1 : -1];

#endif
