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

extern "C" {
// The weapon's hit callback (hit_callback).
void TObjPlayer__sub_80128A74(s32 a, u32 b, s32 c, s32 d);
void *__dt__13TUnk_804A403CFv(void *arg0, s16 arg1);
}

#endif
