#include "types.h"
#include "pso/misc/TLobby_8020B334.h"
#include "pso/misc/TLobby.h"

extern "C" {

u8 *create_set_object_from_row(void *);

struct VObj8020 {
    char pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
};
extern s32 TLobby__data_805D60FC;
extern s32 quest_object_entries;

s32 TLobby::spawn_objects_at_pos(s16 arg0, s16 arg1) {
    s16 temp_r0;
    s16 temp_r3;
    s32 obj_table_entry;
    s32 var_r30;
    u8 *var_r29;
    s32 var_r28;
    u8 *set_object;

    var_r30 = 0;
    var_r29 = (u8 *)get_object_count__6TLobbyFPv((void *)TLobby__data_805D60FC);
    obj_table_entry = TLobby::get_obj_table_entry(TLobby__data_805D60FC);
    for (var_r28 = 0; var_r28 < obj_table_entry; var_r28++, var_r29 += 0x44) {
        temp_r3 = *(s16 *)((s8 *)var_r29 + 2);
        if (!(temp_r3 & 8) && !(temp_r3 & 2) && ((s16) *(s16 *)((s8 *)var_r29 + 0xC) == arg0) && ((s16) *(s16 *)((s8 *)var_r29 + 0xA) == arg1)) {
            set_object = create_set_object_from_row(var_r29);
            if (set_object != NULL) {
                *(void **)((s8 *)var_r29 + 0x40) = set_object;
                *(s16 *)((s8 *)var_r29 + 2) = (s16) (*(s16 *)((s8 *)var_r29 + 2) | 0x12);
                *(s16 *)((s8 *)set_object + 0x28) = (s16) *(s16 *)((s8 *)var_r29 + 0xC);
                *(s16 *)((s8 *)set_object + 0x2A) = (s16) *(s16 *)((s8 *)var_r29 + 0xA);
                *(s16 *)((s8 *)set_object + 0x2C) = (s16) *(s16 *)((s8 *)var_r29 + 4);
                *(void **)((s8 *)set_object + 0x80) = var_r29;
                temp_r0 = *(s16 *)((s8 *)set_object + 0x2C);
                if (temp_r0 != -1) {
                    ((VObj8020*)set_object)->m4(quest_object_entries + (temp_r0 * 4), 0);
                }
                var_r30 += 1;
            } else {
                *(void **)((s8 *)var_r29 + 0x40) = NULL;
            }
        }
    }
    return var_r30;
}

}
