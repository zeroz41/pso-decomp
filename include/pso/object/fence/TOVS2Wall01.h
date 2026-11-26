#ifndef PSO_OBJECT_FENCE_TOVS2WALL01_H
#define PSO_OBJECT_FENCE_TOVS2WALL01_H

#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/render/RenderFadeState.h"

struct TOVS2Wall01 : public TObjChara {
    TOVS2Wall01(void *set_data);
    virtual ~TOVS2Wall01();
    virtual void apply_saved_state(s16 *, s32);
    f32 view_range;
    f32 model_radius;
    u32 hits_left;
    RenderFadeState fade;
    u32 in_view;
    void spawn_debris(s32 index);
    void release();
    void interact_player_neg1();
    virtual void run_task();
    virtual void render();
    virtual s32 select_melee_contact_body(TObjChara *, f32);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual void apply_knockback_from_attacker(TObjBase *, f32);
    virtual s32 try_start_action(TObjChara *, s32, f32);
    virtual s32 roll_physical_accuracy(TObjChara *, s32, f32);
    static void *create(void *set_data);
    static void release_model();
    static void load_resources();
    void break_wall();
    f32 take_hit(TObjBase *attacker);
    s32 remaining_hits();
    void set_remaining_hits(s32 count);
    void save_and_send_state(u16 update_reason);
};

LAYOUT_ASSERT(TOVS2Wall01FadeOffset, offsetof(TOVS2Wall01, fade) == 0x340);
LAYOUT_ASSERT(TOVS2Wall01_size, sizeof(TOVS2Wall01) == 0x360);

// The raw set entry: its quest_object_entries row sits 4 bytes in.
struct WallSetEntry { u8 pad_0[4]; s16 set_index; };

#endif
