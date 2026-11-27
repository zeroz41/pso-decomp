#include "pso/quest/QuestDownloadWorkspace.h"

// The query workspace and the slots are consecutive in the retail buffer
// pool. The twelve-byte display prefix immediately precedes text scratch.
QuestDownloadWorkspace conversion_workspace;
QuestDownloadSlot quest_download_slot_chain_table[80];
QuestDownloadDisplayPrefix quest_download_display_prefix;
QuestDownloadTextBuffer quest_download_text_buffer ATTRIBUTE_ALIGN(4);

// The same TU's .sbss run (a 4-byte pad follows before the next TU's run).
s32 lbl_805D7880;
s32 lbl_805D7884;
s32 ask_convert_mode;
