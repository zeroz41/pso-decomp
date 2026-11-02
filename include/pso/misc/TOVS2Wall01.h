#ifndef PSO_MISC_TOVS2WALL01_H
#define PSO_MISC_TOVS2WALL01_H

#include "types.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/RenderFadeState.h"

struct TOVS2Wall01 : public TObjChara {
    virtual ~TOVS2Wall01();
    virtual void vfunc_6(s16 *, s32);
    u8 unk_334[0x4];
    f32 m_338;
    u32 m_33c;
    RenderFadeState m_340;
    u32 m_35c;
    void spawn_debris(s32 arg1);
    void release();
    int interact_player_neg1();
    virtual void run_task();
    virtual void render();
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual s32 try_start_action(s32, s32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    void *create();
    static void release_model();
    static void load_resources();
    void *destroy(s16 arg1);
    void byteswap_hit_packet();
    void update_and_send();
    void*init();
    void save_and_send_state(u16 arg1);
};

typedef char TOVS2Wall01_size[sizeof(TOVS2Wall01) == 0x360 ? 1 : -1];
#endif
