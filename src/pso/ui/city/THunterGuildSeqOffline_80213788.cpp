#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TUnk_804C8678.h"
#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/ui/city/THunterGuildSeqOffline_80213788.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/OnlineQuestMenuRecords.h"
#include "pso/quest/OnlineQuestDownloadState.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/system/TMemberCheck.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define PADV virtual void CAT(f,__LINE__)();
struct VBase_18_97738d { char pad[0x18]; };

struct VObj_18_97738d : VBase_18_97738d {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7(s32, s32);
};

struct Stack_80213B18 {
    f32 sp8;
    f32 spC;
};

struct Base_80213980 { char pad[0x18]; };

struct V_80213980 : Base_80213980 {
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual void m7(s32, s32);
    virtual s32 m8();
};

struct Obj_80213980 : V_80213980 { char pad1c[0x14]; s32 state; s32 f34; s32 thread; };

extern "C" {

saddr get_window_layout_position(s32);
// Online quest download state, read by TQuestListOnline (THunterGuildSeqOnlineTask.cpp).
OnlineQuestDownloadState TQuestListOnline__dat_download_state;
OnlineQuestDownloadState TQuestListOnline__bin_download_state;
// Per-player slot flags, set by each class's ctor and cleared by its dtor
// (same pattern as THunterGuildSeqOffline__instance_table).
s32 THunterGuildSeqOnline_Server__instance_table[4];
s32 THunterGuildSeqOnline_Client__instance_table[4];
OnlineQuestMenu *TQuestListOnline__quest_list_buffer;
OnlineQuestInfo *TQuestListOnline__selected_quest_info;
int TQuestListOnline__bin_download_complete;
int TQuestListOnline__dat_download_complete;
u32 TQuestListOnline__download_window;
TWindowMessage *TQuestListOnline__quest_info_window;
void *TQuestListOnline__download_barrier_window;
s32 quest_download_active;
s32 quest_download_received_bytes;
s32 quest_download_graph_current_bytes;
int is_quest_active(void);
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
void THunterGuildSeqOffline__sub_80213980(Obj_80213980 *self);
saddr set_service_counter_camera(void *, s32);

    extern int evt2_random_enemies_mode;

}

    extern int evt2_random_enemies_mode;

// Set by each class's ctor, cleared by its dtor.
THunterGuildSeqOnline_Server *hunter_guild_seq_online_server_instance;
THunterGuildSeqOnline_Client *hunter_guild_seq_online_client_instance;

struct List_80214058 { u8 pad[0x28]; void *f28; void *f2c; void *f30; void *f34; };

extern "C" {

saddr get_entity_id(void *);
int is_quest_active(void);
extern saddr TLobby__protocol_instance;

}

struct Stack_8021488C {
    f32 sp8;
    f32 spC;
};

extern "C" {

int is_quest_active(void);

saddr get_window_layout_position(s32);
int is_quest_active(void);
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
saddr set_service_counter_camera(void *, s32);
u8 *create_yes_no_window(s32 arg0, s32 arg1, uaddr arg2, uaddr arg3);
saddr get_window_layout_position(s32);


}

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

extern "C" {

THunterGuildSeqOnline_Server::THunterGuildSeqOnline_Server(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = THunterGuildSeqOnline_Server__name;
    state = 0;
    this->player = player;
    counter_camera = NULL;
    pad_34 = 0;
    choice_menu = NULL;
    quest_thread = NULL;
    pad_40 = 1;
    THunterGuildSeqOnline_Server__instance_table[sub_8022397C()] = 1;
    hunter_guild_seq_online_server_instance = this;
}

THunterGuildSeqOnline_Server::~THunterGuildSeqOnline_Server() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    THunterGuildSeqOnline_Server__instance_table[sub_8022397C()] = 0;
    hunter_guild_seq_online_server_instance = NULL;
}

void THunterGuildSeqOffline::zero_four_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        THunterGuildSeqOnline_Server__instance_table[i] = 0;
    }
}

void THunterGuildSeqOffline::clear_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        THunterGuildSeqOnline_Server__instance_table[i] = 0;
    }
}

