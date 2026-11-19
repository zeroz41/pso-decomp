#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/ui/city/THunterGuildSeqOffline_80213788.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/city/TShopSequence.h"
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

struct RecoveredGlobal_80213CCC_lbl_804C9740 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80213CCC_lbl_804C9740_size[sizeof(RecoveredGlobal_80213CCC_lbl_804C9740) == 0x38 ? 1 : -1];


struct VBase_18_80213BE0 { char pad[0x18]; };

struct VObj_80213BE0 : VBase_18_80213BE0 {
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
};

struct Seq_80213BE0 : VObj_80213BE0 {
    u32 pad1c;
    u32 state;
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
s32 get_window_layout_position(s32);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80213CCC_lbl_804C9740 __vt__28THunterGuildSeqOnline_Client;
// Online quest download state, read by TQuestListOnline (THunterGuildSeqOnlineTask.cpp).
u8 TQuestListOnline__dat_download_state[0x3C];
u8 TQuestListOnline__bin_download_state[0x3C];
// Per-player slot flags, set by each class's ctor and cleared by its dtor
// (same pattern as THunterGuildSeqOffline__instance_table).
s32 THunterGuildSeqOnline_Server__instance_table[4];
s32 THunterGuildSeqOnline_Client__instance_table[4];
u8 *TQuestListOnline__quest_list_buffer;
u8 *TQuestListOnline__selected_quest_info;
int TQuestListOnline__bin_download_complete;
int TQuestListOnline__dat_download_complete;
u32 TQuestListOnline__download_window;
u32 TQuestListOnline__quest_info_window;
void *TQuestListOnline__download_barrier_window;
s32 quest_download_active;
s32 quest_download_received_bytes;
s32 quest_download_graph_current_bytes;
void THunterGuildSeqOffline__sub_80213BE0(Seq_80213BE0 *arg0);
int is_quest_active(void);
s32 sub_802239EC__13TShopSequenceFv(void *);
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
extern s32 quest_mission_manager;
void THunterGuildSeqOffline__sub_80213980(Obj_80213980 *self);
s32 set_service_counter_camera(void *, s32);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 restore_player_state__13TShopSequenceFv();

void THunterGuildSeqOffline::update_shop_close() {
    void *object;

    object = *(void **)((s8 *)this + 0x38);
    if (object != NULL) {
        if (((TObject *)object)->all_parents_unqueued_for_destruction() != 1) {
            *(u32 *)((s8 *)this + 0x38) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)this)->vfunc_10() != 0) && ((((TShopWindowBase *)this)->sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
            ((THunterGuildSeqOffline *)this)->display_guild_message(0xC, 1);
            *(s32 *)((s8 *)this + 0x34) = 1;
            ((TShopWindowBase *)this)->set_field_20(0xC);
        }
    }
}

void THunterGuildSeqOffline::update_close_shop() {
    void *p = *(void **)((s8 *)this + 0x38);
    if (p != 0) {
        if (((TObject *)p)->all_parents_unqueued_for_destruction() == 0) {
            *(u32 *)((s8 *)this + 0x38) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)this)->vfunc_10() != 0) && ((((TShopWindowBase *)this)->sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
            ((THunterGuildSeqOffline *)this)->display_guild_message(0xC, 1);
            *(s32 *)((s8 *)this + 0x34) = 1;
            ((TShopWindowBase *)this)->set_field_20(0xC);
        }
    }
}

