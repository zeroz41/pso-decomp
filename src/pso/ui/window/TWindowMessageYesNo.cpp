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
const char *TWindowMessageYesNo__name = "TWindowMessageYesNo";
#pragma pop

extern "C" {

void TWindowMessageYesNo::render() {  }

void TWindowMessageYesNo::run_task() { if (is_child_visible() != 0) { ((TWindowMenu *)(this->message_menu))->confirm_selection(); } }


TWindowMessageYesNo *TWindowMessageYesNo::create(void *parent, s32 client_id, void *arg2, void *arg3) {
    TWindowMessageYesNo *o;
    o = new TWindowMessageYesNo((TObject *)parent, client_id, arg2, arg3);
    return o;
}

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
