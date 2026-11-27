#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "types.h"
#include "pso/ui/window/TWindowSubComCard_CardSlots.h"
#include "pso/ui/chat/ChatShortcuts.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_Accessors.h"
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


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

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
    m_items[index].clear();
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
Pso3CharacterFile &Pso3CharacterFile::operator=(Pso3CharacterFile &from) {
    Pso3CharacterFileSlot *d;
    Pso3CharacterFileSlot *s;
    checksum = from.checksum;
    d = slots;
    s = from.slots;
    do {
        copy_character_file_slot(d, s);
        d++;
        s++;
    } while (d < &slots[7]);
    tail = from.tail;
    blk = from.blk;
    cipher_seed = from.cipher_seed;
    return *this;
}

Pso3CharacterFileSlot *copy_character_file_slot(Pso3CharacterFileSlot *to, Pso3CharacterFileSlot *from) {
    to->chardata = from->chardata;
    to->record = from->record;
    __memcpy(&to->copy_stamp, &from->copy_stamp, sizeof(to->copy_stamp));
    to->pad_39B0 = from->pad_39B0;
    return to;
}

Pso3CharacterSaveRecord &Pso3CharacterSaveRecord::operator=(Pso3CharacterSaveRecord &source) {
    Pso3SaveRecordView *d = (Pso3SaveRecordView *)this;
    Pso3SaveRecordView *s = (Pso3SaveRecordView *)&source;
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
    d->padding = s->padding;
    d->death_count = s->death_count;
    d->bank_item_count = s->bank_item_count;
    d->bank_meseta = s->bank_meseta;
    d->items[0] = s->items[0];
    d->items[1] = s->items[1];
    d->items[2] = s->items[2];
    d->items[3] = s->items[3];
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
    d->settings = s->settings;
    d->split_screen_battle = s->split_screen_battle;
    d->tail = s->tail;
    return *this;
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
extern "C" {

// The generated GuildCardEntry constructor (emitted in TWindowSubComCard_CardSlots.cpp).
void *__ct__14GuildCardEntryFv(void *card);
}
void*TAdSinglePlyChrSelectGC::init_guild_card_tag() { __ct__14GuildCardEntryFv(this); return this; }
void TPlyInventoryItem::clear_equipped() { m_flags &= ~8; }

void TPlyInventoryItem::clear() {
    m_present[0] = 0;
    m_present[1] = -1;
    m_flags = 0;
    m_data.init();
}

s32 TItemData::is_unit() {
    bool result = false;
    if (data1.data_u8[0] == 1 && data1.data_u8[1] == 3) {
        result = true;
    }
    return result;
}
