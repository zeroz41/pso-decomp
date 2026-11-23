#ifndef PSO_UI_WINDOW_TOBJDEADLISTWIN_H
#define PSO_UI_WINDOW_TOBJDEADLISTWIN_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;

struct DeadPlayerName {
    char text[15];
    char terminator;
};

class TObjDeadListWin : public TObject {
public:
    s32 m_phase;
    TWindowMessage *m_window_handle;
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
LAYOUT_ASSERT(DeadListBaseSize, sizeof(TObject)==0x1C);
LAYOUT_ASSERT(DeadListSize, sizeof(TObjDeadListWin)==0x68);
LAYOUT_ASSERT(DeadListPhase, offsetof(TObjDeadListWin,m_phase)==0x1C);
LAYOUT_ASSERT(DeadListHandle, offsetof(TObjDeadListWin,m_window_handle)==0x20);
LAYOUT_ASSERT(DeadListCountdown, offsetof(TObjDeadListWin,m_countdown)==0x24);
LAYOUT_ASSERT(DeadListNames, offsetof(TObjDeadListWin,m_names)==0x28);
LAYOUT_ASSERT(DeadNameSize, sizeof(DeadPlayerName)==0x10);
LAYOUT_ASSERT(DeadNameTerminator, offsetof(DeadPlayerName,terminator)==15);
#endif
