#include "pso/unk/text_80104FCC.h"
#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TShopJudgmentItemWindow.h"
#include "pso/item/TItem.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubMag.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"

struct Base_802205E4 { char pad[0x18]; };
struct VObj_802205E4 : Base_802205E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8022061C_802205E4 { char pad[0x18]; };
struct VObj_8022061C_802205E4 : Base_8022061C_802205E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};
struct Base_80220940_802205E4 { char pad[0x18]; };
struct VObj_80220940_802205E4 : Base_80220940_802205E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(int, int);
    virtual void m7();
    virtual int  m8();
};
struct Base_80221344_802205E4 { char pad[0x18]; };
struct VObj_80221344_802205E4 : Base_80221344_802205E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(s32, s32);
};

struct Base_18 { char pad[0x18]; };

struct VObj_18 : Base_18 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual s32 m6(int, int); virtual void m7();
    virtual s32 m8();
};

struct VBase_18_2e9c25 { char pad[0x18]; };

struct VObj_18_2e9c25 : VBase_18_2e9c25 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6(s32, s32);
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual s32 m33();
};

struct Ent_80221440 { s32 item; s32 idx; };

struct Win_80221440 {
    VObj_18_2e9c25 base;
    u8 pad1c[0x24 - 0x1C];
    u8 *player;
    u8 pad28[0x54 - 0x28];
    Ent_80221440 ents[30];
    u8 pad144[4];
    s32 count;
    u8 pad14c[0x154 - 0x14C];
    void *list;
};

struct VBase_802209D8 { char pad[0x18]; };
struct VObj_802209D8 : VBase_802209D8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual s8 m31();
};

extern "C" {
int obj_getPtr2B0_20(u8 *p);
void update_all__6TLobbyFi(s32 arg0);
void play_cue_stream_file(s32 name);
void TWindow__close(u8 *arg0);
s32 get_selected_menu_value(int);
s32 select_cursor_entry__22TWindowSubShortCutListFv(int);
extern s32 lbl_8044C1D4[];
u16 obj_getField1c(s32);
void fn_80221838(u8 *arg0, s32 arg1, s32 arg2);
}
s32 get_appraisal_text(s32 arg0);
extern "C" {
s32 calc_list_content_extent(void *);
u8 *create_item_list_window(s32 arg0, s32 arg1, s32 arg2);
void *memset(void *, int, unsigned long);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
s32 get_item_record__23TShopJudgmentItemWindowFPv(int, int, int);
void set_judgment_target_flag(void *arg0, void *arg1);
f32 get_scale__15TShopWindowBaseFv(void *);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 get_window_layout_position(s32);
extern u8 lbl_8044C1B0[];
u32 get_equip_field_d04__10TObjPlayerFl(int, s32);
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *self, void *item);
void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2);
void TItemData__clear_unidentified_flag(void *arg0);
u32 advance_item_id_counter(s32 client);
u32 __nw__7TObjectFUl(int);
u32 __ct__15TWindowHelpItemFPvUs(int, int, u16);
u32 create__22TWindowLoadItemTextureFPv(int, u16);
extern u8 lbl_8044C1C0[];
extern u8 lbl_8044C1CC[];
extern s32 local_client_id;
extern const f32 lbl_805DC708;
void *TShopJudgmentItemWindow__ct(TShopJudgmentItemWindow *arg0, void *arg1, void *arg2, void *arg3);
void *__dt__23TShopJudgmentItemWindowFv(TShopJudgmentItemWindow *arg0, s16 arg1);
s32 play_sound_effect(s32, s32, s32, s32);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
void *__ct__15TShopWindowBaseFv(void *arg0);
void __dl__7TObjectFPv(void *);
void *__dt__15TShopWindowBaseFv(void *self, s16 m);
void queue_destruction__7TObjectFv(void *arg0);

void TShopJudgmentItemWindow::vfunc_7() {
    struct VObj_802205E4 *temp_r3;

    temp_r3 = (struct VObj_802205E4 *)this->m_164;
    if (temp_r3 != NULL) {
        temp_r3->m5();
    }
}

void TShopJudgmentItemWindow::vfunc_8() {
    struct VObj_8022061C_802205E4 *temp_r3;

    temp_r3 = (struct VObj_8022061C_802205E4 *)this->m_164;
    if (temp_r3 != NULL) {
        temp_r3->m6();
    }
}