void THunterGuildSeqOffline::handle_close() {
    if ((((TShopWindowBase *)this)->vfunc_10() != 0) && ((((TShopWindowBase *)this)->sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((THunterGuildSeqOffline *)this)->display_guild_message(0xC, 1);
        *(s32 *)((s8 *)this + 0x34) = 0;
        ((TShopWindowBase *)this)->set_field_20(0xC);
    }
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
            if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFF) != 0) {
                self->m7(0xB, 1);
                if (THunterGuildSeqOffline__quest_result_callbacks[1] != -1) {
                    self->thread = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[1]);
                }
                ((TShopWindowBase *)self)->set_field_20(4);
            } else if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFD) != 0) {
                self->m7(0x12, 1);
                if (THunterGuildSeqOffline__quest_result_callbacks[0] != -1) {
                    self->thread = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[0]);
                }
                ((TShopWindowBase *)self)->set_field_20(5);
            } else {
                self->m7(2, 1);
                ((TShopWindowBase *)self)->set_field_20(6);
            }
        } else if (((TShopWindowBase *)self)->sub_80223A48() != 0 || sub_802239EC__13TShopSequenceFv(self) != 0) {
            self->m7(0x15, 1);
            ((TShopWindowBase *)self)->set_field_20(0xB);
        }
        break;
    }
}

void THunterGuildSeqOffline__sub_80213B18(u8 *shop_sequence) {
    Stack_80213B18 stack;
    stack.sp8 = 332.0f;
    stack.spC = 80.0f;
    ((TShopSequence *)shop_sequence)->create_message_window((s32)(get_window_layout_position(0x2C)), (s32)((s32) &stack.sp8));
    ((VObj_18_97738d *)(shop_sequence))->m7(1, 1);
    *(s32 *)((s8 *)shop_sequence + 0x30) = 0;
    ((TShopWindowBase *)shop_sequence)->set_field_20(2);
}

void THunterGuildSeqOffline::restore_and_init_quest_list() {
    restore_player_state__13TShopSequenceFv();
    *(s32 *)((s8 *)this + 0x2C) = set_service_counter_camera(this, 1);
    ((TShopWindowBase *)this)->set_field_20(1);
}

    extern int evt2_random_enemies_mode;

void THunterGuildSeqOffline__sub_80213BE0(Seq_80213BE0 *shop_sequence) {
    switch (shop_sequence->state) {
    case 0: shop_sequence->m10(); break;
    case 1: THunterGuildSeqOffline__sub_80213B18((u8 *)shop_sequence); break;
    case 2: THunterGuildSeqOffline__sub_80213980((Obj_80213980 *)(shop_sequence)); break;
    case 11: ((THunterGuildSeqOffline *)shop_sequence)->handle_close(); break;
    case 4: ((THunterGuildSeqOffline *)shop_sequence)->update_close_shop(); break;
    case 5: ((THunterGuildSeqOffline *)shop_sequence)->update_shop_close(); break;
    case 6: ((THunterGuildSeqOffline *)shop_sequence)->open_judgment_item_window(); break;
    case 7: ((THunterGuildSeqOffline *)shop_sequence)->handle_confirm_window(); break;
    case 12: shop_sequence->m11(); break;
    case 14: return;
    }
}

void THunterGuildSeqOffline::clear_slots() {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOnline_Client__instance_table[i] = 0;
}

void THunterGuildSeqOffline__sub_80213CA4(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        THunterGuildSeqOnline_Client__instance_table[i] = 0;
    }
}

u8 *__dt__28THunterGuildSeqOnline_ClientFv(u8 *shop_sequence, s16 arg1) {
    u32 temp_r3;
    u32 temp_r3_2;
    if (shop_sequence != NULL) {
        *(s32 **)((s8 *)shop_sequence + 0x18) = &__vt__28THunterGuildSeqOnline_Client.value;
        temp_r3 = *(u32 *)((s8 *)shop_sequence + 0x2C);
        if (temp_r3 != 0U) {
            ((TObject *)temp_r3)->queue_destruction();
            *(u32 *)((s8 *)shop_sequence + 0x2C) = 0U;
        }
        ((TShopSequence *)shop_sequence)->close_message_window();
        temp_r3_2 = *(u32 *)((s8 *)shop_sequence + 0x3C);
        if (temp_r3_2 != 0U) {
            ((TWindowBase *)temp_r3_2)->close();
            *(u32 *)((s8 *)shop_sequence + 0x3C) = 0U;
        }
        THunterGuildSeqOnline_Client__instance_table[sub_8022397C__15TShopWindowBaseFv(shop_sequence)] = 0;
        hunter_guild_seq_online_client_instance = NULL;
        __dt__13TShopSequenceFv((shop_sequence), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(shop_sequence);
        }
    }
    return shop_sequence;
}

