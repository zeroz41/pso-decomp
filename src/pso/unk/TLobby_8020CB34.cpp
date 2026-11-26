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
    s16 quest_entry;
    s16 flags;
    s32 obj_table_entry;
    s32 spawned;
    u8 *row;
    s32 k;
    u8 *set_object;

    spawned = 0;
    row = reinterpret_cast<u8 *>(get_active_floor_object_rows(active_set_floor));
    obj_table_entry = TLobby::get_obj_table_entry(active_set_floor);
    for (k = 0; k < obj_table_entry; k++, row += 0x44) {
        flags = *(s16 *)((s8 *)row + 2);
        if (!(flags & 8) && !(flags & 2) && ((s16) *(s16 *)((s8 *)row + 0xC) == room) && ((s16) *(s16 *)((s8 *)row + 0xA) == wave)) {
            set_object = create_set_object_from_row(row);
            if (set_object != NULL) {
                *(void **)((s8 *)row + 0x40) = set_object;
                *(s16 *)((s8 *)row + 2) = (s16) (*(s16 *)((s8 *)row + 2) | 0x12);
                *(s16 *)((s8 *)set_object + 0x28) = (s16) *(s16 *)((s8 *)row + 0xC);
                *(s16 *)((s8 *)set_object + 0x2A) = (s16) *(s16 *)((s8 *)row + 0xA);
                *(s16 *)((s8 *)set_object + 0x2C) = (s16) *(s16 *)((s8 *)row + 4);
                *(void **)((s8 *)set_object + 0x80) = row;
                quest_entry = *(s16 *)((s8 *)set_object + 0x2C);
                if (quest_entry != -1) {
                    ((VObj8020*)set_object)->m4(quest_object_entries + (quest_entry * 4), 0);
                }
                spawned += 1;
            } else {
                *(void **)((s8 *)row + 0x40) = NULL;
            }
        }
    }
    return spawned;
}

}
