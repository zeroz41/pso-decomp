#ifndef PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOAREAL_H
#define PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOAREAL_H

#include "types.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"

struct TObjEneMe3SinowZoaReal : public TObjEneMe3SinowZoa {
    TObjEneMe3SinowZoaReal(TObject *parent, void *set_data);
    virtual ~TObjEneMe3SinowZoaReal();
    void init_enemy();
    virtual void select_next_attack_state();
    virtual void on_target_lost();
    void run_death_reaction();
    void run_hit_reaction();
    static void *create_instance(void *set_data);
};

LAYOUT_ASSERT(TObjEneMe3SinowZoaReal_size, sizeof(TObjEneMe3SinowZoaReal) == 0x45C);


#endif