void TShopJudgmentItemWindow::invoke_callback_174_and_destroy() {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)this + 0x174);
    if (temp_r12 != NULL) {
        temp_r12(this->m_164);
        queue_destruction__7TObjectFv((this));
    }
}

void TShopJudgmentItemWindow::invoke_callback_16C_and_destroy() {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)this + 0x16C);
    if (temp_r12 != NULL) {
        temp_r12(this->m_164);
        queue_destruction__7TObjectFv((this));
    }
}

void TShopJudgmentItemWindow::invoke_callback_170_and_destroy() {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)this + 0x170);
    if (temp_r12 != NULL) {
        temp_r12(this->m_164);
        queue_destruction__7TObjectFv((this));
    }
}

void TShopJudgmentItemWindow::handle_pay_confirm() {
    s32 selected_menu_value;

    if (this->vfunc_10() != 0) {
        if ((u32) this->m_158 == 0U) {
            this->m_158 = (s32)create_yes_no_window(get_window_layout_position(0x2B), obj_getField1c(this->m_24), 0, 0);
            ((TWindowSubComCardList *)((void *)this->m_158))->set_selected_index(0);
            ((TUnk_804CDFE8 *)(this->m_158))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        }
        if (((u32) this->m_158 != 0U) && (((TWindowMenu *)(this->m_158))->is_visible() != 0)) {
            selected_menu_value = get_selected_menu_value(this->m_158);
            if (selected_menu_value == 0) {
                if ((u32) this->m_160 != 0U) {
                    TWindow__close((u8 *)this->m_160);
                    this->m_160 = 0U;
                }
                if ((u32) this->m_154 != 0U) {
                    TWindow__close((u8 *)this->m_154);
                    this->m_154 = 0U;
                }
                if ((u32) this->m_15c != 0U) {
                    TWindow__close((u8 *)this->m_15c);
                    this->m_15c = 0U;
                }
                if ((u32) this->m_50 != 0U) {
                    queue_destruction__7TObjectFv(*(void * *)&this->m_50);
                    this->m_50 = 0U;
                }
                *(s32 *)&this->_pad14C = 3;
                TWindow__close((u8 *)this->m_158);
                this->m_158 = 0U;
                try_spend_actor_meseta((u8 *)this->m_24, 0x64);
                ((VObj_18 *)(this))->m6(0xA, 1);
                this->set_field_20(5);
                return;
            }
            if (selected_menu_value == 1) {
                TWindow__close((u8 *)this->m_158);
                this->m_158 = 0U;
                ((VObj_18 *)(this))->m6(8, 1);
                this->set_field_20(4);
                return;
            }
            goto block_17;
        }
block_17:
        if (((u32) this->m_158 != 0U) && (((TWindowSubComCard *)(this->m_158))->get_status_flag() != 0)) {
            TWindow__close((u8 *)this->m_158);
            this->m_158 = 0U;
            ((VObj_18 *)(this))->m6(8, 1);
            this->set_field_20(4);
        }
    }
}

void TShopJudgmentItemWindow::update() {
    VObj_80220940_802205E4 *o = (VObj_80220940_802205E4 *)this;
    s32 c = *(s32 *)&this->_pad14C - 1;
    *(s32 *)&this->_pad14C = c;
    if (c <= 0 && o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m6(0xB, 1);
        set_field_20(0);
    }
}

#define F(o, t) (*(t *)(arg0 + (o)))

