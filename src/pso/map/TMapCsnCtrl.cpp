#include "pso/map/TMapCsnCtrl.h"

#include "pso/map/TObjMapCsn.h"
#include "types.h"
#include "pso/unk/TLobby_80140FF4.h"

struct Obj_80140EE4 { u8 pad[0x1c]; void *slots[0x201]; };

struct Ent_80140F18 { void *key; u8 pad[0x14]; };

struct Obj_80140F18 { u8 pad[0x1c]; Ent_80140F18 *slots[1]; };

extern "C" {
void register_slot(Obj_80140EE4 *self, void *p);
void collect_collision_groups(Obj_80140F18 *self, Ent_80140F18 *e);
}

void fn_80140DFC(saddr arg0, saddr arg1) {
    remove_value_from_id_list((s32)((void *)arg0), (u32)((void *) (TLobby__sub_80141030((void *)arg1))));
}

void remove_value_from_id_list(saddr arg0, u32 arg1) {
    s32 i;
    u32 *p;
    p = (u32 *)(arg0 + 0x1C);
    for (i = 0; i < 0x200; p++, i++) {
        if (*p == arg1) {
            u32 *src;
            u32 *dst = p;
            s32 k;
            src = ++p;
            for (k = i; k < 0x200; k++) {
                *dst = *src++;
                if (*++dst == 0) {
                    return;
                }
            }
            *p = 0;
            return;
        }
    }
}

void fn_80140EA8(saddr arg0, saddr arg1) {
    register_slot((Obj_80140EE4 *)((void *)arg0), (void *)((void *) (TLobby__sub_80141030((void *)arg1))));
}
void register_slot(Obj_80140EE4 *self, void *p) {
    s32 i;
    void **s = self->slots;
    for (i = 0; i < 0x200; i++, s++) {
        if (*s == 0) {
            s[0] = p;
            s[1] = 0;
            return;
        }
    }
}
void collect_collision_groups(Obj_80140F18 *self, Ent_80140F18 *e) {
    Ent_80140F18 **p = self->slots;
    while (e->key != 0) {
        *p++ = e;
        e++;
    }
    *p = 0;
}

// TObjMapCsn's name lives in this TU (.sdata 0x805D2CD0, string 0x8043F268), as TMapCsnCtrl's lives in
// TObjMapCsn.cpp.
const char *TObjMapCsn__class_name = "TObjMapCsn";

void TMapCsnCtrl::sub_80140F44() {
    unk_1C = 0;
}

TMapCsnCtrl::~TMapCsnCtrl() {}

TMapCsnCtrl::TMapCsnCtrl(TObject *parent) : TObject(parent) {
    m_name = TMapCsnCtrl__class_name;
    sub_80140F44();
}
