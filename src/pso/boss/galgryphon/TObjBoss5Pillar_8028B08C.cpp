#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/galgryphon/TObjBoss5PillarSmoke.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"

extern "C" {

extern BmlResource *lbl_805D4DD8;
}

TObjBoss5PillarSmoke *TObjBoss5Pillar::create_smoke(TObject *parent, NJS_OBJECT *node) {
    return new TObjBoss5PillarSmoke(parent, node);
}

extern "C" {

void TBoss8Dragon__sub_8028B0DC(TObjBoss5PillarCtrl *pillar_controller, void *arg1, void *arg2) {
    f32 off;
    NJS_OBJECT *n;
    s32 i;

    n = lbl_805D4DD8->models[2].model;
    off = ((TBoss8Dragon *)arg2)->calc_sq_offset(50.0f);
    n = n->child;
    for (i = 0; i < pillar_controller->count; i++) {
        if (pillar_controller->pillars[i] != NULL && ((TBoss8Dragon *)arg1)->is_within_xz_distance((u8 *)n, (f32)off) != 0) {
            pillar_controller->pillars[i]->play_sound_once();
        }
        n = n->sibling;
    }
}

}
