#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowMainMenu1P.h"
#include "pso/ui/window/WindowLayoutCamera2Data.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"

struct Node_8026CC28 { u8 p0[0xC]; Node_8026CC28 *fC; u8 p10[0x44]; f32 f54; };

struct Grp_8026CC28 { u8 p0[0x14]; Node_8026CC28 *f14; };

struct Win_8026CC28 { u8 p0[0x10]; Grp_8026CC28 *f10; u8 p14[0x40]; f32 f54; };

extern "C" {
struct Grp_8026CCA4;
struct Node_8026CCA4 {
    u8 p0[0x8];
    Node_8026CCA4 *prev;
    Node_8026CCA4 *next;
    Grp_8026CCA4 *grp;
    u8 p14[0x40];
    f32 f54;
};
struct Grp_8026CCA4 { u8 p0[0x14]; Node_8026CCA4 *head; };

const NJS_POINT2 *get_window_layout_position(s32 idx);
extern f32 window_depth_order_cursor;
const NJS_POINT2 *TWindowOptionCtrl::get_option_entry(int a0) { return &window_layout_rect_table[a0]; }
const NJS_POINT2 *get_window_layout_position(s32 idx) {
    if (is_split_screen() != 0) {
        return (TCameraCtrl::get_camera_id() == 2) ? &window_layout_position_table_camera2[idx] : &window_layout_position_table[idx];
    }
    return &window_layout_rect_table[idx];
}
void TWindowBase::sub_8026CC28() {
    Node_8026CC28 *n;
    f32 lim;
    f32 t;
    if (has_window_task_root() != 0) {
        this->get_scale();
        window_depth_order_cursor -= -0.3f;
        lim = ((Win_8026CC28 *)this)->f54;
        for (n = ((Win_8026CC28 *)this)->f10->f14; n != NULL; n = n->fC) {
            t = n->f54;
            if (lim > t) {
                n->f54 = t - (-0.3f);
            }
        }
    }
}

void TWindowBase::resort_window_order() {
    Node_8026CCA4 *n;
    Grp_8026CCA4 *g;
    Node_8026CCA4 *last;
    f32 scale;

    ((Node_8026CCA4 *)this)->f54 = -1.3f;
    if (has_window_task_root() != 0 && ((Node_8026CCA4 *)this)->prev != ((Node_8026CCA4 *)this)) {
    g = ((Node_8026CCA4 *)this)->grp;
    if (g->head == ((Node_8026CCA4 *)this)) {
        g->head = ((Node_8026CCA4 *)this)->next;
        ((Node_8026CCA4 *)this)->prev->next = NULL;
        if (((Node_8026CCA4 *)this)->next != NULL) {
            ((Node_8026CCA4 *)this)->next->prev = ((Node_8026CCA4 *)this)->prev;
        }
    } else {
        ((Node_8026CCA4 *)this)->prev->next = ((Node_8026CCA4 *)this)->next;
        if (((Node_8026CCA4 *)this)->next != NULL) {
            ((Node_8026CCA4 *)this)->next->prev = ((Node_8026CCA4 *)this)->prev;
        } else {
            g->head->prev = ((Node_8026CCA4 *)this)->prev;
        }
    }
    scale = ((TWindowBase *)((Node_8026CCA4 *)this))->get_scale();
    window_depth_order_cursor += -0.3f;
    for (n = g->head; n != NULL; n = n->next) {
        last = n;
        if (!(scale < ((TWindowBase *)n)->get_scale())) {
            break;
        }
        n->f54 += -0.3f;
    }
    if (n == NULL) {
        g->head->prev = ((Node_8026CCA4 *)this);
        last->next = ((Node_8026CCA4 *)this);
        ((Node_8026CCA4 *)this)->next = NULL;
        ((Node_8026CCA4 *)this)->prev = last;
        return;
    }
    if (n == g->head) {
        g->head = ((Node_8026CCA4 *)this);
    }
    ((Node_8026CCA4 *)this)->prev = n->prev;
    ((Node_8026CCA4 *)this)->next = n;
    if (n->prev->next != NULL) {
        n->prev->next = ((Node_8026CCA4 *)this);
    }
    n->prev = ((Node_8026CCA4 *)this);
    for (; n != NULL; n = n->next) {
        ((Node_8026CCA4 *)this)->f54 += -0.3f;
    }
    }
}

}
