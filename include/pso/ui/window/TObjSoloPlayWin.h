#ifndef PSO_UI_WINDOW_TOBJSOLOPLAYWIN_H
#define PSO_UI_WINDOW_TOBJSOLOPLAYWIN_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjSoloPlayWin : public TObject {
public:
    s32 m_state;
    void* m_result_window;
    s32 m_countdown;

    TObjSoloPlayWin(TObject* parent);
    virtual ~TObjSoloPlayWin();
    virtual void run_task();
    s32 has_at_most_one_player();
    s32 area_allows_win_timer();
    s32 can_start_win_timer();
    void open_result_window();
    void update_close_timer();
    void start_win_timer();
    static TObjSoloPlayWin* create(TObject* parent);
};
#include <stddef.h>
typedef char SoloWinBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char SoloWinSize[(sizeof(TObjSoloPlayWin)==0x28)?1:-1];
typedef char SoloWinState[(offsetof(TObjSoloPlayWin,m_state)==0x1C)?1:-1];
typedef char SoloWinWindow[(offsetof(TObjSoloPlayWin,m_result_window)==0x20)?1:-1];
typedef char SoloWinCountdown[(offsetof(TObjSoloPlayWin,m_countdown)==0x24)?1:-1];
#endif
