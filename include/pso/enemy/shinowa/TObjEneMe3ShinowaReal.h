#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAREAL_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAREAL_H

#include "types.h"
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"

struct TObjEneMe3ShinowaMirage;

struct TObjEneMe3ShinowaReal : public TObjEneMe3Shinowa {
    TObjEneMe3ShinowaReal(TObject *parent, void *set_data);
    virtual ~TObjEneMe3ShinowaReal();
    virtual void state_split_mirages(s32);
    virtual void state_toggle_cloak(s32);
    virtual void select_next_attack_state();
    virtual void on_target_lost();
    void consume_spawn_request();
    void run_death_reaction();
    void run_hit_reaction();
    void spawn_mirages();
    TObjEneMe3ShinowaMirage *get_or_create_mirage(s32 index);
    void try_spawn_mirages();
    static TObjEneMe3ShinowaReal *create(void *set_data);
    u16 mirage_ids[4];
    u16 get_target_id();
};

LAYOUT_ASSERT(TObjEneMe3ShinowaReal_size, sizeof(TObjEneMe3ShinowaReal) == 0x434);

// The pad button its owner's card flag 2 picks: 0x20000 when set, else 0x10000.
s32 get_control_button_mask(s32 client_id);

#endif
