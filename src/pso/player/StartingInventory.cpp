#include "pso/item/InventoryEntryCopy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyCharData.h"
#include "types.h"
#include "pso/player/StartingInventory.h"
#include "pso/player/TObjPlayer.h"
void init_class_starting_inventory(TPlyCharData *character) {
    u8 class_index = character->m_disp_part2.char_class;
    character->m_inventory.m_num_items = 5;
    copy_item_entry_array(character->m_inventory.m_num_items,
        get_class_starting_inventory(class_index),
        character->m_inventory.get_items());
}