THunterGuildSeqOnline_Client::THunterGuildSeqOnline_Client(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = THunterGuildSeqOnline_Client__name;
    state = 0;
    this->player = player;
    pad_2c = 0;
    pad_30 = 0;
    pad_34 = 0;
    pad_3c = 0;
    pad_38 = 0;
    THunterGuildSeqOnline_Client__instance_table[sub_8022397C__15TShopWindowBaseFv(this)] = 1;
    hunter_guild_seq_online_client_instance = this;
}

void reset_random_enemies_mode(void) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); }

}



    extern int evt2_random_enemies_mode;
void set_random_enemies_mode(void) { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 2; TKeyBoardControl__sub_8000F950(); }

// Set by each class's ctor, cleared by its dtor.
THunterGuildSeqOnline_Server *hunter_guild_seq_online_server_instance;
THunterGuildSeqOnline_Client *hunter_guild_seq_online_client_instance;
extern "C" {

void THunterGuildSeqOffline__sub_80213E64(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(6, 1);
        hunter_guild_seq_online_server_instance->set_field_20(0xC);
        hunter_guild_seq_online_server_instance->pad_34 = 2;
    }
}
}


struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32, s32);
    virtual void m6();
    virtual s32 m7(s32, s32);
    virtual s32 m8();
};
extern "C" {


void THunterGuildSeqOffline__sub_80213EBC(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(0xC, 1);
        hunter_guild_seq_online_server_instance->set_field_20(0xA);
        hunter_guild_seq_online_server_instance->pad_34 = 2;
    }
}
void THunterGuildSeqOffline::reset_quest_list_vm() {
    if (hunter_guild_seq_online_server_instance != NULL) {
        ((VObj_18 *)hunter_guild_seq_online_server_instance)->m5(get_message_text(0x43), 1);
        hunter_guild_seq_online_server_instance->set_field_20(9);
        hunter_guild_seq_online_server_instance->pad_34 = 0;
    }
}

}


extern "C" {


void THunterGuildSeqOffline__sub_80213F78(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(0xC, 1);
        hunter_guild_seq_online_server_instance->set_field_20(9);
        hunter_guild_seq_online_server_instance->pad_34 = 0;
    }
}

}


struct Base_80213FD0 { char pad[0x18]; };
struct VObj_80213FD0 : Base_80213FD0 {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4();
    virtual int m5();
    virtual int m6();
    virtual int m7(int, int);
    virtual int m8();
};

extern "C" {


void TShopWindowBase::confirm_and_close_if_valid() {
    VObj_80213FD0 *o = (VObj_80213FD0 *)this;
    if (o->m8() != 0 && (sub_80223A48() != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m7(0xc, 1);
        this->set_field_20(0xc);
    }
}

}


struct VBase_18_80214058 { char pad[0x18]; };

struct VObj_80214058 : VBase_18_80214058 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
};

struct Seq_80214058 : VObj_80214058 {
    u8 pad1c[8];
    s32 f24;
};

struct List_80214058 { u8 pad[0x28]; void *f28; void *f2c; void *f30; void *f34; };

extern "C" {

void fn_80214058(Seq_80214058 *arg0);
void fn_80214058(Seq_80214058 *arg0) {
    List_80214058 *l;
    void *e;
    l = (List_80214058 *)TObject::operator new(0x70);
    if (l != 0) {
        l = (List_80214058 *)TQuestListOnline__ct((TQuestListOnline *)l, (void *)((void *)tl_05), (void *)arg0, (void *)((void *)arg0->f24));
    }
    if (l != 0) {
        arg0->m7(4, 1);
        l->f28 = (void *)THunterGuildSeqOffline__sub_80213F78;
        l->f2c = (void *)THunterGuildSeqOffline__sub_80213EBC;
        l->f30 = (void *)THunterGuildSeqOffline__sub_80213E64;
        l->f34 = (void *)THunterGuildSeqOffline::reset_quest_list_vm;
        ((TShopWindowBase *)arg0)->set_field_20(0xE);
    }
}

}


