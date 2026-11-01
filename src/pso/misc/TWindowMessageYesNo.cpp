#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowSubComCard_80244774.h"

#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/ui/TAdChrSelASlotGC.h"

extern "C" {
void *__ct__19TWindowMessageYesNoFP7TObjectPvPvPv(void *, void *, void *, void *, void *);
void *__ct__19TWindowMessageYesNoFP7TObjectPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);

void TWindowMessageYesNo::render() {  }

void TWindowMessageYesNo::run_task() { if (is_child_visible() != 0) { ((TWindowMenu *)(this->m_28))->confirm_selection(); } }


void *TWindowMessageYesNo::create(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = new TWindowMessageYesNo((TObject *)arg0, (void *)arg1, (void *)arg2, (void *)arg3);
    return o;
}

}
TWindowMessageYesNo::~TWindowMessageYesNo() {
    if (*(void **)((s8 *)this + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x2C)))->close(); this->m_2c = 0; }
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x28)))->close(); this->m_28 = 0; }
}
extern void *TWindowMessageYesNo__name;
TWindowMessageYesNo::TWindowMessageYesNo(TObject *object, void *arg2, void *arg3, void *arg4) : TObject(object) {
    *(void * *)&this->m_name = TWindowMessageYesNo__name;
    *(void **)((s8 *)this + 0x24) = arg2;
    this->m_28 = 0;
    this->m_2c = 0;
    *(void **)((s8 *)this + 0x20) = arg3;
    *(void **)((s8 *)this + 0x1C) = arg4;
}
