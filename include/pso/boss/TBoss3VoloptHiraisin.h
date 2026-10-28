#ifndef PSO_BOSS_TBOSS3VOLOPTHIRAISIN_H
#define PSO_BOSS_TBOSS3VOLOPTHIRAISIN_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"

struct TBoss3VoloptHiraisin : public TObjEnemyCustom {
    TBoss3VoloptHiraisin(TUnk_804B9870 *parent, u16 id, s32 index);
    TBoss3VoloptHiraisin(TObject *parent, void *set_data);
    virtual ~TBoss3VoloptHiraisin();
    virtual void run_task();
    virtual void render();

    void sub_80040FDC();
    void start_attack();
    void sub_8004118C();
    void update_drop();
    void sub_80041314();
    void dispatch_state();
    static void destroy();
    static void init_models();
    static void *create(void *set_data);
    void init_params();
    void copy_position();
    void load_params_from_table(s32 index);
    void clear_flag_08000000();
    void set_flag_08000000();
    s32 sub_80040FCC();

    s32 hover_angle;
};

typedef char TBoss3VoloptHiraisin_size[sizeof(TBoss3VoloptHiraisin) == 0x390 ? 1 : -1];

#endif
