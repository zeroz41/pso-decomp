#include "types.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TUnk_804D0618.h"
#include "pso/misc/TUnk_804C8678.h"
#include "pso/quest/AreaDialogueScripts.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/misc/TQuestListVM.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/map/CurrentArea.h"
class TObjItemNameSelect : public TObject {
public:
 void* m_1c;
 void* m_20;
public:
    virtual void render();
    virtual ~TObjItemNameSelect();
};
class TObjItemNameEntry : public TObject {
public:
 void* m_1c;
 void* m_20;
public:
    virtual void render();
    virtual ~TObjItemNameEntry();
};
class TQuestThreadBoard : public TObject {
public:
    u8 _pad1C[0xC];
 void* m_28;
 void* m_2c;

    virtual void render();
    virtual ~TQuestThreadBoard();
    virtual void run_task();
};
class TQuestThread : public TObject {
public:
    virtual void render();
    virtual ~TQuestThread();
    virtual void run_task();
};

struct Self_801F4DFC {
    const char *name;
    u8 pad4[0x18 - 0x4];
    void *vtable;
    void *m_1c;
    void *m_20;
};

struct Entry_801F4DFC {
    s32 id;
    s32 f4;
};

struct Pos_801F4DFC {
    f32 x;
    f32 y;
};

struct RecoveredGlobal_801F4F20_lbl_80512B18 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_801F4F20_lbl_80512B18_size[sizeof(RecoveredGlobal_801F4F20_lbl_80512B18) == 0x10 ? 1 : -1];

