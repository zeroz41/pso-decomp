#ifndef PSO_QUEST_ASKDICLOOKUP_H
#define PSO_QUEST_ASKDICLOOKUP_H

#include "types.h"

struct QuestDownloadEntryNode;

QuestDownloadEntryNode *insert_quest_download_entry(QuestDownloadEntryNode *head, QuestDownloadEntryNode *entry);

struct QuestDownloadWorkspaceAddress {
    size_t address;
    QuestDownloadWorkspaceAddress(size_t base) : address(base) {}
};

#endif
