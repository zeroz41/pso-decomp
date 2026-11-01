#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdYesNoBaseGC.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"

#include "pso/misc/TWindowSubComCard.h"

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct T_8032C118 { s32 a; s32 b; };

extern "C" {
s32 append_line__14TWindowMessageFii(int, void *, int);
s32 update_window_mode_from_progress__6TLobbyFPv(void *, void *);
void align_menu_entry_positions(s32);
void update_layout_height__21TWindowSubComCardListFf(f32);
u8 *init_shop_judgment_window(void *p);
extern T_8032C118 lbl_804772E8[];
extern const f32 lbl_805DF788;
struct VtBase8032C1C8_8032C188 { char pad[0x18]; };
struct VtObj8032C1C8_8032C188 : VtBase8032C1C8_8032C188 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

void *TAdYesNoBaseGC__ct(TAdYesNoBaseGC *arg0);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void *__ct__12TAdBackTxtGCFv(void *, void *);
void __ct__7TObjectFP7TObject(void *);
void *__ct__9TAdBackGCFv(void *, void *);
void *__nw__7TObjectFUl(int);
void copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);

s32 TAdYesNoBaseGC::sub_8032C0B4() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    temp_r31 = update_window_mode_from_progress__6TLobbyFPv((u8 *)&this->unk_30, (u8 *)&this->unk_38);
    append_line__14TWindowMessageFii(temp_r31, (void *) (((VObj_18 *)(arg0))->m8()), 1);
    return temp_r31;
}

s32 TAdYesNoBaseGC::create_menu_window() {
    TAdYesNoBaseGC *arg0 = this;
    T_8032C118 t = lbl_804772E8[0];
    s32 r = (s32)init_shop_judgment_window(&t);
    update_layout_height__21TWindowSubComCardListFf(lbl_805DF788);
    align_menu_entry_positions(r);
    ((TWindowSubComCardList *)r)->set_selected_index((s16)arg0->m_2c);
    return r;
}

void TAdYesNoBaseGC::init_parts(void *arg1, void *arg2) {
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv((void *)((char *)this + 48));
    ((void (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *)((char *)this + 56), arg2);
}

extern s8 controller_input_state[];
extern s8 controller_physical_port_bank[];
extern const f32 lbl_805DF78C;

void TAdYesNoBaseGC::vfunc_11() {
    s32 selected_menu_value;
    s32 temp_r4;

    this->m_20 = (s32) this->m_1c;
    switch (this->m_1c) {
    case 0:
        this->m_40 = sub_8032C0B4();
        this->m_44 = this->create_menu_window();
        this->m_1c = 1;
        break;
    case 1:
        if (((TWindowMenu *)(this->m_44))->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)this->m_44)->get_selected_value();
            switch (selected_menu_value) {
            case 0:
                this->vfunc_8();
                this->m_1c = 2;
                this->m_24 = 3;
                break;
            case 1:
                this->vfunc_9();
                this->m_1c = 2;
                this->m_24 = 4;
                break;
            }
        } else if ((TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
            this->m_1c = 2;
            this->m_24 = 4;
        }
        break;
    case 2:
        if ((u32) this->m_40 != 0U) {
            ((TWindowBase *)this->m_40)->close();
            this->m_40 = 0U;
        }
        if ((u32) this->m_44 != 0U) {
            ((TWindowBase *)this->m_44)->close();
            this->m_44 = 0U;
        }
        temp_r4 = this->m_28 + 1;
        this->m_28 = temp_r4;
        if ((f32) temp_r4 > lbl_805DF78C) {
            this->m_1c = (s32) this->m_24;
        }
        break;
    case 3:
        ((VtObj8032C1C8_8032C188*)this)->m4();
        break;
    case 4:
        ((VtObj8032C1C8_8032C188*)this)->m5();
        break;
    }
    if ((s32) this->m_20 != (s32) this->m_1c) {
        this->m_28 = 0;
    }
}

extern s32 __vt__14TAdYesNoBaseGC[];

}
TAdYesNoBaseGC::~TAdYesNoBaseGC() {
    if (*(void **)((s8 *)this + 0x40) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x40)); this->m_40 = 0; }
    if (*(void **)((s8 *)this + 0x44) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x44)); this->m_44 = 0; }
}


extern const f32 lbl_805DF790;
extern const f32 lbl_805DF794;
extern void *lbl_805D41F8;
extern const f32 lbl_805DF798;
extern const f32 lbl_805DF79C;

void *TAdYesNoBaseGC__ct(TAdYesNoBaseGC *ad_yes_no_base_gc) {
    void *o;
    void *o2;
    __ct__7TObjectFP7TObject(ad_yes_no_base_gc);
    *(s32 **)((s8 *)ad_yes_no_base_gc + 0x18) = __vt__14TAdYesNoBaseGC;
    *(void * *)&ad_yes_no_base_gc->m_name = lbl_805D41F8;
    ad_yes_no_base_gc->m_28 = 0;
    *(f32 *)((s8 *)ad_yes_no_base_gc + 0x30) = lbl_805DF790;
    ad_yes_no_base_gc->m_34 = lbl_805DF794;
    *(f32 *)((s8 *)ad_yes_no_base_gc + 0x38) = lbl_805DF798;
    ad_yes_no_base_gc->m_3c = lbl_805DF79C;
    ad_yes_no_base_gc->m_1c = 0;
    ad_yes_no_base_gc->m_24 = 0;
    ad_yes_no_base_gc->m_2c = 1;
    ad_yes_no_base_gc->m_40 = 0;
    ad_yes_no_base_gc->m_44 = 0;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        __ct__9TAdBackGCFv(o, ad_yes_no_base_gc);
    }
    o2 = __nw__7TObjectFUl(0x28);
    if (o2 != NULL) {
        __ct__12TAdBackTxtGCFv(o2, ad_yes_no_base_gc);
    }
    return ad_yes_no_base_gc;
}

