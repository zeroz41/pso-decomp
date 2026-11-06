#ifndef PSO_UI_WINDOW_TOBJDEADLISTWIN_H
#define PSO_UI_WINDOW_TOBJDEADLISTWIN_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct DeadPlayerName {
    char text[15];
    char terminator;
};

class TObjDeadListWin : public TObject {
public:
    s32 m_phase;
    u32 m_window_handle;
    s32 m_countdown;
    DeadPlayerName m_names[4];

    TObjDeadListWin(TObject* parent);
    virtual ~TObjDeadListWin();
    virtual void run_task();
    void build_dead_list_window();
    void update_countdown();
    void refresh_names();
    static TObjDeadListWin* create(TObject* parent);
};
#include <stddef.h>
typedef char DeadListBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char DeadListSize[(sizeof(TObjDeadListWin)==0x68)?1:-1];
typedef char DeadListPhase[(offsetof(TObjDeadListWin,m_phase)==0x1C)?1:-1];
typedef char DeadListHandle[(offsetof(TObjDeadListWin,m_window_handle)==0x20)?1:-1];
typedef char DeadListCountdown[(offsetof(TObjDeadListWin,m_countdown)==0x24)?1:-1];
typedef char DeadListNames[(offsetof(TObjDeadListWin,m_names)==0x28)?1:-1];
typedef char DeadNameSize[(sizeof(DeadPlayerName)==0x10)?1:-1];
typedef char DeadNameTerminator[(offsetof(DeadPlayerName,terminator)==15)?1:-1];
#endif
