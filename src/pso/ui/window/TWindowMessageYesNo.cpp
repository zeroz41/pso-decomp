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
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
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

void TWindowSubComCard::free_windows() {
    if ((u32) this->m_28 != 0U) {
        reinterpret_cast<TWindowBase *>(this->m_28)->reparent_to_main_ctrl();
    }
    if ((u32) this->m_2c != 0U) {
        reinterpret_cast<TWindowBase *>(this->m_2c)->reparent_to_main_ctrl();
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

void TWindowSubComCard::update_card_slot() { void* m = *(void* *)&this->m_2c; if (m) ((TWindowMenu *)m)->set_flag_40(); }
void TWindowSubComCard::notify_trade_main() { void* m = *(void* *)&this->m_2c; if (m) ((TWindowSubTradeMain *)m)->clear_trade_flag(); }



void TWindowMessageYesNo::set_choice_menu_flag70_bit10() {
    TWindowMenu *menu = choice_menu;
    if (menu != NULL) {
        menu->set_flag70_bit10();
    }
}


void TWindowMessageYesNo::close() { queue_destruction(); }
void TWindowMessageYesNo::set_menu_selected_index(s16 index) { if (choice_menu) ((TWindowSubComCardList *)choice_menu)->set_selected_index(index); }
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
void initialize_option_dialog(void *dialog, s32 message, const NJS_POINT2 *position, f32 width) {
    *(s32 *)((s8 *)dialog + 0x28) = (saddr)create_window_menu(position, 1, *(s32 *)((s8 *)dialog + 0x24));
    ((TWindowMenu *)(*(saddr *)((s8 *)dialog + 0x28)))->add_text_entry(message, 0x21, 0);
    ((TWindowMenu *)(*(saddr *)((s8 *)dialog + 0x28)))->set_flag_40();
    TQuestThread::set_status_flag_80((void *)(*(saddr *)((s8 *)dialog + 0x28)));
    ((TWindowMenu *)(*(saddr *)((s8 *)dialog + 0x28)))->calc_layout_height(width);
}

void open_yes_no_prompt(TWindowMessageYesNo *dialog, u32 title, s32 text, const NJS_POINT2 *message_position, f32 width) {
    NJS_POINT2 position;
    if (title == 0U) {
        dialog->message_menu = create_window_menu(message_position, 1, dialog->client_id);
    } else {
        dialog->message_menu = reinterpret_cast<TWindowMenu *>(create_titled_window_menu(message_position, 1, title, dialog->client_id));
    }
    dialog->message_menu->add_text_entry(text, 0x21, 0);
    reinterpret_cast<TWindowMenu *>(dialog->message_menu)->set_flag_40();
    TQuestThread::set_status_flag_80(dialog->message_menu);
    dialog->message_menu->calc_layout_height(width);
    dialog->get_choice_menu_position(&position);
    dialog->choice_menu = create_yes_no_window(&position, dialog->client_id,
                                              reinterpret_cast<const char *>(dialog->yes_text),
                                              reinterpret_cast<const char *>(dialog->no_text));
}


void TWindowMessageYesNo::open_yes_no_prompt_with_text(s32 text, const NJS_POINT2 *pos, f32 width) {
    open_yes_no_prompt(this, 0, text, pos, width);
}


#pragma push
#pragma readonly_strings on
const char *TWindowMessageYesNo__name = "TWindowMessageYesNo";
#pragma pop

void TWindowMessageYesNo::render() {  }

void TWindowMessageYesNo::run_task() { if (is_child_visible() != 0) { ((TWindowMenu *)(this->message_menu))->confirm_selection(); } }

TWindowMessageYesNo *TWindowMessageYesNo::create(void *parent, s32 client_id, void *arg2, void *arg3) {
    TWindowMessageYesNo *o;
    o = new TWindowMessageYesNo((TObject *)parent, client_id, arg2, arg3);
    return o;
}

TWindowMessageYesNo::~TWindowMessageYesNo() {
    if (choice_menu != NULL) { choice_menu->close(); choice_menu = NULL; }
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x28)))->close(); this->message_menu = 0; }
}
TWindowMessageYesNo::TWindowMessageYesNo(TObject *parent, s32 client_id, void *arg3, void *arg4) : TObject(parent) {
    m_name = TWindowMessageYesNo__name;
    this->client_id = client_id;
    this->message_menu = 0;
    choice_menu = NULL;
    *(void **)((s8 *)this + 0x20) = arg3;
    *(void **)((s8 *)this + 0x1C) = arg4;
}
