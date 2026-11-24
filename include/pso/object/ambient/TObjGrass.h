#ifndef PSO_OBJECT_AMBIENT_TOBJGRASS_H
#define PSO_OBJECT_AMBIENT_TOBJGRASS_H

#include <stddef.h>
#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/effect/TAttackTrace.h"

struct NJS_OBJECT;

struct TObjGrass : public TObjEnemy {
    TObjGrass(TObject *parent, void *set_data);
    virtual ~TObjGrass();
    virtual void refresh_target();
    virtual s32 is_target_in_attack_range();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    void sub_800BE75C();
    void sub_800BDD70();
    void sub_800BD4D8();
    void sub_800BCE44();
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
    TAttackTraceStrip *savers[2];  // attack traces; same type and role as TObjEneDubchik::saver (inferred name)
    void update_dying();
    static void update_camera_vec_by_stage(NJS_OBJECT *);
    void update();
    void update_web_attack();
    void update_chase_target();
    static void update_ai(void *arg0);
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void destroy_all();
    static void load_resources();
    void init_from_table_entry(s32 i);
    u8 unk_3D4[0x30];
};

LAYOUT_ASSERT(TObjGrassFadeOffset, offsetof(TObjGrass, fade) == 0x3B0);
LAYOUT_ASSERT(TObjGrass_size, sizeof(TObjGrass) == 0x404);
#endif
