#ifndef PSO_PLAYER_TUNK_804A4138_H
#define PSO_PLAYER_TUNK_804A4138_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

class TUnk_804A4138 : public TUnk_804A4948 {
public:
    virtual ~TUnk_804A4138();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    u8 unk_1C[0x1E4];
};

#endif
