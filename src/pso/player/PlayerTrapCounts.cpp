#include "types.h"
#include "pso/player/PlayerTrapCounts.h"
#include "pso/player/TObjPlayer.h"

s32 decrement_clamped(s32 *value, s32 amount) {
    *value -= amount;
    if ((s32) *value < 0) {
        *value = 0;
        return 0;
    }
    return 1;
}

s32 fn_801C5404(s32 *value) {
    s32 count;

    count = *value;
    if ((count < 0) || (count > 99)) {
        return 0;
    }
    return count;
}

void fn_801C5420(s32 *value, s32 count) {
    if ((count < 0) || (count > 99)) {
        count = 0;
    }
    *value = count;
}

bool fn_801C543C(s8 *counts, s32 kind) {
    return counts[kind] <= 0;
}

void clear_trap_counts(s8 *counts) {
    s32 i;

    for (i = 4; i != 0; i -= 1) {
        *counts = 0;
        counts += 1;
    }
}

s32 are_trap_counts_full(s8 *counts, s32 level, s8 char_class) {
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

void refill_trap_counts(s32 trap_counts, s32 level, s32 char_class) {
    s32 kind;
    for (kind = 0; kind < 4; kind++) {
        s8 capacity = ((s8 (*)(s32, s32, s32))calc_trap_capacity)(level, char_class, kind);
        TObjPlayer__sub_801C5780(trap_counts, capacity, kind);
    }
}

// Only the android classes (HUcast, RAcast, RAcaseal, HUcaseal) carry traps;
// their stock grows with level and is capped at 20.
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

s32 TObjPlayer::consume_trap_count(s32 amount, s32 kind) {
    s8 *counts = (s8 *)this;
    counts[kind] = (u8)counts[kind] - amount;
    if (counts[kind] < 0) {
        counts[kind] = 0;
        return 0;
    }
    return 1;
}

s32 TObjPlayer::clamp_char_at(s32 kind) {
    s8 *counts = (s8 *)this;
    s8 c = counts[kind];
    if (c < 0 || (s32)c > 20) {
        counts[kind] = 0;
    }
    return (u8)(counts[kind]);
}

void TObjPlayer__sub_801C5780(saddr trap_counts, s8 count, s32 kind) {
    if ((count < 0) || (count > 20)) {
        count = 20;
    }
    *(s8 *)(trap_counts + kind) = count;
}

s32 TObjPlayer::init_partial(saddr trap_counts) {
    clear_trap_counts((s8 *)trap_counts);
    return trap_counts;
}
