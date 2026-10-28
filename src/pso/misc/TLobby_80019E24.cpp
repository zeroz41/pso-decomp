#include "types.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TLobby.h"
#include "pso/TItemLoad.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80019E60_lbl_804340D8 { char value[0x13]; };
typedef char RecoveredGlobal_80019E60_lbl_804340D8_size[sizeof(RecoveredGlobal_80019E60_lbl_804340D8) == 0x13 ? 1 : -1];

extern RecoveredGlobal_80019E60_lbl_804340D8 lbl_804340D8;
extern s32 lbl_805D49D8;
extern u32 item_loader_instance;

void TLobby::free_item_loader() {
    if ((u32) item_loader_instance != 0U) {
        __dt__9TItemLoadFPvs((s32 *)item_loader_instance, 1);
        item_loader_instance = 0U;
        lbl_805D49D8 = 0;
    }
}
void TLobby::load_draw_line_task() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TItemLoad *)temp_r3)->load_buffer((u32) &lbl_804340D8.value, 0x4800));
    }
    (*(u8 * *)&item_loader_instance) = (unsigned char *) ((void *) var_r0);
    if ((u32) var_r0 != 0U) {
        lbl_805D49D8 = ((TItemMag *)var_r0)->get_type();
    }
}
