#include "types.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/unk/text_80131ADC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowSubComCard.h"

void TWindowSubShortMail::set_position(void *arg1) {
    *(f32 *)(this->m_20 + 0x30) = (f32) (*(f32 *)((s8 *)arg1 + 0) - 4.0f);
    *(f32 *)(this->m_20 + 0x34) = (f32) (*(f32 *)((s8 *)arg1 + 4) - 1e+01f);
    *(s32 *)(this->m_20 + 0x50) = 3;
}

void fn_80131ADC(u8 *arg0, u8 *arg1) {
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x28)) + 0x30) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x28)) + 0x34) = (f32) *(f32 *)((s8 *)arg1 + 4);
    ((TWindowBase *)(*(u8 **)((s8 *)arg0 + 0x28)))->save_position();
}
void fn_80131B18(u8 *arg0, u8 *arg1) {
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x24)) + 0x30) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x24)) + 0x34) = (f32) *(f32 *)((s8 *)arg1 + 4);
    ((TWindowBase *)(*(u8 **)((s8 *)arg0 + 0x24)))->save_position();
}

extern "C" {

s32 save_position__11TWindowBaseFv(void *, int, int, f32);

void TWindowMakeTeam::set_sub_position(u8 *arg1) {
    f32 temp_f1;
    u8 *temp_r4;
    u8 *temp_r5;

    temp_r5 = (unsigned char *) (this->m_20);
    *(f32 *)((s8 *)temp_r5 + 0x30) = (f32) (*(f32 *)((s8 *)arg1 + 0) - 4.0f);
    temp_f1 = *(f32 *)((s8 *)arg1 + 4);
    temp_r4 = (unsigned char *) (this->m_20);
    *(f32 *)((s8 *)temp_r4 + 0x34) = (f32) (temp_f1 - 1e+01f);
    save_position__11TWindowBaseFv((void *)this->m_20, (int)temp_r4, (int)temp_r5, (f32)temp_f1);
}

int TWindowMakeTeam::get_keyboard_field_6c() { return ((TWindowKeyBoardSoft *)(this->m_20))->get_field_6c(); }

}
