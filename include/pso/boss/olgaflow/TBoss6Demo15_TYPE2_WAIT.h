#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO15_TYPE2_WAIT_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO15_TYPE2_WAIT_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss6Demo15_TYPE2_WAIT : public TObject {
public:
    virtual ~TBoss6Demo15_TYPE2_WAIT();
    void advance_offset();
    void *destroy(s16);
    void check_any_player_near();
    void sub_8033FE30();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    u8 * m_20;
    u8 unk_24[0x1C];
    f32 m_40;
    u8 unk_44[0x4];
    f32 m_48;
    u8 unk_4C[0xC];
    void * m_58;
    u8 unk_5C[0x4];
    TObject *csn_objects[10]; // TObjMapCsn objects (fn_8034009C creates them)
};
typedef char TBoss6Demo15_TYPE2_WAIT_size[sizeof(TBoss6Demo15_TYPE2_WAIT) == 0x88 ? 1 : -1];

#endif
