#ifndef PSO_ITEM_TUNK_804C4468_H
#define PSO_ITEM_TUNK_804C4468_H
#include "types.h"
#include "pso/item/TUnk_804C4498.h"

class TUnk_804C4468 : public TUnk_804C4498 {
public:
    TUnk_804C4468(TObject *parent, s32 list, TObjBase *source, const Vec *pos, s8 arg);
    virtual ~TUnk_804C4468();
    void sub_801D591C();
    u16 get_client_id();
    virtual void run_task();
    s32 unk_54;
};
typedef char TUnk_804C4468_size[sizeof(TUnk_804C4468) == 0x58 ? 1 : -1];

#endif
