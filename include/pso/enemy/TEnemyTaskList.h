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
LAYOUT_ASSERT(EnemyTaskListBaseSize, sizeof(TObject)==0x1C);
LAYOUT_ASSERT(EnemyTaskListSize, sizeof(TEnemyTaskList)==0x2C);
LAYOUT_ASSERT(EnemyTaskListCapacity, offsetof(TEnemyTaskList,m_capacity)==0x1C);
LAYOUT_ASSERT(EnemyTaskListCount, offsetof(TEnemyTaskList,m_count)==0x20);
LAYOUT_ASSERT(EnemyTaskListEnemies, offsetof(TEnemyTaskList,m_enemies)==0x24);
LAYOUT_ASSERT(EnemyTaskListRecords, offsetof(TEnemyTaskList,m_records)==0x28);
#endif
