#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"

extern "C" TObject *tl_01;

TObjBoss5Ctrl *TObjBoss5Ctrl::create() {
    TObjBoss5Ctrl *controller = new TObjBoss5Ctrl(tl_01);
    boss5_ctrl_instance = controller;
    return controller;
}
