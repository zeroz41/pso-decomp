#ifndef PSO_QUEST_CHALLENGE_TCHALLENGE4PITEMSELECT_H
#define PSO_QUEST_CHALLENGE_TCHALLENGE4PITEMSELECT_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChallenge4PResult;

class TChallenge4PItemSelect : public TObject {
public:
    void close_with_callback();
    void submit_selected_item();
    void open_menu();
    void (*onClosed)(void *);
    s32 state;
    s32 waitFrames;
    TChallenge4PResult *result;
    TChallenge4PItemSelect(TObject *parent, TChallenge4PResult *resultOwner);
 void* menu_window;
public:
    virtual ~TChallenge4PItemSelect();
    virtual void run_task();
};

#include <stddef.h>
LAYOUT_ASSERT(ChallengeItemSelectSize, sizeof(TChallenge4PItemSelect)==0x30);
LAYOUT_ASSERT(ChallengeItemSelectCallback, offsetof(TChallenge4PItemSelect,onClosed)==0x1C);
LAYOUT_ASSERT(ChallengeItemSelectState, offsetof(TChallenge4PItemSelect,state)==0x20);
LAYOUT_ASSERT(ChallengeItemSelectTimer, offsetof(TChallenge4PItemSelect,waitFrames)==0x24);
LAYOUT_ASSERT(ChallengeItemSelectResult, offsetof(TChallenge4PItemSelect,result)==0x28);
LAYOUT_ASSERT(ChallengeItemSelectWindow, offsetof(TChallenge4PItemSelect,menu_window)==0x2C);
#endif