void TShopJudgmentItemWindow::handle_equip_prompt() {
    u8 *arg0 = (u8 *)this;
    f32 y;
    s32 sel;
    s32 id;
    VObj_802209D8 *item;
    u32 eq;

    if (this->vfunc_10() != 0) {
        if (F(0x158, void *) == NULL) {
            id = obj_getField1c(F(0x24, s32));
            F(0x158, s32) = (s32)create_yes_no_window(get_window_layout_position(0x2B), id, 0, 0);
            ((TWindowSubComCardList *)(F(0x158, void *)))->set_selected_index(0);
            y = get_scale__15TShopWindowBaseFv(arg0);
            ((TUnk_804CDFE8 *)(F(0x158, s32)))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), y);
        }
        if (F(0x158, void *) != NULL && ((TWindowMenu *)(F(0x158, void *)))->is_visible() != 0) {
            sel = get_selected_menu_value(F(0x158, s32));
            if (sel == 0) {
                if (F(0x160, void *) != NULL) {
                    TWindow__close((u8 *)(F(0x160, void *)));
                    F(0x160, void *) = NULL;
                }
                if (F(0x154, void *) != NULL) {
                    TWindow__close((u8 *)(F(0x154, void *)));
                    F(0x154, void *) = NULL;
                }
                if (F(0x15C, void *) != NULL) {
                    TWindow__close((u8 *)(F(0x15C, void *)));
                    F(0x15C, void *) = NULL;
                }
                TWindow__close((u8 *)(F(0x158, void *)));
                F(0x158, void *) = NULL;
                get_item_record__23TShopJudgmentItemWindowFPv(F(0x24, s32), F(0x48, s32), 1);
                F(0x34, s32) = F(0x48, s32);
                ((TObjPlayer *)(F(0x24, s32)))->request_inventory_item((TItemData*)(arg0 + 0x28));
                set_judgment_target_flag(arg0, &this->unk_28);
                item = (VObj_802209D8 *)find_item_by_id(F(0x34, s32));
                if (item != NULL && (eq = get_equip_field_d04__10TObjPlayerFl(F(0x24, s32), item->m31())) != 0) {
                    send_6x26_unequip_item__10TObjPlayerFPvPv((void *)(F(0x24, s32)), (void *)(((TItem *)eq)->get_item_id()));
                }
                send_6x25_equip_item((void *)(F(0x24, s32)), F(0x34, s32), 0);
                ((VObj_18 *)(arg0))->m6(0xB, 1);
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file((s32)lbl_8044C1B0);
                }
                ((TShopWindowBase *)arg0)->set_field_20(0);
            }
            if (sel == 1) {
                TWindow__close((u8 *)(F(0x158, void *)));
                F(0x158, void *) = NULL;
                get_item_record__23TShopJudgmentItemWindowFPv(F(0x24, s32), F(0x48, s32), 1);
                F(0x34, s32) = F(0x48, s32);
                ((TObjPlayer *)(F(0x24, s32)))->request_inventory_item((TItemData*)(arg0 + 0x28));
                set_judgment_target_flag(arg0, &this->unk_28);
                ((VObj_18 *)(arg0))->m6(0xB, 1);
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file((s32)lbl_8044C1B0);
                }
                ((TShopWindowBase *)arg0)->set_field_20(0);
            }
        }
        if (F(0x158, void *) != NULL && ((TWindowSubComCard *)(F(0x158, void *)))->get_status_flag() != 0) {
            TWindow__close((u8 *)(F(0x158, void *)));
            F(0x158, void *) = NULL;
            get_item_record__23TShopJudgmentItemWindowFPv(F(0x24, s32), F(0x48, s32), 1);
            F(0x34, s32) = F(0x48, s32);
            ((TObjPlayer *)(F(0x24, s32)))->request_inventory_item((TItemData*)(arg0 + 0x28));
            set_judgment_target_flag(arg0, &this->unk_28);
            ((VObj_18 *)(arg0))->m6(0xB, 1);
            if (TLobby::get_shop_value() > 0) {
                play_cue_stream_file((s32)lbl_8044C1B0);
            }
            ((TShopWindowBase *)arg0)->set_field_20(0);
        }
    }
}
#undef F

