#include "types.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/TObjBagWarnWin.h"

extern "C" {
extern u8 *text_language_group_table;

void *TObjBagWarnWin::create(void *bag_warn_win) {
    void *o = (void *)new TObjBagWarnWin((TObject *)bag_warn_win);
    return o;
}
s32 get_message_text(s32 arg0) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0x2C)) + (arg0 * 4));
}

}
