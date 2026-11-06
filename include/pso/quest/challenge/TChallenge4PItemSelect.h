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
typedef char ChallengeItemSelectSize[sizeof(TChallenge4PItemSelect)==0x30 ? 1 : -1];
typedef char ChallengeItemSelectCallback[offsetof(TChallenge4PItemSelect,onClosed)==0x1C ? 1 : -1];
typedef char ChallengeItemSelectState[offsetof(TChallenge4PItemSelect,state)==0x20 ? 1 : -1];
typedef char ChallengeItemSelectTimer[offsetof(TChallenge4PItemSelect,waitFrames)==0x24 ? 1 : -1];
typedef char ChallengeItemSelectResult[offsetof(TChallenge4PItemSelect,result)==0x28 ? 1 : -1];
typedef char ChallengeItemSelectWindow[offsetof(TChallenge4PItemSelect,menu_window)==0x2C ? 1 : -1];
#endif
