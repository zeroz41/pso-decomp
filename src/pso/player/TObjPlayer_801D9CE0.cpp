#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void TObjPlayer__sub_801D9E2C(void *, s16);
void TObjPlayer__sub_801D2CC4(void *, f32);
s32 TObjPlayer__sub_801D9E08(void *);
void TObjPlayer__sub_801D9E10(void *p, s16 v);
}

void PlayerTechniqueState::reset_all_tech_slots() {
    s32 i = 0;
    do {
        TObjPlayer__sub_801D9E2C(this, i);
        i++;
    } while (i < 0x13);
}
void PlayerTechniqueState::reset_tech_state() {
    s32 n;
    u8 v;
    s32 i;
    n = TObjPlayer__sub_801D9E08(this);
    v = TObjPlayer::get_item_count_max();
    for (i = 0; i < n; i++) {
        levels[i] = v;
        caps[i] = v;
    }
    set_level(0xFF);
    set_tech_override(0);
    set_technique_id(0);
    set_tech_level(0);
    TObjPlayer__sub_801D9E10(this, 0);
    set_technique_state(0);
    TObjPlayer__sub_801D2CC4(this, 0.0f);
    set_field18(0.0f);
    set_field_1c(1.5f);
    reset_all_tech_slots();
    reset_slots();
    pad_a = 0;
    pad_3 = 0;
    pad_2 = 0;
}
