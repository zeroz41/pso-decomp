#include "types.h"
#include "pso/ui/window/TWindowChoiceSetting_80249610.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"

extern "C" {

int TWindowMenuInfomation::is_selected() { return (this->m_70 >> 5) & 0x1; }
TWindowFukidasi *TWindowFukidasi::draw_resolved_window(const f32 *position, const f32 *size, s32 viewport) {
    TObject *root = get_viewport_window_root(viewport);
    return find_overlapping_balloon(position, size, (TWindowFukidasi *)root->m_down);
}
}

void resolve_chat_balloon_overlaps(void) {
    s32 i;
    TWindowFukidasi *p;
    TWindowFukidasi *q;
    for (i = 0; i < 6; i++) {
        p = (TWindowFukidasi *)get_viewport_window_root(i)->m_down;
        if (p != NULL) {
            while (p != NULL) {
                p->hide();
                p = static_cast<TWindowFukidasi *>(p->m_next);
            }
        }
    }
    for (i = 0; i < 6; i++) {
        p = (TWindowFukidasi *)get_viewport_window_root(i)->m_down;
        if (p != NULL) {
            while (p->m_next != NULL) {
                q = p->find_balloon_overlap_for(static_cast<TWindowFukidasi *>(p->m_next));
                while (q != NULL) {
                    if (p->get_visible_flag() != 0) {
                        TWindowFukidasi__sub_80249788(q);
                    } else if (q->get_visible_flag() != 0) {
                        TWindowFukidasi__sub_80249788(p);
                    } else if (p->m_58 > q->m_58) {
                        TWindowFukidasi__sub_80249788(p);
                    } else {
                        TWindowFukidasi__sub_80249788(q);
                    }
                    q = p->find_balloon_overlap_for(static_cast<TWindowFukidasi *>(q->m_next));
                }
                p = static_cast<TWindowFukidasi *>(p->m_next);
            }
        }
    }
}

void TWindowFukidasi__sub_80249788(void* p) { *(u32*)((char*)p + 0x2c) |= 0x400; }
void TWindowFukidasi::hide() { *(u32*)((char*)this + 0x2c) &= 0xfffffbff; }
