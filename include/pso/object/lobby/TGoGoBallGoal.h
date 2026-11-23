#ifndef PSO_OBJECT_LOBBY_TGOGOBALLGOAL_H
#define PSO_OBJECT_LOBBY_TGOGOBALLGOAL_H
#include "types.h"
#include "pso/system/task/TObject.h"

// A Go-Go ball goal (fd_obj804_gorl03_dai.gj), spawned by TGoGoBallGame::run_task. While the sync
// state reports a goal here its flaps open and it plays the ball type's celebration.
class TGoGoBallGoal : public TObject {
public:
    TGoGoBallGoal(Vec *pos, s32 team0, s32 three_point, s32 lifetime, TObject *parent);
    TGoGoBallGoal(Vec *pos, s32 team0, s32 lifetime, TObject *parent);
    virtual ~TGoGoBallGoal();
    void update_effects();
    virtual void render();
    virtual void run_task();
    Vec pos;
    s32 team0;        // the goal scores for team 0 (sync goal flags 1/0x10), else team 1 (2/0x20)
    s32 age;          // frames since the goal was created
    s32 goal_frames;  // frames since the current goal was scored; times the celebration effects
    s32 lifetime;     // run_task destroys the goal when age reaches it
    s32 flap_angle;   // opening angle of the two flaps, 0 to 0x4000
    s32 active;       // set while the sync goal flags report a goal here
    s32 three_point;  // a three-point goal
};
LAYOUT_ASSERT(TGoGoBallGoal_size, sizeof(TGoGoBallGoal) == 0x44);

#endif
