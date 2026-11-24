#include "pso/unk/text_80066F10.h"
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_80067034.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/galgryphon/TObjBoss5PillarSmoke.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"


TObjBoss5PillarSmoke *TObjBoss5Pillar::create_smoke(TObject *parent, NJS_OBJECT *node) {
    return new TObjBoss5PillarSmoke(parent, node);
}

extern "C" {

void TBoss8Dragon__sub_8028B0DC(TObjBoss5PillarCtrl *pillar_controller, const Vec *pos, const DragonAttackParams *params) {
    f32 off;
    NJS_OBJECT *n;
    s32 i;

    n = boss5_common_bml_resource->models[2].model;
    off = TBoss8Dragon::calc_sq_offset(params, 50.0f);
    n = n->child;
    for (i = 0; i < pillar_controller->count; i++) {
        if (pillar_controller->pillars[i] != NULL && TBoss8Dragon::is_within_xz_distance(pos, n, off) != 0) {
            pillar_controller->pillars[i]->play_sound_once();
        }
        n = n->sibling;
    }
}

}
