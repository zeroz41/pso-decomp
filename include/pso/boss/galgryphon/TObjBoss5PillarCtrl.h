#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARCTRL_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjBoss5Pillar;

// Creates one TObjBoss5Pillar at each child node of the boss's model 2.
struct TObjBoss5PillarCtrl : public TObject {
    TObjBoss5PillarCtrl(TObject *parent);
    virtual ~TObjBoss5PillarCtrl();
    virtual void render();
    virtual void run_task();
    static TObjBoss5PillarCtrl *create(TObject *parent);
    int update_pillar();
    int forward_pillar_2B710();

    s32 count;
    TObjBoss5Pillar **pillars;
};

LAYOUT_ASSERT(TObjBoss5PillarCtrl_size, sizeof(TObjBoss5PillarCtrl) == 0x24);
#endif
