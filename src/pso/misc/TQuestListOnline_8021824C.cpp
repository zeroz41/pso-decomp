#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TQuestListOnline_8021824C.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TQuestListOnline.h"

extern "C" {

s32 __dl__7TObjectFPv(void *);

extern s32 __vt__16TQuestListOnline[];
extern s32 TQuestListOnline__instance;

void *__dt__16TQuestListOnlineFv(TQuestListOnline *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TQuestListOnline;
        if ((u32) arg0->list_window != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close();
            arg0->list_window = 0U;
        }
        if ((u32) arg0->description_window != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
            arg0->description_window = 0U;
        }
        if ((u32) arg0->info_window != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
            arg0->info_window = 0U;
        }
        if ((u32) arg0->confirm_window != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x44)))->close();
            arg0->confirm_window = 0U;
        }
        TQuestListOnline__instance = 0;
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
