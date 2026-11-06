#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLIGHT_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLIGHT_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjEneMe1Canadin_EffLight : public TObject {
public:
    TObjEneMe1Canadin_EffLight(TObject *parent, s32 count);
    virtual ~TObjEneMe1Canadin_EffLight();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0xC];
    void * m_28;
    u8 unk_2C[0xC];
};
typedef char TObjEneMe1Canadin_EffLight_size[sizeof(TObjEneMe1Canadin_EffLight) == 0x38 ? 1 : -1];

#endif
