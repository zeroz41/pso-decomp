#include "types.h"
#include "pso/misc/TLobby.h"
struct Set_8020C9C8 {
    s16 f0;
    s16 flags;
    s16 f4;
    u8 pad6[4];
    s16 z;
    s16 x;
    u8 padE[0x32];
    void *obj;
};

struct ObjBase_8020C9C8 { u8 pad[0x18]; };

struct Obj_8020C9C8 : ObjBase_8020C9C8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(void *, s32);
    u8 pad1c[0xC];
    s16 x;
    s16 z;
    s16 kind;
    u8 pad2e[0x52];
    Set_8020C9C8 *set;
};

extern "C" {
s32 get_current_floor();
s32 set_room_group_flags__6TLobbyFlssl(s32, s32, s32, s32);
int get_object_count__6TLobbyFPv(void *p);
Obj_8020C9C8 *create_set_object_from_row(Set_8020C9C8 *);
extern u8 *quest_object_entries;
s32 unhide_room_set_objects(s32 arg0, s32 arg1, s32 arg2);
s32 unhide_room_set_objects(s32 arg0, s32 arg1, s32 arg2) {
    s32 n;
    s32 count;
    s32 local;
    Set_8020C9C8 *set;
    s32 i;
    Obj_8020C9C8 *obj;
    count = 0;
    local = 0;
    if (arg0 == get_current_floor()) {
        local = 1;
    }
    if (local == 0) {
        return set_room_group_flags__6TLobbyFlssl(arg0, arg1, arg2, 1);
    }
    set = (Set_8020C9C8 *)get_object_count__6TLobbyFPv((void *)arg0);
    n = TLobby::get_obj_table_entry(arg0);
    for (i = 0; i < n; i++, set++) {
        if (set->flags & 8) continue;
        if (set->flags & 2) continue;
        if (set->flags & 1) continue;
        if (set->x != (s16)arg1) continue;
        if (set->z != (s16)arg2) continue;
        if (local != 0) {
            obj = create_set_object_from_row(set);
            if (obj != NULL) {
                set->obj = obj;
                set->flags |= 0x12;
                obj->x = set->x;
                obj->z = set->z;
                obj->kind = set->f4;
                obj->set = set;
                if (obj->kind != -1) {
                    obj->v4(quest_object_entries + obj->kind * 4, 0);
                }
                count++;
            } else {
                set->obj = NULL;
            }
        } else {
            set->flags |= 1;
            count++;
        }
    }
    return count;
}

}
