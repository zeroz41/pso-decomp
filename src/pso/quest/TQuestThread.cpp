#include "pso/system/memory.h"
#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include <string.h>
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/network/TProtocol.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/item/TObjItemNameSelect.h"
#include "pso/item/TObjItemOKWindow.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_801F2D2C.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TUnk_804C8678.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrl_8024B1A0.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/quest/AreaDialogueScripts.h"
#include "pso/quest/QuestVm.h"
#include "pso/quest/QuestScriptFormat.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "stdio.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/item/TItemData_8010EDA8.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/map/FloorArea.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowHelpItem_802540AC.h"
#include "pso/player/PlayerSlots.h"


#pragma readonly_strings on

struct ItemNameEntry { s32 text_id; s32 value; };
struct WindowPos { f32 x; f32 y; };
struct ByteBlock_20 { u8 bytes[0x20]; };
struct ByteBlock_100 { u8 bytes[0x100]; };

extern "C" {
void *get_window_layout_position(s32);
void TQuestThread__sub_801F5D88(void);
void __dt__16TObjItemOKWindowFv();
void __dt__18TObjItemNameSelectFv();
void __dt__17TObjItemNameEntryFv();
void __dt__17TQuestThreadBoardFv();
void run_task__17TQuestThreadBoardFv();
void __dt__12TQuestThreadFv();
void run_task__12TQuestThreadFv();
void run_task__7TObjectFv();
void render__7TObjectFv();
void render_shadows__7TObjectFv();

extern s32 local_client_id;
extern s32 game_difficulty_selection;
extern s32 evt2_random_enemies_mode;
extern int quest_bin_decompressed_size;
extern u8 *online_quest_bin_data;
extern char offline_quest_filename_buffer_a[];
}

extern const char *TQuestThread__class_name;
extern const char *TQuestThreadBoard__class_name;
extern const char *TObjItemNameEntry__class_name;
extern const char *TObjItemNameSelect__class_name;
extern const char *TObjItemOKWindow__class_name;
extern const char TObjItemOKWindow__text_format[];

ItemNameEntry item_name_table_a[] = {
    {0x165, 0x70}, {0x166, 0x71}, {0x167, 0x72}, {0x168, 0x73}, {0x169, 0x74},
    {0x16A, 0x75}, {0x16B, 0x76}, {0x16C, 0x77}, {0x16D, 0x78}, {0x16E, 0x79},
    {0x16F, 0x7A}, {0x170, 0x7B}, {0x171, 0x7C}, {0x172, 0x7D}, {-1, -1},
};

ItemNameEntry item_name_table_b[] = {
    {0x173, 0x7E}, {0x174, 0x7F}, {0x175, 0x80}, {0x176, 0x81}, {0x177, 0x82},
    {0x178, 0x83}, {0x179, 0x84}, {0x17A, 0x85}, {0x17B, 0x86}, {0x17C, 0x87},
    {0x17D, 0x88}, {0x1C7, 0xA5}, {0x1C8, 0xA6}, {0x1C9, 0xA7}, {0x1CA, 0xA8},
    {0x1CB, 0xA9}, {-1, -1},
};

void *__vt__16TObjItemOKWindow[] = {
    0, 0,
    (void *)__dt__16TObjItemOKWindowFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};

TUnk_804C8678 *quest_mission_manager;
TUnk_804C8678 *quest_area_manager;
TQuestThreadBoard *quest_thread_board;
int item_name_selection_index;
ItemNameEntry *item_name_selection_table;
u8 quest_board_handlers[0xD8];
s32 TQuestThread__floor_handler_ids[18];
char entered_item_name[0x10];

void *TObjItemOKWindow::create(void *parent) {
    return new TObjItemOKWindow((TObject *)parent);
}

s32 TObjItemOKWindow::get_result() {
    void *menu = m_60;
    if (menu != NULL) {
        return ((TWindowMenu *)menu)->get_selected_value();
    }
    return -1;
}

s32 TObjItemOKWindow::is_done() {
    void *menu = m_60;
    if (menu != NULL) {
        return ((TWindowMenu *)menu)->is_decided();
    }
    return 0;
}