void TShopJudgmentItemWindow::update_judge_confirm() {
    u8 *arg0 = (u8 *)this;
    s32 selected_menu_value;
    if (((TShopWindowBase *)(arg0))->vfunc_10() != 0) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x158) == 0U) {
            *(s32 *)((s8 *)arg0 + 0x158) = (s32)create_yes_no_window(get_window_layout_position(0x2B), obj_getField1c((s32) (*(s32 *)((s8 *)arg0 + 0x24))), 0, 0);
            ((TUnk_804CDFE8 *)(*(s32 *)((s8 *)arg0 + 0x158)))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), get_scale__15TShopWindowBaseFv(arg0));
        }
        if (((u32) *(u32 *)((s8 *)arg0 + 0x158) != 0U) && (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x158)))->is_visible() != 0)) {
            selected_menu_value = get_selected_menu_value((s32) (*(u32 *)((s8 *)arg0 + 0x158)));
            if (selected_menu_value == 0) {
                if ((u32) *(u32 *)((s8 *)arg0 + 0x160) != 0U) {
                    TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x160)));
                    *(u32 *)((s8 *)arg0 + 0x160) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x154) != 0U) {
                    TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x154)));
                    *(u32 *)((s8 *)arg0 + 0x154) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x15C) != 0U) {
                    TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x15C)));
                    *(u32 *)((s8 *)arg0 + 0x15C) = 0U;
                }
                try_spend_actor_meseta((u8 *)(*(s32 *)((s8 *)arg0 + 0x24)), 0x64);
                if (check_equip_requirements(*(void **)((s8 *)arg0 + 0x24), arg0 + 0x28, NULL) != 0) {
                    ((VObj_18 *)(arg0))->m6(0xC, 1);
                    TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
                    *(u32 *)((s8 *)arg0 + 0x158) = 0U;
                    ((TShopWindowBase *)arg0)->set_field_20(7);
                    return;
                }
                get_item_record__23TShopJudgmentItemWindowFPv((s32) (*(s32 *)((s8 *)arg0 + 0x24)), (s32) (*(s32 *)((s8 *)arg0 + 0x48)), 1);
                *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)arg0 + 0x48);
                ((TObjPlayer *)(*(s32 *)((s8 *)arg0 + 0x24)))->request_inventory_item((TItemData*)(arg0 + 0x28));
                set_judgment_target_flag((arg0), (arg0 + 0x28));
                ((VObj_18 *)(arg0))->m6(0xB, 1);
                TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
                *(u32 *)((s8 *)arg0 + 0x158) = 0U;
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file((s32)lbl_8044C1B0);
                }
                ((TShopWindowBase *)arg0)->set_field_20(0);
                return;
            }
            if (selected_menu_value == 1) {
                TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
                *(u32 *)((s8 *)arg0 + 0x158) = 0U;
                ((VObj_18 *)(arg0))->m6(9, 1);
                ((TShopWindowBase *)arg0)->set_field_20(6);
                return;
            }
            goto block_19;
        }
block_19:
        if (((u32) *(u32 *)((s8 *)arg0 + 0x158) != 0U) && (((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x158)))->get_status_flag() != 0)) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
            *(u32 *)((s8 *)arg0 + 0x158) = 0U;
            ((VObj_18 *)(arg0))->m6(9, 1);
            ((TShopWindowBase *)arg0)->set_field_20(6);
        }
    }
}

void TShopJudgmentItemWindow::create_result_windows() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    u32 var_r29;
    temp_r0 = *(s32 *)&this->_pad14C - 1;
    *(s32 *)&this->_pad14C = temp_r0;
    if (temp_r0 <= 0) {
        if ((u32) this->m_154 == 0U) {
            switch (current_language) {
            case LANGUAGE_JAPANESE:
                this->m_154 = (u32) create_item_list_window((s32)lbl_8044C1C0, 1, (s32)(obj_getField1c(this->m_24)));
                break;
            case LANGUAGE_ENGLISH:
            case LANGUAGE_GERMAN:
            case LANGUAGE_FRENCH:
            case LANGUAGE_SPANISH:
            default:
                this->m_154 = (u32) create_item_list_window((s32)lbl_8044C1CC, 1, (s32)(obj_getField1c(this->m_24)));
                break;
            }
            TItemData__clear_unidentified_flag(((u8 *)&this->unk_28));
            this->m_34 = advance_item_id_counter(((u16) local_client_id));
            this->m_50 = (u32)construct_item((TItemData *)(arg0 + 0x28));
            ((TShopJudgmentItemWindow *)(this->m_154))->add_list_entry(this->m_50, 0);
            ((TWindowSubShortCutList *)(this->m_154))->set_flag70_bit10();
            ((TWindowSubTradeMain *)(this->m_154))->set_visible();
            ((TWindowSubTradeMain *)(this->m_154))->set_close_flag();
            calc_list_content_extent((void *)this->m_154);
        }
        if ((u32) this->m_160 == 0U) {
            this->m_160 = create__22TWindowLoadItemTextureFPv(get_window_layout_position(0x30), ((s32 (*)(s32))obj_getField1c)(this->m_24));
            ((TWindowSubMag *)(this->m_160))->set_mag_slot_state((s32)(arg0 + 0x28));
        }
        if ((u32) this->m_15c == 0U) {
            var_r29 = __nw__7TObjectFUl(0xBC);
            if (var_r29 != 0U) {
                var_r29 = __ct__15TWindowHelpItemFPvUs(var_r29, (int) (get_window_layout_position(0x27)), ((s32 (*)(s32))obj_getField1c)(this->m_24));
            }
            this->m_15c = var_r29;
            if (((u32) this->m_15c != 0U) && (TLobby::is_camera_ctrl_active() > 2)) {
                ((TLobby *)(this->m_15c))->set_position(lbl_805DC708, lbl_805DC708);
            }
            ((TWindowHelpItem *)(this->m_15c))->set_displayed_item_colored((u32)(arg0 + 0x28));
        }
        ((VObj_18 *)(arg0))->m6(8, 1);
        ((TShopWindowBase *)arg0)->set_field_20(4);
    }
}

