#ifndef PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_EFFCURSE3_H
#define PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_EFFCURSE3_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjEneRe2Flower_EffCurse3 : public TObject {
public:
    TObjEneRe2Flower_EffCurse3(s32 arg1, s32 arg2);
    virtual ~TObjEneRe2Flower_EffCurse3();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
};
typedef char TObjEneRe2Flower_EffCurse3_size[sizeof(TObjEneRe2Flower_EffCurse3) == 0x28 ? 1 : -1];

#endif
