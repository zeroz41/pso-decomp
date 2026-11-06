#ifndef PSO_BOSS_BARBARAY_TBOSS7CRAWFISH_H
#define PSO_BOSS_BARBARAY_TBOSS7CRAWFISH_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TBoss7Crawfish : public TObjEnemy {
    virtual ~TBoss7Crawfish();
    s32 sub_80308AA8();
    s32 is_visible();
    s32 sub_80308688();
    s16 get_floor();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    void* m_374;
    u8 _pad378[0x28];
    u32 m_3a0;
    u8 unk_3A4[0x24];
    s32 m_3c8;
    u32 m_3cc;
    void spawn_effect(s32 arg1);
    void free_child();
    void spawn_ground_effects();
    virtual void render();
    void clear_object_state_exchange();
    void check_band_and_destroy();
    static void update(s32 arg0);
    void update_motion_and_release();
    void aim_at_nearest_player();
    void update_attack_state();
    void change_state(s32 state);
    virtual void run_task();
    static void destroy_instance();
    static void load_static_resource();
    f32 get_health();
    void set_anim_timer(s16 v);
    void register_attack_hits();
};

typedef char TBoss7Crawfish_size[sizeof(TBoss7Crawfish) == 0x3D0 ? 1 : -1];
#endif
