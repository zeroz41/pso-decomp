#include "pso/boss/galgryphon/Boss5CommonResource.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/galgryphon/TObjBoss5FloorGrass.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/PhotonBlastResults.h"

#pragma readonly_strings on


const char *TObjBoss5FloorGrass::name = "TObjBoss5FloorGrass";

void TObjBoss5FloorGrass::render() {
    if (is_any_teammate_in_state() == 0) {
        push_matrix();
        set_texture_list(boss5_common_texture_list);
        draw_ginja_object(boss5_common_bml_resource->models[7].model);
        pop_matrix();
    }
}

void TObjBoss5FloorGrass::run_task() {  }


TObjBoss5FloorGrass::~TObjBoss5FloorGrass() {}

TObjBoss5FloorGrass::TObjBoss5FloorGrass(TObject *parent) : TObject(parent) {
    m_name = TObjBoss5FloorGrass::name;
}

void *TObjBoss5FloorGrass::create() {
    return new TObjBoss5FloorGrass(tl_02);
}
