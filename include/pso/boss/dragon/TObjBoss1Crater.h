#ifndef PSO_BOSS_DRAGON_TOBJBOSS1CRATER_H
#define PSO_BOSS_DRAGON_TOBJBOSS1CRATER_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class AreaAttackHistory;
class PointerBuffer;
class TParticleCtrl;
struct Vec;

struct TObjBoss1Crater : public TUnk_804928CC {
    TObjBoss1Crater(TObject *parent, TObjBase *owner, Vec *pos);
    virtual ~TObjBoss1Crater();
    virtual void area_attack_receive_direct(void *, f32 *, void *);
    virtual void run_task();
    virtual void render();
    static s32 is_count_below_limit();
    static TObjBoss1Crater *create(TObject *parent, Vec *pos);
    TParticleCtrl *emitter;            // particle emitter 0x40 over the crater
    AreaAttackHistory *attack_history; // actors it hit, four at most
    s32 hit_timers[4];                 // frames until each attack_history entry is dropped (60 on a hit)
    s32 attack_kind;                   // 1, or 0x13 in V2 mode
};

LAYOUT_ASSERT(TObjBoss1Crater_size, sizeof(TObjBoss1Crater) == 0xCC);

extern "C" {
// Horizontal distance from position to the nearest crater, 0 when there is none.
f32 calc_nearest_crater_distance(Vec *position);
// TLobby::update_boss1_objects calls it with the other arena objects' teardown hooks; empty.
void TObjBoss1Crater__sub_8002C7B4(void);
// TLobby::init_bosses calls it: empties TObjBoss1Crater__instance_list.
void TObjBoss1Crater__sub_8002C7B8(void);
}

// An attack-target list's entry count.
s32 attack_target_list_count(PointerBuffer *buffer);
// Drops entry index, moving the last entry into its place.
void attack_target_list_remove(PointerBuffer *buffer, s32 index);

#endif
