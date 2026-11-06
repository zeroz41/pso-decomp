#ifndef PSO_UI_TUNK_804F3A20_H
#define PSO_UI_TUNK_804F3A20_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F3A20 : public TObject {
public:
    TUnk_804F3A20(TObject *arg1);
    virtual ~TUnk_804F3A20();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    s32 m_28;
    u8 unk_2C[0x4];
    s32 m_30;
    u8 unk_34[0x4];
};
typedef char TUnk_804F3A20_size[sizeof(TUnk_804F3A20) == 0x38 ? 1 : -1];

#endif
