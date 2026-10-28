#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/TUnk_804F0C48.h"
#include "pso/item/TItemProShield.h"
#include "pso/player/TObjPlayer.h"

struct D_803501BC { u8 a, b, c; u8 rest[0x14 - 3]; };

struct E_803501BC { u8 a, b, c; u8 w; };

struct T_803501BC { s32 n; E_803501BC *e; };

extern "C" {
}
extern "C" {
T_803501BC *get_item_pmt_entry__10TObjPlayerFUc(u8);
s32 rand(void);
extern const f32 lbl_805DFE28;
extern const f32 lbl_805DFE2C;
void TUnk_804F0C48::vfunc_44() {
    T_803501BC *t;
    t = get_item_pmt_entry__10TObjPlayerFUc(this->get_item_index());
    if (t != NULL) {
        s32 r = (s32)(lbl_805DFE28 * (lbl_805DFE2C * (f32)rand()));
        E_803501BC *e = t->e;
        s32 i;
        for (i = t->n; i != 0; i++) {
            if ((u8)r < e->w) {
                D_803501BC d;
                d.a = e->a;
                d.b = e->b;
                d.c = e->c;
                replace_item_with_new_code((const TItemData *)&d, (TItem *)this);
                return;
            }
            r -= e->w;
            e++;
        }
    }
    consume_item_by_id(this->get_item_id());
}
}
