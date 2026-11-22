#ifndef PSO_BOSS_DRAGON_TOBJBOSS1FLOOR_H
#define PSO_BOSS_DRAGON_TOBJBOSS1FLOOR_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

class TParticleCtrl;

class TObjBoss1Floor : public TObject {
public:
    TObjBoss1Floor(TObject *parent);
    virtual ~TObjBoss1Floor();
    virtual void render();
    virtual void run_task();
    Vec position;  // name inferred: zeroed by the constructor, read nowhere in this unit
    TParticleCtrl *player_emitters[4];  // run_task keeps particle 0x144 under each present player
public:
    static void create_instance();
};
LAYOUT_ASSERT(TObjBoss1Floor_size, sizeof(TObjBoss1Floor) == 0x38);

#endif
