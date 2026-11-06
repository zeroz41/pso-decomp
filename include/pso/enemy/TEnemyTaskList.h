#ifndef PSO_ENEMY_TENEMYTASKLIST_H
#define PSO_ENEMY_TENEMYTASKLIST_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct TObjEnemy;

struct EnemySetRecord {
    u16 unknown00;
    s16 flags;
    s16 enemy_index;
    u8 unknown06[6];
    s16 room;
    s16 wave;
    u8 unknown10[0x34];
    TObjEnemy* enemy;
};

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
typedef char EnemySetRecordSize[(sizeof(EnemySetRecord)==0x48)?1:-1];
typedef char EnemySetRecordFlags[(offsetof(EnemySetRecord,flags)==2)?1:-1];
typedef char EnemySetRecordIndex[(offsetof(EnemySetRecord,enemy_index)==4)?1:-1];
typedef char EnemySetRecordRoom[(offsetof(EnemySetRecord,room)==0xC)?1:-1];
typedef char EnemySetRecordWave[(offsetof(EnemySetRecord,wave)==0xE)?1:-1];
typedef char EnemySetRecordEnemy[(offsetof(EnemySetRecord,enemy)==0x44)?1:-1];
#endif