TObjItemOKWindow::~TObjItemOKWindow() {
    if (m_64 != nullptr) { ((TWindowBase *)m_64)->close(); m_64 = nullptr; }
    if (m_5c != nullptr) { ((TWindowBase *)m_5c)->close(); m_5c = nullptr; }
    if (m_60 != nullptr) { ((TWindowBase *)m_60)->close(); m_60 = nullptr; }
}

TObjItemOKWindow::TObjItemOKWindow(TObject *parent) : TObject(parent) {
    WindowPos pos;
    s32 name;

    m_name = TObjItemOKWindow__class_name;
    m_60 = init_shop_judgment_window(get_window_layout_position(0x57));
    if (m_60 != NULL) {
        ((TWindowSubComCardList *)m_60)->set_scroll_target(104.0f, 74.0f);
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(m_60));
    }
    m_5c = (void *)(saddr)create_window_menu_default((saddr)get_window_layout_position(0x56), 1);
    if (m_5c != NULL) {
        name = (saddr)TObjItemNameSelect::get_selected_name();
        if (name != 0) {
            sprintf(m_text, TObjItemOKWindow__text_format, TObjItemOKWindow__sub_801F3268(), name);
        } else {
            sprintf(m_text, "%s", TObjItemOKWindow__sub_801F3268());
        }
        m_text[0x3F] = 0;
        ((TWindowMenu *)m_5c)->add_text_entry((saddr)m_text, 0x81, 0);
    }
    ((TWindowSubComCardList *)m_5c)->set_scroll_target(442.0f, 64.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(m_5c));
    TQuestThread::set_status_flag_80(m_5c);
    pos.x = 332.0f;
    pos.y = 80.0f;
    m_64 = (void *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0x55), (NJS_POINT2 *)&pos);
    if (m_64 != NULL) {
        ((TWindowMessage *)m_64)->append_line(get_message_text(0x48), 0x81);
    }
}

s32 TObjItemNameSelect::get_selected_value() {
    if (item_name_selection_index >= 0) {
        return item_name_selection_table[item_name_selection_index].value;
    }
    return -1;
}

char *TObjItemNameSelect::get_selected_name() {
    if (item_name_selection_index >= 0) {
        return (char *)get_text_collection(item_name_selection_table[item_name_selection_index].text_id);
    }
    return "";
}

void *TObjItemNameSelect::create(void *parent) {
    return new TObjItemNameSelect((TObject *)parent);
}

s32 TObjItemNameSelect::get_result() {
    if (m_1c != NULL) {
        if (((TWindowMenu *)m_1c)->is_decided() != 0) {
            return ((TWindowMenu *)m_1c)->get_selected_value();
        }
    }
    return -1;
}

TObjItemNameSelect::~TObjItemNameSelect() {
    if (m_20 != nullptr) { ((TWindowBase *)m_20)->close(); m_20 = nullptr; }
    if (m_1c != nullptr) { ((TWindowBase *)m_1c)->close(); m_1c = nullptr; }
}

TObjItemNameSelect::TObjItemNameSelect(TObject *parent) : TObject(parent) {
    WindowPos pos;
    s32 i;

    m_name = TObjItemNameSelect__class_name;
    item_name_selection_table = TLobby::get_instance() == 0 ? item_name_table_a : item_name_table_b;
    m_1c = (void *)(saddr)create_window_menu_default((saddr)get_window_layout_position(0x58), 0x19);
    for (i = 0; item_name_selection_table[i].text_id != -1; i++) {
        ((TWindowMenu *)m_1c)->add_text_entry(get_text_collection(item_name_selection_table[i].text_id), 6, i);
    }
    ((TWindowSubComCardList *)m_1c)->set_scroll_target(216.0f, 144.0f);
    TWindowSubComCard__sub_80265500((TWindowMenu *)m_1c);
    ((TWindowBase *)m_1c)->set_depth(39000.0f);
    pos.x = 332.0f;
    pos.y = 80.0f;
    m_20 = (void *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0x55), (NJS_POINT2 *)&pos);
    if (m_20 != NULL) {
        ((TWindowMessage *)m_20)->append_line(get_message_text(0x46), 0x81);
    }
}

