#ifndef PSO_UI_WINDOW_TWINDOWSUBTRADEMAIN_802D2808_H
#define PSO_UI_WINDOW_TWINDOWSUBTRADEMAIN_802D2808_H

#include "types.h"

extern "C" {
void TWindowSubTradeMain__sub_802D2870(void);
}
s32 are_both_trade_offers_confirmed(void);
void clear_local_trade_final_confirmation(void);
void clear_local_trade_offer_confirmation(void);
s32 is_local_trade_offer_confirmation_requested(void);
void set_local_trade_final_confirmation(void);
void set_local_trade_offer_confirmation(void);

// --- C functions defined in TWindowSubTradeMain_802D2808.cpp ---
extern "C" {
void TWindowSubTradeMain__sub_802D2870(void);
}
// --- end of C functions

#endif
