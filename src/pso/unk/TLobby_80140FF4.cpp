#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/TLobby_80140FF4.h"
#include "pso/unk/TLobby.h"
#include "pso/map/TMapCsnCtrl.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/system/task/TMainTask.h"


TMapCsnCtrl *map_csn_ctrl_instance;
s32 pending_adventure_map_floor = -1;

void TLobby::create_map_csn_ctrl() {
    map_csn_ctrl_instance = new TMapCsnCtrl(tl_05);
}

CsnGroup *TLobby__sub_80141030(TObjMapCsn *object) { return &object->collision_group; }

void initialize_floor_transition(Obj_80515BA0 *transition, s32 floor, s32 map) {
    s32 next_floor;
    transition->current_floor = floor;
    next_floor = floor + 1;
    transition->f8 = next_floor;
    transition->next_floor = next_floor;
    transition->current_map = map;
    transition->f14 = 0;
    transition->next_map = 0;
    transition->previous_floor = -1;
    transition->f1C = 0;
    transition->state_flags = 0;
}
