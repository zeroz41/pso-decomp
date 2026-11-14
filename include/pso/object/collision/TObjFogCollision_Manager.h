#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_MANAGER_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_MANAGER_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjFogCollision_Manager : public TObject {
public:
    TObjFogCollision_Manager(TObject *parent, s32 index);
    virtual ~TObjFogCollision_Manager();
    virtual void run_task();
    void record_hit(s32 level, s32 link);
    // inferred: from record_hit and run_task.
    s32 hit_count;  // hits since the last run_task
    s32 fog_level;  // highest level recorded this frame
    s32 fog_link;   // nonzero selects fog bank 0, else bank 1
    s32 player;     // index into TObjFogCollisionPoison__instances and the fog viewports
    s32 cleared;    // 1 once the player's fog is restored
};
typedef char TObjFogCollision_Manager_size[sizeof(TObjFogCollision_Manager) == 0x30 ? 1 : -1];

#endif