struct RecoveredGlobal_801F5630___vt__17TQuestThreadBoard {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_801F5630___vt__17TQuestThreadBoard_size[sizeof(RecoveredGlobal_801F5630___vt__17TQuestThreadBoard) == 0x18 ? 1 : -1];

struct ByteBlock_20 { u8 bytes[0x20]; };

struct ByteBlock_100 { u8 bytes[0x100]; };

struct Node_801F57B4 {
    u8 pad0[0xC];
    Node_801F57B4* next;
    u8 pad1[4];
    Node_801F57B4* child;
};

struct RecoveredGlobal_801F5B5C_TQuestThread__data_80512AD0 { s32 value; u8 remaining[0x44]; };

typedef char RecoveredGlobal_801F5B5C_TQuestThread__data_80512AD0_size[sizeof(RecoveredGlobal_801F5B5C_TQuestThread__data_80512AD0) == 0x48 ? 1 : -1];

struct RecoveredGlobal_801F5E7C_lbl_805129F8 {
    s32 value;
    u8 remaining[0xD4];
};

struct RecoveredGlobal_801F5CB0___vt__12TQuestThread {
    s32 value;
    u8 remaining[0x14];
};

struct Inner_801F5E58 { u8 pad[0x14]; char name[1]; };

struct Obj_801F5E58 { u8 pad[0x198]; Inner_801F5E58 *inner; };

typedef char RecoveredGlobal_801F5CB0___vt__12TQuestThread_size[sizeof(RecoveredGlobal_801F5CB0___vt__12TQuestThread) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_801F5E7C_lbl_805129F8_size[sizeof(RecoveredGlobal_801F5E7C_lbl_805129F8) == 0xD8 ? 1 : -1];

struct QThread_801F6418 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1[0x198 - 0x1C];
    s32 f198;
    u8 pad2[4];
    s32 f1A0;
};

struct TObj_801F62E0;

struct Board_801F526C {
    u8 pad0[0x10];
    void *thread;
    u8 pad14[0x1C - 0x14];
    u8 sub1C[0x24 - 0x1C];
    s32 *ids;
    void *win28;
    void *win2C;
    u8 idx;
    u8 pad31[0x178 - 0x31];
    void *kb178;
    void *card17C;
    void *card180;
    void *win184;
    void *win188;
    u8 pad18C[4];
    s32 state;
};

struct TQuestThread_801F5828 {
    u8 pad0[0x10];
    void *m10;
    u8 pad14[0x1C - 0x14];
    u8 m1C[0x24 - 0x1C];
    s32 *slots;
    u8 pad28[0x2C - 0x28];
    void *comCard;
    u8 slot;
    u8 pad31[0x178 - 0x31];
    void *kbd;
    void *com;
    void *board;
    void *list;
    void *help;
    u32 pad18C;
    u32 state;
};
extern "C" {

s32 memcpy(s32, s32, s32);
int memset(void*, void*, void*);
s32 get_main_phase();
s32 get_current_floor(void);
int queue_destruction__7TObjectFv(void*);
s32 check_value_equals__13TUnk_804B6C24Fl(void*, s32);
void * TQuestVmDownLoadServer__sub_8006EF6C(s32);
void copy_name(s32 arg0);
void read_disc_file(void *, s32);
s32 get_text_collection(s32 arg0);
void fn_80131ADC(u8 *arg0, u8 *arg1);
void fn_80131B18(u8 *arg0, u8 *arg1);
u32 TKeyBoardControl__ct(void *, void *, s32, s32, s32, s32);
void mem_free(void *p);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 check_flag_100__10TObjPlayerFPv(void *);
void * get_player_by_client_id(s32);
s32 init_quest_script_context(s32, void *);
s32 bswap_header__6TLobbyFPv();
s32 tick_com_card__12TQuestThreadFv(void *);
s32 update_board_card__12TQuestThreadFv(void *);
s32 update_com_card__12TQuestThreadFv(void *);
void fn_801F4F20(s32 arg0);
void * create__17TObjItemNameEntryFPv(void *arg0);
void * TObjItemNameEntry__ct(void *arg0);
s32 create_instance__17TQuestThreadBoardFi(s32 arg0);
u8 * TQuestThreadBoard__ct(u8 *arg0, s32 arg1, s32 arg2);
void destroy_children_with_tag(Node_801F57B4* arg0);
u8 * create_floor_quest_thread(void);
u32 create__12TQuestThreadFi(s32 arg0);
u8 * create_quest_thread(s32 arg0);
u8 * __ct__12TQuestThreadFv(u8 *arg0, s32 arg1, s32 arg2);
void TQuestThread__sub_801F5D88(void* p);
void clear_all_floor_handlers(void* _w0);
void clear_buffer__12TQuestThreadFPv(void* p);
char * get_quest_name__12TQuestThreadFv(void);
void clear_thread_state__12TQuestThreadFv(void);
s32 get_register__12TQuestThreadFPvi(u8 *arg0, s32 arg1);
void * __dt__13TUnk_804C8678Fv(void *arg0, s16 arg1);
void destroy_quest_obj__12TQuestThreadFv(void);
s32 create_by_mode__12TQuestThreadFv(void);
u8 * init_from_script__12TQuestThreadFPviii(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
QThread_801F6418 * construct_load_quest__12TQuestThreadFPvPvPv(QThread_801F6418 *self, void *unused, void *scene);
void set_status_flag_80__12TQuestThreadFPv(void* p);
void set_item_name_selection_index(int a0);
int queue_destruction__12TQuestThreadFPv(void* p);
void free_menu_object(void* p);
void fn_801F6520(void* p);
int TQuestListVM__sub_801F6530(void);
int TQuestListOnline__sub_801F6540(void);
s32 *TQuestThread__sub_801F6548(void);
s32 __dl__7TObjectFPv(void *);
u32 __nw__7TObjectFUl(s32);
s32 __dt__7TObjectFv(void *, s32);
s32 __ct__7TObjectFP7TObject();
void TWindow__close(void*);
void TLobby__sub_8024AC20(s32);
s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 get_window_id__11TWindowCtrlFv(void);
void complete_actor_speech_balloons(s32);
s32 is_actor_speech_balloon_done(s32);
void TWindowHelpItem__set_displayed_item_by_id(void *, s32);
void TWindowSubComCard__sub_80265500(u8 *arg0);
s32 get_selected_menu_value(void *);
s32 align_menu_entry_positions(u32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
void * check_room_seq_4__16TAdChrSelASlotGCFl(void *, s32);
s32 select_cursor_entry__22TWindowSubShortCutListFv(void *);
void send_and_handle__6TLobbyFii(void *, void *, s32);
void * update_window_mode_from_progress__6TLobbyFPv(void *, Pos_801F4DFC *);
char *fn_8026CB5C(void);
void * get_window_layout_position(s32);
s32 strcmp(s32, s32 *);
s32 strncpy(void *, void *, int);
}
void copy_quest_script_context(u8 *arg0, u8 *arg1);
void clear_floor_handler(s32 i);
void set_floor_handler(s32 i, s32 v);
void handle_6x77_sync_quest_register(u8 *arg0);
u8 * load_quest_root_script(u8 *arg0, void *parent, void *arg2, s32 arg3);
extern s32 TQuestThread__data_804C8678[];
extern RecoveredGlobal_801F5B5C_TQuestThread__data_80512AD0 TQuestThread__floor_handler_ids;
extern void *__vt__12TQuestThread[];
extern void *__vt__17TObjItemNameEntry[];
extern void *__vt__17TQuestThreadBoard[];
extern void *__vt__18TObjItemNameSelect[];
extern s32 enable_v2_features;
extern s32 evt2_random_enemies_mode;
extern char lbl_8044A5D0[];
extern u8 lbl_8044A640[];
extern Entry_801F4DFC lbl_804C8410[];
extern Entry_801F4DFC lbl_804C8488[];
extern u8 controller_input_state[];
extern RecoveredGlobal_801F5E7C_lbl_805129F8 quest_board_handlers;
extern RecoveredGlobal_801F4F20_lbl_80512B18 lbl_80512B18;
extern s32 TQuestThread__class_name;
extern s32 TQuestThreadBoard__class_name;
extern s32 TObjItemNameEntry__class_name;
extern const char *TObjItemNameSelect__class_name;
extern s32 local_client_id;
extern s32 game_difficulty_selection;
extern u32 quest_mission_manager;
extern u32 quest_area_manager;
extern s32 quest_thread_board;
extern int item_name_selection_index;
extern Entry_801F4DFC *item_name_selection_table;
extern const f32 lbl_805DC4EC;
extern const f32 lbl_805DC4F0;
extern const f32 lbl_805DC4F4;
extern const f32 lbl_805DC4F8;
extern s32 lbl_805DC4FC;
extern const f32 lbl_805DC500;
extern const f32 lbl_805DC504;
extern const f32 lbl_805DC508;
extern u8 lbl_805DC50C;
extern s32 tl_00;
extern s32 tl_04;
extern s32 tl_su;
TObjItemNameSelect::~TObjItemNameSelect() {
    if (m_20 != nullptr) { TWindow__close(m_20); m_20 = nullptr; }
    if (m_1c != nullptr) { TWindow__close(m_1c); m_1c = nullptr; }
}

extern "C" {
Self_801F4DFC *TObjItemNameSelect__ct(Self_801F4DFC *self, void *parent) {
    Pos_801F4DFC pos;
    s32 i;

    ((void (*)(Self_801F4DFC *, void *))__ct__7TObjectFP7TObject)(self, parent);
    self->vtable = __vt__18TObjItemNameSelect;
    self->name = TObjItemNameSelect__class_name;
    item_name_selection_table = TLobby::get_instance() == 0 ? lbl_804C8410 : lbl_804C8488;
    self->m_1c = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x58), 0x19);
    for (i = 0; item_name_selection_table[i].id != -1; i++) {
        forward_trade_action_default__16TObjCityMainWarpFPviii(self->m_1c, get_text_collection(item_name_selection_table[i].id), 6, i);
    }
    ((TWindowSubComCardList *)(self->m_1c))->set_scroll_target(lbl_805DC500, lbl_805DC504);
    TWindowSubComCard__sub_80265500((u8 *)self->m_1c);
    ((TLobby *)(self->m_1c))->set_field_1c(lbl_805DC508);
    pos.x = lbl_805DC4F4;
    pos.y = lbl_805DC4F8;
    self->m_20 = update_window_mode_from_progress__6TLobbyFPv(get_window_layout_position(0x55), &pos);
    if (self->m_20 != NULL) {
        send_and_handle__6TLobbyFii(self->m_20, TQuestVmDownLoadServer__sub_8006EF6C(0x46), 0x81);
    }
    return self;
}

void fn_801F4F20(s32 arg0) {
    strncpy((void *)&lbl_80512B18.value, (void *)arg0, 8);
    *(s8 *)((s8 *)&lbl_80512B18.value + 8) = 0;
}

s32 TWindowSubComCard::process_keyboard_input() {
    s32 temp_r31;
    u32 temp_field;

    temp_field = *(u32 *)((s8 *)this + 0x1C);
    if ((temp_field != 0U) && (((TWindowSubComCard *)temp_field)->update_keyboard() != 0)) {
        temp_r31 = ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x1C)))->realloc_buffer();
        if (strcmp(temp_r31, &lbl_805DC4FC) == 0) {
            mem_free((void *)temp_r31);
            ((s32 (*)(u32))free_menu_object)(*(u32 *)((s8 *)this + 0x1C));
            return 0;
        }
        if (TWindowSubComCard::contains_profanity((char *)temp_r31) != 0) {
            ((s32 (*)(u32))free_menu_object)(*(u32 *)((s8 *)this + 0x1C));
            mem_free((void *)temp_r31);
            return 0;
        }
        ((s32 (*)(s32))fn_801F4F20)(temp_r31);
        mem_free((void *)temp_r31);
        return 1;
    }
    return 0;
}

