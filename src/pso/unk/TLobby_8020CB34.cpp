#include "pso/map/FloorPopulation.h"
#include "types.h"
#include "pso/unk/TLobby_8020B334.h"
#include "pso/network/TLobby.h"

struct VObj8020 {
    char pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
};

extern "C" {

u8 *create_set_object_from_row(void *);

extern s32 quest_object_entries;

s32 TLobby::spawn_objects_at_pos(s16 room, s16 wave) {
    s16 set_index;
    s16 flags;
    s32 obj_table_entry;
    s32 spawned;
    FloorObjectSetRow *row;
    s32 k;
    u8 *set_object;

    spawned = 0;
    row = get_active_floor_object_rows(active_set_floor);
    obj_table_entry = TLobby::get_obj_table_entry(active_set_floor);
    for (k = 0; k < obj_table_entry; k++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->placement.room == room) && (row->placement.wave == wave)) {
            set_object = create_set_object_from_row(row);
            if (set_object != NULL) {
                row->object = (TObject *)set_object;
                row->flags = (s16) (row->flags | 0x12);
                *(s16 *)((s8 *)set_object + 0x28) = row->placement.room;
                *(s16 *)((s8 *)set_object + 0x2A) = row->placement.wave;
                *(s16 *)((s8 *)set_object + 0x2C) = row->placement.set_index;
                *(void **)((s8 *)set_object + 0x80) = row;
                set_index = *(s16 *)((s8 *)set_object + 0x2C);
                if (set_index != -1) {
                    ((VObj8020*)set_object)->m4(quest_object_entries + (set_index * 4), 0);
                }
                spawned += 1;
            } else {
                row->object = NULL;
            }
        }
    }
    return spawned;
}

}