void TObjItemNameEntry::set_entered_name(const char *name) {
    strncpy(entered_item_name, name, 8);
    entered_item_name[8] = 0;
}

s32 TObjItemNameEntry::process_keyboard_input() {
    saddr text;

    if (m_1c != NULL && ((TKeyBoardControl *)m_1c)->is_confirmed() != 0) {
        text = (saddr)((TKeyBoardControl *)m_1c)->realloc_buffer();
        if (strcmp((const char *)text, "") == 0) {
            mem_free((void *)text);
            ((TKeyBoardControl *)m_1c)->clear_keyboard_flag60_bit1();
            return 0;
        }
        if (TWindowSubComCard::contains_profanity((char *)text) != 0) {
            ((TKeyBoardControl *)m_1c)->clear_keyboard_flag60_bit1();
            mem_free((void *)text);
            return 0;
        }
        set_entered_name((const char *)text);
        mem_free((void *)text);
        return 1;
    }
    return 0;
}

void *TObjItemNameEntry::create(void *parent) {
    return new TObjItemNameEntry((TObject *)parent);
}

TObjItemNameEntry::~TObjItemNameEntry() {
    if (m_20 != nullptr) { ((TWindowBase *)m_20)->close(); m_20 = nullptr; }
    if (m_1c != nullptr) { ((TObject *)m_1c)->queue_destruction(); m_1c = nullptr; }
}

TObjItemNameEntry::TObjItemNameEntry(TObject *parent) : TObject(parent) {
    m_name = TObjItemNameEntry__class_name;
    m_1c = new TKeyBoardControl(this, 8, 0, 1, local_client_id);
    if (m_1c != NULL) {
        ((TKeyBoardControl *)m_1c)->set_sub_position((u8 *)get_window_layout_position(0xBF));
        ((TKeyBoardControl *)m_1c)->set_soft_position((u8 *)get_window_layout_position(0xC0));
        ((TKeyBoardControl *)m_1c)->set_hard_position((u8 *)fn_8026CB5C());
    }
    m_20 = (void *)(saddr)create_window_menu_default((saddr)get_window_layout_position(0x56), 1);
    if (m_20 != NULL) {
        ((TWindowMenu *)m_20)->add_text_entry(get_message_text(0x47), 0x81, 0);
    }
    ((TWindowSubComCardList *)m_20)->set_scroll_target(442.0f, 64.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(m_20));
    TQuestThread::set_status_flag_80(m_20);
}

TQuestThreadBoard *TQuestThreadBoard::create_instance(int label) {
    TQuestThreadBoard *board;

    if (quest_mission_manager != NULL) {
        board = new TQuestThreadBoard(quest_mission_manager, label);
        board->set_parent(tl_00);
        return board;
    }
    return NULL;
}

