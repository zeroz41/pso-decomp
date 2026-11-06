#include "types.h"
#include "pso/boss/TObjBoss5Ctrl.h"
#include "pso/boss/TObjBoss5PillarCtrl.h"

extern void *boss5_ctrl_instance;

void TObjBoss5Ctrl::play_pillar_sound() {
    void *sp4;
    sp4 = boss5_ctrl_instance;
    if (sp4 != NULL && (u32) *(u32 *)((s8 *)sp4 + 0x28) != 0U) {
        ((TObjBoss5PillarCtrl *)(*(void **)((s8 *)sp4 + 0x28)))->play_sound_once();
    }
}
