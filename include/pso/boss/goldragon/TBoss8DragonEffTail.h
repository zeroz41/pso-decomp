#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFTAIL_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFTAIL_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class AreaAttackHistory;
class TBoss8Dragon;

struct TBoss8DragonEffTail : public TUnk_804928CC {
    TBoss8DragonEffTail(TBoss8Dragon *dragon, Vec *nodes);
    virtual ~TBoss8DragonEffTail();
    virtual void apply_hit_if_active(void *, f32 *);
    virtual void run_task();
    virtual void area_attack_apply_recoil(void *, f32);
    TBoss8Dragon *dragon;  // its owner: run_task follows it and refreshes its tail hit points
    Vec *nodes;            // the owner's node positions the 17 bodies are placed on
    AreaAttackHistory *attack_history; // laid out as in its twin TBoss1DragonEffTail
    s32 sweep_side;        // 1 after enable, 0 after disable: picks the sign of sweep_vector
    Vec sweep_vector;      // 5 units across rotation_y; area_attack_apply_recoil adds it to the target's velocity
    virtual void render();
    void enable();
    void disable();
    void clear_attack_history();
    // Empty; TBoss8Dragon::load_resources calls it last (name inferred from that caller).
    static void load_resources();
    static void load_statics(); // inferred: loads what free_statics frees (its pair in static_resource_callback_table)
    static void free_statics();
};

LAYOUT_ASSERT(TBoss8DragonEffTail_size, sizeof(TBoss8DragonEffTail) == 0xCC);

#endif
