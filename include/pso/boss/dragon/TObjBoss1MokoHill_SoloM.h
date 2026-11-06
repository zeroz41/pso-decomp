#ifndef PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLOM_H
#define PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLOM_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjBoss1MokoHill_SoloM : public TObject {
public:
    virtual ~TObjBoss1MokoHill_SoloM();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x10];
    f32 m_2c;
    u8 unk_30[0x4];
    f32 m_34;
    u8 unk_38[0x4];
    s32 m_3c;
};
typedef char TObjBoss1MokoHill_SoloM_size[sizeof(TObjBoss1MokoHill_SoloM) == 0x40 ? 1 : -1];

#endif
