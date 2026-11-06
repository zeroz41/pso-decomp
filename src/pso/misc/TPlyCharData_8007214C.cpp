#include "types.h"
#include "pso/misc/TPlyCharData_8007214C.h"
#include "pso/misc/TPlyDispConfig_80071F1C.h"
#include "pso/misc/TPlyInventoryItem_800721D4.h"
#include "pso/player/TPlyCharData.h"

s32 __ct__12TPlyCharDataFv(s32 arg0) {
    __ct__14TPlyDispConfigFv((void *)(arg0 + 0x3C0));
    ((TPlyCharData *)arg0)->init_inventory_items();
    return arg0;
}

void TPlyCharData::init_inventory_items() { { int i; for (i = 0; i < 30; i++) { init__17TPlyInventoryItemFv((u8 *)((char*)this + 0x4 + i * 28)); } } }
