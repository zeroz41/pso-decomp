#include "pso/boss/galgryphon/TObjBoss5FloorGrass.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"

#pragma readonly_strings on

extern "C" {

extern void *lbl_805D4DD8;
extern s32 boss5_common_texture_list;
const char *TObjBoss5FloorGrass__name = "TObjBoss5FloorGrass";

void TObjBoss5FloorGrass::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        push_matrix();
        TObjFish::set_global_param(boss5_common_texture_list);
        draw_ginja_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4DD8 + 0x42C)) + 0x78)));
        pop_matrix();
    }
}

void TObjBoss5FloorGrass::run_task() {  }

}

TObjBoss5FloorGrass::~TObjBoss5FloorGrass() {}

TObjBoss5FloorGrass::TObjBoss5FloorGrass(TObject *parent) : TObject(parent) {
    m_name = TObjBoss5FloorGrass__name;
}

void *TObjBoss5FloorGrass::create() {
    return new TObjBoss5FloorGrass(tl_02);
}
