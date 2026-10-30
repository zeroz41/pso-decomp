#ifndef PSO_OBJECT_TOBJGRASS_H
#define PSO_OBJECT_TOBJGRASS_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjGrass : public TObjEnemy {
    virtual ~TObjGrass();
    virtual void vfunc_28();
    virtual s32 is_target_in_attack_range();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    s32 sub_800BE75C();
    void sub_800BDD70();
    void sub_800BD4D8();
    s32 sub_800BCE44();
    void* m_374;
    u8 _pad378[0x8];
    void* m_380;
    u8 _pad384[0x8];
    void* m_38c;
    u8 unk_390[0x8];
    f32 m_398;
    s16 m_39c;
    s16 m_39e;
    u32 m_3a0;
    u8 _pad3A4[0x4];
    u32 m_3a8;
    u32 m_3ac;

    MaterialOpacityFade fade;

    u32 m_3cc;
    u32 m_3d0;
    static void update_dying(void *arg0_);
    static void update_camera_vec_by_stage();
    s32 update();
    s32 update_web_attack();
    static void update_chase_target(void *arg0_);
    static void update_ai(void *arg0);
    void render();
    void run_task();
    static void *create(void *arg0);
    static void destroy_all();
    static void load_resources();
    void init_from_table_entry(s32 i);
    u8 unk_3D4[0x30];
};

typedef char TObjGrassFadeOffset[offsetof(TObjGrass, fade) == 0x3B0 ? 1 : -1];

typedef char TObjGrass_size[sizeof(TObjGrass) == 0x404 ? 1 : -1];
#endif
