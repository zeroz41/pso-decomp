#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONTORNADO_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONTORNADO_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss5GryphonTornado : public TObject {
    virtual ~TBoss5GryphonTornado();
    void sub_803554F0(u8 *);
    u32 m_1c;
    u32 m_20;
    u16 m_24;
    u8 _pad26[0x2];
    void* m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x4];
    f32 m_38;
    u8 unk_3C[0x10];
    u32 m_4c;
    u32 m_50;
    u32 m_54;
    u32 m_58;
    virtual void render();
    virtual void run_task();
};

typedef char TBoss5GryphonTornado_size[sizeof(TBoss5GryphonTornado) == 0x5C ? 1 : -1];

extern "C" {
u8 *TBoss5GryphonTornado__ct(TBoss5GryphonTornado *boss5_gryphon_tornado, u8 *arg1, s32 arg2, u8 *arg3, s16 arg4);
void *__dt__20TBoss5GryphonTornadoFv(TBoss5GryphonTornado *arg0, s16 arg1);
}

// --- C functions defined in TBoss5GryphonTornado.cpp ---
extern "C" {
u8 *TBoss5GryphonTornado__ct(TBoss5GryphonTornado *boss5_gryphon_tornado, u8 *arg1, s32 arg2, u8 *arg3, s16 arg4);
}
// --- end of C functions

#endif
