#ifndef PSO_BOSS_TUNK_80482C58_H
#define PSO_BOSS_TUNK_80482C58_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_80482C58 : public TObject {
public:
    TUnk_80482C58(TObject *parent, s32 arg2, s32 arg3);
    virtual ~TUnk_80482C58();
    virtual void run_task();
    u8 unk_1C[0x100];
    void * m_11c;
    u8 unk_120[0x4];
};
typedef char TUnk_80482C58_size[sizeof(TUnk_80482C58) == 0x124 ? 1 : -1];

#endif
