#include "pso/system/memory.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/network/TLobby.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

void TKeyBoardControl::hide() {
    u16 cur_flags;

    cur_flags = flags;
    if (!(cur_flags & 4)) {
        flags = cur_flags | 4;
        if (m_hard != NULL) {
            m_hard->set_flag60_bit200();
        }
        if (m_soft != NULL) {
            m_soft->request_close();
        }
    }
}

void TKeyBoardControl::show() {
    u16 cur_flags;

    cur_flags = flags;
    if (cur_flags & 4) {
        flags = cur_flags & 0xFFFFFFFB;
        if (m_hard != NULL) {
            m_hard->clear_flag60_bit200();
        }
        if (!(flags & 1) && (m_soft != NULL)) {
            m_soft->request_show();
        }
    }
}

void TKeyBoardControl::set_flag62_bit2() {
    m_base->set_flag62_bit2();
}

void TKeyBoardControl::set_depth(f32 depth) {
    m_base->set_depth(depth);
}

void TKeyBoardControl::set_position(void *pos) {
    const NJS_POINT2 *point = (const NJS_POINT2 *)pos;

    m_base->target_position[0] = point->x - 4.0f;
    m_base->target_position[1] = point->y - 10.0f;
    m_base->tween_ticks = 3;
}

void TKeyBoardControl::set_soft_position(u8 *pos) {
    const NJS_POINT2 *point = (const NJS_POINT2 *)pos;

    m_soft->target_position[0] = point->x;
    m_soft->target_position[1] = point->y;
    m_soft->save_position();
}

void TKeyBoardControl::set_hard_position(u8 *pos) {
    const NJS_POINT2 *point = (const NJS_POINT2 *)pos;

    m_hard->target_position[0] = point->x;
    m_hard->target_position[1] = point->y;
    m_hard->save_position();
}

void TKeyBoardControl::set_sub_position(u8 *pos) {
    const NJS_POINT2 *point = (const NJS_POINT2 *)pos;

    m_base->target_position[0] = point->x - 4.0f;
    m_base->target_position[1] = point->y - 10.0f;
    m_base->save_position();
}

void TKeyBoardControl::set_text(char *s) {
    m_base->set_text(s);
}

char *TKeyBoardControl::realloc_buffer() {
    char *out;

    out = (char *)mem_alloc(m_base->measure_text_overflow());
    m_base->export_text(out);
    return out;
}

int TKeyBoardControl::is_cancelled() { return m_base->is_cancelled(); }
int TKeyBoardControl::is_confirmed() { return m_base->is_confirmed(); }
