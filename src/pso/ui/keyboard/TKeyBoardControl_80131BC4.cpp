#include "pso/system/memory.h"
#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"


char *TKeyBoardControl::realloc_buffer() {
    char *out;

    out = (char *)mem_alloc(m_base->measure_text_overflow());
    m_base->export_text(out);
    return out;
}

int TKeyBoardControl::is_cancelled() { return m_base->is_cancelled(); }
int TKeyBoardControl::is_confirmed() { return m_base->is_confirmed(); }
