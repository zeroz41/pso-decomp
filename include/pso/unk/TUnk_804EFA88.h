#ifndef PSO_UNK_TUNK_804EFA88_H
#define PSO_UNK_TUNK_804EFA88_H
#include "types.h"
#include "pso/system/task/TObject.h"

// One indirect-effect draw record (0x24 bytes): render() draws each queued record.
struct Item_8033EB4C {
    u8 a[0xC];
    u8 b[0xC];
    s32 p18;
    s32 p1C;
    u16 scene;
    u8 effect_kind;  // indirect effect kind
    u8 pad23;
};

class TUnk_804EFA88 : public TObject {
public:
    TUnk_804EFA88(TObject *parent);
    virtual ~TUnk_804EFA88();
    virtual void run_task();
    virtual void render();
    Item_8033EB4C *entries;  // 16 records, mem_alloc(0x240) by the constructor
    s32 entry_count;
};
LAYOUT_ASSERT(TUnk_804EFA88_size, sizeof(TUnk_804EFA88) == 0x24);

#endif
