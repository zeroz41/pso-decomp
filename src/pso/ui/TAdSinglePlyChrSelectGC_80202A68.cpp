#include "types.h"
#include "pso/misc/TWindowSubComCard_8007A810.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/misc/TPlyCharData.h"
#include "pso/misc/TPlyCharData_8007214C.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_80202A68.h"
#include "pso/system/memory.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Ent_80202B38 { s32 a; s32 b; s32 c[5]; };

struct Obj_80202B38 { s32 hdr; Ent_80202B38 e[1]; };

struct Ent_80202B1C { s32 a; s32 b; s32 c[5]; };

struct Obj_80202B1C { s32 hdr; Ent_80202B1C e[1]; };

struct Ent_80202B4C { s32 a; s32 b; s32 c[5]; };

struct Obj_80202B4C { s32 hdr; Ent_80202B4C e[1]; };

struct Obj_80202C08 { s32 a[4]; s32 b[4]; s32 n; };

struct Obj_80202C3C { s32 a[4]; s32 b[4]; s32 n; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Slot_80202C68 { u8 data[0x39B4]; };

struct Words_80202C68 { u32 w[32]; };

struct Blk_80202C68 { u32 a; Words_80202C68 b; };

struct Pair_80202C68 { u32 a; u32 b; };

struct Tail_80202C68 { Pair_80202C68 p0, p1, p2, p3, p4, p5, p6; };

struct Save_80202C68 {
    s32 hdr;
    Slot_80202C68 slots[7];
    Tail_80202C68 tail;
    Blk_80202C68 blk;
    s32 f194AC;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct B1C_80202DD4 { u32 w[7]; };

struct B10_80202DD4 { u32 w[4]; };

struct B400_80202DD4 { u32 w[0x100]; };

struct B90_80202DD4 { u32 w[0x24]; };

struct B420_80202DD4 { u32 w[0x108]; };

struct BAC_80202DD4 { u32 w[0x2B]; };

struct B100_80202DD4 { u32 w[0x40]; };

struct B28_80202DD4 { u32 w[0xA]; };

struct BC0_80202DD4 { u32 w[0x30]; };

struct B21FC_80202DD4 { u32 w[0x87F]; };

struct Item_80202DD4 { u8 data[0x18]; };

struct Elem_80202DD4 { u8 data[0x54]; };

struct S_80202DD4 {
    s32 f0, f4, f8, fC, f10, f14;
    B1C_80202DD4 b18;
    B10_80202DD4 b34;
    B400_80202DD4 b44;
    s32 f444, f448, f44C;
    Item_80202DD4 items[4];
    B90_80202DD4 b4B0;
    B420_80202DD4 b540;
    Elem_80202DD4 elems[20];
    BAC_80202DD4 bFF0;
    BAC_80202DD4 b109C;
    B1C_80202DD4 b1148;
    B100_80202DD4 b1164;
    B28_80202DD4 b1264;
    B28_80202DD4 b128C;
    BC0_80202DD4 b12B4;
    B1C_80202DD4 b1374;
    B21FC_80202DD4 b1390;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct S_801FE010;
struct B8_801FDFB8 { u32 w[2]; };

struct P_801FDFB8 { u8 pad[0x41C]; u8 a[0x39A8 - 0x41C]; B8_801FDFB8 f278C; s32 f2794; };

extern "C" {
s32 __destroy_arr(s32, s32 *, s32, s32);
extern int card_character_save_buffer;
extern s32 *active_character_save_record;
extern int TAdSinglePlyChrSelectGC__selection_index;
void init__9TItemDataFv(void *);
s32 *TAdSinglePlyChrSelectGC__sub_80202B38(Obj_80202B38 *self, s32 i);
Ent_80202B1C *TAdSinglePlyChrSelectGC__sub_80202B1C(Obj_80202B1C *self, s32 i);
void __construct_array(void *, void *, void *, int, int);
void *TAdSinglePlyChrSelectGC__sub_802115C0(void *p);
Save_80202C68 *copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(Save_80202C68 *arg0, Save_80202C68 *arg1);
void copy_player_data__9TProtocolFPvPv();
int copy_from__8ItemDataFP8ItemData(void*);

s32 TAdSinglePlyChrSelectGC__sub_80202A68(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x194AC);
}

s32 destroy_chardata_array__23TAdSinglePlyChrSelectGCFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr(arg0 + 4, (s32 *)TAdSinglePlyChrSelectGC::free_chardata, 0x39b4, 7);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

s32 TAdSinglePlyChrSelectGC::free_chardata(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __dt__12TPlyCharDataFv(arg0, -1);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

Ent_80202B1C *TAdSinglePlyChrSelectGC__sub_80202B1C(Obj_80202B1C *self, s32 i) {
    return &self->e[i];
}

u8 TAdSinglePlyChrSelectGC__sub_80202B30(void* p) { return *(u8*)((char*)p + 0x0); }

s32 *TAdSinglePlyChrSelectGC__sub_80202B38(Obj_80202B38 *self, s32 i) {
    return self->e[i].c;
}

void TAdSinglePlyChrSelectGC::clear_inventory_slot_by_index(s32 i) {
    Obj_80202B4C *self = (Obj_80202B4C *)this;
    ((TAdSinglePlyChrSelectGC *)(&self->e[i]))->clear_inventory_slot();
}

int TAdSinglePlyChrSelectGC::get_selection() {  return TAdSinglePlyChrSelectGC__selection_index; }

void TAdSinglePlyChrSelectGC::set_global_flags(s32 arg0) {
    if ((s32 *) active_character_save_record != NULL) {
        *active_character_save_record |= arg0;
    }
}

int TAdSinglePlyChrSelectGC::get_instance() {  return card_character_save_buffer; }

    extern int card_load_sequence_state;
void TAdSinglePlyChrSelectGC::set_player_index(int a0) { card_load_sequence_state = a0; }

    extern int chr_select_save_slot;
void TAdSinglePlyChrSelectGC::set_save_slot(int a0) { chr_select_save_slot = a0; }

void TAdSinglePlyChrSelectGC::clear_flags(s32 arg0) {
    if ((s32 *) active_character_save_record != NULL) {
        *active_character_save_record &= ~arg0;
    }
}

u8 TAdSinglePlyChrSelectGC::check_flag(s32 arg0) {
    if ((s32 *) active_character_save_record != NULL) {
        return (u8) ((*active_character_save_record & arg0) != 0);
    }
    return 0U;
}

    extern int lbl_805D5FA0;
void TAdSinglePlyChrSelectGC::set_state(int a0) { lbl_805D5FA0 = a0; }

    extern int chr_select_game_mode;

void TAdSinglePlyChrSelectGC::clear_slot_lists() {
    Obj_80202C08 *self = (Obj_80202C08 *)this;
    s32 i;
    this->m_20 = 0;
    for (i = 0; i < 4; i++) {
        self->a[i] = -1;
        self->b[i] = -1;
    }
}

void TAdSinglePlyChrSelectGC::set_chr_select_state(int a0) { chr_select_game_mode = a0; }

void TAdSinglePlyChrSelectGC::reset_slot_lists() {
    Obj_80202C3C *self = (Obj_80202C3C *)this;
    s32 i;
    this->m_20 = 0;
    for (i = 0; i < 4; i++) {
        self->a[i] = -1;
        self->b[i] = -1;
    }
}

Save_80202C68 *copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(Save_80202C68 *arg0, Save_80202C68 *arg1) {
    Slot_80202C68 *d;
    Slot_80202C68 *s;
    arg0->hdr = arg1->hdr;
    d = arg0->slots;
    s = arg1->slots;
    do {
        TAdSinglePlyChrSelectGC__sub_80202D7C(d, s);
        d++;
        s++;
    } while (d < &arg0->slots[7]);
    arg0->tail = arg1->tail;
    arg0->blk = arg1->blk;
    arg0->f194AC = arg1->f194AC;
    return arg0;
}

#define arg0 ((P_801FDFB8 *)a0)
#define arg1 ((P_801FDFB8 *)a1)
void *TAdSinglePlyChrSelectGC__sub_80202D7C(void *a0, void *a1) {
    copy_player_data__9TProtocolFPvPv();
    ((TAdSinglePlyChrSelectGC *)((S_801FE010 *)arg0->a))->copy_character_data((u8 *)((S_801FE010 *)arg1->a));
    arg0->f278C = arg1->f278C;
    arg0->f2794 = arg1->f2794;
    return a0;
}
#undef arg0
#undef arg1

u8 *TAdSinglePlyChrSelectGC::copy_character_data(u8 *arg1) {
    S_80202DD4 *d = (S_80202DD4 *)this;
    S_80202DD4 *s = (S_80202DD4 *)arg1;
    Elem_80202DD4 *p;
    Elem_80202DD4 *q;
    d->f0 = s->f0;
    d->f4 = s->f4;
    d->f8 = s->f8;
    d->fC = s->fC;
    d->f10 = s->f10;
    d->f14 = s->f14;
    d->b18 = s->b18;
    d->b34 = s->b34;
    d->b44 = s->b44;
    d->f444 = s->f444;
    d->f448 = s->f448;
    d->f44C = s->f44C;
    ((TAdSinglePlyChrSelectGC *)(&d->items[0]))->copy_item_data(&s->items[0]);
    ((TAdSinglePlyChrSelectGC *)(&d->items[1]))->copy_item_data(&s->items[1]);
    ((TAdSinglePlyChrSelectGC *)(&d->items[2]))->copy_item_data(&s->items[2]);
    ((TAdSinglePlyChrSelectGC *)(&d->items[3]))->copy_item_data(&s->items[3]);
    d->b4B0 = s->b4B0;
    d->b540 = s->b540;
    p = d->elems;
    q = s->elems;
    do {
        TAdSinglePlyChrSelectGC__sub_80076D9C((s32)p, (s32)q);
        p++;
        q++;
    } while (p < d->elems + 20);
    d->bFF0 = s->bFF0;
    d->b109C = s->b109C;
    d->b1148 = s->b1148;
    d->b1164 = s->b1164;
    d->b1264 = s->b1264;
    d->b128C = s->b128C;
    d->b12B4 = s->b12B4;
    d->b1374 = s->b1374;
    d->b1390 = s->b1390;
    return ((u8 *)this);
}

void*TAdSinglePlyChrSelectGC::copy_item_data(void* a1) { copy_from__8ItemDataFP8ItemData(this); *(short *)&this->m_down = *(short*)((char*)a1 + 0x14); *(short*)((char*)this + 0x16) = *(short*)((char*)a1 + 0x16); return this; }

u8 *TAdSinglePlyChrSelectGC::construct_chardata_array() {
    __construct_array(((u8 *)this) + 4, (void *)TAdSinglePlyChrSelectGC__sub_80203158, (void *)TAdSinglePlyChrSelectGC::free_chardata, 0x39B4, 7);
    return ((u8 *)this);
}

void* TAdSinglePlyChrSelectGC__sub_80203158(void* p) { __ct__12TPlyCharDataFv((s32)p); TAdSinglePlyChrSelectGC__sub_80203190((u8 *)((void*)((char*)p + 0x41c))); return p; }

u8 *TAdSinglePlyChrSelectGC__sub_80203190(u8 *arg0) {
    __construct_array(arg0 + 0x450, (void *)TAdSinglePlyChrSelectGC__sub_802115C0, 0, 0x18, 4);
    ((TAdSinglePlyChrSelectGC *)(arg0 + 0x4B0))->init_guild_card_tag();
    return arg0;
}

void*TAdSinglePlyChrSelectGC::init_guild_card_tag() { init_guild_card_tag__17TWindowSubComCardFi((s32)this); return this; }
void TAdSinglePlyChrSelectGC__sub_80203210(void* p) { *(u32*)((char*)p + 0x4) &= 0xfffffff7; }

void TAdSinglePlyChrSelectGC::clear_inventory_slot() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)&this->m_name = 0;
    *(s8 *)((s8 *)arg0 + 1) = -1;
    *(s32 *)&this->m_flags = 0;
    init__9TItemDataFv((u8 *)&this->m_prev);
}

int fn_8020325C(void *arg0) {
    int var_r4;
    var_r4 = 0;
    if (((u8) *(u8 *)((s8 *)arg0 + 0x0) == 1) && ((u8) *(u8 *)((s8 *)arg0 + 0x1) == 3)) {
        var_r4 = 1;
    }
    return (u8)var_r4;
}

}
