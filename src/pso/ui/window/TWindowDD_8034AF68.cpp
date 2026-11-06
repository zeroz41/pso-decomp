#include "types.h"
#include "pso/ui/window/TWindowDD_8034AF68.h"
#include "pso/ui/window/TWindowDD.h"

struct RecoveredGlobal_8034B008_lbl_80478B78 {
    s32 value;
    u8 remaining[0x2C];
};

struct H_8034AF68 { u32 f0; s32 f4; };

struct G_8034AF68 {
    s16 ids[16];
    H_8034AF68 *a;
    H_8034AF68 *b;
    u32 a0;
    u32 b0;
    s32 n;
};

struct Ent_8034B050 { s32 *list; s32 count; s32 result; };

extern RecoveredGlobal_8034B008_lbl_80478B78 word_select_type_state_table;
extern G_8034AF68 lbl_804F0070;
extern H_8034AF68 *TWindowDD__ws_data_base;
extern H_8034AF68 *TWindowDD__ws_data_table;
extern Ent_8034B050 lbl_804F0040[4];
extern s32 TWindowDD__window_mode;
extern s8 lbl_805D6E90;
extern s32 lbl_805DFD84;
extern s32 lbl_805DFD88;
extern s32 lbl_805DFD8C;
extern s32 lbl_805DFD90;
typedef char RecoveredGlobal_8034B008_lbl_80478B78_size[sizeof(RecoveredGlobal_8034B008_lbl_80478B78) == 0x30 ? 1 : -1];

void TWindowDD::init_ws_data_tables() {
    H_8034AF68 *a = TWindowDD__ws_data_base;
    H_8034AF68 *b;
    s32 i;
    s32 x;
    s32 y;
    if (a == NULL || (b = TWindowDD__ws_data_table) == NULL) {
        return;
    }
    for (i = 0; i < 16; i++) {
        lbl_804F0070.ids[i] = -1;
    }
    lbl_804F0070.a = a;
    lbl_804F0070.b = b;
    lbl_804F0070.a0 = a->f0;
    lbl_804F0070.b0 = b->f0;
    if (lbl_804F0070.a0 == 0 || lbl_804F0070.b0 == 0) {
        return;
    }
    x = a->f4;
    y = b->f4;
    if (x < 1 || y < 1 || x != y) {
        return;
    }
    lbl_804F0070.n = x;
}

s32 TWindowDD__sub_8034B008(s32 arg0, s32 arg1) {
    return *(s32 *)((s8 *)((u8 *)(((u8 *)&word_select_type_state_table.value + (TWindowDD::lookup_item_category((s32)arg1) * 8))) + (arg0 * 4)) + 0);
}
s32 TWindowDD::lookup_item_category(s32 arg0) {
    s32 r;
    s32 i;
    s32 j;
    Ent_8034B050 *e;
    s32 *list;
    if (lbl_805D6E90 == 0) {
        lbl_804F0040[0].count = lbl_805DFD84;
        lbl_804F0040[1].count = lbl_805DFD88;
        lbl_804F0040[2].count = lbl_805DFD8C;
        lbl_804F0040[3].count = lbl_805DFD90;
        lbl_805D6E90 = 1;
    }
    r = 5;
    for (i = 0; i < 4; i++) {
        e = &lbl_804F0040[i];
        list = e->list;
        for (j = 0; j < e->count; j++) {
            if (arg0 == list[j]) {
                r = e->result;
                break;
            }
        }
        if (r != 5) {
            break;
        }
    }
    if (r == 2 && TWindowDD__window_mode == 0) {
        r = 1;
    }
    return r;
}