void *create__17TObjItemNameEntryFPv(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0x24);
    if (o != NULL) {
        o = ((void * (*)(void *, void *))TObjItemNameEntry__ct)(o, arg0);
    }
    return o;
}

}
TObjItemNameEntry::~TObjItemNameEntry() {
    if (m_20 != nullptr) { TWindow__close(m_20); m_20 = nullptr; }
    if (m_1c != nullptr) { ((void (*)(void*))queue_destruction__7TObjectFv)(m_1c); m_1c = nullptr; }
}

extern "C" {
void *TObjItemNameEntry__ct(void *arg0) {
    u32 var_r0;

    __ct__7TObjectFP7TObject();
    *(void ***)((s8 *)arg0 + 0x18) = __vt__17TObjItemNameEntry;
    *(s32 *)((s8 *)arg0 + 0) = TObjItemNameEntry__class_name;
    if ((var_r0 = __nw__7TObjectFUl(0x2C)) != 0U) {
        var_r0 = TKeyBoardControl__ct((void*)var_r0, arg0, 8, 0, 1, local_client_id);
    }
    *(u32 *)((s8 *)arg0 + 0x1C) = var_r0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x1C) != 0U) {
        ((TWindowMakeTeam *)(*(u32 *)((s8 *)arg0 + 0x1C)))->set_sub_position((u8 *)(((s32 (*)(s32))get_window_layout_position)(0xBF)));
        fn_80131ADC((u8 *)(*(u32 *)((s8 *)arg0 + 0x1C)), (u8 *)(((s32 (*)(s32))get_window_layout_position)(0xC0)));
        fn_80131B18((u8 *)(*(u32 *)((s8 *)arg0 + 0x1C)), (u8 *)(fn_8026CB5C()));
    }
    *(u32 *)((s8 *)arg0 + 0x20) = ((u32 (*)(s32, s32))check_room_seq_4__16TAdChrSelASlotGCFl)(((s32 (*)(s32))get_window_layout_position)(0x56), 1);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x20) != 0U) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)arg0 + 0x20)), (int)(((s32 (*)(s32))TQuestVmDownLoadServer__sub_8006EF6C)(0x47)), 0x81, 0);
    }
    ((TWindowSubComCardList *)(*(u32 *)((s8 *)arg0 + 0x20)))->set_scroll_target(lbl_805DC4EC, lbl_805DC4F0);
    align_menu_entry_positions(*(u32 *)((s8 *)arg0 + 0x20));
    ((s32 (*)(u32))set_status_flag_80__12TQuestThreadFPv)(*(u32 *)((s8 *)arg0 + 0x20));
    return arg0;
}

s32 create_instance__17TQuestThreadBoardFi(s32 arg0) {
    s32 var_r31;

    if ((u32) quest_mission_manager != 0U) {
        var_r31 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x194);
        if (var_r31 != 0) {
            var_r31 = ((s32)TQuestThreadBoard__ct((u8 *)var_r31, (s32)quest_mission_manager, (s32)arg0));
        }
        ((TObject *)var_r31)->set_parent((TObject *)tl_00);
        return var_r31;
    }
    return 0;
}

