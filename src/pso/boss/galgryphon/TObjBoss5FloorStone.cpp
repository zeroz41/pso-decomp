#include "pso/unk/text_80066F10.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/galgryphon/TObjBoss5FloorStone.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80066F5C.h"

#pragma readonly_strings on


const char *TObjBoss5FloorStone__name = "TObjBoss5FloorStone";

void TObjBoss5FloorStone::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
    draw_shadowed_object(boss5_common_texture_list, lbl_805D4DD8->models[5].model);
    }
}

void TObjBoss5FloorStone::run_task() {  }

TObjBoss5FloorStone::~TObjBoss5FloorStone() {}

TObjBoss5FloorStone::TObjBoss5FloorStone(TObject *parent) : TObject(parent) {
    m_name = TObjBoss5FloorStone__name;
}

void *TObjBoss5FloorStone::create() {
    return new TObjBoss5FloorStone(tl_02);
}
