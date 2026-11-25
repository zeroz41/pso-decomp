#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMessageYesNo.h"

#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"

#pragma push
#pragma readonly_strings on
const char *TWindowMessageYesNo::class_name = "TWindowMessageYesNo";
#pragma pop


void TWindowMessageYesNo::render() {  }

void TWindowMessageYesNo::run_task() { if (is_child_visible() != 0) { ((TWindowMenu *)(this->message_menu))->confirm_selection(); } }


TWindowMessageYesNo *TWindowMessageYesNo::create(void *parent, s32 client_id, void *yes_label, void *no_label) {
    TWindowMessageYesNo *o;
    o = new TWindowMessageYesNo((TObject *)parent, client_id, yes_label, no_label);
    return o;
}

TWindowMessageYesNo::~TWindowMessageYesNo() {
    if (choice_menu != NULL) { choice_menu->close(); choice_menu = NULL; }
    if (message_menu != NULL) { message_menu->close(); this->message_menu = 0; }
}
TWindowMessageYesNo::TWindowMessageYesNo(TObject *parent, s32 client_id, void *yes_label, void *no_label) : TObject(parent) {
    m_name = TWindowMessageYesNo::class_name;
    this->client_id = client_id;
    this->message_menu = 0;
    choice_menu = NULL;
    this->yes_text = (u32)yes_label;
    this->no_text = (u32)no_label;
}