void run_task__17TQuestThreadBoardFv(Board_801F526C *o) {
    void *thread = o->thread;

    switch (o->state) {
    case 0:
    case 1:
        o->state = ((TLobby *)(o->sub1C))->dispatch_quest();
        break;
    case 2:
        ((void (*)(void *))queue_destruction__7TObjectFv)(o);
        break;
    case 3:
        ((void (*)(void *))queue_destruction__12TQuestThreadFPv)(thread);
        break;
    case 4: {
        void *p = get_player_by_client_id(local_client_id);
        if (p != NULL && check_flag_100__10TObjPlayerFPv(p) == 0 &&
            TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 4) != 0) {
            s32 id = get_window_id__11TWindowCtrlFv();
            if (is_actor_speech_balloon_done(id) == 0) {
                complete_actor_speech_balloons(id);
            } else {
                o->state = 0;
            }
        }
        break;
    }
    case 5:
        if (get_player_by_client_id(local_client_id) != NULL &&
            TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 4) != 0) {
            o->state = 0;
        }
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 8) != 0 ||
            has_player_active_menu__11TWindowCtrlFv(local_client_id) == 0) {
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
            TLobby::close_windows();
            ((void (*)(void *))queue_destruction__7TObjectFv)(o);
        }
        break;
    case 6:
        break;
    case 7:
        if (((TWindowMenu *)(o->win2C))->is_visible() != 0) {
            o->ids[o->idx] = get_selected_menu_value(o->win2C);
            TWindow__close(o->win2C);
            o->win2C = NULL;
            o->state = 0;
            TLobby__sub_8024AC20(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
        }
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 8) != 0 ||
            has_player_active_menu__11TWindowCtrlFv(local_client_id) == 0) {
            if (o->win28 != NULL) {
                TWindow__close(o->win28);
                o->win28 = NULL;
            }
            if (o->win2C != NULL) {
                TWindow__close(o->win2C);
                o->win2C = NULL;
            }
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
            TLobby::close_windows();
            ((void (*)(void *))queue_destruction__7TObjectFv)(o);
        }
        break;
    case 8:
        if (TLobby::get_quest_thread_state() == 0) {
            o->state = 0;
        }
        break;
    case 9:
        if (((TWindowSubComCard *)(o->kb178))->process_keyboard_input() != 0) {
            ((void (*)(void *))queue_destruction__7TObjectFv)(o->kb178);
            o->kb178 = NULL;
            o->state = 0;
        }
        break;
    case 10: {
        s32 r = update_com_card__12TQuestThreadFv(o->card17C);
        if (r >= 0) {
            ((void (*)(s32))set_item_name_selection_index)(r);
            ((void (*)(void *))queue_destruction__7TObjectFv)(o->card17C);
            o->card17C = NULL;
            o->state = 0;
        }
        break;
    }
    case 11:
        if (update_board_card__12TQuestThreadFv(o->card180) != 0) {
            o->ids[o->idx] = tick_com_card__12TQuestThreadFv(o->card180);
            ((void (*)(void *))queue_destruction__7TObjectFv)(o->card180);
            o->card180 = NULL;
            o->state = 0;
        }
        break;
    case 12: {
        s32 v = select_cursor_entry__22TWindowSubShortCutListFv(o->win184);
        if (v != o->ids[o->idx]) {
            o->ids[o->idx] = v;
            TWindowHelpItem__set_displayed_item_by_id(o->win188, v);
        }
        if (((TUnk_804D0618 *)(o->win184))->get_status_flag() != 0) {
            TWindow__close(o->win184);
            o->win184 = NULL;
            TWindow__close(o->win188);
            o->win188 = NULL;
            o->state = 0;
            TLobby__sub_8024AC20(local_client_id);
            TWindowCtrl::clear_flag_bit2();
        }
        break;
    }
    }
}
}

TQuestThreadBoard::~TQuestThreadBoard() {
    if (m_28 != nullptr) {
        TWindow__close(m_28);
        m_28 = nullptr;
    }
    if (m_2c != nullptr) {
        TWindow__close(m_2c);
        m_2c = nullptr;
    }
    TLobby::close_windows();
    quest_thread_board = 0;
}

