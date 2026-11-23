#ifndef PSO_OBJECT_LOBBY_TGOGOBALLGAME_H
#define PSO_OBJECT_LOBBY_TGOGOBALLGAME_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Gogo-ball round controller: creates the timer window, spawns the goal markers on the beat.
class TGoGoBallGame : public TObject {
public:
    static void create();
    TGoGoBallGame(TObject *parent);
    virtual ~TGoGoBallGame();
    virtual void run_task();
    virtual void render();
    s32 beat; // inferred: TLobby::get_internet_beat() of the last run_task
};
LAYOUT_ASSERT(TGoGoBallGame_size, sizeof(TGoGoBallGame) == 0x20);

#endif
