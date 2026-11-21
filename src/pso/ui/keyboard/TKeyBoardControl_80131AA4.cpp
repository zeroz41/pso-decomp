#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

void TKeyBoardControl::set_position(void *arg1) {
    m_base->target_position[0] = (f32) (((f32 *)arg1)[0] - 4.0f);
    m_base->target_position[1] = (f32) (((f32 *)arg1)[1] - 10.0f);
    m_base->tween_ticks = 3;
}

void TKeyBoardControl::set_soft_position(u8 *pos) {
    m_soft->target_position[0] = (f32) ((f32 *)pos)[0];
    m_soft->target_position[1] = (f32) ((f32 *)pos)[1];
    m_soft->save_position();
}
void TKeyBoardControl::set_hard_position(u8 *arg1) {
    m_hard->target_position[0] = (f32) ((f32 *)arg1)[0];
    m_hard->target_position[1] = (f32) ((f32 *)arg1)[1];
    m_hard->save_position();
}

void TKeyBoardControl::set_sub_position(u8 *pos) {
    m_base->target_position[0] = (f32) (((f32 *)pos)[0] - 4.0f);
    m_base->target_position[1] = (f32) (((f32 *)pos)[1] - 10.0f);
    m_base->save_position();
}

void TKeyBoardControl::set_text(char *s) { m_base->set_text(s); }
