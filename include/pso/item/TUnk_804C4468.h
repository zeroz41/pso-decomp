#ifndef PSO_ITEM_TUNK_804C4468_H
#define PSO_ITEM_TUNK_804C4468_H
#include "types.h"
#include "pso/item/TUnk_804C4498.h"

class TUnk_804C4468 : public TUnk_804C4498 {
public:
    virtual ~TUnk_804C4468();
    void sub_801D591C();
    s32 get_client_id();
    virtual void run_task();
    u8 unk_54[0x4];
};
typedef char TUnk_804C4468_size[sizeof(TUnk_804C4468) == 0x58 ? 1 : -1];

#endif
