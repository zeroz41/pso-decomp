#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TScreenFadeOut.h"
#include "pso/unk/TUnk_804C8678.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildSeqOffline_80213788.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/task/TMainTask.h"

struct Base_802133C4_80212D9C { char pad[0x18]; };
struct VObj_802133C4_80212D9C : Base_802133C4_80212D9C {
    virtual void m0(); virtual void m1();
};
#include <stddef.h>
#include "pso/ui/city/THunterGuildWarning.h"

#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_8022350C.h"

#pragma readonly_strings on
struct Stack_802130AC {
    f32 sp8;
    f32 spC;
};

struct Base_8021317C { u8 pad[0x18]; };

struct Guild_8021317C : Base_8021317C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void m7(int, int);
    virtual s32 m8();
    virtual void m9();
    virtual void begin();
    virtual void finish();
    u32 unknown1c;
    u32 phase;
};

extern "C" {
saddr get_window_layout_position(s32);
s32 THunterGuildSeqOffline__quest_result_callbacks[4];
s32 THunterGuildSeqOffline__instance_table[4];
THunterGuildSeqOffline *THunterGuildSeqOffline__active_instance;
const char *lbl_805D3658 = "THunterGuildSeqOffline";
void THunterGuildSeqOffline__sub_8021339C(void);
void THunterGuildSeqOffline__sub_80213410(void);
s32 THunterGuildSeqOffline__sub_80213458(void);

int fn_80223480(void*);

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

void THunterGuildSeqOnline_Client::open_judgment_item_window() {
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        choice_menu = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), (u16)((TObjBase *)((saddr)player))->get_entity_id(), NULL, NULL);
        ((TWindowSubComCardList *)choice_menu)->set_selected_index(1);
        ((TWindowAddition *)choice_menu)->set_position_xy(get_scale(), get_scale());
        display_guild_message(8, 1);
        set_state(7);
    }
}

void THunterGuildSeqOnline_Client::handle_confirm_window() {
    if ((choice_menu != NULL) && (((TWindowMenu *)choice_menu)->is_decided() != 0)) {
        switch (((TWindowMenu *)choice_menu)->get_selected_value()) {
        case 0:
            choice_menu->close();
            choice_menu = NULL;
            display_guild_message(9, 1);
            pad_34 = 1;
            if (THunterGuildSeqOffline__quest_result_callbacks[2] != -1) {
                quest_thread = reinterpret_cast<TQuestThread *>(TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[2]));
            }
            set_state(0xC);
            break;
        case 1:
            choice_menu->close();
            choice_menu = NULL;
            display_guild_message(0xA, 1);
            pad_34 = 0;
            set_state(0xC);
            break;
        }
    }
    if ((choice_menu != NULL) && (((TWindowMenu *)choice_menu)->is_cancelled() != 0)) {
        choice_menu->close();
        choice_menu = NULL;
        display_guild_message(0xA, 1);
        pad_34 = 0;
        set_state(0xC);
    }
}

void THunterGuildSeqOnline_Client::close_window() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) {
            return;
        }
        quest_thread = NULL;
    }
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        switch (pad_34) {
        case 1: {
            new TScreenFadeOut(tl_00, reset_random_enemies_mode);
            THunterGuildSeqOffline__sub_8021E180(((TObjBase *)((saddr)player))->get_entity_id());
            break;
        }
        case 0:
            break;
        case 2:
            break;
        }
        TShopSequence::close_window();
        queue_destruction();
    }
}

s32 THunterGuildSeqOffline__sub_80213458(void) {
    if (hunter_guild_seq_online_client_instance != NULL) {
        return hunter_guild_seq_online_client_instance->state;
    }
    return -1;
}

void THunterGuildSeqOffline::reset_quest_result_callbacks() {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOffline__quest_result_callbacks[i] = -1;
}

void THunterGuildSeqOffline__sub_80213410(void) { THunterGuildSeqOffline::reset_quest_result_callbacks(); }

void THunterGuildSeqOffline::notify_quest_thread() {
    s32 v = THunterGuildSeqOffline__quest_result_callbacks[3];
    if (v != -1) {
        void *obj = TQuestThread::create(v);
        if (obj != NULL) {
            ((VObj_802133C4_80212D9C *)obj)->m1();
        }
    }
}

void THunterGuildSeqOffline__sub_8021339C(void) {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOffline__instance_table[i] = 0;
}

void THunterGuildSeqOffline::clear_instance_table() {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOffline__instance_table[i] = 0;
}

THunterGuildSeqOffline::THunterGuildSeqOffline(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = lbl_805D3658;
    state = 0;
    choice_menu = NULL;
    this->player = player;
    counter_camera = NULL;
    m_34 = 0;
    unk_38 = 0;
    THunterGuildSeqOffline__active_instance = this;
    THunterGuildSeqOffline__instance_table[get_split_screen_slot()] = 1;
}

