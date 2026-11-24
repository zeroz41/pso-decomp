#include "types.h"
#include "pso/player/PlayerTrapCounts.h"

s32 PlayerSonarStock::consume(s32 amount) {
    count -= amount;
    if (count < 0) {
        count = 0;
        return 0;
    }
    return 1;
}

s32 PlayerSonarStock::get_count() {
    s32 value = count;
    if (value < 0 || value > 99) {
        return 0;
    }
    return value;
}

void PlayerSonarStock::set_count(s32 value) {
    if (value < 0 || value > 99) {
        value = 0;
    }
    count = value;
}

bool PlayerTrapCounts::is_empty(s32 kind) {
    return counts[kind] <= 0;
}

void PlayerTrapCounts::clear() {
    s8 *count = counts;
    s32 i;

    for (i = 4; i != 0; i -= 1) {
        *count = 0;
        count += 1;
    }
}

s32 PlayerTrapCounts::is_full(s32 level, s8 char_class) {
    s32 kind;
    s8 max;
    for (kind = 0; kind < 4; kind++) {
        if (kind != 2) {
            max = calc_trap_capacity(level, char_class, kind);
            if (kind < 4 && counts[kind] < max) {
                return 0;
            }
        }
    }
    return 1;
}

void PlayerTrapCounts::refill(s32 level, s8 char_class) {
    s32 kind;
    for (kind = 0; kind < 4; kind++) {
        s8 capacity = calc_trap_capacity(level, char_class, kind);
        set_count(capacity, kind);
    }
}

s8 calc_trap_capacity(s32 level, s8 char_class, s32 kind) {
    s32 level_number;
    s8 capacity;

    level_number = level + 1;
    capacity = 0;
    switch (char_class) {
    case 3:
        break;
    case 2:
        switch (kind) {
        case 2:
            break;
        case 0:
            capacity = (level_number / 11) + 2;
            break;
        case 1:
        case 3:
            capacity = (level_number / 7) + 2;
            break;
        }
        break;
    case 4:
        switch (kind) {
        case 2:
            break;
        case 0:
            capacity = (level_number / 7) + 2;
            break;
        case 1:
            capacity = (level_number / 9) + 2;
            break;
        case 3:
            capacity = (level_number / 11) + 2;
            break;
        }
        break;
    case 5:
        switch (kind) {
        case 2:
            break;
        case 0:
            capacity = (level_number / 7) + 2;
            break;
        case 1:
            capacity = (level_number / 11) + 2;
            break;
        case 3:
            capacity = (level_number / 9) + 2;
            break;
        }
        break;
    case 9:
        switch (kind) {
        case 2:
            break;
        case 0:
            capacity = (level_number / 9) + 2;
            break;
        case 1:
            capacity = (level_number / 10) + 2;
            break;
        case 3:
            capacity = (level_number / 10) + 2;
            break;
        }
        break;
    }
    if ((capacity < 0) || (capacity > 20)) {
        return 20;
    }
    return capacity;
}

s32 PlayerTrapCounts::consume(s32 amount, s32 kind) {
    counts[kind] = (u8)counts[kind] - amount;
    if (counts[kind] < 0) {
        counts[kind] = 0;
        return 0;
    }
    return 1;
}

s8 PlayerTrapCounts::get_count(s32 kind) {
    if (counts[kind] < 0 || counts[kind] > 20) {
        counts[kind] = 0;
    }
    return counts[kind];
}

void PlayerTrapCounts::set_count(s8 count, s32 kind) {
    if (count < 0 || count > 20) {
        count = 20;
    }
    counts[kind] = count;
}

PlayerTrapCounts *PlayerTrapCounts::init() {
    clear();
    return this;
}
