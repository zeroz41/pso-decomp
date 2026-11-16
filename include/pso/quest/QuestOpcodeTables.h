#ifndef PSO_QUEST_QUEST_OPCODE_TABLES_H
#define PSO_QUEST_QUEST_OPCODE_TABLES_H

#include "types.h"

typedef void (*QuestArgumentDecoder)(s32 opcode);
typedef void (*QuestOpcodeHandler)();
struct QuestOpcodeEntry {
    QuestArgumentDecoder decode_arguments;
    QuestOpcodeHandler handler;
};

extern "C" {
extern QuestOpcodeEntry qst_opcode_table[0x300];
extern const char* qst_bgm_filename_table[];
}

// .rodata of QuestOpcodeTables.cpp; QuestOpcodeHandlers.cpp addresses each on its own.
// Sound effect ids of the quest opcode `se` (qst_op_se), indexed by its argument.
extern const s32 quest_sound_effect_ids[29];
// The BGM files of qst_bgm_filename_table.
extern const char quest_bgm_clear_filename[];
extern const char quest_bgm_miniclear_filename[];

#endif
