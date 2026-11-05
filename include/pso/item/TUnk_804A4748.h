#ifndef PSO_ITEM_TUNK_804A4748_H
#define PSO_ITEM_TUNK_804A4748_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

class TUnk_804A4748 : public TUnk_804A4948 {
public:
    virtual ~TUnk_804A4748();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    void *setup_action();
    u8 unk_1C[0x1D8];
};

extern "C" {
void *__dt__13TUnk_804A4748Fv(void *arg0, s16 arg1);
}

#endif
