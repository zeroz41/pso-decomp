#ifndef PSO_UNK_TUNK_804B8E00_H
#define PSO_UNK_TUNK_804B8E00_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Gogo-ball round controller: creates the timer window, spawns the goal markers on the beat.
class TUnk_804B8E00 : public TObject {
public:
    TUnk_804B8E00(TObject *parent);
    virtual ~TUnk_804B8E00();
    virtual void run_task();
    virtual void render();
    s32 beat; // inferred: TLobby::get_internet_beat() of the last run_task
};
typedef char TUnk_804B8E00_size[sizeof(TUnk_804B8E00) == 0x20 ? 1 : -1];

#endif
