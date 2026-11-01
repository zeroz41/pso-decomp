#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowShortCut.h"
#include "pso/misc/TWindowSubShortCut.h"
class TChCrTagPlBack;
struct TWindowShortCut;
#include "pso/misc/TWindowChat.h"

#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubQuestBoardSelect.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/object/TObjCityMainWarp.h"

struct Win_8027DBB8 { u8 pad[0x20]; s32 f20; };

struct VBase_18_204a81 { char pad[0x18]; };

struct VObj_18_204a81 : VBase_18_204a81 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

extern "C" {
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 get_window_layout_position(s32 a0);
void open_yes_no_prompt(TChCrTagPlBack *arg0, u32 arg1, s32 arg2, s32 arg3, f32 farg0);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, s32, s32, s32);
extern const f32 lbl_805DD6C0;
void queue_destruction__7TObjectFv(void *);
s32 clear_chat_shortcut();
}
s32 store_chat_shortcut(s32 arg0, s32 arg1);
extern "C" {
void *__nw__7TObjectFUl(u32);
s32 get_cursor_value__19TWindowMenuIconLineFv(s32);
void open_com_card_list__18TWindowSubShortCutFv(void *arg0);
u32 *get_chat_shortcut();
s32 align_menu_entry_positions(s32);
s32 get_window_layout_position(s32 a0 = 0);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 draw_card_icon__17TWindowSubComCardFll(s32, s32, s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 free_member__17TWindowSubComCardFv(s32, s32);

int TWindowSubQuestBoardSelect::is_shortcut_active() { return this->m_60 & 0x4; }

s32 TWindowSubShortCut::open_confirm_message() {
    s32 temp_r29;

    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0x3e)), (s32)(get_window_layout_position(0x76)), (f32)lbl_805DD6C0);
    free_member__17TWindowSubComCardFv(temp_r29, 1);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

s32 TWindowSubShortCut::open_confirm_prompt() {
    Win_8027DBB8 *arg0 = (Win_8027DBB8 *)this;
    s32 r = create__19TWindowMessageYesNoFPvPvPvPv(arg0, arg0->f20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)r), (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0x3D)), (s32)(get_window_layout_position(0x75)), (f32)lbl_805DD6C0);
    ((TWindowSubShortMail *)r)->notify_warp_flag70();
    return r;
}

s32 TWindowSubShortCut::open_menu() {
    s32 temp_r31;
    u32 *chat_shortcut;

    get_cursor_value__19TWindowMenuIconLineFv(this->m_2c);
    chat_shortcut = get_chat_shortcut();
    temp_r31 = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x74), 2, get_message_10__20TWindowSubStatusDispFl(0x2C));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x7E)), 6, 5);
    if ((u32) *chat_shortcut != 0U) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_10__20TWindowSubStatusDispFl(0x5A)), 6, 9);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_10__20TWindowSubStatusDispFl(0x5A), 6, 9);
    }
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DD6C0);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

void TWindowSubShortCut::open_com_card_list() {
    s32 tmp = get_window_layout_position(0x72);
    ((TWindowSubShortCutList *)tmp)->create((void *)this->m_24);
}
void TWindowSubShortCut::render() {  }

extern s32 __vt__18TWindowSubShortCut[];

