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
struct BattleRecordBlock { u32 w[7]; };

struct CardAccountBlock { u32 w[7]; };

struct CardUserNameBlock { u32 w[4]; };

struct CardPaddingBlock { u32 w[0x100]; };

struct GuildCardBlock { u32 w[0x24]; };

struct SymbolChatBlock { u32 w[0x108]; };

struct MailTextBlock { u32 w[0x2B]; };

struct ChallengeBlock { u32 w[0x40]; };

struct ListSettingsBlock { u32 w[0xA]; };

struct Pso3SettingsBlock { u32 w[0x30]; };

struct Pso3TailBlock { u32 w[0x87F]; };



struct Pso3SaveRecordView {
    s32 flags, creation_seconds, magic, play_time, card_window_flags, save_count;
    CardAccountBlock account;
    CardUserNameBlock user_name;
    CardPaddingBlock padding;
    s32 death_count, bank_item_count, bank_meseta;
    BankItemRecord items[4];
    GuildCardBlock guild_card;
    SymbolChatBlock symbol_chat_presets;
    ChatShortcut chat_shortcuts[20];
    MailTextBlock short_mail_text;
    MailTextBlock info_board_text;
    BattleRecordBlock online_battle;
    ChallengeBlock challenge;
    ListSettingsBlock short_list_order;
    ListSettingsBlock choice_search;
    Pso3SettingsBlock settings;
    BattleRecordBlock split_screen_battle;
    Pso3TailBlock tail;
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
    Pso3SaveRecordView *d = (Pso3SaveRecordView *)this;
    Pso3SaveRecordView *s = (Pso3SaveRecordView *)source;
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