u8 *TQuestThreadBoard__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((s32 (*)(void *, int))__ct__7TObjectFP7TObject)(arg0, 0);
    *(void ***)((s8 *)arg0 + 0x18) = __vt__17TQuestThreadBoard;
    *(s32 *)((s8 *)arg0 + 0) = TQuestThreadBoard__class_name;
    ((s32 (*)(void *, void *))copy_quest_script_context)((void *)(arg0 + 0x1C), (void *)(arg1 + 0x24));
    *(s32 *)((s8 *)arg0 + 0x3C) = *(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0x20) + (arg2 * 4)) + 0);
    *(s32 *)((s8 *)arg0 + 0x190) = 0;
    (*(u8 * *)&quest_thread_board) = arg0;
    return arg0;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void copy_quest_script_context(u8 *arg0, u8 *arg1) {
    s32 var_r5;
    s32 var_r7;
    u8 *var_r6;
    var_r5 = *(s32 *)((s8 *)arg1 + 0);
    var_r6 = (u8 *)arg1 + 0x30;
    var_r7 = (long) ((u8 *)arg0 + 0x30);
    *(s32 *)((s8 *)arg0 + 0) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)arg0 + 4) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 8);
    *(s32 *)((s8 *)arg0 + 8) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0xC);
    *(s32 *)((s8 *)arg0 + 0xC) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x10) = var_r5;
    var_r5 = (s32) *(u8 *)((s8 *)arg1 + 0x14);
    *(s8 *)((s8 *)arg0 + 0x14) = (s8) var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x18) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x1C) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x20);
    *(s32 *)((s8 *)arg0 + 0x20) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x24);
    *(s32 *)((s8 *)arg0 + 0x24) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x28);
    *(s32 *)((s8 *)arg0 + 0x28) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x2C);
    *(s32 *)((s8 *)arg0 + 0x2C) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 0x30);
    *(s32 *)((s8 *)arg0 + 0x30) = var_r5;
    *(ByteBlock_20 *)(var_r7 + 4) = *(const ByteBlock_20 *)((s32) var_r6 + 4);
    var_r7 += 0x20;
    var_r6 += 0x20;
    var_r7 = (s32) ((u8 *)arg0 + 0x50);
    var_r6 = (u8 *)arg1 + 0x50;
    *(ByteBlock_100 *)(var_r7 + 4) = *(const ByteBlock_100 *)((s32) var_r6 + 4);
    var_r7 += 0x100;
    var_r6 += 0x100;
    *(u8 *)((s8 *)arg0 + 0x154) = (u8) *(u8 *)((s8 *)arg1 + 0x154);
    *(u8 *)((s8 *)arg0 + 0x155) = (u8) *(u8 *)((s8 *)arg1 + 0x155);
    *(u16 *)((s8 *)arg0 + 0x156) = (u16) *(u16 *)((s8 *)arg1 + 0x156);
    *(u16 *)((s8 *)arg0 + 0x158) = (u16) *(u16 *)((s8 *)arg1 + 0x158);
    *(s32 *)((s8 *)arg0 + 0x15C) = (s32) *(s32 *)((s8 *)arg1 + 0x15C);
    *(s32 *)((s8 *)arg0 + 0x160) = (s32) *(s32 *)((s8 *)arg1 + 0x160);
    *(s32 *)((s8 *)arg0 + 0x164) = (s32) *(s32 *)((s8 *)arg1 + 0x164);
    *(s32 *)((s8 *)arg0 + 0x168) = (s32) *(s32 *)((s8 *)arg1 + 0x168);
    *(s32 *)((s8 *)arg0 + 0x16C) = (s32) *(s32 *)((s8 *)arg1 + 0x16C);
    *(u16 *)((s8 *)arg0 + 0x170) = (u16) *(u16 *)((s8 *)arg1 + 0x170);
    *(u16 *)((s8 *)arg0 + 0x172) = (u16) *(u16 *)((s8 *)arg1 + 0x172);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
void destroy_children_with_tag(Node_801F57B4* arg0) {
    Node_801F57B4* n = arg0->child;
    while (arg0->child != 0 && n != 0) {
        Node_801F57B4* cur = n;
        n = n->next;
        if (check_value_equals__13TUnk_804B6C24Fl(cur, TQuestThread__class_name) != 0) {
            ((void (*)(void*))queue_destruction__7TObjectFv)(cur);
        } else {
            destroy_children_with_tag(cur);
        }
    }
}
#pragma pop

void run_task__12TQuestThreadFv(TQuestThread_801F5828 *t) {
    void *p = t->m10;
    switch (t->state) {
    case 0:
    case 1:
        t->state = ((TLobby *)(t->m1C))->dispatch_quest();
        break;
    case 2:
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(t);
        break;
    case 3:
        ((void (*)(void *))queue_destruction__12TQuestThreadFPv)(p);
        break;
    case 4:
        if (((u32 (*)(void *))get_player_by_client_id)((*(void * *)&local_client_id)) != 0 && ((s32 (*)(void))check_flag_100__10TObjPlayerFPv)() == 0 &&
            ((s32 (*)(void *, int))TWindowShortListCtrl__check_controller_button)(controller_input_state + 0x20, 4) != 0) {
            s32 id = get_window_id__11TWindowCtrlFv();
            if (((s32 (*)(void))is_actor_speech_balloon_done)() == 0) {
                complete_actor_speech_balloons(id);
            } else {
                t->state = 0;
            }
        }
        break;
    case 5:
        if (((u32 (*)(void *))get_player_by_client_id)((*(void * *)&local_client_id)) != 0) {
            void *pad = controller_input_state + 0x20;
            if (((s32 (*)(void *, int))TWindowShortListCtrl__check_controller_button)(pad, 4) != 0) {
                t->state = 0;
            }
            if (((s32 (*)(void *, int))TWindowShortListCtrl__check_controller_button)(pad, 8) != 0) {
                TLobby::close_windows();
                ((s32 (*)(void *))queue_destruction__7TObjectFv)(t);
            }
        }
        break;
    case 7:
        if (((TWindowMenu *)(t->comCard))->is_visible() != 0) {
            t->slots[t->slot] = get_selected_menu_value(t->comCard);
            TWindow__close(t->comCard);
            t->comCard = 0;
            t->state = 0;
            ((void (*)(void *))TLobby__sub_8024AC20)((*(void * *)&local_client_id));
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
        }
        break;
    case 8:
        if (TLobby::get_quest_thread_state() == 0) {
            t->state = 0;
        }
        break;
    case 9:
        if (((TWindowSubComCard *)(t->kbd))->process_keyboard_input() != 0) {
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(t->kbd);
            t->kbd = 0;
            t->state = 0;
        }
        break;
    case 10:
        if (update_com_card__12TQuestThreadFv(t->com) >= 0) {
            ((void (*)(void))set_item_name_selection_index)();
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(t->com);
            t->com = 0;
            t->state = 0;
        }
        break;
    case 11:
        if (update_board_card__12TQuestThreadFv(t->board) != 0) {
            t->slots[t->slot] = tick_com_card__12TQuestThreadFv(t->board);
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(t->board);
            t->board = 0;
            t->state = 0;
        }
        break;
    case 12: {
        s32 sel = select_cursor_entry__22TWindowSubShortCutListFv(t->list);
        if (sel != t->slots[t->slot]) {
            t->slots[t->slot] = sel;
            TWindowHelpItem__set_displayed_item_by_id(t->help, sel);
        }
        if (((TUnk_804D0618 *)(t->list))->get_status_flag() != 0 || ((TLobby *)(t->list))->get_flag_bit2() != 0) {
            if (((TLobby *)(t->list))->get_flag_bit2() != 0) {
                t->slots[t->slot] = -1;
            }
            TWindow__close(t->list);
            t->list = 0;
            TWindow__close(t->help);
            t->help = 0;
            t->state = 0;
            ((void (*)(void *))TLobby__sub_8024AC20)((*(void * *)&local_client_id));
            TWindowCtrl::clear_flag_bit2();
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
        }
        break;
    }
    }
}

