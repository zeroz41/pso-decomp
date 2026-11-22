#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemDisconnectCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"


#pragma readonly_strings on


const char *TItemDisconnectCtrl__name = "TItemDisconnectCtrl";


s32 item_desync_detected;
extern const char *TItemDisconnectCtrl__name;

void TItemDisconnectCtrl::run_task() {
    if (get_current_floor_area() != AREA_LOBBY && item_desync_detected != 0) {
        TLobby::disconnect_protocol();
        queue_destruction();
    }
}

TItemDisconnectCtrl::~TItemDisconnectCtrl() {}

TItemDisconnectCtrl::TItemDisconnectCtrl() : TObject(tl_05) {
    m_name = TItemDisconnectCtrl__name;
    disallow_rendering();
}
