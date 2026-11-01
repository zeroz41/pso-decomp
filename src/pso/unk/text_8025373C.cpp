#include "pso/item/MagStats.h"
#include "types.h"
#include "pso/misc/TWindowHelpItem_80255AB4.h"
#include "pso/unk/text_8025373C.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
struct Base_8025373C { char pad[4]; };

struct VEntry_8025373C : Base_8025373C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
};

struct Entry_8025373C {
    u8 pad0[4];
    void *vt;
    u8 pad8[0x20 - 0x8];
    s32 value;
    f32 timer;
};

struct Mag_8025373C {
    u8 data[16];
};

extern "C" {
void deserialize_mag__9TItemDataFPvPv(s32, Mag_8025373C *);
Entry_8025373C *get_array_entry__11TWindowBaseFi(void *, s32);
extern const f32 TWindowHelpItem__data_805DCDE4;
s32 fn_8025373C(u8 *self) {
    Mag_8025373C mag;
    Entry_8025373C *help;
    Entry_8025373C *panel;
    Entry_8025373C *bar;
    Entry_8025373C *num;
    s32 count;
    ((MagStats *)(&mag))->init();
    deserialize_mag__9TItemDataFPvPv(*(s32 *)(self + 0x68), &mag);
    help = get_array_entry__11TWindowBaseFi(self, 0);
    panel = get_array_entry__11TWindowBaseFi(self, 0xF);
    count = TWindowHelpItem__sub_80255DDC(help);
    num = get_array_entry__11TWindowBaseFi(self, 4);
    bar = get_array_entry__11TWindowBaseFi(self, 5);
    if (num->value < ((MagStats *)(&mag))->get_def_level()) {
        num->value++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        count++;
        ((VEntry_8025373C *)bar)->m3();
    }
    num = get_array_entry__11TWindowBaseFi(self, 7);
    bar = get_array_entry__11TWindowBaseFi(self, 8);
    if (num->value < ((MagStats *)(&mag))->get_pow_level()) {
        num->value++;
        count++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        ((VEntry_8025373C *)bar)->m3();
    }
    num = get_array_entry__11TWindowBaseFi(self, 0xA);
    bar = get_array_entry__11TWindowBaseFi(self, 0xB);
    if (num->value < ((MagStats *)(&mag))->get_dex_level()) {
        num->value++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        count++;
        ((VEntry_8025373C *)bar)->m3();
    }
    num = get_array_entry__11TWindowBaseFi(self, 0xD);
    bar = get_array_entry__11TWindowBaseFi(self, 0xE);
    if (num->value < ((MagStats *)(&mag))->get_mind_level()) {
        num->value++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        count++;
        ((VEntry_8025373C *)bar)->m3();
    }
    ((TItemData *)self)->update_mag_status_gauges();
    if (count != TWindowHelpItem__sub_80255DDC(help)) {
        ((TWindowHelpItem *)help)->set_flag4_and_field1c(count);
        ((TWindowHelpItem *)help)->set_flag0_bit2();
        ((TWindowSubStatusDisp *)panel)->clear_visible_flag();
        return 1;
    }
    return 0;
}

}
