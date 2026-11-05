#include "pso/TObjBoss5FloorStone.h"

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
extern void *lbl_805D4DD8;
extern s32 boss5_common_texture_list;
extern const char *TObjBoss5FloorStone__name;
}

void TObjBoss5FloorStone::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        ((TObjBoss5FloorStone *)boss5_common_texture_list)->render_impl((void*)(*(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4DD8 + 0x42C)) + 0x58)));
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
