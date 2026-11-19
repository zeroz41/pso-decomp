#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/quest/TQuestListOffline.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/quest/TQuestThread.h"


struct Base_80212B88 { char pad[0x18]; };

struct Seq_80212B88 : Base_80212B88 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual s32 m7(s32, s32);
    virtual s32 m8();
    u8 pad1c[8];
    s32 player;
};

struct List_80212B88 {
    u8 pad0[0x28];
    void (*cancelled)(void);
    void (*accepted)(void);
    void (*download)(void);
};

struct Base_802129FC { char pad[0x18]; };

struct Seq_802129FC : Base_802129FC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual s32 m7(s32, s32);
    virtual s32 m8();
    u8 pad1c[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    void *f34;
    s32 f38;
};

extern "C" {
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
extern s32 tl_05;
void get_entity_id(s32);
void THunterGuildSeqOffline__sub_8021E180();
void fn_802233F8(void *);
void close_window__13TShopSequenceFv(void *);
s32 sub_802239EC__13TShopSequenceFv(void *);
extern void *tl_00;
struct Base_80212858_8021282C { char pad[0x18]; };
struct VObj_80212858_8021282C : Base_80212858_8021282C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};

    extern int evt2_random_enemies_mode;
void THunterGuildSeqOffline::set_enemy_mode_0() { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); }

extern struct VObj_80212858_8021282C *THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::request_close() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->m7(6, 1);
        *(s32 *)((s8 *)THunterGuildSeqOffline__active_instance + 0x38) = 2;
        ((TShopWindowBase *)THunterGuildSeqOffline__active_instance)->set_field_20(5);
    }
}

void THunterGuildSeqOffline::handle_cancel_choice() {
    u8 *arg0 = (u8 *)this;
    s32 selected_menu_value;
    u8 *temp_r3;
    temp_r3 = this->choice_menu;
    if (temp_r3 != NULL) {
        if (((TWindowMenu *)temp_r3)->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)this->choice_menu)->get_selected_value();
            if (selected_menu_value == 0) {
                ((TWindowBase *)this->choice_menu)->close();
                this->choice_menu = NULL;
                this->display_guild_message(9, 1);
                *(s32 *)&this->unk_38 = 1;
                if ((s32) *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 8) != -1) {
                    this->m_34 = (s32)TQuestThread::create_in_root(*(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 8));
                }
                ((TShopWindowBase *)arg0)->set_field_20(5);
                return;
            }
            if (selected_menu_value == 1) {
                ((TWindowBase *)this->choice_menu)->close();
                this->choice_menu = NULL;
                this->display_guild_message(0xA, 1);
                *(s32 *)&this->unk_38 = 0;
                ((TShopWindowBase *)arg0)->set_field_20(5);
                return;
            }
            goto block_8;
        }
block_8:
        if (((TWindowMenu *)(this->choice_menu))->is_cancelled() != 0) {
            ((TWindowBase *)this->choice_menu)->close();
            this->choice_menu = NULL;
            this->display_guild_message(0xA, 1);
            *(s32 *)&this->unk_38 = 0;
            ((TShopWindowBase *)arg0)->set_field_20(5);
        }
    }
}

void THunterGuildSeqOffline::close_window() {
    Seq_802129FC *arg0 = (Seq_802129FC *)this;
    void *o;
    if (arg0->f34 != NULL) {
        if (((TObject *)(arg0->f34))->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        arg0->f34 = NULL;
    }
    if (arg0->m8() == 0) {
        return;
    }
    if (((TShopWindowBase *)arg0)->sub_80223A48() == 0 && sub_802239EC__13TShopSequenceFv(arg0) == 0) {
        return;
    }
    switch (arg0->f38) {
    case 0:
        break;
    case 1:
        o = TObject::operator new(0x28);
        if (o != NULL) {
            ((THunterGuildSeqOffline *)o)->init(tl_00, (void *)THunterGuildSeqOffline::set_enemy_mode_0);
        }
        get_entity_id(arg0->f24);
        THunterGuildSeqOffline__sub_8021E180();
        break;
    case 2:
        o = TObject::operator new(0x28);
        if (o != NULL) {
            ((THunterGuildSeqOffline *)o)->init(tl_00, (void *)THunterGuildSeqOffline::set_enemy_mode_1);
        }
        get_entity_id(arg0->f24);
        THunterGuildSeqOffline__sub_8021E180();
        break;
    case 3:
        o = TObject::operator new(0x28);
        if (o != NULL) {
            ((THunterGuildSeqOffline *)o)->init(tl_00, (void *)TQuestListVM::set_enemy_mode_3);
        }
        get_entity_id(arg0->f24);
        THunterGuildSeqOffline__sub_8021E180();
        break;
    case 4:
        o = TObject::operator new(0x28);
        if (o != NULL) {
            ((THunterGuildSeqOffline *)o)->init(tl_00, (void *)THunterGuildSeqOffline::set_enemy_mode_5);
        }
        get_entity_id(arg0->f24);
        THunterGuildSeqOffline__sub_8021E180();
        break;
    }
    close_window__13TShopSequenceFv(arg0);
    fn_802233F8(arg0);
    THunterGuildWarning::queue_destruction();
    ((TObject *)arg0)->queue_destruction();
}

void THunterGuildSeqOffline::open_quest_list() {
    Seq_80212B88 *self = (Seq_80212B88 *)this;
    List_80212B88 *list;
    if (self->m8() == 0) return;
    switch (get_game_play_mode()) {
    case 2:
        list = (List_80212B88 *)TObject::operator new(0x5C);
        if (list != NULL) list = (List_80212B88 *)TQuestListChallenge__ct((u8 *)list, (s32)tl_05, (s32)self, (s32)self->player);
        if (list != NULL) {
            list->accepted = THunterGuildSeqOffline::request_close;
            list->cancelled = THunterGuildSeqOffline::set_state_close2;
            ((TShopWindowBase *)self)->set_field_20(10);
        }
        break;
    case 1:
        list = (List_80212B88 *)TObject::operator new(0x5C);
        if (list != NULL) list = (List_80212B88 *)TQuestListChallenge__ct((u8 *)list, (s32)tl_05, (s32)self, (s32)self->player);
        if (list != NULL) {
            list->accepted = THunterGuildSeqOffline::set_state_4;
            list->cancelled = THunterGuildSeqOffline::set_state_close;
            ((TShopWindowBase *)self)->set_field_20(10);
        }
        break;
    case 0:
    default:
        list = (List_80212B88 *)new TQuestListOffline((TObject *)tl_05, (TShopWindowBase *)self, (TObjBase *)self->player);
        if (list != NULL) {
            list->accepted = THunterGuildSeqOffline::request_close;
            list->cancelled = THunterGuildSeqOffline::set_state_close2;
            list->download = THunterGuildSeqOffline::create_quest_list_vm;
            ((TShopWindowBase *)self)->set_field_20(10);
        }
        break;
    }
}

void THunterGuildSeqOffline::handle_window_input() {
    void *object = *(void * *)&this->m_34;

    if (object != NULL) {
        if (((TObject *)object)->all_parents_unqueued_for_destruction() != 1) {
            this->m_34 = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
            this->display_guild_message(0xC, 1);
            *(s32 *)&this->unk_38 = 1;
            set_field_20(5);
        }
    }
}

}