TQuestThread::~TQuestThread() {}

u8 *create_floor_quest_thread(void) {
    s32 temp_r30;
    u8 *quest_thread;
    u8 *var_r0;
    temp_r30 = get_current_floor() * 4;
    if (((s32) *(s32 *)((s8 *)&TQuestThread__floor_handler_ids.value + temp_r30) != -1) && ((u32) quest_mission_manager != 0U)) {
        quest_thread = (u8 *)(((u8 *)__nw__7TObjectFUl(0x194)));
        var_r0 = quest_thread;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((u32)__ct__12TQuestThreadFv((u8 *)quest_thread, (s32)((u32)((s32) quest_mission_manager)), (s32)((s32)(*(s32 *)((s8 *)&TQuestThread__floor_handler_ids.value + temp_r30)))))));
        }
        return var_r0;
    }
    return NULL;
}

u32 create__12TQuestThreadFi(s32 arg0) {
    u32 var_r31;

    if ((u32) quest_mission_manager != 0U) {
        var_r31 = __nw__7TObjectFUl(0x194);
        if (var_r31 != 0U) {
            var_r31 = ((u32)__ct__12TQuestThreadFv((u8 *)var_r31, (s32)quest_mission_manager, (s32)arg0));
        }
        if (var_r31 != 0U) {
            ((TObject *)var_r31)->set_parent((TObject *)tl_00);
            return var_r31;
        }
        return 0U;
    }
    return 0U;
}

u8 *create_quest_thread(s32 arg0) {
    u8 *quest_thread;
    u8 *var_r0;
    if ((u32) quest_mission_manager != 0U) {
        quest_thread = (u8 *)(((u8 *)__nw__7TObjectFUl(0x194)));
        var_r0 = quest_thread;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((u32)__ct__12TQuestThreadFv(quest_thread, (s32)((u32)((s32) quest_mission_manager)), arg0))));
        }
        return var_r0;
    }
    return NULL;
}

u8 *__ct__12TQuestThreadFv(u8 *arg0, s32 arg1, s32 arg2) {
    ((s32 (*)(void *, void *))__ct__7TObjectFP7TObject)((void *)arg0, (void *)arg1);
    *(void ***)((s8 *)arg0 + 0x18) = __vt__12TQuestThread;
    *(s32 *)((s8 *)arg0 + 0) = TQuestThread__class_name;
    ((s32 (*)(void *, void *))copy_quest_script_context)((void *)(arg0 + 0x1C), (void *)(arg1 + 0x24));
    *(s32 *)((s8 *)arg0 + 0x3C) = *(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0x20) + (arg2 * 4)) + 0);
    *(s32 *)((s8 *)arg0 + 0x190) = 0;
    if (*(s32 *)((s8 *)arg0 + 0x3C) == -1) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(arg0);
    }
    return arg0;
}
}

void clear_floor_handler(s32 i) {
    if (i < 0 || i > 0x11) {
        return;
    }
    ((s32 *)&TQuestThread__floor_handler_ids)[i] = -1;
}

void set_floor_handler(s32 i, s32 v) {
    if (i < 0 || i > 0x11) {
        return;
    }
    ((s32 *)&TQuestThread__floor_handler_ids)[i] = v;
}

void TQuestThread__sub_801F5D88(void* p) { clear_all_floor_handlers(p); }

void clear_all_floor_handlers(void* _w0) {
    s32 i;
    for (i = 0; i < 0x12; i++) {
        ((s32 *)&TQuestThread__floor_handler_ids)[i] = -1;
    }
}

void clear_buffer__12TQuestThreadFPv(void* p) { if (*(unsigned int*)((char*)p + 0x2c) != 0) { memset(*(void**)((char*)p + 0x2c), (void*)0, (void*)1024); } }

