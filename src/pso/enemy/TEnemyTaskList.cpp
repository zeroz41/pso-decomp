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
    mem_free(m_records);
    mem_free(m_enemies);
}

TEnemyTaskList::TEnemyTaskList(TObject* parent, s32 capacity) : TObject(parent) {
    s32 i;
    m_name = TEnemyTaskList_name;
    m_capacity = capacity;
    m_count = 0;
    m_enemies = (TObjEnemy**)mem_alloc(m_capacity * 4);
    m_records = (EnemySetRecord**)mem_alloc(m_capacity * 4);
    for (i = 0; i < m_capacity; i++) {
        m_enemies[i] = 0;
        m_records[i] = 0;
    }
}
