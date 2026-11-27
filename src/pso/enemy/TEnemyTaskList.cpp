#include "pso/enemy/TEnemyTaskList.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {
extern const char TEnemyTaskList_class_name[] = "TEnemyTaskList";
const char* TEnemyTaskList_name = TEnemyTaskList_class_name;
}

void TEnemyTaskList::run_task() {}

s32 TEnemyTaskList::has_undefeated_entry() {
    s32 i;
    for (i = 0; i < m_count; i++) {
        EnemySetRecord* record = m_records[i];
        if (record != 0 && !(record->flags & 8)) {
            return 1;
        }
    }
    return 0;
}

TEnemyTaskList::~TEnemyTaskList() {
    delete[] m_records;
    delete[] m_enemies;
}

TEnemyTaskList::TEnemyTaskList(TObject* parent, s32 capacity) : TObject(parent) {
    s32 i;
    m_name = TEnemyTaskList_name;
    m_capacity = capacity;
    m_count = 0;
    m_enemies = new TObjEnemy *[m_capacity];
    m_records = new EnemySetRecord *[m_capacity];
    for (i = 0; i < m_capacity; i++) {
        m_enemies[i] = 0;
        m_records[i] = 0;
    }
}