void THunterGuildSeqOnline_Server::vfunc_11() {
    switch (state) {
    case 0: restore_player_state(); break;
    case 1: init_window(); break;
    case 3: sub_802145F8(); break;
    case 8: sub_80214058(); break;
    case 4: update_confirm_input(); break;
    case 5: update(); break;
    case 6: create_judgment_item_window(); break;
    case 7: sub_80214254(); break;
    case 9: set_field_20(0xC); break;
    case 10: set_field_20(0xC); break;
    case 12: close_window(); break;
    case 13: confirm_and_close_if_valid(); break;
    case 14: return;
    }
}

void THunterGuildSeqOnline_Server::restore_player_state() {
    TShopSequence::restore_player_state();
    counter_camera = (TObject *)set_service_counter_camera(this, 1);
    set_field_20(1);
}

void THunterGuildSeqOnline_Server::init_window() {
    Stack_8021488C stack;
    stack.sp8 = 332.0f;
    stack.spC = 80.0f;
    create_message_window(get_window_layout_position(0x2C), (saddr)&stack.sp8);
    if (is_quest_active() == 0) {
        new TMemberCheck(this);
    }
    display_guild_message(1, 1);
    pad_30 = 0;
    set_field_20(3);
}

void THunterGuildSeqOnline_Server::sub_802145F8() {
    if (vfunc_10() != 0) {
        if (sub_80223A48() != 0) {
            pad_40 = 0;
        }
        if (pad_40 == 0) {
            switch (pad_30) {
            case 3:
                break;
            case 0:
                if (is_quest_active() != 0) {
                    pad_30 = 2;
                    return;
                }
                switch (THunterGuildSeqOffline::check_party_gathered()) {
                case 1:
                    pad_30 = 2;
                    return;
                case 0:
                    display_guild_message(0x11, 1);
                    pad_30 = 1;
                    return;
                case 2:
                    display_guild_message(0xD, 1);
                    pad_30 = 1;
                    return;
                }
                break;
            case 1:
                if (THunterGuildSeqOffline::check_party_gathered() == 1) {
                    pad_30 = 2;
                }
                if (sub_802239EC() != 0) {
                    display_guild_message(0x10, 1);
                    set_field_20(0xD);
                    return;
                }
                break;
            case 2:
                if (is_quest_active() != 0) {
                    if (TQuestThread::get_register(quest_mission_manager, 0xFF) != 0) {
                        display_guild_message(0xB, 1);
                        if (THunterGuildSeqOffline__quest_result_callbacks[1] != -1) {
                            quest_thread = TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[1]);
                        }
                        set_field_20(4);
                        return;
                    }
                    if (TQuestThread::get_register(quest_mission_manager, 0xFD) != 0) {
                        display_guild_message(0x12, 1);
                        if (THunterGuildSeqOffline__quest_result_callbacks[0] != -1) {
                            quest_thread = TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[0]);
                        }
                        set_field_20(5);
                        return;
                    }
                    display_guild_message(2, 1);
                    set_field_20(6);
                    return;
                }
                display_guild_message(4, 1);
                pad_30 = 0;
                set_field_20(8);
                break;
            }
        }
    }
}

void THunterGuildSeqOnline_Server::update_confirm_input() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) {
            return;
        }
        quest_thread = NULL;
    }
    if ((vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC() != 0))) {
        display_guild_message(0xC, 1);
        pad_34 = 1;
        set_field_20(0xC);
    }
}

void THunterGuildSeqOnline_Server::update() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        quest_thread = NULL;
    }
    if ((vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC() != 0))) {
        display_guild_message(0xC, 1);
        pad_34 = 1;
        set_field_20(0xC);
    }
}

void THunterGuildSeqOnline_Server::create_judgment_item_window() {
    if ((vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC() != 0))) {
        choice_menu = (TWindowMenu *)create_yes_no_window(get_window_layout_position(0x2B), (u16)get_entity_id(player), 0, 0);
        ((TWindowSubComCardList *)choice_menu)->set_selected_index(1);
        choice_menu->set_position_xy(get_scale(), get_scale());
        display_guild_message(8, 1);
        set_field_20(7);
    }
}