#pragma push
#pragma fp_contract on
void TShopJudgmentItemWindow::handle_judge_confirm() {
    s32 selected_menu_value;
    u8 *temp_r31;
    u8 *arg0 = (u8 *)this;
    if (((TShopJudgmentItemWindow *)arg0)->vfunc_10() != 0) {
        if ((*(void **)((s8 *)arg0 + 0x158) != NULL) && (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x158)))->is_visible() != 0)) {
            selected_menu_value = get_selected_menu_value(this->m_158);
            if ((selected_menu_value == 0) && ((u32) this->m_154 != 0U)) {
                if (obj_getPtr2B0_20((u8 *)this->m_24) < 0x64) {
                    TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
                    this->m_158 = 0U;
                    ((VObj_18 *) arg0)->m6(5, 1);
                    ((TShopWindowBase *)arg0)->set_field_20(0xB);
                    return;
                }
                temp_r31 = arg0 + (select_cursor_entry__22TWindowSubShortCutListFv(this->m_154) * 8);
                if (((TItem *)(*(s32 *)((s8 *)temp_r31 + 0x54)))->copy_to_item_data((TItemData *)(arg0 + 0x3C)) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x168) = ((TItem *)(*(s32 *)((s8 *)temp_r31 + 0x54)))->is_at_tekker();
                    ((ItemData *)(arg0 + 0x28))->copy_from((ItemData *)(arg0 + 0x3C));
                    update_all__6TLobbyFi((s32)(arg0 + 0x28));
                    *(s32 *)((s8 *)arg0 + 0x14C) = 0x5F;
                    if (*(void **)((s8 *)arg0 + 0x154) != NULL) {
                        TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x154)));
                        this->m_154 = 0U;
                    }
                    play_cue_stream_file((s32)lbl_8044C1D4);
                }
                TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
                this->m_158 = 0U;
                ((VObj_18 *) arg0)->m6(6, 1);
                ((TShopWindowBase *)arg0)->set_field_20(3);
                return;
            }
            if (selected_menu_value == 1) {
                TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
                this->m_158 = 0U;
                ((VObj_18 *) arg0)->m6(4, 1);
                ((TShopWindowBase *)arg0)->set_field_20(1);
                ((TWindowSubItem *)(this->m_154))->clear_selected_and_update_entry();
                return;
            }
            goto block_14;
        }
block_14:
        if ((*(void **)((s8 *)arg0 + 0x158) != NULL) && (((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x158)))->get_status_flag() != 0)) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158)));
            this->m_158 = 0U;
            ((VObj_18 *) arg0)->m6(4, 1);
            ((TShopWindowBase *)arg0)->set_field_20(1);
            ((TWindowSubItem *)(this->m_154))->clear_selected_and_update_entry();
        }
    }
}
#pragma pop

