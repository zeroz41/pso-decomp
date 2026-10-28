#include "types.h"
#include "pso/misc/TLobby.h"

struct VBase { char pad[0x18]; };
struct VObj : VBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
};

extern "C" {

u8 *create_set_object_from_row(void *);
u8 *get_object_count__6TLobbyFPv();

extern s32 quest_object_entries;

void TLobby::attach_objects_by_id(s32 arg0) {
    s16 temp_r3;
    s16 temp_r0;
    s32 count;
    u8 *ptr;
    s32 i;
    u8 *set_object;

    ptr = get_object_count__6TLobbyFPv();
    count = TLobby::get_obj_table_entry(arg0);
    for (i = 0; i < count; i++, ptr += 0x44) {
        temp_r3 = *(s16 *)((s8 *)ptr + 2);
        if (!(temp_r3 & 8) && !(temp_r3 & 2) && (*(s16 *)((s8 *)ptr + 0) != -1) && ((temp_r3 & 0x10) || (temp_r3 & 1) || (*(s16 *)((s8 *)ptr + 0xA) == 0))) {
            set_object = create_set_object_from_row(ptr);
            if (set_object != NULL) {
                *(void **)((s8 *)ptr + 0x40) = set_object;
                *(s16 *)((s8 *)ptr + 2) = (s16) (*(s16 *)((s8 *)ptr + 2) | 2);
                *(s16 *)((s8 *)set_object + 0x28) = (s16) *(s16 *)((s8 *)ptr + 0xC);
                *(s16 *)((s8 *)set_object + 0x2C) = (s16) *(s16 *)((s8 *)ptr + 4);
                *(void **)((s8 *)set_object + 0x80) = ptr;
                temp_r0 = *(s16 *)((s8 *)set_object + 0x2C);
                if (temp_r0 != -1) {
                    ((VObj *) set_object)->m4(quest_object_entries + (temp_r0 * 4), 0);
                }
            } else {
                *(void **)((s8 *)ptr + 0x40) = NULL;
            }
            *(s16 *)((s8 *)ptr + 2) = (s16) (*(s16 *)((s8 *)ptr + 2) & 0xFFFFFFFE);
        }
    }
}

}
