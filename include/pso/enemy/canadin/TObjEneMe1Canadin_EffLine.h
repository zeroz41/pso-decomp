#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINE_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFLINE_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjEneMe1Canadin_EffLine : public TObject {
public:
    virtual ~TObjEneMe1Canadin_EffLine();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x1C];
    s32 m_40;
    u8 unk_44[0x4];
};
typedef char TObjEneMe1Canadin_EffLine_size[sizeof(TObjEneMe1Canadin_EffLine) == 0x48 ? 1 : -1];

#endif
