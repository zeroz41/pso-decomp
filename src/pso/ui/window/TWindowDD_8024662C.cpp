#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {
TObject *TWindowCtrlMain__sub_8024CDB0(void *p);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__11TWindowBase[];
int TWindowSubComCard__sub_8024634C(void*);
int update_open_close__17TWindowSubComCardFv(void*);

int TWindowDD::update_com_card() { return TWindowSubComCard__sub_8024634C(this); }
int TWindowDD::initialize_subwindow() { return update_open_close__17TWindowSubComCardFv(this); }
void TWindowBase::render() {  }
void TWindowBase::run_task() {  }

TWindowBase::~TWindowBase() {
    ((TWindowSubStatusDisp *)((s8 *)this + 0x24))->destroy_all_items();
    sub_8026CC28();
}
u8 *TWindowDD::construct_base(u8 *arg1, s16 arg2, u8 *arg3) {
    __ct__7TObjectFP7TObject(this, (void *) (TWindowCtrlMain__sub_8024CDB0((void *)arg2)));
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = __vt__11TWindowBase;
    ((TWindowBase *)((u8 *)this))->sub_80244F2C(arg1, arg3, arg2);
    return ((u8 *)this);
}

}
