#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "types.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_80202A68.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TItemData.h"
#include "pso/player/TPlyInventory.h"

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



struct S_80202DD4 {
    s32 flags, creation_seconds, magic, play_time, card_window_flags, save_count;
    B1C_80202DD4 account;
    B10_80202DD4 user_name;
    B400_80202DD4 pad_44;
    s32 death_count, bank_item_count, bank_meseta;
    BankItemRecord bank_items[4];
    B90_80202DD4 guild_card;
    B420_80202DD4 symbol_chat_presets;
    ChatShortcut chat_shortcuts[20];
    BAC_80202DD4 short_mail_text;
    BAC_80202DD4 info_board_text;
    B1C_80202DD4 online_battle;
    B100_80202DD4 challenge;
    B28_80202DD4 short_list_order;
    B28_80202DD4 choice_search;
    BC0_80202DD4 pad_12B4;
    B1C_80202DD4 split_screen_battle;
    B21FC_80202DD4 pad_1390;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct S_801FE010;
struct B8_801FDFB8 { u32 w[2]; };

struct P_801FDFB8 { TPlyCharData char_data; u8 a[0x39A8 - 0x41C]; B8_801FDFB8 copy_stamp; s32 f2794; };


s32 Pso3CharacterFile::get_cipher_seed() {
    return cipher_seed;
}


Pso3CharacterFile::~Pso3CharacterFile() {}

Pso3CharacterFileSlot::~Pso3CharacterFileSlot() {}

TPlyInventoryItem *TPlyInventory::get_item(s32 index) {
    return &m_items[index];
}

u8 TPlyInventory::get_item_count() { return m_num_items; }

TItemData *TPlyInventory::get_item_data(s32 index) {
    return &m_items[index].m_data;
}

void TPlyInventory::clear_item(s32 index) {
    ((TAdSinglePlyChrSelectGC *)(&m_items[index]))->clear_inventory_slot();
}

int TAdSinglePlyChrSelectGC::get_selection() {  return TAdSinglePlyChrSelectGC::selection_index; }

void TAdSinglePlyChrSelectGC::set_global_flags(s32 flags) {
    if (active_character_save_record != NULL) {
        active_character_save_record->flags |= flags;
    }
}

CharacterFile *TAdSinglePlyChrSelectGC::get_instance() { return card_character_save_buffer; }

void TAdSinglePlyChrSelectGC::set_player_index(int a0) { card_load_sequence_state = a0; }

void TAdSinglePlyChrSelectGC::set_save_slot(int a0) { chr_select_save_slot = a0; }

void TAdSinglePlyChrSelectGC::clear_flags(s32 flags) {
    if (active_character_save_record != NULL) {
        active_character_save_record->flags &= ~flags;
    }
}

s32 TAdSinglePlyChrSelectGC::check_flag(s32 flags) {
    if (active_character_save_record != NULL) {
        return (u8)((u8) ((active_character_save_record->flags & flags) != 0));
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
extern "C" {

Pso3CharacterFile *copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(Pso3CharacterFile *to, Pso3CharacterFile *from) {
    Pso3CharacterFileSlot *d;
    Pso3CharacterFileSlot *s;
    to->checksum = from->checksum;
    d = to->slots;
    s = from->slots;
    do {
        TAdSinglePlyChrSelectGC__sub_80202D7C(d, s);
        d++;
        s++;
    } while (d < &to->slots[7]);
    to->tail = from->tail;
    to->blk = from->blk;
    to->cipher_seed = from->cipher_seed;
    return to;
}

#define dst ((P_801FDFB8 *)a0)
#define src ((P_801FDFB8 *)a1)
void *TAdSinglePlyChrSelectGC__sub_80202D7C(void *a0, void *a1) {
    dst->char_data = src->char_data;
    ((TAdSinglePlyChrSelectGC *)((S_801FE010 *)dst->a))->copy_character_data((u8 *)((S_801FE010 *)src->a));
    dst->copy_stamp = src->copy_stamp;
    dst->f2794 = src->f2794;
    return a0;
}
#undef dst
#undef src

u8 *TAdSinglePlyChrSelectGC::copy_character_data(u8 *source) {
    S_80202DD4 *d = (S_80202DD4 *)this;
    S_80202DD4 *s = (S_80202DD4 *)source;
    ChatShortcut *p;
    ChatShortcut *q;
    d->flags = s->flags;
    d->creation_seconds = s->creation_seconds;
    d->magic = s->magic;
    d->play_time = s->play_time;
    d->card_window_flags = s->card_window_flags;
    d->save_count = s->save_count;
    d->account = s->account;
    d->user_name = s->user_name;
    d->pad_44 = s->pad_44;
    d->death_count = s->death_count;
    d->bank_item_count = s->bank_item_count;
    d->bank_meseta = s->bank_meseta;
    d->bank_items[0] = s->bank_items[0];
    d->bank_items[1] = s->bank_items[1];
    d->bank_items[2] = s->bank_items[2];
    d->bank_items[3] = s->bank_items[3];
    d->guild_card = s->guild_card;
    d->symbol_chat_presets = s->symbol_chat_presets;
    p = d->chat_shortcuts;
    q = s->chat_shortcuts;
    do {
        *p = *q;
        p++;
        q++;
    } while (p < d->chat_shortcuts + 20);
    d->short_mail_text = s->short_mail_text;
    d->info_board_text = s->info_board_text;
    d->online_battle = s->online_battle;
    d->challenge = s->challenge;
    d->short_list_order = s->short_list_order;
    d->choice_search = s->choice_search;
    d->pad_12B4 = s->pad_12B4;
    d->split_screen_battle = s->split_screen_battle;
    d->pad_1390 = s->pad_1390;
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

// The generated GuildCardEntry constructor (emitted in TWindowSubComCard_8007A810.cpp).
void *__ct__14GuildCardEntryFv(void *card);
}
void*TAdSinglePlyChrSelectGC::init_guild_card_tag() { __ct__14GuildCardEntryFv(this); return this; }
void clear_equipped_flag(void* item) { *(u32*)((char*)item + 0x4) &= 0xfffffff7; }

void TAdSinglePlyChrSelectGC::clear_inventory_slot() {
    *(s8 *)&this->m_name = 0;
    *(s8 *)((s8 *)this + 1) = -1;
    *(s32 *)&this->m_flags = 0;
    ((TItemData *)((u8 *)&this->m_prev))->init();
}

int is_unit_item_data(void *item) {
    int is_unit;
    is_unit = 0;
    if (((u8) *(u8 *)((s8 *)item + 0x0) == 1) && ((u8) *(u8 *)((s8 *)item + 0x1) == 3)) {
        is_unit = 1;
    }
    return (u8)is_unit;
}
