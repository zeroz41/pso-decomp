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
extern BmlResource *lbl_805D4DD8;
#pragma push
#pragma readonly_strings on
const char *TObjBoss5PillarDemo__name = "TObjBoss5PillarDemo";
#pragma pop
s32 clear_child_target_refs(s32, s32);
s32 clear_chain_flags(s32, s32);

void TObjBoss5PillarDemo__sub_8028AB38(void) {
    void *temp_r4;

    if ((void *) lbl_805D4DD8 != NULL) {
        temp_r4 = *(void **)((s8 *)lbl_805D4DD8 + 0x42C);
        clear_child_target_refs(*(s32 *)((s8 *)temp_r4 + 0x78), *(s32 *)((s8 *)temp_r4 + 0x68));
    }
}

void TObjBoss5PillarDemo::update_active_pillar() {
    void *temp_r4;

    if ((void *) lbl_805D4DD8 != NULL) {
        temp_r4 = *(void **)((s8 *)lbl_805D4DD8 + 0x42C);
        clear_chain_flags(*(s32 *)((s8 *)temp_r4 + 0x78), *(s32 *)((s8 *)temp_r4 + 0x68));
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