void THunterGuildSeqOnline_Server::sub_80214254() {
    if ((choice_menu != NULL) && (choice_menu->is_decided() != 0)) {
        switch (choice_menu->get_selected_value()) {
        case 0:
            choice_menu->close();
            choice_menu = NULL;
            display_guild_message(9, 1);
            pad_34 = 1;
            if ((s32) THunterGuildSeqOffline__quest_result_callbacks[2] != -1) {
                quest_thread = TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[2]);
            }
            set_field_20(0xC);
            break;
        case 1:
            choice_menu->close();
            choice_menu = NULL;
            display_guild_message(0xA, 1);
            pad_34 = 0;
            set_field_20(0xC);
            break;
        }
    }
    if ((choice_menu != NULL) && (choice_menu->is_cancelled() != 0)) {
        choice_menu->close();
        choice_menu = NULL;
        display_guild_message(0xA, 1);
        pad_34 = 0;
        set_field_20(0xC);
    }
}

void THunterGuildSeqOnline_Server::close_window() {
    void *mem;
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) return;
        quest_thread = NULL;
    }
    if (vfunc_10() == 0) return;
    switch (pad_34) {
    case 0:
        if (sub_80223A48() == 0 && sub_802239EC() == 0) return;
        if (is_quest_active() == 0) {
            ((TProtocol *)TLobby__protocol_instance)->send_quest_menu_closed();
        }
        TShopSequence::close_window();
        queue_destruction();
        break;
    case 1:
        mem = TObject::operator new(0x28);
        if (mem != NULL) ((THunterGuildSeqOffline *)mem)->init((void *)tl_00, (void *)reset_random_enemies_mode);
        THunterGuildSeqOffline__sub_8021E180((saddr)(get_entity_id(player)));
        TShopSequence::close_window();
        queue_destruction();
        break;
    case 2:
        mem = TObject::operator new(0x28);
        if (mem != NULL) ((THunterGuildSeqOffline *)mem)->init((void *)tl_00, (void *)set_random_enemies_mode);
        THunterGuildSeqOffline__sub_8021E180((saddr)(get_entity_id(player)));
        TShopSequence::close_window();
        queue_destruction();
        break;
    }
}

void THunterGuildSeqOnline_Server::sub_80214058() {
    List_80214058 *l;
    l = (List_80214058 *)TObject::operator new(0x70);
    if (l != 0) {
        l = (List_80214058 *)TQuestListOnline__ct((TQuestListOnline *)l, (void *)tl_05, this, player);
    }
    if (l != 0) {
        display_guild_message(4, 1);
        l->f28 = (void *)THunterGuildSeqOffline__sub_80213F78;
        l->f2c = (void *)THunterGuildSeqOffline__sub_80213EBC;
        l->f30 = (void *)THunterGuildSeqOffline__sub_80213E64;
        l->f34 = (void *)THunterGuildSeqOffline::reset_quest_list_vm;
        set_field_20(0xE);
    }
}

void THunterGuildSeqOnline_Server::confirm_and_close_if_valid() {
    if (vfunc_10() != 0 && (sub_80223A48() != 0 || sub_802239EC() != 0)) {
        display_guild_message(0xc, 1);
        set_field_20(0xc);
    }
}

void THunterGuildSeqOffline__sub_80213F78(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(0xC, 1);
        hunter_guild_seq_online_server_instance->set_field_20(9);
        hunter_guild_seq_online_server_instance->pad_34 = 0;
    }
}

void THunterGuildSeqOffline::reset_quest_list_vm() {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_message((const char *)get_message_text(0x43), 1);
        hunter_guild_seq_online_server_instance->set_field_20(9);
        hunter_guild_seq_online_server_instance->pad_34 = 0;
    }
}

void THunterGuildSeqOffline__sub_80213EBC(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(0xC, 1);
        hunter_guild_seq_online_server_instance->set_field_20(0xA);
        hunter_guild_seq_online_server_instance->pad_34 = 2;
    }
}

void THunterGuildSeqOffline__sub_80213E64(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(6, 1);
        hunter_guild_seq_online_server_instance->set_field_20(0xC);
        hunter_guild_seq_online_server_instance->pad_34 = 2;
    }
}

}

void set_random_enemies_mode(void) { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 2; TKeyBoardControl__sub_8000F950(); }

extern "C" {

void reset_random_enemies_mode(void) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); }