struct Base_80214104 { char pad[0x18]; };

struct Seq_80214104 : Base_80214104 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
    u8 pad1c[8];
    void *player;
    u8 pad28[0xC];
    s32 mode;
    u8 pad38[4];
    void *child;
};

extern "C" {
void *get_entity_id(void *);
int is_quest_active(void);
void close_window__13TShopSequenceFv(void *);
s32 sub_802239EC__13TShopSequenceFv(void *);
extern s32 TLobby__protocol_instance;

void TLobby::handle_random_enemies_choice() {
    void *mem;
    if (((Seq_80214104 *)this)->child != NULL) {
        if (((TObject *)(((Seq_80214104 *)this)->child))->all_parents_unqueued_for_destruction() != 0) return;
        ((Seq_80214104 *)this)->child = NULL;
    }
    if (((Seq_80214104 *)this)->m8() == 0) return;
    switch (((Seq_80214104 *)this)->mode) {
    case 0:
        if (((TShopWindowBase *)((Seq_80214104 *)this))->sub_80223A48() == 0 && sub_802239EC__13TShopSequenceFv(((Seq_80214104 *)this)) == 0) return;
        if (is_quest_active() == 0) {
            ((TProtocol *)TLobby__protocol_instance)->send_quest_menu_closed();
        }
        close_window__13TShopSequenceFv(((Seq_80214104 *)this));
        ((TObject *)((Seq_80214104 *)this))->queue_destruction();
        break;
    case 1:
        mem = TObject::operator new(0x28);
        if (mem != NULL) ((THunterGuildSeqOffline *)mem)->init((void *)tl_00, (void *)reset_random_enemies_mode);
        THunterGuildSeqOffline__sub_8021E180((s32)(get_entity_id(((Seq_80214104 *)this)->player)));
        close_window__13TShopSequenceFv(((Seq_80214104 *)this));
        ((TObject *)((Seq_80214104 *)this))->queue_destruction();
        break;
    case 2:
        mem = TObject::operator new(0x28);
        if (mem != NULL) ((THunterGuildSeqOffline *)mem)->init((void *)tl_00, (void *)set_random_enemies_mode);
        THunterGuildSeqOffline__sub_8021E180((s32)(get_entity_id(((Seq_80214104 *)this)->player)));
        close_window__13TShopSequenceFv(((Seq_80214104 *)this));
        ((TObject *)((Seq_80214104 *)this))->queue_destruction();
        break;
    }
}

}


