#ifndef PSO_UNK_TUNK_804C349C_H
#define PSO_UNK_TUNK_804C349C_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C349C : public TObject {
public:
    virtual ~TUnk_804C349C();
    void update_and_destroy();
    virtual void run_task();
    u8 unk_1C[0x1C];
    s32 m_38;
    u8 unk_3C[0x10];
    s32 m_4c;
    u8 unk_50[0x48];
};
typedef char TUnk_804C349C_size[sizeof(TUnk_804C349C) == 0x98 ? 1 : -1];

#endif
