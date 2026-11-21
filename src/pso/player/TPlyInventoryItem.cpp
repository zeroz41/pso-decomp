#include "types.h"
#include "pso/player/TPlyInventory.h"
#include "pso/system/byteswap.h"

void TPlyInventoryItem::bswap() {
    bswap_32(&m_flags);
    m_data.bswap();
}
