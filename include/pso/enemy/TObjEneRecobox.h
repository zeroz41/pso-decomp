#ifndef PSO_ENEMY_TOBJENERECOBOX_H
#define PSO_ENEMY_TOBJENERECOBOX_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneRecobox : public TObjEneDD_ST {
    virtual ~TObjEneRecobox();
    virtual void run_task();
    virtual void render();
    s32 render_trap_model_if_visible();
    virtual void update_if_800BB858();
    virtual void draw_with_debug_info();
    void sub_8031F800();
    void sub_8031F6C0(s32);
    void update_floor_probe();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x8];
    f32 m_37c;
    u8 unk_380[0x24];
    void* m_3c0;

    u8 _padBeforeFade[0x18];
    MaterialOpacityFade fade;

    u32 m_3f8;
    u8 _pad3FC[0x10];
    u32 m_40c;
    u32 m_410;
    u32 m_414;
    u8 _pad418[0x48];
    void* m_460;
    u8 _pad464[0x74];
    u32 m_4d8;
    u32 m_4dc;
    u32 m_4e0;
    u32 m_4e4;
    u32 m_4e8;
    u32 m_4ec;
    static u32 remap_area_sound_id(u32 arg0);
    static void release_static_instance();
    static void load_resources();
    u8 unk_4D4[0x1C];
    f32 m_4f0;
};

typedef char TObjEneRecoboxFadeOffset[offsetof(TObjEneRecobox, fade) == 0x3C0 ? 1 : -1];

typedef char TObjEneRecobox_size[sizeof(TObjEneRecobox) == 0x4F4 ? 1 : -1];
#endif
