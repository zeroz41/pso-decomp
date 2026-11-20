#include "types.h"
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

void TLobby__sub_80141038(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r6;
    *(s32 *)((s8 *)arg0 + 4) = arg1;
    temp_r6 = arg1 + 1;
    *(s32 *)((s8 *)arg0 + 8) = temp_r6;
    *(s32 *)((s8 *)arg0 + 0xC) = temp_r6;
    *(s32 *)((s8 *)arg0 + 0x10) = arg2;
    *(s32 *)((s8 *)arg0 + 0x14) = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    *(s32 *)((s8 *)arg0 + 0) = -1;
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
}
