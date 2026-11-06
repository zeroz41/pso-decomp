#ifndef PSO_UI_WINDOW_TWINDOW_H
#define PSO_UI_WINDOW_TWINDOW_H

#include "types.h"

struct TWindow
{
    void close_sub_windows();
};

class TShopWindowBase;
void handle_confirm_dialog(TShopWindowBase *arg0);

#endif