extern "C" {
void fn_80214254(u8 *shop_window_base) {
    s32 selected_menu_value;
    u8 *window_menu;
    u8 *window_sub_com_card;
    window_menu = (u8 *)(*(u8 **)((s8 *)shop_window_base + 0x38));
    if ((window_menu != NULL) && (((TWindowMenu *)window_menu)->is_decided() != 0)) {
        selected_menu_value = ((TWindowMenu *)(*(u8 **)((s8 *)shop_window_base + 0x38)))->get_selected_value();
        switch (selected_menu_value) {
        case 0:
            ((TWindowBase *)(*(u8 **)((s8 *)shop_window_base + 0x38)))->close();
            *(u8 **)((s8 *)shop_window_base + 0x38) = NULL;
            ((TShopWindowBase *)(shop_window_base))->display_guild_message(9, 1);
            *(s32 *)((s8 *)shop_window_base + 0x34) = 1;
            if ((s32) THunterGuildSeqOffline__quest_result_callbacks[2] != -1) {
                *(s32 *)((s8 *)shop_window_base + 0x3C) = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[2]);
            }
            ((TShopWindowBase *)shop_window_base)->set_field_20(0xC);
            break;
        case 1:
            ((TWindowBase *)(*(u8 **)((s8 *)shop_window_base + 0x38)))->close();
            *(u8 **)((s8 *)shop_window_base + 0x38) = NULL;
            ((TShopWindowBase *)(shop_window_base))->display_guild_message(0xA, 1);
            *(s32 *)((s8 *)shop_window_base + 0x34) = 0;
            ((TShopWindowBase *)shop_window_base)->set_field_20(0xC);
            break;
        }
    }
    window_sub_com_card = (u8 *)(*(u8 **)((s8 *)shop_window_base + 0x38));
    if ((window_sub_com_card != NULL) && (((TWindowMenu *)window_sub_com_card)->is_cancelled() != 0)) {
        ((TWindowBase *)(*(u8 **)((s8 *)shop_window_base + 0x38)))->close();
        *(u8 **)((s8 *)shop_window_base + 0x38) = NULL;
        ((TShopWindowBase *)(shop_window_base))->display_guild_message(0xA, 1);
        *(s32 *)((s8 *)shop_window_base + 0x34) = 0;
        ((TShopWindowBase *)shop_window_base)->set_field_20(0xC);
    }
}

}


struct Base_802143AC { char pad[0x18]; };
struct VObj_802143AC : Base_802143AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
    virtual s32 m8r();
};


struct Stack_8021488C {
    f32 sp8;
    f32 spC;
};

