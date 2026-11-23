#ifndef PSO_OBJECT_KEY_TODUMMYKEYCAVE01_H
#define PSO_OBJECT_KEY_TODUMMYKEYCAVE01_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;

struct TODummyKeyCave01 : public TObjBase {
    TODummyKeyCave01(TObject *parent, void *set_data);
    virtual ~TODummyKeyCave01();
    void sub_80165940();
    NJS_TEXLIST *off_textures;
    NJS_TEXLIST *on_textures;
    u16 id;
    u16 m_9a;
    void* color;
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
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TODummyKeyCave01_size, sizeof(TODummyKeyCave01) == 0xD4);

extern "C" {
void TODummyKeyCave01__sub_80165E88(void);
void TODummyKeyCave01__sub_80165E8C(void);
void *__dt__16TODummyKeyCave01Fv(void *arg0, s16 arg1);
}

#endif
