#ifndef PSO_PLAYER_TUNK_804E3BC0_H
#define PSO_PLAYER_TUNK_804E3BC0_H
#include "types.h"
#include "pso/player/TUnk_804E3BD8.h"

class TUnk_804E3BC0 : public TUnk_804E3BD8 {
public:
    TUnk_804E3BC0(TObject *parent, Vec *position, s32 index);
    virtual ~TUnk_804E3BC0();
    void sub_802E7640();
    virtual void run_task();
    virtual void render();
};
LAYOUT_ASSERT(TUnk_804E3BC0_size, sizeof(TUnk_804E3BC0) == 0x2C);

#endif
