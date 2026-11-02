#ifndef PSO_ITEM_TUNK_804A403C_H
#define PSO_ITEM_TUNK_804A403C_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

class TUnk_804A403C : public TUnk_804A4948 {
public:
    virtual ~TUnk_804A403C();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    void *init_event_callbacks();
    u8 unk_1C[0x1DC];
};

#endif
