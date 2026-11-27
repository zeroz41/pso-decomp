#include "types.h"
#include "pso/ui/window/ChatBalloonOverlap.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowCtrlMain.h"


TWindowFukidasi *TWindowFukidasi::draw_resolved_window(const f32 *position, const f32 *size, s32 viewport) {
    TObject *root = get_viewport_window_root(viewport);
    return find_overlapping_balloon(position, size, (TWindowFukidasi *)root->m_down);
}

void resolve_chat_balloon_overlaps(void) {
    s32 i;
    TWindowFukidasi *p;
    TWindowFukidasi *q;
    for (i = 0; i < 6; i++) {
        p = (TWindowFukidasi *)get_viewport_window_root(i)->m_down;
        if (p != NULL) {
            while (p != NULL) {
                p->clear_overlapped();
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
                        q->mark_overlapped();
                    } else if (q->get_visible_flag() != 0) {
                        p->mark_overlapped();
                    } else if (p->display_age > q->display_age) {
                        p->mark_overlapped();
                    } else {
                        q->mark_overlapped();
                    }
                    q = p->find_balloon_overlap_for(static_cast<TWindowFukidasi *>(q->m_next));
                }
                p = static_cast<TWindowFukidasi *>(p->m_next);
            }
        }
    }
}

void TWindowFukidasi::mark_overlapped() { window_flags |= 0x400; }
void TWindowFukidasi::clear_overlapped() { window_flags &= ~0x400; }
