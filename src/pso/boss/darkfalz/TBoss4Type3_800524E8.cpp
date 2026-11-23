#include "pso/player/TObjPlayer.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"


extern const f32 lbl_805D8AE0;

extern const f32 lbl_805D8AE4;
extern const f32 lbl_805D8AF0;

#pragma push
#pragma fp_contract on
f32 ease_out_pow6(f32 t) {
    f32 rest;
    rest = lbl_805D8AE0 - t;
    return -((rest * (rest * (rest * (rest * (rest * rest))))) - lbl_805D8AE0);
}
#pragma pop

f32 TBoss4Type3::compute_wave_offset(f32 wave) {
    return lbl_805D8AE4 * (lbl_805D8AE0 - cos_table_lookup((s32) (lbl_805D8AF0 * wave)));
}
s32 is_player_in_boss_area(u16 id) {
    TObjPlayer *p;
    if (id != 0xFFFF) {
        p = get_player_by_client_id(id);
        if (p != 0 && !(p->actorFlags & 0x2000800) && p->get_area() == 0xE) {
            return 1;
        }
    }
    return 0;
}

