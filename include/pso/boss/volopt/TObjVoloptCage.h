#ifndef PSO_BOSS_VOLOPT_TOBJVOLOPTCAGE_H
#define PSO_BOSS_VOLOPT_TOBJVOLOPTCAGE_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/object/base/TObjChara.h"

// The cage Vol Opt drops over a player: it holds the player (mode 1), can be
// hit (mode 4) and breaks apart (mode 5); mode 7 is the drop itself.
class TObjVoloptCage : public TObjEnemyCustom {
public:
    s32 countdown;
    s32 status;

    TObjVoloptCage(TObjEnemy *boss, u16 target, u16 id, s32 group);
    virtual ~TObjVoloptCage();
    virtual void run_task();
    virtual void render();

    void update_breakup();
    void update_collision_state();
    void update_capture();
    void update_rise();
    void damage_caged_player();

    void update_state();
    static void destroy();
    static void init_break_model();
    static s32 get_int_param(s32 index);
    static f32 get_float_param(s32 index);
};

LAYOUT_ASSERT(TObjVoloptCage_size, sizeof(TObjVoloptCage) == 0x394);

struct BreakUpParamRow;
extern BreakUpParamRow volopt_cage_breakup_params;
extern player_stats *volopt_cage_combat_stats;
// Same layout as the P02 table (VoloptP02Params): floats first, ints at 0x18.
struct VoloptCageParams {
    f32 float_params[6];
    s32 int_params[6];
};

extern VoloptCageParams *volopt_cage_params;

extern "C" {
void obj_set_flag_20000(TObjBase *actor);
void obj_clear_flag30_20000(TObjBase *actor);
}

void set_volopt_cage_flag();

#endif
