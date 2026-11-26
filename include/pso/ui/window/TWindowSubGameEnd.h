#ifndef PSO_UI_WINDOW_TWINDOWSUBGAMEEND_H
#define PSO_UI_WINDOW_TWINDOWSUBGAMEEND_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMessageYesNo;

// Main-menu "end the game" prompt: a yes/no window; yes logs out and returns to
// character select.
struct TWindowSubGameEnd : public TObject {
    TWindowSubGameEnd(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubGameEnd();
    u32 state;
    saddr client;
    TWindowMainMenu *parent_menu;
    TWindowMessageYesNo *yes_no_window;
    static const char *class_name;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubGameEnd_size, sizeof(TWindowSubGameEnd) == 0x2C);

void clear_game_end_window_flag_on_floor_free(void);
void clear_game_end_window_flag_on_floor_load(void);

void init_char_select(TObject *fade);

#endif
