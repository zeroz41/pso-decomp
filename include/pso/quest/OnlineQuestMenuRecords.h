#ifndef PSO_QUEST_ONLINEQUESTMENURECORDS_H
#define PSO_QUEST_ONLINEQUESTMENURECORDS_H

#include <stddef.h>
#include "pso/network/protocol/packet_classes.h"
#include "pso/quest/TQuestListOnline.h"

LAYOUT_ASSERT(OnlineQuestMenu_size, sizeof(OnlineQuestMenu) == 0x11D4);
LAYOUT_ASSERT(OnlineQuestMenu_entries_offset, offsetof(OnlineQuestMenu, entries) == 4);
LAYOUT_ASSERT(OnlineQuestMenu_entry_size, sizeof(QuestListEntry) == 0x98);
LAYOUT_ASSERT(OnlineQuestInfo_size, sizeof(OnlineQuestInfo) == 0x124);
LAYOUT_ASSERT(OnlineQuestInfo_text_offset, offsetof(OnlineQuestInfo, text) == 4);
LAYOUT_ASSERT(OnlineQuestFile_name_offset, offsetof(TRecvDownloadHead, filename) == 0x28);
LAYOUT_ASSERT(OnlineQuestFile_size_offset, offsetof(TRecvDownloadHead, file_size) == 0x38);

extern "C" {
extern OnlineQuestMenu *TQuestListOnline__quest_list_buffer;
extern OnlineQuestInfo *TQuestListOnline__selected_quest_info;
extern TWindowMessage *TQuestListOnline__download_window;
extern TWindowMessage *TQuestListOnline__quest_info_window;
extern TWindowMessage *TQuestListOnline__download_barrier_window;
}

#endif
