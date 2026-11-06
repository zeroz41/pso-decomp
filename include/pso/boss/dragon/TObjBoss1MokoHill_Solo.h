#ifndef PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLO_H
#define PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLO_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjBoss1MokoHill_Solo : public TObject {
public:
    virtual ~TObjBoss1MokoHill_Solo();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0xC];
    f32 m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x14];
    s32 m_48;
    u8 unk_4C[0x4];
};
typedef char TObjBoss1MokoHill_Solo_size[sizeof(TObjBoss1MokoHill_Solo) == 0x50 ? 1 : -1];

#endif
