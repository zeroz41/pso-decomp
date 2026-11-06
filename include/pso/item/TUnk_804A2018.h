#ifndef PSO_ITEM_TUNK_804A2018_H
#define PSO_ITEM_TUNK_804A2018_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804A2018 : public TObject {
public:
    TUnk_804A2018(TObject *parent, s32 a, s32 b);
    virtual ~TUnk_804A2018();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    u32 m_28;
};
typedef char TUnk_804A2018_size[sizeof(TUnk_804A2018) == 0x2C ? 1 : -1];

#endif
