#include "types.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"

extern "C" {

s32 TObjFish__sub_8001EDB0(s32, s32);
void *get_bml_model(s32, s32);

extern s32 falz_zako_texture_list;
extern u32 falz_zako_chunk_model;
extern s32 TBoss4ZakoDraw__rotation_phase;

void TBoss4DarkFalz::init_uro_link() {
    u32 temp_r3_2;
    void *temp_r3;

    falz_zako_texture_list = TObjFish__sub_8001EDB0(TBoss4Uro::get_instance_count(), 8);
    temp_r3 = *(void **)((s8 *)(get_bml_model(TBoss4Uro::get_instance_count(), 8)) + 0x2C);
    *(s32 *)((s8 *)temp_r3 + 0) = (s32) (*(s32 *)((s8 *)temp_r3 + 0) & 0xFFFFFFFD);
    temp_r3_2 = *(u32 *)((s8 *)temp_r3 + 4);
    if (temp_r3_2 != 0U) {
        falz_zako_chunk_model = temp_r3_2;
        TBoss4ZakoDraw__rotation_phase = 0;
        TBoss4DarkFalz::clear_uro_link_state();
    }
}

}
