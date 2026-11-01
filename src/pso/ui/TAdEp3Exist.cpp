#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdEp3Exist.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/ui/TAdAgreementBaseGC.h"
#include "pso/ui/TAdScrollWinGC_80327504.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/unk/text_8036F764.h"

#include "pso/TLevelSelect.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdScrollWinGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Obj_8036F4DC { u8 pad0[8]; u8 cnt; u8 bits; };

struct Ep3_8036F354 {
    s32 x0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u32 win1C;
    u32 cur20;
    s32 x24;
    s32 x28;
    s32 x2C;
    s32 x30;
    s32 x34;
};

struct Base_8036F10C { u8 pad[0x18]; };

struct Ep3_8036F10C : Base_8036F10C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual u32 m4();
    u8 pad1C[0x20 - 0x1C];
    s32 sel;
    u32 win;
    s32 state;
    s32 prev;
    s32 next;
    s32 count;
};

struct Prs_8036F5B0 {
    u8 *f0;
    u8 *f4;
    u8 *fC_pad8;
    s32 fC;
    u8 *f10;
    s32 f14;
    u8 *f18;
    u32 f1C;
    s32 f20, f24;
    s32 f28;
    u32 f2C;
};

extern "C" {
void TAdEp3Exist__sub_8036F574(u8 *arg0);
u8 TAdEp3Exist__sub_8036F590(u8 *arg0);
s32 get_localized_text_entry(s32 arg0, s32 arg1);
u32 calc_text_width(char *s);
s32 render_status_line__15TAdSubPlyItemGCFi(int, int, f32, f32, f32);
extern const f32 lbl_805E0440;
extern const f32 lbl_805E0444;
extern const f32 lbl_805E0448;
void queue_destruction__7TObjectFv(void *);
s32 load_and_verify_character_save__23TAdSinglePlyChrSelectGCFPc(void *, void *);
u8 *get_instance__23TAdSinglePlyChrSelectGCFv(void);
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void);
int reset_and_set_mode__21TAdMultiChgGameModeGCFv(void*);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
u32 __ct__14TAdSelectCurGCFv(void *, TObject *, void *, void *);
extern u8 lbl_8047B8A8[];
extern u8 lbl_8047B8B0[];
extern s32 __vt__11TAdEp3Exist[];
extern s32 lbl_805D4500;
void *TAdEp3Exist__ct(Ep3_8036F354 *o);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
int TAdEp3Exist__sub_8036F0AC(void* p);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
extern const f32 lbl_805E044C;
int prs_read_control_bit(Obj_8036F4DC *arg0);
void TAdEp3Exist__sub_8036F5A4(void* p);
void *memmove(void *, const void *, u32);
s32 prs_decompress(Prs_8036F5B0 *c, u8 *src, s32 arg2, s32 arg3);
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);
int request_transition__21TAdMultiChgGameModeGCFv(void*);

void TAdEp3Exist::draw_message_window(s32 arg1) {
    s32 arg0 = (s32)this;
    ((TWindowBase *)arg0)->draw_window_frame((void *) (arg1));
    render_status_line__15TAdSubPlyItemGCFi((int) (get_localized_text_entry(0x2C, 0xA)), -1, (f32) (lbl_805E0440 - (f32) (calc_text_width((char *)(get_localized_text_entry(0x2C, 0xA))) >> 1U)), (f32) (lbl_805E0444), (f32) (lbl_805E0448));
}

void TAdEp3Exist::render() {
    if (TMainTask::get_render_pass() == 1) {
        return;
    }
}

int TAdEp3Exist::request_game_mode_transition() { return request_transition__21TAdMultiChgGameModeGCFv(this); }
int TAdEp3Exist::request_scene_change() { return request_scene_change__21TAdMultiChgGameModeGCFv(this); }
int TAdEp3Exist__sub_8036F0AC(void* p) { return reset_and_set_mode__21TAdMultiChgGameModeGCFv(p); }
void TAdEp3Exist::close_window() { if (this->m_1c != 0) { ((TAdScrollWinGC *)(this->m_1c))->close_window(); this->m_1c = 0; } }

void TAdEp3Exist::run_task() {
    Ep3_8036F10C *o = (Ep3_8036F10C *)this;
    o->prev = o->state;
    switch (o->state) {
    case 0:
        o->win = o->m4();
        o->state = 1;
        break;
    case 1:
        if (((TAdSinglePlyChrSelectGC *)(o->sel))->get_selected_slot() == 1) {
            switch (TAdSinglePlyChrSelectGC__sub_801334DC((void *)o->sel)) {
            case 0:
                o->state = 2;
                o->next = 3;
                break;
            case 1:
                o->state = 2;
                o->next = 4;
                break;
            }
        } else if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0 ||
                   test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0) {
            o->state = 2;
            o->next = 5;
        }
        break;
    case 2:
        if (o->win != 0) {
            ((TWindowBase *)o->win)->close();
            o->win = 0;
        }
        close_window();
        if ((f32)++o->count > lbl_805E044C) {
            o->state = o->next;
        }
        break;
    case 3:
        TAdEp3Exist__sub_8036F0AC((void*)(o));
        break;
    case 4:
        request_scene_change();
        break;
    case 5:
        request_game_mode_transition();
        break;
    }
    if (o->prev != o->state) {
        o->count = 0;
    }
}

}
TAdEp3Exist::~TAdEp3Exist() {
    if (*(void **)((s8 *)this + 0x24) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x24)); this->m_24 = 0; }
    if (*(void **)((s8 *)this + 0x20) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x20)); this->m_20 = 0; }
}


