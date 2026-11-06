#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONSHOCKWAVE_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONSHOCKWAVE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss5GryphonShockWave : public TObject {
    TBoss5GryphonShockWave(TObject *arg1_parent, s32 arg2, u8 *arg3, u8 *arg4, s32 arg5, s16 arg6);
    virtual ~TBoss5GryphonShockWave();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u16 m_28;
    u8 _pad2A[0x2];
    void* m_2c;
    u8 _pad30[0x8];
    u32 m_38;
    u32 m_3c;
    void* m_40;
    u8 _pad44[0xC];
    void* m_50;
    u8 _pad54[0xC];
    void* m_60;
    virtual void render();
    virtual void run_task();
    u8 unk_64[0xC];
};

typedef char TBoss5GryphonShockWave_size[sizeof(TBoss5GryphonShockWave) == 0x70 ? 1 : -1];

extern "C" {
void TBoss8Dragon__sub_80066A4C(void);
void *__dt__22TBoss5GryphonShockWaveFv(void *arg0, s16 arg1);
}

// --- C functions defined in TBoss5GryphonShockWave.cpp ---
extern "C" {
void TBoss8Dragon__sub_80066A4C(void);
}
// --- end of C functions

#endif
