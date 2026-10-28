#ifndef PSO_MISC_TODUMMYKEYCAVE01_H
#define PSO_MISC_TODUMMYKEYCAVE01_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TODummyKeyCave01 : public TObjBase {
    virtual ~TODummyKeyCave01();
    void sub_80165940();
    u32 m_90;
    u32 m_94;
    u16 m_98;
    u16 m_9a;
    void* m_9c;
    u8 unk_A0[0x4];
    f32 m_a4;
    u8 unk_A8[0x4];
    void* m_ac;
    u8 unk_B0[0x4];
    f32 m_b4;
    u32 m_b8;
    u8 _padBC[0x4];
    u32 m_c0;
    u32 m_c4;
    u32 m_c8;
    u32 m_cc;
    u32 m_d0;
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
};

typedef char TODummyKeyCave01_size[sizeof(TODummyKeyCave01) == 0xD4 ? 1 : -1];

extern "C" {
u8 *TODummyKeyCave01__ct(u8 *arg0, s32 arg1, s32 arg2);
void TODummyKeyCave01__sub_80165E88(void);
void TODummyKeyCave01__sub_80165E8C(void);
void *__dt__16TODummyKeyCave01Fv(void *arg0, s16 arg1);
}

#endif
