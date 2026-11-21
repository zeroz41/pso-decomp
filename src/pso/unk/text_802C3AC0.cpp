#include "types.h"
#include "pso/unk/text_802C3AC0.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
s32 get_class_starting_inventory(u8);
void copy_item_entry_array(u8, s32, s32);
void init_class_starting_inventory(void *arg0) {
    u8 *p = (u8 *) arg0;
    u8 v = p[0x3A1];
    p[0] = 5;
    copy_item_entry_array(p[0], get_class_starting_inventory(v), (s32)((TObjPlayer *)p)->get_ptr_4());
}

}
