#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/map/FloorPopulation.h"

struct VBase_8020d1bc { char pad[0x18]; };
struct VObj_8020d1bc : VBase_8020d1bc {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
};

extern "C" {

u8 *create_set_object_from_row(void *);

extern s32 quest_object_entries;

void TLobby::assign_objects_to_slots(u8 *rows, s32 object_count) {
    s16 flags;
    s16 set_index;
    FloorObjectSetRow *row;
    s32 i;
    u8 *set_object;

    row = (FloorObjectSetRow *)rows;
    for (i = 0; i < object_count; i++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->type != -1) && ((flags & 0x10) || (flags & 1) || (row->placement.wave == 0))) {
            set_object = create_set_object_from_row(row);
            if (set_object != NULL) {
                row->object = (TObject *)set_object;
                row->flags = (s16) (row->flags | 2);
                *(s16 *)((s8 *)set_object + 0x28) = row->placement.room;
                *(s16 *)((s8 *)set_object + 0x2C) = row->placement.set_index;
                *(void **)((s8 *)set_object + 0x80) = row;
                set_index = *(s16 *)((s8 *)set_object + 0x2C);
                if (set_index != -1) {
                    ((VObj_8020d1bc *) set_object)->m4(quest_object_entries + (set_index * 4), 0);
                }
            } else {
                row->object = NULL;
            }
            row->flags = (s16) (row->flags & 0xFFFFFFFE);
        }
    }
}

}
