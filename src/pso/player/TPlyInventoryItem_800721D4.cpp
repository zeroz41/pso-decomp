#include "types.h"
#include "pso/player/TPlyInventory.h"

void TPlyInventoryItem::init() {
    m_present[0] = 0;
    m_present[1] = -1;
    m_flags = 0;
    m_present[3] = 0;
    m_present[2] = 0;
    m_data.init();
}
