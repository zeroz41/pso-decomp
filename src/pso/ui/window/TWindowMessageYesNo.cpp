#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowBase.h"


// The yes/no choice menu sits 111 left of and 10 above the message window's bottom-right corner.
void TWindowMessageYesNo::get_choice_menu_position(NJS_POINT2 *position) {
    if (message_menu != NULL) {
        position->x = (message_menu->target_position[0] + message_menu->target_size[0]) - 111.0f;
        position->y = (message_menu->target_position[1] + message_menu->target_size[1]) - 10.0f;
    }
}

void TWindowMessageYesNo::reparent_to_main_ctrl() {
    if (message_menu != NULL) {
        message_menu->reparent_to_main_ctrl();
    }
    if (choice_menu != NULL) {
        choice_menu->reparent_to_main_ctrl();
    }
}

void TWindowMessageYesNo::move_to(const NJS_POINT2 *position) {
    NJS_POINT2 choice_position;
    TWindowBase *window = message_menu;
    if (window != NULL && (window->target_position[0] != position->x || window->target_position[1] != position->y)) {
        window->slide_to((f32 *)position);
    }
    if (choice_menu != NULL) {
        get_choice_menu_position(&choice_position);
        window = choice_menu;
        if (window->target_position[0] != choice_position.x || window->target_position[1] != choice_position.y) {
            window->slide_to((f32 *)&choice_position);
        }
    }
}

void TWindowMessageYesNo::disable_choice_input() {
    TWindowMenu *menu = choice_menu;
    if (menu != NULL) {
        menu->disable_input();
    }
}

void TWindowMessageYesNo::enable_choice_input() {
    TWindowMenu *menu = choice_menu;
    if (menu != NULL) {
        menu->enable_input();
    }
}



void TWindowMessageYesNo::set_choice_menu_flag70_bit10() {
    TWindowMenu *menu = choice_menu;
    if (menu != NULL) {
        menu->set_flag70_bit10();
    }
}


void TWindowMessageYesNo::close() { queue_destruction(); }
void TWindowMessageYesNo::set_menu_selected_index(s16 index) { if (choice_menu) choice_menu->set_selected_index(index); }
s32 TWindowMessageYesNo::get_selected_value() {
    if (choice_menu == NULL) {
        return -1;
    }
    return choice_menu->get_selected_value();
}
s32 TWindowMessageYesNo::is_cancelled() {
    if (choice_menu == NULL) {
        return 0;
    }
    return choice_menu->is_cancelled();
}

s32 TWindowMessageYesNo::is_child_visible() {
    if (choice_menu == NULL) {
        return 0;
    }
    return choice_menu->is_decided();
}
void initialize_option_dialog(TWindowMessageYesNo *dialog, s32 message, const NJS_POINT2 *position, f32 width) {
    dialog->message_menu = create_window_menu(position, 1, dialog->client_id);
    dialog->message_menu->add_text_entry(message, 0x21, 0);
    dialog->message_menu->disable_input();
    TQuestThread::set_status_flag_80(dialog->message_menu);
    dialog->message_menu->calc_layout_height(width);
}

void open_yes_no_prompt(TWindowMessageYesNo *dialog, u32 title, s32 text, const NJS_POINT2 *message_position, f32 width) {
    NJS_POINT2 position;
    if (title == 0U) {
        dialog->message_menu = create_window_menu(message_position, 1, dialog->client_id);
    } else {
        dialog->message_menu = reinterpret_cast<TWindowMenu *>(create_titled_window_menu(message_position, 1, title, dialog->client_id));
    }
    dialog->message_menu->add_text_entry(text, 0x21, 0);
    reinterpret_cast<TWindowMenu *>(dialog->message_menu)->disable_input();
    TQuestThread::set_status_flag_80(dialog->message_menu);
    dialog->message_menu->calc_layout_height(width);
    dialog->get_choice_menu_position(&position);
    dialog->choice_menu = create_yes_no_window(&position, dialog->client_id, dialog->yes_text, dialog->no_text);
}


void TWindowMessageYesNo::open_yes_no_prompt_with_text(s32 text, const NJS_POINT2 *pos, f32 width) {
    open_yes_no_prompt(this, 0, text, pos, width);
}


#pragma push
#pragma readonly_strings on
const char *TWindowMessageYesNo::class_name = "TWindowMessageYesNo";
#pragma pop

void TWindowMessageYesNo::render() {  }

void TWindowMessageYesNo::run_task() { if (is_child_visible() != 0) { this->message_menu->confirm_selection(); } }

TWindowMessageYesNo *TWindowMessageYesNo::create(void *parent, s32 client_id, const char *yes_label, const char *no_label) {
    TWindowMessageYesNo *o;
    o = new TWindowMessageYesNo((TObject *)parent, client_id, yes_label, no_label);
    return o;
}

TWindowMessageYesNo::~TWindowMessageYesNo() {
    if (choice_menu != NULL) { choice_menu->close(); choice_menu = NULL; }
    if (message_menu != NULL) { message_menu->close(); message_menu = NULL; }
}
TWindowMessageYesNo::TWindowMessageYesNo(TObject *parent, s32 client_id, const char *yes_label, const char *no_label) : TObject(parent) {
    m_name = TWindowMessageYesNo::class_name;
    this->client_id = client_id;
    this->message_menu = 0;
    choice_menu = NULL;
    this->yes_text = yes_label;
    this->no_text = no_label;
}
