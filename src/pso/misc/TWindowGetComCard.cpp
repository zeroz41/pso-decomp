#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowGetComCard.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowMessagePage.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TUnk_804CF0B8.h"
#include "pso/misc/TWindowFukidasi.h"

#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjCityMainWarp.h"

struct RecoveredGlobal_80252FCC___vt__17TWindowGetComCard {
    s32 value;
    u8 remaining[0x14];
};

struct Pad_80252CCC { u8 pad[0x20]; u8 m20[0x30]; };

struct GetCard_80252CCC {
    u8 pad0[0x1C];
    void *fmt;
    void *win;
    s32 state;
    s32 timer;
};

extern "C" {
s32 *get_shared_text_buffer(void);
s32 init_com_card__17TWindowSubComCardFv();
s32 *TWindowGetComCard__sub_8007B594(void);
s32 reset_equip_slots__10TObjPlayerFv();
void *get_player_by_client_id(s32 i);
void *get_com_card_list__6TLobbyFPv(void *p);
s32 text_builder_append();
s32 __ct__7TObjectFP7TObject();
void TObjPlayer__sub_8024ABDC(s32 arg0);
void fn_8024AC64(s32 arg0);
s32 create__14TWindowMessageFPvll(void *, void *, int);
extern s32 lbl_8044ED94[];
extern s32 lbl_8044ED9C[];
extern void *__vt__17TWindowGetComCard[];
extern s32 TWindowGetComCard__name;
extern s32 local_client_id;
u8 *TWindowGetComCard__ct(TWindowGetComCard *arg0);
void queue_destruction__7TObjectFv(void *);
void start_player_data_load__17TWindowSubComCardFl(void);
void TWindowGetComCard__sub_8007B54C(void);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void play_sound_effect(s32, s32, s32, s32);
s32 is_player_input_active(s32);
u8 *init_shop_judgment_window(void *p);
extern u8 TWindowGetComCard__window_rect[];
extern Pad_80252CCC controller_input_state[];
void run_task__17TWindowGetComCardFv(GetCard_80252CCC *self);
void TWindowFukidasi__sub_80252C38(void* p);
int fn_80252CBC(void* p);
void TLobby__sub_8024AC20(s32 arg0);
s32 TWindowCtrl__sub_8024A314();
void TWindowReturnCity__sub_8024ACA8(s32 arg0);
s32 init_parts__10TObjPlayerFv();

void TWindowFukidasi__sub_80252C38(void* p) { *(u8*)((char*)p + 0x71) |= 0x4; }
void TUnk_804CF0B8::clear_visible_flag() { this->m_71 &= 0xfe; }
void TUnk_804CF0B8::set_flag() { this->m_71 |= 0x1; }
void TUnk_804CF0B8::sub_80252C68() { this->m_71 |= 0x20; }
int TUnk_804CF0B8::is_flag_set() { return this->m_71 & 0x1; }
void TUnk_804CF0B8::clear_flag_20() { this->m_71 &= 0xffffffdf; }
int TUnk_804CF0B8::is_active() { return (this->m_71 >> 2) & 0x1; }
void TUnk_804CF0B8::clear_flag() { this->m_71 &= 0xfffffffb; }
int TUnk_804CF0B8::is_balloon_visible() { return (this->m_71 >> 5) & 0x1; }
int fn_80252CBC(void* p) { return *(u16*)((char*)p + 0x0) & 0x10; }
void TWindowGetComCard::render() {  }

void run_task__17TWindowGetComCardFv(GetCard_80252CCC *self) {
    s32 port = is_player_input_active(local_client_id);
    switch (self->state) {
    case 0:
    case 1:
        if (((TWindowMessagePage *)(self->fmt))->is_message_window_ready() != 0) {
            self->state = 2;
        }
        if (TWindowShortListCtrl__check_controller_button(controller_input_state[0].m20, 4) != 0) {
            ((TWindowMessage *)(self->fmt))->complete_reveal();
            self->state = 2;
        }
        break;
    case 2:
        if (self->timer != 0) {
            self->state = 5;
            break;
        }
        if (self->win == 0) {
            self->win = init_shop_judgment_window(TWindowGetComCard__window_rect);
            ((TWindowSubComCardList *)(self->win))->set_flag70_bit10();
        }
        ((TWindowSubComCard *)(self->win))->clear_flag_and_release();
        self->state = 3;
    case 3:
        if (((TWindowMenu *)(self->win))->is_cancelled() != 0) {
            TWindowGetComCard__sub_8007B54C();
            queue_destruction__7TObjectFv(self);
            self->state = 6;
        } else if (((TWindowMenu *)(self->win))->is_decided() != 0) {
            s32 r = ((TWindowMenu *)self->win)->get_selected_value();
            if (r == 0) {
                self->state = 4;
            }
            if (r == 1) {
                TWindowGetComCard__sub_8007B54C();
                queue_destruction__7TObjectFv(self);
                self->state = 6;
            }
        }
        break;
    case 4:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            TWindowGetComCard__sub_8007B594();
            start_player_data_load__17TWindowSubComCardFl();
            TWindowGetComCard__sub_8007B54C();
            queue_destruction__7TObjectFv(self);
            self->state = 6;
        } else if (TWindowShortListCtrl__check_controller_button(controller_input_state[port].m20, 2) != 0 ||
                   test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state[4].m20, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            self->state = 2;
        }
        break;
    case 5:
        if (self->timer-- <= 0 || TWindowShortListCtrl__check_controller_button(controller_input_state[0].m20, 4) != 0) {
            TWindowGetComCard__sub_8007B54C();
            queue_destruction__7TObjectFv(self);
            self->state = 6;
        }
        break;
    case 6:
        break;
    }
}
}
void text_builder_reset(void);
TWindowGetComCard::~TWindowGetComCard() {
    if ((u32) this->m_20 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x20)))->close();
        this->m_20 = 0U;
    }
    if ((u32) this->m_1c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x1C)))->close();
        this->m_1c = 0U;
    }
    TWindowReturnCity__sub_8024ACA8(local_client_id);
    TLobby__sub_8024AC20(local_client_id);
    if ((TWindowCtrl__sub_8024A314() == 0) && (get_player_by_client_id(local_client_id) != 0U)) {
        init_parts__10TObjPlayerFv();
    }
}

