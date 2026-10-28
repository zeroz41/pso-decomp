#include "types.h"
#include "pso/unk/text_80365348.h"

typedef struct Ent_803653A4 { s32 id; s32 arg; } Ent_803653A4;

extern "C" {
void TLobby__sub_8001FE7C(void *, int);
extern u32 labo_design_object_table[];
void *load_resource_from_descriptor(void *, s32, s32, s32, s32, s32);
}
extern Ent_803653A4 lbl_804F2C08[];
void free_object_table(void) {
    s32 i;
    for (i = 5; i >= 0; i--) {
        if (labo_design_object_table[i] != 0) {
            TLobby__sub_8001FE7C((void *)labo_design_object_table[i], 1);
            labo_design_object_table[i] = 0;
        }
    }
}

void fn_803653A4(void) {
    s32 i;
    Ent_803653A4 *e;
    void *p;
    for (i = 0; i < 6; i++) {
        labo_design_object_table[i] = 0;
    }
    e = lbl_804F2C08;
    if (e != NULL) {
        while (e->id != -1) {
            p = ::operator new(0x440);
            if (p != NULL) {
                p = load_resource_from_descriptor(p, 5, e->arg, 0, 0, 0);
            }
            labo_design_object_table[e->id] = (u32)p;
            e++;
        }
    }
}
