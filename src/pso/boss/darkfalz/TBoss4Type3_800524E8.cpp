#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/volopt/TBoss3Volopt.h"

struct Player_8005254C { u8 pad[0x30]; u32 flags; };

extern "C" {
extern const f32 lbl_805D8AE0;
void *get_player_by_client_id(s32 i);
f32 cos_table_lookup(s32);

extern const f32 lbl_805D8AE4;
extern const f32 lbl_805D8AF0;

#pragma push
#pragma fp_contract on
f32 TBoss4Type3__sub_800524E8(f32 farg0) {
    f32 temp_f1;
    temp_f1 = lbl_805D8AE0 - farg0;
    return -((temp_f1 * (temp_f1 * (temp_f1 * (temp_f1 * (temp_f1 * temp_f1))))) - lbl_805D8AE0);
}
#pragma pop

f32 TBoss4Type3::compute_wave_offset(f32 farg0) {
    return lbl_805D8AE4 * (lbl_805D8AE0 - cos_table_lookup((s32) (lbl_805D8AF0 * farg0)));
}
s32 TBoss4Type3__sub_8005254C(u16 id) {
    Player_8005254C *p;
    if (id != 0xFFFF) {
        p = (Player_8005254C *)get_player_by_client_id(id);
        if (p != 0 && !(p->flags & 0x2000800) && ((TBoss3Volopt *)p)->get_field_3e0() == 0xE) {
            return 1;
        }
    }
    return 0;
}

}
