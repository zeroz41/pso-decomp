#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowMainMenu1P.h"
#include "pso/ui/window/WindowLayoutCamera2Data.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/ui/window/TWindowQuantity.h"

extern "C" {
extern f32 window_depth_order_cursor;
const NJS_POINT2 *TWindowOptionCtrl::get_option_entry(int a0) { return &window_layout_rect_table[a0]; }
const NJS_POINT2 *get_window_layout_position(s32 idx) {
    if (is_split_screen() != 0) {
        return (TCameraCtrl::get_camera_id() == 2) ? &window_layout_position_table_camera2[idx] : &window_layout_position_table[idx];
    }
    return &window_layout_rect_table[idx];
}
}

void TWindowBase::bring_to_front() {
    TObject *n;
    f32 lim;
    f32 t;
    if (has_window_task_root() != 0) {
        this->get_scale();
        window_depth_order_cursor -= -0.3f;
        lim = this->draw_depth;
        for (n = m_up->m_down; n != NULL; n = n->m_next) {
            t = ((TWindowBase *)n)->draw_depth;
            if (lim > t) {
                ((TWindowBase *)n)->draw_depth = t - (-0.3f);
            }
        }
    }
}

void TWindowBase::resort_window_order() {
    TObject *n;
    TObject *g;
    TObject *last;
    f32 scale;

    this->draw_depth = -1.3f;
    if (has_window_task_root() != 0 && m_prev != this) {
    g = m_up;
    if (g->m_down == this) {
        g->m_down = m_next;
        m_prev->m_next = NULL;
        if (m_next != NULL) {
            m_next->m_prev = m_prev;
        }
    } else {
        m_prev->m_next = m_next;
        if (m_next != NULL) {
            m_next->m_prev = m_prev;
        } else {
            g->m_down->m_prev = m_prev;
        }
    }
    scale = this->get_scale();
    window_depth_order_cursor += -0.3f;
    for (n = g->m_down; n != NULL; n = n->m_next) {
        last = n;
        if (!(scale < ((TWindowBase *)n)->get_scale())) {
            break;
        }
        ((TWindowBase *)n)->draw_depth += -0.3f;
    }
    if (n == NULL) {
        g->m_down->m_prev = this;
        last->m_next = this;
        m_next = NULL;
        m_prev = last;
        return;
    }
    if (n == g->m_down) {
        g->m_down = this;
    }
    m_prev = n->m_prev;
    m_next = n;
    if (n->m_prev->m_next != NULL) {
        n->m_prev->m_next = this;
    }
    n->m_prev = this;
    for (; n != NULL; n = n->m_next) {
        this->draw_depth += -0.3f;
    }
    }
}

f32 TWindowBase::get_scale() { return sort_depth; }
void TWindowQuantity::set_quantity(s32 quantity) {
    *(s32 *)((s8 *)(get_array_entry(1)) + 0x20) = quantity;
}