void TQuestThreadBoard::run_task() {
    TObject *parent = m_up;

    switch (state) {
    case QST_RUNNING:
    case QST_SUSPEND_SYNC:
        state = ctx.dispatch();
        break;
    case QST_SUSPEND_RETURN:
        queue_destruction();
        break;
    case QST_SUSPEND_EXIT:
        TQuestThread::queue_destruction(parent);
        break;
    case QST_WAIT_MESSAGE: {
        TObjPlayer *player = get_player_by_client_id(local_client_id);
        if (player != NULL && player->is_controls_locked() == 0 &&
            test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
            u16 id = TWindowCtrl::get_window_id();
            if (is_actor_speech_balloon_done(id) == 0) {
                complete_actor_speech_balloons(id);
            } else {
                state = QST_RUNNING;
            }
        }
        break;
    }
    case QST_WAIT_MESSAGE_QB:
        if (get_player_by_client_id(local_client_id) != NULL &&
            test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
            state = QST_RUNNING;
        }
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 8) != 0 ||
            TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
            TLobby::close_windows();
            queue_destruction();
        }
        break;
    case QST_SUSPEND_6:
        break;
    case QST_WAIT_LIST:
        if (((TWindowMenu *)ctx.list_window)->is_decided() != 0) {
            ctx.registers[ctx.result_register] = ((TWindowMenu *)ctx.list_window)->get_selected_value();
            ((TWindowBase *)ctx.list_window)->close();
            ctx.list_window = NULL;
            state = QST_RUNNING;
            TWindowCtrl::enable_client_main_menu(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
        }
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 8) != 0 ||
            TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
            if (ctx.message_window != NULL) {
                ((TWindowBase *)ctx.message_window)->close();
                ctx.message_window = NULL;
            }
            if (ctx.list_window != NULL) {
                ((TWindowBase *)ctx.list_window)->close();
                ctx.list_window = NULL;
            }
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
            TLobby::close_windows();
            queue_destruction();
        }
        break;
    case QST_WAIT_FADE:
        if (TLobby::get_quest_thread_state() == 0) {
            state = QST_RUNNING;
        }
        break;
    case QST_WAIT_ITEM_NAME_ENTRY:
        if (((TObjItemNameEntry *)ctx.item_name_entry)->process_keyboard_input() != 0) {
            ((TObject *)ctx.item_name_entry)->queue_destruction();
            ctx.item_name_entry = NULL;
            state = QST_RUNNING;
        }
        break;
    case QST_WAIT_ITEM_NAME_SELECT: {
        s32 selection = ((TObjItemNameSelect *)ctx.item_name_select)->get_result();
        if (selection >= 0) {
            TObjItemNameSelect::set_selection_index(selection);
            ((TObject *)ctx.item_name_select)->queue_destruction();
            ctx.item_name_select = NULL;
            state = QST_RUNNING;
        }
        break;
    }
    case QST_WAIT_ITEM_OK:
        if (((TObjItemOKWindow *)ctx.item_ok_window)->is_done() != 0) {
            ctx.registers[ctx.result_register] = ((TObjItemOKWindow *)ctx.item_ok_window)->get_result();
            ((TObject *)ctx.item_ok_window)->queue_destruction();
            ctx.item_ok_window = NULL;
            state = QST_RUNNING;
        }
        break;
    case QST_WAIT_ITEM_CHOICE: {
        s32 item = ((TWindowMenuIconLine *)ctx.pack_select_window)->get_cursor_value();
        if (item != ctx.registers[ctx.result_register]) {
            ctx.registers[ctx.result_register] = item;
            ((TWindowHelpItem *)ctx.pack_select_help_window)->set_displayed_item_by_id(item);
        }
        if (((TWindowMenuIconLine *)ctx.pack_select_window)->is_decided() != 0) {
            ((TWindowBase *)ctx.pack_select_window)->close();
            ctx.pack_select_window = NULL;
            ((TWindowBase *)ctx.pack_select_help_window)->close();
            ctx.pack_select_help_window = NULL;
            state = QST_RUNNING;
            TWindowCtrl::enable_client_main_menu(local_client_id);
            TWindowCtrl::clear_flag_bit2();
        }
        break;
    }
    }
}

TQuestThreadBoard::~TQuestThreadBoard() {
    if (ctx.message_window != nullptr) {
        ((TWindowBase *)ctx.message_window)->close();
        ctx.message_window = nullptr;
    }
    if (ctx.list_window != nullptr) {
        ((TWindowBase *)ctx.list_window)->close();
        ctx.list_window = nullptr;
    }
    TLobby::close_windows();
    quest_thread_board = NULL;
}

TQuestThreadBoard::TQuestThreadBoard(TUnk_804C8678 *root, s32 label) : TObject(NULL) {
    m_name = TQuestThreadBoard__class_name;
    ctx.copy(&root->ctx);
    ctx.pc = ctx.function_table[label];
    state = QST_RUNNING;
    quest_thread_board = this;
}

