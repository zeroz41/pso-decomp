#include "pso/quest/QuestDownloadWorkspace.h"

// The query workspace and the slots are consecutive in the retail buffer
// pool. The twelve-byte display prefix immediately precedes text scratch.
QuestDownloadWorkspace lbl_80595008;
QuestDownloadSlot quest_download_slot_chain_table[80];
QuestDownloadDisplayPrefix lbl_80596258;
u8 quest_download_text_buffer[0x404] ATTRIBUTE_ALIGN(4);

// The same TU's .sbss run (0x805D7880-0x805D788C, a 4-byte pad follows before the next TU's run at 0x805D7890).
s32 lbl_805D7880;
s32 lbl_805D7884;
s32 lbl_805D7888;
