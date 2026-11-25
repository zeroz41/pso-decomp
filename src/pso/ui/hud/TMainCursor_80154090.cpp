#include "types.h"
#include "pso/ui/hud/TMainCursor_80154090.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/system/data/FlagWord.h"

extern "C" {
s32 test_flags_any(s32 flags, s32 mask, s32 table);

void TMainCursor__sub_80154090(void) {  }
void TMainCursor__sub_80154094(void) {  }

void TMainCursor__sub_80154098(void *self, TargetCandidateEntry *arr, s32 i) {
    if (arr != 0) {
        arr[i].flags |= 0x80000000;
    }
}

void TMainCursor__sub_801540B8(void *self, TargetCandidateEntry *arr, s32 i) {
    if (arr != 0) {
        arr[i].flags |= 0x40000000;
    }
}

void clear_bodies_collision_flag(TargetCandidateEntry *arr, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        arr->flags &= ~1;
        arr++;
    }
}
void set_bodies_collision_flag(TargetCandidateEntry *arr, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        arr->flags |= 1;
        arr++;
    }
}

void TObjCollidable::disable_all_bodies() { clear_bodies_collision_flag((TargetCandidateEntry *)bodies, body_count); }
void TObjCollidable::enable_all_bodies() { set_bodies_collision_flag((TargetCandidateEntry *)bodies, body_count); }

s32 TMainCursor::test_button(s32 index, u16 target_id) {
    s32 flag_table;

    if (((s32 (*)(void))TMainCursor__sub_80154288)() != 0) {
        flag_table = *(s32 *)((s8 *)this + 0x9C);
        return test_flags_any(flag_table + (index * 4), 1 << target_id, flag_table);
    }
    return 0;
}
void TMainCursor::set_flag_bit(s32 index, u16 target_id) {
    saddr flag_table;

    if (((s32 (*)(void))TMainCursor__sub_80154288)() != 0) {
        flag_table = *(s32 *)((s8 *)this + 0x9C);
        ((FlagWord *)(flag_table + (index * 4)))->clear(1 << target_id);
    }
}
void TMainCursor__sub_80154230(void *cursor, s32 index, u16 target_id) {
    saddr flag_table;

    if (((s32 (*)(void))TMainCursor__sub_80154288)() != 0) {
        flag_table = *(s32 *)((s8 *)cursor + 0x9C);
        ((FlagWord *)(flag_table + (index * 4)))->set(1 << target_id);
    }
}

s32 TMainCursor__sub_80154288(u8 *cursor, s32 index, u16 target_id) {
    if ((u32) *(u32 *)((s8 *)cursor + 0x9C) == 0U) {
        return 0;
    }
    if (target_id >= 0xCU) {
        return 0;
    }
    return index < *(s32 *)((s8 *)cursor + 0xA8);
}

}
