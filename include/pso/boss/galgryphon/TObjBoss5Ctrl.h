#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5CTRL_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5CTRL_H

#include "pso/system/task/TObject.h"

class TObjBoss5PillarDemo;
class TObjBoss5PillarCtrl;
class TObjBoss5FloorStone;

class TObjBoss5Ctrl : public TObject {
public:
    TObject *floor_grass;
    TObjBoss5FloorStone *floor_stone;
    TObjBoss5PillarCtrl *pillar_controller;
    TObjBoss5PillarDemo *pillar_demo;
    s16 sound_countdown;

    TObjBoss5Ctrl(TObject *parent);
    virtual ~TObjBoss5Ctrl();
    virtual void run_task();

    static void play_pillar_sound();
    static TObjBoss5Ctrl *create();
};

extern "C" {
extern TObjBoss5Ctrl *boss5_ctrl_instance;
}

LAYOUT_ASSERT(TObjBoss5Ctrl_size, sizeof(TObjBoss5Ctrl) == 0x30);

#endif