THunterGuildSeqOffline::~THunterGuildSeqOffline() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        ((TWindowBase *)choice_menu)->close();
        choice_menu = NULL;
    }
    if (m_34 != 0) {
        ((TObject *)m_34)->queue_destruction();
        m_34 = 0;
    }
    THunterGuildSeqOffline__instance_table[get_split_screen_slot()] = 0;
    THunterGuildSeqOffline__active_instance = NULL;
}

void THunterGuildSeqOffline::update_state() {
    Guild_8021317C *self = (Guild_8021317C *)this;
    switch (self->phase) {
    case 0: self->begin(); break;
    case 1: ((THunterGuildSeqOffline *)self)->open_greeting(); break;
    case 2: ((THunterGuildSeqOffline *)self)->resolve_active_quest_result(); break;
    case 3: ((THunterGuildSeqOffline *)self)->open_judgment_window(); break;
    case 4: ((THunterGuildSeqOffline *)self)->open_quest_list(); break;
    case 5: self->finish(); break;
    case 6: ((THunterGuildSeqOffline *)self)->handle_cancel_choice(); break;
    case 7: ((THunterGuildSeqOffline *)self)->handle_select(); break;
    case 8: ((THunterGuildSeqOffline *)self)->handle_window_input(); break;
    case 9: ((THunterGuildSeqOffline *)self)->handle_click(); break;
    case 10: break;
    }
}

void THunterGuildSeqOffline::restore_player_state() { TShopSequence::restore_player_state(); fn_80223480(this); THunterGuildWarning::create_instance((saddr)((void*)2)); set_state((saddr)((void*)((void*)1))); }

void THunterGuildSeqOffline::open_greeting() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802130AC, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802130AC, spC) == 0x4);
    Stack_802130AC stack;
    stack.sp8 = 332.0f;
    stack.spC = 80.0f;
    ((TShopSequence *)arg0)->create_message_window((s32)((saddr) (((u8 *)get_window_layout_position(0x2C)))), (saddr)&stack.sp8);
    this->display_guild_message(1, 1);
    counter_camera = set_service_counter_camera(arg0, 1);
    ((TShopWindowBase *)arg0)->set_state((saddr)((void*)(2)));
}

void THunterGuildSeqOffline::resolve_active_quest_result() {
    u8 *arg0 = (u8 *)this;
    if ((this->is_message_ready() != 0) && ((((TShopWindowBase *)arg0)->is_decide_pressed() != 0) || (((TShopWindowBase *)arg0)->is_cancel_pressed() != 0))) {
        if (is_quest_active() == 1) {
            if (TQuestThread::get_register(quest_mission_manager, 0xFF) == 1) {
                this->display_guild_message(0xB, 1);
                if ((s32) *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 4) != -1) {
                    this->m_34 = reinterpret_cast<TQuestThread *>(TQuestThread::create_in_root(*(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 4)));
                }
                ((TShopWindowBase *)arg0)->set_state((saddr)((void*)(7)));
                return;
            }
            if (TQuestThread::get_register(quest_mission_manager, 0xFD) == 1) {
                this->display_guild_message(0x12, 1);
                if ((s32) *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 0) != -1) {
                    this->m_34 = reinterpret_cast<TQuestThread *>(TQuestThread::create_in_root(*(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 0)));
                }
                ((TShopWindowBase *)arg0)->set_state((saddr)((void*)(8)));
                return;
            }
            this->display_guild_message(2, 1);
            ((TShopWindowBase *)arg0)->set_state((saddr)((void*)(3)));
            return;
        }
        this->display_guild_message(4, 1);
        ((TShopWindowBase *)arg0)->set_state((saddr)((void*)(4)));
    }
}

void THunterGuildSeqOffline::open_judgment_window() {

    if ((this->is_message_ready() != 0)
        && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        *(s32 *)&this->choice_menu = (saddr)create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), (u16)((TObjBase *)((saddr)this->player))->get_entity_id(), NULL, NULL);
        ((TWindowSubComCardList *)(this->choice_menu))->set_selected_index(1);
        ((TWindowAddition *)(this->choice_menu))->set_position_xy(get_scale(), get_scale());
        this->display_guild_message(8, 1);
        set_state((saddr)((void*)(6)));
    }
}

void THunterGuildSeqOffline::handle_select() {
    void *p = *(void * *)&this->m_34;
    if (p != NULL) {
        if (((TObject *)p)->all_parents_unqueued_for_destruction() != 1) {
            this->m_34 = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((this->is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
            this->display_guild_message(0xC, 1);
            *(s32 *)&this->unk_38 = 1;
            set_state((saddr)((void*)(5)));
        }
    }
}

}
