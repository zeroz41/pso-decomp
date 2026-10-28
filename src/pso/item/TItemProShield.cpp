#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemProShield.h"
#include "pso/item/TItemEquipBase.h"

extern "C" {

void* TItemEquipBase__sub_8010B73C(void* p);

u8 TItem::get_item_index() { return this->m_ee; }
void* TItemEquipBase__sub_8010B73C(void* p) { ((TItemEquipBase *)p)->init_slot(); return p; }

}
