#ifndef PSO_OBJECT_TOBJGRASS_H
#define PSO_OBJECT_TOBJGRASS_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TUnk_80494938.h"
#include "pso/unk/TUnk_80494968.h"

struct TObjGrass : public TObjEnemy {
    TObjGrass(TObject *parent, void *set_data);
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
    TUnk_80494938 fade;
    TUnk_80494968 *savers[2];  // attack traces; same type and role as TObjEneDubchik::saver (inferred name)
    static void update_dying(void *arg0_);
    static void update_camera_vec_by_stage();
    s32 update();
    s32 update_web_attack();
    static void update_chase_target(void *arg0_);
    static void update_ai(void *arg0);
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    static void destroy_all();
    static void load_resources();
    void init_from_table_entry(s32 i);
    u8 unk_3D4[0x30];
};

typedef char TObjGrass_size[sizeof(TObjGrass) == 0x404 ? 1 : -1];
#endif