void *TAdEp3Exist__ct(Ep3_8036F354 *o) {
    s8 flag[16];
    u8 save[16];
    s32 res;
    void *p;
    u32 r;
    bool ok;
    bool go;
    __ct__7TObjectFP7TObject();
    o->vt = __vt__11TAdEp3Exist;
    o->x0 = lbl_805D4500;
    o->win1C = 0;
    o->cur20 = 0;
    o->x24 = 0;
    o->x34 = 0;
    o->x28 = 0;
    o->x30 = 0;
    flag[0] = 0;
    res = load_and_verify_character_save__23TAdSinglePlyChrSelectGCFPc(flag, save);
    ok = false;
    if (res != 0) {
        if (flag[0] != 0) {
            ok = true;
        }
    }
    go = false;
    if (ok) {
        if ((s8)get_instance__23TAdSinglePlyChrSelectGCFv()[0x1152C] == 0) {
            go = true;
        }
    }
    if (!go) {
        ((int (*)(void))reset_and_set_mode__21TAdMultiChgGameModeGCFv)();
        queue_destruction__7TObjectFv(o);
        return o;
    }
    p = __nw__7TObjectFUl(0x24);
    if (p != 0) {
        __ct__9TAdBackGCFv(p, o);
    }
    p = __nw__7TObjectFUl(0x28);
    if (p != 0) {
        __ct__12TAdBackTxtGCFv(p, o);
    }
    r = (u32)__nw__7TObjectFUl(0x54);
    if (r != 0) {
        r = (u32)TAdScrollWinGC__ct((TAdScrollWinGC *)((void *)r), (void *)o, 3, (s32)(get_localized_text_entry(0x2C, 9)));
    }
    o->win1C = r;
    r = (u32)__nw__7TObjectFUl(0x708);
    if (r != 0) {
        r = __ct__14TAdSelectCurGCFv((void *)r, tl_clipout, lbl_8047B8A8, lbl_8047B8B0);
    }
    o->cur20 = r;
    ((TLevelSelect *)(o->cur20))->add_item_rect(lbl_8047B8A8);
    fn_80329BAC((void *)o->cur20);
    ((TLobby *)(o->cur20))->set_ad_field(0);
    return o;
}

int prs_read_control_bit(Obj_8036F4DC *arg0) {
    s32 t;
    if (--arg0->cnt == 0) {
        arg0->bits = TAdEp3Exist__sub_8036F590((u8 *)arg0);
        arg0->cnt = 8;
    }
    t = arg0->bits;
    arg0->bits = t >> 1;
    return t & 1;
}

s32 TAdEp3Exist::free_if_valid(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void TAdEp3Exist__sub_8036F574(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0xC) = 0;
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 8) = 1;
}

u8 TAdEp3Exist__sub_8036F590(u8 *arg0) {
    u8 *temp_r4;
    temp_r4 = *(u8 **)((s8 *)arg0 + 0xC);
    *(u8 **)((s8 *)arg0 + 0xC) = (u8 *) (temp_r4 + 1);
    return *temp_r4;
}

void TAdEp3Exist__sub_8036F5A4(void* p) { *(s32*)((char*)p + 0x10) = 0; }
#pragma push
#pragma opt_lifetimes off
#define BIT(c) ((u8 (*)(void *))prs_read_control_bit)(c)
#define BYTE(c) TAdEp3Exist__sub_8036F590((u8 *)(c))
s32 prs_decompress(Prs_8036F5B0 *c, u8 *src, s32 arg2, s32 arg3) {
    s32 n;
    s32 off;
    u32 size;
    u8 *p;
    u32 lo;
    u32 hi;
    u8 a;
    n = 0;
    c->fC = c->f14 = arg2;
    c->f18 = src;
    c->f0 = src;
    c->f4 = src;
    c->f28 = arg3;
    c->f10 = (u8 *)0x80001800;
    for (;;) {
        if (c->f2C != 0) break;
        while (BIT(c)) {
            p = (u8 *)prs_next_output_byte(c);
            *p = BYTE(c);
            n++;
        }
        if (BIT(c)) {
            size = BYTE(c);
            hi = BYTE(c);
            if ((hi | size) == 0) break;
            off = (s32)(hi << 5) + (s32)(size >> 3) - 0x2000;
            size &= 7;
            if (size != 0) {
                size += 2;
            } else {
                size = BYTE(c) + 1;
            }
        } else {
            a = BIT(c);
            size = (a << 1) + BIT(c) + 2;
            off = BYTE(c) - 0x100;
        }
        off += n;
        while (size-- != 0) {
            p = (u8 *)prs_next_output_byte(c);
            *p = prs_read_byte_at((u8 *)c, off);
            n++;
            off++;
        }
    }
    if (c->f2C != 0) {
        TAdEp3Exist__sub_8036F5A4((void*)(c));
        return -1;
    }
    size = n;
    if (c->f1C != 0) {
        memmove(c->f18 + (n - c->f1C), c->f10, c->f1C);
        c->f1C = 0;
    }
    TAdEp3Exist__sub_8036F5A4((void*)(c));
    return size;
}
#pragma pop

