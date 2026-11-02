#ifndef PSO_PLAYER_TUNK_804F27E0_H
#define PSO_PLAYER_TUNK_804F27E0_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

class TUnk_804F27E0 : public TUnk_804A4948 {
public:
    virtual ~TUnk_804F27E0();
    virtual void vfunc_60();
    virtual void update_weapon();
    virtual void reserved_53();
    void *enter_state_804F27E0(s32, void *);
    virtual void emit_marker_effects();
    u8 unk_1C[0x1E4];
};

#endif
