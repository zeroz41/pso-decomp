#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct RecoveredGlobal_802466E0_lbl_804CE018 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 TWindowCtrlMain__sub_8024CDB0(void *p);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_804CE018[];
int TWindowSubComCard__sub_8024634C(void*);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
int update_open_close__17TWindowSubComCardFv(void*);
void sub_8026CC28__11TWindowBaseFv(void *);

int TWindowDD::update_com_card() { return TWindowSubComCard__sub_8024634C(this); }
int TWindowDD::initialize_subwindow() { return update_open_close__17TWindowSubComCardFv(this); }
void TWindowBase::render() {  }
void TWindowBase::run_task() {  }

void *TWindowDD::destroy_window_base(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804CE018;
        ((TWindowSubStatusDisp *)((s8 *)this + 0x24))->destroy_all_items();
        sub_8026CC28__11TWindowBaseFv(this);
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
typedef char RecoveredGlobal_802466E0_lbl_804CE018_size[sizeof(RecoveredGlobal_802466E0_lbl_804CE018) == 0x18 ? 1 : -1];
u8 *TWindowDD::construct_base(u8 *arg1, s16 arg2, u8 *arg3) {
    __ct__7TObjectFP7TObject(this, (void *) (TWindowCtrlMain__sub_8024CDB0((void *)arg2)));
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_802466E0_lbl_804CE018 *)&lbl_804CE018).value;
    ((TWindowBase *)((u8 *)this))->sub_80244F2C(arg1, arg3, arg2);
    return ((u8 *)this);
}

}