extern "C" {
int is_quest_active(void);
s32 __ct__12TMemberCheckFP7TObject(int, void *);

s32 get_window_layout_position(s32);
int is_quest_active(void);
s32 sub_802239EC__13TShopSequenceFv(void *);
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
extern s32 quest_mission_manager;
s32 set_service_counter_camera(void *, s32);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 get_window_layout_position(s32);

s32 restore_player_state__13TShopSequenceFv();

void TShopWindowBase::create_judgment_item_window() {
    VObj_802143AC *vobj = (VObj_802143AC *)this;

    if ((vobj->m8r() != 0) && ((((TShopWindowBase *)this)->sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        *(s32 *)((s8 *)this + 0x38) = (s32)create_yes_no_window(get_window_layout_position(0x2B), (u16)get_entity_id((void *)(*(s32 *)((s8 *)this + 0x24))), 0, 0);
        ((TWindowSubComCardList *)(*(s32 *)((s8 *)this + 0x38)))->set_selected_index(1);
        ((TWindowAddition *)(*(s32 *)((s8 *)this + 0x38)))->set_position_xy(((TShopWindowBase *)this)->get_scale(), ((TShopWindowBase *)this)->get_scale());
        vobj->m7(8, 1);
        ((TShopWindowBase *)this)->set_field_20(7);
    }
}

void update__15TShopWindowBaseFPv(void *shop_sequence) {
    u32 v = *(u32 *)((s8 *)shop_sequence + 0x3C);
    if (v != 0U) {
        if (((TObject *)v)->all_parents_unqueued_for_destruction() != 1) {
            *(u32 *)((s8 *)shop_sequence + 0x3C) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)shop_sequence)->vfunc_10() != 0) && ((((TShopWindowBase *)shop_sequence)->sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
            ((TShopWindowBase *)shop_sequence)->display_guild_message(0xC, 1);
            *(s32 *)((s8 *)shop_sequence + 0x34) = 1;
            ((TShopWindowBase *)shop_sequence)->set_field_20(0xC);
        }
    }
}

void TShopWindowBase::update_confirm_input() {
    void *parent = *(void **)((s8 *)this + 0x3C);
    if (parent != NULL) {
        if (((TObject *)parent)->all_parents_unqueued_for_destruction() == 0) {
            *(u32 *)((s8 *)this + 0x3C) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)this)->vfunc_10() != 0) && ((((TShopWindowBase *)this)->sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
            ((TShopWindowBase *)this)->display_guild_message(0xC, 1);
            *(s32 *)((s8 *)this + 0x34) = 1;
            ((TShopWindowBase *)this)->set_field_20(0xC);
        }
    }
}

void THunterGuildSeqOffline__sub_802145F8(u8 *shop_sequence) {
    if (((TShopWindowBase *)(shop_sequence))->vfunc_10() != 0) {
        if (((TShopWindowBase *)shop_sequence)->sub_80223A48() != 0) {
            *(s32 *)((s8 *)shop_sequence + 0x40) = 0;
        }
        if ((s32) *(s32 *)((s8 *)shop_sequence + 0x40) == 0) {
            switch (*(s32 *)((s8 *)shop_sequence + 0x30)) {
            case 3:
                break;
            case 0:
                if (is_quest_active() != 0) {
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 2;
                    return;
                }
                switch (THunterGuildSeqOffline::check_party_gathered()) {
                case 1:
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 2;
                    return;
                case 0:
                    ((TShopSequence *)(shop_sequence))->display_guild_message(0x11, 1);
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 1;
                    return;
                case 2:
                    ((TShopSequence *)(shop_sequence))->display_guild_message(0xD, 1);
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 1;
                    return;
                }
                break;
            case 1:
                if (THunterGuildSeqOffline::check_party_gathered() == 1) {
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 2;
                }
                if (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0) {
                    ((TShopSequence *)(shop_sequence))->display_guild_message(0x10, 1);
                    ((TShopWindowBase *)shop_sequence)->set_field_20(0xD);
                    return;
                }
                break;
            case 2:
                if (is_quest_active() != 0) {
                    if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFF) != 0) {
                        ((TShopSequence *)(shop_sequence))->display_guild_message(0xB, 1);
                        if (THunterGuildSeqOffline__quest_result_callbacks[1] != -1) {
                            *(s32 *)((s8 *)shop_sequence + 0x3C) = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[1]);
                        }
                        ((TShopWindowBase *)shop_sequence)->set_field_20(4);
                        return;
                    }
                    if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFD) != 0) {
                        ((TShopSequence *)(shop_sequence))->display_guild_message(0x12, 1);
                        if (THunterGuildSeqOffline__quest_result_callbacks[0] != -1) {
                            *(s32 *)((s8 *)shop_sequence + 0x3C) = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[0]);
                        }
                        ((TShopWindowBase *)shop_sequence)->set_field_20(5);
                        return;
                    }
                    ((TShopSequence *)(shop_sequence))->display_guild_message(2, 1);
                    ((TShopWindowBase *)shop_sequence)->set_field_20(6);
                    return;
                }
                ((TShopSequence *)(shop_sequence))->display_guild_message(4, 1);
                *(s32 *)((s8 *)shop_sequence + 0x30) = 0;
                ((TShopWindowBase *)shop_sequence)->set_field_20(8);
                break;
            }
        }
    }
}

void THunterGuildSeqOffline::init_window() {
    typedef char sp8_offset[(offsetof(Stack_8021488C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8021488C, spC) == 0x4) ? 1 : -1];
    Stack_8021488C stack;
    u32 temp_r3;
    stack.sp8 = 332.0f;
    stack.spC = 80.0f;
    ((TShopSequence *)((u8 *)this))->create_message_window((s32)((int) (get_window_layout_position(0x2C))), (s32)&stack.sp8);
    if (is_quest_active() == 0) {
        temp_r3 = (u32)TObject::operator new(0x80);
        if (temp_r3 != 0U) {
            __ct__12TMemberCheckFP7TObject(temp_r3, ((u8 *)this));
        }
    }
    ((VObj_18_97738d *)(((u8 *)this)))->m7(1, 1);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = 0;
    ((TShopWindowBase *)((u8 *)this))->set_field_20(3);
}

void restore_shop_and_init_quest_state(void *shop_window_base) {
    restore_player_state__13TShopSequenceFv();
    *(s32 *)((s8 *)shop_window_base + 0x2C) = set_service_counter_camera(shop_window_base, 1);
    ((TShopWindowBase *)shop_window_base)->set_field_20(1);
}

}



