#include "types.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct V2_8026CBB8 { f32 x, y; };

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

extern const f32 lbl_805DD2CC;
s32 is_split_screen(void);
extern V2_8026CBB8 window_layout_position_table[];
extern V2_8026CBB8 lbl_80477890[];
extern unsigned char window_layout_rect_table[];
V2_8026CBB8 *get_window_layout_position(s32 idx);
s32 TWindowCtrlMain__sub_8024CE58(void);
extern f32 window_depth_order_cursor;
extern const f32 lbl_805DD2C8;
void*TWindowOptionCtrl::get_option_entry(int a0) {  return (char*)window_layout_rect_table + a0 * 8; }
V2_8026CBB8 *get_window_layout_position(s32 idx) {
    if (is_split_screen() != 0) {
        return (TCameraCtrl::get_camera_id() == 2) ? &lbl_80477890[idx] : &window_layout_position_table[idx];
    }
    return (V2_8026CBB8 *)((char *)window_layout_rect_table + idx * 8);
}
void TWindowBase::sub_8026CC28() {
    Node_8026CC28 *n;
    f32 lim;
    f32 t;
    if (TWindowCtrlMain__sub_8024CE58() != 0) {
        this->get_scale();
        window_depth_order_cursor -= lbl_805DD2C8;
        lim = ((Win_8026CC28 *)this)->f54;
        for (n = ((Win_8026CC28 *)this)->f10->f14; n != NULL; n = n->fC) {
            t = n->f54;
            if (lim > t) {
                n->f54 = t - lbl_805DD2C8;
            }
        }
    }
}

void TWindowBase::resort_window_order() {
    Node_8026CCA4 *n;
    Grp_8026CCA4 *g;
    Node_8026CCA4 *last;
    f32 scale;

    ((Node_8026CCA4 *)this)->f54 = lbl_805DD2CC;
    if (TWindowCtrlMain__sub_8024CE58() != 0 && ((Node_8026CCA4 *)this)->prev != ((Node_8026CCA4 *)this)) {
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
    window_depth_order_cursor += lbl_805DD2C8;
    for (n = g->head; n != NULL; n = n->next) {
        last = n;
        if (!(scale < ((TWindowBase *)n)->get_scale())) {
            break;
        }
        n->f54 += lbl_805DD2C8;
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
        ((Node_8026CCA4 *)this)->f54 += lbl_805DD2C8;
    }
    }
}

}
