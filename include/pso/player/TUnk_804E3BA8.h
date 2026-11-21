#ifndef PSO_PLAYER_TUNK_804E3BA8_H
#define PSO_PLAYER_TUNK_804E3BA8_H
#include "types.h"
#include "pso/player/TUnk_804E3BD8.h"

class TUnk_804E3BA8 : public TUnk_804E3BD8 {
public:
    virtual ~TUnk_804E3BA8();
    virtual void run_task();
    virtual void render();
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x4];
    f32 m_38;
};
LAYOUT_ASSERT(TUnk_804E3BA8_size, sizeof(TUnk_804E3BA8) == 0x3C);

#endif
