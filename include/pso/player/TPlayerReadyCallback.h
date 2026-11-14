#ifndef PSO_PLAYER_TPLAYERREADYCALLBACK_H
#define PSO_PLAYER_TPLAYERREADYCALLBACK_H
#include "pso/system/task/TObject.h"
struct TObjPlayer;
class TPlayerReadyCallback : public TObject {
public:
    TPlayerReadyCallback(TObject*, u16, void (*)(TObjPlayer*));
    virtual void run_task();
    virtual ~TPlayerReadyCallback();
    u16 player_id;
    void (*callback)(TObjPlayer*);
};
typedef char ReadyCallback_size[sizeof(TPlayerReadyCallback) == 0x24 ? 1 : -1];
#endif
