#include "types.h"
#include "pso/ui/window/TWindowChoiceSetting_80249610.h"
#include "pso/ui/window/TUnk_804D0658.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowSubComCard.h"

typedef struct Balloon_8024966C {
    u8 pad0[0xC];
    struct Balloon_8024966C *next;
    u8 pad10[0x58 - 0x10];
    f32 rise;
} Balloon_8024966C;

typedef struct Ctrl_8024966C {
    u8 pad0[0x14];
    Balloon_8024966C *head;
} Ctrl_8024966C;

extern "C" {
Balloon_8024966C *find_balloon_overlap_for__15TWindowFukidasiFl(Balloon_8024966C *, Balloon_8024966C *);
s32 TWindowCtrlMain__sub_8024CDD0(s32 arg0);
s32 find_overlapping_balloon__15TWindowFukidasiFPvPvPvPv(s32, s32, s32, s32);

int TUnk_804D0658::is_selected() { return (this->m_70 >> 5) & 0x1; }
void TWindowFukidasi::draw_resolved_window(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    find_overlapping_balloon__15TWindowFukidasiFPvPvPvPv(arg0, arg1, arg2, *(s32 *)((s8 *)(TWindowCtrlMain__sub_8024CDD0(arg3)) + 0x14));
}
}

void resolve_chat_balloon_overlaps(void) {
    s32 i;
    Balloon_8024966C *p;
    Balloon_8024966C *q;
    for (i = 0; i < 6; i++) {
        p = ((Ctrl_8024966C *)TWindowCtrlMain__sub_8024CDD0(i))->head;
        if (p != NULL) {
            while (p != NULL) {
                ((TWindowFukidasi *)p)->hide();
                p = p->next;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        p = ((Ctrl_8024966C *)TWindowCtrlMain__sub_8024CDD0(i))->head;
        if (p != NULL) {
            while (p->next != NULL) {
                q = find_balloon_overlap_for__15TWindowFukidasiFl(p, p->next);
                while (q != NULL) {
                    if (((TWindowFukidasi *)p)->get_visible_flag() != 0) {
                        TWindowFukidasi__sub_80249788(q);
                    } else if (((TWindowFukidasi *)q)->get_visible_flag() != 0) {
                        TWindowFukidasi__sub_80249788(p);
                    } else if (p->rise > q->rise) {
                        TWindowFukidasi__sub_80249788(p);
                    } else {
                        TWindowFukidasi__sub_80249788(q);
                    }
                    q = find_balloon_overlap_for__15TWindowFukidasiFl(p, q->next);
                }
                p = p->next;
            }
        }
    }
}

void TWindowFukidasi__sub_80249788(void* p) { *(u32*)((char*)p + 0x2c) |= 0x400; }
void TWindowFukidasi::hide() { *(u32*)((char*)this + 0x2c) &= 0xfffffbff; }
