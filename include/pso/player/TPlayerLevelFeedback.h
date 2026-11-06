#ifndef PSO_PLAYER_TPLAYERLEVELFEEDBACK_H
#define PSO_PLAYER_TPLAYERLEVELFEEDBACK_H
#include "pso/system/task/TObject.h"
struct TObjPlayer;
class TPlayerLevelFeedback : public TObject {
public:
    TPlayerLevelFeedback(TObject*, u16);
    virtual ~TPlayerLevelFeedback();
    virtual void run_task();
    u16 player_id;
    s32 timer;
};
typedef char LevelFeedback_size[sizeof(TPlayerLevelFeedback) == 0x24 ? 1 : -1];
#endif
