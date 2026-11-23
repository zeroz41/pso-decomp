#ifndef PSO_UI_WINDOW_TWINDOWRETURNCITY_H
#define PSO_UI_WINDOW_TWINDOWRETURNCITY_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMessageYesNo;

// Yes/no prompt shown to the player of client after a defeat; yes sends the party
// back to floor 0, the city.
struct TWindowReturnCity : public TObject {
    TWindowReturnCity(TObject *parent, s32 client);
    virtual ~TWindowReturnCity();
    TWindowMessageYesNo *yes_no_window;
    u32 state;
    s32 client;
    static const char *class_name;
    s32 query_battle_state();
    virtual void render();
    virtual void run_task();
    static void clear_flag_bit5();
};

LAYOUT_ASSERT(TWindowReturnCity_size, sizeof(TWindowReturnCity) == 0x28);

// Floor-resource release/load pair run from the lobby session load table.
extern "C" {
void TWindowReturnCity__sub_8026D4BC(void);
void TWindowReturnCity__sub_8026D4C0(void);
}
#endif
