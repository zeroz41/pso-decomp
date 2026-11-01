#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/unk/text_8026A93C.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802C6F88.h"
#include "pso/ui/TAdScrollWinGC_8026A5F8.h"
#include "pso/ui/TAdScrollWinGC_80327504.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowMessageLog.h"
#include "pso/ui/TAdScrollWinGC.h"
#include "pso/misc/TLobby.h"

struct RecoveredGlobal_80327698___vt__14TAdScrollWinGC { s32 value; u8 remaining[0x14]; };

extern "C" {
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_80327698___vt__14TAdScrollWinGC __vt__14TAdScrollWinGC;
extern u8 controller_physical_port_bank[];
extern const f32 lbl_805DF69C;
extern const f32 lbl_805DF6A0;
extern const f32 lbl_805DF6A4;
extern const f32 lbl_805DF6A8;
extern const f32 lbl_805DF6AC;
extern const f32 lbl_805DF6B0;
void __ct__7TObjectFP7TObject(void *, void *);
extern u8 lbl_80476770[];
extern u8 lbl_80476778[];
extern s32 TAdScrollWinGC__class_name;
extern s32 scroll_win_texture_handle;
extern const f32 lbl_805DF6B4;
extern const f32 lbl_805DF6B8;
extern const f32 lbl_805DF6BC;
extern const f32 lbl_805DF6C0;

void TAdScrollWinGC::close_window() { if (this->m_40 != 0) { ((TWindowBase *)this->m_40)->close(); this->m_40 = 0; } }

void TAdScrollWinGC::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 d;
    u32 a;
    switch (*(s32 *)&this->m_4c) {
    case 0:
        break;
    case 1:
        if (++*(s32 *)&this->m_50 > lbl_805DF69C) {
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        break;
    }
    this->m_3c += 0xC;
    this->m_3c = this->m_3c > 0xFF ? 0xFF : this->m_3c;
    *(f32 *)&this->unk_1C = lbl_805DF6A0;
    this->m_20 = lbl_805DF6A4;
    *(f32 *)&this->unk_24 = lbl_805DF6A8;
    this->m_28 = lbl_805DF6AC;
    d = *(s16 *)((s8 *)controller_physical_port_bank + 0x3A);
    if (d < 0) {
        d += 0x19;
        if (*(void * *)&this->m_40 != 0) {
            fn_8026A61C(*(void * *)&this->m_40, lbl_805DF6B0 * d);
        }
    }
    if (d > 0 && *(void * *)&this->m_40 != 0) {
        ((TAdScrollWinGC *)(*(void * *)&this->m_40))->advance_scroll(lbl_805DF6B0 * (d - 0x19));
    }
}

u8 *__dt__14TAdScrollWinGCFv(u8 *arg0, s16 arg1) {
    u8 *object;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__14TAdScrollWinGC.value;
        object = (u8 *)(*(u8 **)((s8 *)arg0 + 0x40));
        if (object != NULL) {
            queue_destruction__7TObjectFv(object);
            *(u8 **)((s8 *)arg0 + 0x40) = NULL;
        }
        fn_8026A14C();
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}
void *TAdScrollWinGC__ct(TAdScrollWinGC *ad_scroll_win_gc, void *arg1, s32 arg2, s32 arg3) {
    s32 base;
    s32 i;
    __ct__7TObjectFP7TObject(ad_scroll_win_gc, arg1);
    *(s32 **)((s8 *)ad_scroll_win_gc + 0x18) = &__vt__14TAdScrollWinGC.value;
    *(s32 *)((s8 *)ad_scroll_win_gc + 0) = (s32) TAdScrollWinGC__class_name;
    scroll_win_texture_handle = TAdMultiPlyChrSelectGC__sub_802C6FA8();
    ad_scroll_win_gc->m_3c = 0;
    ad_scroll_win_gc->m_40 = 0;
    ad_scroll_win_gc->m_44 = arg2;
    ad_scroll_win_gc->m_48 = 0;
    ad_scroll_win_gc->m_4c = 0;
    ad_scroll_win_gc->m_50 = 0;
    base = ad_scroll_win_gc->get_scroll_delay_for_mode();
    ad_scroll_win_gc->m_40 = (s32)create_message_log_window((s32)lbl_80476770, (s32)lbl_80476778, 0);
    switch (ad_scroll_win_gc->m_44) {
    case 0:
    case 1:
        for (i = 0; i < 10; i++) {
            ((TWindowMessage *)(ad_scroll_win_gc->m_40))->append_line(get_localized_text_entry(0x1A, base + i), 1);
        }
        break;
    case 2:
    case 3:
        ((TWindowMessage *)(ad_scroll_win_gc->m_40))->append_line(arg3, 1);
        break;
    }
    ((TWindowMessage *)(ad_scroll_win_gc->m_40))->complete_reveal();
    ((TWindowMessageLog *)(ad_scroll_win_gc->m_40))->update_scroll_position();
    TAdScrollWinGC__sub_8026A5F8((void *)ad_scroll_win_gc->m_40);
    *(f32 *)((s8 *)ad_scroll_win_gc + 0x2C) = lbl_805DF6B4;
    ad_scroll_win_gc->m_30 = lbl_805DF6B8;
    *(f32 *)((s8 *)ad_scroll_win_gc + 0x34) = lbl_805DF6BC;
    ad_scroll_win_gc->m_38 = lbl_805DF6C0;
    return ad_scroll_win_gc;
}

}
