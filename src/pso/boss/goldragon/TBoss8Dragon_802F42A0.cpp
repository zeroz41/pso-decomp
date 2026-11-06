#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"

extern "C" {

s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 push_matrix();
s32 draw__10TObjMotionFv(void *, int);

extern u8 *TBoss8Dragon__data_805D6988;

void TBoss8Dragon::draw() {
    s32 temp_r31;
    u8 *temp_r4;

    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->m_60);
    rotate_matrix_x(0, this->m_5c);
    rotate_matrix_z(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x64)));
    scale_current_matrix((void *) (((u8 *)this) + 0x68));
    temp_r31 = this->m_34;
    temp_r4 = (unsigned char *) (*(void **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C));
    this->m_34 = (s32) *(s32 *)((s8 *)temp_r4 + 0x28);
    draw__10TObjMotionFv(this, (int)temp_r4);
    this->m_34 = temp_r31;
    pop_matrix();
}

}
