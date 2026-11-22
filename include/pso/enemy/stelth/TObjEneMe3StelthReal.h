#ifndef PSO_ENEMY_STELTH_TOBJENEME3STELTHREAL_H
#define PSO_ENEMY_STELTH_TOBJENEME3STELTHREAL_H

#include "types.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"

struct TObjEneMe3StelthReal : public TObjEneMe3Stelth {
    TObjEneMe3StelthReal(TObject *parent, void *set_data);
    virtual ~TObjEneMe3StelthReal();
    virtual void select_next_attack_state();
    virtual void on_target_lost();
    void init_common();
    void run_death_reaction();
    void run_hit_reaction();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEneMe3StelthReal_size, sizeof(TObjEneMe3StelthReal) == 0x44C);
#endif
