#ifndef PSO_UNK_TQUESTMANAGER_H
#define PSO_UNK_TQUESTMANAGER_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/quest/QuestVm.h"

struct QuestBinHeader;

class TQuestManager : public TObject {
public:
    u8 unk_1C[0x24 - 0x1C];
    QuestVmContext ctx;
    QuestBinHeader *script;
    u8 unk_19C[4];
    s32 kind;

    TQuestManager(TObject *parent, void *script, s32 size);
    TQuestManager(TObject *parent, const char *filename, s32 kind);
    TQuestManager(TObject *parent, const char *filename);
    virtual ~TQuestManager();
    virtual void run_task();
};
LAYOUT_ASSERT(TQuestManager_size, sizeof(TQuestManager) == 0x1A4);

extern TQuestManager *quest_mission_manager;
extern TQuestManager *quest_area_manager;

#endif
