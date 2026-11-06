#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/memory.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/object/ambient/TObjGrassWeb.h"

#include "pso/enemy/AttackTargetHistory.h"


extern "C" {
void *mem_alloc(u32 size);
s32 fill_value_array(void *);
void mem_free(void *p);

s32 attack_target_history_add(s32 object, s32 target) {
    if ((fn_800BC758((u8 *)object) != 0) && (((s32)attack_target_history_contains((void*)((void *)((void *)object)), (void*)((void *)((void *)target)))) == 0)) {
        ((s32)push_attack_target_entry((u8 *)object, (s32)target));
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

s32 push_attack_target_entry(u8 *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r6;
    temp_r6 = *(s32 *)((s8 *)arg0 + 8);
    if (temp_r6 < (s32) *(s32 *)((s8 *)arg0 + 0xC)) {
        *(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0)) + (temp_r6 * 4)) = arg1;
        temp_r4 = *(s32 *)((s8 *)arg0 + 8);
        *(s32 *)((s8 *)arg0 + 8) = (temp_r4 + 1);
        return temp_r4;
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

s32 fn_800BC758(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 8) < *(s32 *)((s8 *)arg0 + 0xC);
}