void handle_6x77_sync_quest_register(u8 *arg0) {
    s32 var_r4;
    u16 temp_r0;
    u8 *var_r31;
    u8 *var_r3;
    var_r31 = arg0;
    bswap_header__6TLobbyFPv();
    var_r3 = (u8 *)((*(u8 * *)&quest_mission_manager));
    if (var_r3 != NULL) {
        temp_r0 = *(u16 *)((s8 *)var_r31 + 4);
        var_r4 = *(s32 *)((s8 *)var_r3 + 0x2C);
        if (temp_r0 <= 0xFFU) {
            var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 8));
            *(s32 *)((s8 *)var_r4 + ((temp_r0 * 4) & 0x3FFFC)) = (long) (var_r3);
        }
    }
}

char *get_quest_name__12TQuestThreadFv(void) {
    if ((*(Obj_801F5E58 * *)&quest_mission_manager) != 0) {
        return (*(Obj_801F5E58 * *)&quest_mission_manager)->inner->name;
    }
    return lbl_8044A5D0;
}

void clear_thread_state__12TQuestThreadFv(void) {
    memset(&quest_board_handlers.value, (void*)(0), (void*)(0xD8));
}

s32 get_register__12TQuestThreadFPvi(u8 *arg0, s32 arg1) {
    if (arg0 != NULL) {
        return *(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0x2C)) + (arg1 * 4));
    }
    return 0;
}

void TUnk_804C8678::run_task() {  }

void *__dt__13TUnk_804C8678Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = TQuestThread__data_804C8678;
        if ((s32) *(s32 *)((s8 *)arg0 + 0x1A0) == 0) {
            (*(s32 *)&quest_mission_manager) = 0;
            ((s32 (*)(void))clear_thread_state__12TQuestThreadFv)();
        } else {
            (*(s32 *)&quest_area_manager) = 0;
        }
        TAdSinglePlyChrSelectGC::safe_free(*(s32 *)((s8 *)arg0 + 0x198));
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void destroy_quest_obj__12TQuestThreadFv(void) {
    if ((u32) quest_area_manager != 0U) {
        queue_destruction__7TObjectFv((void*)((void*)quest_area_manager));
        quest_area_manager = 0U;
    }
}

void load_area_dialogue_script(void) {
    s32 bank;
    void *mem;

    switch (get_current_area()) {
    case 0: if (get_main_phase() == 14) { bank = 0; } else { bank = 1; } break;
    case 1: case 2: bank = 2; break;
    case 3: case 4: case 5: bank = 3; break;
    case 6: case 7: case 13: bank = 4; break;
    case 8: case 9: case 10: bank = 5; break;
    case 18: if (get_main_phase() == 14) { bank = 6; } else { bank = 7; } break;
    case 19: case 20: case 32: bank = 8; break;
    case 21: case 22: case 33: bank = 9; break;
    case 23: case 24: case 25: case 26: case 27: case 30: bank = 10; break;
    case 28: case 29: case 31: bank = 11; break;
    default: return;
    }
    if (enable_v2_features == 1 && game_difficulty_selection == 3) {
        mem = ((void *(*)(s32))__nw__7TObjectFUl)(0x1A4);
        if (mem != NULL) {
            load_quest_root_script((u8 *)mem, (void *)tl_04, (void *)area_dialogue_ultimate_script_files[current_language][bank], 1);
        }
    } else {
        mem = ((void *(*)(s32))__nw__7TObjectFUl)(0x1A4);
        if (mem != NULL) {
            load_quest_root_script((u8 *)mem, (void *)tl_04, (void *)area_dialogue_script_files[current_language][bank], 1);
        }
    }
}

s32 create_by_mode__12TQuestThreadFv(void) {
    s32 temp_r31;
    s32 quest_count;
    s32 object;
    s32 var_r30_2;
    s32 var_r30_3;
    s32 var_r30_4;
    s32 var_r31;
    switch ((s32) evt2_random_enemies_mode) {
    case 1:
        temp_r31 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x1A4);
        if (temp_r31 != 0) {
            temp_r31 = ((s32)construct_load_quest__12TQuestThreadFPvPvPv((QThread_801F6418 *)(temp_r31), (void *)tl_su, (void *)(TQuestThread__sub_801F6548())));
        }
        return temp_r31;
    case 2:
        object = ((s32 (*)(s32))__nw__7TObjectFUl)(0x1A4);
        if (object != 0) {
            temp_r31 = TQuestListOnline::get_quest_count();
            object = (s32)init_from_script__12TQuestThreadFPviii((u8 *)object, (s32)tl_su, (s32)(TQuestListOnline__sub_801F6540()), (s32)temp_r31);
        }
        return object;
    case 3:
        var_r30_2 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x1A4);
        if (var_r30_2 != 0) {
            var_r30_2 = (s32)init_from_script__12TQuestThreadFPviii((u8 *)var_r30_2, (s32)tl_su, (s32)(TQuestListVM::get_instance()), (s32)TQuestListVM__sub_801F6530());
        }
        TQuestListVM::reset();
        return var_r30_2;
    case 4:
        var_r30_3 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x1A4);
        if (var_r30_3 != 0) {
            quest_count = TQuestListOnline::get_quest_count();
            var_r30_3 = (s32)init_from_script__12TQuestThreadFPviii((u8 *)var_r30_3, (s32)tl_su, (s32)(TQuestListOnline__sub_801F6540()), (s32)quest_count);
        }
        return var_r30_3;
    case 5:
        var_r30_4 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x1A4);
        if (var_r30_4 != 0) {
            var_r30_4 = ((s32)construct_load_quest__12TQuestThreadFPvPvPv((QThread_801F6418 *)(var_r30_4), (void *)tl_su, (void *)(TQuestThread__sub_801F6548())));
        }
        return var_r30_4;
    default:
        return 0;
    }
}

