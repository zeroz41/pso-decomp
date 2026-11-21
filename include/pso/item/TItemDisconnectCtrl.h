#ifndef PSO_ITEM_TITEMDISCONNECTCTRL_H
#define PSO_ITEM_TITEMDISCONNECTCTRL_H

#include "pso/system/task/TObject.h"

// Set when the item lists stop agreeing with the other clients (an id that
// cannot be assigned or is already taken); TItemDisconnectCtrl leaves the
// game when it sees it.
extern s32 item_desync_detected;

class TItemDisconnectCtrl : public TObject {
public:
    TItemDisconnectCtrl();
    virtual ~TItemDisconnectCtrl();
    virtual void run_task();
};

#include <stddef.h>
LAYOUT_ASSERT(TItemDisconnectCtrlSize, sizeof(TItemDisconnectCtrl) == 0x1C);
LAYOUT_ASSERT(TItemDisconnectCtrlNameOffset, offsetof(TItemDisconnectCtrl, m_name) == 0);

#endif
