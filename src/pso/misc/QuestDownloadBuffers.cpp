#include "types.h"

// Download-server work buffers. Defining them in either file that uses them (TQuestVmDownLoadServer_803E5668 or
// _803E6970) changes codegen of an exact function there, so they belong to a TU whose code does not touch them.
s32 quest_vm_download_server_file_info[0x11];
u8 quest_download_slot_table[0x2C78];
u8 quest_name_index_table[0x1000];
u8 lbl_80591AC4[0x404];
u8 lbl_80591EC8[0x2000];
void *lbl_80593EC8[0x450];
u8 lbl_80595008[0x990];
u8 quest_download_slot_chain_table[0x8C0];
u8 lbl_80596258[0xC];
u8 quest_download_text_buffer[0x404];
