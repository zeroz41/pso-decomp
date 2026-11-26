#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_80202A68_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_80202A68_H

#include "types.h"
#include <stddef.h>
#include "pso/player/TPlyCharData.h"
#include "pso/ui/city/BankItemRecord.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/system/save/CharacterFile.h"

// The save record of a PSO3_CHARACTER slot: the CharacterSaveRecord layout with four bank rows.
struct Pso3CharacterSaveRecord {
    Pso3CharacterSaveRecord();

    s32 flags;
    s32 creation_seconds;
    u32 magic;
    s32 play_time;
    s32 card_window_flags;
    u32 save_count;
    u8 account[0x1C];
    u8 user_name[0x10];
    u8 pad_44[0x444 - 0x44];
    s32 death_count;
    s32 bank_item_count;
    s32 bank_meseta;
    BankItemRecord bank_items[4];
    // Set up by init_guild_card_tag.
    u8 guild_card[0x90];
    SymbolChatPreset symbol_chat_presets[12];
    ChatShortcut chat_shortcuts[20];
    char short_mail_text[0xAC];
    char info_board_text[0xAC];
    BattleRecord online_battle;
    ChallengeRecord challenge;
    s16 short_list_order[0x14];
    ChoiceSearchSelection choice_search[5];
    u8 pad_12B4[0x1374 - 0x12B4];
    BattleRecord split_screen_battle;
    u8 pad_1390[0x358C - 0x1390];
};

LAYOUT_ASSERT(Pso3CharacterSaveRecord_chat_shortcuts, offsetof(Pso3CharacterSaveRecord, chat_shortcuts) == 0x960);
LAYOUT_ASSERT(Pso3CharacterSaveRecord_split_screen_battle, offsetof(Pso3CharacterSaveRecord, split_screen_battle) == 0x1374);
LAYOUT_ASSERT(Pso3CharacterSaveRecord_size, sizeof(Pso3CharacterSaveRecord) == 0x358C);

struct Pso3CharacterFileSlot {
    Pso3CharacterFileSlot();
    ~Pso3CharacterFileSlot();

    TPlyCharData chardata;
    Pso3CharacterSaveRecord record;
    CharacterCopyStamp copy_stamp;
    u8 pad_39B0[0x39B4 - 0x39B0];
};

struct Words_80202C68 { u32 w[32]; };

struct Blk_80202C68 { u32 a; Words_80202C68 b; };

struct Pair_80202C68 { u32 a; u32 b; };

struct Tail_80202C68 { Pair_80202C68 p0, p1, p2, p3, p4, p5, p6; };

// The PSO3_CHARACTER memory card file: seven character slots behind a CRC32.
struct Pso3CharacterFile {
    Pso3CharacterFile();
    ~Pso3CharacterFile();
    // The seed of the cipher over the file, kept in its last word.
    s32 get_cipher_seed();

    s32 checksum;
    Pso3CharacterFileSlot slots[7];
    Tail_80202C68 tail;
    Blk_80202C68 blk;
    // Seeds the cipher over everything before it.
    s32 cipher_seed;
};

LAYOUT_ASSERT(Pso3CharacterFileSlot_record_offset, offsetof(Pso3CharacterFileSlot, record) == 0x41C);
LAYOUT_ASSERT(Pso3CharacterFileSlot_size, sizeof(Pso3CharacterFileSlot) == 0x39B4);
LAYOUT_ASSERT(Pso3CharacterFile_size, sizeof(Pso3CharacterFile) == 0x194B0);

void *copy_character_file_slot(void *a0, void *a1);

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

#endif