void QuestVmContext::copy(QuestVmContext *src) {
    saddr tmp;
    saddr to;
    u8 *from;
    tmp = (saddr)src->code;
    from = (u8 *)src + 0x30;
    to = (saddr)((u8 *)this + 0x30);
    code = (u8 *)tmp;
    function_table = src->function_table;
    registers = src->registers;
    message_window = src->message_window;
    list_window = src->list_window;
    result_register = src->result_register;
    unk18 = src->unk18;
    call_stack_depth = src->call_stack_depth;
    pc = src->pc;
    unk24 = src->unk24;
    unk28 = src->unk28;
    message_speaker = src->message_speaker;
    tmp = *(s32 *)((s8 *)src + 0x30);
    *(s32 *)((s8 *)this + 0x30) = tmp;
    *(ByteBlock_20 *)(to + 4) = *(const ByteBlock_20 *)((saddr)from + 4);
    to = (saddr)((u8 *)this + 0x50);
    from = (u8 *)src + 0x50;
    *(ByteBlock_100 *)(to + 4) = *(const ByteBlock_100 *)((saddr)from + 4);
    unk154 = src->unk154;
    unk155 = src->unk155;
    unk156 = src->unk156;
    unk158 = src->unk158;
    item_name_entry = src->item_name_entry;
    item_name_select = src->item_name_select;
    item_ok_window = src->item_ok_window;
    pack_select_window = src->pack_select_window;
    pack_select_help_window = src->pack_select_help_window;
    statistic_arg1 = src->statistic_arg1;
    statistic_arg2 = src->statistic_arg2;
}

void TQuestThread::destroy_all_in(TObject *parent) {
    TObject *child = parent->m_down;
    while (parent->m_down != NULL && child != NULL) {
        TObject *cur = child;
        child = child->m_next;
        if (cur->check_value_equals(TQuestThread__class_name) != 0) {
            cur->queue_destruction();
        } else {
            destroy_all_in(cur);
        }
    }
}