void TShopJudgmentItemWindow::handle_input() {

    if (sub_802239EC__13TShopSequenceFv(this) != 0) {
        set_field_20(0xA);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (sub_80223A48__15TShopWindowBaseFv(this) != 0) {
        this->m_158 = (s32)create_yes_no_window(get_window_layout_position(0x2B), (u16)obj_getField1c(this->m_24), 0, 0);
        ((TUnk_804CDFE8 *)(this->m_158))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        ((VObj_80221344_802205E4 *)this)->m6(3, 1);
        set_field_20(2);
        play_sound_effect(0x52D01, 0, 0, 0);
    }
}

#define W ((Win_80221440 *)arg0)
s32 TShopJudgmentItemWindow::build_item_list(void *arg0) {
    VObj_18_2e9c25 *items[32];
    s32 n;
    s32 i;
    VObj_18_2e9c25 *it;
    s32 j;
    s32 k;
    memset(W->ents, 0, 0xF0);
    n = ((TObjPlayer *)(*(s32 *)(W->player + 0xD00)))->apply_shop_judgment((int)items);
    W->count = 0;
    for (i = 0; i < n; i++) {
        it = items[i];
        if (it != NULL && it->m33() == 0) {
            fn_80221838((u8 *)&W->ents[W->count++], (s32)items[i], i);
        }
    }
    if (W->count != 0) {
        ((TShopWindowBase *)W)->set_field_20(1);
    } else {
        W->base.m6(2, 1);
        ((TShopWindowBase *)W)->set_field_20(0xB);
        return;
    }
    if (W->list == NULL) {
        W->list = create_item_list_window(get_appraisal_text(0), W->count, (u16)((s32 (*)(s32))obj_getField1c)((s32)W->player));
        for (j = 0; j < W->count; j++) {
            ((TShopJudgmentItemWindow *)(W->list))->add_list_entry(W->ents[j].item, j);
        }
        calc_list_content_extent(W->list);
        return;
    }
    ((TShopArmorListWindow *)(W->list))->reset_list();
    for (k = 0; k < W->count; k++) {
        ((TShopJudgmentItemWindow *)(W->list))->add_list_entry(W->ents[k].item, k);
    }
    calc_list_content_extent(W->list);
    ((TWindowSubItem *)((int)W->list))->clear_selected_and_update_entry();
}
#undef W

void TShopJudgmentItemWindow::close() { if (*(unsigned int *)&this->m_50 != 0) { queue_destruction__7TObjectFv((*(void* *)&this->m_50)); *(int *)&this->m_50 = 0; } }

extern s32 __vt__23TShopJudgmentItemWindow[];

void TShopJudgmentItemWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        ((TShopJudgmentItemWindow *)arg0)->close();
        TShopJudgmentItemWindow::build_item_list(arg0);
        return;
    case 1:
        ((TShopJudgmentItemWindow *)arg0)->handle_input();
        return;
    case 2:
        ((TShopJudgmentItemWindow *)arg0)->handle_judge_confirm();
        return;
    case 3:
        ((TShopJudgmentItemWindow *)arg0)->create_result_windows();
        return;
    case 4:
        ((TShopJudgmentItemWindow *)arg0)->update_judge_confirm();
        return;
    case 5:
        ((TShopJudgmentItemWindow *)arg0)->update();
        return;
    case 6:
        ((TShopJudgmentItemWindow *)arg0)->handle_pay_confirm();
        return;
    case 7:
        ((TShopJudgmentItemWindow *)arg0)->handle_equip_prompt();
        return;
    case 10:
        ((TShopJudgmentItemWindow *)arg0)->invoke_callback_170_and_destroy();
        return;
    case 8:
        ((TShopJudgmentItemWindow *)arg0)->invoke_callback_16C_and_destroy();
        return;
    case 11:
        ((TShopJudgmentItemWindow *)arg0)->invoke_callback_174_and_destroy();
    default:
        return;
    }
}

void *__dt__23TShopJudgmentItemWindowFv(TShopJudgmentItemWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TShopJudgmentItemWindow;
        if (*(void **)((s8 *)arg0 + 0x154) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x154))); arg0->m_154 = 0; }
        if (*(void **)((s8 *)arg0 + 0x160) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x160))); arg0->m_160 = 0; }
        if (*(void **)((s8 *)arg0 + 0x158) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x158))); arg0->m_158 = 0; }
        if (*(void **)((s8 *)arg0 + 0x50) != NULL) { queue_destruction__7TObjectFv((*(void **)((s8 *)arg0 + 0x50))); arg0->m_50 = 0; }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *TShopJudgmentItemWindow__class_name;

void *TShopJudgmentItemWindow__ct(TShopJudgmentItemWindow *shop_judgment_item_window, void *arg1, void *arg2, void *arg3) {
    __ct__15TShopWindowBaseFv(shop_judgment_item_window);
    *(s32 **)((s8 *)shop_judgment_item_window + 0x18) = __vt__23TShopJudgmentItemWindow;
    *(void * *)&shop_judgment_item_window->m_name = TShopJudgmentItemWindow__class_name;
    shop_judgment_item_window->m_144 = 0;
    shop_judgment_item_window->m_148 = 0;
    shop_judgment_item_window->m_150 = 0;
    *(void **)((s8 *)shop_judgment_item_window + 0x24) = arg3;
    shop_judgment_item_window->m_154 = 0;
    shop_judgment_item_window->m_158 = 0;
    shop_judgment_item_window->m_15c = 0;
    shop_judgment_item_window->m_160 = 0;
    shop_judgment_item_window->m_50 = 0;
    *(void **)((s8 *)shop_judgment_item_window + 0x164) = arg2;
    shop_judgment_item_window->m_16c = 0;
    shop_judgment_item_window->m_170 = 0;
    shop_judgment_item_window->m_174 = 0;
    return shop_judgment_item_window;
}
}
