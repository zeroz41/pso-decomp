#include "types.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/TObjLuker.h"
struct Txt_802497A8 { u16 flags; u8 pad2[6]; f32 x; u8 padC[4]; f32 w; };

struct Set_802497A8 { void *t0; Txt_802497A8 *t4; void *t8; void *tC; void *t10; void *t14; };

struct Win_802497A8 { u8 pad[4]; Set_802497A8 *set; };

extern "C" {
s32 get_shared_text_buffer();
s8 TWindowSubComCard__sub_8007B6EC(void *);
s32 TWindowSubComCard__sub_8007B6F4(void *);
s32 get_com_card_list__6TLobbyFPv(void *);
void TWindowSubStatusDisp__sub_80228F5C(int);
void refresh_status_display__9TWindowDDFv(void *);
s8 TWindowComCard__sub_80249C18(void *);
s8 TWindowComCard__sub_80249C20(void *);
}
void text_builder_reset();
s32 get_class_name_text(s32 arg0);
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2);
extern s32 com_card_status_text_table[];
extern const f32 lbl_805DCBCC;
extern "C" {
void update_com_card_display(Win_802497A8 *arg0, void *arg1);
void update_com_card_display(Win_802497A8 *arg0, void *arg1) {
    Txt_802497A8 *t4;
    void *t14;
    void *t0;
    void *tC;
    void *t8;
    void *t10;
    Set_802497A8 *s;
    s32 n;
    s32 id;
    s = arg0->set;
    t0 = s->t0;
    tC = s->tC;
    t8 = s->t8;
    t10 = s->t10;
    t4 = s->t4;
    t14 = s->t14;
    set_text_entry_string((u8 *)t0, (u32)((void *)get_com_card_list__6TLobbyFPv(arg1)), 0x220);
    n = TWindowComCard__sub_80249C20(arg1);
    if (n > 5) {
        n = 5;
    }
    TWindowDuelResult::set_default_status(tC, com_card_status_text_table[n]);
    n = TWindowSubComCard__sub_8007B6EC(arg1);
    if (n > 0xC) {
        n = 0xC;
    }
    TWindowDuelResult::set_default_status(t8, get_class_name_text(n));
    n = TWindowComCard__sub_80249C18(arg1);
    if (n > 0xA) {
        n = 0xA;
    }
    TWindowDuelResult::set_default_status(t10, TObjLuker::get_stat_table_entry(n));
    if (TWindowSubComCard__sub_8007B6F4(arg1) != 0) {
        id = ((TWindowSubComCard *)arg1)->get_card_id();
        if (id == 0) {
            t4->flags |= 2;
        } else {
            text_builder_reset();
            TWindowSubStatusDisp__sub_80228F5C(id);
            set_text_entry_string((u8 *)t4, (u32)((void *)get_shared_text_buffer()), 0x20);
            refresh_status_display__9TWindowDDFv(t4);
            t4->x = lbl_805DCBCC - t4->w;
            t4->flags &= ~2;
        }
    } else {
        t4->flags |= 2;
    }
    set_text_entry_string((u8 *)t14, (u32)((void *)((TWindowComCard *)arg1)->get_kbd_ptr()), 0x220);
}
}
