#include "types.h"
#include "pso/network/TLobby.h"

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
    s16 quest_entry;
    u8 *ptr;
    s32 i;
    u8 *set_object;

    ptr = rows;
    for (i = 0; i < object_count; i++, ptr += 0x44) {
        flags = *(s16 *)((s8 *)ptr + 2);
        if (!(flags & 8) && !(flags & 2) && (*(s16 *)((s8 *)ptr + 0) != -1) && ((flags & 0x10) || (flags & 1) || (*(s16 *)((s8 *)ptr + 0xA) == 0))) {
            set_object = create_set_object_from_row(ptr);
            if (set_object != NULL) {
                *(void **)((s8 *)ptr + 0x40) = set_object;
                *(s16 *)((s8 *)ptr + 2) = (s16) (*(s16 *)((s8 *)ptr + 2) | 2);
                *(s16 *)((s8 *)set_object + 0x28) = (s16) *(s16 *)((s8 *)ptr + 0xC);
                *(s16 *)((s8 *)set_object + 0x2C) = (s16) *(s16 *)((s8 *)ptr + 4);
                *(void **)((s8 *)set_object + 0x80) = ptr;
                quest_entry = *(s16 *)((s8 *)set_object + 0x2C);
                if (quest_entry != -1) {
                    ((VObj_8020d1bc *) set_object)->m4(quest_object_entries + (quest_entry * 4), 0);
                }
            } else {
                *(void **)((s8 *)ptr + 0x40) = NULL;
            }
            *(s16 *)((s8 *)ptr + 2) = (s16) (*(s16 *)((s8 *)ptr + 2) & 0xFFFFFFFE);
        }
    }
}

}
