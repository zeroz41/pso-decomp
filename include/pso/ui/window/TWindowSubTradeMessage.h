#ifndef PSO_UI_WINDOW_TWINDOWSUBTRADEMESSAGE_H
#define PSO_UI_WINDOW_TWINDOWSUBTRADEMESSAGE_H
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
class TWindowMessage;
class TWindowSubTradeMessage : public TObject {
public:
    TWindowSubTradeMessage(TWindowMainMenu *parent, s32 playerIndex);
    virtual ~TWindowSubTradeMessage();
    virtual void run_task();
    virtual void render();
    void finish();
    void show_message(const char* text);
    TWindowMessage* create_message_window(const char* text);
    u8 state;
    u8 padding1D[3];
    s32 playerIndex;
    TWindowMainMenu *parentWindow;
    TWindowMessage* messageWindow;
};
#include <stddef.h>
LAYOUT_ASSERT(TradeMessageBaseSize, sizeof(TObject)==0x1C);
LAYOUT_ASSERT(TradeMessageSize, sizeof(TWindowSubTradeMessage)==0x2C);
#define TRADE_MESSAGE_OFFSET(field,offset) LAYOUT_ASSERT(TradeMessageOffset_##field, offsetof(TWindowSubTradeMessage,field)==offset)
TRADE_MESSAGE_OFFSET(state,0x1C); TRADE_MESSAGE_OFFSET(playerIndex,0x20);
TRADE_MESSAGE_OFFSET(parentWindow,0x24); TRADE_MESSAGE_OFFSET(messageWindow,0x28);
#undef TRADE_MESSAGE_OFFSET
#endif
