#ifndef PSO_UI_WINDOW_ISCOMCARDWINDOWOPEN_H
#define PSO_UI_WINDOW_ISCOMCARDWINDOWOPEN_H

#include "types.h"

// Not in TWindowCtrl.h: TWindowShortListCtrl_8026E7DC.cpp calls this through an int-returning prototype
// (cmpwi on the result) while these callers test a bool (clrlwi.).
bool is_com_card_window_open(void);

#endif
