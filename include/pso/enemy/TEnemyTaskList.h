#ifndef PSO_ENEMY_TENEMYTASKLIST_H
#define PSO_ENEMY_TENEMYTASKLIST_H
#include "pso/system/task/TObject.h"
#include "pso/map/FloorPopulation.h"
#include "types.h"

struct TObjEnemy;

class TEnemyTaskList : public TObject {
public:
    s32 m_capacity;
    s32 m_count;
    TObjEnemy** m_enemies;
    EnemySetRecord** m_records;

    TEnemyTaskList(TObject* parent, s32 capacity);
    virtual ~TEnemyTaskList();
    virtual void run_task();
    s32 has_undefeated_entry();
};

#include <stddef.h>
typedef char EnemyTaskListBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char EnemyTaskListSize[(sizeof(TEnemyTaskList)==0x2C)?1:-1];
typedef char EnemyTaskListCapacity[(offsetof(TEnemyTaskList,m_capacity)==0x1C)?1:-1];
typedef char EnemyTaskListCount[(offsetof(TEnemyTaskList,m_count)==0x20)?1:-1];
typedef char EnemyTaskListEnemies[(offsetof(TEnemyTaskList,m_enemies)==0x24)?1:-1];
typedef char EnemyTaskListRecords[(offsetof(TEnemyTaskList,m_records)==0x28)?1:-1];
#endif
