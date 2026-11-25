#include "types.h"
#include "pso/ui/hud/TMainCursor_80154090.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/system/data/FlagWord.h"

extern "C" {
s32 test_flags_any(s32 flags, s32 mask, s32 table);

void TMainCursor__sub_80154090(void) {  }
void TMainCursor__sub_80154094(void) {  }

void TMainCursor__sub_80154098(void *unused, CollisionBody *arr, s32 i) {
    if (arr != 0) {
        arr[i].flags |= 0x80000000;
    }
}

void TMainCursor__sub_801540B8(void *unused, CollisionBody *arr, s32 i) {
    if (arr != 0) {
        arr[i].flags |= 0x40000000;
    }
}

void clear_bodies_collision_flag(CollisionBody *arr, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        arr->flags &= ~1;
        arr++;
    }
}
void set_bodies_collision_flag(CollisionBody *arr, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        arr->flags |= 1;
        arr++;
    }
}

void TObjCollidable::disable_all_bodies() { clear_bodies_collision_flag(bodies, body_count); }
void TObjCollidable::enable_all_bodies() { set_bodies_collision_flag(bodies, body_count); }

s32 TObjCollidable::test_body_flag(s32 index, u16 client) {
    if (is_body_flag_valid(index, client) != 0) {
        return test_flags_any((saddr)&body_flags[index], 1 << client, (saddr)body_flags);
    }
    return 0;
}
void TObjCollidable::clear_body_flag(s32 index, u16 client) {
    if (is_body_flag_valid(index, client) != 0) {
        body_flags[index].clear(1 << client);
    }
}
void TObjCollidable::set_body_flag(s32 index, u16 client) {
    if (is_body_flag_valid(index, client) != 0) {
        body_flags[index].set(1 << client);
    }
}

s32 TObjCollidable::is_body_flag_valid(s32 index, u16 client) {
    if (body_flags == NULL) {
        return 0;
    }
    if (client >= 0xCU) {
        return 0;
    }
    return index < body_count;
}

}
