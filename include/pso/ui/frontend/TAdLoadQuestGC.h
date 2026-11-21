#ifndef PSO_UI_FRONTEND_TADLOADQUESTGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTGC_H
#include "pso/system/task/TObject.h"
#include <stddef.h>

class TAdLdQuestPrtGC;
class TAdLoadQuestCellGC;
class TAdLoadQuestLineGC;
struct TAdLoadQuestPrtTxtGC;

class TAdLoadQuestGC : public TObject {
public:
    TAdLoadQuestGC(TObject *parent);
    virtual ~TAdLoadQuestGC();
    virtual void run_task();
    virtual void render();

    TAdLoadQuestCellGC *get_or_create_cell(int slot);
    TAdLoadQuestLineGC *get_or_create_line(int slot);
    TAdLoadQuestPrtTxtGC *get_or_create_prt_txt(int slot);
    static TAdLoadQuestCellGC *get_cell(int slot);
    static TAdLoadQuestLineGC *get_line(int slot);
    static TAdLoadQuestPrtTxtGC *get_text(int slot);
    static void setup();
    static void cleanup();

    TAdLdQuestPrtGC *quest_display;
};

LAYOUT_ASSERT(TAdLoadQuestGCDisplayOffset, offsetof(TAdLoadQuestGC, quest_display) == 0x1C);
LAYOUT_ASSERT(TAdLoadQuestGCSize, sizeof(TAdLoadQuestGC) == 0x20);

#endif