struct VBase_18_80214978 { char pad[0x18]; };

struct VObj_80214978 : VBase_18_80214978 {
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
};

struct Seq_80214978 : VObj_80214978 {
    u32 pad1c;
    u32 state;
};

extern "C" {
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
struct RecoveredGlobal_804C97F0 { s32 value; u8 remaining[0x34]; };
extern RecoveredGlobal_804C97F0 __vt__28THunterGuildSeqOnline_Server;

void dispatch_state__22THunterGuildSeqOfflineFPv(Seq_80214978 *arg0);

void dispatch_state__22THunterGuildSeqOfflineFPv(Seq_80214978 *shop_sequence) {
    switch (shop_sequence->state) {
    case 0: shop_sequence->m10(); break;
    case 1: ((THunterGuildSeqOffline *)shop_sequence)->init_window(); break;
    case 3: THunterGuildSeqOffline__sub_802145F8((u8 *)shop_sequence); break;
    case 8: fn_80214058((Seq_80214058 *)shop_sequence); break;
    case 4: ((TShopWindowBase *)shop_sequence)->update_confirm_input(); break;
    case 5: update__15TShopWindowBaseFPv(shop_sequence); break;
    case 6: ((TShopWindowBase *)shop_sequence)->create_judgment_item_window(); break;
    case 7: fn_80214254((u8 *)shop_sequence); break;
    case 9: ((TShopWindowBase *)shop_sequence)->set_field_20((s32)((void *)0xC)); break;
    case 10: ((TShopWindowBase *)shop_sequence)->set_field_20((s32)((void *)0xC)); break;
    case 12: shop_sequence->m11(); break;
    case 13: ((TShopWindowBase *)shop_sequence)->confirm_and_close_if_valid(); break;
    case 14: return;
    }
}

void THunterGuildSeqOffline::clear_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        THunterGuildSeqOnline_Server__instance_table[i] = 0;
    }
}

void THunterGuildSeqOffline::zero_four_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        THunterGuildSeqOnline_Server__instance_table[i] = 0;
    }
}

u8 *__dt__28THunterGuildSeqOnline_ServerFv(u8 *shop_sequence, s16 arg1) {
    u32 temp_r3;
    u32 temp_r3_2;
    if (shop_sequence != NULL) {
        *(s32 **)((s8 *)shop_sequence + 0x18) = &__vt__28THunterGuildSeqOnline_Server.value;
        temp_r3 = *(u32 *)((s8 *)shop_sequence + 0x2C);
        if (temp_r3 != 0U) {
            ((TObject *)temp_r3)->queue_destruction();
            *(u32 *)((s8 *)shop_sequence + 0x2C) = 0U;
        }
        ((TShopSequence *)shop_sequence)->close_message_window();
        temp_r3_2 = *(u32 *)((s8 *)shop_sequence + 0x38);
        if (temp_r3_2 != 0U) {
            ((TWindowBase *)temp_r3_2)->close();
            *(u32 *)((s8 *)shop_sequence + 0x38) = 0U;
        }
        THunterGuildSeqOnline_Server__instance_table[sub_8022397C__15TShopWindowBaseFv(shop_sequence)] = 0;
        hunter_guild_seq_online_server_instance = NULL;
        __dt__13TShopSequenceFv((shop_sequence), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(shop_sequence);
        }
    }
    return shop_sequence;
}
THunterGuildSeqOnline_Server::THunterGuildSeqOnline_Server(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = THunterGuildSeqOnline_Server__name;
    state = 0;
    this->player = player;
    pad_2c = 0;
    pad_34 = 0;
    pad_38 = 0;
    pad_3c = 0;
    pad_40 = 1;
    THunterGuildSeqOnline_Server__instance_table[sub_8022397C__15TShopWindowBaseFv(this)] = 1;
    hunter_guild_seq_online_server_instance = this;
}

}


