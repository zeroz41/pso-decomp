#ifndef PSO_UNK_TUNK_804EFA88_H
#define PSO_UNK_TUNK_804EFA88_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

// One indirect-effect draw record (0x24 bytes): render() draws each queued record.
struct IndirectDrawRecord {
    u8 a[0xC];
    u8 b[0xC];
    NJS_TEXLIST *texlist;
    void *model;
    u16 scene;
    u8 effect_kind;  // indirect effect kind
    u8 pad23;
};

// Empties a record: drops its texture list and model.
void clear_draw_record(IndirectDrawRecord *record);

class TUnk_804EFA88 : public TObject {
public:
    TUnk_804EFA88(TObject *parent);
    virtual ~TUnk_804EFA88();
    virtual void run_task();
    virtual void render();
    IndirectDrawRecord *entries;  // 16 records, mem_alloc(0x240) by the constructor
    s32 entry_count;
};
LAYOUT_ASSERT(TUnk_804EFA88_size, sizeof(TUnk_804EFA88) == 0x24);

#endif
