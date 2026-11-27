#ifndef PSO_NETWORK_TLOBBYIDLETIMER_H
#define PSO_NETWORK_TLOBBYIDLETIMER_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The lobby idle timer: TLobby::update_idle_timeout warns when the idle limit is near and ends the session at it.
// On CodeWarrior TLobby.cpp's hand-built vtable holds TLobby::update_idle_timeout and render_idle_timeout in
// the run_task and render slots.
class TLobbyIdleTimer : public TObject {
public:
    TLobbyIdleTimer(TObject *parent) : TObject(parent) {}
    virtual ~TLobbyIdleTimer();
    virtual void run_task();
    virtual void render();

    int now;   // DateToSeconds of the current date, every frame
    s32 start; // the time of the last key or pad input
    u32 limit; // the idle time allowed
    u8 state;  // 1 once the warning window is shown
    u8 pad_29[0x3];
};
LAYOUT_ASSERT(TLobbyIdleTimer_size, sizeof(TLobbyIdleTimer) == 0x2C);

// The idle time allowed for the client, from its character's idle timeout setting.
s32 get_idle_timeout_limit(u32 client_id);

// TLobbyIdleTimer::~TLobbyIdleTimer(), for CodeWarrior's hand-built idle timer vtable in TLobby.cpp.
#ifdef __MWERKS__
extern "C" {
void *__dt__15TLobbyIdleTimerFv(void *object, s16 dtor_flags);
}
#endif

#endif
