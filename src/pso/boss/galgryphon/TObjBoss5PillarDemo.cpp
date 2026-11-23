#include "pso/unk/text_80066F10.h"
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/render/ModelDrawContext.h"

#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
#pragma push
#pragma readonly_strings on
const char *TObjBoss5PillarDemo__name = "TObjBoss5PillarDemo";
#pragma pop

void TObjBoss5PillarDemo__sub_8028AB38(void) {
    if (lbl_805D4DD8 != NULL) {
        BmlModelEntry *models = lbl_805D4DD8->models;
        clear_child_target_refs(models[7].model, models[6].model);
    }
}

void TObjBoss5PillarDemo::update_active_pillar() {
    if (lbl_805D4DD8 != NULL) {
        BmlModelEntry *models = lbl_805D4DD8->models;
        clear_chain_flags(models[7].model, models[6].model);
    }
}

}
TObjBoss5PillarDemo::~TObjBoss5PillarDemo() {

}

TObjBoss5PillarDemo::TObjBoss5PillarDemo(TObject *parent, Vec *pos) : TObjBoss5Pillar(parent, pos) {
    m_name = TObjBoss5PillarDemo__name;
    this->frame_step = 0.5f;
    this->models[0] = lbl_805D4DD8->models[3].model;
    this->models[1] = lbl_805D4DD8->models[4].model;
    this->motions[0] = lbl_805D4DD8->motions[0].motion;
    this->motions[1] = lbl_805D4DD8->motions[1].motion;
}

TObjBoss5PillarDemo *TObjBoss5PillarDemo::create() {
    NJS_OBJECT *model = lbl_805D4DD8->models[3].model;
    return new TObjBoss5PillarDemo(tl_02, (Vec *)model->pos);
}

void TObjBoss5PillarDemo__sub_8028ACE0(void) {  }
void TObjBoss5PillarDemo__sub_8028ACE4(void) {  }
