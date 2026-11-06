#ifndef PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_BOMB_H
#define PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_BOMB_H
#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class TObjEneRe2Flower_Bomb : public TUnk_804928CC {
public:
    virtual ~TObjEneRe2Flower_Bomb();
    virtual s32 area_attack_deliver_direct(void *, s32, void *, f32);
    void *destroy_and_free(s16);
    virtual void render();
    virtual void run_task();
    u8 unk_B0[0x8];
    s16 m_b8; // 0xB8
    u8 unk_BA[0x42];
    void * m_fc;
    s32 m_100;
};
typedef char TObjEneRe2Flower_Bomb_size[sizeof(TObjEneRe2Flower_Bomb) == 0x104 ? 1 : -1];

#endif
