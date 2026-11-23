#ifndef PSO_PLAYER_TUNK_804E3BA8_H
#define PSO_PLAYER_TUNK_804E3BA8_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/player/TUnk_804E3BD8.h"

class TUnk_804E3BA8 : public TUnk_804E3BD8 {
public:
    TUnk_804E3BA8(TObject *parent, GC_Mtx *matrices);
    virtual ~TUnk_804E3BA8();
    virtual void run_task();
    virtual void render();
    GC_Mtx *matrices;   // the boss's node matrices
    Vec pivot;          // origin transformed by the first matrix; render draws around it

};
LAYOUT_ASSERT(TUnk_804E3BA8_size, sizeof(TUnk_804E3BA8) == 0x3C);

#endif