void TQuestThread::run_task() {
    TObject *parent = m_up;

    switch (state) {
    case QST_RUNNING:
    case QST_SUSPEND_SYNC:
        state = ctx.dispatch();
        break;
    case QST_SUSPEND_RETURN:
        ((TObject *)this)->queue_destruction();
        break;
    case QST_SUSPEND_EXIT:
        queue_destruction(parent);
        break;
    case QST_WAIT_MESSAGE: {
        TObjPlayer *player = get_player_by_client_id(local_client_id);
        if (player != NULL && player->is_controls_locked() == 0 &&
            test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
            u16 id = TWindowCtrl::get_window_id();
            if (is_actor_speech_balloon_done(id) == 0) {
                complete_actor_speech_balloons(id);
            } else {
                state = QST_RUNNING;
            }
        }
        break;
    }
    case QST_WAIT_MESSAGE_QB:
        if (get_player_by_client_id(local_client_id) != NULL) {
            void *pad = &controller_input_state.controllers[0];
            if (test_pressed_buttons_packed(pad, 4) != 0) {
                state = QST_RUNNING;
            }
            if (test_pressed_buttons_packed(pad, 8) != 0) {
                TLobby::close_windows();
                ((TObject *)this)->queue_destruction();
            }
        }
        break;
    case QST_WAIT_LIST:
        if (((TWindowMenu *)ctx.list_window)->is_decided() != 0) {
            ctx.registers[ctx.result_register] = ((TWindowMenu *)ctx.list_window)->get_selected_value();
            ((TWindowBase *)ctx.list_window)->close();
            ctx.list_window = NULL;
            state = QST_RUNNING;
            TWindowCtrl::enable_client_main_menu(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
        }
        break;
    case QST_WAIT_FADE:
        if (TLobby::get_quest_thread_state() == 0) {
            state = QST_RUNNING;
        }
        break;
    case QST_WAIT_ITEM_NAME_ENTRY:
        if (((TObjItemNameEntry *)ctx.item_name_entry)->process_keyboard_input() != 0) {
            ((TObject *)ctx.item_name_entry)->queue_destruction();
            ctx.item_name_entry = NULL;
            state = QST_RUNNING;
        }
        break;
    case QST_WAIT_ITEM_NAME_SELECT: {
        s32 selection = ((TObjItemNameSelect *)ctx.item_name_select)->get_result();
        if (selection >= 0) {
            TObjItemNameSelect::set_selection_index(selection);
            ((TObject *)ctx.item_name_select)->queue_destruction();
            ctx.item_name_select = NULL;
            state = QST_RUNNING;
        }
        break;
    }
    case QST_WAIT_ITEM_OK:
        if (((TObjItemOKWindow *)ctx.item_ok_window)->is_done() != 0) {
            ctx.registers[ctx.result_register] = ((TObjItemOKWindow *)ctx.item_ok_window)->get_result();
            ((TObject *)ctx.item_ok_window)->queue_destruction();
            ctx.item_ok_window = NULL;
            state = QST_RUNNING;
        }
        break;
    case QST_WAIT_ITEM_CHOICE: {
        s32 item = ((TWindowMenuIconLine *)ctx.pack_select_window)->get_cursor_value();
        if (item != ctx.registers[ctx.result_register]) {
            ctx.registers[ctx.result_register] = item;
            ((TWindowHelpItem *)ctx.pack_select_help_window)->set_displayed_item_by_id(item);
        }
        if (((TWindowMenuIconLine *)ctx.pack_select_window)->is_decided() != 0 ||
            ((TWindowMenuIconLine *)ctx.pack_select_window)->is_cancelled() != 0) {
            if (((TWindowMenuIconLine *)ctx.pack_select_window)->is_cancelled() != 0) {
                ctx.registers[ctx.result_register] = -1;
            }
            ((TWindowBase *)ctx.pack_select_window)->close();
            ctx.pack_select_window = NULL;
            ((TWindowBase *)ctx.pack_select_help_window)->close();
            ctx.pack_select_help_window = NULL;
            state = QST_RUNNING;
            TWindowCtrl::enable_client_main_menu(local_client_id);
            TWindowCtrl::clear_flag_bit2();
            TWindowCtrl::clear_flag();
            TWindowCtrl::clear_flag_2();
        }
        break;
    }
    }
}

TQuestThread::~TQuestThread() {}

TQuestThread *TQuestThread::create_for_floor() {
    s32 floor = get_current_floor();
    if (TQuestThread__floor_handler_ids[floor] != -1 && quest_mission_manager != NULL) {
        return new TQuestThread(quest_mission_manager, TQuestThread__floor_handler_ids[floor]);
    }
    return NULL;
}

TQuestThread *TQuestThread::create(int label) {
    TQuestThread *thread;

    if (quest_mission_manager != NULL) {
        thread = new TQuestThread(quest_mission_manager, label);
        if (thread != NULL) {
            thread->set_parent(tl_00);
            return thread;
        }
        return NULL;
    }
    return NULL;
}

TQuestThread *TQuestThread::create_in_root(s32 label) {
    if (quest_mission_manager != NULL) {
        return new TQuestThread(quest_mission_manager, label);
    }
    return NULL;
}

TQuestThread::TQuestThread(TUnk_804C8678 *root, s32 label) : TObject(root) {
    m_name = TQuestThread__class_name;
    ctx.copy(&root->ctx);
    ctx.pc = ctx.function_table[label];
    state = QST_RUNNING;
    if (ctx.pc == -1) {
        ((TObject *)this)->queue_destruction();
    }
}

void TQuestThread::clear_floor_handler(s32 floor) {
    if (floor < 0 || floor > 0x11) {
        return;
    }
    TQuestThread__floor_handler_ids[floor] = -1;
}

void TQuestThread::set_floor_handler(s32 floor, s32 label) {
    if (floor < 0 || floor > 0x11) {
        return;
    }
    TQuestThread__floor_handler_ids[floor] = label;
}

void TQuestThread__sub_801F5D88(void) { TQuestThread::clear_all_floor_handlers(); }

void TQuestThread::clear_all_floor_handlers() {
    s32 i;
    for (i = 0; i < 0x12; i++) {
        TQuestThread__floor_handler_ids[i] = -1;
    }
}

void TQuestThread::clear_buffer(TUnk_804C8678 *root) {
    if (root->ctx.registers != NULL) {
        memset(root->ctx.registers, 0, 1024);
    }
}

void handle_6x77_sync_quest_register(u8 *packet) {
    TUnk_804C8678 *root;
    s32 *registers;
    u16 index;
    TLobby::bswap_header(packet);
    root = quest_mission_manager;
    if (root != NULL) {
        index = *(u16 *)(packet + 4);
        registers = root->ctx.registers;
        if (index <= 0xFFU) {
            registers[index] = *(s32 *)(packet + 8);
        }
    }
}

char *TQuestThread::get_quest_name() {
    if (quest_mission_manager != NULL) {
        return reinterpret_cast<QuestBinHeader *>(quest_mission_manager->script)->name;
    }
    return "ERROR";
}

// defined here so their strings follow "ERROR" in .rodata, as in the original
const char *TQuestThread__class_name = "TQuestThread";
const char *TQuestThreadBoard__class_name = "TQuestThreadBoard";
const char *TObjItemNameEntry__class_name = "TObjItemNameEntry";
const char *TObjItemNameSelect__class_name = "TObjItemNameSelect";
const char *TObjItemOKWindow__class_name = "TObjItemOKWindow";
__declspec(section ".rodata") extern const char TObjItemOKWindow__text_format[] = "%s %s";

void TQuestThread::clear_thread_state() {
    memset(quest_board_handlers, 0, 0xD8);
}

s32 TQuestThread::get_register(const TUnk_804C8678 *root, int index) {
    if (root != NULL) {
        return root->ctx.registers[index];
    }
    return 0;
}

void TUnk_804C8678::run_task() {}

TUnk_804C8678::~TUnk_804C8678() {
    if (kind == 0) {
        quest_mission_manager = NULL;
        TQuestThread::clear_thread_state();
    } else {
        quest_area_manager = NULL;
    }
    safe_free(script);
}

void TQuestThread::destroy_quest_obj() {
    if (quest_area_manager != NULL) {
        quest_area_manager->queue_destruction();
        quest_area_manager = NULL;
    }
}

void load_area_dialogue_script() {
    s32 bank;

    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1: if (get_main_phase() == 14) { bank = 0; } else { bank = 1; } break;
    case AREA_FOREST1: case AREA_FOREST2: bank = 2; break;
    case AREA_CAVE1: case AREA_CAVE2: case AREA_CAVE3: bank = 3; break;
    case AREA_MINE1: case AREA_MINE2: case AREA_VOL_OPT: bank = 4; break;
    case AREA_RUINS1: case AREA_RUINS2: case AREA_RUINS3: bank = 5; break;
    case AREA_PIONEER2_EP2: if (get_main_phase() == 14) { bank = 6; } else { bank = 7; } break;
    case AREA_VR_TEMPLE_ALPHA: case AREA_VR_TEMPLE_BETA: case AREA_BARBA_RAY: bank = 8; break;
    case AREA_VR_SPACESHIP_ALPHA: case AREA_VR_SPACESHIP_BETA: case AREA_GOL_DRAGON: bank = 9; break;
    case AREA_CENTRAL_CONTROL_AREA: case AREA_JUNGLE_NORTH: case AREA_JUNGLE_EAST: case AREA_MOUNTAIN: case AREA_SEASIDE: case AREA_GAL_GRYPHON: bank = 10; break;
    case AREA_SEABED_UPPER: case AREA_SEABED_LOWER: case AREA_OLGA_FLOW: bank = 11; break;
    default: return;
    }
    if (enable_v2_features == 1 && game_difficulty_selection == 3) {
        new TUnk_804C8678(tl_04, area_dialogue_ultimate_script_files[current_language][bank], 1);
    } else {
        new TUnk_804C8678(tl_04, area_dialogue_script_files[current_language][bank], 1);
    }
}

