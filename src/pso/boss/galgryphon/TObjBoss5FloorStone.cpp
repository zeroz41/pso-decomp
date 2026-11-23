#include "pso/boss/galgryphon/TObjBoss5FloorStone.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80066F5C.h"

#pragma readonly_strings on


extern void *lbl_805D4DD8;
extern void *boss5_common_texture_list;
const char *TObjBoss5FloorStone__name = "TObjBoss5FloorStone";

void TObjBoss5FloorStone::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        draw_shadowed_object((NJS_TEXLIST *)boss5_common_texture_list, (NJS_OBJECT *)(*(saddr *)((s8 *)(*(void **)((s8 *)lbl_805D4DD8 + 0x42C)) + 0x58)));
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