void TWindowSubShortCut::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 var_r0;
    void *var_r30;
    switch (this->m_1c) {
    case 0:
    case 1:
        if ((u32) this->m_38 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_38);
            this->m_38 = 0U;
        }
        if ((u32) this->m_34 != 0U) {
            ((TWindowSubComCard *)(this->m_34))->close();
            this->m_34 = 0U;
        }
        if ((u32) this->m_3c != 0U) {
            ((TWindowBase *)this->m_3c)->close();
            this->m_3c = 0U;
        }
        if ((u32) this->m_30 != 0U) {
            ((TWindowBase *)this->m_30)->close();
            this->m_30 = 0U;
        }
        if ((u32) this->m_2c == 0U) {
            this->m_2c = ((s32 (*)(void *))open_com_card_list__18TWindowSubShortCutFv)(arg0);
        }
        ((TWindowSubShortCutList *)(this->m_2c))->refresh_entries();
        ((TWindowMenuIconLine *)(this->m_2c))->clear_decided();
        this->m_1c = 2U;
    case 2:
        if (((TWindowMenuIconLine *)(this->m_2c))->is_cancelled() != 0) {
            ((VObj_18_204a81 *)(this->m_28))->m7();
            this->m_1c = 0xBU;
            return;
        }
        if (((TWindowMenuIconLine *)(this->m_2c))->is_decided() != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        if ((u32) this->m_34 != 0U) {
            ((TWindowSubComCard *)(this->m_34))->close();
            this->m_34 = 0U;
        }
        if ((u32) this->m_30 == 0U) {
            this->m_30 = open_menu();
        }
        ((TWindowSubComCard *)(this->m_30))->clear_flag_and_release();
        ((TWindowSubComCard *)(this->m_30))->clear_transition_flag();
        this->m_1c = 4U;
    case 4:
        if (((TWindowMenu *)(this->m_30))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_30))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_30)->get_selected_value();
            return;
        }
        break;
    case 5:
        if ((u32) this->m_30 != 0U) {
            ((TWindowBase *)this->m_30)->close();
            this->m_30 = 0U;
        }
        if ((u32) this->m_2c != 0U) {
            this->m_24 = get_cursor_value__19TWindowMenuIconLineFv(this->m_2c);
            ((TWindowBase *)this->m_2c)->close();
            this->m_2c = 0U;
        }
        if ((u32) this->m_38 == 0U) {
            void *chat = new TWindowChat((TObject *)arg0, (u8 *)&this->m_40);
            *(void * *)&this->m_38 = chat;
            ((TWindowSubShortCut *)(this->m_38))->free_icon();
            ((TWindowSubShortCut *)(this->m_38))->close_and_clear_flag();
            ((TWindowSubShortCut *)(this->m_38))->set_flag1e_bit80();
        }
        this->m_1c = 6U;
    case 6:
        if (((TWindowChat *)(this->m_38))->is_visible() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowChat *)(this->m_38))->is_mode_bit4() != 0) {
            this->m_1c = 7U;
            return;
        }
        break;
    case 7:
        if ((u32) this->m_38 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_38);
            this->m_38 = 0U;
        }
        if ((u32) this->m_3c == 0U) {
            var_r30 = __nw__7TObjectFUl(0x74);
            if (var_r30 != 0) {
                var_r30 = (void *)TWindowShortCut__ct((TWindowShortCut *)((u8 *)var_r30), (s32)(get_window_layout_position(0x73)), this->m_24, (s32)((u8 *)arg0 + 0x40));
            }
            *(void * *)&this->m_3c = var_r30;
        }
        if ((u32) this->m_34 == 0U) {
            this->m_34 = open_confirm_prompt();
        }
        this->m_1c = 8U;
    case 8:
        if (((TWindowSubComCard *)(this->m_34))->get_card_data() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_34))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_34))->get_slot_or_neg1() == 0) {
                store_chat_shortcut((this->m_24), (s32)(arg0 + 0x40));
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 1U;
            return;
        }
        break;
    case 9:
        ((TWindowOptionCtrl *)(this->m_30))->open();
        if ((u32) this->m_34 == 0U) {
            this->m_34 = open_confirm_message();
        }
        this->m_1c = 0xAU;
    case 10:
        if (((TWindowSubComCard *)(this->m_34))->get_card_data() != 0) {
            this->m_1c = 3U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_34))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_34))->get_slot_or_neg1() == 0) {
                get_cursor_value__19TWindowMenuIconLineFv(this->m_2c);
                clear_chat_shortcut();
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 3U;
        }
        break;
    case 11:
        break;
    }
}

void *__dt__18TWindowSubShortCutFv(TWindowSubShortCut *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TWindowSubShortCut;
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x38)); arg0->m_38 = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x34)))->close(); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close(); arg0->m_3c = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close(); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2C)))->close(); arg0->m_2c = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}

extern void *TWindowSubShortCut__class_name;
TWindowSubShortCut::TWindowSubShortCut(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = TWindowSubShortCut__class_name;
    *(void **)((s8 *)this + 0x28) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_2c = 0;
    this->m_30 = 0;
    this->m_34 = 0;
    this->m_38 = 0;
    this->m_3c = 0;
    this->m_24 = 0;
    this->m_1c = 0;
}

void TWindowSubShortCut::set_flag1e_bit80() { this->m_1e |= 0x80; }
