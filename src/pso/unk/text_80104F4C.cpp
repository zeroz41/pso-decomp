#include "types.h"
#include "pso/unk/text_80104F4C.h"
extern "C" {
void *get_equip_field_d04__10TObjPlayerFl(void *p, s32 slot);
void *find_item_combination_recipe(void *item, void *equip);
}
void *find_unique_combination_target(void *player, void *item) {
    s32 count = 0;
    void *found;
    s32 i;
    void *e;
    for (i = 0; i != 13; i++) {
        e = get_equip_field_d04__10TObjPlayerFl(player, i);
        if (find_item_combination_recipe(item, e) != NULL) {
            found = e;
            count++;
        }
    }
    if (count != 1) {
        found = NULL;
    }
    return found;
}
