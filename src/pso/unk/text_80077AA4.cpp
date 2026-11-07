#include "types.h"
struct Elem_80077AA4 { u8 data[8]; };

extern "C" {
void *__construct_array(void *, void *, void *, u32, u32);
void __ct__16TPlyGuildCardTagFv(void);
Elem_80077AA4 *construct_guild_card_tag_array(Elem_80077AA4 *self);
Elem_80077AA4 *construct_guild_card_tag_array(Elem_80077AA4 *self) {
    __construct_array(self, (void *)__ct__16TPlyGuildCardTagFv, 0, 8, 8);
    return self;
}

}
