#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPTHIRAISIN_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPTHIRAISIN_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"

struct TBoss3VoloptHiraisin : public TObjEnemyCustom {
    TBoss3VoloptHiraisin(TObjBase *parent, u16 id, s32 index);
    TBoss3VoloptHiraisin(TObject *parent, void *set_data);
    virtual ~TBoss3VoloptHiraisin();
    virtual void run_task();
    virtual void render();

    void update_descend();
    void start_attack();
    void update_hover();
    void update_drop();
    void update_hit();
    void dispatch_state();
    static void destroy();
    static void init_models();
    static void *create(void *set_data);
    void init_params();
    void load_params_from_table(s32 index);
    void clear_flag_08000000();
    void set_flag_08000000();
    s32 is_grounded();

    s32 hover_angle;
};

LAYOUT_ASSERT(TBoss3VoloptHiraisin_size, sizeof(TBoss3VoloptHiraisin) == 0x390);

#endif
