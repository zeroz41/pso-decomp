#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARCTRL_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjBoss5PillarCtrl : public TObject {
    virtual ~TObjBoss5PillarCtrl();
    u32 m_1c;
    u32 m_20;
    virtual void render();
    virtual void run_task();
    void *create();
    int update_pillar();
    int forward_pillar_2B710();
    void play_sound_once();
};

typedef char TObjBoss5PillarCtrl_size[sizeof(TObjBoss5PillarCtrl) == 0x24 ? 1 : -1];
#endif
