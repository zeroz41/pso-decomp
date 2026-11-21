#ifndef PSO_QUEST_QUESTSCRIPTFORMAT_H
#define PSO_QUEST_QUESTSCRIPTFORMAT_H

#include "types.h"
#include <stddef.h>

// The header at the start of a decompressed quest .bin file.
struct QuestBinHeader {
    u32 code_offset;
    u32 function_table_offset;
    u32 size;
    u32 unused;
    s8 language;
    s8 unk_11;
    s8 quest_number;
    s8 episode;
    char name[0x20];
    char short_description[0x80];
    char long_description[0x120];
};

LAYOUT_ASSERT(QuestBinScriptNameOffset, offsetof(QuestBinHeader, name) == 0x14);

struct QuestVmContext;
extern "C" void init_quest_script_context(QuestBinHeader *header, QuestVmContext *context);

#endif
