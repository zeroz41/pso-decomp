#ifndef PSO_QUEST_QUESTDOWNLOADCHARTABLES_H
#define PSO_QUEST_QUESTDOWNLOADCHARTABLES_H

#include "types.h"

// Character-code tables of the quest text converter, .rodata 0x8047E698-0x8047EA28, defined by
// QuestDownloadCharTables.c (interim data-only unit). Read by TQuestVmDownLoadServer_803E6970.

// JIS symbol code and the single-byte code it maps to.
typedef struct JisSymbolEntry {
    u16 key;
    u8 val;
} JisSymbolEntry;

extern const u16 single_byte_to_jis_table[0x100];
extern const u8 key_symbol_chars[9];
extern const u16 key_symbol_jis[8];
extern const u16 quest_download_char_code_table[0x5F];
extern const JisSymbolEntry jis_to_single_byte_symbol_table[45];

#endif
