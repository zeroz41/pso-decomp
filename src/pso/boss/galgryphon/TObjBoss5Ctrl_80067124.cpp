#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"

#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"

void TObjBoss5Ctrl::play_pillar_sound() {
    TObjBoss5Ctrl *controller = boss5_ctrl_instance;
    if (controller != NULL && controller->pillar_demo != NULL) {
        ((TObjBoss5PillarCtrl *)controller->pillar_demo)->play_sound_once();
    }
}
