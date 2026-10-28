#include "types.h"
#include "pso/misc/TWindowCtrl.h"
struct Self_8017866C { u8 pad[0x36C]; u8 *items[3]; };

extern "C" {
u16 get_entity_id(void *);
void fn_8017866C(Self_8017866C *self, s32 i, u16 v);
void fn_8017866C(Self_8017866C *self, s32 i, u16 v) {
    if (i < 3) {
        u8 *p = self->items[i];
        if (p != 0) {
            TWindowCtrl::open_balloon(get_entity_id(self), p, 10, v);
        }
    }
}

}
