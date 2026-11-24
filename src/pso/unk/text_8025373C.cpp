#include "pso/item/MagStats.h"
#include "types.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/unk/text_8025373C.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
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


extern const f32 TWindowHelpItem__data_805DCDE4;
s32 fn_8025373C(TWindowHelpItem *self) {
    MagStats mag;
    Entry_8025373C *help;
    Entry_8025373C *panel;
    Entry_8025373C *bar;
    Entry_8025373C *num;
    s32 count;
    mag.init();
    TItemData::deserialize_mag(self->active_item, &mag);
    help = (Entry_8025373C *)self->get_array_entry(0);
    panel = (Entry_8025373C *)self->get_array_entry(0xF);
    count = TWindowHelpItem__sub_80255DDC(help);
    num = (Entry_8025373C *)self->get_array_entry(4);
    bar = (Entry_8025373C *)self->get_array_entry(5);
    if (num->value < mag.get_def_level()) {
        num->value++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        count++;
        ((VEntry_8025373C *)bar)->m3();
    }
    num = (Entry_8025373C *)self->get_array_entry(7);
    bar = (Entry_8025373C *)self->get_array_entry(8);
    if (num->value < mag.get_pow_level()) {
        num->value++;
        count++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        ((VEntry_8025373C *)bar)->m3();
    }
    num = (Entry_8025373C *)self->get_array_entry(0xA);
    bar = (Entry_8025373C *)self->get_array_entry(0xB);
    if (num->value < mag.get_dex_level()) {
        num->value++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        count++;
        ((VEntry_8025373C *)bar)->m3();
    }
    num = (Entry_8025373C *)self->get_array_entry(0xD);
    bar = (Entry_8025373C *)self->get_array_entry(0xE);
    if (num->value < mag.get_mind_level()) {
        num->value++;
        bar->timer = TWindowHelpItem__data_805DCDE4;
        count++;
        ((VEntry_8025373C *)bar)->m3();
    }
    self->update_mag_status_gauges();
    if (count != TWindowHelpItem__sub_80255DDC(help)) {
        ((TWindowHelpItem *)help)->set_flag4_and_field1c(count);
        ((TWindowHelpItem *)help)->set_flag0_bit2();
        ((TWindowSubStatusDisp *)panel)->clear_visible_flag();
        return 1;
    }
    return 0;
}

