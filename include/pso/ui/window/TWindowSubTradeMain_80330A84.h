#ifndef PSO_UI_WINDOW_TWINDOWSUBTRADEMAIN_80330A84_H
#define PSO_UI_WINDOW_TWINDOWSUBTRADEMAIN_80330A84_H

#include "types.h"

struct TWindowMessageYesNo;
struct TWindowSubTradeMain;

extern "C" {
void TWindowSubTradeMain__sub_80330A84(void *p);
TWindowMessageYesNo *open_option_dialog__19TWindowSubTradeMainFPvi(TWindowSubTradeMain *window, saddr message);
TWindowMessageYesNo *open_option_dialog_thunk__19TWindowSubTradeMainFPvPv(TWindowSubTradeMain *window, saddr message);
TWindowMessageYesNo *open_status_window__19TWindowSubTradeMainFi(TWindowSubTradeMain *window);
TWindowMessageYesNo *update_from_lobby__19TWindowSubTradeMainFi(TWindowSubTradeMain *window);
}

#endif
