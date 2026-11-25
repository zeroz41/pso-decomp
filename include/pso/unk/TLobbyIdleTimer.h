#ifndef PSO_UNK_TLOBBYIDLETIMER_H
#define PSO_UNK_TLOBBYIDLETIMER_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The lobby idle timer: TLobby::update_idle_timeout warns when the idle limit is near and ends the session at it.
class TLobbyIdleTimer : public TObject {
public:
    virtual ~TLobbyIdleTimer();
    int now;   // DateToSeconds of the current date, every frame
    s32 start; // the time of the last key or pad input
    u32 limit; // the idle time allowed
    u8 state;  // 1 once the warning window is shown
    u8 pad_29[0x3];
};
LAYOUT_ASSERT(TLobbyIdleTimer_size, sizeof(TLobbyIdleTimer) == 0x2C);

// The idle time allowed for the client, from its character's idle timeout setting.
s32 get_idle_timeout_limit(u32 client_id);

#endif
