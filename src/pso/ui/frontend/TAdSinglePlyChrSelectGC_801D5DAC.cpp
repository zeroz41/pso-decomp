#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TItemData.h"

int TAdSinglePlyChrSelectGC::get_game_mode() {  return chr_select_game_mode; }

s32 TItemData::is_frame() {
    bool result = false;
    if (data1.data_u8[0] == 1 && data1.data_u8[1] == 1) {
        result = true;
    }
    return result;
}
