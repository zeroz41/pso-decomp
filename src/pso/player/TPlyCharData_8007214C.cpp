#include "pso/player/TPlyCharData.h"

TPlyCharData::TPlyCharData() { init_inventory_items(); }

void TPlyCharData::init_inventory_items() { { int i; for (i = 0; i < 30; i++) { ((TPlyInventoryItem *)((u8 *)((char*)this + 0x4 + i * 28)))->init(); } } }
