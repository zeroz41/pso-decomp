#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemDisconnectCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TLobby.h"
#include "pso/map/FloorArea.h"

extern s32 item_desync_detected;
extern TObject *tl_05;
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