TUnk_804C8678 *TQuestThread::create_by_mode() {
    switch (evt2_random_enemies_mode) {
    case 1:
        return new TUnk_804C8678(tl_su, get_offline_quest_filename());
    case 2:
        return new TUnk_804C8678(tl_su, TQuestListOnline::get_quest_data(), TQuestListOnline::get_quest_size());
    case 3: {
        TUnk_804C8678 *root = new TUnk_804C8678(tl_su, TQuestListVM::get_quest_bin(), TQuestListVM::get_quest_size());
        TQuestListVM::reset();
        return root;
    }
    case 4:
        return new TUnk_804C8678(tl_su, TQuestListOnline::get_quest_data(), TQuestListOnline::get_quest_size());
    case 5:
        return new TUnk_804C8678(tl_su, get_offline_quest_filename());
    default:
        return NULL;
    }
}

TUnk_804C8678::TUnk_804C8678(TObject *parent, void *data, s32 size) : TObject(parent) {
    s32 alloc_size;
    if (size < 0) {
        queue_destruction();
    } else {
        alloc_size = size + 0x400;
        script = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(alloc_size));
        memcpy(script, data, alloc_size);
        quest_mission_manager = this;
        init_quest_script_context(reinterpret_cast<QuestBinHeader *>(script), &ctx);
        kind = 0;
    }
    TQuestThread::clear_thread_state();
}

