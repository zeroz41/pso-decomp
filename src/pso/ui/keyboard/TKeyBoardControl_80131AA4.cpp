#include "types.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubComCard.h"

void TKeyBoardControl::set_position(void *arg1) {
    *(f32 *)((u8 *)m_base + 0x30) = (f32) (*(f32 *)((s8 *)arg1 + 0) - 4.0f);
    *(f32 *)((u8 *)m_base + 0x34) = (f32) (*(f32 *)((s8 *)arg1 + 4) - 1e+01f);
    *(s32 *)((u8 *)m_base + 0x50) = 3;
}

void TKeyBoardControl::set_soft_position(u8 *arg1) {
    *(f32 *)((s8 *)m_soft + 0x30) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)m_soft + 0x34) = (f32) *(f32 *)((s8 *)arg1 + 4);
    m_soft->save_position();
}
void TKeyBoardControl::set_hard_position(u8 *arg1) {
    *(f32 *)((s8 *)m_hard + 0x30) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)m_hard + 0x34) = (f32) *(f32 *)((s8 *)arg1 + 4);
    m_hard->save_position();
}

extern "C" {

s32 save_position__11TWindowBaseFv(void *, int, int, f32);

void TKeyBoardControl::set_sub_position(u8 *arg1) {
    f32 temp_f1;
    u8 *temp_r4;
    u8 *temp_r5;

    temp_r5 = (unsigned char *)m_base;
    *(f32 *)((s8 *)temp_r5 + 0x30) = (f32) (*(f32 *)((s8 *)arg1 + 0) - 4.0f);
    temp_f1 = *(f32 *)((s8 *)arg1 + 4);
    temp_r4 = (unsigned char *)m_base;
    *(f32 *)((s8 *)temp_r4 + 0x34) = (f32) (temp_f1 - 1e+01f);
    save_position__11TWindowBaseFv((void *)m_base, (int)temp_r4, (int)temp_r5, (f32)temp_f1);
}

void TKeyBoardControl::set_text(char *s) { m_base->set_text(s); }

}
