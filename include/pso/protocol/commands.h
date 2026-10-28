/* PSO main command formats (S_/C_/SC_*).
 *
 * Shared PSO wire-protocol structures for Episode I & II Plus (GameCube / V3).
 * These command/subcommand formats are identical between server and client by
 * definition, so they are safe to use to type the GameCube client decomp's
 * network handlers.
 *
 * Field names and byte offsets are derived from newserv
 * (fuzziqersoftware/newserv), an MIT-licensed PSO server reimplementation, via
 * tools/newserv_match.py. newserv is MIT (Copyright (c) 2024 Martin Michelsen);
 * its LICENSE is bundled at reference/newserv-LICENSE and permits this reuse.
 *
 * The decomp's own integer types (u8/u16/u32/s8/s16/s32/f32 ...) replace
 * newserv's phosg le_/be_ wire-endian wrappers; on the big-endian PowerPC
 * client these are plain scalars. The `size 0xNN` trailer reflects newserv's
 * static_assert/check_struct_size (0 computed-vs-declared mismatches at
 * generation time). V3/GC-relevant structs are kept; BB/DC/Ep3/XB-only
 * variants are skipped.
 *
 * GENERATED — verify offsets against the DOL before relying on a field.
 */

#ifndef PSO_PROTOCOL_COMMANDS_H
#define PSO_PROTOCOL_COMMANDS_H

#include "types.h"
#include "pso/protocol/protocol_types.h"

struct C_ChangeShipOrBlock_A0_A1 {
 u32 player_tag;
 u32 guild_card_number;
 u8 unused[0x10];
};

struct C_CharSaveInfo_DCv2_PC_V3_BB_96 {
 u32 creation_timestamp;
 u32 event_counter;
};

struct C_CharacterData_PC_61_98 {
 u8 inventory[0x34C];
 u8 disp[0xD0];
 struct PlayerRecordsEntry_PC records;
 u8 choice_search_config[0x18];
 u32 blocked_senders[0x1E];
 u32 auto_reply_enabled;
};

struct C_CharacterData_V3_61_98 {
 u8 inventory[0x34C];
 u8 disp[0xD0];
 struct PlayerRecordsEntry_V3 records;
 u8 choice_search_config[0x18];
 char info_board[0xAC];
 u32 blocked_senders[0x1E];
 u32 auto_reply_enabled;
};

struct C_ClientConfig_V3_9F {
 u8 data[0x20];
};

struct C_ExecuteCodeResult_B3 {
 u32 return_value;
 u32 checksum;
};

struct C_FileInformation_Patch_0F {
 u32 request_id;
 u32 checksum;
 u32 size;
};

struct C_GBAGameRequest_V3_D7 {
 char filename[0x10];
};

struct C_GuildCardChecksum_01E8 {
 u32 checksum;
 u32 unused;
};

struct C_GuildCardSearch_40 {
 u32 player_tag;
 u32 searcher_guild_card_number;
 u32 target_guild_card_number;
};

struct C_LegacyLogin_PC_V3_03 {
 u64 hardware_id;
 u32 sub_version;
 u8 is_extended;
 u8 language[0x1];
 u16 unused;
 char serial_number2[0x10];
 char access_key2[0x10];
};

struct C_LegacyLogin_PC_V3_04 {
 u64 hardware_id;
 u32 sub_version;
 u8 is_extended;
 u8 language[0x1];
 u16 unused;
 char serial_number[0x10];
 char access_key[0x10];
};

struct C_LobbySelection_84 {
 u32 menu_id;
 u32 item_id;
};

struct C_Login_DC_PC_GC_9D {
 u32 player_tag;
 u32 guild_card_number;
 u64 hardware_id;
 u32 sub_version;
 u8 is_extended;
 u8 language[0x1];
 u8 unused3[0x2];
 char v1_serial_number[0x10];
 char v1_access_key[0x10];
 char serial_number[0x10];
 char access_key[0x10];
 char serial_number2[0x30];
 char access_key2[0x30];
 char login_character_name[0x10];
};

struct C_LoginExtended_DC_GC_9D {
 struct C_Login_DC_PC_GC_9D __base_C_Login_DC_PC_GC_9D;
 u8 extension[0x64];
};

struct C_Login_PC_GC_9E {
 struct C_Login_DC_PC_GC_9D __base_C_Login_DC_PC_GC_9D;
 u8 client_config[0x20];
};

struct C_LoginExtended_GC_9E {
 struct C_Login_PC_GC_9E __base_C_Login_PC_GC_9E;
 u8 extension[0x64];
};

struct C_LoginExtended_PC_9D {
 struct C_Login_DC_PC_GC_9D __base_C_Login_DC_PC_GC_9D;
 u8 extension[0x84];
};

struct C_LoginExtended_PC_9E {
 struct C_Login_PC_GC_9E __base_C_Login_PC_GC_9E;
 u8 extension[0x84];
};

struct C_LoginV1_DC_PC_V3_90 {
 char serial_number[0x11];
 char access_key[0x11];
};