TUnk_804C8678::TUnk_804C8678(TObject *parent, const char *filename, s32 kind) : TObject(parent) {
    s32 size;
    this->kind = kind;
    script = NULL;
    switch (this->kind) {
    case 0:
        copy_name("QUEST");
        size = get_resource_file_size((const char *)filename);
        if (size < 0) {
            queue_destruction();
        } else {
            script = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(size + 0x400));
            read_disc_file((const char *)filename, script);
            copy_name("..");
            quest_mission_manager = this;
            init_quest_script_context(reinterpret_cast<QuestBinHeader *>(script), &ctx);
            new TQuestThread(this, 0);
        }
        TQuestThread::clear_thread_state();
        break;
    case 1:
        size = get_resource_file_size((const char *)filename);
        if (size < 0) {
            queue_destruction();
        } else {
            script = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(size + 0x400));
            read_disc_file((const char *)filename, script);
            quest_area_manager = this;
            init_quest_script_context(reinterpret_cast<QuestBinHeader *>(script), &ctx);
        }
        break;
    default:
        queue_destruction();
        break;
    }
}

TUnk_804C8678::TUnk_804C8678(TObject *parent, const char *filename) : TObject(parent) {
    s32 size;
    copy_name("QUEST");
    size = get_resource_file_size((const char *)filename);
    if (size < 0) {
        queue_destruction();
    } else {
        script = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(size + 0x400));
        read_disc_file((const char *)filename, script);
        copy_name("..");
        quest_mission_manager = this;
        init_quest_script_context(reinterpret_cast<QuestBinHeader *>(script), &ctx);
        kind = 0;
    }
    TQuestThread::clear_thread_state();
}

void TQuestThread::set_status_flag_80(void *window) { *(u16 *)((u8 *)window + 0x70) |= 0x80; }

void TObjItemNameSelect::set_selection_index(int index) { item_name_selection_index = index; }

void TQuestThread::queue_destruction(void *obj) { ((TObject *)obj)->queue_destruction(); }

void TKeyBoardControl::clear_keyboard_flag60_bit1() {
    TWindowKeyBoardBase *composer = m_base;
    if (composer != NULL) {
        composer->clear_flag60_bit1();
    }
}

void TWindowKeyBoardBase::clear_flag60_bit1() { m_60 &= 0xfffe; }

u32 TQuestListVM::get_quest_size() { return decompression_capacity; }

int TQuestListOnline::get_quest_size() { return quest_bin_decompressed_size; }

u8 *TQuestListOnline::get_quest_data() { return online_quest_bin_data; }

char *get_offline_quest_filename() { return offline_quest_filename_buffer_a; }

void *__vt__18TObjItemNameSelect[] = {
    0, 0,
    (void *)__dt__18TObjItemNameSelectFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};

void *__vt__17TObjItemNameEntry[] = {
    0, 0,
    (void *)__dt__17TObjItemNameEntryFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};

void *__vt__17TQuestThreadBoard[] = {
    0, 0,
    (void *)__dt__17TQuestThreadBoardFv,
    (void *)run_task__17TQuestThreadBoardFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};

void *__vt__12TQuestThread[] = {
    0, 0,
    (void *)__dt__12TQuestThreadFv,
    (void *)run_task__12TQuestThreadFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
