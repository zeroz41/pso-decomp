#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"

extern "C" {


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
}
void initialize_option_dialog(void *dialog, s32 message, s32 position, f32 width) {
    *(s32 *)((s8 *)dialog + 0x28) = (saddr)create_window_menu((saddr)(position), 1, *(s32 *)((s8 *)dialog + 0x24));
    ((TWindowMenu *)(*(saddr *)((s8 *)dialog + 0x28)))->add_text_entry(message, 0x21, 0);
    ((TWindowMenu *)(*(saddr *)((s8 *)dialog + 0x28)))->set_flag_40();
    TQuestThread::set_status_flag_80((void *)(*(saddr *)((s8 *)dialog + 0x28)));
    ((TWindowSubComCard *)(*(saddr *)((s8 *)dialog + 0x28)))->calc_layout_height(width);
}

void open_yes_no_prompt(TWindowMessageYesNo *dialog, u32 title, s32 text, s32 position_id, f32 width) {
    NJS_POINT2 position;
    if (title == 0U) {
        dialog->message_menu = create_window_menu(position_id, 1, dialog->client_id);
    } else {
        dialog->message_menu = reinterpret_cast<TWindowMenu *>(create_titled_window_menu(position_id, 1, title, dialog->client_id));
    }
    dialog->message_menu->add_text_entry(text, 0x21, 0);
    reinterpret_cast<TWindowMenu *>(dialog->message_menu)->set_flag_40();
    TQuestThread::set_status_flag_80(dialog->message_menu);
    reinterpret_cast<TWindowSubComCard *>(dialog->message_menu)->calc_layout_height(width);
    dialog->get_choice_menu_position(&position);
    dialog->choice_menu = create_yes_no_window(&position, dialog->client_id,
                                              reinterpret_cast<const char *>(dialog->yes_text),
                                              reinterpret_cast<const char *>(dialog->no_text));
}
