#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "types.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyCharData_8007214C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_80202A68.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TItemData.h"

struct Ent_80202B38 { s32 a; s32 b; s32 c[5]; };

struct Obj_80202B38 { s32 hdr; Ent_80202B38 e[1]; };

struct Ent_80202B1C { s32 a; s32 b; s32 c[5]; };

struct Obj_80202B1C { s32 hdr; Ent_80202B1C e[1]; };

struct Ent_80202B4C { s32 a; s32 b; s32 c[5]; };

struct Obj_80202B4C { s32 hdr; Ent_80202B4C e[1]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
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


struct Elem_80202DD4 { u8 data[0x54]; };

struct S_80202DD4 {
    s32 f0, f4, f8, fC, f10, f14;
    B1C_80202DD4 b18;
    B10_80202DD4 b34;
    B400_80202DD4 b44;
    s32 f444, f448, f44C;
    BankItemRecord items[4];
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
s32 *TAdSinglePlyChrSelectGC__sub_80202B38(Obj_80202B38 *self, s32 i);
Ent_80202B1C *TAdSinglePlyChrSelectGC__sub_80202B1C(Obj_80202B1C *self, s32 i);
void __construct_array(void *, void *, void *, int, int);
Pso3CharacterFile *copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(Pso3CharacterFile *arg0, Pso3CharacterFile *arg1);
void copy_player_data__9TProtocolFPvPv();

s32 TAdSinglePlyChrSelectGC__sub_80202A68(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x194AC);
}

}

Pso3CharacterFile::~Pso3CharacterFile() {}

extern "C" {

Pso3CharacterFileSlot::~Pso3CharacterFileSlot() {}

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
        *(s32 *)active_character_save_record |= arg0;
    }
}

saddr TAdSinglePlyChrSelectGC::get_instance() {  return (saddr)card_character_save_buffer; }

void TAdSinglePlyChrSelectGC::set_player_index(int a0) { card_load_sequence_state = a0; }

void TAdSinglePlyChrSelectGC::set_save_slot(int a0) { chr_select_save_slot = a0; }

void TAdSinglePlyChrSelectGC::clear_flags(s32 arg0) {
    if ((s32 *) active_character_save_record != NULL) {
        *(s32 *)active_character_save_record &= ~arg0;
    }
}

s32 TAdSinglePlyChrSelectGC::check_flag(s32 arg0) {
    if ((s32 *) active_character_save_record != NULL) {
        return (u8)((u8) ((*(s32 *)active_character_save_record & arg0) != 0));
    }
    return (u8)(0U);
}

void TAdSinglePlyChrSelectGC::set_state(int a0) { chr_select_scene_state = a0; }

void CharacterSelectionRequest::clear_slot_lists() {
    s32 i;
    count = 0;
    for (i = 0; i < 4; i++) {
        card_slots[i] = -1;
        player_ids[i] = -1;
    }
}

void TAdSinglePlyChrSelectGC::set_chr_select_state(int a0) { chr_select_game_mode = a0; }

void CharacterSelectionRequest::reset_slot_lists() {
    s32 i;
    count = 0;
    for (i = 0; i < 4; i++) {
        card_slots[i] = -1;
        player_ids[i] = -1;
    }
}

Pso3CharacterFile *copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(Pso3CharacterFile *arg0, Pso3CharacterFile *arg1) {
    Pso3CharacterFileSlot *d;
    Pso3CharacterFileSlot *s;
    arg0->checksum = arg1->checksum;
    d = arg0->slots;
    s = arg1->slots;
    do {
        TAdSinglePlyChrSelectGC__sub_80202D7C(d, s);
        d++;
        s++;
    } while (d < &arg0->slots[7]);
    arg0->tail = arg1->tail;
    arg0->blk = arg1->blk;
    arg0->cipher_seed = arg1->cipher_seed;
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
    d->items[0] = s->items[0];
    d->items[1] = s->items[1];
    d->items[2] = s->items[2];
    d->items[3] = s->items[3];
    d->b4B0 = s->b4B0;
    d->b540 = s->b540;
    p = d->elems;
    q = s->elems;
    do {
        TAdSinglePlyChrSelectGC__sub_80076D9C((saddr)p, (saddr)q);
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

BankItemRecord &BankItemRecord::operator=(BankItemRecord &src) {
    item.copy_from(&src.item);
    amount = src.amount;
    used = src.used;
    return *this;
}

Pso3CharacterFile::Pso3CharacterFile() {}

Pso3CharacterFileSlot::Pso3CharacterFileSlot() {}

Pso3CharacterSaveRecord::Pso3CharacterSaveRecord() {
    ((TAdSinglePlyChrSelectGC *)guild_card)->init_guild_card_tag();
}

void*TAdSinglePlyChrSelectGC::init_guild_card_tag() { init_guild_card_tag__17TWindowSubComCardFi((saddr)this); return this; }
void TAdSinglePlyChrSelectGC__sub_80203210(void* p) { *(u32*)((char*)p + 0x4) &= 0xfffffff7; }

void TAdSinglePlyChrSelectGC::clear_inventory_slot() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)&this->m_name = 0;
    *(s8 *)((s8 *)arg0 + 1) = -1;
    *(s32 *)&this->m_flags = 0;
    ((TItemData *)((u8 *)&this->m_prev))->init();
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
