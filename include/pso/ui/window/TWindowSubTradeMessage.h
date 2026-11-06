#ifndef PSO_UI_WINDOW_TWINDOWSUBTRADEMESSAGE_H
#define PSO_UI_WINDOW_TWINDOWSUBTRADEMESSAGE_H
#include "pso/system/task/TObject.h"
class TWindowMessage;
class TWindowSubTradeMessage : public TObject {
public:
    TWindowSubTradeMessage(TObject* parent, s32 playerIndex);
    virtual ~TWindowSubTradeMessage();
    virtual void run_task();
    virtual void render();
    void finish();
    void show_message(const char* text);
    TWindowMessage* create_message_window(const char* text);
    u8 state;
    u8 padding1D[3];
    s32 playerIndex;
    TObject* parentWindow;
    TWindowMessage* messageWindow;
};
#include <stddef.h>
typedef char TradeMessageBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char TradeMessageSize[(sizeof(TWindowSubTradeMessage)==0x2C)?1:-1];
#define TRADE_MESSAGE_OFFSET(field,offset) typedef char TradeMessageOffset_##field[(offsetof(TWindowSubTradeMessage,field)==offset)?1:-1]
TRADE_MESSAGE_OFFSET(state,0x1C); TRADE_MESSAGE_OFFSET(playerIndex,0x20);
TRADE_MESSAGE_OFFSET(parentWindow,0x24); TRADE_MESSAGE_OFFSET(messageWindow,0x28);
#undef TRADE_MESSAGE_OFFSET
#endif