#pragma push
#pragma fp_contract on
u8 *init_from_script__12TQuestThreadFPviii(u8 *object, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r31;
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)object + 0x18) = TQuestThread__data_804C8678;
    if (arg3 < 0) {
        queue_destruction__7TObjectFv(object);
    } else {
        temp_r31 = arg3 + 0x400;
        *(s32 *)((s8 *)object + 0x198) = ((TQuestVmDownLoadServer *)temp_r31)->alloc();
        memcpy(*(s32 *)((s8 *)object + 0x198), arg2, temp_r31);
        (*(u8 * *)&quest_mission_manager) = object;
        init_quest_script_context(*(s32 *)((s8 *)object + 0x198), object + 0x24);
        *(s32 *)((s8 *)object + 0x1A0) = 0;
    }
    ((s32 (*)(void))clear_thread_state__12TQuestThreadFv)();
    return object;
}
#pragma pop

u8 *load_quest_root_script(u8 *object, void *parent, void *scene, s32 arg3) {
    s32 size;
    void *mem;
    TObj_801F62E0 *obj;
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(object, parent);
    *(s32 **)((s8 *)object + 0x18) = TQuestThread__data_804C8678;
    *(s32 *)((s8 *)object + 0x1A0) = arg3;
    *(s32 *)((s8 *)object + 0x198) = 0;
    obj = (TObj_801F62E0 *)object;
    switch (*(s32 *)((s8 *)object + 0x1A0)) {
    case 0:
        copy_name((s32)lbl_8044A640);
        size = ((TScene *)scene)->update_lobby_scene();
        if (size < 0) {
            queue_destruction__7TObjectFv(object);
        } else {
            *(s32 *)((s8 *)object + 0x198) = ((TQuestVmDownLoadServer *)(size + 0x400))->alloc();
            read_disc_file(scene, *(s32 *)((s8 *)object + 0x198));
            copy_name((s32)&lbl_805DC50C);
            (*(u8 * *)&quest_mission_manager) = object;
            init_quest_script_context(*(s32 *)((s8 *)object + 0x198), object + 0x24);
            mem = (void *)((s32 (*)(s32))__nw__7TObjectFUl)(0x194);
            if (mem != NULL) {
                ((s32 (*)(void *, void *, s32))__ct__12TQuestThreadFv)(mem, object, 0);
            }
        }
        ((s32 (*)(void))clear_thread_state__12TQuestThreadFv)();
        break;
    case 1:
        size = ((TScene *)scene)->update_lobby_scene();
        if (size < 0) {
            queue_destruction__7TObjectFv(object);
        } else {
            *(s32 *)((s8 *)object + 0x198) = ((TQuestVmDownLoadServer *)(size + 0x400))->alloc();
            read_disc_file(scene, *(s32 *)((s8 *)object + 0x198));
            quest_area_manager = (u32)object;
            init_quest_script_context(*(s32 *)((s8 *)object + 0x198), object + 0x24);
        }
        break;
    default:
        queue_destruction__7TObjectFv(obj);
        break;
    }
    return object;
}
extern "C" {

QThread_801F6418 *construct_load_quest__12TQuestThreadFPvPvPv(QThread_801F6418 *self, void *unused, void *scene) {
    s32 r;
    __ct__7TObjectFP7TObject();
    self->vt = ((u8 *)&TQuestThread__data_804C8678);
    copy_name((s32)lbl_8044A640);
    r = ((TScene *)scene)->update_lobby_scene();
    if (r < 0) {
        queue_destruction__7TObjectFv(self);
    } else {
        self->f198 = ((TQuestVmDownLoadServer *)(r + 0x400))->alloc();
        read_disc_file(scene, self->f198);
        copy_name((s32)&lbl_805DC50C);
        (*(QThread_801F6418 * *)&quest_mission_manager) = self;
        init_quest_script_context(self->f198, (u8 *)self + 0x24);
        self->f1A0 = 0;
    }
    ((s32 (*)(void))clear_thread_state__12TQuestThreadFv)();
    return self;
}

void set_status_flag_80__12TQuestThreadFPv(void* p) { *(u16*)((char*)p + 0x70) |= 0x80; }

void set_item_name_selection_index(int a0) { item_name_selection_index = a0; }

int queue_destruction__12TQuestThreadFPv(void* p) { return queue_destruction__7TObjectFv(p); }

void free_menu_object(void* p) { void* m = *(void**)((char*)p + 0x20); if (m) fn_801F6520(m); }

void fn_801F6520(void* p) { *(u16*)((char*)p + 0x60) &= 0xfffe; }

void __dt__18TObjItemNameSelectFv();
void __dt__17TObjItemNameEntryFv();
void __dt__17TQuestThreadBoardFv();
void __dt__12TQuestThreadFv();
void run_task__7TObjectFv();
void render__7TObjectFv();
void render_shadows__7TObjectFv();
}
void *__vt__18TObjItemNameSelect[] = {
    0,
    0,
    (void *)__dt__18TObjItemNameSelectFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
void *__vt__17TObjItemNameEntry[] = {
    0,
    0,
    (void *)__dt__17TObjItemNameEntryFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
void *__vt__17TQuestThreadBoard[] = {
    0,
    0,
    (void *)__dt__17TQuestThreadBoardFv,
    (void *)run_task__17TQuestThreadBoardFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
void *__vt__12TQuestThread[] = {
    0,
    0,
    (void *)__dt__12TQuestThreadFv,
    (void *)run_task__12TQuestThreadFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
