#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"

extern "C" {
// The original also calls this entry with a pillar-demo receiver. Its shared
// class ownership is unresolved; retain the observed TObject borrow here.
void play_sound_once__19TObjBoss5PillarCtrlFv(TObject *pillar);
}

void TObjBoss5Ctrl::play_pillar_sound() {
    TObjBoss5Ctrl *controller = boss5_ctrl_instance;
    if (controller != NULL && controller->pillar_demo != NULL) {
        play_sound_once__19TObjBoss5PillarCtrlFv(controller->pillar_demo);
    }
}
