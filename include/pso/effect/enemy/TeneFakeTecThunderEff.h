#ifndef PSO_EFFECT_ENEMY_TENEFAKETECTHUNDEREFF_H
#define PSO_EFFECT_ENEMY_TENEFAKETECTHUNDEREFF_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TeneFakeTecThunderEff : public TObject {
public:
    virtual ~TeneFakeTecThunderEff();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x1C];
    s32 m_38;
    u8 unk_3C[0x2EC];
    s32 m_328;
    u8 unk_32C[0x4];
    s32 m_330;
    u8 unk_334[0x4];
    s32 m_338;
    u8 unk_33C[0x4];
    s32 m_340;
    u8 unk_344[0x4];
};
typedef char TeneFakeTecThunderEff_size[sizeof(TeneFakeTecThunderEff) == 0x348 ? 1 : -1];

extern "C" {
u8 *TObjPlayer__sub_800A4204(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
void *__dt__21TeneFakeTecThunderEffFv(void *arg0, s16 arg1);
}

#endif
