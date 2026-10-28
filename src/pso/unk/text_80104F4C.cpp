#include "types.h"
#include "pso/unk/text_80104F4C.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
void *find_item_combination_recipe(void *item, void *equip);
}
void *find_unique_combination_target(void *player, void *item) {
    s32 count = 0;
    void *found;
    s32 i;
    void *e;
    for (i = 0; i != 13; i++) {
        e = ((TObjPlayer *)player)->get_equipped_item(i);
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
