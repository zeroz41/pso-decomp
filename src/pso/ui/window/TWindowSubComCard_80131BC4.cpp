#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowMakeTeam.h"

extern "C" {

s32 export_keyboard_text(s32, s32);
s32 mem_alloc();

s32 TWindowSubComCard::realloc_buffer() {
    s32 out;

    ((TWindowKeyBoardSoft *)(this->m_20))->measure_text_overflow();
    out = mem_alloc();
    export_keyboard_text(this->m_20, out);
    return out;
}

int TWindowSubComCard::is_keyboard_active() { return ((TKeyBoardControl *)(this->m_20))->is_active(); }
int TWindowSubComCard::update_keyboard() { return ((TKeyBoardControl *)(this->m_20))->is_key_active(); }

}
