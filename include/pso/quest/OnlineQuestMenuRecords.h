#ifndef PSO_QUEST_ONLINEQUESTMENURECORDS_H
#define PSO_QUEST_ONLINEQUESTMENURECORDS_H

#include <stddef.h>
#include "pso/network/protocol/packet_classes.h"
#include "pso/quest/TQuestListOnline.h"

typedef char OnlineQuestMenu_size[sizeof(OnlineQuestMenu) == 0x11D4 ? 1 : -1];
typedef char OnlineQuestMenu_entries_offset[offsetof(OnlineQuestMenu, entries) == 4 ? 1 : -1];
typedef char OnlineQuestMenu_entry_size[sizeof(QuestListEntry) == 0x98 ? 1 : -1];
typedef char OnlineQuestInfo_size[sizeof(OnlineQuestInfo) == 0x124 ? 1 : -1];
typedef char OnlineQuestInfo_text_offset[offsetof(OnlineQuestInfo, text) == 4 ? 1 : -1];
typedef char OnlineQuestFile_name_offset[offsetof(TRecvDownloadHead, filename) == 0x28 ? 1 : -1];
typedef char OnlineQuestFile_size_offset[offsetof(TRecvDownloadHead, file_size) == 0x38 ? 1 : -1];

extern "C" {
extern OnlineQuestMenu *TQuestListOnline__quest_list_buffer;
extern OnlineQuestInfo *TQuestListOnline__selected_quest_info;
}

#endif
