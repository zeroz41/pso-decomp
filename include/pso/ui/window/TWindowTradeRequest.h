#ifndef PSO_UI_WINDOW_TWINDOWTRADEREQUEST_H
#define PSO_UI_WINDOW_TWINDOWTRADEREQUEST_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowTradeRequest : public TObject {
    virtual ~TWindowTradeRequest();
    u32 m_1c;
    u32 m_20;
    static void close_request_window();
    static void reset_trade();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowTradeRequest_size, sizeof(TWindowTradeRequest) == 0x24);
#endif
