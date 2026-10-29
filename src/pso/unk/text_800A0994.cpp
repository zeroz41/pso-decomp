#include "types.h"
#include "pso/enemy/TObjEneDarkGunCenter.h"

struct Player_800A0994 {
    u8 pad0[0x28];
    s16 f28;
    u8 pad2A[0x354 - 0x2A];
    f32 f354;
    u8 pad358[0x428 - 0x358];
    u16 f428;
};

struct Ene_800A0994 {
    u8 pad0[0x358];
    f32 f358;
};

struct Gunner_800A0994 {
    u8 pad0[0x1C];
    u16 f1C;
    u8 pad1E[0x28 - 0x1E];
    s16 f28;
    u8 pad2A[0x354 - 0x2A];
    f32 f354;
    u8 pad358[0x37C - 0x358];
    s32 count;
    u8 pad380[0x384 - 0x380];
    u16 ids[16];
};

extern "C" {
int get_player_data__10TObjPlayerFi(int a0);
s16 get_entity_id(void *);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
u8 *get_enemy_entity(u16 arg0);
extern s32 dark_gunner_class_name_ptr;
extern s32 registered_player_count;
extern s32 lbl_805D5870;
void TObjEneDarkGunCenter::sub_800A0994() {
    Gunner_800A0994 *self = (Gunner_800A0994 *)this;
    s32 k;
    Ene_800A0994 *a;
    Player_800A0994 *p;
    s32 m;
    Ene_800A0994 *b;
    s32 i;
    s32 j;
    self->count = 0;
    for (k = registered_player_count; k < registered_player_count + lbl_805D5870; k++) {
        p = (Player_800A0994 *)get_player_data__10TObjPlayerFi(k);
        if (p != NULL && check_value_equals__13TUnk_804B6C24Fl(p, dark_gunner_class_name_ptr) != 0 &&
            self->f354 == p->f354 && self->f28 == p->f28) {
            p->f428 = self->f1C;
            self->ids[self->count++] = get_entity_id(p);
            if (self->count >= 16) {
                break;
            }
        }
    }
    for (m = self->count; m < 16; m++) {
        self->ids[m] = 0xFFFF;
    }
    for (i = 0; i < self->count - 1; i++) {
        for (j = i + 1; j < self->count; j++) {
            a = (Ene_800A0994 *)get_enemy_entity(self->ids[i]);
            b = (Ene_800A0994 *)get_enemy_entity(self->ids[j]);
            if (a != NULL && b != NULL && a->f358 > b->f358) {
                u16 t = self->ids[i];
                self->ids[i] = self->ids[j];
                self->ids[j] = t;
            }
        }
    }
}

}
