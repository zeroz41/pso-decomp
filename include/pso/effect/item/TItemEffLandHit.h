#ifndef PSO_EFFECT_ITEM_TITEMEFFLANDHIT_H
#define PSO_EFFECT_ITEM_TITEMEFFLANDHIT_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/system/vector.h"

struct TItemEquipBase;

// A Vec copied as three words.
struct HitPositionWords { s32 x; s32 y; s32 z; };
union HitPosition { HitPositionWords w; Vec f; };

class TItem;
class TItemWeapon;

class TItemEffLandHit : public TObject {
public:
    Vec start;
    Vec end;
    s32 item_id;
    s32 finished;

    static const char *class_name;

    TItemEffLandHit(TObject *parent, TItem *item, Vec *start, Vec *end);
    virtual ~TItemEffLandHit();
    virtual void run_task();
    // Fires the shooting item's impact callback from start to end and ends the effect.
    void trigger_impact();
    // The item timer's expiry callback for the effect.
    static void on_timer_expired(TObject *object);
};

void spawn_land_hit_effect(TObject *parent, TItem *item, Vec *start, Vec *end, s32 frames);
// Three hit particles at pos, the last one 15 units lower.
void spawn_hit_particle_trio(Vec *pos);
// A weapon effect's wall-hit callback.
void spawn_wall_hit_particles(s32 layer, Vec *pos);
// The weapons' impact callback: hit particles where the shot ended.
void spawn_weapon_impact_effect(TObject *layer, TItemEquipBase *weapon, const Vec *start, Vec *end);

#endif