typedef char RecoveredGlobal_80252FCC___vt__17TWindowGetComCard_size[sizeof(RecoveredGlobal_80252FCC___vt__17TWindowGetComCard) == 0x18 ? 1 : -1];
u8 *TWindowGetComCard__ct(TWindowGetComCard *window_get_com_card) {
    s32 temp_r31;
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_get_com_card + 0x18) = &(*(RecoveredGlobal_80252FCC___vt__17TWindowGetComCard *)&__vt__17TWindowGetComCard).value;
    *(s32 *)((s8 *)window_get_com_card + 0) = (s32) TWindowGetComCard__name;
    window_get_com_card->m_1c = create__14TWindowMessageFPvll(lbl_8044ED94, lbl_8044ED9C, 1);
    window_get_com_card->m_20 = 0;
    if (init_com_card__17TWindowSubComCardFv() != 0) {
        temp_r31 = (s32)TWindowGetComCard__sub_8007B594();
        text_builder_reset();
        get_com_card_list__6TLobbyFPv((void *)temp_r31);
        text_builder_append();
        TWindowSubStatusDisp::get_message_10(0x36);
        text_builder_append();
        ((TWindowMessage *)(window_get_com_card->m_1c))->append_line((int) (get_shared_text_buffer()), 2);
        window_get_com_card->m_28 = 0;
    } else {
        ((TWindowMessage *)(window_get_com_card->m_1c))->append_line((int) (TWindowSubStatusDisp::get_message_10(0x37)), 0);
        window_get_com_card->m_28 = 0x384;
    }
    if (get_player_by_client_id(local_client_id) != 0U) {
        reset_equip_slots__10TObjPlayerFv();
    }
    TObjPlayer__sub_8024ABDC((local_client_id));
    fn_8024AC64((local_client_id));
    window_get_com_card->m_24 = 0;
    return (u8 *)window_get_com_card;
}