THunterGuildSeqOnline_Client::THunterGuildSeqOnline_Client(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = THunterGuildSeqOnline_Client__name;
    state = 0;
    this->player = player;
    counter_camera = NULL;
    pad_30 = 0;
    pad_34 = 0;
    choice_menu = NULL;
    quest_thread = NULL;
    THunterGuildSeqOnline_Client__instance_table[sub_8022397C()] = 1;
    hunter_guild_seq_online_client_instance = this;
}

THunterGuildSeqOnline_Client::~THunterGuildSeqOnline_Client() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    THunterGuildSeqOnline_Client__instance_table[sub_8022397C()] = 0;
    hunter_guild_seq_online_client_instance = NULL;
}

void THunterGuildSeqOffline__sub_80213CA4(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        THunterGuildSeqOnline_Client__instance_table[i] = 0;
    }
}

void THunterGuildSeqOffline::clear_slots() {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOnline_Client__instance_table[i] = 0;
}

void THunterGuildSeqOnline_Client::vfunc_11() {
    switch (state) {
    case 0: restore_player_state(); break;
    case 1: THunterGuildSeqOffline__sub_80213B18((u8 *)this); break;
    case 2: THunterGuildSeqOffline__sub_80213980((Obj_80213980 *)this); break;
    case 11: handle_close(); break;
    case 4: update_close_shop(); break;
    case 5: update_shop_close(); break;
    case 6: open_judgment_item_window(); break;
    case 7: handle_confirm_window(); break;
    case 12: close_window(); break;
    case 14: return;
    }
}

void THunterGuildSeqOnline_Client::restore_player_state() {
    TShopSequence::restore_player_state();
    counter_camera = (TObject *)set_service_counter_camera(this, 1);
    set_field_20(1);
}

void THunterGuildSeqOffline__sub_80213B18(u8 *shop_sequence) {
    Stack_80213B18 stack;
    stack.sp8 = 332.0f;
    stack.spC = 80.0f;
    ((TShopSequence *)shop_sequence)->create_message_window((s32)(get_window_layout_position(0x2C)), (s32)((saddr) &stack.sp8));
    ((VObj_18_97738d *)(shop_sequence))->m7(1, 1);
    *(s32 *)((s8 *)shop_sequence + 0x30) = 0;
    ((TShopWindowBase *)shop_sequence)->set_field_20(2);
}

void THunterGuildSeqOffline__sub_80213980(Obj_80213980 *self) {
    if (self->m8() == 0) {
        return;
    }
    switch (self->state) {
    case 1:
        return;
    case 0:
        if (is_quest_active() != 0) {
            if (TQuestThread::get_register(quest_mission_manager, 0xFF) != 0) {
                self->m7(0xB, 1);
                if (THunterGuildSeqOffline__quest_result_callbacks[1] != -1) {
                    self->thread = (saddr)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[1]);
                }
                ((TShopWindowBase *)self)->set_field_20(4);
            } else if (TQuestThread::get_register(quest_mission_manager, 0xFD) != 0) {
                self->m7(0x12, 1);
                if (THunterGuildSeqOffline__quest_result_callbacks[0] != -1) {
                    self->thread = (saddr)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[0]);
                }
                ((TShopWindowBase *)self)->set_field_20(5);
            } else {
                self->m7(2, 1);
                ((TShopWindowBase *)self)->set_field_20(6);
            }
        } else if (((TShopWindowBase *)self)->sub_80223A48() != 0 || ((TShopWindowBase *)self)->sub_802239EC() != 0) {
            self->m7(0x15, 1);
            ((TShopWindowBase *)self)->set_field_20(0xB);
        }
        break;
    }
}

void THunterGuildSeqOnline_Client::handle_close() {
    if ((vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC() != 0))) {
        display_guild_message(0xC, 1);
        pad_34 = 0;
        set_field_20(0xC);
    }
}

void THunterGuildSeqOnline_Client::update_close_shop() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) {
            return;
        }
        quest_thread = NULL;
    }
    if ((vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC() != 0))) {
        display_guild_message(0xC, 1);
        pad_34 = 1;
        set_field_20(0xC);
    }
}

void THunterGuildSeqOnline_Client::update_shop_close() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        quest_thread = NULL;
    }
    if ((vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC() != 0))) {
        display_guild_message(0xC, 1);
        pad_34 = 1;
        set_field_20(0xC);
    }
}

}
