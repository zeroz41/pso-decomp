#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/memory.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/object/ambient/TObjGrassWeb.h"

#include "pso/enemy/AttackTargetHistory.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"


extern "C" {

s32 attack_target_history_add(AreaAttackHistory *history, TObjChara *target) {
    if (fn_800BC758(history) != 0 && attack_target_history_contains(history, target) == 0) {
        push_attack_target_entry(history, target);
        return 1;
    }
    return 0;
}

AreaAttackHistory::~AreaAttackHistory() {}

AreaAttackHistory::AreaAttackHistory(s32 capacity) : PointerBuffer(capacity, NULL) {}

PointerBuffer::PointerBuffer(s32 capacity, void *empty) {
    if (capacity > 0) {
        entries = (void **)mem_alloc(capacity * sizeof(void *));
    } else {
        entries = NULL;
    }
    this->empty = empty;
    count = 0;
    this->capacity = capacity;
    fill_value_array(this);
}

PointerBuffer::~PointerBuffer() {
    if (entries != NULL) {
        mem_free(entries);
        entries = NULL;
    }
}
}

s32 push_attack_target_entry(PointerBuffer *buffer, void *entry) {
    s32 count = buffer->count;
    if (count < buffer->capacity) {
        buffer->entries[count] = entry;
        return buffer->count++;
    }
    return -1;
}

int attack_target_history_contains(void* object, void* target) {
    AreaAttackHistory* history = static_cast<AreaAttackHistory*>(object);
    for (s32 i = 0; i < history->count; ++i) {
        if (history->entries[i] == target) return 1;
    }
    return 0;
}

s32 fn_800BC758(PointerBuffer *buffer) {
    return buffer->count < buffer->capacity;
}
