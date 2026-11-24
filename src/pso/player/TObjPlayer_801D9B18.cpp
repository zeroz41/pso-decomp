// ---- pso/player/TObjPlayer_801D9B18
#include "types.h"
#include "pso/player/TObjPlayer_801D9B18.h"
#include "pso/player/TObjPlayer.h"


void PlayerTechniqueState::set_tech_level(s16 lim) {
    s16 var_r4;

    var_r4 = lim;
    if ((var_r4 < 0) || (var_r4 > 0xA)) {
        var_r4 = 0;
    }
    target_count = var_r4;
}

// ---- pso/unk/text_801D9B38

#include "pso/player/TObjPlayer_801D9E08.h"
#include "pso/unk/text_801D9B38.h"


extern "C" {
u8 TObjPlayer__sub_801C010C(void *self, s16 i);
u8 clamp_to_max__10TObjPlayerFlUcUc(s32 arg0, u8 arg1, u8 arg2);
void set_technique_level_entry(void *, s16, void *);

void TObjPlayer::set_all_technique_levels(void *level) {
    s32 i;
    s32 n = TObjPlayer__sub_801D9E08();
    for (i = 0; i < n; i++) {
        set_technique_level_entry(this, i, level);
    }
}

void TObjPlayer::copy_all_technique_entries(void *arg1) {
    s32 i;
    s32 n = TObjPlayer__sub_801D9E08();
    for (i = 0; i < n; i++) {
        TObjPlayer__sub_801D9C34((u8 *)this, (s16)i, (void *)arg1);
    }
}

void get_effective_technique_level__10TObjPlayerFPvs(u8 *self, s16 idx) {
    u8 v = *(self + idx + 0x70);
    u8 c = TObjPlayer__sub_801C010C(self, idx);
    TObjPlayer::clamp_to_max((saddr)self, v, c);
}
void TObjPlayer__sub_801D9C34(u8 *self, s16 idx, void *arg2) {
    u8 c = TObjPlayer__sub_801C010C(self, idx);
    *(self + idx + 0x70) = ((u8 (*)(s32, void *, u8))clamp_to_max__10TObjPlayerFlUcUc)((saddr)self, arg2, c);
}

// ---- pso/player/TObjPlayer_801D9C88
int set_slot_type_state__10TObjPlayerFllls(void*, s32, void*, void*);

void PlayerTechniqueState::reset_slots() { target_count = 0; { int i; for (i = 0; i < 10; i++) { set_slot_type_state__10TObjPlayerFllls(this, i, (void*)65535, (void*)0); } } }

}
