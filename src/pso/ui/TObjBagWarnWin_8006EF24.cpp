#include "types.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/TObjBagWarnWin.h"

extern "C" {
extern u8 *text_language_group_table;
void *__nw__7TObjectFUl(int);

void *TObjBagWarnWin::create(void *bag_warn_win) {
    void *o = __nw__7TObjectFUl(0xA4);
    if (o != NULL) {
        o = __ct__14TObjBagWarnWinFv(o, bag_warn_win);
    }
    return o;
}
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32 arg0) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0x2C)) + (arg0 * 4));
}

}
