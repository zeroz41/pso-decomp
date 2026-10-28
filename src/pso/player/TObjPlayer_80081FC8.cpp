#include "types.h"
#include "pso/player/TObjPlayer_80081FC8.h"
#include "pso/map/FloorArea.h"

extern "C" {

s32 construct_freeze_shell__10TObjPlayerFPUcPUc(u32, u32, s32, s32);
u32 __nw__7TObjectFUl(s32);
u16 get_entity_id(u32);

void create__10TObjPlayerFUiii(u32 arg0, s32 arg1, s32 arg2) {
    u16 temp_r3;

    u32 obj;
    if ((is_current_area_item_enabled() != 0) && (arg0 != 0U)) {
        temp_r3 = get_entity_id(arg0);
        if (((u16) temp_r3 != 0xFFFF) && ((u16) temp_r3 < 0x4000U) && ((obj = __nw__7TObjectFUl(0x368)) != 0U)) {
            construct_freeze_shell__10TObjPlayerFPUcPUc(obj, arg0, arg1, arg2);
        }
    }
}

}
