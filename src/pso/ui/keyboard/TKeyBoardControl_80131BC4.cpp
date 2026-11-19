#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowMakeTeam.h"

extern "C" {

s32 export_keyboard_text(s32, s32);
s32 mem_alloc();

char *TKeyBoardControl::realloc_buffer() {
    s32 out;

    m_base->measure_text_overflow();
    out = mem_alloc();
    export_keyboard_text((s32)m_base, out);
    return (char *)out;
}

int TKeyBoardControl::is_active() { return m_base->is_active(); }
int TKeyBoardControl::is_key_active() { return m_base->is_key_active(); }

}
