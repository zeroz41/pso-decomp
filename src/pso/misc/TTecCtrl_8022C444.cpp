#include "types.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/TTecCtrl.h"
#include "pso/misc/TechniqueBoost.h"

struct Slot_8022C5CC { s16 id; u16 flags; f32 amount; };

struct RecoveredGlobal_8022C680_lbl_80515FBC {
    s32 value;
    u8 remaining[0xBC];
};

extern RecoveredGlobal_8022C680_lbl_80515FBC lbl_80515FBC;
f32 calc_technique_boost(s32, u16);
extern "C" {
f32 get_battle_value__10TObjPlayerFlil(void *, s32, s16);
void *get_player_by_client_id(s32 i);
extern const f32 lbl_805DC7D8;
s32 calc_technique_parameters();

void TUnk_804CC148::vfunc_6(void *) {  }
void TUnk_804CC148::vfunc_8(void *) {  }
void TUnk_804CC148::vfunc_9() {  }

extern f32 lbl_805DC7D0;
extern f32 lbl_805DC7D4;

s32 TTecCtrl::classify_distance_band(s32 arg0, s32 arg1, s32 arg2) {
    f32 temp_f1;

    calc_technique_parameters();
    if ((arg1 == 0) || (arg1 == 1)) {
        return 0;
    }
    temp_f1 = ((f32 (*)(s32, s32))calc_technique_boost)(arg0, arg2);
    if (temp_f1 < lbl_805DC7D0) {
        return 1;
    }
    if (temp_f1 < lbl_805DC7D4) {
        return 2;
    }
    return 3;
}

u32 get_technique_caster_flags(s32 technique, u16 actor) {
    u32 flags;
    void *player;
    s32 i;

    flags = 0;
    if (actor >= 4) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        player = get_player_by_client_id(actor);
        if (player != NULL) {
            flags += ((f32 (*)(void *, u16, s16))get_battle_value__10TObjPlayerFlil)(player, actor, technique);
            switch (technique) {
            case 18:
                if (((f32 (*)(void *, u16, s16))get_battle_value__10TObjPlayerFlil)(player, actor, technique) == lbl_805DC7D0) {
                    flags |= 1;
                }
                break;
            }
        }
        if (technique == ((struct Slot_8022C5CC (*)[6])&lbl_80515FBC)[actor][i].id) {
            flags |= ((struct Slot_8022C5CC (*)[6])&lbl_80515FBC)[actor][i].flags;
        }
    }
    return flags;
}
}
f32 calc_technique_boost(s32 technique, u16 actor) {
    f32 sum;
    void *player;
    s32 i;

    sum = lbl_805DC7D8;
    if (actor >= 4) {
        return sum;
    }
    for (i = 0; i < 6; i++) {
        if (technique == ((struct Slot_8022C5CC (*)[6])&lbl_80515FBC)[actor][i].id) {
            sum += ((struct Slot_8022C5CC (*)[6])&lbl_80515FBC)[actor][i].amount;
        }
    }
    player = get_player_by_client_id(actor);
    if (player != NULL) {
        sum += ((f32 (*)(void *, u16, s16))get_battle_value__10TObjPlayerFlil)(player, actor, technique);
    }
    return sum;
}
typedef char RecoveredGlobal_8022C680_lbl_80515FBC_size[sizeof(RecoveredGlobal_8022C680_lbl_80515FBC) == 0xC0 ? 1 : -1];

void set_technique_boost(TechniqueBoost *boost, u16 client, s32 index) {
    if (client < 4U) {
        ((TechniqueBoostTable *)&lbl_80515FBC)[client].set(index, boost);
    }
}
