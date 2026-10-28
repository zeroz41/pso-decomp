#include "types.h"
#include "pso/misc/TOKurage.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
struct Stack_8016D8F8 {
    s32 sp8;
    u8 pad_C[0x4];
    s32 sp10;
};

extern "C" {
s32 approach_angle_limited(int, int, int);
extern const f32 lbl_805DB7A0;
extern const f32 lbl_805DB7A4;
void TOKurage::sub_8016D8F8() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_8016D8F8, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8016D8F8, sp10) == 0x8) ? 1 : -1];
    Stack_8016D8F8 stack;
    ((TObjPlayer *)(&stack.sp8))->copy_xyz((u8 *)&this->rotation_x);
    *(s32 *)&this->rotation_x = (s32) (lbl_805DB7A0 * (*(f32 *)((s8 *)arg0 + 0x40) - *(f32 *)&this->m_4c));
    this->rotation_z = (s32) (lbl_805DB7A4 * (*(f32 *)((s8 *)arg0 + 0x38) - *(f32 *)&this->m_44));
    *(s32 *)&this->rotation_x = approach_angle_limited(stack.sp8, (int) (*(s32 *)&this->rotation_x), 0x40);
    this->rotation_z = approach_angle_limited(stack.sp10, this->rotation_z, 0x40);
}

}
