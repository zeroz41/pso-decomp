#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERIDO_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERIDO_H

#include "types.h"
#include "pso/item/TUnk_804B97C0.h"

struct TObjContainerIdo : public TUnk_804B97C0 {
    virtual ~TObjContainerIdo();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual void render();
    virtual void run_task();
    void* m_b4;
    u8 _padB8[0x8];
    void* m_c0;
    u8 _padC4[0x18];
    u32 m_dc;
    u32 m_e0;
    u8 unk_E4[0x4];
    f32 m_e8;
    u8 unk_EC[0x4];
    void* m_f0;
    u8 _padF4[0x10];
    u32 m_104;
    static void free_resources();
    static void load_resources();
    u8 unk_108[0x4];
    static void *create(void *arg0);
};

typedef char TObjContainerIdo_size[sizeof(TObjContainerIdo) == 0x10C ? 1 : -1];
#endif
