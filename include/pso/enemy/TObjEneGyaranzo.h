#ifndef PSO_ENEMY_TOBJENEGYARANZO_H
#define PSO_ENEMY_TOBJENEGYARANZO_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "dolphin/mtx.h"
#include "pso/enemy/TObjEnemyCustom.h"

struct TObjEneGyaranzo : public TObjEnemyCustom {
    virtual ~TObjEneGyaranzo();
    void select_targets();
    virtual void run_task();
    virtual void render();
    void sub_800D37F4();
    void sub_800D2900();
    void init_params_from_table();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_58();
    virtual s32 is_target_in_attack_range();
    virtual void vfunc_59();
    virtual void vfunc_61();
    void spawn_missile();
    u32 m_38c;
    u8 _pad390[0x18];
    u32 m_3a8;
    u32 m_3ac;
    u32 m_3b0;
    u32 m_3b4;
    u32 m_3b8;
    u8 unk_3BC[0x4];
    s32 m_3c0;
    u8 unk_3C4[0x4];
    s32 m_3c8;
    u8 unk_3CC[0x4];

    MaterialOpacityFade fade;

    void* m_3ec;
    u8 unk_3F0[0x6C];
    static void *create(void *arg0);
    static void free_static_instances();
};

typedef char TObjEneGyaranzoFadeOffset[offsetof(TObjEneGyaranzo, fade) == 0x3D0 ? 1 : -1];

typedef char TObjEneGyaranzo_size[sizeof(TObjEneGyaranzo) == 0x45C ? 1 : -1];
#endif
