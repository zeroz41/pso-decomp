#ifndef PSO_UI_WINDOW_TWINDOWTRADEREQUEST_H
#define PSO_UI_WINDOW_TWINDOWTRADEREQUEST_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

struct TWindowMessageYesNo;

struct TWindowTradeRequest : public TObject {
    TWindowTradeRequest(TObject *parent);
    virtual ~TWindowTradeRequest();
    s32 state;
    TWindowMessageYesNo *dialog;
    static void close_request_window();
    static void reset_trade();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TradeRequestDialogOffset, offsetof(TWindowTradeRequest, dialog) == 0x20);
LAYOUT_ASSERT(TWindowTradeRequest_size, sizeof(TWindowTradeRequest) == 0x24);
#endif
