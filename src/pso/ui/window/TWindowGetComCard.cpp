#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowGetComCard_8007B54C.h"
#include "pso/unk/text_8024AC64.h"
#include "pso/unk/text_8024ACA8.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TUnk_804CF0B8.h"
#include "pso/ui/window/TWindowFukidasi.h"

#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"

struct GetCard_80252CCC {
    u8 pad0[0x1C];
    void *fmt;
    void *win;
    s32 state;
    s32 timer;
};

extern "C" {
void *get_player_by_client_id(s32 i);
s32 text_builder_append();
s32 __ct__7TObjectFP7TObject();
extern void *__vt__17TWindowGetComCard[];
const char *TWindowGetComCard__name = "TWindowGetComCard";
extern s32 local_client_id;
u8 *TWindowGetComCard__ct(TWindowGetComCard *arg0);
void play_sound_effect(s32, s32, s32, s32);
u8 *init_shop_judgment_window(void *p);
__declspec(section ".data") f32 TWindowGetComCard__window_rect[2] = {152.0f, 370.0f};
void run_task__17TWindowGetComCardFv(GetCard_80252CCC *self);
void TWindowFukidasi__sub_80252C38(void* p);
int fn_80252CBC(void* p);

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
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 4) != 0) {
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
            ((TWindowMenu *)(self->win))->set_flag70_bit10();
        }
        ((TWindowSubComCard *)(self->win))->clear_flag_and_release();
        self->state = 3;
    case 3:
        if (((TWindowMenu *)(self->win))->is_cancelled() != 0) {
            TWindowGetComCard__sub_8007B54C();
            ((TObject *)self)->queue_destruction();
            self->state = 6;
        } else if (((TWindowMenu *)(self->win))->is_decided() != 0) {
            s32 r = ((TWindowMenu *)self->win)->get_selected_value();
            if (r == 0) {
                self->state = 4;
            }
            if (r == 1) {
                TWindowGetComCard__sub_8007B54C();
                ((TObject *)self)->queue_destruction();
                self->state = 6;
            }
        }
        break;
    case 4:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            TWindowSubComCard::start_player_data_load((saddr)TWindowGetComCard__sub_8007B594());
            TWindowGetComCard__sub_8007B54C();
            ((TObject *)self)->queue_destruction();
            self->state = 6;
        } else if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[port], 2) != 0 ||
                   test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            self->state = 2;
        }
        break;
    case 5:
        if (self->timer-- <= 0 || TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 4) != 0) {
            TWindowGetComCard__sub_8007B54C();
            ((TObject *)self)->queue_destruction();
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
    void *player;
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
    if ((TWindowCtrl__sub_8024A314() == 0) && ((player = (void *)get_player_by_client_id(local_client_id)) != 0U)) {
        ((TObjPlayer *)player)->init_parts();
    }
}

u8 *TWindowGetComCard__ct(TWindowGetComCard *window_get_com_card) {
    void *player;
    static const f32 pos[2] = {10.0f, 277.0f};
    static const f32 size[3] = {264.0f, 104.0f, 0.0f};
    saddr temp_r31;
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_get_com_card + 0x18) = ((s32 *)&__vt__17TWindowGetComCard);
    *(s32 *)((s8 *)window_get_com_card + 0) = (saddr) TWindowGetComCard__name;
    window_get_com_card->m_1c = (saddr)TWindowMessage::create((const NJS_POINT2 *)pos, (const f32 *)size, 1);
    window_get_com_card->m_20 = 0;
    if (TWindowSubComCard::init_com_card() != 0) {
        temp_r31 = (saddr)TWindowGetComCard__sub_8007B594();
        text_builder_reset();
        ((TLobby *)temp_r31)->get_com_card_list();
        text_builder_append();
        TWindowSubStatusDisp::get_message_10(0x36);
        text_builder_append();
        ((TWindowMessage *)(window_get_com_card->m_1c))->append_line((saddr) (get_shared_text_buffer()), 2);
        window_get_com_card->m_28 = 0;
    } else {
        ((TWindowMessage *)(window_get_com_card->m_1c))->append_line((saddr) (TWindowSubStatusDisp::get_message_10(0x37)), 0);
        window_get_com_card->m_28 = 0x384;
    }
    if ((player = (void *)get_player_by_client_id(local_client_id)) != 0U) {
        ((TObjPlayer *)player)->reset_equip_slots();
    }
    TObjPlayer__sub_8024ABDC((local_client_id));
    fn_8024AC64((local_client_id));
    window_get_com_card->m_24 = 0;
    return (u8 *)window_get_com_card;
}
