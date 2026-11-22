#ifndef PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_H
#define PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

struct TObjEneRe2Flower : public TObjEneDD_ST {
    TObjEneRe2Flower(TObject *parent, void *setData);
    virtual ~TObjEneRe2Flower();
    virtual void run_task();
    virtual void render();
    virtual void refresh_target();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    void sync_center_offset();
    s32 is_rare_variant();
    void sub_800C3BA8();
    void dispatch_action(s32);
    void handle_event(s32 arg1);
    void begin_state_242();
    s32 check_hit_flag();
    void clear_child_flags();
    void set_child_flags();
    u8 *find_target_in_range();
    static void destroy_instance();
    static void *create(void *setData);
    int get_flag_11();

    s32 m_3c0;
    u32 m_3c4;
    f32 m_3c8;
    s32 m_3cc;
    s32 m_3d0;
    s32 m_3d4;
    s32 m_3d8;
    Vec m_3dc[2];
    TUnk_80494938 m_3f4;
    s32 m_410;
    s32 m_414;
    s32 m_418;
    s32 m_41c;
    s32 m_420;
    f32 m_424;
    TObject *m_428;
};

// The archive loader the enemy factory table pairs with destroy_instance.
extern "C" void load_re2_flower_resources(void);

LAYOUT_ASSERT(TObjEneRe2Flower_size, sizeof(TObjEneRe2Flower) == 0x42C);
#endif
