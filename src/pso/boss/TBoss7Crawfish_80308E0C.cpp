#include "types.h"
#include "pso/object/obj_band.h"
#include "pso/boss/TBoss7Crawfish.h"

struct Pair_80308F8C { void *a; s32 b; };

struct Craw_80308F8C {
    u8 pad0[0x38];
    u8 f38[0xA4 - 0x38];
    s32 *fA4;
    u8 padA8[0x326 - 0xA8];
    s16 state;
    u8 pad328[0x3A0 - 0x328];
    s32 *f3A0;
    s32 f3A4;
    Pair_80308F8C pairs[4];
    s32 f3C8;
    s32 f3CC;
};

extern "C" {
void *create_particle_emitter(void *pos, s32 id);

extern const f32 lbl_805DF0F8;

void TBoss7Crawfish::update_attack_state() {
    s32 temp_r0;
    s32 temp_r3;
    void *temp_r4;

    temp_r0 = this->m_3c8 - 1;
    this->m_3c8 = temp_r0;
    if (temp_r0 < 0) {
        change_state(1);
    }
    if ((get_floor() == 2) && (objInBand((GameObj *)this, (f32)lbl_805DF0F8) != 0)) {
        temp_r4 = this->bodies;
        if (*(s32 *)((s8 *)temp_r4 + 0x18) & 0x02000000) {
            *(s32 *)((s8 *)temp_r4 + 0x18) &= ~0x02000000;
        }
        if (sub_80308AA8() != 0) {
            spawn_effect(0x3A80A);
        } else {
            spawn_effect(0x3A80B);
        }
    }
    if (*(s32 *)((s8 *)this->bodies + 0x18) & 0x02000000) {
        register_attack_hits();
    }
}
void TBoss7Crawfish::change_state(s32 state) {
    Craw_80308F8C *o = (Craw_80308F8C *)this;
    s32 i;
    o->state = state;
    o->fA4[6] |= 0x02000000;
    switch (o->state) {
    case 0:
        o->f3C8 = o->f3A0[6] - 10;
        break;
    case 1:
        break;
    case 2:
        ((TBoss7Crawfish *)o)->set_anim_timer(0);
        for (i = 0; i < 4; i++) {
            o->pairs[i].a = 0;
            o->pairs[i].b = 0;
        }
        o->f3A4 = 0;
        ((TBoss7Crawfish *)o)->free_child();
        o->f3CC = (s32)create_particle_emitter(o->f38, 0x20B);
        break;
    case 3:
        ((TBoss7Crawfish *)o)->set_anim_timer(4);
        break;
    case 4:
        ((TBoss7Crawfish *)o)->spawn_effect(0x3990E);
        ((TBoss7Crawfish *)o)->set_anim_timer(1);
        break;
    case 5:
        break;
    }
}

}
