#include "types.h"
#include "pso/player/TObjPlayer.h"

typedef struct Techs_801D9D24 {
    u8 pad0[2];
    u8 f2;
    u8 f3;
    u8 pad4[0xA - 0x4];
    s16 fa;
    u8 padc[0x5C - 0xC];
    u8 levels[0x14];
    u8 caps[0x14];
} Techs_801D9D24;

extern "C" {
void TObjPlayer__sub_801D9E2C(void *, s16);
void set_technique_id__10TObjPlayerFs(void *, s16);
u8 get_item_count_max__10TObjPlayerFv(void);
void set_technique_id__10TObjPlayerFUc(void *, u8);
void TObjPlayer__sub_801D2CC4(void *, f32);
s32 TObjPlayer__sub_801D9E08(void *);
void TObjPlayer__sub_801D9E10(void *p, s16 v);
void TObjPlayer::reset_all_tech_slots() {
    s32 i = 0;
    do {
        TObjPlayer__sub_801D9E2C(this, i);
        i++;
    } while (i < 0x13);
}
void TObjPlayer::reset_tech_state() {
    Techs_801D9D24 *self = (Techs_801D9D24 *)this;
    s32 n;
    u8 v;
    s32 i;
    n = TObjPlayer__sub_801D9E08(self);
    v = get_item_count_max__10TObjPlayerFv();
    for (i = 0; i < n; i++) {
        self->levels[i] = v;
        self->caps[i] = v;
    }
    set_technique_id__10TObjPlayerFUc(self, 0xFF);
    ((TObjPlayer *)self)->set_tech_override(0);
    set_technique_id__10TObjPlayerFs(self, 0);
    ((TObjPlayer *)self)->set_tech_level(0);
    TObjPlayer__sub_801D9E10(self, 0);
    ((TObjPlayer *)self)->set_technique_state(0);
    TObjPlayer__sub_801D2CC4(self, 0.0f);
    ((TObjPlayer *)self)->set_field18(0.0f);
    ((TObjPlayer *)self)->set_field_1c(1.5f);
    reset_all_tech_slots();
    ((TObjPlayer *)self)->reset_slots();
    self->fa = 0;
    self->f3 = 0;
    self->f2 = 0;
}

}
