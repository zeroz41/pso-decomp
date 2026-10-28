#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneRe2Flower.h"

extern "C" {
extern const f32 lbl_805D9FF8;
s32 get_flag_11__16TObjEneRe2FlowerFv();
int TBoss8Dragon__sub_800BB7D4(void*, void*);

void TObjEneRe2Flower::begin_state_242() { if (*(int*)((char*)this + 0x3d4) == 0) { TBoss8Dragon__sub_800BB7D4(this, (void*)242); *(int*)((char*)this + 0x3d4) = 20; } }

s32 TObjEneRe2Flower::check_hit_flag() {
    if (*(s32 *)((s8 *)this + 0x3C4) & 2) {
        transition_enemy_state(7);
        return 1;
    }
    return 0;
}

void TObjEneRe2Flower::clear_child_flags() {
    void *temp_r3;
    void *temp_r3_2;

    if (get_flag_11__16TObjEneRe2FlowerFv() != 0) {
        temp_r3 = this->bodies;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
        return;
    }
    temp_r3_2 = this->bodies;
    *(s32 *)((s8 *)temp_r3_2 + 0x44) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0x44) & 0xFFFFFFFE);
}

void TObjEneRe2Flower::set_child_flags() {
    void *temp_r3;
    void *temp_r3_2;

    if (get_flag_11__16TObjEneRe2FlowerFv() != 0) {
        temp_r3 = this->bodies;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
        return;
    }
    temp_r3_2 = this->bodies;
    *(s32 *)((s8 *)temp_r3_2 + 0x44) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0x44) | 1);
}

void TObjEneRe2Flower::vfunc_88() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)this->bodies + 0x30) = (f32) (this->m_300 - *(f32 *)((s8 *)arg0 + 0x3C));
    ((TObjEneDD *)arg0)->set_part_local_pos((u8 *)&this->_pad3F8, 0);
}

void TObjEneRe2Flower::sub_800C3DC4() {
    VecCopy((Vec *)&this->m_2fc, (const Vec *)&this->position);
    this->m_300 = (f32) (this->m_300 + lbl_805D9FF8);
    VecCopy(&this->center, (const Vec *)&this->m_2fc);
}

}