struct C_Login_DC_PC_V3_9A {
 char v1_serial_number[0x10];
 char v1_access_key[0x10];
 char serial_number[0x10];
 char access_key[0x10];
 u32 player_tag;
 u32 guild_card_number;
 u32 sub_version;
 char serial_number2[0x30];
 char access_key2[0x30];
 char email_address[0x30];
};

struct C_Login_Patch_04 {
 u32 unused[3];
 char username[0x10];
 char password[0x10];
 char email_address[0x40];
};

struct C_MenuItemInfoRequest_09 {
 u32 menu_id;
 u32 item_id;
};

struct C_MenuSelectionBase_10 {
 u32 menu_id;
 u32 item_id;
};

struct C_OpenFileConfirmation_44_A6 {
 char filename[0x10];
};

struct C_Register_DC_PC_V3_9C {
 u64 hardware_id;
 u32 sub_version;
 u8 unused1;
 u8 language[0x1];
 u8 unused2[2];
 char serial_number[0x30];
 char access_key[0x30];
 char password[0x30];
};

struct C_WriteFileConfirmation_V3_BB_13_A7 {
 char filename[0x10];
};

struct SC_SimpleMail_DC_V3_81 {
 u32 player_tag;
 u32 from_guild_card_number;
 char from_name[0xF];
 u8 from_name_term;
 u32 to_guild_card_number;
 char text[0x1FF];
 u8 text_term;
};

struct SC_SimpleMail_PC_81 {
 u32 player_tag;
 u32 from_guild_card_number;
 char from_name[0x1E];
 u16 from_name_term;
 u32 to_guild_card_number;
 char text[0x3FE];
 u16 text_term;
};

struct SC_TextHeader_01_06_11_B0_EE {
 u32 unused;
 u32 guild_card_number;
};

struct SC_TradeItems_D0_D3 {
 u16 target_client_id;
 u16 item_count;
 TItemData item_datas[0x20];
};

struct S_ArrowUpdateEntry_88 {
 u32 player_tag;
 u32 guild_card_number;
 u32 arrow_color;
};

struct S_CloseCurrentFile_Patch_08 {
 u32 unused;
};

struct S_EnterDirectory_Patch_09 {
 char name[0x40];
};

struct S_ExecuteCode_B2 {
 u32 code_size;
 u32 checksum_start;
 u32 checksum_size;
};

struct S_FileChecksumRequest_Patch_0C {
 u32 request_id;
 char filename[0x20];
};

struct S_GenerateID_DC_PC_V3_80 {
 u32 client_id;
 u32 unused;
 u32 next_item_id;
};

struct S_GuildCardFileChunk_02DC {
 u32 unknown_a1;
 u32 chunk_index;
 u8 data[0x6800];
};

struct S_JoinGame_GC_64 {
 u8 __base_S_JoinGameT_DC_PC[0x10C];
 u8 episode;
 u8 unused[3];
};

struct S_LegacyJoinGame_GC_0E {
 struct PlayerLobbyDataDCGC lobby_data[4];
 u8 meet_user_extension[0x64];
 u8 unknown_a3[4];
};

struct S_LegacyJoinGame_PC_0E {
 u32 lobby_data[4];
 u8 unknown_a3[0x20];
};

struct S_LobbyListEntry_83 {
 u32 menu_id;
 u32 item_id;
 u32 player_count;
};

struct S_OpenFile_PC_GC_44_A6 {
 char name[0x22];
 u16 type;
 char filename[0x10];
 u32 file_size;
};

struct S_OpenFile_Patch_06 {
 u32 unused;
 u32 size;
 char filename[0x30];
};

struct S_ReconnectIPv6_Extension_19 {
 u8 address[0x10];
 u16 port;
 u16 unused;
};

struct S_ReconnectSplit_19 {
 u32 pc_address;
 u16 pc_port;
 u8 unused1[0x0F];
 u8 gc_command;
 u8 gc_flag;
 u16 gc_size;
 u32 gc_address;
 u16 gc_port;
 u8 unused2[0xB0 - 0x23];
};

struct S_ServerInitDefault_DC_PC_V3_02_17_91_9B {
 char copyright[0x40];
 u32 server_key;
 u32 client_key;
};

struct S_ServerInit_Patch_02 {
 char copyright[0x40];
 u32 server_key;
 u32 client_key;
};

struct S_ServerTime_B1 {
 char time_str[0x19];
 u8 time_flags_low;
 u8 time_flags_mid;
 u8 time_flags_high;
};

struct S_StartFileDownloads_Patch_11 {
 u32 total_bytes;
 u32 num_files;
};

struct S_TournamentList_Ep3NTE_E0 {
 u32 entries[0x20];
 u8 unknown_a1;
 u8 unknown_a2;
 u8 unknown_a3;
 u8 unknown_a4;
};

struct S_UpdateClientConfig_DC_PC_04 {
 u32 player_tag;
 u32 guild_card_number;
};

struct S_WriteFileHeader_Patch_07 {
 u32 chunk_index;
 u32 chunk_checksum;
 u32 chunk_size;
};

struct S_WriteFile_13_A7 {
 char filename[0x10];
 u8 data[0x400];
 u32 data_size;
};

#endif
